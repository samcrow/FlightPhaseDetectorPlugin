#ifndef AIR_STATES_H
#define AIR_STATES_H

// Include only if this is not already being included from fsmdefs.h
#ifndef FSMDEFS_H
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <boost/mpl/list.hpp>
#include "fsmdefs.h"
#include "outer_states.h"
#endif

namespace FlightPhaseDetector {
namespace FSM {
namespace AirState {
namespace sc = ::boost::statechart;
namespace mpl = ::boost::mpl;

class Climbout : public sc::simple_state< Climbout, OuterState::InAir > {
public:
    typedef mpl::list <
    sc::transition< Event::FlapsRetracted, Climb >,
    sc::transition< Event::Touchdown, GroundState::Takeoff >
    > reactions;
    
    Climbout() {
        std::cerr << "Climbout entering" << std::endl;
    }
};

class Climb : public sc::simple_state< Climb, OuterState::InAir > {
public:
    typedef sc::transition< Event::AltitudeNotIncreasing, Cruise > reactions;
    
    Climb() {
        std::cerr << "Climb entering" << std::endl;
    }
};

class Cruise : public sc::simple_state< Cruise, OuterState::InAir > {
public:
    
    typedef mpl::list <
    sc::transition< Event::AltitudeDecreasing, Descent >,
    sc::transition< Event::AltitudeIncreasing, Climb >
    > reactions;
    
    Cruise() {
        std::cerr << "Cruise entering" << std::endl;
    }
};

class Descent : public sc::simple_state< Descent, OuterState::InAir > {
public:
    typedef mpl::list <
    sc::transition< Event::AltitudeNotDecreasing, Cruise >,
    sc::transition< Event::GearExtended, Approach >,
    sc::transition< Event::FlapsExtended, Approach >,
    sc::transition< Event::RadarAltitudeBelow2500, Approach >
    > reactions;
    
    Descent() {
        std::cerr << "Descent entering" << std::endl;
    }
};

class Approach : public sc::simple_state< Approach, OuterState::InAir > {
public:
    typedef mpl::list <
    sc::transition< Event::AltitudeIncreasing, Climb >,
    sc::transition< Event::FlapsFullyExtended, FinalApproach >,
    sc::transition< Event::RadarAltitudeBelow1000, FinalApproach >
    > reactions;
    
    Approach() {
        std::cerr << "Approach entering" << std::endl;
    }
};

class FinalApproach : public sc::simple_state< FinalApproach, OuterState::InAir > {
public:
    typedef mpl::list <
    sc::transition< Event::RadarAltitudeBelow100, Flare >
    > reactions;
    
    FinalApproach() {
        std::cerr << "FinalApproach entering" << std::endl;
    }
};

class Flare : public sc::simple_state< Flare, OuterState::InAir > {
public:
    typedef mpl::list <
    sc::transition< Event::Touchdown, GroundState::Landing >
    > reactions;
    
    Flare() {
        std::cerr << "Flare entering" << std::endl;
    }
};

}
}
}

#endif // AIR_STATES_H
