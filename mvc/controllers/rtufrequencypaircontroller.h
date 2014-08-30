#ifndef RTUFREQUENCYPAIRCONTROLLER_H
#define RTUFREQUENCYPAIRCONTROLLER_H

#include <functional>

/**
 * Manages a frequency pair and its display 
 *
 * For selecting and switching frequencies, each frequency
 * has the following states and transitions:
 * 
 * S0: Frequency not selected, label RECALL displayed
 * Line key pressed -> S1
 * 
 * S1: Frequency selected, box around standby frequency, RECALL displayed
 * Line key pressed -> S3
 * Knob rotated -> S4
 * 
 * S3: Action: Switch active and standby frequencies
 * Immediate -> S1
 * 
 * S4: Frequency selected, box around standby frequency, PRE displayed
 * Line key pressed -> S3
 * 
 */
class RTUFrequencyPairController
{
public:
    
    typedef std::function< void () > callback_type;
    
    /**
     * @brief Constructor
     * @param activeStandbySwitchCallback A callback that, when called,
     * should switch the active and standby frequencies
     */
    RTUFrequencyPairController(callback_type activeStandbySwitchCallback);
    
    /**
     * @brief Sets whether this frequency is the frequency
     * that is selected, or if another frequency on the page is selected
     * @param selected
     */
    void setSelected(bool selected);
    
    /**
     * @brief This method should be called when
     * the line key corresponding to this frequency is pressed
     */
    void lineKeyPressed();
    
    /**
     * @brief This method should be called when a
     * line key corresponding to another frequency is pressed
     */
    void otherLineKeyPressed();
    
    /**
     * @brief This method should be called when
     * the frequency knob is rotated in any way
     */
    void frequencyKnobRotated();
    
    // Accessors
    
    /**
     * @brief Returns true if this frequency pair is selected, otherwise false
     * @return 
     */
    bool isSelected();
    
    /**
     * @brief If the tuning window (the rectangle around the
     * standby frequency) should be displayed
     * @return 
     */
    bool shouldDisplayTuningWindow();
    
    /**
     * @brief If a bidirectional horizontal arrow should be drawn
     * near the standby frequency
     * @return 
     */
    bool shouldDisplayHorizontalArrow();
    
    /**
     * @brief Returns the label to display above the standby frequency
     * @return 
     */
    const std::string& getLabel();
    
private:
    
    bool selected_;
    
    bool presetMode_;
    
    callback_type switchCallback;
    
};

#endif // RTUFREQUENCYPAIRCONTROLLER_H
