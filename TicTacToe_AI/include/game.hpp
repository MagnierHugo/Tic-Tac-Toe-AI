#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <typeindex>

#include "board.hpp"
#include "player.hpp"


class Game {

	Board board;

	std::array<Player*, 2> players = {
		new Player('X'), new Player('O')
	};

	bool CheckGameOver(char currentPlayerSymbol) const;

public:
	Game();

	int Run();
};