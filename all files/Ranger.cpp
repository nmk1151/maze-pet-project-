#include "Ranger.h"   
void Ranger::init() {  
	width = 60;  
	height = 55;  
}

Ranger::Ranger(Vector2f position, String imagePath) : Entity(imagePath) {
	init();
	setPosition(position);  
	setName("ranger");   
	arrow = new Arrow(Vector2f(position.x - width, position.y + 20), "images/arrow.png");   
	setTextureRect(IntRect(0, 0, width, height));  
	sprite.setScale(-1, 1);  
}

Arrow* Ranger::getArrow() {  
	return arrow;  
}

void Ranger::animation() {   
	currentFrame += 0.02;
	setTextureRect(IntRect(int(currentFrame) * width, 0, width, height));
}

void Ranger::shoot() {   
	if (!isShot) {
		if (currentFrame >= 4) {
			arrow->setPosition(Vector2f(position.x - width, position.y + 20));
			setTextureRect(IntRect(int(currentFrame) * width, 0, width, height));
			currentFrame -= 4;
			isShot = true;
		}
		else {

			animation();
		}
	}
	else {
		arrow->update();
	}
}

void Ranger::update() {   
	shoot();
}

void Ranger::collision(list<Entity*> entities) {   
	FloatRect arrowCollider = arrow->getSprite().getGlobalBounds();
	for (auto it = entities.begin(); it != entities.end(); it++) {

		FloatRect otherCollider = (*it)->getSprite().getGlobalBounds();
		if (arrowCollider.intersects(otherCollider) && (*it)->getName() == "wall") {
			isShot = false;
		}
	}
}