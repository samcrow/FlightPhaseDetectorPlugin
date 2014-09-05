#ifndef EGPWSPLUGIN_H
#define EGPWSPLUGIN_H
#include "plugin_interface/plugin.h"
#include "mvc/models/airdatamodel.h"

namespace FlightPhaseDetector {

class FlightPhaseDetectorPlugin : public Plugin
{
public:
    FlightPhaseDetectorPlugin();
    
    virtual void onStop() override;
    virtual void onDisable() override;
    virtual int onEnable() override;
    
private:
    
    AirDataModel* airDataModel;
    
};

}
#endif // EGPWSPLUGIN_H
