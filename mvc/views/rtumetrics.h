#ifndef RTUMETRICS_H
#define RTUMETRICS_H

/**
 * @brief The RTUMetrics class calculates locations for
 * text on an RTU display.
 */
class RTUMetrics
{
public:
    
    struct Metrics {
        // Y center positions of the four lines
        float line1Center;
        float line2Center;
        float line3Center;
        float line4Center;
        // Y center positions for labels for the four lines
        float line1Label;
        float line2Label;
        float line3Label;
        float line4Label;
        
        // X center positions for the three columns
        float col1Center;
        float col2Center;
        float col3Center;
        
        // Font sizes, in points
        unsigned int primaryValueSize;
        unsigned int primaryLabelSize;
        unsigned int secondaryValueSize;
        unsigned int secondaryLabelSize;
    };
    
    static Metrics getDefaultMetrics();
    
    static Metrics getMetrics(float screenLeft, float screenRight, float screenBottom, float screenTop);
    
private:
    RTUMetrics() = delete;
};

#endif // RTUMETRICS_H
