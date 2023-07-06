#pragma once
#include<iostream>

class worker{

        
    public:
        int workerID;
        std::string name;
        int DeptID;
        worker *next,*pre;
        virtual void showInfo()=0;
        virtual std::string getDeptname()=0;

};