#ifndef RTUPRIMARYPAGEVIEW_H
#define RTUPRIMARYPAGEVIEW_H
#include "../rtuviewcomponent.h"
#include "../../models/tuningmodel.h"

class RTUFrequencyPairController;

class RTUPrimaryPageView : public RTUViewComponent < TuningModel >
{
public:
    RTUPrimaryPageView(TuningModel& model, RTUFrequencyPairController& comController, RTUFrequencyPairController& navController) :
        RTUViewComponent<TuningModel>(model),
        comController(comController),
        navController(navController)
    {}
    
    void draw(PPL::GraphicsContext& gc) override;
    
private:
    
    static std::string tcasModeToString(TuningModel::TcasMode mode);
    
    static std::string altitudeReadoutModeToString(TuningModel::AltitudeReadoutMode mode);
    
    RTUFrequencyPairController& comController;
    RTUFrequencyPairController& navController;
};

#endif // RTUPRIMARYPAGEVIEW_H
