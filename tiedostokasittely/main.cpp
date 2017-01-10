#pragma hdrstop
#pragma argsused

#include <tchar.h>
#include <stdio.h>

#include <fstream>
#include <iostream>
#include <time.h>
#include <clrotate.h>

#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#define ARCHIVE_PATH "/noexists/testing/"

int _tmain(int argc, _TCHAR* argv[])
{
    boost::filesystem::path test(boost::filesystem::current_path<boost::filesystem::path>());
    boost::filesystem::path folder = boost::filesystem::path(ARCHIVE_PATH);
    boost::filesystem::path fullpath = test.string() + folder.string();
    boost::filesystem::path root = test.root_path();
    std::cout << fullpath << std::endl;

            boost::filesystem::create_directories(fullpath);

    system("pause");
    return 0;
}

/*
boost::filesystem::space_info s = boost::filesystem::space(root);
        std::cout << "Cap: " << (s.capacity / (1024 * 1024 * 1024)) << std::endl;
        std::cout << "Free: " << (s.free / (1024 * 1024 * 1024)) << std::endl;
        std::cout << "Avail: " << (s.available / (1024 * 1024 * 1024)) << std::endl;
-----------------------------------------

 /*std::cout << date_only << std::endl;

    boost::filesystem::path full_path(boost::filesystem::current_path<boost::filesystem::path>());
    full_path /= ARCHIVE_PATH;
    std::cout << full_path << std::endl;
    std::cout << boost::filesystem::exists(full_path) << std::endl;

    RotateFile rf("logs/archives"); */

    /*std::cout << full_path.stem() << std::endl;
    std::cout << boost::filesystem::current_path() << std::endl;
    //full_path /= "logs/archive/";
    std::cout << full_path << std::endl;
    std::cout << "-----------" << std::endl;
    std::string fileName = "rutiiniLog.log";
    full_path /= fileName;
    std::cout << full_path << std::endl;
    std::cout << boost::filesystem::exists(full_path) << std::endl;*/

    ////////////////////////////////////////////////////////////////////////
    /*boost::posix_time::ptime utc = boost::posix_time::microsec_clock::local_time();
    std::string date_str = boost::posix_time::to_simple_string(utc);
    std::string date_only = date_str.substr(0, date_str.find(" "));

    std::ofstream activeFile;
    activeFile.open("testi/alterLog.log", std::ofstream::app | std::ios_base::out);

    for(int i = 0; i < 800000; i++)
    {
        activeFile << "ABCDED";
    }

    RotateFile fileRotator("logs/archive");
    fileRotator.DoRotate(&activeFile, "testi/alterLog.log", date_only);

    activeFile.close();*/
