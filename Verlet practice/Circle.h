#pragma once
#include "Verlet_object.h"
#define RADIUS 2

struct Circle : public Verlet_object {
	float radius;
	Color colour;
	static int colour_index;
public:
	Circle(Vector2 current_p = { 13,13}, Vector2 init_velocity = { 2 * RADIUS / substep,0 } );
	void bound() override;
	inline float get_radius() { return radius; };
	void collide(Verlet_object* &target) override;
	void Draw_object() override;
};
