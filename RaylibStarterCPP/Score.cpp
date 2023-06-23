#include "Score.h"

Score::Score() {
	Vector2 position;
	Vector2 size;
	int score;
	int fontSize;
	bool player;
}

void Score::DrawBoarder()
{
	DrawRectangleLines(position.x, position.y, size.x, size.y, YELLOW);
}

void Score::Draw()
{
	if (player) {
		DrawText(TextFormat("Player 1:%4i", score), position.x, position.y, fontSize, PURPLE);
	}
	if (!player) {
		DrawText(TextFormat("Player 2:%4i", score), position.x, position.y, fontSize, PURPLE);
	}

}