#pragma once
#include "Verlet_object.h"
#include "Space.h"

class Solver {
	friend class Verlet_object;
	Vector2 gravity = { 0,980 };
	Space griddy;
public:
	void Update();
	void Apply_gravity();
	void Update_Positions();
	void collisions_correction();
	void Boundary();

};