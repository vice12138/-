#include <iostream>
#include "./headfile/speechmanager.h"
#include "./sourcefile/speechmanager.cpp"
using namespace std;


int main()
{
    
    speechmanager *sm = new speechmanager();
    sm->show();
    
    system("pause");
    return 0;
}