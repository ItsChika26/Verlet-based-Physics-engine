#include "World.h"

void World::draw()
{
	ClearBackground(GRAY);
	DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, radius, BLACK);
}
