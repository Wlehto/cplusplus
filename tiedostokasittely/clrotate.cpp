//---------------------------------------------------------------------------

#pragma hdrstop

#include "clrotate.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <ctime>
#include <fstream>

#include <boost/lexical_cast.hpp>
#include <boost/filesystem.hpp>

#define MAX_FILE_SIZE 10000000 //10MB in bytes

namespace fs = boost::filesystem;

RotateFile::RotateFile(const std::string &_archivePath)
    : archivePath(_archivePath)
{
}

/// @brief Check if file already exists and return bool
/// @param fileName Given filename
/// @return Result as bool, if file exists
bool RotateFile::IfFileExists(const std::string& fileName)
{
    //open given file name in "r" mode, requires that file exists and
    //if not, fopen returns NULL. Return bool accordinly.
    if(FILE *file = fopen(fileName.c_str(), "r"))
    {
        fclose(file);
        return true;
    }

    return false;
}

/// @brief Returns formed filename. Adds given parameter with timestamp, "log-yyyy-mmm-dd.txt"
/// @param logName name string of the supposed logfile
/// @return formed filename as std::string
std::string RotateFile::FormFileName(const std::string& logName, const std::string& date)
{
    //start marking duplicate files with "-i" from 2
    int i = 2;
    //lenght of the string before file extension (.log)
    int len = logName.length() - 4;

    //string variable to return
    std::string formedFileName;
    // filename-timestamp.log
    formedFileName = logName.substr(0, len) + "-" +  date +  logName.substr(len, logName.length());

    // create path object with entire path
    fs::path fullPath = fs::complete(fs::path(archivePath)) / fs::path(formedFileName);

    // check if filename already exists
    while(IfFileExists(fullPath.string()) == true)
    {
        // the first duplicate just add "-2" before file extension
        // if i>2 then replace with "-i"
        // does not handle i>9 propely!!!
        if(i == 2)
        {
            std::string tmp = "-" + boost::lexical_cast<std::string>(i);
            formedFileName.insert(formedFileName.length()-4, tmp.c_str());
        }
        else
        {
            std::string tmp = "-" + boost::lexical_cast<std::string>(i);
            formedFileName.replace(formedFileName.length()-6, 2, tmp.c_str() );
        }

        // recreate the full path
        fullPath = fs::complete(fs::path(archivePath)) / fs::path(formedFileName);

        i++;
    }

    return fullPath.string();
}

/// @brief Main method to make the rotate
/// @param pLogFile pointer to an open filestream
/// @param fileName given filename as string
/// @param date string
void RotateFile::DoRotate(std::ofstream* pLogFile, const std::string& fileName, const std::string& date)
{
    //create path object dir/filename.log
    fs::path srcPath = fs::complete(fs::path(fileName));

    //check file size
    if(fs::file_size(srcPath) > MAX_FILE_SIZE)
    {
        //form a new file name
        std::string newFileName = FormFileName(srcPath.filename(), date);

        //create path object with the formed path and copy file
        fs::path destPath = fs::path(newFileName);
        fs::copy_file(srcPath, destPath);

        //Restart the filestream, trunc mode to clear previous content
        pLogFile->close();
        pLogFile->open(fileName.c_str(), std::ios_base::trunc | std::ios_base::out);
    }
}
