#pragma once
#include"identity.h"
#include"./processOrderFile.h"
#include"../sourcefile/processOrderFile.cpp"

class teacher : public identity{
    public:

    int teacherID;

    teacher();
    teacher(string name, string password, int teacherID);

    virtual void menu();

    void showAllOrder();
    void validOrder();

};