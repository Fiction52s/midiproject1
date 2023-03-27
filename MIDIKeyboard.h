#ifndef __MIDIKEYBOARD_H__
#define __MIDIKEYBOARD_H__

#include "RtMidi.h"
#include <list>
#include "KeyInput.h"

struct MIDIKeyboard
{
	//singleton
	static MIDIKeyboard *GetInstance();
	static MIDIKeyboard *currInstance;

	RtMidiIn *midiin;

	std::list<KeyInput> inputQueue;

	MIDIKeyboard();
	bool Setup();
	~MIDIKeyboard();
	bool IsInitialized();

	static void MIDICallback(double deltatime, std::vector< unsigned char > *message, void *userData);
};

#endif
