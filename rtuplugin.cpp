#include "rtuplugin.h"
#include <iostream>
#include <log.h>
#include <pluginpath.h>
#include <mvc/data/frequency.h>
#include <plugin_namespace/pluginnamespace.h>

RTUPlugin::RTUPlugin() :
    Plugin("Radio Tuning Unit Plugin", "org.samcrow.rtu", "Simulates a radio tuning unit")
{
    // Configure software components with information specific to this plugin
    PPL::PluginPath::setPluginDirectoryName("RTU");
    PPL::PluginNamespace::setOuterNamespace({ "C604" });
    
    // GLEW
    GLenum iGlewStatus = glewInit();
    if (GLEW_OK == iGlewStatus){
    }
    else{
        throw std::runtime_error("Could not initialize GLEW");
    }
    
    
    // Set up model testing
    model = new TuningModelXPlane();
    controller = new RTUController(*model);
    
    connector = new RTUXPlaneCommandConnector(*controller);
    
    view = new RTUView(*controller);
}


int RTUPlugin::onEnable() {
    
    return 1;
}

void RTUPlugin::onDisable() {
}

void RTUPlugin::onStop() {
    delete view;
    delete connector;
    delete controller;
    delete model;
    
}

RTUPlugin::~RTUPlugin() {
    
}
