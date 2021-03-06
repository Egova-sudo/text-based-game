#include <iostream>
#include "game.h"

// Main body of text-based game
int main() {

	int x;
	std::cout << "--- Main Menu ---\n1.New Game\n2.Load Game\n3.Exit\n----------------\nChoice: ";
	std::cin >> x;

	switch (x) {
	case 1:
	{
		Game NewGame;
		NewGame.get_id();
		NewGame.run();
		break;
	}
	case 2:
	{   
		Game OldGame(-1);
		OldGame.load();
		OldGame.run();
		break;
	}
	case 3:
		std::cout << "Exiting...\n";
		break;
	}

	system("pause");
}