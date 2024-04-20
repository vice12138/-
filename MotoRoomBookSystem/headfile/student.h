#pragma once
#include"./computerRoom.h"
#include"./identity.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include"./processOrderFile.h"
#include"../sourcefile/processOrderFile.cpp"

class student : public identity{
    public:

    int studentID;


    student();
    student(string name, string password, int studentID);

    virtual void menu();

    void applyOrder();
    void showMyOrder();
    void showAllOrder();
    void cancelOrder();

    void initComputerRoom();
    static void printSingleComputer(computerRoom&);
    void showComputer();


    private:
    vector<computerRoom> comRoom;

};