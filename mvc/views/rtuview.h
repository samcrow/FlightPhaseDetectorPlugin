#ifndef RTUVIEW_H
#define RTUVIEW_H

#include <texture.h>
#include <mvc/view/overlaygaugeview.h>
#include <mvc/view/clickregion/clickregion.h>

class RTUController;

class RTUView : public PPL::OverlayGaugeView < RTUController >
{
public:
    RTUView(RTUController& controller);
    
    virtual void advancedDraw(int left, int top, int right, int bottom) override;
    
    virtual ~RTUView();
private:
    
    PPL::Texture background;
    
    PPL::ClickRegion leftLine1;
    PPL::ClickRegion leftLine2;
    PPL::ClickRegion leftLine3;
    PPL::ClickRegion leftLine4;
    
    PPL::ClickRegion rightLine1;
    PPL::ClickRegion rightLine2;
    PPL::ClickRegion rightLine3;
    PPL::ClickRegion rightLine4;
    
    PPL::ClickRegion outerKnobLeft;
    PPL::ClickRegion outerKnobRight;
    PPL::ClickRegion innerKnobLeft;
    PPL::ClickRegion innerKnobRight;
    
    PPL::ClickRegion ident;
    PPL::ClickRegion dmeHold;
    PPL::ClickRegion leftRightSelect;
};

#endif // RTUVIEW_H
