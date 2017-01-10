//---------------------------------------------------------------------------
#ifndef ClassPlayerH
#define ClassPlayerH
#include <vector>
//---------------------------------------------------------------------------
#endif

class cPlayer
{
    friend class cCollectData;

    private:
        int widthLimit;
        int heightLimit;
        std::vector<int> position;  //[0]=vertical [1]=horizontal
    public:
        cPlayer(int w, int h) : widthLimit(w), heightLimit(h)
        {
            position.push_back(1);
            position.push_back(1);
        };

        void setPosition();
        std::vector<int> returnPos();
};
