#include "../include/game.hpp"

#include "../include/ai_player.hpp"
#include "../include/utilities.hpp"


Game::Game() {
	int nbrPlayer;
	_condition_func func = [&]() -> bool { return (0 > nbrPlayer) && (nbrPlayer > 2); };
	AskUser<int>(nbrPlayer, "How many players ? (between 0 and 2)", func);

	if (nbrPlayer == 1) {
		Player* temp = players[1];
		players[1] = new AIPlayer(*temp);
		delete temp;
	}
	else if (nbrPlayer == 0){
		for (int i = 0; i < 2; i++) {
			Player* temp = players[i];
			players[i] = new AIPlayer(*temp);
			delete temp;
		}
	}

	window.create(sf::VideoMode(1440, 1080), "Tic Tac Toe AI");
}


bool Game::CheckGameOver(char currentPlayerSymbol) const {
	if (board.CheckWin()) {
		std::cout << "Player " << currentPlayerSymbol << " Win !!" << std::endl;
		return true;
	}
	if (board.IsBoardFull()) {
		std::cout << "It's a tie !" << std::endl;
		return true;
	}
	return false;
}


int Game::Run() {
	bool playing = true;

	while (window.isOpen()) {

		sf::Event e;
		while (window.pollEvent(e) != 0) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
		}

		for (Player* player : players) {
			board.RenderGrid(window);
			player->Play(board);
			if (CheckGameOver(player->GetSymbol())) {
				board.RenderGrid(window);
				std::cout << "Game Over !!" << std::endl;
				playing = false;
				break;
			}
		}

		if (!playing) {
			std::string answer;
			_condition_func func = [&]() -> bool { Str_ToLower(answer); return !Contains<std::array<std::string, 4>, std::string>({ "y", "yes", "n", "no" }, answer); };
			AskUser<std::string>(answer, "Continue Playing ? (yes or no)", func);

			if (answer == "n" || answer == "no") {
				window.close();
				return 0; 
			}
			playing = true;
			board.Clear();
		}
	}
}