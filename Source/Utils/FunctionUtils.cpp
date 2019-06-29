#include "../Utils/FunctionUtils.h"
#include <iostream>

String textFromValueFunction(double value)
{
	double level = value * 100.0;

	// Round
	int intLevel = (int)(level * 100.0);
	double roundedLevel = ((double)intLevel) / 100.0;

	return juce::String(roundedLevel) + "%";
}

double valueFromTextFunction(String text)
{
	double level = text.removeCharacters("%").getDoubleValue();

	// Round
	int intLevel = (int)(level * 100.0);
	double roundedLevel = ((double)intLevel) / 100.0;

	return roundedLevel / 100.0;
}