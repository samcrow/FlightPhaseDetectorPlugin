#include "frequency.h"
#include <boost/lexical_cast.hpp>
#include <stdexcept>
#include <sstream>
#include <iomanip>


Frequency::Frequency(std::string megahertz) :
    hertz_( boost::lexical_cast<float>(megahertz) * 1000000 )
{  
}

uint32_t Frequency::hertz() const {
    return hertz_;
}

uint32_t Frequency::ten_hertz() const {
    return hertz_ / 10;
}

float Frequency::megahertz() const {
    return float(hertz_) / 1000000;
}

float Frequency::kilohertz() const {
    return float(hertz_) / 1000;
}

std::string Frequency::toMhzString() {
    std::stringstream stream;
    
    int megahertz = hertz_ / 1000000;
    int otherDigits = (hertz_ % 1000000) / 10000;
    
    stream << std::setfill('0') << std::setw(3);
    stream << megahertz;
    stream << '.';
    stream << std::setw(2);
    stream << otherDigits;
    
    
    return stream.str();
}

Frequency Frequency::operator + (const Frequency& other) const {
    return Frequency(this->hertz() + other.hertz());
}

Frequency Frequency::operator - (const Frequency& other) const {
    // Check non-negative result
    if(other.hertz() > this->hertz()) {
        throw std::underflow_error("Frequency: Performing this frequency subtraction would create a negative frequency");
    }
    
    return Frequency(this->hertz() - other.hertz());
}

void Frequency::operator -= (const Frequency& other) {
    // Check non-negative result
    if(other.hertz() > this->hertz()) {
        throw std::underflow_error("Frequency: Performing this frequency subtraction would create a negative frequency");
    }
    
    hertz_ -= other.hertz();
}

void Frequency::operator += (const Frequency& other) {
    hertz_ += other.hertz();
}

std::ostream& operator << (std::ostream& stream, const Frequency& freq) {
    stream << "Frequency[" << freq.megahertz() << " MHz]";
    return stream;
}

