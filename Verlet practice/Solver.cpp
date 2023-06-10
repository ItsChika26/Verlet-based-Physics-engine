#include "Solver.h"

void Solver::Update()
{
	for (Verlet_object* i : Verlet_object::objects)
		i->move();
	
}

void Solver::Apply_gravity()
{
	for (Verlet_object* i : Verlet_object::objects)
		i->accelerate(gravity);

}

void Solver::Update_Positions()
{
	for (int i = 0; i < substep; i++) {
		Apply_gravity();
		collisions_correction();
		Boundary();
		Update();
	}
}

void Solver::collisions_correction()
{
	griddy.UpdateGridPartitioning();
	griddy.PerformCollisionDetection();
}

void Solver::Boundary()
{
	for (Verlet_object* i : Verlet_object::objects)
		i->bound();
	
}

