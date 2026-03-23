#pragma once

#include <SFML/Graphics.hpp>

#include "MoveEntity.h"

using namespace sf;

class Arrow : public MoveEntity {  

private:   

	void init();   

public:   

	Arrow(Vector2f position, String imagePath);   

	void update();  

};