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
    g.fillAll (Colour(0xff36454f));

	header.setBounds(0, 0, 800, 50);
	addAndMakeVisible(header);
}

void MreverbAudioProcessorEditor::resized()
{
}
