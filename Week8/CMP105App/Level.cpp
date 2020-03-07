#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ball1.setWindow(window);
	ball1.setSize(sf::Vector2f(50, 50));
	ball1.setPosition(200, 200);
	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	ball1.setTexture(&ballTexture);

	ball2.setWindow(window);
	ball2.setSize(sf::Vector2f(50, 50));
	ball2.setPosition(800, 200);
	ball2.setTexture(&ballTexture);

	ball3.setWindow(window);
	ball3.setSize(sf::Vector2f(50, 50));
	ball3.setPosition(200, 600);
	ball3.setTexture(&ballTexture);

	ball4.setWindow(window);
	ball4.setSize(sf::Vector2f(50, 50));
	ball4.setPosition(800, 600);
	ball4.setTexture(&ballTexture);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt);
	ball2.update(dt);
	ball3.update(dt);
	ball4.update(dt);

	if (Collision::checkBoundingCircle(&ball1, &ball2))
	{
		ball1.direction = ball1.direction * -1;
		ball2.direction = ball2.direction * -1;
	}

	if (Collision::checkBoundingBox(&ball3, &ball4))
	{
		ball3.direction = ball3.direction * -1;
		ball4.direction = ball4.direction * -1;
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball1);
	window->draw(ball2);
	window->draw(ball3);
	window->draw(ball4);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}