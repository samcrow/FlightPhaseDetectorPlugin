#ifndef RTUADFPAGEVIEW_H
#define RTUADFPAGEVIEW_H
#include "../rtuviewcomponent.h"
#include "../../models/tuningmodel.h"

class RTUADFPageView : public RTUViewComponent < TuningModel >
{
public:
    RTUADFPageView(TuningModel& model) :
        RTUViewComponent<TuningModel>(model)
    {}
    
    void draw(PPL::GraphicsContext& gc) override;
};

#endif // RTUADFPAGEVIEW_H
