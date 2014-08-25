#ifndef RTUPRIMARYPAGEVIEW_H
#define RTUPRIMARYPAGEVIEW_H
#include "../rtuviewcomponent.h"
#include "../../models/tuningmodel.h"

class RTUPrimaryPageView : public RTUViewComponent < TuningModel >
{
public:
    RTUPrimaryPageView(TuningModel& model) :
        RTUViewComponent<TuningModel>(model)
    {}
    
    void draw(PPL::GraphicsContext& gc) override;
};

#endif // RTUPRIMARYPAGEVIEW_H
