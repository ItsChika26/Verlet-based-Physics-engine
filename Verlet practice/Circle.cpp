#include "Circle.h"


Color arr[] = { RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, VIOLET };
int Circle::colour_index = 0;


Circle::Circle(Vector2 current_p, Vector2 init_velocity) :radius(RADIUS),Verlet_object(current_p, init_velocity), colour(arr[colour_index])
{
	if (Verlet_object::objects.size() % 200 == 0) {
		colour_index = colour_index++ % 6;
	}
}

void Circle::bound()
{
	if (current_pos.x + radius > GetScreenWidth()) {
		current_pos.x = -radius + GetScreenWidth();
		velocity = Vector2Scale(velocity, 0.9);
	}
	else
		if (current_pos.x - radius < 0)
	{
		current_pos.x = radius;
		velocity = Vector2Scale(velocity, 0.9);
	}
	if (current_pos.y + radius > GetScreenHeight())
	{
		current_pos.y = -radius + GetScreenHeight();
		velocity = Vector2Scale(velocity, 0.9);
	}
	else
		if (current_pos.y - radius < 0)
	{
		current_pos.y = radius;
		velocity = Vector2Scale(velocity, 0.9);
	}
	
}

void Circle::collide(Verlet_object*& target) {
    //Vector2 distance = Vector2Subtract(current_pos, target->current_pos);
    //float distanceLength = Vector2Length(distance);

    //// Calculate the normal vector between the circles
    //Vector2 normal = Vector2Normalize(distance);

    //// Calculate the relative velocity
    //Vector2 relativeVelocity = Vector2Subtract(target->velocity, velocity);

    //// Calculate the impact speed along the normal direction
    //float impactSpeed = Vector2DotProduct(relativeVelocity, normal);

    //// Define the minimum velocity threshold to prevent merging
    //float minVelocityThreshold = 0.1; // Adjust this value as needed

    //// Check if the circles are moving towards each other with sufficient velocity
    //if (impactSpeed > minVelocityThreshold) {
    //    // Calculate the restitution coefficient (e.g., 1 for perfectly elastic collision)
    //    float restitution = 0.9;

    //    // Calculate the impulse magnitude
    //    float impulseMagnitude = (1 + restitution) * impactSpeed / (1 / mass + 1 / target->mass);

    //    // Calculate the impulse vector
    //    Vector2 impulse = Vector2Scale(normal, impulseMagnitude);

    //    // Update velocities
    //    velocity = Vector2Add(velocity, Vector2Scale(impulse, 1 / mass));
    //    target->velocity = Vector2Subtract(target->velocity, Vector2Scale(impulse, 1 / target->mass));
    //}

	Vector2 distance = Vector2Subtract(current_pos, target->current_pos);
	current_pos = Vector2Add(current_pos, Vector2Scale(Vector2Normalize(distance), (2 * radius - Vector2Length(distance)) / 2));
	target->current_pos = Vector2Subtract(target->current_pos, Vector2Scale(Vector2Normalize(distance), (2 * radius - Vector2Length(distance)) / 2));
	velocity = Vector2Scale(velocity, 0.99);
	target->velocity = Vector2Scale(target->velocity, 0.99);
}




void Circle::Draw_object()
{
	DrawCircle(current_pos.x, current_pos.y, radius, colour);
}

