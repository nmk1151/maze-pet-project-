#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

#include "Money.h" 

#include "Wall.h" 

#include "Floor.h" 

#include "Ranger.h"

#include<list>

using namespace sf;

using namespace std; 

const int WINDOW_WIDTH = 1260;

const int WINDOW_HEIGHT = 720;

const int WIDTH_MAP = 21;

const int HEIGHT_MAP = 12; 

class Map {
public:

	Map();

	void draw(RenderWindow& window);

	Player* getPlayer();

	void update();

private:
	sf::String TileMap[HEIGHT_MAP] = {
		"kkkkkkkkkkkkkkkkkkkkk",
		"kggggggggmgggakgmkgmk",
		"kgggggggggggggkggkggk",
		"kgggggkkkkkgggkggkggk",
		"kkkkkkkgmgkgggkggkggk",
		"kgggggggggkgggkggkggk",
		"kgggggggggkgggkggkggk",
		"kggkkkkkkkkgggkggkggk",
		"kggggggagggggggggkggk",
		"kggggggmgggggggmggggk",
		"kggggggggggggggggggak",
		"kmgkkkkkkkkkkkkkkkkkk"
	};

	Player* player;

	list<Entity*> entities; 

	void init();
};