#ifndef PLAYERS_H
#define PLAYERS_H

#include <iostream>
#include <string.h>

using namespace std;

class Player {
	
private:

	int ovr;
	string name;
	string position;
	string club;
	string league;
	string nation;
	int price;

public:

	// konstruktorok
	Player();
	Player(int, string, string, string, string, string, int);
	Player(int, string);

	// lekerdezo metodusok
	int getOvr();
	string getName();
	string getPosition();
	string getClub();
	string getLeague();
	string getNation();
	int getPrice();

	// osszehasonlito operator
	bool operator<(const Player&) const;
	bool operator>(const Player&) const;
	bool operator==(const Player&) const;

};

#endif
