#pragma once
#include "player.hpp"


class AIPlayer : public Player {

	struct TestedPlay {
		std::pair<int, int> position;
		int value;
	};

	TestedPlay AlphaBetaPruning(const Board& board, const int depth, int alpha, int beta) const;

public:
	AIPlayer(Player player);

	void Play(Board& board) override;
};