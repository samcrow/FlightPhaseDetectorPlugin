#ifndef FSMDEFS_H
#define FSMDEFS_H
#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/mpl/list.hpp>
#include <iostream>

#include "events.h"

/**
 * @file fsmdefs.h
 * 
 * Provides definitions used for the flight phase detector finite state machine
 */

#include "ground_states_fwd.h"
#include "air_states_fwd.h"

namespace FlightPhaseDetector {
namespace FSM {
namespace sc = ::boost::statechart;

// Forward-declare initial state
namespace OuterState {
class OnGround;
}

class StateMachine : public sc::state_machine< StateMachine, OuterState::OnGround > {};

}
}

#include "outer_states.h"
#include "ground_states.h"
#include "air_states.h"

#endif // FSMDEFS_H
