#include "ScaleManager.h"

ScaleManager::ScaleManager()
{
	majorSharps = { "G", "D", "A", "E", "B", "F#", "C#" };
	majorFlats = { "F", "Bb", "Eb", "Ab", "Db", "Gb", "Cb" };
	FillScales();
}

Note ScaleManager::GetNote(int noteIndex, int scaleLetter, int scaleAccidental, int scaleType)
{
	return scales[scaleType][scaleLetter].GetNote(noteIndex);
}

void ScaleManager::FillScales()
{
	scales[SCALE_MAJOR][0] = Scale(SCALE_MAJOR, LETTER_C, ACC_NEUTRAL);
	scales[SCALE_MAJOR][1] = Scale(SCALE_MAJOR, LETTER_D, ACC_NEUTRAL);
	scales[SCALE_MAJOR][2] = Scale(SCALE_MAJOR, LETTER_E, ACC_NEUTRAL);
	scales[SCALE_MAJOR][3] = Scale(SCALE_MAJOR, LETTER_F, ACC_SHARP);
	scales[SCALE_MAJOR][4] = Scale(SCALE_MAJOR, LETTER_A, ACC_FLAT);
	scales[SCALE_MAJOR][5] = Scale(SCALE_MAJOR, LETTER_B, ACC_FLAT);
	scales[SCALE_MAJOR][6] = Scale(SCALE_MAJOR, LETTER_G, ACC_NEUTRAL);
	scales[SCALE_MAJOR][7] = Scale(SCALE_MAJOR, LETTER_A, ACC_NEUTRAL);
	scales[SCALE_MAJOR][8] = Scale(SCALE_MAJOR, LETTER_B, ACC_NEUTRAL);
	scales[SCALE_MAJOR][9] = Scale(SCALE_MAJOR, LETTER_D, ACC_FLAT);
	scales[SCALE_MAJOR][10] = Scale(SCALE_MAJOR, LETTER_E, ACC_FLAT);
	scales[SCALE_MAJOR][11] = Scale(SCALE_MAJOR, LETTER_F, ACC_NEUTRAL);

	scales[SCALE_MINOR][0] = Scale(SCALE_MINOR, LETTER_C, ACC_NEUTRAL);
	scales[SCALE_MINOR][1] = Scale(SCALE_MINOR, LETTER_G, ACC_NEUTRAL);
	scales[SCALE_MINOR][2] = Scale(SCALE_MINOR, LETTER_D, ACC_NEUTRAL);
	scales[SCALE_MINOR][3] = Scale(SCALE_MINOR, LETTER_A, ACC_NEUTRAL);
	scales[SCALE_MINOR][4] = Scale(SCALE_MINOR, LETTER_E, ACC_NEUTRAL);
	scales[SCALE_MINOR][5] = Scale(SCALE_MINOR, LETTER_B, ACC_NEUTRAL);
	scales[SCALE_MINOR][6] = Scale(SCALE_MINOR, LETTER_F, ACC_SHARP);
	scales[SCALE_MINOR][7] = Scale(SCALE_MINOR, LETTER_C, ACC_SHARP);
	scales[SCALE_MINOR][8] = Scale(SCALE_MINOR, LETTER_G, ACC_SHARP);
	scales[SCALE_MINOR][9] = Scale(SCALE_MINOR, LETTER_E, ACC_FLAT);
	scales[SCALE_MINOR][10] = Scale(SCALE_MINOR, LETTER_B, ACC_FLAT);
	scales[SCALE_MINOR][11] = Scale(SCALE_MINOR, LETTER_F, ACC_NEUTRAL);

	chordQualityNames["M"] = "Major";
	chordQualityNames["m"] = "minor";
	chordQualityNames["d"] = "diminished";
	chordQualityNames["A"] = "Augmented";
}