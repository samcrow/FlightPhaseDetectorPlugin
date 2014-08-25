#ifndef ADFFREQUENCYDATAREFPAIR_H
#define ADFFREQUENCYDATAREFPAIR_H
#include <dataref.h>
#include "../data/frequency.h"

/**
 * @brief The FrequencyDataRefPair class provides access to a pair of Frequency datarefs.
 * 
 * This class works with the intricacies of the X-Plane ADF frequency storage mechanism.
 */
class ADFFrequencyDataRefPair
{
public:
    ADFFrequencyDataRefPair(std::string activeDataRefName, std::string standbyDataRefName);
    
    Frequency getActive();
    Frequency getStandby();
    
    void setActive(Frequency newActive);
    void setStandby(Frequency newStandby);
    
private:
    PPL::DataRef<int> active;
    PPL::DataRef<int> standby;
};

#endif // ADFFREQUENCYDATAREFPAIR_H
