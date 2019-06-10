
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
    g.fillAll (Colour(0xff727c83));
}

void BodyComponent::resized()
{
}
