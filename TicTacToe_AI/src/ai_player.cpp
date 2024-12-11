#include "../include/ai_player.hpp"


const int INF = std::numeric_limits<int>::max();


AIPlayer::AIPlayer(Player player) {
	symbol = player.GetSymbol();
}


void AIPlayer::Play(Board& board, sf::RenderWindow& window) {
	TestedPlay play = AlphaBetaPruning(board, 0, -INF, INF);
	board.PlaceOnGrid(symbol, play.position);
}


AIPlayer::TestedPlay AIPlayer::AlphaBetaPruning(const Board& board, const int depth, int alpha, int beta) const {
	bool maximizing = (depth % 2 == 0);

	// !maximizing because the function is called after the move is made
	// so the maximizing of the parent call is used
	if (board.CheckWin()) { return { {}, !maximizing ? 10 - depth : -10 + depth }; }
	if (board.IsBoardFull()) { return { {}, 0 }; }

	TestedPlay bestPlay = { {}, maximizing ? -INF : INF };
	char player = maximizing ? (symbol == 'X') ? 'O' : 'X' : symbol ;

	for (std::pair<int, int> play : board.GetPossiblePlay()) {
		int playValue = AlphaBetaPruning(board.PlaceOnGridCopy(player, play), depth + 1, alpha, beta).value;
		if (maximizing) {
			if (bestPlay.value < playValue) { bestPlay = { play, playValue }; }
			if (alpha >= beta) { break; }
			alpha = std::max(alpha, bestPlay.value);
		}
		else {
			if (bestPlay.value > playValue) { bestPlay = { play, playValue }; }
			if (alpha >= beta) { break; }
			beta = std::min(beta, bestPlay.value);
		}
	}
	return bestPlay;
}