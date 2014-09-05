#ifndef AIRDATAMODEL_H
#define AIRDATAMODEL_H

namespace FlightPhaseDetector {

/**
 * @brief An interface for a model that provides data on
 * the aircraft's position and movement
 */
class AirDataModel
{
public:
    
    /**
     * @brief Data sources to use
     */
    enum class Source {
        Pilot,
        Copilot,
    };
    
    virtual float getIndicatedAirspeed() = 0;
    virtual float getTrueAirspeed() = 0;
    virtual float getAltitude() = 0;
    virtual float getOutsideAirTemperatureCelsius() = 0;
    virtual float getVerticalSpeed() = 0;
    
    virtual bool hasGlideslope() = 0;
    virtual float getGlideslopeDeflection() = 0;
    
    virtual float getRollAngle() = 0;
    
    virtual float getRadioAltitude() = 0;
    
    virtual float getAngleOfAttack() = 0;
    
    virtual float getDecisionHeight() = 0;
    
    virtual bool isLandingGearDownRequested() = 0;
    
    enum class FlapHandlePosition {
        Flaps0,
        Flaps20,
        Flaps30,
        Flaps45,
    };
    
    virtual FlapHandlePosition getFlapHandlePosition() = 0;
    
    virtual float getAverageThrottleRatio() = 0;
    virtual float getMaximumThrottleRatio() = 0;
    virtual float getLeftEngineThrottleRatio() = 0;
    virtual float getRightEngineThrottleRatio() = 0;
    
    virtual bool isLeftEngineEnabled() = 0;
    virtual bool isRightEngineEnabled() = 0;
    
    virtual ~AirDataModel() = default;
};

}
#endif // AIRDATAMODEL_H
