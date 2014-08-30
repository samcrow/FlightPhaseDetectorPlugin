#ifndef TUNINGMODEL_H
#define TUNINGMODEL_H
#include "../data/frequency.h"

/**
 * @brief The TuningModel class defines an interface
 * for getting and setting setting radio frequencies,
 * and for transponder control
 */
class TuningModel
{
public:
    
    /**
     * @brief Defines the default radios that an RTU is set to tune
     * when it starts up.
     */
    enum class Radios {
        /**
         * Set 1: NAV1, COM1, etc.
         * Normally used for the pilot's RTU
         */
        Set1 = 1,
        /**
         * Set 2: NAV2, COM2, etc.
         * Normally used for the copilot's RTU
         */
        Set2 = 2,
    };

    TuningModel();
    
    /**
     * @return The set of radios that is displayed. This is changed by
     * pressing the 1/2 (side select) key.
     */
    virtual Radios getSelectedRadios() = 0;
    virtual void setSelectedRadios(Radios radios) = 0;
    
    /**
     * @return The nav 1 frequency
     */
    virtual Frequency getNav1() = 0;
    virtual void setNav1(Frequency frequency) = 0;
    virtual Frequency getNav1Standby() = 0;
    virtual void setNav1Standby(Frequency frequency) = 0;
    
    /**
     * @return The nav 2 frequency
     */
    virtual Frequency getNav2() = 0;
    virtual void setNav2(Frequency frequency) = 0;
    virtual Frequency getNav2Standby() = 0;
    virtual void setNav2Standby(Frequency frequency) = 0;
    
    /**
     * @return The com 1 frequency
     */
    virtual Frequency getCom1() = 0;
    virtual void setCom1(Frequency frequency) = 0;
    virtual Frequency getCom1Standby() = 0;
    virtual void setCom1Standby(Frequency frequency) = 0;
    
    /**
     * @return The com 2 frequency
     */
    virtual Frequency getCom2() = 0;
    virtual void setCom2(Frequency frequency) = 0;
    virtual Frequency getCom2Standby() = 0;
    virtual void setCom2Standby(Frequency frequency) = 0;
    
    /**
     * @return The com 3 frequency
     */
    virtual Frequency getCom3() = 0;
    virtual void setCom3(Frequency frequency) = 0;
    virtual Frequency getCom3Standby() = 0;
    virtual void setCom3Standby(Frequency frequency) = 0;
    
    
    virtual Frequency getHF1() = 0;
    virtual void setHF1(Frequency frequency) = 0;
    virtual Frequency getHF1Standby() = 0;
    virtual void setHF1Standby(Frequency frequency) = 0;
    virtual Frequency getHF2() = 0;
    virtual void setHF2(Frequency frequency) = 0;
    virtual Frequency getHF2Standby() = 0;
    virtual void setHF2Standby(Frequency frequency) = 0;
    
    // ADF section
    // Frequencies
    virtual Frequency getADF1() = 0;
    virtual void setADF1(Frequency frequency) = 0;
    virtual Frequency getADF1Standby() = 0;
    virtual void setADF1Standby(Frequency frequency) = 0;
    virtual Frequency getADF2() = 0;
    virtual void setADF2(Frequency frequency) = 0;
    virtual Frequency getADF2Standby() = 0;
    virtual void setADF2Standby(Frequency frequency) = 0;
    
    // Mode
    enum class ADFMode {
        /**
         * Used for range navigation, optimum station tuning,or monitoring commercial broadcast
         */
        ADF = 0,
        /**
         * selects directional antenna which seeks signal source
         */
        ANT = 1,
    };
    virtual ADFMode getADFMode() = 0;
    virtual void setADFMode(ADFMode mode) = 0;
    
    virtual bool isADFInTestMode() = 0;
    virtual void setADFTestMode(bool testMode) = 0;
    
    /**
     * @brief Determines if ADF tone mode is enabled.
     * 
     * Tone mode superimposes an aural signal on unmodulated
     * carrier waves to aid in precise frequency selection.
     * 
     * @return 
     */
    virtual bool isADFToneEnabled() = 0;
    virtual void setADFToneEnabled(bool enabled) = 0;
    
    // Transponder section
    virtual int getTransponderCode() = 0;
    virtual void setTransponderCode(int code) = 0;
    
    /**
     * @brief Starts the process of sending an identification
     * thing from the transponder.
     */
    virtual void transponderIdent() = 0;
    
    enum class TransponderMode {
        Off = 0,
        Standby = 1,
        On = 2,
        Test = 3,
    };
    
    virtual TransponderMode getTransponderMode() = 0;
    virtual void setTransponderMode(TransponderMode newMode) = 0;
    
    // Altitude for transponder display
    /**
     * @return The aircraft altitude displayed in the cockpit, feet
     */
    virtual int getAltitude() = 0;
    
    // If-altitude-is-displayed-on-transponder section
    virtual bool isTransponderAltitudeDisplayed() = 0;
    virtual void setTransponderAltitudeDisplayed(bool displayed) = 0;
    
    // TCAS section
    
    /**
     * @brief Modes for the TCAS display
     */
    enum class TcasMode {
        /**
         * Displays TA/RA above 900 feet AGL,
         * RA only below 900 feet
         */
        Auto = 1,
        /// Standby mode: does not display traffic
        Standby = 2,
        /// Displays traffic advisories only
        TaOnly =3,
    };
    
    virtual TcasMode getTcasMode() = 0;
    virtual void setTcasMode(TcasMode mode) = 0;
    
    /// Modes for the display of altitude on the navigation display
    enum class AltitudeReadoutMode {
        /// Altitudes displayed relative to the current aircraft altitude
        Relative = 1,
        /// Absolute altitudes displayed
        Absolute = 2,
    };
    
    virtual AltitudeReadoutMode getAltitudeReadoutMode() = 0;
    virtual void setAltitudeReadoutMode(AltitudeReadoutMode mode) = 0;
    
    /**
     * @brief
     * @return true if all traffic with transponders should be displayed,
     * false if only threatening traffic should be displayed 
     */
    virtual bool isDisplayingAllTraffic() = 0;
    virtual void setDisplayAllTraffic(bool displayAllTraffic) = 0;
    
    /// Defines the range of altitudes for which non-threat traffic is displayed
    enum class AltitudeRange {
        /// Traffic from -2700 to +9900 feet relative altitude is displayed
        Above = 0,
        /// Traffic from -2700 to +2700 feet relative altitude is displayed
        Normal = 1,
        /// Traffic from -9900 to +2700 feet relative altitude is displayed
        Below = 2,
    };
    
    virtual AltitudeRange getDisplayedAltitudeRange() = 0;
    virtual void setDisplayedAltitudeRange(AltitudeRange range) = 0;
    
    virtual ~TuningModel();
};

#endif // TUNINGMODEL_H
