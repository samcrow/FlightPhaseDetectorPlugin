#include "frequencydatarefpair.h"

FrequencyDataRefPair::FrequencyDataRefPair(std::string activeDataRefName, std::string standbyDataRefName) :
    active(activeDataRefName, PPL::ReadWrite),
    standby(standbyDataRefName, PPL::ReadWrite)
{
}

Frequency FrequencyDataRefPair::getActive() {
    // Datarefs store frequencies in megahertz * 100
    return Frequency(int32_t(active * 10000));
}

Frequency FrequencyDataRefPair::getStandby() {
    return Frequency(int32_t(standby * 10000));
}

void FrequencyDataRefPair::setActive(Frequency newActive) {
    active = newActive.hertz() / 10000;
}

void FrequencyDataRefPair::setStandby(Frequency newStandby) {
    standby = newStandby.hertz() / 10000;
}
