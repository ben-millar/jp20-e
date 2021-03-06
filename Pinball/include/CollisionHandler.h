#pragma once

#include <Thor/Vectors.hpp>
#include "Subject.h"
#include "EntityType.h"

class GameEntity;
class Flipper;
class Ball;

struct CollisionBox {};

struct Circle : public CollisionBox
{
	sf::Vector2f p;
	float r;
};

///////////////////////////////////////////////////////////////

struct Line : public CollisionBox
{
	sf::Vector2f p1;
	sf::Vector2f p2;
};

///////////////////////////////////////////////////////////////

struct AABB : public CollisionBox
{
	sf::Vector2f p;
	float w;
	float h;
};

///////////////////////////////////////////////////////////////

class CollisionHandler : public Subject
{
public:

	CollisionHandler() = default;
	~CollisionHandler() = default;

	static void resolveCollision(Ball& t_ball, Circle t_entityCircle, EntityType t_type);
	static void resolveCollision(Ball& t_ball, AABB t_entityAABB, EntityType t_type);
	static void resolveCollision(Ball& t_ball, Line t_entityLine, EntityType t_type);
	static void resolveCollision(Ball& t_ball, Flipper& t_flipper, EntityType t_type);

private:

	static bool isColliding(Circle t_ball, Circle t_entityCircle);
	static bool isColliding(Circle t_ball, AABB t_entityAABB);
	static bool isColliding(Circle t_ball, Line t_entityLine);

	/// <summary>
	/// @brief Given a ball and a line, move the ball to a position where it is no longer intersecting
	/// </summary>
	static void contactSolver(Ball& t_ball, Line t_entityLine);

	/// <summary>
	/// @brief Get a vector perpendicular to the contact normal
	/// </summary>
	static sf::Vector2f getSurfaceOfContact(sf::Vector2f t_ball, sf::Vector2f t_entity);

	/// <summary>
	/// @brief Get the vector along which our ball has rebounded
	/// </summary>
	static sf::Vector2f getReboundVector(sf::Vector2f t_velocity, sf::Vector2f t_surfaceOfContact, EntityType t_type);

	/// <summary>
	/// @brief Get the distance between two points in 2D
	/// </summary>
	/// <param name="t_p1">First point</param>
	/// <param name="t_p2">Second point</param>
	/// <returns>length as a float</returns>
	static float getDistance(sf::Vector2f t_p1, sf::Vector2f t_p2);
};

#include "GameEntity.h"
#include "Flipper.h"
#include "Ball.h"