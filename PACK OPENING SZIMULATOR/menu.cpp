#include "menu.h"
#include "players.h"
#include "avl.h"
#include <iostream>

using namespace std;

// menu kirajzolasa
void drawMainMenu() {
    cout << ANSI_COLOR_BLUE << "------------------------------------" << ANSI_COLOR_RESET << endl;
    cout << "           " << ANSI_COLOR_RED << "PACK SIMULATOR" << ANSI_COLOR_RESET << endl;
    cout << "             " << ANSI_COLOR_BLUE << "Valassz!" << ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_BLUE << "------------------------------------" << ANSI_COLOR_RESET << endl;
    cout << endl;
    cout << "    " << ANSI_COLOR_LIGHT_BLUE << "       1. Csomagnyitas" << endl;
    cout << "           2. Inventory" << endl;
    cout << "           3. Jatekos eladasa" << endl;
    cout << "           4. Kilepes" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_BLUE << "------------------------------------" << ANSI_COLOR_RESET << endl;
}

// csomagnyitasos menu kirajzolasa
void drawPacksMenu(int curr) {

    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_RED << "  PACK SIMULATOR" << ANSI_COLOR_RESET << std::endl;
    cout << "  ~Nyitasok~" << endl << endl;
    cout << ANSI_COLOR_ORANGE << "                                        &> Egyenleged: " << ANSI_COLOR_RESET << curr << endl << endl;
    cout << "       _______________     _______________     _______________     " << endl;
    cout << "       {   STANDARD  }     {    ULTRA    }     {   PREMIUM   }     " << endl;
    cout << "       uuuuuuuuuuuuuuu     uuuuuuuuuuuuuuu     uuuuuuuuuuuuuuu     " << endl;
    cout << "       |             |     |             |     |             |     " << endl;
    cout << "       |             |     |             |     |             |     " << endl;
    cout << "       |             |     |             |     |             |     " << endl;
    cout << "       |             |     |             |     |             |     " << endl;
    cout << "       ~~~~~~~~~~~~~~~     ~~~~~~~~~~~~~~~     ~~~~~~~~~~~~~~~     " << endl;
    cout << endl;
    cout << "          1. opcio            2. opcio            3. opcio         " << endl;
    cout << "         (ingyenes)          (200 coin)          (500 coin)        " << endl << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "         [visszalepes a 4-es gomb beadasaval]" <<  ANSI_COLOR_RESET << endl;
    cout << endl << endl;
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
}

// nincs elegendo zsetonod csomagnyitas kirajzolasa
void drawPurchaseFailed() {

    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_RED << "  PACK SIMULATOR" << ANSI_COLOR_RESET << std::endl;
    cout << "  ~Nyitasok~" << endl << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "                       Egyenleged: " << ANSI_COLOR_RED << "NEM ELEG!!" << ANSI_COLOR_RESET << endl << endl;
    cout << "       _______________     _______________     _______________     " << endl;
    cout << "       {   STANDARD  }     {    ULTRA    }     {   PREMIUM   }     " << endl;
    cout << "       uuuuuuuuuuuuuuu     uuuuuuuuuuuuuuu     uuuuuuuuuuuuuuu     " << endl;
    cout << "       |             |     |             |     |             |     " << endl;
    cout << "       |             |     |             |     |             |     " << endl;
    cout << "       |             |     |             |     |             |     " << endl;
    cout << "       |             |     |             |     |             |     " << endl;
    cout << "       ~~~~~~~~~~~~~~~     ~~~~~~~~~~~~~~~     ~~~~~~~~~~~~~~~     " << endl;
    cout << endl;
    cout << "          1. opcio            2. opcio            3. opcio         " << endl;
    cout << "         (ingyenes)          (200 coin)          (500 coin)        " << endl << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << " Nem volt eleg penzed a csomag megvasarlasara! " << ANSI_COLOR_RESET << endl;
    cout << endl << endl;
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
}

// csomag kinyitasanak menuje
void drawPackOpen() {
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_RED << "  PACK SIMULATOR" << ANSI_COLOR_RESET << std::endl;
    cout << "  ~Nyitasok - Csomag megtekintese~" << endl << endl << endl;
}

// bucsu, kilepes kirajzolasa
void drawQuitGame() {
    cout << ANSI_COLOR_BLUE << "----------------------------------------" << ANSI_COLOR_RESET << endl << endl;

    cout << ANSI_COLOR_RED << " PACK SIMULATOR" << ANSI_COLOR_RESET << endl << endl << endl;

    cout << ANSI_COLOR_BLUE << " Koszonjuk, hogy velunk jatszodtal!" << ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_BLUE << " Szep napot!" << ANSI_COLOR_RESET << endl << endl;

    cout << ANSI_COLOR_BLUE << "----------------------------------------" << ANSI_COLOR_RESET << endl << endl;

}

