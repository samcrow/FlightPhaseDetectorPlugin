#include <sstream>
#include <XPLMUtilities.h>

#include "flightphasedetectorplugin.h"

/**
  The plugin.
  */
static Plugin * plugin;


PLUGIN_API int XPluginStart(
                        char *		outName,
                        char *		outSig,
                        char *		outDesc)
{
    try {
        //Init the plugin
        plugin = new FlightPhaseDetector::FlightPhaseDetectorPlugin();
        
        //Get the plugin's information
        strcpy(outName, plugin->getName().c_str());
        strcpy(outSig, plugin->getSignature().c_str());
        strcpy(outDesc, plugin->getDescription().c_str());
        
        return 1;
    }
    catch (std::exception& ex) {
        std::stringstream stream;
        stream << "Plugin failed to load: " << ex.what() << '\n';
        XPLMDebugString(stream.str().c_str());
        return 0;
    }
}

PLUGIN_API void	XPluginStop(void)
{
    try {
        plugin->onStop();
        delete plugin;
    }
    catch (std::exception& ex) {
        std::stringstream stream;
        stream << "Plugin failed to stop: " << ex.what() << '\n';
        XPLMDebugString(stream.str().c_str());
    }
}


PLUGIN_API void XPluginDisable(void)
{
    try {
        plugin->onDisable();
    }
    catch (std::exception& ex) {
        std::stringstream stream;
        stream << "Plugin failed to disable: " << ex.what() << '\n';
        XPLMDebugString(stream.str().c_str());
    }
}

PLUGIN_API int XPluginEnable(void)
{
    try {
        plugin->onEnable();
    }
    catch (std::exception& ex) {
        std::stringstream stream;
        stream << "Plugin failed to enable: " << ex.what() << '\n';
        XPLMDebugString(stream.str().c_str());
    }
}

PLUGIN_API void XPluginReceiveMessage(
                    XPLMPluginID	inFromWho,
                    long			inMessage,
                    void *			inParam)
{
    try {
        plugin->onMessageReceived(inFromWho, inMessage, inParam);
    }
    catch (std::exception& ex) {
        std::stringstream stream;
        stream << "Plugin threw exception from onMessageReceived: " << ex.what() << '\n';
        XPLMDebugString(stream.str().c_str());
    }
}

