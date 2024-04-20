#pragma once
#include"../headfile/student.h"

student :: student(){};

student :: student(string name, string password, int studentID){
    this->name = name;
    this->password  = password;
    this->studentID = studentID;
    this->initComputerRoom();
};
void student :: menu(){
    std::cout << endl;
    std::cout<<"     in student, what you chose   "<<std::endl;
    std::cout<<"     1: applyorder                 "<<std::endl;
    std::cout<<"     2: showMyorder                "<<std::endl;
    std::cout<<"     3: showAllOrder               "<<std::endl;
    std::cout<<"     4: cancelOrder                "<<std::endl;
    std::cout<<"     0: break                      "<<std::endl;
    std::cout<<endl;  
};
void student :: applyOrder(){
    cout << "the day you apply shoule be in 1 -> 5" << endl;
    
    int day = -1, interval = -1, room = -1;
    while(true){
        cout << "please cin >> the day you wish to apply" << endl;
        cin >> day;
        if(!(day >= 1 && day <= 5)){
            cout << " day invalid, do it again " << endl;
            continue;
        }
        break;   
    }
    while(true){
        cout << "please cin >> the interval you wish to apply" << endl;
        cout << "  1 : morning  2 : afternoon" << endl;
        cin >> interval;
        if(interval != 1 && interval != 2){
            cout << " interval invalid, do it again " << endl;
            continue;
        } 
        break;
    }
    while(true){
        cout << "please cin >> the room you wish to apply" << endl;
        this->showComputer();
        cin >> room;
        if(!(room >= 1 && room <= 3)){
            cout << " room invalid, do it again " << endl;
            continue;
        } 
        break;
    }
    cout << "successfully ordered, which is under check" << endl;
    ofstream ofs(ORDER_FILE, ios :: app);
    ofs << "date:" << day << " ";
    ofs << "interval:" << interval << " ";
    ofs << "studentID:" << this->studentID << " ";
    ofs << "name:" << this->name << " ";
    ofs << "room:" << room << " ";
    ofs << "state:" << 1 << endl;
    ofs.close();
    system("pause");
    system("cls");
};
void student :: showMyOrder(){
    processOrderFile *proder = new processOrderFile();
    if(proder->file_size == 0){
        cout << " the order.txt is empty " << endl;
        system("pause");
        return;
    }
    for(int i = 0; i < proder->file_size; ++i){
        if(stoi(proder->map[i]["studentID"]) != this->studentID) continue;
        cout << "name:" << this->name << " date:" << proder->map[i]["date"] << " interval:" << proder->map[i]["interval"] << 
        " room:" << proder->map[i]["room"] << " state:" << proder->map[i]["state"] << endl;
    }
    system("pause");
    return;
};
void student :: showAllOrder(){
    processOrderFile *proder = new processOrderFile();
    if(proder->file_size == 0){
        cout << " the order.txt is empty " << endl;
        system("pause");
        return;
    }
    for(int i = 0; i < proder->file_size; ++i){
        
        cout << "studentID:" << proder->map[i]["studentID"] << " name:" << proder->map[i]["name"] << " date:" << proder->map[i]["date"] << " interval:" << proder->map[i]["interval"] << 
        " room:" << proder->map[i]["room"] << " state:" << proder->map[i]["state"] << endl;
    }
    system("pause");
    return;
};
void student :: cancelOrder(){
    processOrderFile* it = new processOrderFile();
    if(it->file_size == 0){
        cout << "order.txt is empty" << endl;
        system("pause");
        return;
    }
    int idx = 0;
    vector<int> tag;
    for(int i = 0; i < it->file_size; ++i){
        if(stoi(it->map[i]["studentID"]) != this->studentID) continue;
        if(stoi(it->map[i]["state"]) != 1 && stoi(it->map[i]["state"]) != 2) continue;
        tag.push_back(i);
        cout << "idx:" << idx << " ";
        it->printSingleOrder(i);
        idx++;
    }
    while(true){
        cout << "please cin the id you wish to cancel, 100 means stop the cancel process" << endl;
        int choice;
        cin >> choice;
        if(choice == 100) break;
        if(choice < 0 || choice >= idx){
            cout << " your choice is out of range , do it again" << endl;
            continue; 
        } 
        int num = stoi(it->map[tag[choice]]["state"]);
        if(num != 1 && num != 2){
            cout << "your choice is invalid, state shoule be 1 or 2" << endl;
            continue;
        }
        it->map[tag[choice]]["state"] = to_string(0);
    }
    it->updateOrderFile();
    cout << "successfully cancel" << endl;
    return;
};
void student :: initComputerRoom(){
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios :: in);
    if(!ifs.is_open()){
        cout << "wrong , cound not open the computer_file" << endl;
        return;
    }
    this->comRoom.clear();
    computerRoom com;
    while(ifs >> com.id && ifs >> com.capicity){
        this->comRoom.push_back(com);
    }
    cout << " in computer.txt , there are " << this->comRoom.size() << "  computer" << endl;
    ifs.close();
}
void student :: printSingleComputer(computerRoom& cur){

    cout << "computerRoom id : " << cur.id << " room capacity : " << cur.capicity << endl;
}
void student :: showComputer(){
    for_each(this->comRoom.begin(), this->comRoom.end(), printSingleComputer);
};