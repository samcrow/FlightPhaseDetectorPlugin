#include "rtuprimarypageview.h"
#include "../../controllers/rtufrequencypaircontroller.h"


void RTUPrimaryPageView::draw(PPL::GraphicsContext &gc) {
    
    
    const TuningModel::Radios radios = model().getSelectedRadios();
    if(radios != TuningModel::Radios::Set1 && radios != TuningModel::Radios::Set2) {
        throw std::logic_error("An RTU's selected radio was set to an invalid value");
    }
    
    // Title
    gc.setStroke(white);
    const std::string titleText = radios == TuningModel::Radios::Set1 ? "COM1" : "COM2";
    gc.strokeTextCentered(titleText, metrics.col2Center, metrics.line1Label, PPL::GraphicsContext::Monospace, metrics.primaryLabelSize);
    
    // Labels: ACT and PRE/RECALL
    gc.strokeTextCentered("ACT", metrics.col1Center, metrics.line1Label, PPL::GraphicsContext::Monospace, metrics.secondaryLabelSize);
    gc.strokeTextCentered(comController.getLabel(), metrics.col3Center, metrics.line1Label, PPL::GraphicsContext::Monospace, metrics.secondaryLabelSize);
    
    // Active: Green
    gc.setStroke(green);
    const Frequency topActive = radios == TuningModel::Radios::Set1 ? model().getCom1() : model().getCom2();
    gc.strokeTextCentered(frequencyToString(topActive), metrics.col1Center, metrics.line1Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
    // Standby: White
    gc.setStroke(white);
    const Frequency topStandby = radios == TuningModel::Radios::Set1 ? model().getCom1Standby() : model().getCom2Standby();    
    gc.strokeTextCentered(frequencyToString(topStandby), metrics.col3Center, metrics.line1Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize, comController.shouldDisplayTuningWindow());

    
    // Second row title: NAV1/2
    gc.setStroke(white);
    const std::string row2TitleText = radios == TuningModel::Radios::Set1 ? "NAV1" : "NAV2";
    gc.strokeTextCentered(row2TitleText, metrics.col2Center, metrics.line2Label, PPL::GraphicsContext::Monospace, metrics.primaryLabelSize);
    // Labels: ACT and PRE/RECALL
    gc.strokeTextCentered("ACT", metrics.col1Center, metrics.line2Label, PPL::GraphicsContext::Monospace, metrics.secondaryLabelSize);
    gc.strokeTextCentered(navController.getLabel(), metrics.col3Center, metrics.line2Label, PPL::GraphicsContext::Monospace, metrics.secondaryLabelSize);
    // Active: Green
    gc.setStroke(green);
    const Frequency row2Active = radios == TuningModel::Radios::Set1 ? model().getNav1() : model().getNav2();
    gc.strokeTextCentered(frequencyToString(row2Active), metrics.col1Center, metrics.line2Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
    // Standby: White
    gc.setStroke(white);
    const Frequency row2Standby = radios == TuningModel::Radios::Set1 ? model().getNav1Standby() : model().getNav2Standby();    
    gc.strokeTextCentered(frequencyToString(row2Standby), metrics.col3Center, metrics.line2Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize, navController.shouldDisplayTuningWindow());
    
    // Third row, left area: ADF
    const std::string adfTitle = radios == TuningModel::Radios::Set1 ? "ADF1" : "ADF2";
    gc.strokeTextCentered(adfTitle, metrics.col1Center, metrics.line3Label, PPL::GraphicsContext::Monospace, metrics.secondaryLabelSize);
    gc.setStroke(green);
    const Frequency adf = radios == TuningModel::Radios::Set1 ? model().getADF1() : model().getADF2();
    gc.strokeTextCentered(adfFrequencyToString(adf), metrics.col1Center, metrics.line3Center, PPL::GraphicsContext::Monospace, metrics.primaryValueSize);
    
    // Third row, right area: TCAS mode information
    gc.setStroke(white);
    gc.strokeTextCentered("TCAS", metrics.col3Center, metrics.line3Label, PPL::GraphicsContext::Monospace, metrics.primaryLabelSize);
    
    gc.setStroke(blue);
    // Third row, right area, left part: AUTO/STBY/TA ONLY
    gc.strokeTextCentered(tcasModeToString(model().getTcasMode()), metrics.col3Center - 20, metrics.line3Center, PPL::GraphicsContext::Monospace, metrics.secondaryValueSize);
    gc.strokeTextCentered(altitudeReadoutModeToString(model().getAltitudeReadoutMode()), metrics.col3Center + 20, metrics.line3Center, PPL::GraphicsContext::Monospace, metrics.secondaryValueSize);
    
}


std::string RTUPrimaryPageView::tcasModeToString(TuningModel::TcasMode mode) {
    switch(mode) {
    case TuningModel::TcasMode::Auto:
        return "AUTO";
    case TuningModel::TcasMode::TaOnly:
        return "TA";
    case TuningModel::TcasMode::Standby:
        return "STBY";
    default:
        throw std::logic_error("The TCAS mode was set to an invalid value");
    }
}

std::string RTUPrimaryPageView::altitudeReadoutModeToString(TuningModel::AltitudeReadoutMode mode) {
    switch(mode) {
    case TuningModel::AltitudeReadoutMode::Absolute:
        return "ABS";
    case TuningModel::AltitudeReadoutMode::Relative:
        return "REL";
    default:
        throw std::logic_error("The TCAS altitude readout mode was set to an invalid value");
    }
}
