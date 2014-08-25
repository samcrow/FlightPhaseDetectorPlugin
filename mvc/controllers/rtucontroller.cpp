#include "rtucontroller.h"
#include <iostream>
#include "rtupage.h"
#include <stdexcept>
#include <boost/lexical_cast.hpp>
#include <mvc/view/graphicscontext.h>
#include <mvc/view/viewcomponent.h>

RTUController::RTUController(TuningModel &model) :
    PPL::Controller < TuningModel > ("Radio Tuning Unit controller", model),
    atcPage(model),
    adfPage(model),
    activePage(&adfPage)
{
    // Hook up the page change signal for every page
    atcPage.setPage.connect(boost::bind(&RTUController::setActivePage, this, _1));
    adfPage.setPage.connect(boost::bind(&RTUController::setActivePage, this, _1));
}

void RTUController::setActivePage(RTUPage::Page newPage) {
    switch(newPage) {
    // TODO
    
    case RTUPage::Page::ATC:
        activePage = &atcPage;
        break;
    
    default:
        throw std::logic_error(std::string("RTU: Asked to switch to an unknown page, numbered ")+boost::lexical_cast<std::string>(static_cast<int>(newPage)));
    }
}

void RTUController::draw(PPL::GraphicsContext& gc) {
    // Clear screen
    gc.setFill(PPL::Color(0.13, 0.12, 0.12, 1));
    gc.fillRect(181, 56, 35, 196);
    
    // Draw page graphics
    activePage->viewComponent()->draw(gc);
}

// Some buttons delegate to the active page
void RTUController::leftLine1Pressed() {
    activePage->leftLine1Pressed();
}
void RTUController::leftLine2Pressed() {
    activePage->leftLine2Pressed();
}
void RTUController::leftLine3Pressed() {
    activePage->leftLine3Pressed();
}
void RTUController::leftLine4Pressed() {
    activePage->leftLine4Pressed();
}
void RTUController::rightLine1Pressed() {
    activePage->rightLine1Pressed();
}
void RTUController::rightLine2Pressed() {
    activePage->rightLine2Pressed();
}
void RTUController::rightLine3Pressed() {
    activePage->rightLine3Pressed();
}
void RTUController::rightLine4Pressed() {
    activePage->rightLine4Pressed();
}

void RTUController::identPressed() {
    model().transponderIdent();
}

void RTUController::dmeHoldPressed() {
    
}

void RTUController::leftRightPressed() {
    
}

void RTUController::outerKnobClockwise() {
    activePage->outerKnobClockwise();
}
void RTUController::outerKnobCounterclockwise() {
    activePage->outerKnobCounterclockwise();
}
void RTUController::innerKnobClockwise() {
    activePage->innerKnobClockwise();
}
void RTUController::innerKnobCounterclockwise() {
    activePage->innerKnobCounterclockwise();
}