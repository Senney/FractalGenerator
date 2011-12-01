#include "SerpinskiTriangle.h"

#include <GL/gl.h>

SerpinskiTriangle::SerpinskiTriangle() { }

void SerpinskiTriangle::draw(int count) {
	glBegin(GL_TRIANGLES);
	generate(sf::Vector2f(0.0f, -1.0f), sf::Vector2f(-1.0f, 1.0f), sf::Vector2f(1.0f, 1.0f), count);
	glEnd();
}

void SerpinskiTriangle::generate(sf::Vector2f top, sf::Vector2f right, sf::Vector2f left, int count) {
	if (count > 0) {
		sf::Vector2f left_mid((top.x + left.x)/2, (top.y + left.y)/2);
		sf::Vector2f right_mid((top.x + right.x)/2, (top.y + right.y)/2);
		sf::Vector2f bottom_mid((right.x + left.x)/2, (right.y + left.y)/2);
		
		// Top recursion
		generate(top, left_mid, right_mid, count - 1);		

		// Left
		generate(left_mid, left, bottom_mid, count - 1);
		
		// Right
		generate(right_mid, bottom_mid, right, count - 1);
	}
	else {
		glVertex2f(top.x, top.y);
		glVertex2f(left.x, left.y);
		glVertex2f(right.x, right.y);
	}
}
