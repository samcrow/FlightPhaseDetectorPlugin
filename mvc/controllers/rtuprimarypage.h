#ifndef RTUPRIMARYPAGE_H
#define RTUPRIMARYPAGE_H

#include "rtupage.h"
#include "../views/rtu/rtuprimarypageview.h"
#include "rtufrequencypaircontroller.h"

/**
 * @brief Controller for the RTU primary page
 */
class RTUPrimaryPage : public RTUPage
{
public:
    RTUPrimaryPage(TuningModel& model);
    
    virtual void leftLine1Pressed();
    virtual void leftLine2Pressed();
    virtual void leftLine3Pressed();
    virtual void leftLine4Pressed();
    
    virtual void rightLine1Pressed();
    virtual void rightLine2Pressed();
    virtual void rightLine3Pressed();
    virtual void rightLine4Pressed();
    
    virtual void outerKnobClockwise();
    virtual void outerKnobCounterclockwise();
    virtual void innerKnobClockwise();
    virtual void innerKnobCounterclockwise();
    
    virtual PPL::ViewComponent<TuningModel>* viewComponent();
    
private:

    RTUFrequencyPairController comController;
    RTUFrequencyPairController navController;
    
    RTUPrimaryPageView view;
    
    /**
     * @brief Swaps the currently displayed active and standby COM frequencies
     */
    void swapNav();
    /**
     * @brief Swaps the currently displayed active and standby NAV frequencies
     */
    void swapCom();
    
    void incrementStandbyFrequency(Frequency increment);
    
};

#endif // RTUPRIMARYPAGE_H
