#include "../../../JuceLibraryCode/JuceHeader.h"
#include "OutputComponent.h"

String textFromValueFunction(double value);
double valueFromTextFunction(String text);

OutputComponent::OutputComponent()
{
	addAndMakeVisible(gainKnob);
	gainKnob.setTextValueSuffix(" dB");
	gainKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 100, gainKnob.getTextBoxHeight());
	gainKnob.setSliderStyle(Slider::RotaryVerticalDrag);
	gainKnob.setSize(100,100);
	gainKnob.setRange(0.0, 1.0);
	gainKnob.setValue(1.0);
	gainKnob.setSkewFactor(0.5);
	gainKnob.textFromValueFunction = [](double value)
	{
		return textFromValueFunction(value);
	};
	gainKnob.valueFromTextFunction = [](const String & text)
	{
		return valueFromTextFunction(text);
	};
	gainKnob.updateText();
	addAndMakeVisible(gainKnob);
}

OutputComponent::~OutputComponent()
{
}

void OutputComponent::paint (Graphics& g)
{
	g.fillAll(Colour(0xff4a5760));
}

void OutputComponent::resized()
{
	gainKnob.setBounds((getWidth() / 2) - 50, getHeight() - 120, 100, 100);
}