//
// Created by sveyda on 20.12.2016.
//

#include <iostream>
#include "Plotting.h"


/*
 *   Constructor
 *   -Caption
 *   -Irrlicht device
 *   -RectangleArea
 */
Plotting::Plotting(wchar_t* _caption, irr::IrrlichtDevice* device, irr::core::rect<irr::s32> Rect)
{
    driver = device->getVideoDriver();

    //Corner Points
    L = (irr::u16)Rect.UpperLeftCorner.X;
    T = (irr::u16)Rect.UpperLeftCorner.Y;
    W = (irr::u16)Rect.LowerRightCorner.X;
    H = (irr::u16)Rect.LowerRightCorner.Y;

    // default colors
    white = irr::video::SColor(255, 255,255,255);
    black = irr::video::SColor(255,0,0,0);
    red = irr::video::SColor(255,255,0,0);
    green = irr::video::SColor(255,0,255,0);
    blue = irr::video::SColor(255,0,0,255);
    yellow = irr::video::SColor(255,255,255,0);
    capColor = irr::video::SColor(255, 255,170,120);
    //coloring different
    start = irr::video::SColor(255, 255,170,120);
    end   = irr::video::SColor(255, 85 ,32 ,50 );

    // draw text
    caption = _caption;
    irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
    font = guienv->getFont("Textures/font.bmp");
    guienv->getSkin()->setFont(font);

    // initialize plotting area
    irr::u8 nbVals = (irr::u8)(W - L);
    max = (irr::u8)(H - T-10); // -10 to draw text
    for (irr::u8 x=0; x<nbVals; x++)
        t.push_back(50);//50 ortasi
}


/**
 * White Border for Plot Area
 */
void Plotting::drawBorder()
{
    driver->draw2DLine (position2d<irr::s32>(L,T), position2d<irr::s32>(W,T), white);
    driver->draw2DLine (position2d<irr::s32>(L,T), position2d<irr::s32>(L,H), white);
    driver->draw2DLine (position2d<irr::s32>(L,H), position2d<irr::s32>(W,H), white);
    driver->draw2DLine (position2d<irr::s32>(W,T), position2d<irr::s32>(W,H), white);
}

void Plotting::drawCaption()
{
    font->draw (caption, irr::core::rect<irr::s32>(L+2,T+1,W,H), capColor);
}


/**
 *  Draw White
 */
void Plotting::drawWhite()
{
    drawBorder();
    drawCaption();
    //values
    for (irr::u8 x=1; x<t.size(); x++)
        driver->draw2DLine (position2d<irr::s32>(L+x, H-t[x-1]), position2d<irr::s32>(L+x, H-t[x]),white);
}
/**
 * Draw Black
 */
void Plotting::drawBlack()
{
    drawBorder();
    drawCaption();

    for (irr::u8 x=1; x<t.size(); x++)
        driver->draw2DLine (position2d<irr::s32>(L+x, H-t[x-1]), position2d<irr::s32>(L+x, H-t[x]  ), black );
}

/**
 * Draw Red Solid
 */
void Plotting::drawRed()
{
    drawBorder();
    drawCaption();
    //values
    for (irr::u8 x=1; x<t.size(); x++)
        driver->draw2DLine (position2d<irr::s32>(L+x, H-t[x-1]), position2d<irr::s32>(L+x, H-t[x]  ), red );
}

/**
 * Draw Green Solid
 */
void Plotting::drawGreen()
{
    drawBorder();
    drawCaption();
    //values
    for (irr::u8 x=1; x<t.size(); x++)
        driver->draw2DLine (position2d<irr::s32>(L+x, H-t[x-1]), position2d<irr::s32>(L+x, H-t[x]  ), green );
}

/**
 * Draw Blue Solid
 */
void Plotting::drawBlue()
{
    drawBorder();
    drawCaption();
    //values
    for (irr::u8 x=1; x<t.size(); x++)
        driver->draw2DLine (position2d<irr::s32>(L+x, H-t[x-1]), position2d<irr::s32>(L+x, H-t[x]  ), blue );
}


/**
 * Draw Yellow Solid
 */
void Plotting::drawYellow()
{
    drawBorder();
    drawCaption();
    //values
    for (irr::u8 x=1; x<t.size(); x++)
        driver->draw2DLine (position2d<irr::s32>(L+x, H-t[x-1]), position2d<irr::s32>(L+x, H-t[x]  ), yellow );
}

/**
 * Draw Green With Shading
 */
void Plotting::drawGreenWithShading()
{
    drawBorder();
    drawCaption();
    static irr::u8 nb = (irr::u8)(W - L); // -10 to draw text above

    static irr::f32 Rstep = (start.getRed() - end.getRed()) / nb;


    //values
    for (irr::u8 x=1; x<t.size(); x++)
        driver->draw2DLine (position2d<irr::s32>(L+x, H-t[x-1]), position2d<irr::s32>(L+x, H-t[x]  ), irr::video:: SColor(255,(irr::u8)(x*Rstep), 100, 10) );
}


/*
 *  Adding a value will put it at the end of the list, and erase the first element
 */
void Plotting::addValue(irr::u8 val)
{
    t.push_back(val);
    t.erase(0);
}
/*
 * Y Max Value
 */
irr::u8 Plotting::getMax() {
    return max;
}

/*
 *   Set Caption
 */
void Plotting::setText(wchar_t* text)
{
    caption = text;
}

/*
 * Destructor
 */
Plotting::~Plotting()
{

}



/*==============================================================================
  orange to red

void Plotting::drawOrange()
{
    drawBorder();
   drawCaption();
    static irr::u8 nb = (u8)(W - L - 10); // -10 to draw text above

    //since there are nbVals = W - L values, step is
    static irr::f32 Rstep = (start.getRed()   - end.getRed()  ) / nb; // 170 / 90 = 1,8889
    static irr::f32 Gstep = (start.getGreen() - end.getGreen()) / nb;
    static irr::f32 Bstep = (start.getBlue()  - end.getBlue() ) / nb;



    //values
    for (irr::u8 x=1; x<t.size(); x++)
        driver->draw2DLine (position2d<irr::s32>(L+x, H-t[x-1]),
                            position2d<irr::s32>(L+x, H-t[x]  ),
                            irr::video::SColor (255, 255-(irr::u8)(x*Rstep), (irr::u8)(x*Gstep), (irr::u8)(x*Bstep)) );
}

*/
