#ifndef __KEYINPUT_H__
#define __KEYINPUT_H__

#include <vector>

struct KeyInput
{
	
	bool down; //up is false, down is true
	int keyIndex; //start at 36 on the left side, but this will be 0 when the input byte is 36. ignore < 36

				  //byte 2 and stamp have something to do with the timing maybe? ignore for now
	KeyInput();
	void Print();
	bool SetFromCallbackData(double deltatime, std::vector< unsigned char > *message, void *userData);
};

#endif
