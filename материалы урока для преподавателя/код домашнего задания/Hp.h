#pragma once 

#include <SFML/Graphics.hpp> 

#include "Entity.h" 

using namespace sf;

class Hp : public Entity {

private:

	void init();

public:

	Hp(Vector2f position, String imagePath);

};