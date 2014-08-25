#include "rtuatcpage.h"
#include <mvc/view/graphicscontext.h>
#include <sstream>
#include <iomanip>
#include <boost/lexical_cast.hpp>

RTUATCPage::RTUATCPage(TuningModel &model) :
    RTUPage("RTU ATC page controller", model),
    view(model)
{
}

void RTUATCPage::leftLine1Pressed() {
    // Toggle between standby and on mode
    TuningModel::TransponderMode mode = model().getTransponderMode();
    if(mode != TuningModel::TransponderMode::On) {
        model().setTransponderMode(TuningModel::TransponderMode::On);
    }
    else {
        model().setTransponderMode(TuningModel::TransponderMode::Standby);
    }
}

void RTUATCPage::leftLine4Pressed() {
    // Return to main page
    setPage(Page::Primary);
}

void RTUATCPage::leftLine2Pressed() {
    // Toggle display of altitude
    model().setTransponderAltitudeDisplayed(!model().isTransponderAltitudeDisplayed());
}

// Overall numerical intent: Keep the code in the range 0-7777
// and don't let one digit pair affect the other

// Outer knob controls first two digits
void RTUATCPage::outerKnobClockwise()
{
    int code = model().getTransponderCode();
    int newCode = code + 100;
    // Check rollover: don't let the code exceed 7777
    if(newCode > 7777) {
        newCode -= 7800;
    }
    model().setTransponderCode(newCode);
}

void RTUATCPage::outerKnobCounterclockwise()
{
    int code = model().getTransponderCode();
    int newCode = code - 100;
    // Check rollunder: Don't let the code be negative
    if(newCode < 0) {
        newCode += 7800;
    }
    model().setTransponderCode(newCode);
}
// Inner knob controls last two digits
void RTUATCPage::innerKnobClockwise()
{
    int code = model().getTransponderCode();
    int newCode;
    
    int lastTwoDigits = code % 100;
    if(lastTwoDigits == 77) {
        // Roll over and make last two digits zero
        newCode = code - 77;
    }
    else {
        // Just increment the last two digits
        newCode = code + 1;
    }
    
    model().setTransponderCode(newCode);
}

void RTUATCPage::innerKnobCounterclockwise()
{
    int code = model().getTransponderCode();
    int newCode;
    int lastTwoDigits = code % 100;
    // Don't let the last two digits go below zero and start
    // dragging down the other digits
    if(lastTwoDigits == 0) {
        newCode = code + 77;
    }
    else {
        // Just decrement the code
        newCode = code - 1;
    }
    
    model().setTransponderCode(newCode);
}

PPL::ViewComponent<TuningModel>* RTUATCPage::viewComponent() {
    return &view;
}
