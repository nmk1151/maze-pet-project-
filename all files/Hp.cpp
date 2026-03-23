#include "Hp.h"
void Hp::init() {

	width = 32;

	height = 32;

}

Hp::Hp(Vector2f position, String imagePath) : Entity(imagePath) {

	init();

	setPosition(position);

	setName("hp");
}