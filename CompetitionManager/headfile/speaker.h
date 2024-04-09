#pragma once
#include<iostream>

using namespace std;

class speaker{
    public:
    string name;
    double score[2];
    speaker(string name){
        this->name=name;
        this->score[0] = 0;
        this->score[1] = 0;
    }
};