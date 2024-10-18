#ifndef MENU_H
#define MENU_H
#include "players.h"
#include "avl.h"

// ANSI szoveg szinek beallitasa
#define ANSI_COLOR_BLUE "\033[34m"
#define ANSI_COLOR_RED "\033[31m"
#define ANSI_COLOR_LIGHT_BLUE "\033[94m"
#define ANSI_COLOR_RESET "\033[0m"
#define ANSI_COLOR_ORANGE "\033[38;5;208m"

// Kepernyo "tisztitasa"
#define CLEAR_SCREEN "\033[2J\033[1;1H";

    // Grafikai fuggvenyek
    void drawMainMenu();
    void drawPacksMenu(int);
    void drawPackOpen();
    void drawQuitGame();
    void drawInventoryMenu();
    void drawOpeningAnimation();
    void drawError();
    void drawPurchaseFailed();

    // Menu logika fuggvenyek
    int mainMenu();
    int openingMenu(int);
    void notEnough();
    int openInvMenu();
    void openingAnimation(Player&);
    void drawTableSA(AVLFa <Player>&);
    void drawTableSD(AVLFa <Player>&);
    void drawTableLA(AVLFa<Player>&);
    void drawTableLD(AVLFa<Player>&);
    int searchMenu(AVLFa<Player>&, int&);

    
#endif
