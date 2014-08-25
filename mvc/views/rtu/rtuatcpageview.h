#ifndef RTUATCPAGEVIEW_H
#define RTUATCPAGEVIEW_H
#include "../rtuviewcomponent.h"
#include "../../models/tuningmodel.h"


class RTUATCPageView : public RTUViewComponent < TuningModel >
{
public:
    RTUATCPageView(TuningModel& model) :
        RTUViewComponent<TuningModel>(model)
    {
    }
    
    void draw(PPL::GraphicsContext &gc) override;
};

#endif // RTUATCPAGEVIEW_H
