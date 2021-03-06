#ifndef __PLAYER_H_
#define __PLAYER_H_
#include<iostream>

enum class PlayerStatus {
	ALIVE,
	DEAD,
};

class Player
{
private:
	// The specs of player characters, status(alive or dead) and health points ranging from 0 to 100
	PlayerStatus _status;
	std::string _name;
	int _hp;

public:
	Player(std::string &name, int& value); // constructor of player object

	PlayerStatus check_alive();
	int get_hp();
	PlayerStatus get_status();
	std::string get_name() const;
	void change_hp(int& x);
};

#endif
