#include "Bird.h"

Bird::Bird(float xIn, float yIn)
{
	m_shape.setPosition(sf::Vector2f(xIn, yIn));
	m_shape.setSize(sf::Vector2f(WIDTH, HEIGHT));
	m_shape.setFillColor(sf::Color(13, 191, 10));
}

Bird::~Bird()
{
}

void Bird::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_yVelocity = -11.f;
	}
	m_yVelocity += 1.f;
	sf::Vector2f pos = m_shape.getPosition();
	pos.y += m_yVelocity;
	m_shape.setPosition(pos);
}

void Bird::updateNN(bool flap)
{
	if (flap)
	{
		m_yVelocity = -11.f;
	}
	m_yVelocity += 1.f;
	sf::Vector2f pos = m_shape.getPosition();
	pos.y += m_yVelocity;
	m_shape.setPosition(pos);
}


void Bird::render(sf::RenderWindow & window)
{
	window.draw(m_shape);
}

void Bird::renderToTexture(sf::RenderTexture & renderTexture)
{
	renderTexture.draw(m_shape);
}

sf::RectangleShape Bird::getShape()
{
	return m_shape;
}

void Bird::setPosition(sf::Vector2f pos)
{
	m_shape.setPosition(pos);
	m_yVelocity = 0.f;
}

void Bird::incrementScore()
{
	++m_score;
}

void Bird::resetScore()
{
	m_score = 0;
}

bool Bird::isAlive()
{
	return m_alive;
}

void Bird::setAliveStatus(bool status)
{
	m_alive = status;
}

float Bird::getY()
{
	return m_shape.getPosition().y;
}
