#include"../headfile/manager.h"
#include"../headfile/globalFile.h"
#include<fstream>
#include<algorithm>

manager :: manager(){
    this->name = "default";
    this->password = "1234";
    
};
manager :: manager(string name, string password){
    this->name = name;
    this->password = password;
    this->initVecStudent();
    this->initVecTeacher();
    this->initComputerRoom();
};
void manager :: menu(){
    std::cout << endl;
    std::cout<<"     in manager, what you chose   "<<std::endl;
    std::cout<<"     1: addperson                 "<<std::endl;
    std::cout<<"     2: showperson                "<<std::endl;
    std::cout<<"     3: showcomputer               "<<std::endl;
    std::cout<<"     4: cleanFile                 "<<std::endl;
    std::cout<<"     0: break                     "<<std::endl;
    std::cout<<endl;  
};
void manager :: addPerson(){
    int choice;
    while(true){
        std::cout<<"     what to add ?             "<<std::endl;
        std::cout<<"     1: student                "<<std::endl;
        std::cout<<"     2: teacher                "<<std::endl;
        std::cout<<"     3: break                  "<<std::endl;
        cin >> choice;
        if(choice == 3) return;
        if(choice != 1 && choice != 2){
            cout << "wrong ! please do it again " << endl;
            continue;
        }
        else break;
    }
    string filename;
    if(choice == 1) filename = STUDENT_FILE;
    else filename = TEACHER_FILE;

    ofstream ofs;
    ofs.open(filename, ios :: out | ios :: app);

    while(true){
        int id;
        string name, password;
        cout << "need id" << endl;
        cin >> id;
        cout << "need name" << endl;
        cin >> name;
        cout << "need password" << endl;
        cin >> password;
        if(choice == 1 && checkRepeat(id, choice)){
            cout << "in student.txt , the id already existed , do it again" << endl;
            continue;
        }
        else if(choice == 2 && checkRepeat(id, choice)){
            cout << "in teacher.txt , the id already existed , do it again" << endl;
            continue;
        }
        ofs << id << " " << name << " " << password << " " << endl;
        if(choice == 1) this->initVecStudent();
        else if(choice == 2) this->initVecTeacher();
        break;
    }
    cout << "successfully add one person" << endl;
    ofs.close();

    system("pause");
    system("cls");
};
void manager :: showPerson(){
    int choice = -1;
    while(true){
        cout << "what you want to check ?" << endl;
        cout << "    1. student  " << endl;
        cout << "    2. teacher  " << endl;
        cout << "    3. break    " << endl;
        cout << "please cin your choice" << endl;
        cin >> choice;
        if(choice == 3) break;
        if(choice != 1 && choice != 2){
            cout << "your choice is invalid, do it again" << endl;
            continue;
        }
        if(choice == 1) for_each(this->stu.begin(), this->stu.end(), printSingleStudent);
        else if(choice == 2) for_each(this->tea.begin(), this->tea.end(), printSingleTeacher);
    }
};
void manager :: printSingleStudent(student& cur){    
    cout << "id : " << cur.studentID << " name : " << cur.name << "  password : " << cur.password << endl;
}
void manager :: printSingleTeacher(teacher& cur){
    cout << "id : " << cur.teacherID << " name : " << cur.name << "  password : " << cur.password << endl;
}
void manager :: printSingleComputer(computerRoom& cur){
    cout << "computerRoom id : " << cur.id << " room capacity : " << cur.capicity << endl;
}
void manager :: showComputer(){
    for_each(this->comRoom.begin(), this->comRoom.end(), printSingleComputer);
    system("pause");
};
void manager :: cleanFile(){
    ofstream ofs(ORDER_FILE, ios::trunc);
    ofs.close();
    cout << "file order.txt has been cleaned" << endl;
    return;
};
void manager :: initVecStudent(){
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios :: in);
    if(!ifs.is_open()){
        cout << "wrong , cound not open the student_file" << endl;
        return;
    }
    stu.clear();
    student s;
    while(ifs >> s.studentID && ifs >> s.name && ifs >> s.password){
        stu.push_back(s);
    }
    cout << " in student.txt , there are " << stu.size() << "  student" << endl;
    ifs.close();

}
void manager :: initVecTeacher(){


    ifstream ifs;
    ifs.open(TEACHER_FILE, ios :: in);
    if(!ifs.is_open()){
        cout << "wrong , cound not open the teacher_file" << endl;
        return;
    }
    tea.clear();
    teacher s;
    while(ifs >> s.teacherID && ifs >> s.name && ifs >> s.password){
        tea.push_back(s);
    }
    cout << " in teacher.txt , there are " << tea.size() << "  teacher" << endl;
    ifs.close();
}
void manager :: initComputerRoom(){
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
bool manager :: checkRepeat(int id, int type){
    if(type == 1){
        for(auto it : this->stu){
            if(it.studentID == id) return true;
        }
    }
    else if(type == 2){
        for(auto it : this->tea){
            if(it.teacherID == id) return true;
        }
    }
    else{
        cout << "the type is wrong" << endl;
    }
    return false;
}




