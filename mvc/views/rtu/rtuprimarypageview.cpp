#include "rtuprimarypageview.h"


void RTUPrimaryPageView::draw(PPL::GraphicsContext &gc) {
    
    // Title
    gc.setStroke(white);
    gc.strokeTextCentered("COM1", metrics.col2Center, metrics.line1Label, PPL::GraphicsContext::Monospace, metrics.primaryLabelSize);
    
    // COM1 labels: ACT and PRE
    gc.strokeTextCentered("ACT", metrics.col1Center, metrics.line1Center, PPL::GraphicsContext::Monospace, metrics.secondaryLabelSize);
    gc.strokeTextCentered("PRE", metrics.col3Center, metrics.line1Center, PPL::GraphicsContext::Monospace, metrics.secondaryLabelSize);
    
    
    
}
