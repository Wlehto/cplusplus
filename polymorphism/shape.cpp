//---------------------------------------------------------------------------

#pragma hdrstop

#include "shape.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Polygon::set_values(int a, int b)
{
    this->width = a;
    this->height = b;
}

int Rectangle::area()
{
    return width*height;
}

int Triangle::area()
{
    return width*height/2;
}

