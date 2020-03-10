#pragma once

#include "GameEntity.h"

class Flipper : public GameEntity
{
public:

	enum class Handedness
	{
		LEFT,
		RIGHT
	};

	Flipper();
	~Flipper() = default;

	/// <summary>
	/// @brief Updates the flipper along with the game loop
	/// </summary>
	/// <param name="t_dTime">time since last update</param>
	void update(sf::Time t_dTime);

	/// <summary>
	/// @brief Returns the flipper shape
	/// </summary>
	/// <param name="t_window"></param>
	sf::RectangleShape getShape();

	/// <summary>
	/// @brief Sets the position of the flipper
	/// </summary>
	/// <param name="t_pos"></param>
	virtual void setPosition(sf::Vector2f t_pos) override;

	/// <summary>
	/// @brief Returns the position of the flipper
	/// </summary>
	/// <returns></returns>
	virtual const sf::Vector2f getPosition() const override;

	/// <summary>
	/// @brief Returns the bounds of our line
	/// </summary>
	/// <returns></returns>
	Line const& getBounds() const override;

	/// <summary>
	/// @brief Returns the velocity of the tip of the paddle
	/// </summary>
	/// <returns></returns>
	float getSpeed() const;

	/// <summary>
	/// @brief 'Flicks' our flipper up to hit the ball
	/// </summary>
	void flick();

	/// <summary>
	/// @brief Setup the orientation of our flipper
	/// </summary>
	/// <param name="t_handedness">Left-handed or right-handed</param>
	void setHandedness(Handedness t_handedness);

private:

	void setupSprite();
	void setupBoundingBox();

	/// <summary>
	/// @brief Moves our flipper up or down, depending on its phase
	/// </summary>
	void move();

	sf::RectangleShape m_body;

	Handedness m_handedness;

	float m_width;
	float m_height;

	// Keep track of whether or flipper should be actively moving up or now
	bool m_isFlicking;

	// Constraints for our rotation
	const float INITIAL_ROTATION;
	const float FINAL_ROTATION;

	// How many radians rotated off horizontal are we
	float m_currentRotation;

	// How fast the flipper is moving
	float m_speed;

	Line m_boundingBox;
};