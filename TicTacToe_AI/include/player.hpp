#pragma once
#include <array>
#include <vector>

#include "board.hpp"


class Player {
protected:

	char symbol;

public:
	Player() = default;
	Player(char symbol_) : symbol(symbol_) {}

	virtual void Play(Board& board, sf::RenderWindow& window);
	char GetSymbol() const;

};