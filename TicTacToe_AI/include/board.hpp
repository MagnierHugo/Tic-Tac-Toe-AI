#pragma once
#include <array>
#include <vector>


class Board {

	using Grid = std::array<std::array<char, 3>, 3>;
	using PairList = std::vector<std::pair<int, int>>;

	Grid grid = { {
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '}
	} };

	PairList possiblePlay = {
		{0, 0}, {0, 1}, {0, 2},
		{1, 0}, {1, 1}, {1, 2},
		{2, 0}, {2, 1}, {2, 2}
	};

public:
	Board() = default;
	Board(const Board& board);

	PairList GetPossiblePlay() const;

	void PlaceOnGrid(const char symbol, const int row, const int column);
	void PlaceOnGrid(const char symbol, const std::pair<int, int>& play);
	Board PlaceOnGridCopy(const char symbol, const std::pair<int, int>& play) const;

	void RenderGrid() const;
	void Clear();

	bool CheckWin() const;
	bool IsBoardFull() const;
	bool IsValidePlay(const int row, const int column) const;

};