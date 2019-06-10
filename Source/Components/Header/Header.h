/*
  ==============================================================================

    Header.h
    Created: 10 Jun 2019 8:51:54pm
    Author:  Marc Monserrat

  ==============================================================================
*/

#pragma once

#include "../../../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
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
