#pragma once
#include"../headfile/teacher.h"


teacher :: teacher(){};
teacher :: teacher(string name, string password, int teacherID){
    this->name = name;
    this->password = password;
    this->teacherID = teacherID;
};

void teacher :: menu(){
    std::cout << endl;
    std::cout<<"     in teacher, what you chose   "<<std::endl;
    std::cout<<"     1: showAllOrder                "<<std::endl;
    std::cout<<"     2: validOrder               "<<std::endl;
    std::cout<<"     0: break                      "<<std::endl;
    std::cout<<endl;
};
void teacher :: showAllOrder(){
    processOrderFile *proder = new processOrderFile();
    if(proder->file_size == 0){
        cout << " the order.txt is empty " << endl;
        system("pause");
        return;
    }
    cout << "state = 1 : wait for valid, = 2 : success, = 3 : failed, = 0 : cancel" << endl;
    for(int i = 0; i < proder->file_size; ++i){
        
        cout << "studentID:" << proder->map[i]["studentID"] << " name:" << proder->map[i]["name"] << " date:" << proder->map[i]["date"] << " interval:" << proder->map[i]["interval"] << 
        " room:" << proder->map[i]["room"] << " state:" << proder->map[i]["state"] << endl;
    }
    system("pause");
    return;
};
void teacher :: validOrder(){
    processOrderFile* it = new processOrderFile();
    if(it->file_size == 0){
        cout << "order.txt is empty" << endl;
        system("pause");
        return;
    }
    int idx = 0;
    vector<int> tag;
    for(int i = 0; i < it->file_size; ++i){
        int num = stoi(it->map[i]["state"]);
        if(num != 1) continue;
        tag.push_back(i);
        cout << "idx:" << idx << " ";
        it->printSingleOrder(i);
        idx++;
    }
    while(true){
        cout << "please cin the id you wish to valid, 100 means stop the valid process" << endl;
        int choice;
        cin >> choice;
        if(choice == 100) break;
        if(choice < 0 || choice >= idx){
            cout << " your choice is out of range , do it again" << endl;
            continue; 
        } 
        cout << "please cin the valid choice , 2 mean success, 3 mean failed" << endl;
        int res;
        cin >> res;
        it->map[tag[choice]]["state"] = to_string(res);
    }
    it->updateOrderFile();
    cout << "successfully cancel" << endl;
    return;
};
