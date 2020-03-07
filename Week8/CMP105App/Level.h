#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/Collision.h"
#include "Ball.h"
#include <string>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

	Ball ball1 = Ball(1);
	Ball ball2 = Ball(-1);
	Ball ball3 = Ball(1);
	Ball ball4 = Ball(-1);
	sf::Texture ballTexture;

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
};