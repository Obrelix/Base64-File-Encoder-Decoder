#ifndef IO_H
#define IO_H
#include <string>
#include <cstdlib>
#include <fstream>
#include "windows.h"
#include "Base64.h"
#include <Lmcons.h>
#include <iostream>
#include <streambuf>

    bool ConvertLogMix(std::string name, bool op)
    {
        //std::string decFile = "DEC " + name;
        try
        {
            std::ifstream en(name.c_str());
            if(!en) return false;
            std::string str((std::istreambuf_iterator<char>(en)),
                             std::istreambuf_iterator<char>());
            if(!en) return false;
            en.close();

            std::string data;
            if(op)
            {
                data = DecryptMix(str);
            }
            else
            {
                data = EncryptMix(str);
            }

            std::ofstream file(name.c_str());
            if(!file) return false;
            file << data;
            if(!file)
                return false;
            file.close();
            return true;
        }
        catch(...)
        {
            return false;
        }
    }

    bool ConvertLog(std::string name, bool op)
    {
        //std::string decFile = "DEC " + name;
        try
        {
            std::ifstream en(name.c_str());
            if(!en) return false;
            std::string str((std::istreambuf_iterator<char>(en)),
                             std::istreambuf_iterator<char>());
            if(!en) return false;
            en.close();

            std::string data;
            if(op)
            {
                data = decrypt(str);
            }
            else
            {
                data = encrypt(reinterpret_cast<const unsigned char*>(str.c_str()), str.length());
            }

            std::ofstream file(name.c_str());
            if(!file) return false;
            file << data;
            if(!file)
                return false;
            file.close();
            return true;
        }
        catch(...)
        {
            return false;
        }
    }



#endif // IO_H
