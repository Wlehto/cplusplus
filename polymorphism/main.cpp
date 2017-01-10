#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <shape.h>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
    Rectangle rect;
    Triangle trgl;

    Polygon * ppoly1 = &rect;
    Polygon * ppoly2 = &trgl;

    ppoly1->set_values(4, 5);
    ppoly2->set_values(4,5);

    std::cout << rect.area() << std::endl;
    std::cout << trgl.area() << std::endl;

    system("pause");

	return 0;
}
