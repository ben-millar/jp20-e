#pragma once
#include "GameEntity.h"

class Spring :
	public GameEntity
{
public:
	Spring();
	~Spring() = default;

	/// <summary>
	/// @brief Updates the spring along with the game loop
	/// </summary>
	/// <param name="t_dTime">time since last update</param>
	void update(sf::Time t_dTime);

	/// <summary>
	/// @brief Moves the spring down toward its maximum compression
	/// </summary>
	void pullBack();

	/// <summary>
	/// @brief Returns the spring shape
	/// </summary>
	/// <param name="t_window"></param>
	sf::RectangleShape getShape();

	/// @brief Sets the position of the spring
	/// </summary>
	/// <param name="t_pos"></param>
	void setPosition(sf::Vector2f t_pos) override;

	/// <summary>
	/// @brief Returns the position of the spring
	/// </summary>
	/// <returns></returns>
	const sf::Vector2f getPosition() const override;

	/// <summary>
	/// @brief Returns the bounds of our line
	/// </summary>
	/// <returns></returns>
	Line const& getBounds() const  override;
private:

	void setupSprite();
	void setupBoundingBox();

	void updatePosition();
	void updateBoundingBox();

	sf::RectangleShape m_body;

	float m_width;
	float m_height;

	// How far the spring can stretch and squash
	const float MIN_COMPRESSION;
	const float MAX_COMPRESSION;

	float m_currentCompression;

	Line m_boundingBox;
};