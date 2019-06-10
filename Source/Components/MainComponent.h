#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "../Processors/PluginProcessor.h"
#include "../Components/Header/HeaderComponent.h"
#include "../Components/Body/BodyComponent.h"
#include "../Components/Output/OutputComponent.h"

class MreverbAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    MreverbAudioProcessorEditor (MreverbAudioProcessor&);
    ~MreverbAudioProcessorEditor();
	
    void paint (Graphics&) override;
    void resized() override;

private:
    MreverbAudioProcessor& processor;

	HeaderComponent header;
	BodyComponent body;
	OutputComponent output;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MreverbAudioProcessorEditor)
};
