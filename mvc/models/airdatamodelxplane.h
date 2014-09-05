#ifndef AIRDATAMODELXPLANE_H
#define AIRDATAMODELXPLANE_H
#include "airdatamodel.h"
#include <dataref.h>

namespace FlightPhaseDetector {

class AirDataModelXPlane : public AirDataModel
{
public:
    
    AirDataModelXPlane(AirDataModel::Source source);
    

    virtual float getIndicatedAirspeed() override;
    virtual float getTrueAirspeed() override;
    virtual float getAltitude() override;
    virtual float getOutsideAirTemperatureCelsius() override;
    virtual float getVerticalSpeed() override;
    virtual bool hasGlideslope() override;
    virtual float getGlideslopeDeflection() override;
    virtual float getRollAngle() override;
    virtual float getRadioAltitude() override;
    virtual float getAngleOfAttack() override;
    virtual float getDecisionHeight() override;
    virtual bool isLandingGearDownRequested() override;
    virtual FlapHandlePosition getFlapHandlePosition() override;
    virtual float getAverageThrottleRatio() override;
    virtual float getMaximumThrottleRatio() override;
    virtual float getLeftEngineThrottleRatio() override;
    virtual float getRightEngineThrottleRatio() override;
    virtual bool isLeftEngineEnabled() override;
    virtual bool isRightEngineEnabled() override;
    
    
private:
    PPL::DataRef<float> indicatedAirspeed;
    PPL::DataRef<float> altitude;
    PPL::DataRef<float> outsideTemperature;
    PPL::DataRef<float> verticalSpeed;
    PPL::DataRef<float> rollAngle;
    PPL::DataRef<float> radioAltitude;
    PPL::DataRef<float> angleOfAttack;
    PPL::DataRef<float> decisionHeight;
    PPL::DataRef<int> landingGearHandle;
    PPL::DataRef<float> flapHandle;
    
    PPL::DataRef<std::vector<float>> throttles;
    PPL::DataRef<std::vector<float>> mixtures;
};


}
#endif // AIRDATAMODELXPLANE_H
