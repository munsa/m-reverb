
#include "../../../JuceLibraryCode/JuceHeader.h"
#include "BodyComponent.h"

BodyComponent::BodyComponent()
{
}

BodyComponent::~BodyComponent()
{
}

void BodyComponent::paint (Graphics& g)
{
    g.fillAll(Colour(0xff4a5760));
}

void BodyComponent::resized()
{
}
