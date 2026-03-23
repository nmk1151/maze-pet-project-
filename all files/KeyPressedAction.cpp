#include "KeyPressedAction.h"

KeyPressedAction::KeyPressedAction() {

}

void KeyPressedAction::setPlayer(Player* player) {

	

	this->player = player;  

}

void KeyPressedAction::action() {

	if (Keyboard::isKeyPressed(Keyboard::Right)){ 
		 

		player->setSpeed(Vector2f(2, 0));

	player->setTextureRect(IntRect(int(player->currentFrame) * 80, 3 * 120, 80, 120));

	 

	}
	else if (Keyboard::isKeyPressed(Keyboard::Left)) { 
		

		player->setSpeed(Vector2f(-2, 0));

		player->setTextureRect(IntRect(int(player->currentFrame) * 80, 2 * 120, 80, 120));

		

	}
	else if (Keyboard::isKeyPressed(Keyboard::Up)) {

		

		player->setSpeed(Vector2f(0, -2));

		player->setTextureRect(IntRect(int(player->currentFrame) * 80, 1 * 120, 80, 120));

		

	}

	else if (Keyboard::isKeyPressed(Keyboard::Down)) {

		

		player->setSpeed(Vector2f(0, 2));

		

		player->setTextureRect(IntRect(int(player->currentFrame) * 80, 0, 80, 120));

		

	}

	else {

		player->setSpeed(Vector2f(0, 0));

	}

	player->currentFrame = player->currentFrame + 0.1;

	if (player->currentFrame > 4) {

		player->currentFrame = 0; 

	}
}