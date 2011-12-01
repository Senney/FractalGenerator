#include <GL/gl.h>
#include <iostream>
#include <string>

#include "SFML/Window.hpp"

#include "Fern.h"
#include "SerpinskiTriangle.h"
#include "KochSnowflake.h"

int main(int argv, char** argc)
{
	const int XSIZE = 500, YSIZE = 500;
	const float SPEED = 0.0006f;
	sf::Window appWindow(sf::VideoMode(XSIZE, YSIZE, 32), "Fractal Generator");
	
	// Setup color clear information.
	glClearDepth(1.f);
	glClearColor(0.f, 0.f, 0.f, 0.f);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, 1, -1, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	
	glDisable(GL_DEPTH_TEST);
	
	// Fractals
	SerpinskiTriangle serpinski;
	KochSnowflake snowflake;
	Fern fern(77.f, 89.f, 99.f);
	int count = 0;
	int type = 0;
	float zfac = 1.2;
	
	int curType = -1;
	bool update = true;
	int curDisplayList = 0;
	
	sf::Event Event;
	while (appWindow.IsOpened()) {
		const sf::Input& input = appWindow.GetInput();
		while (appWindow.GetEvent(Event)) {
			if (Event.Type == sf::Event::Closed) {
				appWindow.Close();
			}
			if (Event.Type == sf::Event::Resized) {
				glViewport(0, 0, Event.Size.Width, Event.Size.Height);
				
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				glOrtho(-1, 1, 1, -1, 0, 1);
				glMatrixMode(GL_MODELVIEW);
			}
			if (Event.Type == sf::Event::KeyReleased) {
				if (Event.Key.Code == sf::Key::Up) {
					if (count >= 0)
						count++;
					update = true;
				}
				if (Event.Key.Code == sf::Key::Down)
				{
					if (count > 0)
						count--;
					update = true;
				}
				if (Event.Key.Code == sf::Key::U) {
					glScalef(zfac, zfac, 0.0f);					
				}
				if (Event.Key.Code == sf::Key::J) {
					glScalef(2.0f - zfac, 2.0f - zfac, 0.0f);						
				}
				if (Event.Key.Code == sf::Key::E) {
					if (type >= 0) {
						type++;
						count = 0;
					}
				}
				if (Event.Key.Code == sf::Key::Q) {
					if (type > 0) {
						type--;
						count = 0;
					}
				}
			}
		}
		if (input.IsKeyDown(sf::Key::W))
			glTranslatef(0.0f, SPEED, 0.0f);
		else if (input.IsKeyDown(sf::Key::S))
			glTranslatef(0.0f, -SPEED, 0.0f);
		
		if (input.IsKeyDown(sf::Key::D))
			glTranslatef(-SPEED, 0.0f, 0.0f);
		else if (input.IsKeyDown(sf::Key::A))
			glTranslatef(SPEED, 0.0f, 0.0f);	
		
		appWindow.SetActive();
				
		glClear(GL_COLOR_BUFFER_BIT);
				
		if (curType != type || update) {
			curDisplayList = glGenLists(1);
			glNewList(curDisplayList, GL_COMPILE);
			if (type == 0) serpinski.draw(count);
			else if (type == 1) snowflake.draw(count);
			else if (type == 2) fern.draw(count * 1000);
			glEndList();
			
			curType = type; update = false;
		}
		
		glCallList(curDisplayList);
				
		appWindow.Display();
	}
}
