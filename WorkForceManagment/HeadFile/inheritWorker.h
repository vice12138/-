#pragma once
#include<iostream>
#include"worker.h"

class Employee : public worker{

    public:

        Employee();
        Employee(int id,std::string name,int deptid);

        virtual void showInfo();
        virtual std::string getDeptname();

};

class Manager : public worker{

    public:

        Manager();
        Manager(int id,std::string name,int deptid);
        virtual void showInfo();
        virtual std::string getDeptname();
};

class Boss : public worker{

    public:

        Boss();
        Boss(int id,std::string name,int deptid);
        virtual void showInfo();
        virtual std::string getDeptname();
};