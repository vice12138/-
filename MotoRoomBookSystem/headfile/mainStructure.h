#pragma once
#include<iostream>
#include<fstream>
#include"./identity.h"
#include"./globalFile.h"
#include"./student.h"
#include"../sourcefile/student.cpp"
#include"./teacher.h"
#include"../sourcefile/teacher.cpp"
#include"./manager.h"
#include"../sourcefile/manager.cpp"
using namespace std;

class mainStructure{
    public:

    void structure();
    void mainMenu();
    void managerMenu(manager *);
    void studentMenu(student *);
    void teacherMenu(teacher *);
    void logIn(string, int);

};