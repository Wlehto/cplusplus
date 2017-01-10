//---------------------------------------------------------------------------

#ifndef ClassDrawH
#define ClassDrawH
#include <vector>

//---------------------------------------------------------------------------
#endif

class cCollectData
{
    private:
        std::vector<int> playerPos;
        std::vector< std::vector<char> > map;

    public:
        void setPlayerPos(const std::vector<int> & );
        void setMap(const std::vector< std::vector<char> >  & );
        void mergeData(std::vector<int>&);
        void drawData();
};
