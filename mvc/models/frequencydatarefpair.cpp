#include "frequencydatarefpair.h"

FrequencyDataRefPair::FrequencyDataRefPair(std::string activeDataRefName, std::string standbyDataRefName) :
    active(activeDataRefName, PPL::ReadWrite),
    standby(standbyDataRefName, PPL::ReadWrite)
{
}

Frequency FrequencyDataRefPair::getActive() {
    // Datarefs store frequencies in tens of hertz
    return Frequency(uint32_t(active / 10));
}

Frequency FrequencyDataRefPair::getStandby() {
    return Frequency(uint32_t(standby / 10));
}

void FrequencyDataRefPair::setActive(Frequency newActive) {
    active = newActive.ten_hertz();
}

void FrequencyDataRefPair::setStandby(Frequency newStandby) {
    standby = newStandby.ten_hertz();
}
