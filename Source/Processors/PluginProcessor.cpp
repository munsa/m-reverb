#include "PluginProcessor.h"
#include "../Components/MainComponent.h"

MreverbAudioProcessor::MreverbAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

MreverbAudioProcessor::~MreverbAudioProcessor()
{
}

const String MreverbAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MreverbAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MreverbAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MreverbAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MreverbAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MreverbAudioProcessor::getNumPrograms()
{
    return 1;
}

int MreverbAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MreverbAudioProcessor::setCurrentProgram (int index)
{
}

const String MreverbAudioProcessor::getProgramName (int index)
{
    return {};
}

void MreverbAudioProcessor::changeProgramName (int index, const String& newName)
{
}

void MreverbAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void MreverbAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MreverbAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void MreverbAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	ScopedNoDenormals noDenormals;
	auto totalNumInputChannels = getTotalNumInputChannels();
	auto totalNumOutputChannels = getTotalNumOutputChannels();
	bool processReverb = false;

	for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
		buffer.clear(i, 0, buffer.getNumSamples());

	// Num Channels
	const auto numChannels = jmin(totalNumInputChannels, totalNumOutputChannels);

	// Reverb Width
	if (reverbWidthValue >= 0)
	{
		processReverb = true;
		reverbParameters.width = reverbWidthValue;
	}

	// Reverb Room
	if (reverbRoomValue >= 0)
	{
		processReverb = true;
		reverbParameters.roomSize = reverbRoomValue;
	}

	// Reverb Wet
	if (reverbWetValue >= 0)
	{
		processReverb = true;
		reverbParameters.wetLevel = reverbWetValue;
	}

	// Reverb Dry
	if (reverbDryValue >= 0)
	{
		processReverb = true;
		reverbParameters.dryLevel = reverbDryValue;
	}

	// Process Reverb
	if (processReverb) {
		reverb.setParameters(reverbParameters);
		if (numChannels == 1)
			reverb.processMono(buffer.getWritePointer(0), buffer.getNumSamples());

		else if (numChannels == 2)
			reverb.processStereo(buffer.getWritePointer(0), buffer.getWritePointer(1), buffer.getNumSamples());
	}

	// Gain
	for (int channel = 0; channel < totalNumInputChannels; ++channel)
	{
		float* channelData = buffer.getWritePointer(channel);

		for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
			channelData[sample] = buffer.getSample(channel, sample) * gainValue;
		}
	}
}

//==============================================================================
bool MreverbAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MreverbAudioProcessor::createEditor()
{
    return new MreverbAudioProcessorEditor (*this);
}

//==============================================================================
void MreverbAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MreverbAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MreverbAudioProcessor();
}
