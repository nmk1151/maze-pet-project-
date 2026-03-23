#pragma once 
#include <SFML/Graphics.hpp> 
#include "Entity.h" 
using namespace sf;  

class Wall : public Entity { 

private: 

	void init(); 
public:

	Wall(Vector2f position, String imagePath);

};
