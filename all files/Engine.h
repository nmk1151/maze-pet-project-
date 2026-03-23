#pragma once

#include <SFML/Graphics.hpp>

#include<iostream>

#include "Map.h" 

#include "KeyPressedAction.h"

#include "Camera.h" 

using namespace sf; 

using namespace std;  

class Engine {

public:

	RenderWindow window;

	Map map;

	KeyPressedAction pressedAction;

	Camera* camera; 

	Engine(); 

	void init();

	void loop(); 

	void draw();

	void update();

};
