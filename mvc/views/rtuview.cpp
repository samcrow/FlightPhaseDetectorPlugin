#include "rtuview.h"
#include "../controllers/rtucontroller.h"
#include <pluginpath.h>
#include <iostream>

static const int RTU_WIDTH = 300;
static const int RTU_HEIGHT = 216;

static const int LEFT_LINES_LEFT = 14;
static const int LEFT_LINES_RIGHT = 34;
static const int RIGHT_LINES_LEFT = 214;
static const int RIGHT_LINES_RIGHT = 234;

static const int KNOB_INNER_RADIUS = 16;
static const int KNOB_OUTER_RADIUS = 26;
static const int KNOB_CENTER_X = 246;
static const int KNOB_CENTER_Y = 29;
static const int KNOB_VERTICAL_RADIUS = KNOB_INNER_RADIUS;


static const int RIGHT3_LEFT = 251;
static const int RIGHT3_RIGHT = 270;

RTUView::RTUView(RTUController &controller) :
    OverlayGaugeView(RTU_WIDTH, RTU_HEIGHT, controller),
    background(PPL::PluginPath::prependPluginResourcesPath("RTU.png")),
    
    leftLine1(168, LEFT_LINES_LEFT, 156, LEFT_LINES_RIGHT),
    leftLine2(136, LEFT_LINES_LEFT, 124, LEFT_LINES_RIGHT),
    leftLine3(104, LEFT_LINES_LEFT, 92, LEFT_LINES_RIGHT),
    leftLine4(77, LEFT_LINES_LEFT, 58, LEFT_LINES_RIGHT),
    
    rightLine1(171, RIGHT_LINES_LEFT, 152, RIGHT_LINES_RIGHT),
    rightLine2(136, RIGHT_LINES_LEFT, 124, RIGHT_LINES_RIGHT),
    rightLine3(104, RIGHT_LINES_LEFT, 92, RIGHT_LINES_RIGHT),
    rightLine4(70, RIGHT_LINES_LEFT, 58, RIGHT_LINES_RIGHT),
    
    outerKnobLeft(KNOB_CENTER_Y + KNOB_VERTICAL_RADIUS, KNOB_CENTER_X - KNOB_OUTER_RADIUS, KNOB_CENTER_Y - KNOB_VERTICAL_RADIUS, KNOB_CENTER_X - KNOB_INNER_RADIUS, PPL::CursorType::RotateLargeCounterclockwise),
    outerKnobRight(KNOB_CENTER_Y + KNOB_VERTICAL_RADIUS, KNOB_CENTER_X + KNOB_INNER_RADIUS, KNOB_CENTER_Y - KNOB_VERTICAL_RADIUS, KNOB_CENTER_X + KNOB_OUTER_RADIUS, PPL::CursorType::RotateLargeClockwise),
    innerKnobLeft(KNOB_CENTER_Y + KNOB_VERTICAL_RADIUS, KNOB_CENTER_X - KNOB_INNER_RADIUS, KNOB_CENTER_Y - KNOB_VERTICAL_RADIUS, KNOB_CENTER_X, PPL::CursorType::RotateMediumCounterclockwise),
    innerKnobRight(KNOB_CENTER_Y + KNOB_VERTICAL_RADIUS, KNOB_CENTER_X, KNOB_CENTER_Y - KNOB_VERTICAL_RADIUS, KNOB_CENTER_X + KNOB_INNER_RADIUS, PPL::CursorType::RotateMediumClockwise),
    
    ident(175, RIGHT3_LEFT, 154, RIGHT3_RIGHT),
    dmeHold(140, RIGHT3_LEFT, 121, RIGHT3_RIGHT),
    leftRightSelect(107, RIGHT3_LEFT, 88, RIGHT3_RIGHT)
{
    // Click regions    
    
    addClickRegion(&leftLine1);
    addClickRegion(&leftLine2);
    addClickRegion(&leftLine3);
    addClickRegion(&leftLine4);
    addClickRegion(&rightLine1);
    addClickRegion(&rightLine2);
    addClickRegion(&rightLine3);
    addClickRegion(&rightLine4);
    addClickRegion(&outerKnobLeft);
    addClickRegion(&outerKnobRight);
    addClickRegion(&innerKnobLeft);
    addClickRegion(&innerKnobRight);
    addClickRegion(&ident);
    addClickRegion(&dmeHold);
    addClickRegion(&leftRightSelect);
    
    RTUController* controllerPtr = &(View<RTUController>::controller());
    leftLine1.addClickHandler(boost::bind(&RTUController::leftLine1Pressed, controllerPtr));
    leftLine2.addClickHandler(boost::bind(&RTUController::leftLine2Pressed, controllerPtr));
    leftLine3.addClickHandler(boost::bind(&RTUController::leftLine3Pressed, controllerPtr));
    leftLine4.addClickHandler(boost::bind(&RTUController::leftLine4Pressed, controllerPtr));
    
    rightLine1.addClickHandler(boost::bind(&RTUController::rightLine1Pressed, controllerPtr));
    rightLine2.addClickHandler(boost::bind(&RTUController::rightLine2Pressed, controllerPtr));
    rightLine3.addClickHandler(boost::bind(&RTUController::rightLine3Pressed, controllerPtr));
    rightLine4.addClickHandler(boost::bind(&RTUController::rightLine4Pressed, controllerPtr));
    
    outerKnobLeft.addClickHandler(boost::bind(&RTUController::outerKnobCounterclockwise, controllerPtr));
    outerKnobRight.addClickHandler(boost::bind(&RTUController::outerKnobClockwise, controllerPtr));
    innerKnobLeft.addClickHandler(boost::bind(&RTUController::innerKnobCounterclockwise, controllerPtr));
    innerKnobRight.addClickHandler(boost::bind(&RTUController::innerKnobClockwise, controllerPtr));
    
    ident.addClickHandler(boost::bind(&RTUController::identPressed, controllerPtr));
    dmeHold.addClickHandler(boost::bind(&RTUController::dmeHoldPressed, controllerPtr));
    leftRightSelect.addClickHandler(boost::bind(&RTUController::leftRightPressed, controllerPtr));
    
    // Memory-leaking click regions for testing
    constexpr int top = 40;
    constexpr int bottom = 30;
    addClickRegion(new PPL::ClickRegion(top, 1, bottom, 5, PPL::CursorType::ArrowUp));
    addClickRegion(new PPL::ClickRegion(top, 6, bottom, 10, PPL::CursorType::ArrowDown));
    addClickRegion(new PPL::ClickRegion(top, 11, bottom, 15, PPL::CursorType::RotateLargeCounterclockwise));
    addClickRegion(new PPL::ClickRegion(top, 16, bottom, 20, PPL::CursorType::RotateLargeClockwise));
    addClickRegion(new PPL::ClickRegion(top, 21, bottom, 25, PPL::CursorType::RotateMediumCounterclockwise));
    addClickRegion(new PPL::ClickRegion(top, 26, bottom, 30, PPL::CursorType::RotateMediumClockwise));
    addClickRegion(new PPL::ClickRegion(top, 31, bottom, 35, PPL::CursorType::RotateSmallCounterclockwise));
    addClickRegion(new PPL::ClickRegion(top, 36, bottom, 40, PPL::CursorType::RotateSmallClockwise));
    addClickRegion(new PPL::ClickRegion(top, 41, bottom, 45, PPL::CursorType::ResizeHorizontal));
    addClickRegion(new PPL::ClickRegion(top, 46, bottom, 50, PPL::CursorType::ResizeVertical));
    addClickRegion(new PPL::ClickRegion(top, 51, bottom, 55, PPL::CursorType::MoveHorizontal));
    addClickRegion(new PPL::ClickRegion(top, 56, bottom, 60, PPL::CursorType::MoveVertical));
    addClickRegion(new PPL::ClickRegion(top, 61, bottom, 65, PPL::CursorType::Move));
    addClickRegion(new PPL::ClickRegion(top, 66, bottom, 70, PPL::CursorType::HandOpen));
    addClickRegion(new PPL::ClickRegion(top, 71, bottom, 75, PPL::CursorType::HandPointing));
    addClickRegion(new PPL::ClickRegion(top, 76, bottom, 80, PPL::CursorType::HandClosed));
    addClickRegion(new PPL::ClickRegion(top, 81, bottom, 86, PPL::CursorType::SmallCircle));
    
}

void RTUView::advancedDraw(int left, int top, int right, int bottom) {
    // Draw image
    background.drawTex(left, top, right, bottom, 1);
    
    // Draw controller-defined graphics
    OverlayGaugeView::advancedDraw(left, top, right, bottom);
    
    
}

RTUView::~RTUView() {
    
}
