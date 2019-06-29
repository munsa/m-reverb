#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class MreverbAudioProcessor  : public AudioProcessor
{
public:
    MreverbAudioProcessor();
    ~MreverbAudioProcessor();

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;


	double reverbWidthValue;
	double reverbRoomValue;
	double reverbDryValue;
	double reverbWetValue;
	Reverb reverb;
	Reverb::Parameters reverbParameters;
	double gainValue;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MreverbAudioProcessor)
};
