#pragma once 
#include"./identity.h"
#include"./computerRoom.h"
#include<vector>

class manager : public identity{
    public:
    

    manager();
    manager(string name, string password);

    virtual void menu();
    void addPerson();
    void showPerson();
    void showComputer();
    void cleanFile();
    void initVecStudent();
    void initVecTeacher();
    void initComputerRoom();
    bool checkRepeat(int, int);
    static void printSingleStudent(student&);
    static void printSingleTeacher(teacher&);
    static void printSingleComputer(computerRoom&);

    private:
    vector<student> stu;
    vector<teacher> tea;
    vector<computerRoom> comRoom;

};