#include "Player.h"

Player::Player() {
	Vector2 position;
	Vector2 size;
	Color color;
}

void Player::Draw() {
	DrawRectangle(position.x, position.y, size.x, size.y, color);
}