#pragma once
#include "Framework/GameObject.h"


class Ball :
	public GameObject
{
public:
	Ball(int _direction);
	~Ball();

	void setWindow(sf::RenderWindow* hwnd);
	void update(float dt) override;

	sf::RenderWindow* window;
	int direction = 1;
};

