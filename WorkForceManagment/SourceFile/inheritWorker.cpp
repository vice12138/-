#pragma once
#include"../HeadFile/inheritWorker.h"

Employee::Employee(){
    this->workerID=-1;
    this->name="dummyname";
    this->DeptID=-1;
    this->next=nullptr;
    this->pre=nullptr;
}
Employee::Employee(int id,std::string name,int deptid){
    this->workerID=id;
    this->name=name;
    this->DeptID=deptid;
    this->next=nullptr;
    this->pre=nullptr;
}
void Employee::showInfo(){
    std:: cout<<"workerID:"<<this->workerID
              <<"\tname:"<<this->name
              <<"\tdepartID:"<<this->getDeptname()
              <<"\tduty:"<<"the Employee work"
              <<std::endl;
};

std::string Employee::getDeptname(){
    return std::string("employee");
};

Manager::Manager(){
    this->workerID=-1;
    this->name="dummyname";
    this->DeptID=-1;
    this->next=nullptr;
    this->pre=nullptr;
}
Manager::Manager(int id,std::string name,int deptid){
    this->workerID=id;
    this->name=name;
    this->DeptID=deptid;
    this->next=nullptr;
    this->pre=nullptr;
}
void Manager::showInfo(){
    std:: cout<<"workerID:"<<this->workerID
              <<"\tname:"<<this->name
              <<"\tdepartID:"<<this->getDeptname()
              <<"\tduty:"<<"the manager work"
              <<std::endl;

}
std::string Manager::getDeptname(){
    return std::string("manager");
}

Boss::Boss(){
    this->workerID=-1;
    this->name="dummyname";
    this->DeptID=-1;
    this->next=nullptr;
    this->pre=nullptr;
}
Boss::Boss(int id,std::string name,int deptid){
    this->workerID=id;
    this->name=name;
    this->DeptID=deptid;
    this->next=nullptr;
    this->pre=nullptr;
}
void Boss::showInfo(){
    std:: cout<<"workerID:"<<this->workerID
              <<"\tname:"<<this->name
              <<"\tdepartID:"<<this->getDeptname()
              <<"\tduty:"<<"the boss work"
              <<std::endl;

}
std::string Boss::getDeptname(){
    return std::string("boss");
}


