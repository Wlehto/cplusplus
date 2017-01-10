#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <boost/math/special_functions/hypot.hpp>

class Triangle
{
private:
    //[x, y, z]
    // x = axis towards depth
    // y = axis towards right
    // z = axis towards up

    std::vector<double> p1;
    std::vector<double> p2;
    std::vector<double> p3;
public:
    Triangle()
    {
        p1.push_back(0);
        p1.push_back(0);
        p1.push_back(0);

        p2.push_back(0);
        p2.push_back(10);
        p2.push_back(0);

        p3.push_back(10);
        p3.push_back(0);
        p3.push_back(0);

    };

    void reportPoints()
    {
        std::cout << "P1: X" << p1[0] << ", Y" << p1[1] << ", Z" << p1[2] << std::endl;
        std::cout << "P2: X" << p2[0] << ", Y" << p2[1] << ", Z" << p2[2] << std::endl;
        std::cout << "P3: X" << p3[0] << ", Y" << p3[1] << ", Z" << p3[2] << std::endl;
    };

    // A = ½ x base x height
    // base = between p1-p2
    // height = between p1-p3
    void reportArea()
    {
        double baseDistance =  hypot(hypot(p1[0] - p2[0], p1[1] - p2[1]), p1[2] - p2[2]);
        double heightDistance = hypot(hypot(p1[0] - p3[0], p1[1] - p3[1]), p1[2] - p3[2]);
        double area = 0.5 * baseDistance * heightDistance;

        std::cout << area << std::endl;
    };
};

int _tmain(int argc, _TCHAR* argv[])
{
    Triangle objTriangle;

    objTriangle.reportPoints();
    objTriangle.reportArea();

    system("pause");
	return 0;
}
