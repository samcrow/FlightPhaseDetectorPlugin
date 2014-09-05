#ifndef FSMDEFS_H
#define FSMDEFS_H
#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <iostream>

#include "events.h"
#include "outer_states.h"

/**
 * @file fsmdefs.h
 * 
 * Provides definitions used for the flight phase detector finite state machine
 */

namespace FlightPhaseDetector {
namespace FSM {

namespace sc = ::boost::statechart;

class StateMachine : public sc::state_machine< StateMachine, OuterState::OnGround > {};

namespace OuterState {

class OnGround : public sc::simple_state< OnGround, StateMachine > {
public:
    OnGround() {
        std::cerr << "OnGround entering" << std::endl;
    }
    ~OnGround() {
        std::cerr << "OnGround exiting" << std::endl;
    }
};
class InAir : public sc::simple_state< OnGround, StateMachine > {
public:
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

#endif // FSMDEFS_H
