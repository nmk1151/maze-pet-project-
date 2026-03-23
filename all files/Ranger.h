#pragma once  

#include <SFML/Graphics.hpp>   sfml 

#include "Entity.h"   Entity 

#include<iostream>   iostream

#include<list>   list 

#include "Arrow.h"  

using namespace sf;   sf

using namespace std;   std 

class Ranger : public Entity {   Ranger
private:  
	bool isShot = false;   

	Arrow* arrow;

	float currentFrame = 4;   

	void init();  

	void animation();   

	void shoot();   

public:   

	Ranger(Vector2f position, String imagePath);   

	void collision(list<Entity*> entities);   

	void update();   

	Arrow* getArrow();  
};