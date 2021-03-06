#include <iostream>
#include <vector>
#include <memory>
#include <tuple>

#include "game.h"
#include "player.h"
#include "data_management.h"


// Ask for player name on terminal
std::string ask_for_player_name()
{
	std::string name;
	std::cout << "Name of the player?\n";
	std::cin >> name;
	return name;
}

// Create new game here
Game::Game():_id(Game::counter++),_turn(0),_status(Status::New){

	// Let's first prompt the name of our characters and create Player objects via a vector containing smart pointers to 
	// the adresses of Player objects
	std::string name1 = ask_for_player_name();
	std::string name2 = "Alpha";
	
	// Features of character
	int hp1 = 100;
	int hp2 = 100;

	// Create player characters
	_players.push_back(std::make_unique<Player>(name1, hp1));
	_players.push_back(std::make_unique<Player>(name2, hp2));
	std::cout << "New game is starting...\n";
	print_players();
}

// Create a game object to be filled from savefile 
Game::Game(int x) :_id(Game::counter++),_status(Status::Load) {
	
}

// Check _players vector containing pointer to Player objects
void Game::print_players() {
	std::cout << "Available characters: \n";
	for (auto &P : _players) {
		std::cout << P->get_name() <<","<< P->get_hp()<< std::endl;
	}
}

// Load game method
void Game::load() {

	// Data is fecthed from .csv save file
	std::tuple < std::vector<std::string>, std::vector<int>> all = load_file();
	std::cout << "Game is loading...\n";

	//Divide data into multiple variables
	auto names = std::get<0>(all);
	auto hps = std::get<1>(all);

	// Attribute these data to members of Game class
	for (int i = 0; i < names.size(); i++) {
		_players.push_back(std::make_unique<Player>(names[i],hps[i]));
	}		
	print_players();
}

// Save game method
void Game::save() {
	std::vector<std::string> names;
	std::vector<int> hps;

	for (auto& P : _players) {
		names.push_back(P->get_name());
		hps.push_back(P->get_hp());
	}
	std::tuple < std::vector<std::string>, std::vector<int>> all = { names,hps };
	save_file(all);
}


// Retrieve the game id
void Game::get_id() {
	std::cout << "Id of game: " << _id << "\n";
}

// Run the main loop
void Game::run() {

	std::cout << "0.Fight\n1.Show stats\n2.Save\n3.Exit\n"; // Main interface for user 

	int x; // that variable will contain the choice of user
	int i = 0; // the index of players' vector

	
	// This part is the main game loop, it will loop until player dies. Every turn it checks the health condition of player and update it to DEAD
	// if its health point is under zero. Then, while_param will be modified to 0 to terminate the while loop. Four different options are provided
    // to the user, which it can choose Fight, show stats, save the current game and exit. This is implemented by switch case statements.
	unsigned int while_param = 1;
	while (while_param){
		_turn += 1;
		std::cout << "Turn "<<_turn<<": ";
		std::cin >> x;
		switch (x)
		{
		case 0: // Fight
		{
			std::unique_ptr<Player> &P = _players[i]; // call-by-reference of _players[0] address

			// dummy fight simulator
			auto hp = P->get_hp();
			auto new_hp = hp - 24;
			P->change_hp(new_hp); 

			// check our character has died this turn or not
			PlayerStatus status = P->check_alive();
			if (status == PlayerStatus::DEAD) {
				std::cout << "Character is dead...\n"; 
				while_param = 0;
			}
			break;
		}
		case 1: // Retrieve player stats
		{
			for (auto& P : _players) {
				std::cout << P->get_name() << ": HP = " << P->get_hp() << std::endl;
			}
			break;
		}
		case 2: // Save game
		{
			save();
			break;
		}
		case 3: // Terminate
		{
			while_param = 0;
			break;
		}
		}
	}
	std::cout << "Game is over.\n";
}
