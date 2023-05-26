#pragma once
#include "Raylib/include/raylib.h"
#include "Items.h"

class Player : public Items
{

public:
	Player();
	void Draw() override;

	Vector2 position;
	Vector2 size;
	Color color;

};