#ifndef RTUCONTROLLER_H
#define RTUCONTROLLER_H
#include <mvc/controller.h>
#include <mvc/view/drawable.h>
#include "../models/tuningmodel.h"

#include "rtupage.h"
#include "rtuatcpage.h"
#include "rtuadfpage.h"

class RTUController : public PPL::Controller < TuningModel >, public PPL::Drawable
{
public:
    RTUController(TuningModel& model);
    
    // Buttons
    
    // Line select buttons
    void leftLine1Pressed();
    void leftLine2Pressed();
    void leftLine3Pressed();
    void leftLine4Pressed();
    
    void rightLine1Pressed();
    void rightLine2Pressed();
    void rightLine3Pressed();
    void rightLine4Pressed();
    
    // Other buttons
    void identPressed();
    // DME hold (DME-H)
    void dmeHoldPressed();
    // Left/right side select (1-2)
    void leftRightPressed();
    
    // Knob
    void outerKnobClockwise();
    void outerKnobCounterclockwise();
    
    void innerKnobClockwise();
    void innerKnobCounterclockwise();
    
    // Drawable interface
    void draw(PPL::GraphicsContext& gc);
    
    
private:
    
    // Page control function,
    // called by pages to switch to other pages
    
    
    void setActivePage(RTUPage::Page newPage);
    
    // Pages
    RTUATCPage atcPage;
    RTUADFPage adfPage;
    
    // The page currently being displayed
    RTUPage* activePage;
};

#endif // RTUCONTROLLER_H
