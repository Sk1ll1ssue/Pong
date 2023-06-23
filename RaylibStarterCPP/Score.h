#pragma once
#include "Raylib/include/raylib.h"
#include "Items.h"

class Score : public Items
{
public:
	Score();
	void Draw() override;
	void DrawBoarder();

	Vector2 position;
	Vector2 size;
	int score;
	int fontSize;
	bool player;

};