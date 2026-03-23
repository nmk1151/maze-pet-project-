#pragma once  
#include <SFML/Graphics.hpp>  
using namespace sf; 

class Entity { 

protected: 

	Vector2f position; 
	Sprite sprite;
	Texture texture; 
	int width; 
	int height;
	String imagePath; 
	String name; 
	virtual void init(); 

public:

	Entity(String imagePath); 
	virtual void update();
	void setPosition(Vector2f position); 
	void setTextureRect(IntRect rect); 
	void setWidth(int width);
	void setHeight(int height); 
	void setImagePath(String imagePath); 
	void setName(String name);
	Vector2f getPosition(); 
	Sprite getSprite();
	int getWidth();
	int getHeight(); 
	String getImagePath();
	String getName(); 
};