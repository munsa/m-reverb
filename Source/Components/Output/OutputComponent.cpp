#include "../../../JuceLibraryCode/JuceHeader.h"
#include "OutputComponent.h"

OutputComponent::OutputComponent()
{
}

OutputComponent::~OutputComponent()
{
}

void OutputComponent::paint (Graphics& g)
{
	g.fillAll(Colour(0xff4a5760));

}

void OutputComponent::resized()
{
}
