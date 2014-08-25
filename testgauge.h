#ifndef TESTGUAGE_H
#define TESTGUAGE_H

#include <overlaygauge.h>
#include <texture.h>

class TestGauge : public PPL::OverlayGauge
{
public:
    TestGauge();
    
    virtual void draw(int left, int top, int right, int bottom);
    virtual void handleNonDragClick(int x_rel, int y_rel);
    virtual void handleKeyPress(char key, XPLMKeyFlags flags, char virtual_key);
    
private:
    PPL::Texture rtuTexture;
    
};

#endif // TESTGUAGE_H
