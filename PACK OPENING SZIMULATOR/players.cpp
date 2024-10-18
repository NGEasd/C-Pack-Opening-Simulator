#include "players.h"

// alapertelmezett konstruktor
Player::Player() {
	ovr = 70;
	name = "Szabo Akos";
	position = "Hatved";
	club = "Barcelona";
	league = "La Liga";
	nation = "Magyarorszag";
	price = 0;
}


// minden adattagot inicializalo konstruktor
// ezt hasznalom az adatbazis feltoltesehez
Player::Player(int pts, string n, string p, string c, string l, string o, int a) {
	ovr = pts;
	name = n;
	position = p;
	club = c;
	league = l;
	nation = o;
	price = a;
}


// kereseshez szukseges konstruktor
// tulajdonkeppen felepiti a kulcsot
Player::Player(int pts, string n) {
	ovr = pts;
	name = n;
	position = "-";
	club = "-";
	league = "-";
	nation = "-";
	price = 0;
}

// getter fuggvenyek
int Player::getOvr() {
	return this->ovr;
}

string Player::getPosition() {
	return this->position;
}

string Player::getClub() {
	return this->club;
}

string Player::getLeague() {
	return this->league;
}

string Player::getName() {
	return this->name;
}

string Player::getNation() {
	return this->nation;
}

int Player::getPrice() {
	return this->price;
}


// operatorok a kereseshez

// nagyobb operator tulterhelese
bool Player::operator<(const Player& other) const {
	if (ovr == other.ovr) {
		return name < other.name;
	}
	return ovr < other.ovr;
}

// kisebb operator tulterhelese
bool Player::operator>(const Player& other) const {
	if (ovr == other.ovr) {
		return name > other.name;
	}
	return ovr > other.ovr;
}

// egyenlo operator tulterhelese
bool Player::operator==(const Player& other) const {
	if (ovr == other.ovr && name == other.name) {
		return true;
	}
	return false;
}

