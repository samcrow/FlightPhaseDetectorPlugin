#include "testplugin.h"

TestPlugin::TestPlugin() :
    Plugin("Test plugin", "org.samcrow.test_plugin", "Test plugin for testing")
{
    debug("Test plugin starting.");
}
