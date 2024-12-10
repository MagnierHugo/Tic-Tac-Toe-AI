#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <typeindex>
#include <SFML/Graphics.hpp>

#include "board.hpp"
#include "player.hpp"


class Game {

	sf::RenderWindow window;
	Board board;

	std::array<Player*, 2> players = {
		new Player('X'), new Player('O')
	};

	bool CheckGameOver(char currentPlayerSymbol) const;

public:
	Game();

	int Run();
};