#include "Ball.h"

Ball::Ball()
{
	Vector2 position;
	Vector2 speed;
	bool active;
	int radius;

}

void Ball::Draw()
{
	DrawCircle(position.x, position.y, radius, DARKBLUE);
}
