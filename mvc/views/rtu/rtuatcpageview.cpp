#include "rtuatcpageview.h"
#include <sstream>
#include <iomanip>


void RTUATCPageView::draw(PPL::GraphicsContext &gc)
{
    
    gc.setStroke(PPL::Color(1, 1, 1, 1));
    // Title
    gc.strokeTextCentered("ATC", metrics.col2Center, metrics.line1Label, PPL::GraphicsContext::Monospace, metrics.primaryLabelSize);
    
    // Transponder code
    // Format with four digits
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(4) << model().getTransponderCode();
    gc.setStroke(green);
    gc.strokeTextCentered(stream.str(), metrics.col1Center, metrics.line1Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
    
    // Box around code
    const float boxTop = 2 + metrics.line1Center + metrics.primaryValueSize;
    const float boxBottom = -2 + metrics.line1Center;
    const float boxLeft = metrics.col1Center - 20;
    const float boxRight = metrics.col1Center + 20;
    gc.setStroke(white);
    gc.strokeRect(boxTop, boxLeft, boxBottom, boxRight);
    
    
    // Standby/active indicator
    gc.setStroke(blue);
    std::string activeText = model().getTransponderMode() == TuningModel::TransponderMode::On ? "ATC 1" : "STBY";
    gc.strokeTextCentered(activeText, metrics.col1Center, metrics.line1Center - metrics.secondaryValueSize - 3, PPL::GraphicsContext::Monospace, metrics.secondaryValueSize);
    
    // Altitude mode indicator
    gc.setStroke(white);
    gc.strokeTextCentered("ALT", metrics.col1Center, metrics.line2Label, PPL::GraphicsContext::Monospace, metrics.secondaryLabelSize);
    
    // On indicator
    if(model().isTransponderAltitudeDisplayed()) {
        gc.setStroke(blue);
    }
    else {
        gc.setStroke(white);
    }
    gc.strokeTextCentered("ON", metrics.col1Center - 15, metrics.line2Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
    
    if(!model().isTransponderAltitudeDisplayed()) {
        gc.setStroke(blue);
    }
    else {
        gc.setStroke(white);
    }
    gc.strokeTextCentered("OFF", metrics.col1Center + 15, metrics.line2Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
    
    // Display numerical altitude
    if(model().isTransponderAltitudeDisplayed()) {
        // Display altitude: Big number for thousands,
        // small number for hundreds
        int altitude = model().getAltitude();
        int thousands = altitude / 1000;
        int tens = (altitude % 1000) / 10;
        
        // Format each value with two digits
        std::stringstream stream;
        stream << std::setfill(' ') << std::setw(2);
        stream << thousands;
        std::string thousandsString = stream.str();
        std::stringstream stream2;
        stream2 << std::setfill('0') << std::setw(2) << tens;
        std::string tensString = stream2.str();
        
        gc.strokeTextCentered(thousandsString, metrics.col2Center + 10, metrics.line3Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
        gc.strokeTextCentered(tensString, metrics.col2Center + 27, metrics.line3Center, PPL::GraphicsContext::Monospace, metrics.secondaryValueSize);
    }
    
    // Return key label
    gc.setStroke(white);
    gc.strokeTextCentered("RETURN", metrics.col1Center, metrics.line4Center, PPL::GraphicsContext::Monospace, metrics.primaryLabelSize);
}
