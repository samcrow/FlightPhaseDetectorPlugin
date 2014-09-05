#ifndef EGPWSPLUGIN_H
#define EGPWSPLUGIN_H
#include "plugin_interface/plugin.h"
#include "mvc/models/airdatamodel.h"
#include "fsm/fsmdefs.h"

namespace FlightPhaseDetector {

class FlightPhaseDetectorPlugin : public Plugin
{
public:
    FlightPhaseDetectorPlugin();
    
    virtual void onStop() override;
    virtual void onDisable() override;
    virtual int onEnable() override;
    
private:
    
    std::unique_ptr<AirDataModel> airDataModel;
    std::unique_ptr<FSM::StateMachine> stateMachine;
};

}
#endif // EGPWSPLUGIN_H
