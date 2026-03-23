#include "Arrow.h"   Arrow.h
void Arrow::init() {   

	width = 47;  
	height = 22;  
}



Arrow::Arrow(Vector2f position, String imagePath) : MoveEntity(position, imagePath) {

	init();  

	setName("arrow");  

	setSpeed(Vector2f(-2, 0));  

}

void Arrow::update() {   

	sprite.move(speed.x, speed.y);  

	position = sprite.getPosition();  

}