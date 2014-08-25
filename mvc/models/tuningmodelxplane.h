#ifndef TUNINGMODELXPLANE_H
#define TUNINGMODELXPLANE_H
#include "tuningmodel.h"
#include "frequencydatarefpair.h"
#include "adffrequencydatarefpair.h"
#include <externalcommand.h>
#include <owneddata.h>

class TuningModelXPlane : public TuningModel
{
public:
    TuningModelXPlane();
    
    // TuningModel interface

    virtual Frequency getNav1();
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
    virtual ADFMode getADFMode();
    virtual void setADFMode(ADFMode mode);
    virtual bool isADFInTestMode();
    virtual void setADFTestMode(bool testMode);
    virtual bool isADFToneEnabled();
    virtual void setADFToneEnabled(bool enabled);
    
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
    
    virtual ~TuningModelXPlane();
    
private:
    
    
    // These frequencies are not used by X-Plane. They are stored here in the model.
    Frequency com3, com3Standby;
    
    Frequency hf1, hf1Standby;
    
    Frequency hf2, hf2Standby;
    
    // Dataref accessors
    
    FrequencyDataRefPair nav1;
    FrequencyDataRefPair nav2;
    
    FrequencyDataRefPair com1;
    FrequencyDataRefPair com2;
    
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
    
};

#endif // TUNINGMODELXPLANE_H
