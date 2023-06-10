#pragma once
#include "raylib.h"
#include "raymath.h"
#include <vector>
constexpr float substep = 8;
#define  dt GetFrameTime() / substep

using namespace std;


struct Verlet_object {
	friend class Solver;
	friend class Renderer;
	float mass;
	Vector2 current_pos,previous_pos, acceleration, velocity;
public:
	static vector<Verlet_object*> objects;
	Verlet_object(Vector2 current_p = { GetScreenWidth() / 2.0f,GetScreenHeight() / 2.0f }, Vector2 init_velocity = { 0,0 });
	void move();
	virtual void bound() = 0;
	inline void accelerate(Vector2 accelerant) { acceleration = Vector2Add( acceleration,accelerant); }
	virtual void Draw_object() = 0;
	virtual void collide(Verlet_object* &target) = 0;
	inline void Relocate(const Vector2& pos) { current_pos = pos; };
	inline Vector2 GetPos() const{ return current_pos; };

};


