#include "Map.h"

void Map::init() {

	player = new Player(Vector2f(70, 70), "images/player1.png");

	for (int i = 0; i < HEIGHT_MAP; i++) {

		for (int j = 0; j < WIDTH_MAP; j++)

		{
			if (TileMap[i][j] == 'm') {

				Floor* floor = new Floor(Vector2f(j * 60, i * 60), "images/floor.png");

				entities.push_back(floor); 

				Money* money = new Money(Vector2f(j * 60, i * 60), "images/coin.png");

				entities.push_back(money);

			}

			if (TileMap[i][j] == 'g') { 

				Floor* floor = new Floor(Vector2f(j * 60, i * 60), "images/floor.png");

				entities.push_back(floor);

			}
			if (TileMap[i][j] == 'k') { 

				Wall* wall = new Wall(Vector2f(j * 60, i * 60), "images/brick.png");

				entities.push_back(wall);

			}

			if (TileMap[i][j] == 'a') {  
				

				Floor* floor = new Floor(Vector2f(j * 60, i * 60), "images/floor.png");

				entities.push_back(floor); 
				Ranger* ranger = new Ranger(Vector2f(j * 60 + 60, i * 60), "images/ranger.png");  
				entities.push_back(ranger);  
				entities.push_back(ranger->getArrow());  
			}

		}
	}
}

Map::Map() {

	init();

}

void Map::update() {

	int coinsCounter = 0;

	for (auto it = entities.begin(); it != entities.end(); it++) {

		if ((*it)->getName() == "money") {

			coinsCounter++;

		}

	}

	if (coinsCounter == 0) {

		player->setState("win");

	}

	player->update();

	for (auto it = entities.begin(); it != entities.end(); it++) {
		if ((*it)->getName() == "ranger") {
			(*it)->update();
			/*Ranger* ranger = (Ranger*)(*it);
			ranger->collision(entities);*/
		}
	}

	for (auto it = entities.begin(); it != entities.end();) {
		FloatRect playerCollider = player->getSprite().getGlobalBounds();
		FloatRect otherCollider = (*it)->getSprite().getGlobalBounds();

		if (playerCollider.intersects(otherCollider) && (*it)->getName() == "money") { 

			player->setCoins(player->getCoins() + 1);

			entities.erase(it++);			
		}
		else if (playerCollider.intersects(otherCollider) && (*it)->getName() == "wall") { 

			player->setSpeed(Vector2f(-player->getSpeed().x, -player->getSpeed().y));

			player->update();

			it++;

		}
		else if ((*it)->getName() == "ranger") {
			Ranger* ranger = (Ranger*)(*it);

			ranger->collision(entities);

			Arrow* arrow = ranger->getArrow();

			FloatRect otherCollider = arrow->getSprite().getGlobalBounds();

			if (playerCollider.intersects(otherCollider)) {

				player->setState("loose");
			}
			it++;
		}
		else {

			it++;

		}

	}
}

Player* Map::getPlayer() {

	return player;

}

void Map::draw(RenderWindow& window) {

	for (auto it = entities.begin(); it != entities.end(); it++) { 
		window.draw((*it)->getSprite());
	}

	window.draw(player->getSprite());

}