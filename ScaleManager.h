#ifndef __SCALEMANAGER_H__
#define __SCALEMANAGER_H__

#include <string>
#include <vector>
#include "Note.h"

struct ScaleManager
{
	std::vector<std::string> majorSharps;// [NUM_NOTES_PER_SCALE] = { "G", "D", "A", "E", "B", "F#", "C#" };
	std::vector<std::string> majorFlats;// [NUM_NOTES_PER_SCALE] = { "F", "Bb", "Eb", "Ab", "Db", "Gb", "Cb" };
	Scale scales[SCALE_Count][NUM_MAJOR_SCALES];

	ScaleManager();
	Note GetNote(int noteIndex, int scaleLetter, int scaleAccidental, int scaleType);
	void FillScales();
};

#endif
