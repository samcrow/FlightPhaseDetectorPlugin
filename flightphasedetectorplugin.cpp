#include "flightphasedetectorplugin.h"
#include "mvc/models/airdatamodelxplane.h"
#include <plugin_namespace/pluginnamespace.h>
#include <pluginpath.h>
#include "fsm/fsmdefs.h"

namespace FlightPhaseDetector {

FlightPhaseDetectorPlugin::FlightPhaseDetectorPlugin() :
    Plugin("Flight phase detector", "org.samcrow.c604.components.flightphasedetector", "Determines the aircraft's phase of flight")
{
    PPL::PluginPath::setPluginDirectoryName("FlightPhaseDetector");
    PPL::PluginNamespace::setOuterNamespace({"Flight Phase Detector"});
    
    FSM::StateMachine stateMachine;
    stateMachine.initiate();
    
    airDataModel = new AirDataModelXPlane(AirDataModel::Source::Pilot);
}

int FlightPhaseDetectorPlugin::onEnable()
{
    
    // Success
    return 1;
}

void FlightPhaseDetectorPlugin::onDisable()
{
}

void FlightPhaseDetectorPlugin::onStop()
{
    delete airDataModel;
}


}
