#include "Engine.h"


Engine::Engine() {

	init();

}

void Engine::draw() {

	window.clear(Color(0, 255, 0));

	window.setView(camera->getView());

	map.draw(window);

	Text text;

	Font font;

	font.loadFromFile("20016.ttf");

	text.setFont(font);

	text.setCharacterSize(24);

	text.setFillColor(sf::Color::White);

	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	if (map.getPlayer()->getState() == "start") {

		text.setString("coins:" + std::to_string(map.getPlayer()->getCoins()));
		text.setPosition(camera->getView().getCenter().x + 300, camera->getView().getCenter().y - 240);

	}

	else if (map.getPlayer()->getState() == "loose") {

		window.clear();

		text.setString("You loose");

		text.setPosition(camera->getView().getCenter().x - 40, 	camera->getView().getCenter().y - 20);

	}

	else {

		window.clear();

		text.setPosition(camera->getView().getCenter().x - 40,	camera->getView().getCenter().y - 20);
		
		text.setString("You win");
	}
	window.draw(text);

	window.display(); 

}

void Engine::update() {

	pressedAction.action(); 

	map.update();

	camera->update(); 

}


void Engine::init() {

	window.create(sf::VideoMode(1260, 720), "Game");
	window.setFramerateLimit(60); 
	pressedAction.setPlayer(map.getPlayer());
	camera = new Camera(map.getPlayer());
}

void Engine::loop() {

	while (window.isOpen())

	{

		Event event;

		while (window.pollEvent(event))

		{

			if (event.type == Event::Closed) {

				window.close();

			}

		}
		draw(); 
		update();
	}

}
