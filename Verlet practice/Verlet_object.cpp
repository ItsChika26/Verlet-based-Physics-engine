#include "Verlet_object.h"

vector<Verlet_object*> Verlet_object::objects = {};


	Verlet_object::Verlet_object(Vector2 current_pos, Vector2 init_velocity) : acceleration({ 0,0 }), velocity(init_velocity), current_pos(current_pos), previous_pos(current_pos), mass(5)
{
	objects.push_back(this);
}

void Verlet_object::move()
{
	
	current_pos = Vector2Add(current_pos , Vector2Add(velocity, Vector2Scale(acceleration, dt * dt/2)));
	velocity = Vector2Subtract(current_pos, previous_pos);
	previous_pos = current_pos;
	acceleration = {};
}

Vector2 operator+(const Vector2 a, const Vector2 b)
{

	return Vector2Add(a, b);
}


Vector2& operator+=(Vector2& a, const Vector2 b)
{
	a = a + b;
	return a;
}

Vector2 operator-(const Vector2 a, const Vector2 b)
{
	return Vector2Add(a, Vector2Negate(b));
}

Vector2 operator-(const Vector2 a)
{
	return a * -1;
}

Vector2 operator*(const Vector2& a, const float b)
{
	return Vector2Scale(a, b);
}

Vector2 operator/(const Vector2 a, const float b)
{
	return Vector2Scale(a, 1 / b);
}
