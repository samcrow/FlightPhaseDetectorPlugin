#include "frequencyowneddatapair.h"

FrequencyOwnedDataPair::FrequencyOwnedDataPair(std::string activeDataRefName, std::string standbyDataRefName) :
    // Last parameter is whether it should be published in DataRefEditor
    active(activeDataRefName, PPL::ReadWrite, true),
    standby(standbyDataRefName, PPL::ReadWrite, true)
{
}

Frequency FrequencyOwnedDataPair::getActive() {
    return Frequency(int32_t(active * 10000));
}

Frequency FrequencyOwnedDataPair::getStandby() {
    return Frequency(int32_t(standby * 10000));
}

void FrequencyOwnedDataPair::setActive(Frequency newActive) {
    active = newActive.hertz() / 10000;
}

void FrequencyOwnedDataPair::setStandby(Frequency newStandby) {
    standby = newStandby.hertz() / 10000;
}
