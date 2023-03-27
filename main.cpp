#include <iostream>
#include "RtMidi.h"
#include "MyWindow.h"
#include "KeyInput.h"
#include "MIDIKeyboard.h"
#include <SFML\Graphics.hpp>
#include <chrono>

using namespace std;
using namespace sf;

int main()
{
	MIDIKeyboard keyboard;
	keyboard.Setup();

	if (!keyboard.IsInitialized())
	{
		cout << "keyboard failed\n";
		int x;
		cin >> x;
		return 0;
	}
	
	while (true)
	{
		cout << "-----------ROUND START-----------" << endl << endl;
		srand(time(0));

		auto startTime = chrono::high_resolution_clock::now();

		int numQuestions = 10;
		int totalScore = 0;
		for (int i = 0; i < numQuestions; ++i)
		{
			cout << "Press a C:" << endl;

			keyboard.inputQueue.clear();
			while (true)
			{
				if (keyboard.inputQueue.size() > 0 && keyboard.inputQueue.back().keyIndex == 0 && keyboard.inputQueue.back().down )
				{
					cout << "C" << endl;
					break;
				}
			}

			//cout << endl;
		}


		auto finishTime = chrono::high_resolution_clock::now();

		chrono::duration<double> totalTime = finishTime - startTime;

		cout << "---------------------------------" << endl;
		cout << "You scored: " << totalScore << "/" << numQuestions << endl;
		cout << "You took " << totalTime.count() << " seconds." << endl;
		cout << "\n\n\n\n" << endl;
	}
}