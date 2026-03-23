#pragma once

#include <SFML/Graphics.hpp>  

#include "MoveEntity.h"

using namespace sf;  

class Player : public MoveEntity {   
								    
private: 

	int coins = 0;

	String state = "start";

	void init();  

	void dontMoveBehindMap(); 
public:
	float currentFrame = 0;

	Player(Vector2f position, String imagePath); 

	int getCoins();

	void setCoins(int coins);

	void setState(String state);

	String getState();
	
	void update();
};