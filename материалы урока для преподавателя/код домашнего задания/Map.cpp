#include "Map.h"

void Map::init() {

	player = new Player(Vector2f(70, 70), "images/player1.png");

	for (int i = 0; i < HEIGHT_MAP; i++) {// цикл по высоте карты

		for (int j = 0; j < WIDTH_MAP; j++)

		{// цикл по ширине карты
			if (TileMap[i][j] == 'm') {// если встретили монетку

				Floor* floor = new Floor(Vector2f(j * 60, i * 60), "images/floor.png");// создадим пол

				entities.push_back(floor);// добавим пол в список 

				Money* money = new Money(Vector2f(j * 60, i * 60), "images/coin.png");// создадим монетку

				entities.push_back(money);// добавим её в список

			}

			if (TileMap[i][j] == 'h') {// если встретили монетку

				Floor* floor = new Floor(Vector2f(j * 60, i * 60), "images/floor.png");// создадим пол

				entities.push_back(floor);// добавим пол в список 

				Hp* hp = new Hp(Vector2f(j * 60, i * 60), "images/hp.png");// создадим монетку

				entities.push_back(hp);// добавим её в список

			}

			if (TileMap[i][j] == 'g') {// если встретили пол 

				Floor* floor = new Floor(Vector2f(j * 60, i * 60), "images/floor.png");// создаём пол

				entities.push_back(floor);// добавляем его в список

			}
			if (TileMap[i][j] == 'k') {// если встретили стену 

				Wall* wall = new Wall(Vector2f(j * 60, i * 60), "images/brick.png");// создаём стену

				entities.push_back(wall);//добавляем её в список

			}

			if (TileMap[i][j] == 'a') {  // если на карте лучник
				//создаём пол

				Floor* floor = new Floor(Vector2f(j * 60, i * 60), "images/floor.png");

				entities.push_back(floor); // добавляем пол
				Ranger* ranger = new Ranger(Vector2f(j * 60 + 60, i * 60), "images/ranger.png");  // создаём лучника
				entities.push_back(ranger);  // добавляем лучника
				entities.push_back(ranger->getArrow());  //добавляем стрелу
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

		if (playerCollider.intersects(otherCollider) && (*it)->getName() == "money") {// если игрок столкнулся с монеткой 

			player->setCoins(player->getCoins() + 1);

			entities.erase(it++);//удаляем монетку			
		}
		else if (playerCollider.intersects(otherCollider) && (*it)->getName() == "wall") {// если игрок столкнулся со стеной 

			player->setSpeed(Vector2f(-player->getSpeed().x, -player->getSpeed().y));// отталкиваем игрока

			player->update();// обновляем позицию

			it++;

		}
		else if (playerCollider.intersects(otherCollider) && (*it)->getName() == "hp") {

			player->setHp(player->getHp() + 1);

			entities.erase(it++);

		}
		else if ((*it)->getName() == "ranger") {
			Ranger* ranger = (Ranger*)(*it);

			ranger->collision(entities);

			Arrow* arrow = ranger->getArrow();

			FloatRect otherCollider = arrow->getSprite().getGlobalBounds();

			if (playerCollider.intersects(otherCollider)) {

				player->setHp(player->getHp() - 1);

				if (player->getHp() == 0) {

					player->setState("loose");

				}

				entities.erase(it++);//удаляем лучника

				entities.erase(it++);//удаляем стрелу, которая лежит сразу за лучником на наше счастье
			}
			else 
				it++;
		}
		else {// если мы ни с кем не столкнулись

			it++;// перейти на следующий объект списка

		}

	}
}

Player* Map::getPlayer() {

	return player;

}

void Map::draw(RenderWindow& window) {

	for (auto it = entities.begin(); it != entities.end(); it++) {// цикл по игровым объектам 
		window.draw((*it)->getSprite());
	}

	window.draw(player->getSprite());

}