#include "tuningmodelxplane.h"
#include <cmath>
#include <plugin_namespace/pluginnamespace.h>

TuningModelXPlane::TuningModelXPlane() :
    nav1("sim/cockpit2/radios/actuators/nav1_frequency_hz", "sim/cockpit2/radios/actuators/nav1_standby_frequency_hz"),
    nav2("sim/cockpit2/radios/actuators/nav2_frequency_hz", "sim/cockpit2/radios/actuators/nav2_standby_frequency_hz"),
    com1("sim/cockpit2/radios/actuators/com1_frequency_hz", "sim/cockpit2/radios/actuators/com1_standby_frequency_hz"),
    com2("sim/cockpit2/radios/actuators/com2_frequency_hz", "sim/cockpit2/radios/actuators/com2_standby_frequency_hz"),
    adf1("sim/cockpit2/radios/actuators/adf1_frequency_hz", "sim/cockpit2/radios/actuators/adf1_standby_frequency_hz"),
    adf2("sim/cockpit2/radios/actuators/adf2_frequency_hz", "sim/cockpit2/radios/actuators/adf2_standby_frequency_hz"),
    transponderCode("sim/cockpit2/radios/actuators/transponder_code", PPL::ReadWrite),
    transponderMode("sim/cockpit2/radios/actuators/transponder_mode", PPL::ReadWrite),
    ident("sim/transponder/transponder_ident"),
    altitude("sim/cockpit2/gauges/indicators/altitude_ft_pilot"),
    
    altitudeDisplayed(PPL::PluginNamespace{"cockpit", "RTU", "transponder", "altitude displayed"}.path(), PPL::ReadWrite, true),
    
    adfMode(PPL::PluginNamespace{"cockpit", "RTU", "ADF", "ADF mode"}.path(), PPL::ReadWrite, true),
    adfInTestMode(PPL::PluginNamespace{"cockpit", "RTU", "ADF", "ADF in test mode"}.path(), PPL::ReadWrite, true),
    adfToneEnabled(PPL::PluginNamespace{"cockpit", "RTU", "ADF", "ADF tone enabled"}.path(), PPL::ReadWrite, true)
{
    // altitude displayed defaults to true
    altitudeDisplayed.setValue(true);
}


Frequency TuningModelXPlane::getNav1()
{
    return nav1.getActive();
}

void TuningModelXPlane::setNav1(Frequency frequency)
{
    nav1.setActive(frequency);
}

Frequency TuningModelXPlane::getNav2()
{
    return nav2.getActive();
}

void TuningModelXPlane::setNav2(Frequency frequency)
{
    nav2.setActive(frequency);
}

Frequency TuningModelXPlane::getCom1()
{
    return com1.getActive();
}

void TuningModelXPlane::setCom1(Frequency frequency)
{
    com1.setActive(frequency);
}

Frequency TuningModelXPlane::getCom2()
{
    return com2.getActive();
}

void TuningModelXPlane::setCom2(Frequency frequency)
{
    com2.setActive(frequency);
}

Frequency TuningModelXPlane::getCom3()
{
    // Not supported in X-Plane.
    return com3;
}

void TuningModelXPlane::setCom3(Frequency frequency)
{
    // Not supported in X-Plane.
    com3 = frequency;
}

Frequency TuningModelXPlane::getHF1()
{
    return hf1;
}

void TuningModelXPlane::setHF1(Frequency frequency)
{
    hf1 = frequency;
}

Frequency TuningModelXPlane::getHF2()
{
    return hf2;
}

void TuningModelXPlane::setHF2(Frequency frequency)
{
    hf2 = frequency;
}

Frequency TuningModelXPlane::getADF1()
{
    return adf1.getActive();
}

void TuningModelXPlane::setADF1(Frequency frequency)
{
    adf1.setActive(frequency);
}

Frequency TuningModelXPlane::getADF2()
{
    return adf2.getActive();
}

void TuningModelXPlane::setADF2(Frequency frequency)
{
    adf2.setActive(frequency);
}

TuningModelXPlane::~TuningModelXPlane() {
    
}


Frequency TuningModelXPlane::getNav1Standby()
{
    return nav1.getStandby();
}

void TuningModelXPlane::setNav1Standby(Frequency frequency)
{
    nav1.setStandby(frequency);
}

Frequency TuningModelXPlane::getNav2Standby()
{
    return nav2.getStandby();
}

void TuningModelXPlane::setNav2Standby(Frequency frequency)
{
    nav2.setStandby(frequency);
}

Frequency TuningModelXPlane::getCom1Standby()
{
    return com1.getStandby();
}

void TuningModelXPlane::setCom1Standby(Frequency frequency)
{
    com1.setStandby(frequency);
}

Frequency TuningModelXPlane::getCom2Standby()
{
    return com2.getStandby();
}

void TuningModelXPlane::setCom2Standby(Frequency frequency)
{
    com2.setStandby(frequency);
}

Frequency TuningModelXPlane::getCom3Standby()
{
    return com3Standby;
}

void TuningModelXPlane::setCom3Standby(Frequency frequency)
{
    com3Standby = frequency;
}

Frequency TuningModelXPlane::getHF1Standby()
{
    return hf1Standby;
}

void TuningModelXPlane::setHF1Standby(Frequency frequency)
{
    hf1Standby = frequency;
}

Frequency TuningModelXPlane::getHF2Standby()
{
    return hf2Standby;
}

void TuningModelXPlane::setHF2Standby(Frequency frequency)
{
    hf2Standby = frequency;
}

Frequency TuningModelXPlane::getADF1Standby()
{
    return adf1.getStandby();
}

void TuningModelXPlane::setADF1Standby(Frequency frequency)
{
    adf1.setStandby(frequency);
}

Frequency TuningModelXPlane::getADF2Standby()
{
    return adf2.getStandby();
}

void TuningModelXPlane::setADF2Standby(Frequency frequency)
{
    adf2.setStandby(frequency);
}

// Transponder section

int TuningModelXPlane::getTransponderCode() {
    return transponderCode;
}

void TuningModelXPlane::setTransponderCode(int code) {
    transponderCode = code;
}

void TuningModelXPlane::transponderIdent() {
    ident.trigger();
}

TuningModel::TransponderMode TuningModelXPlane::getTransponderMode() {
    return static_cast<TransponderMode>( transponderMode[0] );
}

void TuningModelXPlane::setTransponderMode(TuningModel::TransponderMode newMode) {
    transponderMode = static_cast<int>(newMode);
}

int TuningModelXPlane::getAltitude() {
    return std::round(altitude);
}

bool TuningModelXPlane::isTransponderAltitudeDisplayed() {
    return altitudeDisplayed;
}
void TuningModelXPlane::setTransponderAltitudeDisplayed(bool displayed) {
    altitudeDisplayed = displayed;
}


TuningModelXPlane::ADFMode TuningModelXPlane::getADFMode()
{
    return static_cast<ADFMode>(int(adfMode));
}

void TuningModelXPlane::setADFMode(ADFMode mode)
{
    adfMode = static_cast<int>(mode);
}

bool TuningModelXPlane::isADFInTestMode()
{
    return adfInTestMode;
}

void TuningModelXPlane::setADFTestMode(bool testMode)
{
    adfInTestMode = testMode;
}

bool TuningModelXPlane::isADFToneEnabled()
{
    return adfToneEnabled;
}

void TuningModelXPlane::setADFToneEnabled(bool enabled)
{
    adfToneEnabled = enabled;
}
