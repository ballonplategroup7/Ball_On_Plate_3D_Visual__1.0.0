//
// Created by sveyda on 20.12.2016.
//

#ifndef BALL_ON_PLATE_3D_VISUAL_1_0_0_PLOTTING_H
#define BALL_ON_PLATE_3D_VISUAL_1_0_0_PLOTTING_H

#include "irrlicht.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace gui;


class Plotting
{

public:
    Plotting(wchar_t* _caption, irr::IrrlichtDevice* device, irr::core::rect<irr::s32> rect);
    ~Plotting();

    void setText(wchar_t* text);
    void addValue(irr::u8 val);

    void drawWhite();
    void drawBlack();
    void drawRed();
    void drawGreen();
    void drawBlue();
    void drawYellow();
    void drawGreenWithShading();


    irr::u8 getMax();

private:
    void drawBorder();
    void drawCaption();
    irr::video::IVideoDriver* driver;

    //caption
    wchar_t* caption;
    irr::gui::IGUIFont* font;

    // Ekrandaki Cizilen noktalar
    irr::core::array<irr::u8> t;

    irr::u16 L,T,W,H; //Corners props.
    irr::u8 max; // max Y value

    irr::video::SColor white,black,red,green,blue,yellow;
    irr::video::SColor capColor;

    irr::video::SColor start, end;

};


#endif //BALL_ON_PLATE_3D_VISUAL_1_0_0_PLOTTING_H
