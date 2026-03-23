#pragma once 

#include <SFML/Graphics.hpp> 

#include "Entity.h"

using namespace sf; 

class Money : public Entity { 
private: 

	void init(); 

public: 

	Money(Vector2f position, String imagePath); 

};