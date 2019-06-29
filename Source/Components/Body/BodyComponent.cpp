#include "../../../JuceLibraryCode/JuceHeader.h"
#include "BodyComponent.h"

String textFromValueFunction(double value);
double valueFromTextFunction(String text);

BodyComponent::BodyComponent()
{
	// Width Knob
	addAndMakeVisible(reverbWidthKnob);
	reverbWidthKnob.setTextValueSuffix(" %");
	reverbWidthKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 100, reverbWidthKnob.getTextBoxHeight());
	reverbWidthKnob.setSliderStyle(Slider::RotaryVerticalDrag);
	reverbWidthKnob.setSize(100, 100);
	reverbWidthKnob.setRange(0.0, 1.0);
	reverbWidthKnob.setValue(1.0);
	reverbWidthKnob.textFromValueFunction = [](double value)
	{
		return textFromValueFunction(value);
	};
	reverbWidthKnob.valueFromTextFunction = [](const String & text)
	{
		return valueFromTextFunction(text);
	};
	reverbWidthKnob.updateText();
	addAndMakeVisible(reverbWidthKnob);

	// Room Knob
	addAndMakeVisible(reverbRoomKnob);
	reverbRoomKnob.setTextValueSuffix(" %");
	reverbRoomKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 100, reverbRoomKnob.getTextBoxHeight());
	reverbRoomKnob.setSliderStyle(Slider::RotaryVerticalDrag);
	reverbRoomKnob.setSize(100, 100);
	reverbRoomKnob.setRange(0.0, 1.0);
	reverbRoomKnob.setValue(1.0);
	reverbRoomKnob.textFromValueFunction = [](double value)
	{
		return textFromValueFunction(value);
	};
	reverbRoomKnob.valueFromTextFunction = [](const String & text)
	{
		return valueFromTextFunction(text);
	};
	reverbRoomKnob.updateText();
	addAndMakeVisible(reverbRoomKnob);

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
	reverbWidthKnob.setBounds(1 * (getWidth() / 4) - (getWidth() / 8) - (reverbWidthKnob.getWidth() / 2), getHeight() - 120, 100, 100);
	reverbRoomKnob.setBounds(2 * (getWidth() / 4) - (getWidth() / 8) - (reverbRoomKnob.getWidth() / 2), getHeight() - 120, 100, 100);
	reverbWetKnob.setBounds(3 * (getWidth() / 4) - (getWidth() / 8) - (reverbWetKnob.getWidth() / 2), getHeight() - 120, 100, 100);
	reverbDryKnob.setBounds(4 * (getWidth() / 4) - (getWidth() / 8) - (reverbDryKnob.getWidth() / 2), getHeight() - 120, 100, 100);
}
