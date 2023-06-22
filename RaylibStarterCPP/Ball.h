#pragma once
#include "Items.h"
#include "Raylib/include/raylib.h"

class Ball : public Items
{

public:
	Ball();
	void Draw() override;

	Vector2 position;
	Vector2 speed;
	bool active;
	int radius;

};