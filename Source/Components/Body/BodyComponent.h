#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

class BodyComponent    : public Component
{
public:
	Slider reverbDryKnob;
	Slider reverbWetKnob;

    BodyComponent();
    ~BodyComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (BodyComponent)
};
