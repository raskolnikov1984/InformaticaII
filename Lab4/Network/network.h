#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <queue>
#include <random>
#include <set>
#include "router.h"


// Clase Red
class Network {
private:
    map<::string, Router> routers;
    map<::pair<string, string>, int> links; // Enlaces y sus costos

public:
    // Agregar enrutador
    void addRouter(const string& routerId) {
        routers.emplace(routerId, Router(routerId));
        ::cout << "Router " << routerId << " agregado a la red.\n";
    }

    // Remover enrutador
    void removeRouter(const string& routerId) {
        // Remover enlaces relacionados
        auto it = links.begin();
        while (it != links.end()) {
            if (it->first.first == routerId || it->first.second == routerId) {
                it = links.erase(it);
            } else {
                ++it;
            }
        }

        // Remover de vecinos de otros routers
        for (auto& router : routers) {
            router.second.removeNeighbor(routerId);
        }

        // Remover router
        routers.erase(routerId);
        ::cout << "Router " << routerId << " removido de la red.\n";
    }

    // Agregar enlace
    void addLink(const string& router1, const string& router2, int cost) {
        if (routers.find(router1) == routers.end() || routers.find(router2) == routers.end()) {
            cout << "Error: Uno o ambos routers no existen.\n";
            return;
        }

        links[{router1, router2}] = cost;
        links[{router2, router1}] = cost; // Enlace bidireccional

        routers[router1].addNeighbor(router2, cost);
        routers[router2].addNeighbor(router1, cost);

        cout << "Enlace agregado: " << router1 << " <-> " << router2 << " (costo: " << cost << ")\n";
    }

    // Remover enlace
    void removeLink(const string& router1, const string& router2) {
        links.erase({router1, router2});
        links.erase({router2, router1});

        if (routers.find(router1) != routers.end()) {
            routers[router1].removeNeighbor(router2);
        }
        if (routers.find(router2) != routers.end()) {
            routers[router2].removeNeighbor(router1);
        }

        cout << "Enlace removido: " << router1 << " <-> " << router2 << "\n";
    }

    // Algoritmo de Dijkstra para encontrar caminos más cortos
    void calculateShortestPaths(const string& source) {
        if (routers.find(source) == routers.end()) {
            cout << "Error: Router fuente no existe.\n";
            return;
        }

        map<string, int> distances;
        map<string, string> previous;
        priority_queue<pair<int, string>,
                       vector<pair<int, string>>,
                       greater<pair<int, string>>> pq;

        // Inicializar distancias
        for (const auto& router : routers) {
            distances[router.first] = numeric_limits<int>::max();
        }
        distances[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int currentDist = pq.top().first;
            string currentRouter = pq.top().second;
            pq.pop();

            if (currentDist > distances[currentRouter]) continue;

            for (const auto& neighbor : routers[currentRouter].getNeighbors()) {
                string neighborId = neighbor.first;
                int edgeWeight = neighbor.second;
                int newDist = distances[currentRouter] + edgeWeight;

                if (newDist < distances[neighborId]) {
                    distances[neighborId] = newDist;
                    previous[neighborId] = currentRouter;
                    pq.push({newDist, neighborId});
                }
            }
        }

        // Construir rutas y actualizar tabla de enrutamiento
        routers[source].clearRoutingTable();
        for (const auto& dest : routers) {
            if (dest.first != source && distances[dest.first] != numeric_limits<int>::max()) {
                vector<::string> path;
                string current = dest.first;

                while (current != source) {
                    path.push_back(current);
                    current = previous[current];
                }
                path.push_back(source);
                reverse(path.begin(), path.end());

                Route route(path, distances[dest.first]);
                routers[source].updateRoutingTable(dest.first, route);
            }
        }
    }

    // Actualizar todas las tablas de enrutamiento
    void updateAllRoutingTables() {
        cout << "\nActualizando tablas de enrutamiento...\n";
        for (const auto& router : routers) {
            calculateShortestPaths(router.first);
        }
        cout << "Tablas actualizadas.\n";
    }

