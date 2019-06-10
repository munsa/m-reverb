#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

class HeaderComponent : public Component
{
public:
	HeaderComponent();
    ~HeaderComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HeaderComponent)
};
