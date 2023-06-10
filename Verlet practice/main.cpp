#include "Verlet_object.h"
#include "Circle.h"
#include "Renderer.h"
#include "Solver.h"
#include "Space.h"

int main() {
	InitWindow(800, 600, "test");
	SetTargetFPS(60);
	Solver movement;
	Renderer visuals;
	
	vector<Verlet_object*> checks;

	Rectangle screen = { 0,0,GetScreenWidth(),GetScreenHeight() };

	while (!WindowShouldClose()) {
		BeginDrawing();
		if(IsKeyDown(KEY_SPACE))
		new Circle;
		if (IsKeyPressed(KEY_BACKSPACE))
			Verlet_object::objects.pop_back();
	
		
		movement.Update_Positions();
		visuals.Render_world();

		
		EndDrawing();
	}


}