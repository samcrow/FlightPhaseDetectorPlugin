#include "rtuprimarypage.h"

RTUPrimaryPage::RTUPrimaryPage(TuningModel& model) :
    RTUPage("RTU Main Page Controller", model),
    view(model)
{
}


void RTUPrimaryPage::leftLine1Pressed()
{
}

void RTUPrimaryPage::leftLine2Pressed()
{
}

void RTUPrimaryPage::leftLine3Pressed()
{
}

void RTUPrimaryPage::leftLine4Pressed()
{
}

void RTUPrimaryPage::rightLine1Pressed()
{
}

void RTUPrimaryPage::rightLine2Pressed()
{
}

void RTUPrimaryPage::rightLine3Pressed()
{
}

void RTUPrimaryPage::rightLine4Pressed()
{
}

void RTUPrimaryPage::outerKnobClockwise()
{
}

void RTUPrimaryPage::outerKnobCounterclockwise()
{
}

void RTUPrimaryPage::innerKnobClockwise()
{
}

void RTUPrimaryPage::innerKnobCounterclockwise()
{
}


PPL::ViewComponent<TuningModel>* RTUPrimaryPage::viewComponent()
{
    return &view;
}
