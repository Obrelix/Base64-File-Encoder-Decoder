#include <iostream>
#include "io.h"
#include "base64.h"
#include <stdlib.h>
using namespace std;

int main()
{
    string path;
    bool exit = true;
    string data;
    char choise;

    do
    {
        system("cls");
        cout<< "[1: Encrypt mix]" << "  [2: Decrypt mix]" <<  "\n[3: Encrypt std]"  << "  [4: Decrypt std]" <<"\n[6: EXIT]" <<endl;
        cin >> choise;
        switch(choise)
        {
            case '1':
                cout<< "Type the file name :"<<endl;
                cin >> path;
                if(!ConvertLogMix(path, false))
                {
                    cout<< "File failed to Encrypt"<<endl;
                }
                break;
            case '2':
                cout<< "Type the file name :"<<endl;
                cin >> path;
                if(!ConvertLogMix(path, true))
                {
                    cout<< "File failed to Decrypt"<<endl;
                }
                break;
            case '3':
                cout<< "Type the file name :"<<endl;
                cin >> path;
                if(!ConvertLog(path, false))
                {
                    cout<< "File failed to Encrypt"<<endl;
                }
                break;
            case '4':
                cout<< "Type the file name :"<<endl;
                cin >> path;
                if(!ConvertLog(path, true))
                {
                    cout<< "File failed to Decrypt"<<endl;
                }
                break;
            case '6':
                cout<< "exit "<<endl;
                exit = false;
                break;

            default:
                cout<< "Try Again...";

        }


    }while(exit);

    return 0;
}
