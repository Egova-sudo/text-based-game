#ifndef __GAME_H_
#define __GAME_H_

#include <vector>
#include <memory>
#include "player.h"

enum class Status
{
	New,
	Load,

};
class Game
{
private:
	Status _status;
	const unsigned int _id;
	static inline unsigned int counter = 0; // inline command requires C++17 support
	unsigned int _turn;
	std::vector<std::unique_ptr<Player>> _players;

public:
	Game(); // Create-game constructor
	Game(int x); // overloading
	void run();
	void get_id();
	void print_players();
	void load();
	void save();
};

#endif