// listazasi menu kirajzolasa
void drawInventoryMenu() {
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_RED << "  PACK SIMULATOR" << ANSI_COLOR_RESET << std::endl;
    cout << "  ~Inventoy~" << endl << endl << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "     #############################################       " << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "     V                                           V       " << ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "     V" << ANSI_COLOR_ORANGE <<"   Lehetosegek:"<<ANSI_COLOR_LIGHT_BLUE<<"                            V       "<<ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "     V                                           V       " << ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "     V" << ANSI_COLOR_ORANGE <<" > listazas roviden, novekvo OVR      (1)" << ANSI_COLOR_LIGHT_BLUE << "  V       " << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "     V" << ANSI_COLOR_ORANGE <<" > listazas roviden, csokkeno OVR     (2)" << ANSI_COLOR_LIGHT_BLUE << "  V       " << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "     V" << ANSI_COLOR_ORANGE <<" > listazas hosszan, novekvo OVR      (3)" << ANSI_COLOR_LIGHT_BLUE << "  V       " << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "     V" << ANSI_COLOR_ORANGE <<" > listazas hosszan, csokkeno OVR     (4)" << ANSI_COLOR_LIGHT_BLUE << "  V       " << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "     V" << ANSI_COLOR_ORANGE <<" > Kilepes a menube                   (5)" << ANSI_COLOR_LIGHT_BLUE << "  V       " << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "     V                                           V       " << ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "     V                                           V       " << ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "     V                                           V       " << ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_LIGHT_BLUE << "     #############################################       " << endl;
    cout << endl << endl;
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;

}

// jatekos letenek kideritese (animacio)
void drawOpeningAnimation() {
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------------------" << ANSI_COLOR_RESET << endl;
    cout << "                           " << ANSI_COLOR_ORANGE << "PACK SIMULATOR" << ANSI_COLOR_RESET << endl;
    cout << "                           " << ANSI_COLOR_RED << "Csomag kinyitasa!" << ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << endl;
    cout << endl;
    cout << "   " << ANSI_COLOR_LIGHT_BLUE <<"# Keszen allsz a jatekos kinyitasara ? # " << ANSI_COLOR_RESET << endl << endl;
}

// adatbazis betoltesi hiba
void drawError() {
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------------------" << ANSI_COLOR_RESET << endl;
    cout << "                           " << ANSI_COLOR_ORANGE << "PACK SIMULATOR" << ANSI_COLOR_RESET << endl;
    cout << "                           " << ANSI_COLOR_RED << "BETOLTESI HIBA!" << ANSI_COLOR_RESET << endl;
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << "  >> Hiba tortent a jatek adatbazisanak betoltesevel:(" << endl;
    cout << "     Valoszinuleg hibas vagy mar nem letezik a fajl!      " << endl;
    cout << "     Kerjuk, keresse fel a weboldalunkat bovebb infokert! "<< endl;
    cout << endl;
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------------------" << ANSI_COLOR_RESET << endl;
}

// listazasok 1.
void drawTableSA(AVLFa<Player> &inventory) {
    cout << CLEAR_SCREEN;

    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_RED << "  PACK SIMULATOR" << ANSI_COLOR_RESET << std::endl;
    cout << "  ~Inventoy - Listazasok~" << endl << endl;

    string seg;
    cout << ANSI_COLOR_ORANGE << "* Listazas roviden, novekvo OVR szerint: " << endl << endl << ANSI_COLOR_RESET;
    inventory.printShortAsc();
    cout << endl;
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_ORANGE << " A kilepeshez olvass be barmit!" << endl << ANSI_COLOR_RESET;
    cout << ">";
    cin >> seg;
}

// listazasok 2.
void drawTableSD(AVLFa<Player>& inventory) {
    cout << CLEAR_SCREEN;

    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_RED << "  PACK SIMULATOR" << ANSI_COLOR_RESET << std::endl;
    cout << "  ~Inventoy - Listazasok~" << endl << endl;

    string seg;
    cout << ANSI_COLOR_ORANGE << "* Listazas roviden, csokkeno OVR szerint: " << endl << endl << ANSI_COLOR_RESET;
    inventory.printShortDes();
    cout << endl;
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_ORANGE << " A kilepeshez olvass be barmit!" << endl << ANSI_COLOR_RESET;
    cout << ">";
    cin >> seg;
}

