#include "Ball.h"


Ball::Ball(int _direction)
{

}

Ball::~Ball()
{

}

void Ball::setWindow(sf::RenderWindow* hwnd)
{
	window = hwnd;
}

void Ball::update(float dt)
{
	move(1000 * dt * direction, 0);

	// Check for collision with window
	direction = getPosition().x >= window->getSize().x - getSize().x ? direction * -1 : direction;
	direction = getPosition().x < 0 ? direction * -1 : direction;
}