#pragma once
#include<unordered_map>
#include<fstream>
#include"./globalFile.h"
using namespace std;


class processOrderFile{
    public:
    
    processOrderFile();
    void updateOrderFile();
    void printSingleOrder(int);
    int file_size;
    unordered_map<int, unordered_map<string, string>> map;
};