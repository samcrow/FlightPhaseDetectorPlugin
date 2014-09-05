#ifndef GROUND_STATES_H
#define GROUND_STATES_H

// Include only if this is not already being included from fsmdefs.h
#ifndef FSMDEFS_H
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/mpl/list.hpp>
#include "fsmdefs.h"
#include "outer_states.h"
#endif

/**
 * @file ground_states.h Defines states contained in the OnGround state
 */

namespace FlightPhaseDetector {
namespace FSM {
namespace GroundState {
namespace sc = ::boost::statechart;
namespace mpl = ::boost::mpl;


class Shutdown : public sc::simple_state< Shutdown, OuterState::OnGround > {
public:
    typedef sc::transition< Event::ElectronicsTurnedOn, Preflight > reactions;
    
    Shutdown() {
        std::cerr << "Shutdown entering" << std::endl;
    }
};

class Preflight : public sc::simple_state< Preflight, OuterState::OnGround > {
public:
    typedef sc::transition< Event::AnyEngineStartRequested, EngineStartupInProgress > reactions;
    
    Preflight() {
        std::cerr << "Preflight entering" << std::endl;
    }
};

class EngineStartupInProgress : public sc::simple_state< EngineStartupInProgress, OuterState::OnGround > {
public:
    typedef sc::transition< Event::BothEnginesRunning, PreflightTaxi > reactions;
    
    EngineStartupInProgress() {
        std::cerr << "EngineStartupInProgress entering" << std::endl;
    }
};

class PreflightTaxi : public sc::simple_state< PreflightTaxi, OuterState::OnGround > {
public:
    typedef sc::transition< Event::ThrottleHigh, Takeoff > reactions;
    
    PreflightTaxi() {
        std::cerr << "PreflightTaxi entering" << std::endl;
    }
};

class Takeoff : public sc::simple_state< Takeoff, OuterState::OnGround > {
public:
    typedef mpl::list <
    sc::transition< Event::Liftoff, AirState::Climbout >
    > reactions;
    
    Takeoff() {
        std::cerr << "Takeoff entering" << std::endl;
    }
};


//--------------------------------------------


class Landing : public sc::simple_state< Landing, OuterState::OnGround > {
public:
    typedef mpl::list <
    sc::transition< Event::FlapsNotFullyExtended, PostFlightTaxi >,
    sc::transition< Event::GroundSpeedBelow20, PostFlightTaxi >
    > reactions;
    
    Landing() {
        std::cerr << "Landing entering" << std::endl;
    }
};

class PostFlightTaxi : public sc::simple_state< Landing, OuterState::OnGround > {
public:
    typedef mpl::list <
    sc::transition< Event::ThrottleHigh, Takeoff >,
    sc::transition< Event::AnyEngineNotRunning, ArrivedAtGate >
    > reactions;
    
    PostFlightTaxi() {
        std::cerr << "PostFlightTaxi entering" << std::endl;
    }
};

class ArrivedAtGate : public sc::simple_state< ArrivedAtGate, OuterState::OnGround > {
public:
    typedef mpl::list <
    sc::transition< Event::ElectronicsTurnedOff, Shutdown >,
    sc::transition< Event::AnyEngineStartRequested, EngineStartupInProgress >
    > reactions;
    
    ArrivedAtGate() {
        std::cerr << "ArrivedAtGate entering" << std::endl;
    }
};


}
}
}

#endif // GROUND_STATES_H
