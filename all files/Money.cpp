#include "Money.h" 

Money::Money(Vector2f position, String imagePath) : Entity(imagePath) { 

	init(); 

	setPosition(position); 

	setName("money");

}

void Money::init() {. 

	width = 32;

	height = 32;

}

