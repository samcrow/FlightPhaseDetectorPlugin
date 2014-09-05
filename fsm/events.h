#ifndef EVENTS_H
#define EVENTS_H
#include <boost/statechart/event.hpp>

namespace FlightPhaseDetector {
namespace FSM {
namespace Event {

namespace sc = ::boost::statechart;


/**
 * @brief An event that happens when the aircraft
 * leaves the ground
 */
class Liftoff : public sc::event< Liftoff > {};
/**
 * @brief An event that happens when the aircraft
 * touches down
 */
class Touchdown : public sc::event< Touchdown > {};

/**
 * @brief Happens when the pilot requests flaps 0
 */
class FlapsRetracted : public sc::event< FlapsRetracted > {};

/**
 * @brief Happens when the pilot requests a flap position greater than 0
 */
class FlapsExtended : public sc::event< FlapsRetracted > {};

/**
 * @brief Happens when the pilot requests 45º flaps
 */
class FlapsFullyExtended : public sc::event< FlapsFullyExtended > {};
/**
 * @brief Happens when the pilot requests less than 45º flaps
 */
class FlapsNotFullyExtended : public sc::event< FlapsNotFullyExtended > {};

class GearExtended : public sc::event< GearExtended > {};
class GearRetracted : public sc::event< GearRetracted > {};

/**
 * @brief Happens when the altitude has been increasing
 * but is no longer increasing
 */
class AltitudeNotIncreasing : public sc::event< AltitudeNotIncreasing > {};

/**
 * @brief Happens when the altitude has been decreasing
 * but is no longer decreasing
 */
class AltitudeNotDecreasing : public sc::event< AltitudeNotDecreasing > {};

/**
 * @brief Happens when the altitude has been steady but is now increasing
 */
class AltitudeIncreasing : public sc::event< AltitudeIncreasing > {};

/**
 * @brief Happens when the altitude has been steady but is now decreasing
 */
class AltitudeDecreasing : public sc::event< AltitudeIncreasing > {};

/**
 * @brief Happens when the radar altitude decreases below 2500 feet
 */
class RadarAltitudeBelow2500 : public sc::event< RadarAltitudeBelow2500 > {};

/**
 * @brief Happens when the radar altitude decreases below 1000 feet
 */
class RadarAltitudeBelow1000 : public sc::event< RadarAltitudeBelow1000 > {};

/**
 * @brief Happens when the radar altitude decreases below 100 feet
 */
class RadarAltitudeBelow100 : public sc::event< RadarAltitudeBelow100 > {};

}
}
}

#endif // EVENTS_H
