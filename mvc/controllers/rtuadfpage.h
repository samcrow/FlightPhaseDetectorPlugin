#ifndef RTUADFPAGE_H
#define RTUADFPAGE_H
#include "rtupage.h"
#include "../views/rtu/rtuadfpageview.h"

class RTUADFPage : public RTUPage
{
public:
    RTUADFPage(TuningModel& model);
    
    virtual void leftLine2Pressed() override;
    virtual void leftLine3Pressed() override;
    virtual void leftLine4Pressed() override;
    virtual void rightLine1Pressed() override;
    
    virtual PPL::ViewComponent<TuningModel>* viewComponent() override;
    
private:
    RTUADFPageView view;
};

#endif // RTUADFPAGE_H
