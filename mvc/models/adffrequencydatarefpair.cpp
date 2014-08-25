#include "adffrequencydatarefpair.h"

ADFFrequencyDataRefPair::ADFFrequencyDataRefPair(std::string activeDataRefName, std::string standbyDataRefName) :
    active(activeDataRefName, PPL::ReadWrite),
    standby(standbyDataRefName, PPL::ReadWrite)
{
}

Frequency ADFFrequencyDataRefPair::getActive() {
    // Datarefs store frequencies in kilohertz
    return Frequency(uint32_t(active * 1000));
}

Frequency ADFFrequencyDataRefPair::getStandby() {
    return Frequency(uint32_t(standby * 1000));
}

void ADFFrequencyDataRefPair::setActive(Frequency newActive) {
    active = newActive.kilohertz();
}

void ADFFrequencyDataRefPair::setStandby(Frequency newStandby) {
    standby = newStandby.kilohertz();
}
