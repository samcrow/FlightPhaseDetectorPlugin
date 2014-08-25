#include "testgauge.h"
#include <XPLMUtilities.h>
#include <iostream>
#include <pluginpath.h>

TestGauge::TestGauge() :
    PPL::OverlayGauge(300, 300, 220, 220, 300, 300, 200, 200, 0, 0, 0, true, true, true),
    rtuTexture(PPL::PluginPath::prependPluginResourcesPath("rtu.png"))
{
    
}


void TestGauge::draw(int left, int top, int right, int bottom)
{
    glPushMatrix();
    
    setDrawState(false // fog
                 , 0 // numberTexUnits
                 , false // lighting
                 , false // alpha testing
                 , true // alpha blending
                 , false // depth testing
                 , false // depth writing
                 );
    
    // Red triangle
    
    glColor4f(1.0, 0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(left, bottom);
    glVertex2f(right, top);
    glVertex2f(right, bottom);
    glEnd();
    
    // Purple alternate triangle
    glColor4f(1, 0, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(left, bottom);
    glVertex2f(left, top);
    glVertex2f(right, bottom);
    glEnd();
    
    // Image
    rtuTexture.drawTex(left, bottom + rtuTexture.height(), left + rtuTexture.width(), bottom, 1);
    
    glPopMatrix();
}

void TestGauge::handleNonDragClick(int x_rel, int y_rel)
{
    std::cout << "Panel clicked" << std::endl;
}

void TestGauge::handleKeyPress(char key, XPLMKeyFlags flags, char virtual_key)
{
}
