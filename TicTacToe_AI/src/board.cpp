#include "../include/board.hpp"

#include <iostream>

#include "../include/utilities.hpp"


Board::Board(const Board& board) {
	grid = board.grid;
	possiblePlay = board.possiblePlay;
}


Board::PairList Board::GetPossiblePlay() const {
	return possiblePlay;
}


void Board::PlaceOnGrid(const char symbol, const int row, const int column) {
	grid[row][column] = symbol;
	EraseElement<PairList, std::pair<int, int>>(possiblePlay, { row, column });
}


void Board::PlaceOnGrid(const char symbol, const std::pair<int, int>& play) {
	grid[play.first][play.second] = symbol;
	EraseElement<PairList, std::pair<int, int>>(possiblePlay, play);
}


Board Board::PlaceOnGridCopy(const char symbol, const std::pair<int, int>& play) const {
	Board boardCopy = Board(*this);
	boardCopy.PlaceOnGrid(symbol, play);
	return boardCopy;
}


void Board::RenderGrid() const {
	for (int i = 0; i < 3; i++) {
		std::cout << grid[i][0] << "|" << grid[i][1] << "|" << grid[i][2] << std::endl;
		if (i < 2) {
			std::cout << "-+-+-" << std::endl;
		}
	}
	std::cout << std::endl;
}


void Board::Clear() {
	grid = { {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	} };

	possiblePlay = {
		{0, 0}, {0, 1}, {0, 2},
		{1, 0}, {1, 1}, {1, 2},
		{2, 0}, {2, 1}, {2, 2}
	};
}


bool Board::CheckWin() const {
	for (int i = 0; i < 3; i++) {
		// Check Rows
		if ((' ' != grid[i][0]) && (grid[i][0] == grid[i][1]) && (grid[i][1] == grid[i][2])) {
			return true;
		}

		//Check Columns
		if ((' ' != grid[0][i]) && (grid[0][i] == grid[1][i]) && (grid[1][i] == grid[2][i])) {
			return true;
		}

		//Check Diagonals
		if (i > 1) { continue; }
		else if ((' ' != grid[0][0 + 2 * i]) && (grid[0][0 + 2 * i] == grid[1][1]) && (grid[1][1] == grid[2][2 - 2 * i])) {
			return true;
		}
	}
	return false;
}


bool Board::IsBoardFull() const {
	return possiblePlay.empty();
}


bool Board::IsValidePlay(const int row, const int column) const {
	if (!(0 <= row && row < 3) || !(0 <= column && column < 3)) {
		std::cout << "Coordinate invalid !!" << std::endl;
		return false;
	}
	if (grid[row][column] != ' ') {
		std::cout << "Position already taken !!" << std::endl;
		return false;
	}
	return true;
}