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
    
    ident.addClickHandler(boost::bind(&RTUController::identPressed, controllerPtr));
    dmeHold.addClickHandler(boost::bind(&RTUController::dmeHoldPressed, controllerPtr));
    leftRightSelect.addClickHandler(boost::bind(&RTUController::leftRightPressed, controllerPtr));
    
}

void RTUView::draw(int left, int top, int right, int bottom) {
    // Draw image
    background.drawTex(left, top, right, bottom, 1);
    
    // Draw controller-defined graphics
    OverlayGaugeView::draw(left, top, right, bottom);
    
    
}

RTUView::~RTUView() {
    
}
