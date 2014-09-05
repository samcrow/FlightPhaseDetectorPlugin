#include "airdatamodelxplane.h"
#include <basics.h>

namespace FlightPhaseDetector {

AirDataModelXPlane::AirDataModelXPlane(AirDataModel::Source source) :
    indicatedAirspeed( source == AirDataModel::Source::Pilot ? "sim/cockpit2/gauges/indicators/airspeed_kts_pilot" : "sim/cockpit2/gauges/indicators/airspeed_kts_copilot"),
    altitude( source == AirDataModel::Source::Pilot ? "sim/cockpit2/gauges/indicators/altitude_ft_pilot" : "sim/cockpit2/gauges/indicators/altitude_ft_copilot"),
    outsideTemperature("sim/cockpit2/temperature/outside_air_temp_degc"),
    verticalSpeed( source == AirDataModel::Source::Pilot ? "sim/cockpit2/gauges/indicators/vvi_fpm_pilot" : "sim/cockpit2/gauges/indicators/vvi_fpm_copilot"),
    rollAngle( source == AirDataModel::Source::Pilot ? "sim/cockpit2/gauges/indicators/roll_AHARS_deg_pilot" : "sim/cockpit2/gauges/indicators/roll_AHARS_deg_copilot"),
    radioAltitude( source == AirDataModel::Source::Pilot ? "sim/cockpit2/gauges/indicators/radio_altimeter_height_ft_pilot" : "sim/cockpit2/gauges/indicators/radio_altimeter_height_ft_copilot"),
    // Couldn't find a cockpit dataref for this
    angleOfAttack("sim/flightmodel/position/alpha"),
    decisionHeight( source == AirDataModel::Source::Pilot ? "sim/cockpit2/gauges/actuators/radio_altimeter_bug_ft_pilot" : "sim/cockpit2/gauges/actuators/radio_altimeter_bug_ft_pilot"),
    landingGearHandle("sim/cockpit2/controls/gear_handle_down"),
    flapHandle("sim/cockpit2/controls/flap_ratio"),
    
    throttles("sim/cockpit2/engine/actuators/throttle_ratio"),
    mixtures("sim/cockpit2/engine/actuators/mixture_ratio")
{
}


float AirDataModelXPlane::getIndicatedAirspeed()
{
    return indicatedAirspeed;
}

float AirDataModelXPlane::getTrueAirspeed()
{
    // TODO
    return 0;
}

float AirDataModelXPlane::getAltitude()
{
    return altitude;
}

float AirDataModelXPlane::getOutsideAirTemperatureCelsius()
{
    return outsideTemperature;
}

float AirDataModelXPlane::getVerticalSpeed()
{
    return verticalSpeed;
}

bool AirDataModelXPlane::hasGlideslope()
{
    // TODO
    return false;
}

float AirDataModelXPlane::getGlideslopeDeflection()
{
    // TODO
    return 0;
}

float AirDataModelXPlane::getRollAngle()
{
    return rollAngle;
}

float AirDataModelXPlane::getRadioAltitude()
{
    return radioAltitude;
}

float AirDataModelXPlane::getAngleOfAttack()
{
    return angleOfAttack;
}

float AirDataModelXPlane::getDecisionHeight()
{
    return decisionHeight;
}

bool AirDataModelXPlane::isLandingGearDownRequested()
{
    return landingGearHandle;
}

AirDataModel::FlapHandlePosition AirDataModelXPlane::getFlapHandlePosition()
{
    float ratio = flapHandle;
    // Convert from a ratio to a 0/20/30/45
    constexpr float ratio0 = 0;
    constexpr float ratio20 = float(20) / 45;
    constexpr float ratio30 = float(30) / 45;
    constexpr float ratio45 = 1;
    // Calculate the averages between the ratios
    constexpr float ratio0_20 = (ratio0 + ratio20) / 2;
    constexpr float ratio20_30 = (ratio20 + ratio30) /2;
    constexpr float ratio30_45 = (ratio30 + ratio45) / 2;
    
    if(ratio < ratio0_20) {
        return FlapHandlePosition::Flaps0;
    }
    else if(ratio < ratio20_30) {
        return FlapHandlePosition::Flaps20;
    }
    else if(ratio < ratio30_45) {
        return FlapHandlePosition::Flaps30;
    }
    else {
        return FlapHandlePosition::Flaps45;
    }
}

float AirDataModelXPlane::getAverageThrottleRatio() {
    return (throttles[0] + throttles[1]) / 2;
}
float AirDataModelXPlane::getMaximumThrottleRatio() {
    return PPL::max(throttles[0], throttles[1]);
}
float AirDataModelXPlane::getLeftEngineThrottleRatio() {
    return throttles[0];
}
float AirDataModelXPlane::getRightEngineThrottleRatio() {
    return throttles[1];
}

bool AirDataModelXPlane::isLeftEngineEnabled() {
    return mixtures[0] > 0.1;
}

bool AirDataModelXPlane::isRightEngineEnabled() {
    return mixtures[1] > 0.1;
}


}