// listazasok 3.
void drawTableLA(AVLFa<Player>& inventory) {
    cout << CLEAR_SCREEN;

    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_RED << "  PACK SIMULATOR" << ANSI_COLOR_RESET << std::endl;
    cout << "  ~Inventoy - Listazasok~" << endl << endl;

    string seg;
    cout << ANSI_COLOR_ORANGE << "* Listazas hosszan, novekvo OVR szerint: " << endl << endl << ANSI_COLOR_RESET;
    inventory.printLongAsc();
    cout << endl;
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_ORANGE << " A kilepeshez olvass be barmit!" << endl << ANSI_COLOR_RESET;
    cout << ">";
    cin >> seg;
}

// listazasok 4.
void drawTableLD(AVLFa<Player>& inventory) {
    cout << CLEAR_SCREEN;

    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_RED << "  PACK SIMULATOR" << ANSI_COLOR_RESET << std::endl;
    cout << "  ~Inventoy - Listazasok~" << endl << endl;

    string seg;
    cout << ANSI_COLOR_ORANGE << "* Listazas hosszan, csokkeno OVR szerint: " << endl << endl << ANSI_COLOR_RESET;
    inventory.printLongDes();
    cout << endl;
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_ORANGE << " A kilepeshez olvass be barmit!" << endl << ANSI_COLOR_RESET;
    cout << ">";
    cin >> seg;
}

// Eladasi menu kirajzolasa
void drawTradeStartMenu() {
    cout << ANSI_COLOR_BLUE << "-----------------------------------------------------------------------" << ANSI_COLOR_RESET << endl << endl;
    cout << ANSI_COLOR_RED << "  PACK SIMULATOR" << ANSI_COLOR_RESET << std::endl;
    cout << "  ~Jatekosok eladasa~" << endl << endl << endl;
    cout << ANSI_COLOR_ORANGE << "  * Itt megkeresheted az eladasra szant jatekosodat nev es OVR szerint! * " ANSI_COLOR_RESET << endl << endl;
    cout << "  Add meg a keresett jatekos OVR-et: " << endl;
    cout << "  > ";
}

// Menu logikak 

// fomenu logikaja
int mainMenu() {
    cout << CLEAR_SCREEN;

    int navigation;
    bool error = false;

    do {
        drawMainMenu();

        if (error) {
            cout << "Nincs ilyen menupont, probald ujra!" << endl;
        }
        else cout << "A kivalasztott menupont: " << endl;
        cout << ">";

        cin >> navigation;

        if (navigation < 1 || navigation > 4) {

            error = true;
            cout << CLEAR_SCREEN;
        }
    } while (navigation < 1 || navigation > 4);

    return navigation;
}

// csomag nyitasanak menuje
int openingMenu(int curr) {
    cout << CLEAR_SCREEN;

    int navigation;
    bool error = false;

    do {
        drawPacksMenu(curr);

        if (error) {
            cout << "Nincs ilyen csomag, probald ujra!" << endl;
        }

        cout << "> ";
        cin >> navigation;

        if (navigation < 1 || navigation > 4) {

            error = true;
            cout << CLEAR_SCREEN;
        }
    } while (navigation < 1 || navigation > 4);

    return navigation;
}

// sikertelen tranzakcios logika
void notEnough() {
    cout << CLEAR_SCREEN;
    drawPurchaseFailed();
    string temp;

    cout << "A folytatashoz olvass be akarmit: ";
    cin >> temp;
}

// listazas, inventory logika
int openInvMenu() {
    cout << CLEAR_SCREEN;

    int navigation;
    bool error = false;

    do {
        drawInventoryMenu();

        if (error) {
            cout << "Nincs ilyen menupont, valassz ujra!" << endl;
        }

        cout << "> ";
        cin >> navigation;

        if (navigation < 1 || navigation > 5) {

            error = true;
            cout << CLEAR_SCREEN;
        }
    } while (navigation < 1 || navigation > 5);

    return navigation;
}

