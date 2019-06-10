#include "../../../JuceLibraryCode/JuceHeader.h"
#include "HeaderComponent.h"

HeaderComponent::HeaderComponent()
{
}

HeaderComponent::~HeaderComponent()
{
}

void HeaderComponent::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("Header", getLocalBounds(),
                Justification::centred, true);
}

void HeaderComponent::resized()
{
}
