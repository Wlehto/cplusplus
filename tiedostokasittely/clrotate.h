//---------------------------------------------------------------------------

#ifndef clrotateH
#define clrotateH
//---------------------------------------------------------------------------
#endif

#include <string>

class RotateFile
{
private:
    std::string archivePath;

    std::string FormFileName(const std::string&, const std::string& date);
    bool IfFileExists(const std::string&);
public:
    void DoRotate(std::ofstream*, const std::string&, const std::string& date);

    RotateFile(const std::string &_archivePath);
};
