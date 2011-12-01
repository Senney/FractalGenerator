#ifndef KOCH_H
#define KOCH_H

#include "SFML/Graphics.hpp"

class KochSnowflake
{
public:
	KochSnowflake();
	
	void draw(int count);
private:
	void generate(sf::Vector2f p1, sf::Vector2f p2, int count);
};

#endif
