#ifndef FREQUENCY_H
#define FREQUENCY_H
#include <cstdint>
#include <string>

/**
 * @brief The Frequency class stores a radio frequency
 * and allows its megahertz and kilohertz components to be accessed.
 */
class Frequency
{
public:
    
    /**
     * @brief Default constructor.
     * 
     * The frequency will be set to zero.
     */
    constexpr Frequency() :
        hertz_(0)
    {
    }
    
    constexpr Frequency(uint32_t hertz) :
        hertz_(hertz)
    {
    }
    
    constexpr Frequency(float megahertz);
    
    /**
     * @brief Parses a string representation of a number of megahertz
     * @param megahertz
     */
    Frequency(std::string megahertz);
    
    // Accessors
    
    /**
     * @brief Returns this frequency in hertz
     */
    uint32_t hertz() const;
    
    /**
     * @brief Returns this frequency in tens of hertz
     */
    uint32_t ten_hertz() const;
    
    /**
     * @return This frequency in megahertz
     */
    float megahertz() const;
    /**
     * @return This frequency in kilohertz
     */
    float kilohertz() const;
    
    /**
     * @brief Prints this frequency to an ostream
     * @param stream
     * @param freq
     * @return 
     */
    friend std::ostream& operator << (std::ostream& stream, const Frequency& freq);
    
    /**
     * @brief Converts this frequency into a string
     * representing this frequency in megahertz, with three digits
     * before the decimal place and two digits after the decimal place.
     * @return 
     */
    std::string toMhzString();
    
    // Operators
    
    /**
     * @brief Adds two frequencies
     * @param other
     * @return 
     */
    Frequency operator + (const Frequency& other) const;
    /**
     * @brief Subtracts two frequencies
     * @param other
     * @return 
     */
    Frequency operator - (const Frequency& other) const;
    
    void operator += (const Frequency& other);
    
    void operator -= (const Frequency& other);
    
private:
    
    /**
     * @brief The underlying frequency, in hertz.
     */
    uint32_t hertz_;
    
};

/**
  * A literal operator that allows creating Frequency objects from
  * hertz numbers.
  * 
  * Example: Frequency nav1 = 111700000_hz
  */ 
constexpr Frequency operator "" _hz ( unsigned long long hertz ) {
    
    return Frequency(uint32_t(hertz));
}

/**
  * A literal operator that allows creating Frequency objects from
  * numbers of kilohertz.
  * 
  * Example: Frequency nav1 = 111700_khz
  */ 
constexpr Frequency operator "" _khz (unsigned long long kilohertz ) {
    return Frequency(  uint32_t(kilohertz) * 1000  );
}

/**
  * A literal operator that allows creating Frequency objects from
  * numbers of kilohertz.
  * 
  * Example: Frequency nav1 = 111.70_khz
  */ 
constexpr Frequency operator "" _khz (long double kilohertz ) {
    return Frequency(  uint32_t( kilohertz * 1000 )  );
}

/**
  * A literal operator that allows creating Frequency objects from
  * numbers of megahertz.
  * 
  * Example: Frequency nav1 = 111.70_mhz
  */ 
constexpr Frequency operator "" _mhz (long double megahertz ) {
    return Frequency(  uint32_t( megahertz * 1000000 )  );
}

/**
  * A literal operator that allows creating Frequency objects from
  * numbers of megahertz.
  * 
  * Example: Frequency nav1 = 111_mhz
  */ 
constexpr Frequency operator "" _mhz (unsigned long long megahertz ) {
    return Frequency(  uint32_t( megahertz * 1000000 )  );
}

#endif // FREQUENCY_H
