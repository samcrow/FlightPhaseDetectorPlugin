#ifndef RTUPAGE_H
#define RTUPAGE_H
#include <boost/signals2.hpp>
#include <mvc/controller.h>
#include <mvc/view/drawable.h>
#include "../models/tuningmodel.h"
#include "../views/rtumetrics.h"
#include <mvc/view/viewcomponent.h>

/**
 * @brief The RTUPage class represents a page
 * on the RTU. This class is the controller;
 * each page controller also contains a corresponding view.
 */
class RTUPage : public PPL::Controller < TuningModel >
{
public:
    RTUPage(std::string name, TuningModel& model);
    
    // Line select buttons.
    // Subclasses can override these to be notified
    // when a button is pressed.
    virtual void leftLine1Pressed();
    virtual void leftLine2Pressed();
    virtual void leftLine3Pressed();
    virtual void leftLine4Pressed();
    
    virtual void rightLine1Pressed();
    virtual void rightLine2Pressed();
    virtual void rightLine3Pressed();
    virtual void rightLine4Pressed();
    
    // Knob
    virtual void outerKnobClockwise();
    virtual void outerKnobCounterclockwise();
    
    virtual void innerKnobClockwise();
    virtual void innerKnobCounterclockwise();
    
    /**
     * @brief Returns a view component that can be used
     * to draw the graphics of this page.
     * @return 
     */
    virtual PPL::ViewComponent<TuningModel>* viewComponent() = 0;
    
    /**
     * @brief The Page enum enumerates valid
     * RTU pages and allows pages to tell the RTU to switch
     * to other pages.
     */
    enum class Page {
        Primary,
        Com,
        Nav,
        Secondary,
        Com3,
        ADF,
        ATC,
        TCAS,
        HFPreset,
    };
    
    /**
     * @brief A signal emitted when this page wants
     * the RTU to make a different page active
     */
    boost::signals2::signal< void (Page) > setPage;
    
};

#endif // RTUPAGE_H
