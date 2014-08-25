#include "rtuadfpageview.h"
#include <sstream>

void RTUADFPageView::draw(PPL::GraphicsContext &gc) {
    
    // Title
    gc.setStroke(white);
    gc.strokeTextCentered("ADF1", metrics.col2Center, metrics.line1Label, PPL::GraphicsContext::Monospace, metrics.primaryLabelSize);
    
    // ADF frequency in kilohertz, three digits with one decimal digit
    std::stringstream freqStream;
    freqStream.precision(1);
    freqStream << std::fixed;
    freqStream << model().getADF1().kilohertz();
    gc.setStroke(green);
    gc.strokeTextCentered(freqStream.str(), metrics.col1Center, metrics.line1Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
    
    // Box around frequency
    const float boxTop = 2 + metrics.line1Center + metrics.primaryValueSize;
    const float boxBottom = -2 + metrics.line1Center;
    const float boxLeft = metrics.col1Center - 25;
    const float boxRight = metrics.col1Center + 23;
    gc.setStroke(white);
    gc.strokeRect(boxTop, boxLeft, boxBottom, boxRight);
    
    // Mode indicator
    
    gc.strokeText("MODE", metrics.col1Center - 15, metrics.line2Label, PPL::GraphicsContext::Monospace, metrics.secondaryLabelSize);
    
    PPL::Color adfColor;
    PPL::Color antColor;
    if(model().getADFMode() == TuningModel::ADF) {
        adfColor = blue;
        antColor = white;
    }
    else {
        adfColor = white;
        antColor = blue;
    }
    gc.setStroke(adfColor);
    gc.strokeText("ADF", metrics.col1Center - 18 - 15, metrics.line2Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
    gc.setStroke(antColor);
    gc.strokeText("ANT", metrics.col1Center + 18 - 15, metrics.line2Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
    
    // Tone indicator
    gc.setStroke(white);
    gc.strokeText("TONE", metrics.col1Center - 15, metrics.line3Label, PPL::GraphicsContext::Monospace, metrics.secondaryLabelSize);
    
    PPL::Color onColor;
    PPL::Color offColor;
    if(model().isADFToneEnabled()) {
        onColor = blue;
        offColor = white;
    }
    else {
        onColor = white;
        offColor = blue;
    }
    gc.setStroke(onColor);
    gc.strokeText("ON", metrics.col1Center - 18 - 15, metrics.line3Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
    gc.setStroke(offColor);
    gc.strokeText("OFF", metrics.col1Center + 18 - 15, metrics.line3Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
    
    // Return label
    gc.setStroke(white);
    gc.strokeTextCentered("RETURN", metrics.col1Center, metrics.line4Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
    // Test label
    gc.strokeTextCentered("TEST", metrics.col3Center, metrics.line4Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
}
