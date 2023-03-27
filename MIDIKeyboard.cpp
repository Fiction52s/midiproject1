#include "MIDIKeyboard.h"
#include <iostream>
#include "KeyInput.h"

using namespace std;

MIDIKeyboard *MIDIKeyboard::currInstance = NULL;

//singleton
MIDIKeyboard *MIDIKeyboard::GetInstance()
{
	return currInstance;
}

MIDIKeyboard::MIDIKeyboard()
{
	midiin = NULL;
	currInstance = this;
}

MIDIKeyboard::~MIDIKeyboard()
{
	if (midiin != NULL)
	{
		delete midiin;
	}
}

bool MIDIKeyboard::IsInitialized()
{
	return midiin != NULL;
}

bool MIDIKeyboard::Setup()
{
	if (midiin != NULL)
		delete midiin;

	midiin = new RtMidiIn();
	// Check available ports.
	unsigned int nPorts = midiin->getPortCount();
	if (nPorts == 0) {
		std::cout << "No ports available!\n";

		delete midiin;
		midiin = NULL;

		return false;
	}

	midiin->openPort(0);
	// Set our callback function.  This should be done immediately after
	// opening the port to avoid having incoming messages written to the
	// queue.
	midiin->setCallback(&MIDIKeyboard::MIDICallback);
	// Don't ignore sysex, timing, or active sensing messages.
	midiin->ignoreTypes(false, false, false);
	//midiin->ignoreTypes(true, true, true);

	cout << "keyboard successfully set up\n";

	inputQueue.clear();

	return true;
}



void MIDIKeyboard::MIDICallback(double deltatime, std::vector< unsigned char > *message, void *userData)
{
	/*unsigned int nBytes = message->size();
	for (unsigned int i = 0; i<nBytes; i++)
		std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
	if (nBytes > 0)
		std::cout << "stamp = " << deltatime << std::endl;*/

	KeyInput key;
	key.SetFromCallbackData(deltatime, message, userData);
	//key.Print();

	MIDIKeyboard *kb = MIDIKeyboard::GetInstance();
	kb->inputQueue.push_back(key);
	if (kb->inputQueue.size() > 100)
	{
		kb->inputQueue.pop_front();
	}
}