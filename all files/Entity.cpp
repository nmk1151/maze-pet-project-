#include "Entity.h"

Entity::Entity(String imagePath) {

	setImagePath(imagePath);

	init();

}

void Entity::init() {

	Image image;

	image.loadFromFile(imagePath);

	texture.loadFromImage(image);

	sprite.setTexture(texture);

}

void Entity::setPosition(Vector2f position) { 

	this->position = position;

	sprite.setPosition(position.x, position.y);

}

void Entity::setTextureRect(IntRect rect) { 

	sprite.setTextureRect(rect);

}

void Entity::setWidth(int width) { 

	this->width = width;

}

void Entity::setHeight(int height) { 

	this->height = height;

}

void Entity::setImagePath(String imagePath) { 

	this->imagePath = imagePath;

}

void Entity::setName(String name) { 
	this->name = name;
}

Vector2f Entity::getPosition() { 

	return sprite.getPosition();

}

Sprite Entity::getSprite() { 

	return sprite;

}

int Entity::getWidth() { 

	return width;

}

int Entity::getHeight() { 

	return height;

}

String Entity::getImagePath() { 

	return imagePath;

}

String Entity::getName() { 
	return name;
}

void Entity::update() {

}