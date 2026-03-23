#include "Floor.h" 

void Floor::init() { 
	width = 60;

	height = 60;

}

Floor::Floor(Vector2f position, String imagePath) : Entity(imagePath) { 

	init();

	setPosition(position);

	setName("floor");

}