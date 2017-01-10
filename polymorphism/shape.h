//---------------------------------------------------------------------------

#ifndef shapeH
#define shapeH
//---------------------------------------------------------------------------
#endif

class Polygon
{
    protected:
        int width, height;
    public:
        void set_values (int, int);
        virtual int area(void) =0;
};

class Rectangle: public Polygon
{
    public:
        int area();
};

class Triangle: public Polygon
{
    public:
        int area();
};
