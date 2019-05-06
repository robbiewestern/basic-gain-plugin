/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainSliderTutorialAudioProcessorEditor::GainSliderTutorialAudioProcessorEditor (GainSliderTutorialAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
    
    sliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, GAIN_ID, gainSlider);
    
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    gainSlider.setRange(minGain, maxGain, 0.01f);
    gainSlider.setValue(startGain);
    gainSlider.setTextValueSuffix(" dB");
    addAndMakeVisible(&gainSlider);
    
    gainLabel.setText("Gain", dontSendNotification);
    gainLabel.attachToComponent(&gainSlider, false);
    addAndMakeVisible(&gainLabel);

}

GainSliderTutorialAudioProcessorEditor::~GainSliderTutorialAudioProcessorEditor()
{
}

//==============================================================================
void GainSliderTutorialAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

}

void GainSliderTutorialAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds());
}

