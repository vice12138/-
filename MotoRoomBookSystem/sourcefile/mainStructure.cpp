#pragma once
#include"../headfile/mainStructure.h"

void mainStructure::structure(){
    while(true){
        mainMenu();
        cout << "what is your choice ?" << endl;
        int choice;
		cin >> choice;
		switch (choice) {
            case 1://学生登陆
              
                logIn(STUDENT_FILE, 1);
                break;
            case 2://教师登陆
                logIn(TEACHER_FILE, 2);
                break;
            case 3://管理员登陆
                logIn(ADMIN_FILE, 3);
                break;
            case 4://退出
                cout << "you have edit your system " << endl;
                exit(0);
                break;
            default:
                system("cls");
                break;
        }
        system("pause");
        system("cls");
    }
}

void mainStructure::mainMenu() {
    std::cout<<"                                  "<<std::endl;
    std::cout<<"     1: student                   "<<std::endl;
    std::cout<<"     2: teacher                   "<<std::endl;
    std::cout<<"     3: manager                   "<<std::endl;
    std::cout<<"     4: edit                      "<<std::endl;
    std::cout<<"                                  "<<std::endl;
}

void mainStructure::managerMenu(manager *person){
    while(true){
        person->menu();
        int choice = -1;
		cin >> choice;
		switch (choice) {
            case 1://添加账号
                person->addPerson();
                break;
            case 2://查看账号
                person->showPerson();
                // cout << "showPerson" << endl;
                break;
            case 3://查看服务器
                person->showComputer();
                // cout << "showComputer" << endl;
                break;
            case 4://清空缓存
                person->cleanFile();
                cout << "cleanFile " << endl;
                break;
            default:
                // delete person;
                cout << "manager has been deleted" << endl;
                system("pause");
                system("cls");
                return;
        }
        system("pause");
        system("cls");        
    }
}
void mainStructure::studentMenu(student *person){
    while(true){
        person->menu();
        int choice = -1;
		cin >> choice;
		switch (choice) {
            case 1://申请预约
                person->applyOrder();
                break;
            case 2://查看自己的预约
                person->showMyOrder();
               
                break;
            case 3://查看所有预约
                person->showAllOrder();
                break;
            case 4:
                person->cancelOrder();
                break;
            default:
                // delete person;
                cout << "student has been deleted" << endl;
                system("pause");
                
                system("cls");
                return;
        }
        system("pause");
        system("cls");        
    }
}
void mainStructure::teacherMenu(teacher *person){
    while(true){
        person->menu();
        int choice = -1;
		cin >> choice;
		switch (choice) {
            case 1:
                person->showAllOrder();
                break;
            case 2:
                person->validOrder();             
                break;
            default:
                cout << "teacher has been deleted" << endl;
                system("pause");
                system("cls");
                return;
        }
        system("pause");
        system("cls");        
    }
}
void mainStructure::logIn(string filename, int type){
   
    // identity *person = NULL;
    ifstream ifs;
    ifs.open(filename, ios :: in);
    if(!ifs.is_open()){
        cout << "open file failed , file doesn't exist " << endl;
        return;
    }
    string name, password;
    int id;
   
    cout << "need your name" << endl;
    cin >> name;
    cout << "need your password" << endl;
    cin >> password;
   
     if(type == 1){
        cout << "need your studentID " << endl;
        cin >> id;
        //下面是学生登陆验证

        int fid;
        string fname, fpassword;
        while(ifs >> fid && ifs >> fname && ifs >> fpassword){
            if(fid == id && fname == name && fpassword == password){
                cout << "student valid successfully " << endl;
                system("pause");
                system("cls");
                student *person = new student(name, password, id);
                studentMenu(person);
                return;
            }
        }
        ifs.close();
        ifs.clear();
        
    }
    else if(type == 2){
        cout << "need your teacherID " << endl;
        cin >> id;
        //下面是教师登录验证
        int fid;
        string fname, fpassword;
        while(ifs >> fid && ifs >> fname && ifs >> fpassword){
            if(fid == id && fname == name && fpassword == password){
                cout << "teacher valid successfully " << endl;
                teacher* person = new teacher(name, password, id);
                teacherMenu(person);
                system("pause");
                system("cls");
                return;
            }
        }
    }
    else if(type == 3){
        //下面是管理员登陆验证
        string fname, fpassword;
        while(ifs >> fname && ifs >> fpassword){
            if(fname == name && fpassword == password){
                cout << "manager valid successfully " << endl;
                manager *person = new manager(name, password);
                managerMenu(person);
                system("pause");
                system("cls");
                return;
            }
        }
        
    }
    ifs.close();
    ifs.clear();
    cout << "valid identity failed" << endl;
    system("pause");
    system("cls");
    return;
}