#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <SFML\Graphics.hpp>

struct MyWindow
{
	sf::RenderWindow *window;
	int windowWidth;
	int windowHeight;
	int style;

	MyWindow();
	void Setup();
};

#endif
