#include <iostream>
#include <fstream>
#include <vector>
#include "menu.h"
#include "players.h"
#include "packs.h"

#include "avl.h"

using namespace std;

// adatbazis letrehozasa
bool loadDatabase(int &size, vector<Player> &database) {

    ifstream f("database.in");

    // Sikertelen fajlmegnyitas
    if (!f.is_open()) {
        return false;
    }

    f >> size;
    int temp_ovr, temp_price = 0;
    string temp_name, temp_pos, temp_cl, temp_l, temp_nat;

    // Beolvasas
    for (int i = 0; i < size; i++) {
        f >> temp_name >> temp_ovr >> temp_pos >> temp_cl >> temp_l >> temp_nat >> temp_price;
        Player temp(temp_ovr, temp_name, temp_pos, temp_cl, temp_l, temp_nat, temp_price);

        database.push_back(temp);
    }
   
    f.close();

    return true;
}

void game(vector<Player> &database, AVLFa<Player> &inventory) {

    int currency = 1500;

    // Fo navigalo
    int foopcio = mainMenu();
    while (foopcio != 4) {

        // 1. Nyitasok, es navigacio
        if (foopcio == 1) {

            // Csomagok kivalasztasa
            int nyopcio = openingMenu(currency);
            while (nyopcio != 4) {

                // free csomag
                if (nyopcio == 1) {
                    Player seged = freePack(database);
                    inventory.insert(seged);
                    openingAnimation(seged);
                }

                // ultra csomag
                else if (nyopcio == 2) {

                    if (currency >= 200) {
                        currency -= 200;
                        Player seged = ultraPack(database);
                        inventory.insert(seged);
                        openingAnimation(seged);
                    }
                    else notEnough();
                }

                // premium csomag
                else if (nyopcio == 3) {

                    if (currency >= 500) {
                        currency -= 500;
                        Player seged = premiumPack(database);
                        inventory.insert(seged);
                        openingAnimation(seged);
                    }
                    else notEnough();
                }
                nyopcio = openingMenu(currency);
            }
        }
        else if (foopcio == 2) {

            int invopcio = openInvMenu();
            while (invopcio != 5) {

                if (invopcio == 1) {
                    drawTableSA(inventory);
                }
                else if (invopcio == 2) {
                    drawTableSD(inventory);
                }
                else if (invopcio == 3) {
                    drawTableLA(inventory);
                }
                else if (invopcio == 4) {
                    drawTableLD(inventory);
                }

                invopcio = openInvMenu();
            }
        }
        else if (foopcio == 3) {
            int invopcio = searchMenu(inventory, currency);
            while (invopcio != 0) {
                invopcio = searchMenu(inventory, currency);
            }
        }
        foopcio = mainMenu();
    }

    cout << CLEAR_SCREEN;
    drawQuitGame();
}

int main()
{
    // adatbazis letrehozasa, adatok betoltese
    vector<Player> player_database;
    int database_size;
    if (!loadDatabase(database_size, player_database)) {

        drawError();
        return -1;
    }

    // a felhasznalo jatekosainak adatbazisa(kezdetben egy Ures AVL-Fa)
    AVLFa<Player> inventory;

    // futtatas
    game(player_database, inventory);
    cout << endl;

    return 0;
    
}