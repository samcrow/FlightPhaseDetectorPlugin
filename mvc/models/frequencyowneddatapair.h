#ifndef FREQUENCYOWNEDDATAPAIR_H
#define FREQUENCYOWNEDDATAPAIR_H
#include <owneddata.h>
#include "../data/frequency.h"

/**
 * @brief The FrequencyOwnedDataPair class provides access to a pair of Frequency datarefs
 * that are created by the plugin.
 */
class FrequencyOwnedDataPair
{
public:
    FrequencyOwnedDataPair(std::string activeDataRefName, std::string standbyDataRefName);
    
    Frequency getActive();
    Frequency getStandby();
    
    void setActive(Frequency newActive);
    void setStandby(Frequency newStandby);
    
private:
    PPL::OwnedData<int> active;
    PPL::OwnedData<int> standby;
};

#endif // FREQUENCYOWNEDDATAPAIR_H
