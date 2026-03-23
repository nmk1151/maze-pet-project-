#include "Wall.h" 

void Wall::init() { 

	width = 60;

	height = 60;

}

Wall::Wall(Vector2f position, String imagePath) : Entity(imagePath) {

	init();

	setPosition(position);

	setName("wall");

}