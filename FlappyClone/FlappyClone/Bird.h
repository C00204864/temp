#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>

class Bird
{
public:
	Bird(float xIn, float yIn);
	~Bird();
	void update();
	void updateNN(bool flap);
	void render(sf::RenderWindow & window);
	void renderToTexture(sf::RenderTexture & renderTexture);
	sf::RectangleShape getShape();
	void setPosition(sf::Vector2f pos);
	void incrementScore();
	void resetScore();
	bool isAlive();
	void setAliveStatus(bool status);
	float getY();
private:
	sf::RectangleShape m_shape;
	float m_yVelocity = 0;
	const float WIDTH = 30.f;
	const float HEIGHT = 30.f;
	int m_score;
	bool m_alive;
};

#endif // !BIRD_H
