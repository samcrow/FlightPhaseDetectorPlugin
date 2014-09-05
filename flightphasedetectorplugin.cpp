#include "flightphasedetectorplugin.h"
#include "mvc/models/airdatamodelxplane.h"
#include <plugin_namespace/pluginnamespace.h>
#include <pluginpath.h>

namespace FlightPhaseDetector {

FlightPhaseDetectorPlugin::FlightPhaseDetectorPlugin() :
    Plugin("Flight phase detector", "org.samcrow.c604.components.flightphasedetector", "Determines the aircraft's phase of flight")
{
    PPL::PluginPath::setPluginDirectoryName("FlightPhaseDetector");
    PPL::PluginNamespace::setOuterNamespace({"Flight Phase Detector"});
    

    
    airDataModel.reset(new AirDataModelXPlane(AirDataModel::Source::Pilot));
    stateMachine.reset(new FSM::StateMachine());
    stateMachine->initiate();
    stateMachine->process_event( FSM::Event::Liftoff() );
    stateMachine->process_event( FSM::Event::Touchdown() );
    stateMachine->process_event( FSM::Event::Liftoff() );
    stateMachine->process_event( FSM::Event::Touchdown() );
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
    airDataModel.reset();
    stateMachine.reset();
}


}
