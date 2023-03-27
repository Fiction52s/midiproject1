#include "MyWindow.h"
#include <assert.h>

using namespace std;
using namespace sf;

MyWindow::MyWindow()
{
	window = NULL;
	windowWidth = 0;
	windowHeight = 0;
	style = 0;
}

void MyWindow::Setup()
{
	if (window != NULL)
	{
		window->close();
		delete window;
		window = NULL;
	}

	windowWidth = 1000;
	windowHeight = 300;
	style = sf::Style::Default;

		/*windowWidth = 960;
	windowHeight = 540;*/
	window = new RenderWindow(sf::VideoMode(windowWidth, windowHeight), "MidiProject1",
		style, sf::ContextSettings(0, 0, 0, 0, 0));
	window->setKeyRepeatEnabled(false);

	assert(window != NULL);
	window->setVerticalSyncEnabled(true);

	auto vMode = VideoMode::getDesktopMode();

	Vector2i border((vMode.width - windowWidth) / 2, (vMode.height - windowHeight) / 2);

	window->setPosition(border);
}