    // Obtener costo de envío
    int getPacketCost(const string& source, const string& destination) {
        if (routers.find(source) == routers.end() || routers.find(destination) == routers.end()) {
            cout << "Error: Router fuente o destino no existe.\n";
            return -1;
        }

        Route route = routers[source].getRoute(destination);
        if (route.cost == numeric_limits<int>::max()) {
            cout << "No hay ruta disponible de " << source << " a " << destination << "\n";
            return -1;
        }

        return route.cost;
    }

    // Obtener camino de envío
    vector<string> getPacketPath(const string& source, const string& destination) {
        if (routers.find(source) == routers.end() || routers.find(destination) == routers.end()) {
            cout << "Error: Router fuente o destino no existe.\n";

            return {};
        }

        Route route = routers[source].getRoute(destination);
        if (route.cost == numeric_limits<int>::max()) {
            cout << "No hay ruta disponible de " << source << " a " << destination << "\n";
            return {};
        }

        return route.path;
    }

    // Cargar red desde archivo
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Error: No se pudo abrir el archivo " << filename << "\n";
            return;
        }

        string line;
        while (getline(file, line)) {
            if (line.empty() || line[0] == '#') continue; // Ignorar comentarios

            // Formato esperado: router1 router2 costo
            string router1, router2;
            int cost;

            istringstream iss(line);

            if (iss >> router1 >> router2 >> cost) {
                // Agregar routers si no existen
                if (routers.find(router1) == routers.end()) {
                    addRouter(router1);
                }
                if (routers.find(router2) == routers.end()) {
                    addRouter(router2);
                }

                addLink(router1, router2, cost);
            }
        }

        file.close();
        cout << "Red cargada desde " << filename << "\n";
    }

    // Generar red aleatoria
    void generateRandomNetwork(int numRouters, double linkProbability, int maxCost = 10) {
        // Limpiar red actual
        routers.clear();
        links.clear();

        // Crear routers
        for (int i = 0; i < numRouters; ++i) {
            addRouter("R" + ::to_string(i));
        }

        // Generar enlaces aleatorios
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> probDist(0.0, 1.0);
        uniform_int_distribution<> costDist(1, maxCost);

        vector<::string> routerIds;
        for (const auto& router : routers) {
            routerIds.push_back(router.first);
        }

        for (size_t i = 0; i < routerIds.size(); ++i) {
            for (size_t j = i + 1; j < routerIds.size(); ++j) {
                if (probDist(gen) < linkProbability) {
                    int cost = costDist(gen);
                    addLink(routerIds[i], routerIds[j], cost);
                }
            }
        }

        ::cout << "Red aleatoria generada con " << numRouters << " routers.\n";
    }

    // Mostrar topología de la red
    void printTopology() {
        ::cout << "\n=== Topología de la Red ===\n";
        ::cout << "Routers: ";
        for (const auto& router : routers) {
            ::cout << router.first << " ";
        }
        ::cout << "\n\nEnlaces:\n";

        set<pair<string, string>> printedLinks;
        for (const auto& link : links) {
            string r1 = link.first.first;
            string r2 = link.first.second;

            if (printedLinks.find({r2, r1}) == printedLinks.end()) {
                ::cout << r1 << " <-> " << r2 << " (costo: " << link.second << ")\n";
                printedLinks.insert({r1, r2});
            }
        }
    }

    // Mostrar todas las tablas de enrutamiento
    void printAllRoutingTables() {
        for (const auto& router : routers) {
            router.second.printRoutingTable();
        }
    }

    // Verificar si la red está conectada
    bool isConnected() {
        if (routers.empty()) return true;

        string startRouter = routers.begin()->first;
        set<string> visited;
        queue<string> queue;

        queue.push(startRouter);
        visited.insert(startRouter);

        while (!queue.empty()) {
            string current = queue.front();
            queue.pop();

            for (const auto& neighbor : routers[current].getNeighbors()) {
                if (visited.find(neighbor.first) == visited.end()) {
                    visited.insert(neighbor.first);
                    queue.push(neighbor.first);
                }
            }
        }

        return visited.size() == routers.size();
    }
};

#endif // NETWORK_H
