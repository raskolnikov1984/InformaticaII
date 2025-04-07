#include <gtest/gtest.h>
#include "room.h"

void showMenu() {
    std::cout << "\n--- MENÚ DE CINE ---\n";
    std::cout << "1. Reservar asiento\n";
    std::cout << "2. Cancelar reserva\n";
    std::cout << "3. Ver asientos de la Sala\n";
    std::cout << "4. Ver informacion de la Sala\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    Room room(15, 20); // 15 filas (A-O), 20 asientos por fila
    int option;
    char row;
    int seat;

    do {
        showMenu();
        std::cin >> option;

        switch (option) {
        case 1: // Reservar
            std::cout << "Ingrese fila (A-O): ";
            std::cin >> row;
            std::cout << "Ingrese asiento (1-20): ";
            std::cin >> seat;
            room.reserveSeat(row, seat);
            room.printRoom();
            break;

        case 2: // Cancelar
            std::cout << "Ingrese fila (A-O): ";
            std::cin >> row;
            std::cout << "Ingrese asiento (1-20): ";
            std::cin >> seat;
            room.unReserveSeat(row, seat);
            room.printRoom();
            break;
        case 3: // Ver Sala
            room.printRoom();
            break;
        case 4: // Ver informacion de la Sala
            std::cout<<std::endl;
            std::cout << "La Cantidad de asientos libres son: " << room.unreservedSeats << std::endl;
            std::cout << "La Cantidad de asientos ocupados son: " << room.reservedSeats << std::endl;
            break;
        case 5: // Salir
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción inválida. Intente de nuevo.\n";
            break;
        }
    } while (option != 5);

    return RUN_ALL_TESTS();
}
