#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>


using namespace std;
// Estructura para representar una ruta
struct Route {
    vector<string> path;  // Camino completo
    int cost;                       // Costo total

    Route() : cost(numeric_limits<int>::max()) {}
    Route(const vector<string>& p, int c) : path(p), cost(c) {}
};

// Clase Enrutador
class Router {
private:
    string id;
    map<string, Route> routingTable;  // Tabla de enrutamiento
    map<string, int> neighbors;       // Vecinos directos y sus costos

public:
    Router(){}
    Router(const string& routerId) : id(routerId) {}

    string getId() const { return id; }

    // Agregar vecino directo
    void addNeighbor(const string& neighborId, int cost) {
        neighbors[neighborId] = cost;
    }

    // Remover vecino
    void removeNeighbor(const string& neighborId) {
        neighbors.erase(neighborId);
    }

    // Obtener vecinos
    const map<string, int>& getNeighbors() const {
        return neighbors;
    }

    // Actualizar tabla de enrutamiento
    void updateRoutingTable(const string& destination, const Route& route) {
        routingTable[destination] = route;
    }

    // Obtener ruta a destino
    Route getRoute(const string& destination) const {
        auto it = routingTable.find(destination);
        if (it != routingTable.end()) {
            return it->second;
        }
        return Route(); // Ruta no encontrada
    }

    // Mostrar tabla de enrutamiento
    void printRoutingTable() const {
        ::cout << "\n=== Tabla de Enrutamiento - Router " << id << " ===\n";
        ::cout << "Destino\tCosto\tCamino\n";
        ::cout << "-------\t-----\t------\n";

        for (const auto& entry : routingTable) {
            ::cout << entry.first << "\t" << entry.second.cost << "\t";
            for (size_t i = 0; i < entry.second.path.size(); ++i) {
                cout << entry.second.path[i];
                if (i < entry.second.path.size() - 1) cout << " -> ";
            }
            cout << "\n";
        }
    }

    // Limpiar tabla de enrutamiento
    void clearRoutingTable() {
        routingTable.clear();
    }
};

#endif // ROUTER_H
