#include"./headfile/mainStructure.h"
#include"./sourcefile/mainStructure.cpp"
#include<iostream>

using namespace std;


int main(){
    mainStructure* ms = new mainStructure();
    ms->structure();
    system("pause");
    return 0;
}