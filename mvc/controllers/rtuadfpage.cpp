#include "rtuadfpage.h"
#include <delayedaction.h>

RTUADFPage::RTUADFPage(TuningModel &model) :
    RTUPage("RTU ADF page controller", model),
    view(model)
{
}


void RTUADFPage::leftLine2Pressed() {
    // Toggle mode
    TuningModel::ADFMode mode = model().getADFMode();
    if(mode == TuningModel::ADF) {
        model().setADFMode(TuningModel::ANT);
    }
    else {
        model().setADFMode(TuningModel::ADF);
    }
}

void RTUADFPage::leftLine3Pressed() {
    // Toggle tone mode
    model().setADFToneEnabled(!model().isADFToneEnabled());
}

void RTUADFPage::leftLine4Pressed() {
    // Return softkey
    setPage(Page::Primary);
}

void RTUADFPage::rightLine1Pressed() {
    // Test softkey
    model().setADFTestMode(true);
    // Disable test mode after 3 seconds
    PPL::DelayedAction::schedule(3, [this]() {
        model().setADFTestMode(false);
    });
}

PPL::ViewComponent<TuningModel>* RTUADFPage::viewComponent() {
    return &view;
}
