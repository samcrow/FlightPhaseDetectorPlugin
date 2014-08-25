#ifndef FREQUENCYDATAREFPAIR_H
#define FREQUENCYDATAREFPAIR_H
#include <dataref.h>
#include "../data/frequency.h"

/**
 * @brief The FrequencyDataRefPair class provides access to a pair of Frequency datarefs.
 */
class FrequencyDataRefPair
{
public:
    FrequencyDataRefPair(std::string activeDataRefName, std::string standbyDataRefName);
    
    Frequency getActive();
    Frequency getStandby();
    
    void setActive(Frequency newActive);
    void setStandby(Frequency newStandby);
    
private:
    PPL::DataRef<int> active;
    PPL::DataRef<int> standby;
};

#endif // FREQUENCYDATAREFPAIR_H
