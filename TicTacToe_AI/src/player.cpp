#include "../include/player.hpp"

#include "../include/utilities.hpp"


void Player::Play(Board& board) {
	int row, column;
	_condition_func func = [&]() -> bool { return !board.IsValidePlay(row, column); };
	AskUser<int, int>(std::tie(row, column), symbol + static_cast<std::string>(" turn. Choose where to play (row column)"), func);
	board.PlaceOnGrid(symbol, row, column);
}


char Player::GetSymbol() const {
	return symbol;
}