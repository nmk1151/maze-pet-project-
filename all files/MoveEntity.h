#pragma once 

#include <SFML/Graphics.hpp> 

#include "Entity.h"

using namespace sf; 

class MoveEntity : public Entity { 

protected: 

	Vector2f speed; 

public:

	MoveEntity(Vector2f position, String imagePath); 
	void setSpeed(Vector2f speed);
	Vector2f getSpeed();

};