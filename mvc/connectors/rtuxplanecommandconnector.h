#ifndef RTUXPLANECOMMANDCONNECTOR_H
#define RTUXPLANECOMMANDCONNECTOR_H
#include <signalcommand.h>

class RTUController;

/**
 * @brief The RTUXPlaneCommandConnector class sets up X-Plane commands
 * to trigger functions of the RTU controller
 */
class RTUXPlaneCommandConnector
{
public:
    RTUXPlaneCommandConnector(RTUController& inController);
    
private:
    
    /**
     * @brief A reference to the controller that is manipulated
     */
    RTUController& controller;
    
    // Commands
    PPL::SignalCommand leftLine1;
    PPL::SignalCommand leftLine2;
    PPL::SignalCommand leftLine3;
    PPL::SignalCommand leftLine4;
    
    PPL::SignalCommand rightLine1;
    PPL::SignalCommand rightLine2;
    PPL::SignalCommand rightLine3;
    PPL::SignalCommand rightLine4;
    
    PPL::SignalCommand ident;
    PPL::SignalCommand dmeHold;
    PPL::SignalCommand leftRight;
    
    PPL::SignalCommand outerKnobClockwise;
    PPL::SignalCommand outerKnobCounterclockwise;
    
    PPL::SignalCommand innerKnobClockwise;
    PPL::SignalCommand innerKnobCounterclockwise;
    
    
    /**
     * @brief Assembles a command name
     * @param commandKey
     * @return 
     */
    static std::string commandName(std::string commandKey);
};

#endif // RTUXPLANECOMMANDCONNECTOR_H
