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
	// Background colour
    g.fillAll (Colour(0xff253037));

	// Logo image
	Image logo = ImageCache::getFromMemory(BinaryData::logo_mreverb_png, BinaryData::logo_mreverb_pngSize);
	g.drawImageAt(logo, 0, 0);
}

void HeaderComponent::resized()
{
}
