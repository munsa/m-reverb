#include "../../../JuceLibraryCode/JuceHeader.h"
#include "OutputComponent.h"

OutputComponent::OutputComponent()
{
	addAndMakeVisible(gainKnob);
	gainKnob.setRange(0, 100);
	gainKnob.setTextValueSuffix(" dB");
	gainKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 100, gainKnob.getTextBoxHeight());
	gainKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
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
