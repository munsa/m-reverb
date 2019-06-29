#include "../../../JuceLibraryCode/JuceHeader.h"
#include "BodyComponent.h"

String textFromValueFunction(double value);
double valueFromTextFunction(String text);

BodyComponent::BodyComponent()
{
	// Wet Knob
	addAndMakeVisible(reverbWetKnob);
	reverbWetKnob.setTextValueSuffix(" %");
	reverbWetKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 100, reverbWetKnob.getTextBoxHeight());
	reverbWetKnob.setSliderStyle(Slider::RotaryVerticalDrag);
	reverbWetKnob.setSize(100, 100);
	reverbWetKnob.setRange(0.0, 1.0);
	reverbWetKnob.setValue(1.0);
	reverbWetKnob.textFromValueFunction = [](double value)
	{
		return textFromValueFunction(value);
	};
	reverbWetKnob.valueFromTextFunction = [](const String & text)
	{
		return valueFromTextFunction(text);
	};
	reverbWetKnob.updateText();
	addAndMakeVisible(reverbWetKnob);

	// Dry Knob
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
	reverbWetKnob.setBounds(3*(getWidth() / 4) - (getWidth() / 8) - (reverbDryKnob.getWidth() / 2), getHeight() - 120, 100, 100);
	reverbDryKnob.setBounds(4*(getWidth() / 4) - (getWidth() / 8) - (reverbDryKnob.getWidth() / 2), getHeight() - 120, 100, 100);
}
