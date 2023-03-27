#include "KeyInput.h"
#include <iostream>
#include <assert.h>

using namespace std;

KeyInput::KeyInput()
{

}

void KeyInput::Print()
{
	cout << "keyindex: " << keyIndex;

	if (down)
	{
		cout << " down\n";
	}
	else
	{
		cout << " up\n";
	}
}

bool KeyInput::SetFromCallbackData(double deltatime, std::vector< unsigned char > *message, void *userData)
{
	/*unsigned int nBytes = message->size();
	for (unsigned int i = 0; i<nBytes; i++)
		std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
	if (nBytes > 0)
		std::cout << "stamp = " << deltatime << std::endl;*/


	//assert(nBytes >= 2);

	unsigned char keyByte = message->at(1);
	int firstKey = 36;

	keyIndex = (int)keyByte - firstKey;

	if (keyIndex < 0)
	{
		return false;
	}

	unsigned char downByte = message->at(0);
	if (downByte == 144)
	{
		down = true;
	}
	else if (downByte == 128)
	{
		down = false;
	}
	else
	{
		cout << "downbyte was erroneously: " << (int)downByte << "\n";
		assert(0);
	}

	//byte at index 2 and stamp value are both unneeded for now

	return true;
	
}


 //start at 36 on the left side, but this will be 0 when the input byte is 36. ignore < 36
//byte 2 and stamp have something to do with the timing maybe? ignore for now