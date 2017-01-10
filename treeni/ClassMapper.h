//---------------------------------------------------------------------------
#include <vector>
#ifndef ClassMapperH
#define ClassMapperH
//---------------------------------------------------------------------------
#endif

class cMap
{
    private:
        int height;
        int width;

        std::vector< std::vector<char> > iMap;

        void initMap();
    public:
        cMap(int h, int w) : height(h), width(w)
        {
            initMap();
        };

        std::vector< std::vector<char> > returnMap();

        void debugPrint();
};
