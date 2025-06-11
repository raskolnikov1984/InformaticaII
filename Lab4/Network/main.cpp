#include <iostream>
#include <string>
#include "network.h"

using namespace  std;

void showMenu() {
    cout << "\n=== SIMULADOR DE RED DE ENRUTADORES ===\n";
    cout << "1. Agregar router\n";
    cout << "2. Remover router\n";
    cout << "3. Agregar enlace\n";
    cout << "4. Remover enlace\n";
    cout << "5. Actualizar tablas de enrutamiento\n";
    cout << "6. Consultar costo de envío\n";
    cout << "7. Consultar camino de envío\n";
    cout << "8. Mostrar topología\n";
    cout << "9. Mostrar tablas de enrutamiento\n";
    cout << "10. Cargar red desde archivo\n";
    cout << "11. Generar red aleatoria\n";
    cout << "12. Verificar conectividad\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    Network network;
    int option;

    do {
        showMenu();
        cin >> option;

        switch (option) {
        case 1: {
            string routerId;
            cout << "Ingrese ID del router: ";
            cin >> routerId;
            network.addRouter(routerId);
            break;
        }
        case 2: {
            string routerId;
            cout << "Ingrese ID del router a remover: ";
            cin >> routerId;
            network.removeRouter(routerId);
            break;
        }
        case 3: {
            string router1, router2;
            int cost;
            cout << "Ingrese router 1: ";
            cin >> router1;
            cout << "Ingrese router 2: ";
            cin >> router2;
            cout << "Ingrese costo: ";
            cin >> cost;
            network.addLink(router1, router2, cost);
            break;
        }
        case 4: {
            string router1, router2;
            cout << "Ingrese router 1: ";
            cin >> router1;
            cout << "Ingrese router 2: ";
            cin >> router2;
            network.removeLink(router1, router2);
            break;
        }
        case 5: {
            network.updateAllRoutingTables();
            break;
        }
        case 6: {
            string source, destination;
            cout << "Ingrese router origen: ";
            cin >> source;
            cout << "Ingrese router destino: ";
            cin >> destination;

            int cost = network.getPacketCost(source, destination);
            if (cost >= 0) {
                cout << "Costo de envío de " << source << " a " << destination << ": " << cost << "\n";
            }
            break;
        }
        case 7: {
            string source, destination;
            cout << "Ingrese router origen: ";
            cin >> source;
            cout << "Ingrese router destino: ";
            cin >> destination;

            auto path = network.getPacketPath(source, destination);
            if (!path.empty()) {
                cout << "Camino de " << source << " a " << destination << ": ";
                for (size_t i = 0; i < path.size(); ++i) {
                    cout << path[i];
                    if (i < path.size() - 1) cout << " -> ";
                }
                cout << "\n";
            }
            break;
        }
        case 8: {
            network.printTopology();
            break;
        }
        case 9: {
            network.printAllRoutingTables();
            break;
        }
        case 10: {
            string filename;
            cout << "Ingrese nombre del archivo: ";
            cin >> filename;
            network.loadFromFile(filename);
            break;
        }
        case 11: {
            int numRouters;
            double linkProb;
            int maxCost;

            cout << "Ingrese número de routers: ";
            cin >> numRouters;
            cout << "Ingrese probabilidad de enlace (0.0-1.0): ";
            cin >> linkProb;
            cout << "Ingrese costo máximo de enlaces: ";
            cin >> maxCost;

            network.generateRandomNetwork(numRouters, linkProb, maxCost);
            break;
        }
        case 12: {
            if (network.isConnected()) {
                cout << "La red está completamente conectada.\n";
            } else {
                cout << "La red NO está completamente conectada.\n";
            }
            break;
        }
        case 0: {
            cout << "¡Hasta luego!\n";
            break;
        }
        default: {
            cout << "Opción inválida.\n";
            break;
        }
        }
    } while (option != 0);

    return 0;
}
