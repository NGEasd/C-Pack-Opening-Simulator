#include "packs.h"

// ingyenes csomag
Player freePack(vector<Player>& a) {

    // random generator
    std::random_device random;
    std::mt19937 gen(random());

    // Szabad csomag eselyei
    std::vector<double> freeProbabilities = {
        0.0801,     // 70
        0.08,       // 71
        0.08,       // 72
        0.08,       // 73
        0.08,       // 74
        0.08,       // 75
        0.08,       // 76
        0.08,       // 77
        0.08,       // 78
        0.08,       // 79
        0.04,       // 80
        0.04,       // 81
        0.03,       // 82
        0.02,       // 83
        0.02,       // 84
        0.01,       // 85
        0.01,       // 86
        0.01,       // 87
        0.005,      // 88
        0.003,      // 89
        0.002,      // 90 - 99%
        0.001,      // 91
        0.001,      // 92
        0.001,      // 93
        0.001,      // 94
        0.001,      // 95
        0.001,      // 96
        0.001,      // 97
        0.001,      // 98
        0.001       // 99
    };

    // Elosztas
    std::discrete_distribution<> distFree(freeProbabilities.begin(), freeProbabilities.end());

    // OVR generalas
    int randomOVR = 70 + distFree(gen);

    // Jatekos kivalasztasa
    int id;

    // kereses az adatbazisbol
    do {
        id = gen() % a.size();
    } while (a[id].getOvr() != randomOVR);

    return a[id];
}


// Ultra csomag
Player ultraPack(vector<Player>& a) {

    // generatorok
    std::random_device random;
    std::mt19937 gen(random());

    // Szabad csomag eselyei
    std::vector<double> freeProbabilities = {
        0.01,   // 70
        0.01,   // 71
        0.01,   // 72
        0.01,   // 73
        0.01,   // 74
        0.01,   // 75
        0.06,   // 76
        0.06,   // 77
        0.07,   // 78
        0.07,   // 79
        0.08,   // 80 
        0.084,  // 81
        0.08,   // 82
        0.08,   // 83
        0.08,   // 84
        0.08,   // 85
        0.04,   // 86
        0.04,   // 87 - 88%
        0.03,   // 88 - 91%
        0.03,   // 89 - 94%
        0.03,   // 90 - 97%
        0.005,  // 91
        0.005,  // 92 - 98%
        0.003,  // 93
        0.003,  // 94
        0.002,  // 95 - 1%
        0.002,  // 96 - 99%
        0.002,  // 97
        0.002,  // 98
        0.002   // 99 - 99,6%
    };

    // Eseyek elosztasa
    std::discrete_distribution<> distFree(freeProbabilities.begin(), freeProbabilities.end());

    // OVR generalas
    int randomOVR = 70 + distFree(gen);

    // Kivalasztas
    int id;

    do {
        id = rand() % a.size();
    } while (a[id].getOvr() != randomOVR);

    return a[id];
}


// Premium csomag
Player premiumPack(vector<Player>& a) {
    std::random_device random;
    std::mt19937 gen(random());

    // Szabad csomag esélyei
    std::vector<double> freeProbabilities = {
        0.005, // 70
        0.005, // 71
        0.005, // 72
        0.005, // 73
        0.005, // 74
        0.005, // 75
        0.01,  // 76
        0.01,  // 77
        0.01,  // 78
        0.01,  // 79
        0.03,  // 80
        0.05,  // 81 
        0.05,  // 82 
        0.05,  // 83 
        0.05,  // 84 
        0.09,  // 85 
        0.09,  // 86
        0.10,  // 87 
        0.10,  // 88 - 61%
        0.10,  // 89 
        0.08,  // 90 
        0.07,  // 91 
        0.05,  // 92 
        0.04,  // 93 
        0.038, // 94 
        0.03,  // 95 
        0.03,  // 96
        0.02,  // 97
        0.02,  // 98
        0.02   // 99
    };

    // Diszkrét eloszlás az esélyekhez
    std::discrete_distribution<> distFree(freeProbabilities.begin(), freeProbabilities.end());

    // OVR generálás
    int randomOVR = 70 + distFree(gen);

    // Játékos kiválasztása
    int id;
    do {
        id = rand() % a.size();
    } while (a[id].getOvr() != randomOVR);

    return a[id];
}


