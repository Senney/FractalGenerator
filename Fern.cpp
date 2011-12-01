#include "Fern.h"

#include <GL/gl.h>
#include <cstdio>
#include <cstdlib>

Fern::Fern(float p1, float p2, float p3) {
	if (p1 > p2 || p2 > p3)	{
		printf("p1 < p2 < p3 for fern fractal!\n");
		return;
	}
	prob1 = p1;
	prob2 = p2;
	prob3 = p3;
}

void Fern::draw(int maxpoints) {
	float x = 0;
	float y = 0;
	glBegin(GL_POINTS);
	for (int n = 1; n <= maxpoints; n++) {
		int p = random() % 100;
		int x_n = x;
		
		if (p < prob1) {
			x = 0.85f * x + 0.04f * y + 0.075f;
			y = -0.04f * x_n + 0.85f * y + 0.18f;
		}
		else if (p < prob2) {
			x = 0.20f * x + -0.26f * y + 0.4f;
			y = 0.23f * x_n + 0.22f * y + 0.045f;		
		}
		else if (p < prob3) {
			x = -0.15f * x + 0.28f * y + 0.575f;
			y = 0.26f * x_n + 0.24f * y + -0.086f;	
		}
		
		if (n > 100)
			glVertex2f(x, y);
	}
	glEnd();
}
