/** @mainpage
   Practica PRO2 primavera 2024. Gerard Rius Husillos.
   Grup 23
*/

/** @file program.cc

    @brief Contiene el programa principal
*/
#include "common.hh"
#include "valley.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

int main() {
    using namespace std;

    Valley v;

    // Initial setup
    int start_product_count;
    cin >> start_product_count;
    v.addProducts(start_product_count);
    v.readRiver();
    v.readShip();

    // Debug only
    // v.printRiver();
    // v.printShip();

    string in;
    cin >> in;
    while (in != "fin") {
        if (in == "//") {
            string dump;
            getline(cin, dump);
        } else if (in == "leer_rio" || in == "lr") {
            cout << '#' << in << endl;
            v.readRiver();
        } else if (in == "leer_inventario" || in == "li") {
            string city;
            cin >> city;

            cout << '#' << in << ' ' << city << endl;
            if (!v.isValidCity(city)) {
                cout << "error: no existe la ciudad" << endl;
                // dump input
                int c;
                cin >> c;

                for (int i = 0; i < c; i++) {
                    int id, has, need;
                    cin >> id >> has >> need;
                }
            } else {
                v.readCityInventory(city);
            }
        } else if (in == "leer_inventarios" || in == "ls") {
            cout << '#' << in << endl;

            string city;
            cin >> city;
            while (city != "#") {
                v.readCityInventory(city);
                cin >> city;
            }
        } else if (in == "modificar_barco" || in == "mb") {
            cout << '#' << in << endl;
            v.readShip();
        } else if (in == "escribir_barco" || in == "eb") {
            cout << '#' << in << endl;
            v.printShip();
        } else if (in == "consultar_num" || in == "cn") {
            cout << '#' << in << '\n';
            cout << v.numProducts() << endl;
        } else if (in == "agregar_productos" || in == "ap") {
            int count;
            cin >> count;
            cout << '#' << in << " " << count << endl;
            v.addProducts(count);
        } else if (in == "escribir_producto" || in == "ep") {
            int i;
            cin >> i;
            cout << '#' << in << ' ' << i << endl;
            v.printProduct(i - 1);
        } else if (in == "escribir_ciudad" || in == "ec") {
            string city;
            cin >> city;
            cout << '#' << in << ' ' << city << endl;
            if (!v.isValidCity(city)) {
                cout << "error: no existe la ciudad" << endl;
            } else {
                v.printCity(city);
            }
        } else if (in == "poner_prod" || in == "pp") {
            string city;
            size_t id;
            int needs, has;
            cin >> city >> id >> has >> needs;
            cout << '#' << in << ' ' << city << ' ' << id << endl;
            if (!v.isValidProduct(id)) {
                cout << "error: no existe el producto" << endl;
            } else if (!v.isValidCity(city)) {
                cout << "error: no existe la ciudad" << endl;
            } else if (v.hasProduct(city, id)) {
                cout << "error: la ciudad ya tiene el producto" << endl;
            } else {
                v.addToCityInventory(city, id, has, needs);
                int mass, vol;
                v.getCityMassVol(city, mass, vol);
                cout << mass << ' ' << vol << endl;
            }
        } else if (in == "modificar_prod" || in == "mp") {
            string city;
            size_t id;
            int needs, has;
            cin >> city >> id >> has >> needs;
            cout << '#' << in << ' ' << city << ' ' << id << endl;
            if (!v.isValidProduct(id)) {
                cout << "error: no existe el producto" << endl;
            } else if (!v.isValidCity(city)) {
                cout << "error: no existe la ciudad" << endl;
            } else if (!v.hasProduct(city, id)) {
                cout << "error: la ciudad no tiene el producto" << endl;
            } else {
                v.removeFromCityInventory(city, id);
                v.addToCityInventory(city, id, has, needs);
                int mass, vol;
                v.getCityMassVol(city, mass, vol);
                cout << mass << ' ' << vol << endl;
            }
        } else if (in == "quitar_prod" || in == "qp") {
            string city;
            size_t id;
            cin >> city >> id;
            cout << '#' << in << ' ' << city << ' ' << id << endl;
            if (!v.isValidProduct(id)) {
                cout << "error: no existe el producto" << endl;
            } else if (!v.isValidCity(city)) {
                cout << "error: no existe la ciudad" << endl;
            } else if (!v.hasProduct(city, id)) {
                cout << "error: la ciudad no tiene el producto" << endl;
            } else {
                v.removeFromCityInventory(city, id);
                int mass, vol;
                v.getCityMassVol(city, mass, vol);
                cout << mass << ' ' << vol << endl;
            }
        } else if (in == "consultar_prod" || in == "cp") {
            string city;
            size_t id;
            cin >> city >> id;
            cout << '#' << in << ' ' << city << ' ' << id << endl;
            if (!v.isValidProduct(id)) {
                cout << "error: no existe el producto" << endl;
            } else if (!v.isValidCity(city)) {
                cout << "error: no existe la ciudad" << endl;
            } else if (!v.hasProduct(city, id)) {
                cout << "error: la ciudad no tiene el producto" << endl;
            } else {
                int has, needs;
                v.getCityProduct(city, id, has, needs);
                cout << has << ' ' << needs << endl;
            }
        } else if (in == "comerciar" || in == "co") {
            string city1, city2;
            cin >> city1 >> city2;
            cout << '#' << in << ' ' << city1 << ' ' << city2 << endl;
            if (!v.isValidCity(city1) || !v.isValidCity(city2)) {
                cout << "error: no existe la ciudad" << endl;
            } else if (city1 == city2) {
                cout << "error: ciudad repetida" << endl;
            } else {
                v.trade(city1, city2);
            }
        } else if (in == "redistribuir" || in == "re") {
            cout << '#' << in << endl;
            v.redistribute();

        } else if (in == "hacer_viaje" || in == "hv") {
            cout << '#' << in << endl;
            v.travel();
        } else {
            panic("Reached unreachable code!");
        }

        cin >> in;
    }
}
