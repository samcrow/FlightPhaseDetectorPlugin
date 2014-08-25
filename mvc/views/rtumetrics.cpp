#include "rtumetrics.h"

RTUMetrics::Metrics RTUMetrics::getDefaultMetrics()
{
    return getMetrics(44, 203, 26, 190);
}

RTUMetrics::Metrics RTUMetrics::getMetrics(float screenLeft, float screenRight, float screenBottom, float screenTop)
{
    const float width = screenRight - screenLeft;
    const float height = screenTop - screenBottom;
    
    Metrics metrics;
    // Font sizes
    metrics.primaryValueSize = 11;
    metrics.primaryLabelSize = 10;
    metrics.secondaryValueSize = 8;
    metrics.secondaryLabelSize = 8;
    
    metrics.line1Center = screenBottom + height * 4 / 5;
    metrics.line2Center = -10 + screenBottom + height * 3/5;
    metrics.line3Center = -10 + screenBottom + height * 2/5;
    metrics.line4Center = -10 + screenBottom + height / 5;
    
    const float labelOffset = 4 + 0.5 * (metrics.primaryLabelSize + metrics.primaryValueSize);
    metrics.line1Label = metrics.line1Center + labelOffset;
    metrics.line2Label = metrics.line2Center + labelOffset;
    metrics.line3Label = metrics.line3Center + labelOffset;
    metrics.line4Label = metrics.line4Center + labelOffset;
   
    metrics.col1Center = screenLeft + width * 1/4;
    metrics.col2Center = screenLeft + width * 1/2;
    metrics.col3Center = screenLeft + width * 3/4;
    
    return metrics;
}

