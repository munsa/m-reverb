#include "../../../JuceLibraryCode/JuceHeader.h"
#include "BodyComponent.h"

String textFromValueFunction(double value);
double valueFromTextFunction(String text);

BodyComponent::BodyComponent()
{
	addAndMakeVisible(reverbDryKnob);
	reverbDryKnob.setTextValueSuffix(" %");
	reverbDryKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 100, reverbDryKnob.getTextBoxHeight());
	reverbDryKnob.setSliderStyle(Slider::RotaryVerticalDrag);
	reverbDryKnob.setSize(100, 100);
	reverbDryKnob.setRange(0.0, 1.0);
	reverbDryKnob.setValue(1.0);
	reverbDryKnob.textFromValueFunction = [](double value)
	{
		return textFromValueFunction(value);
	};
	reverbDryKnob.valueFromTextFunction = [](const String & text)
	{
		return valueFromTextFunction(text);
	};
	reverbDryKnob.updateText();
	addAndMakeVisible(reverbDryKnob);




}

BodyComponent::~BodyComponent()
{
}

void BodyComponent::paint (Graphics& g)
{
    g.fillAll(Colour(0xff4a5760));
}

void BodyComponent::resized()
{
	reverbDryKnob.setBounds(4*(getWidth() / 4) - (getWidth() / 8) - (reverbDryKnob.getWidth() / 2), getHeight() - 120, 100, 100);
}
