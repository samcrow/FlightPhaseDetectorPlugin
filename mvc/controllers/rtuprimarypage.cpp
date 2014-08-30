#include "rtuprimarypage.h"

RTUPrimaryPage::RTUPrimaryPage(TuningModel& model) :
    RTUPage("RTU Main Page Controller", model),
    comController(std::bind(&RTUPrimaryPage::swapCom, this)),
    navController(std::bind(&RTUPrimaryPage::swapNav, this)),
    view(model, comController, navController)
{
    // Set COM as selected initially
    comController.setSelected(true);
}


void RTUPrimaryPage::leftLine1Pressed()
{
    // Move to COM page
    setPage(Page::Com);
}

void RTUPrimaryPage::leftLine2Pressed()
{
    setPage(Page::Nav);
}

void RTUPrimaryPage::leftLine3Pressed()
{
    setPage(Page::ADF);
}

void RTUPrimaryPage::leftLine4Pressed()
{
    setPage(Page::Secondary);
}

void RTUPrimaryPage::rightLine1Pressed()
{
    comController.lineKeyPressed();
    navController.otherLineKeyPressed();
}

void RTUPrimaryPage::rightLine2Pressed()
{
    comController.otherLineKeyPressed();
    navController.lineKeyPressed();
}

void RTUPrimaryPage::rightLine3Pressed()
{
    setPage(Page::TCAS);
}

void RTUPrimaryPage::rightLine4Pressed()
{
    setPage(Page::ATC);
}

void RTUPrimaryPage::outerKnobClockwise()
{
    comController.frequencyKnobRotated();
    navController.frequencyKnobRotated();
    
    incrementStandbyFrequency(1_mhz);
}

void RTUPrimaryPage::outerKnobCounterclockwise()
{
    comController.frequencyKnobRotated();
    navController.frequencyKnobRotated();
    
    incrementStandbyFrequency(-1_mhz);
}

void RTUPrimaryPage::innerKnobClockwise()
{
    comController.frequencyKnobRotated();
    navController.frequencyKnobRotated();
    incrementStandbyFrequency(50_khz);
}

void RTUPrimaryPage::innerKnobCounterclockwise()
{
    comController.frequencyKnobRotated();
    navController.frequencyKnobRotated();
    incrementStandbyFrequency(-50_khz);
}

void RTUPrimaryPage::swapCom() {
    switch(model().getSelectedRadios()) {
    case TuningModel::Radios::Set1: {
        Frequency temp = model().getCom1();
        model().setCom1(model().getCom1Standby());
        model().setCom1Standby(temp);
        break;
    }
    case TuningModel::Radios::Set2: {
        Frequency temp = model().getCom2();
        model().setCom2(model().getCom2Standby());
        model().setCom2Standby(temp);
        break;
    }
    default:
        throw std::logic_error("An RTU's selected radio was set to an invalid state");
    }
}

void RTUPrimaryPage::swapNav() {
    switch(model().getSelectedRadios()) {
    case TuningModel::Radios::Set1: {
        Frequency oldActive = model().getNav1();
        model().setNav1(model().getNav1Standby());
        model().setNav1Standby(oldActive);
        break;
    }
    case TuningModel::Radios::Set2: {
        Frequency temp = model().getNav2();
        model().setNav2(model().getNav2Standby());
        model().setNav2Standby(temp);
        break;
    }
    default:
        throw std::logic_error("An RTU's selected radio was set to an invalid state");
    }
}

void RTUPrimaryPage::incrementStandbyFrequency(Frequency increment) {
    switch(model().getSelectedRadios()) {
    case TuningModel::Radios::Set1:
        if(comController.isSelected()) {
            model().setCom1Standby(model().getCom1Standby() + increment);
        }
        else if(navController.isSelected()) {
            model().setNav1Standby(model().getNav1Standby() + increment);
        }
        break;
    case TuningModel::Radios::Set2:
        if(comController.isSelected()) {
            model().setCom2Standby(model().getCom2Standby() + increment);
        }
        else if(navController.isSelected()) {
            model().setNav2Standby(model().getNav2Standby() + increment);
        }
        break;
    }
}

PPL::ViewComponent<TuningModel>* RTUPrimaryPage::viewComponent()
{
    return &view;
}
