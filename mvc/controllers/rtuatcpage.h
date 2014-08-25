#ifndef RTUATCPAGE_H
#define RTUATCPAGE_H
#include "rtupage.h"
#include "../views/rtu/rtuatcpageview.h"

class RTUATCPage : public RTUPage
{
public:
    RTUATCPage(TuningModel& model);
    
    void leftLine1Pressed();
    void leftLine4Pressed();
    void leftLine2Pressed();
    
    
    virtual void outerKnobClockwise();
    virtual void outerKnobCounterclockwise();
    virtual void innerKnobClockwise();
    virtual void innerKnobCounterclockwise();
    
    virtual PPL::ViewComponent<TuningModel>* viewComponent() override;
    
private:
    
    RTUATCPageView view;
};

#endif // RTUATCPAGE_H
