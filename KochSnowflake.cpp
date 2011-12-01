#include "KochSnowflake.h"

#include "GL/gl.h"

KochSnowflake::KochSnowflake() { }

void KochSnowflake::draw(int count) {
	sf::Vector2f top = sf::Vector2f(0.0f, -1.0f);
	sf::Vector2f left = sf::Vector2f(-1.0f, 1.0f);
	sf::Vector2f right = sf::Vector2f(1.0f, 1.0f);

	glBegin(GL_LINES);
	generate(top, right, count);
	generate(left, right, count);
	generate(top, left, count);
	glEnd();
}

void KochSnowflake::generate(sf::Vector2f p1, sf::Vector2f p2, int count)
{
	if (count >= 0) {
		sf::Vector2f left_third((p1.x + p2.x)/3, (p1.y + p2.y)/3);
		sf::Vector2f right_third(p2.x - left_third.x, p2.y - left_third.y);
		sf::Vector2f tip((left_third.x + right_third.x)/2, (left_third.y + right_third.y)/2);
	} else {
		glVertex2f(p1.x, p1.y);
		glVertex2f(p2.x, p2.y);
	}
}
