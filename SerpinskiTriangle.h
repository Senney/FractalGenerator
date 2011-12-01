#ifndef SERP_TRI_H
#define SERP_TRI_H

#include "SFML/Graphics.hpp"

class SerpinskiTriangle
{
public:
	SerpinskiTriangle();
	
	void draw(int count);
private:
	void generate(sf::Vector2f top, sf::Vector2f left, sf::Vector2f right, int count);
};

#endif
