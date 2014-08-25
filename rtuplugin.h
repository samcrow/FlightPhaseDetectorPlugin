#ifndef GRAPHICSPLUGIN_H
#define GRAPHICSPLUGIN_H
#include "plugin_interface/plugin.h"

#include "mvc/controllers/rtucontroller.h"
#include "mvc/models/tuningmodelxplane.h"
#include "mvc/connectors/rtuxplanecommandconnector.h"
#include "mvc/views/rtuview.h"

class RTUPlugin : public Plugin
{
public:
    RTUPlugin();
    
    virtual ~RTUPlugin();
    
    virtual int onEnable();
    
    virtual void onDisable();
    
    virtual void onStop();
    
private:
    
    // MVC test
    RTUController* controller;
    TuningModel* model;
    RTUXPlaneCommandConnector* connector;
    
    RTUView* view;
};

#endif // GRAPHICSPLUGIN_H
