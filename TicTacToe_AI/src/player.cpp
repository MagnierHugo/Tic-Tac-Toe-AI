#include "../include/player.hpp"

#include "../include/utilities.hpp"


void Player::Play(Board& board, sf::RenderWindow& window) {
	int row = 0;
	int column = 0;

	bool played = false;

	while (!played) {

		sf::Event e;
		while (window.pollEvent(e) != 0) {
			if (e.type == sf::Event::Closed) {
				window.close();
			}
			if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
				for (int i = 0; i < 9; i++) {
					sf::FloatRect cellRect = board.GetGridColliders()[i];
					if (cellRect.intersects({ mousePos.x, mousePos.y, 1, 1 })) {
						std::cout << i << std::endl;
						row = i / 3;
						column = i % 3;
						if (!board.IsValidePlay(row, column)) { continue; }
						played = true;
						break;
					}
				}
			}
		}

	}

	board.PlaceOnGrid(symbol, row, column);
}


char Player::GetSymbol() const {
	return symbol;
}