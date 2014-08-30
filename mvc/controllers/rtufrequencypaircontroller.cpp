#include "rtufrequencypaircontroller.h"
#include <string>


RTUFrequencyPairController::RTUFrequencyPairController(callback_type activeStandbySwitchCallback) :
    switchCallback(activeStandbySwitchCallback)
{
    selected_ = false;
    presetMode_ = false;
}

void RTUFrequencyPairController::setSelected(bool selected) {
    selected_ = selected;
}

void RTUFrequencyPairController::lineKeyPressed() {
    if(!selected_) {
        selected_ = true;
    }
    else {
        // Swap active and standby
        switchCallback();
        // Switch to recall mode
        presetMode_ = false;
    }
}

void RTUFrequencyPairController::otherLineKeyPressed() {
    selected_ = false;
}

void RTUFrequencyPairController::frequencyKnobRotated() {
    if(selected_) {
        // Switch from recall to preset mode
        presetMode_ = true;
    }
}

bool RTUFrequencyPairController::isSelected() {
    return selected_;
}

bool RTUFrequencyPairController::shouldDisplayTuningWindow()
{
    return selected_;
}

bool RTUFrequencyPairController::shouldDisplayHorizontalArrow()
{
    return selected_;
}

const std::string& RTUFrequencyPairController::getLabel()
{
    if(presetMode_) {
        static const std::string pre = "PRE";
        return pre;
    }
    else {
        static const std::string recall = "RECALL";
        return recall;
    }
}

