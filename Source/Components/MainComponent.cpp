#include "../Processors/PluginProcessor.h"
#include "../Components/MainComponent.h"
#include "../Components/Header/HeaderComponent.h"

MreverbAudioProcessorEditor::MreverbAudioProcessorEditor (MreverbAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (800, 400);

	// Header
	header.setBounds(
		0,
		0,
		getWidth(),
		50);
	addAndMakeVisible(header);

	// Body
	body.setBounds(
		20,
		header.getHeight() + 20,
		600,
		getHeight() - header.getHeight() - 40);
	body.reverbWidthKnob.addListener(this);
	body.reverbRoomKnob.addListener(this);
	body.reverbWetKnob.addListener(this);
	body.reverbDryKnob.addListener(this);
	addAndMakeVisible(body);

	// Output
	output.setBounds(
		body.getWidth() + 40,
		header.getHeight() + 20,
		140,
		getHeight() - header.getHeight() - 40);
	output.gainKnob.addListener(this);
	addAndMakeVisible(output);
}

MreverbAudioProcessorEditor::~MreverbAudioProcessorEditor()
{
}

void MreverbAudioProcessorEditor::paint (Graphics& g)
{
	// Background
    g.fillAll (Colour(0xff36454f));
}

void MreverbAudioProcessorEditor::resized()
{
}

void MreverbAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
	
	// Width
	if (slider == &body.reverbWidthKnob) {
		processor.reverbWidthValue = body.reverbWidthKnob.getValue();
	}

	// Room
	if (slider == &body.reverbRoomKnob) {
		processor.reverbRoomValue = body.reverbRoomKnob.getValue();
	}

	// Wet
	if (slider == &body.reverbWetKnob) {
		processor.reverbWetValue = body.reverbWetKnob.getValue();
	}

	// Dry
	if (slider == &body.reverbDryKnob) {
		processor.reverbDryValue = body.reverbDryKnob.getValue();
	}
	
	// Gain
	if (slider == &output.gainKnob) {
		processor.gainValue = output.gainKnob.getValue();
	}

}
