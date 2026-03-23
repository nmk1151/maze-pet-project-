#include "MoveEntity.h" 

MoveEntity::MoveEntity(Vector2f position, String imagePath) :	Entity(imagePath) { 
	setPosition(position);
}

void MoveEntity::setSpeed(Vector2f speed) { 
	this->speed = speed; 

}

Vector2f MoveEntity::getSpeed() { 
	return speed; 
}