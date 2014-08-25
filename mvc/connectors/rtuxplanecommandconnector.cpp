#include "rtuxplanecommandconnector.h"
#include "../controllers/rtucontroller.h"

RTUXPlaneCommandConnector::RTUXPlaneCommandConnector(RTUController &inController) :
    controller(inController),
    
    // Lots of commands
    
#define INIT_CMD(field, key, description) \
    field(commandName(#key).c_str(), description, 0)
    
    INIT_CMD(leftLine1, left_line_1, "RTU left line 1 select button"),
    INIT_CMD(leftLine2, left_line_2, "RTU left line 2 select button"),
    INIT_CMD(leftLine3, left_line_3, "RTU left line 3 select button"),
    INIT_CMD(leftLine4, left_line_4, "RTU left line 4 select button"),
    
    INIT_CMD(rightLine1, right_line_1, "RTU right line 1 select button"),
    INIT_CMD(rightLine2, right_line_2, "RTU right line 2 select button"),
    INIT_CMD(rightLine3, right_line_3, "RTU right line 3 select button"),
    INIT_CMD(rightLine4, right_line_4, "RTU right line 4 select button"),
    
    INIT_CMD(ident, ident, "RTU transponder ident"),
    INIT_CMD(dmeHold, dme_hold, "RTU DME hold"),
    INIT_CMD(leftRight, left_right_select, "RTU left/right tune select"),
    
    INIT_CMD(outerKnobClockwise, knob_outer_clockwise, "Rotates the outer RTU knob clockwise"),
    INIT_CMD(outerKnobCounterclockwise, knob_outer_counterclockwise, "Rotates the outer RTU knob counterclockwise"),
    INIT_CMD(innerKnobClockwise, knob_inner_clockwise, "Rotates the inner RTU knob clockwise"),
    INIT_CMD(innerKnobCounterclockwise, knob_inner_counterclockwise, "Rotates the inner RTU knob counterclockwise")
  
#undef INIT_CMD
{
    // Lots of hookups
#define HOOKUP(field, controllerFunction) \
    field.addListener(boost::bind(controllerFunction, boost::ref(controller)))
    
    HOOKUP(leftLine1, &RTUController::leftLine1Pressed);
    HOOKUP(leftLine2, &RTUController::leftLine2Pressed);
    HOOKUP(leftLine3, &RTUController::leftLine3Pressed);
    HOOKUP(leftLine4, &RTUController::leftLine4Pressed);
    
    HOOKUP(rightLine1, &RTUController::rightLine1Pressed);
    HOOKUP(rightLine2, &RTUController::rightLine2Pressed);
    HOOKUP(rightLine3, &RTUController::rightLine3Pressed);
    HOOKUP(rightLine4, &RTUController::rightLine4Pressed);
    
    HOOKUP(ident, &RTUController::identPressed);
    HOOKUP(dmeHold, &RTUController::dmeHoldPressed);
    HOOKUP(leftRight, &RTUController::leftRightPressed);
    
    HOOKUP(outerKnobClockwise, &RTUController::outerKnobClockwise);
    HOOKUP(outerKnobCounterclockwise, &RTUController::outerKnobCounterclockwise);
    
    HOOKUP(innerKnobClockwise, &RTUController::innerKnobClockwise);
    HOOKUP(innerKnobCounterclockwise, &RTUController::innerKnobCounterclockwise);
    
#undef HOOKUP
}

std::string RTUXPlaneCommandConnector::commandName(std::string commandKey) {
    return commandKey.insert(0, "C604/cockpit/RTU/");
}
