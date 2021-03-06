#include<iostream>
#include "player.h"

Player::Player(std::string &name, int& value): _name(name), _hp(value), _status(PlayerStatus::ALIVE){
	std::cout << "Player " << name << " is created (HP=" << _hp << ").\n";
	}

// a method to damage the health of our hero
void Player::change_hp(int& x) {
	_hp = x;
}

// check and update the life status of fighter
PlayerStatus Player::check_alive() {
	if (_hp > 0) {
		_status = PlayerStatus::ALIVE;
	}
	else {
		_status = PlayerStatus::DEAD;
	}
	return _status;
}

// return its health point 
int Player::get_hp() {
	return _hp;
}

// that one actually is unnecessary
PlayerStatus Player::get_status() {
	return _status;
}

// get the name of our hero, since the name will not change ever for one specific character. Then make it const variable to make it compile-time computation
std::string Player::get_name() const {
	return _name;
}
