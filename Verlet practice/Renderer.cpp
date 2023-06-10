#include "Renderer.h"
#include <string>
void Renderer::Render_world()
{
	ClearBackground(BLACK);
	//DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 300, BLACK);
	DrawText(to_string(Verlet_object::objects.size()).c_str(), 100, 100, 20, WHITE);
	DrawFPS(50, 50);
	Render_objects();
}

void Renderer::Render_objects()
{
	for (Verlet_object* i : Verlet_object::objects)
		i->Draw_object();
}
