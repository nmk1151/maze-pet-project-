#pragma once  

#include <SFML/Graphics.hpp> 

#include "Entity.h" 

using namespace sf;  

class Floor : public Entity {

private:

	void init();

public:

	Floor(Vector2f position, String imagePath);

};