#ifndef TUNINGMODELXPLANE_H
#define TUNINGMODELXPLANE_H
#include "tuningmodel.h"
#include "frequencydatarefpair.h"
#include "adffrequencydatarefpair.h"
#include "frequencyowneddatapair.h"
#include <externalcommand.h>
#include <owneddata.h>

class TuningModelXPlane : public TuningModel
{
public:
    
    /**
     * @brief Constructor
     * @param rtuName The name of this RTU. This is used to
     * give this RTU model a unique environment with its own datarefs.
     * @param defaultRadios The set of radio frequencies that the RTU should be
     * set up to tune by default
     */
    TuningModelXPlane(const std::string& rtuName, Radios defaultRadios);
    
    // TuningModel interface
    
    virtual Radios getSelectedRadios() override;
    virtual void setSelectedRadios(Radios radios) override;

    virtual Frequency getNav1() override;
    virtual void setNav1(Frequency frequency) override;
    virtual Frequency getNav2() override;
    virtual void setNav2(Frequency frequency) override;
    virtual Frequency getCom1() override;
    virtual void setCom1(Frequency frequency) override;
    virtual Frequency getCom2() override;
    virtual void setCom2(Frequency frequency) override;
    virtual Frequency getCom3() override;
    virtual void setCom3(Frequency frequency) override;
    virtual Frequency getHF1() override;
    virtual void setHF1(Frequency frequency) override;
    virtual Frequency getHF2() override;
    virtual void setHF2(Frequency frequency) override;
    virtual Frequency getADF1() override;
    virtual void setADF1(Frequency frequency) override;
    virtual Frequency getADF2() override;
    virtual void setADF2(Frequency frequency) override;
    
    virtual Frequency getNav1Standby() override;
    virtual void setNav1Standby(Frequency frequency) override;
    virtual Frequency getNav2Standby() override;
    virtual void setNav2Standby(Frequency frequency) override;
    virtual Frequency getCom1Standby() override;
    virtual void setCom1Standby(Frequency frequency) override;
    virtual Frequency getCom2Standby() override;
    virtual void setCom2Standby(Frequency frequency) override;
    virtual Frequency getCom3Standby() override;
    virtual void setCom3Standby(Frequency frequency) override;
    virtual Frequency getHF1Standby() override;
    virtual void setHF1Standby(Frequency frequency) override;
    virtual Frequency getHF2Standby() override;
    virtual void setHF2Standby(Frequency frequency) override;
    virtual Frequency getADF1Standby() override;
    virtual void setADF1Standby(Frequency frequency) override;
    virtual Frequency getADF2Standby() override;
    virtual void setADF2Standby(Frequency frequency) override;
    
    // ADF section
    virtual ADFMode getADFMode() override;
    virtual void setADFMode(ADFMode mode) override;
    virtual bool isADFInTestMode() override;
    virtual void setADFTestMode(bool testMode) override;
    virtual bool isADFToneEnabled() override;
    virtual void setADFToneEnabled(bool enabled) override;
    
    // Transponder section
    virtual int getTransponderCode() override;
    virtual void setTransponderCode(int code) override;
    
    virtual void transponderIdent() override;
    
    virtual TransponderMode getTransponderMode() override;
    virtual void setTransponderMode(TransponderMode newMode) override;
    
    virtual int getAltitude() override;
    
    // If-altitude-is-displayed-on-transponder section
    virtual bool isTransponderAltitudeDisplayed() override;
    virtual void setTransponderAltitudeDisplayed(bool displayed) override;
    
    // TCAS section
    virtual TcasMode getTcasMode() override;
    virtual void setTcasMode(TcasMode mode) override;
    virtual AltitudeReadoutMode getAltitudeReadoutMode() override;
    virtual void setAltitudeReadoutMode(AltitudeReadoutMode mode) override;
    virtual bool isDisplayingAllTraffic() override;
    virtual void setDisplayAllTraffic(bool displayAllTraffic) override;
    virtual AltitudeRange getDisplayedAltitudeRange() override;
    virtual void setDisplayedAltitudeRange(AltitudeRange range) override;
    
    virtual ~TuningModelXPlane();
    
private:
    
    
    Frequency hf1, hf1Standby;
    
    Frequency hf2, hf2Standby;
    
    // Dataref accessors
    
    FrequencyDataRefPair nav1;
    FrequencyDataRefPair nav2;
    
    FrequencyDataRefPair com1;
    FrequencyDataRefPair com2;
    FrequencyOwnedDataPair com3;
    
    ADFFrequencyDataRefPair adf1;
    ADFFrequencyDataRefPair adf2;
    
    // Transponder datarefs
    PPL::DataRef<int> transponderCode;
    PPL::DataRef<int> transponderMode;
    
    PPL::ExternalCommand ident;
   
    PPL::DataRef<float> altitude;
    
    /**
     * Dataref: If altitude is displayed on
     * the RTU ATC page, 0 (false) or 1 (true)
     */
    PPL::OwnedData<int> altitudeDisplayed;
    
    /**
     * Dataref: Mode of the ADF receiver.
     * 0 = ADF mode
     * 1 = ANT mode
     * 
     * See TuningModel::ADFMode documentation
     * for more details
     */
    PPL::OwnedData<int> adfMode;
    /**
     * Dataref: If the ADF receiver is in
     * test mode, boolean
     */
    PPL::OwnedData<int> adfInTestMode;
    /**
     * Dataref: If the ADF tone is enabled, boolean
     */
    PPL::OwnedData<int> adfToneEnabled;
    
    PPL::OwnedData<int> selectedRadios;
    
    PPL::OwnedData<int> tcasMode;
    
    PPL::OwnedData<int> tcasAltitudeReadoutMode;
    
    PPL::OwnedData<int> tcasDisplayingAllTraffic;
    
    PPL::OwnedData<int> tcasDisplayedAltitudeRange;
    
};

#endif // TUNINGMODELXPLANE_H
