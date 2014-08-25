#ifndef RTUVIEWCOMPONENT_H
#define RTUVIEWCOMPONENT_H

#include <mvc/view/viewcomponent.h>
#include <mvc/view/graphicscontext.h>
#include "rtumetrics.h"

template < class ModelType >
class RTUViewComponent : public PPL::ViewComponent < ModelType >
{
public:
    RTUViewComponent(ModelType& model) :
        PPL::ViewComponent<ModelType>(model)
    {}
    
protected:
    
    /**
     * @brief The metrics that can be used to draw text on the display
     */
    static const RTUMetrics::Metrics metrics;
    /**
     * @brief The blue color used for RTU graphics
     */
    static const PPL::Color blue;
    /**
     * @brief The green color used for RTU graphics
     */
    static const PPL::Color green;
    /**
     * @brief The white color used for RTU graphics
     */
    static const PPL::Color white;
    
};


template < class ModelType >
const RTUMetrics::Metrics RTUViewComponent<ModelType>::metrics = RTUMetrics::getDefaultMetrics();
template < class ModelType >
const PPL::Color RTUViewComponent<ModelType>::blue(0.18, 0.73, 0.9, 1);
template < class ModelType >
const PPL::Color RTUViewComponent<ModelType>::green(0.2, 0.9, 0.2, 1);
template < class ModelType >
const PPL::Color RTUViewComponent<ModelType>::white(0.9, 0.9, 1, 1);

#endif // RTUVIEWCOMPONENT_H
