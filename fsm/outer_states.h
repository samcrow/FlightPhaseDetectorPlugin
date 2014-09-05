#ifndef OUTER_STATES_H
#define OUTER_STATES_H

// Include only if this is not already being included from fsmdefs.h
#ifndef FSMDEFS_H
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include "fsmdefs.h"
#endif

/**
 * @file outer_states.h Defines outer states for the state machine
 */

namespace FlightPhaseDetector {
namespace FSM {


namespace OuterState {
namespace sc = ::boost::statechart;

class InAir;
class OnGround : public sc::simple_state< OnGround, StateMachine, GroundState::Shutdown > {
public:
    OnGround() {
        std::cerr << "OnGround entering" << std::endl;
    }
    ~OnGround() {
        std::cerr << "OnGround exiting" << std::endl;
    }
};
class InAir : public sc::simple_state< InAir, StateMachine, AirState::Cruise > {
public:
    
    typedef sc::transition< Event::Touchdown, OnGround > reactions;
    
    InAir() {
        std::cerr << "InAir entering" << std::endl;
    }
    ~InAir() {
        std::cerr << "InAir exiting" << std::endl;
    }
};

}
}
}

#endif // OUTER_STATES_H
