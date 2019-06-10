#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

class OutputComponent    : public Component
{
public:
    OutputComponent();
    ~OutputComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OutputComponent)
};
