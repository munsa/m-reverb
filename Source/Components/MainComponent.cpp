#include "../Processors/PluginProcessor.h"
#include "../Components/MainComponent.h"
#include "../Components/Header/HeaderComponent.h"

MreverbAudioProcessorEditor::MreverbAudioProcessorEditor (MreverbAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (800, 400);
}

MreverbAudioProcessorEditor::~MreverbAudioProcessorEditor()
{
}

void MreverbAudioProcessorEditor::paint (Graphics& g)
{
	// Background
    g.fillAll (Colour(0xff36454f));

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
	addAndMakeVisible(body);

	// Output
	output.setBounds(
		body.getWidth() + 40, 
		header.getHeight() + 20, 
		140, 
		getHeight() - header.getHeight() - 40);
	addAndMakeVisible(output);
}

void MreverbAudioProcessorEditor::resized()
{
}
