#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

class Header    : public Component
{
public:
    Header();
    ~Header();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Header)
};
