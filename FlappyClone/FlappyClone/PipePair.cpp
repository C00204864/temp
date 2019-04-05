#include "PipePair.h"

PipePair::PipePair(float xPositionIn, int screenHeight, int pipeCount, float gapBetween)
	: m_xPosition(xPositionIn),
	m_screenHeight(screenHeight),
	m_totalPipes(pipeCount),
	m_distanceBetween(gapBetween)
{
	m_upperPipe.setFillColor(sf::Color(29, 46, 72));
	m_lowerPipe.setFillColor(sf::Color(29, 46, 72));
	randomise();
}

PipePair::~PipePair()
{
}

void PipePair::update()
{
	movePipe(m_upperPipe);
	movePipe(m_lowerPipe);
	sf::Vector2f upperPos = m_upperPipe.getPosition();
	sf::Vector2f lowerPos = m_lowerPipe.getPosition();
	m_xPosition = upperPos.x;
	if (upperPos.x < -RECT_WIDTH && lowerPos.x < -RECT_WIDTH)
	{
		m_xPosition = upperPos.x + m_totalPipes * m_distanceBetween;
		randomise();
	}
}

void PipePair::render(sf::RenderWindow & window)
{
	window.draw(m_upperPipe);
	window.draw(m_lowerPipe);
}

void PipePair::renderToTexture(sf::RenderTexture & renderTexture)
{
	renderTexture.draw(m_upperPipe);
	renderTexture.draw(m_lowerPipe);
}

void PipePair::randomise()
{
	m_gapYPosition = (rand() % (m_screenHeight - 400));
	m_upperPipe.setPosition(sf::Vector2f(m_xPosition, 0));
	m_upperPipe.setSize(sf::Vector2f(RECT_WIDTH, m_gapYPosition));
	m_lowerPipe.setPosition(sf::Vector2f(m_xPosition, m_gapYPosition + GAP_WIDTH));
	m_lowerPipe.setSize(sf::Vector2f(RECT_WIDTH, m_screenHeight - m_gapYPosition));
}

bool PipePair::checkCollision(sf::FloatRect shape)
{
	if (m_upperPipe.getGlobalBounds().intersects(shape)
		|| m_lowerPipe.getGlobalBounds().intersects(shape))
	{
		return true;
	}
	return false;
}

float PipePair::getX()
{
	return m_xPosition;
}

float PipePair::getGapY()
{
	return m_gapYPosition;
}

void PipePair::movePipe(sf::RectangleShape & rect)
{
	sf::Vector2f pos = rect.getPosition();
	pos.x -= 3;
	m_xPosition = pos.x;
	rect.setPosition(pos);
}