// jatekos megjelenitese teljesen
void openingAnimation(Player &pl) {
    cout << CLEAR_SCREEN;

    string any;
    bool error = false;

    drawOpeningAnimation();

    cout << ANSI_COLOR_BLUE << "    Nezzuk akkor!" << ANSI_COLOR_RESET << endl << endl;
    cout << "    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl << endl;
    cout << ANSI_COLOR_ORANGE << "     * Nemzetiseg: " << ANSI_COLOR_RESET;
    cin >> any;
    cout << "     > " << pl.getNation() << endl << endl;
    cout << ANSI_COLOR_ORANGE << "     * Jatekos posztja: " << ANSI_COLOR_RESET;
    cin >> any;
    cout << "     > " << pl.getPosition() << endl << endl << ANSI_COLOR_RESET;
    cout << ANSI_COLOR_ORANGE << "     * Bajnoksag: " << ANSI_COLOR_RESET;
    cin >> any;
    cout << "     > " << pl.getLeague() << endl << endl;
    cout << ANSI_COLOR_ORANGE << "     * OVERALL: " << ANSI_COLOR_RESET;
    cin >> any;
    cout << "     > " << pl.getOvr() << endl << endl;
    cout << ANSI_COLOR_ORANGE << "     A teljes felfedeshez nyomj akarmit: " << ANSI_COLOR_RESET;
    cin >> any;
    cout << endl << endl;
    cout << "    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl << endl;
    cout << "     " << ANSI_COLOR_RED << "!!GRATULALUNK!! "<<ANSI_COLOR_RESET<<" Kinyitottad " << pl.getName() << " futbalistat!" << endl << endl;
    cout << "     Az inventoryban megtekintheted a jatekosod!" << endl;
    cout << "     A folytatashoz nyomd meg barmelyik karaktert!" << endl;
    cout << "     >";
    cin >> any;

}

// eladasi menu logikaja
int searchMenu(AVLFa<Player>& inventory, int &curr) {

    cout << CLEAR_SCREEN;

    int ovr;
    string nev;

    drawTradeStartMenu();

    cin >> ovr;
    cout << endl;
    cout << "  Add meg a keresett jatekos nevet is: " << endl;
    cout << "  > ";
    cin >> nev;
    cout << endl;

    Player keresett(ovr, nev);
    Node<Player>* foundNode = inventory.search(keresett);
    string seged;

    if (foundNode != nullptr) {
        Player& talaltJatekos = foundNode->key;

        cout << ANSI_COLOR_RED << "     A keresett jatekos adatai:  " << ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_LIGHT_BLUE << "     > NEV: " << ANSI_COLOR_RESET << talaltJatekos.getName() << endl;
        cout << ANSI_COLOR_LIGHT_BLUE << "     > ERTEKELES:  " << ANSI_COLOR_RESET << talaltJatekos.getOvr() << ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_LIGHT_BLUE << "     > BAJNOKSAG:  " << ANSI_COLOR_RESET << talaltJatekos.getLeague() << ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_LIGHT_BLUE << "     > KLUBCSAPAT: " << ANSI_COLOR_RESET << talaltJatekos.getClub() << ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_LIGHT_BLUE << "     > POZICIO:    " << ANSI_COLOR_RESET << talaltJatekos.getPosition() << ANSI_COLOR_RESET << endl;
        cout << ANSI_COLOR_LIGHT_BLUE << "     > NEMZETISEG: " << ANSI_COLOR_RESET << talaltJatekos.getNation() << ANSI_COLOR_RESET << endl;
        cout << endl << endl;
        cout << " A jatekos ara : " << ANSI_COLOR_RED << talaltJatekos.getPrice() << endl;

        
        cout << ANSI_COLOR_RED << "  Szeretnel megvalni az adott jatekostol? (0 - igen, 1 - nem) " << ANSI_COLOR_RESET << endl;
        cout << "  > ";
        int opcio;
        cin >> opcio;
        cout << endl;
        
        
        if (opcio == 1) {
            cout << ANSI_COLOR_ORANGE << "  * Rendben van! Kilepeshez olvass be akarmit! * " << ANSI_COLOR_RESET << endl;
        }

        else if (opcio == 0) {

            curr += talaltJatekos.getPrice();
            inventory.remove(talaltJatekos);
            cout << ANSI_COLOR_ORANGE << "  * Sikeresen eladtad! Az egyenleged: " << curr << endl;
            cout << "  A folyatashoz olvass be barmit!*" << ANSI_COLOR_RESET << endl;
                
        }
        else {
            cout << ANSI_COLOR_ORANGE << "  * Nincs ilyen opcio, visszalepeshez olvas be barmit! * " << ANSI_COLOR_RESET << endl;
        }
        
        
    }
    else {
        cout << ANSI_COLOR_RED << "  * A keresett jatekos nem talalhato. A folytatashoz olvass be barmit *" << ANSI_COLOR_RESET << endl;
    }

    cout << "  >";
    cin >> seged;

    return 0;
}


