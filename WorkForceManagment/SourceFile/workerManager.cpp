#pragma once
#include"../HeadFile/workerManager.h"

workerManager::workerManager(){

    this->EmployeeNum=0;
    head=new Boss();
    tail=new Boss();
    head->next=tail;
    tail->pre=head;
    
    std::ifstream ifs;
    ifs.open(FILENAME,std::ios::in);

    if(!ifs.is_open()){
        std::cout<<"the file doesn't exist !"<<std::endl;
        this->FileIsEmpty=true;
        ifs.close();
        return;
    }

    char ch;
    ifs>>ch;
    if(ifs.eof()){
        std::cout<<"the file exists, but no information exists !"<<std::endl;
        this->FileIsEmpty=true;
        ifs.close();
        return;
    }
    ifs.close(); 
    initFromFile();

};
workerManager::~workerManager(){
    while(this->head->next!=this->tail){
        deleteSingleWorker(this->head->next);
        this->EmployeeNum--;
    }

};


void Show_Menu(){
    std::cout<<"                                  "<<std::endl;
    std::cout<<"     0: exit workermanagement     "<<std::endl;
    std::cout<<"     1: add  worker information   "<<std::endl;
    std::cout<<"     2: show worker information   "<<std::endl;
    std::cout<<"     3: delete worker             "<<std::endl;
    std::cout<<"     4: change worker             "<<std::endl;
    std::cout<<"     5: search worker             "<<std::endl;
    std::cout<<"     6: sort all worker           "<<std::endl;
    std::cout<<"     7: clean the file            "<<std::endl;
    std::cout<<"                                  "<<std::endl;
}
void workerManager::ExitSystem(){
    std::cout<<"exit the workermanagment "<<std::endl;
    std::system("pause");
    exit(0);
};
void workerManager::show(){
    while(true){
        Show_Menu();
        int choice=-1;
        std::cout<<"please input your choice :"<<std::endl;
        std::cin>>choice;

        int curchoice=-1;
        int curid=-1;
        std::string curname="qqq";

        switch(choice){
            case 0:
                ExitSystem();
                break;
            case 1:
                this->addEm();
                break;
            case 2:
                this->shoWorker();
                break;
            case 3:
                std::cout<<"please input the worker you want to delete,  workerid:1, workername:2 "<<std::endl;
                
                std::cin>>curchoice;
                switch(curchoice){
                    case 1:
                        std::cout<<"please input the workerID you want to delete:"<<std::endl;
                        std::cin>>curid;
                        this->delWorker(curid);
                        break;
                    case 2:
                        std::cout<<"please input the workerName you want to delete:"<<std::endl;
                        std::cin>>curname;
                        this->delWorker(curname);
                        break;
                    default:
                        std::cout<<"wrong choice"<<std::endl;
                        break;
                };
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                std::cout<<"invalid input !"<<std::endl;
                std::system("pause");
                break;
        }

        std::system("cls");

    }
}

worker* workerManager::addAtail(worker *temp){
    temp->next=this->tail;
    temp->pre=this->tail->pre;
    temp->pre->next= temp;
    this->tail->pre=temp;
    return temp;
}

void workerManager::addEm(){
    std::cout<<"please input how many person you want to add : "<<std::endl;
    int addnum=0;
    std::cin>>addnum;

    if(addnum<=0) std::cout<<"invalid input"<<std::endl;
    else{
        for(int i=0;i<addnum;++i){
            std::cout<<"please input person "<<i+1<<" : "<<std::endl;
            int workerID=-1,DeptID=-1;
            std::string name="";
            
            std::cout<<"please input workerID ,there has been person "<<this->EmployeeNum<<" : "<<std::endl;
            std::cin>>workerID;
            std::cout<<"please input name : "<<std::endl;
            std::cin>>name;
            std::cout<<"please input DeptID , Employee:1  Manager:2  Boss:3"<<std::endl;
            std::cin>>DeptID;

            worker *neworker=nullptr;
            switch (DeptID){
                case 1:
                    neworker=new Employee(workerID,name,DeptID);
                    break;
                case 2:
                    neworker=new Manager(workerID,name,DeptID);
                    break;
                case 3:
                    neworker=new Boss(workerID,name,DeptID);
                    break;
                default:
                    break;        
            } 
            worker *temp=addAtail(neworker);
            this->EmployeeNum++;
            std::cout<<"Successfully added person "<<i+1<<" ! "<<std::endl;

        }
    }
    this->FileIsEmpty=false;
    this->save();
    std::system("pause");
    std::system("cls");
}

void workerManager::save(){
    std::ofstream ofs;
    
    ofs.open(FILENAME,std::ios::out);
    worker *cur=this->head;
    while(cur->next!=this->tail){
        ofs<<cur->next->workerID<<" "
           <<cur->next->name<<" "
           <<cur->next->DeptID<<std::endl;
        cur=cur->next;
    }
    ofs.close();
}

 void workerManager::initFromFile(){
    std::ifstream ifs;
    ifs.open(FILENAME,std::ios::in);
    
    int workerid;
    std::string workername;
    int deptid;

    while(ifs>>workerid>>workername>>deptid){
        worker *wk=nullptr;
        if(deptid==1) wk=new Employee(workerid,workername,deptid);
        else if(deptid==2) wk=new Manager(workerid,workername,deptid);
        else if(deptid==3) wk=new Boss(workerid,workername,deptid);
        else std::cout<<"something is wrong"<<std::endl;
        addAtail(wk);
        this->EmployeeNum++;
    }
    std::cout<<"in this file,there has "<<this->EmployeeNum<<" person, they have been loaded "<<std::endl;
    this->FileIsEmpty=false;
    ifs.close();
    return;
 };



void workerManager::showSingleWorker(const worker* wk){
    if(!wk) std::cout<<"wk=nullptr,wrong"<<std::endl;
    std::cout<<"workerID:"<<wk->workerID<<"       workername:"<<wk->name<<"       DeptID:"<<wk->DeptID<<std::endl;
}
void workerManager::shoWorker(){
    if(this->EmployeeNum==0) std::cout<<"no worker exists"<<std::endl;
    worker * cur=this->head;
    while(cur->next!=this->tail){
        showSingleWorker(cur->next);
        cur=cur->next;
    }
    std::system("pause");
}

worker* workerManager::searchWorker(int workerid){
    if(this->EmployeeNum==0) return nullptr;
    worker *wk=this->head;
    while(wk->next!=this->tail){
        if(wk->next->workerID==workerid) return wk;
    }
    return nullptr;
};
worker* workerManager::searchWorker(std::string workername){
    if(this->EmployeeNum==0) return nullptr;
    worker *wk=this->head;
    while(wk->next!=this->tail){
        if(wk->next->name==workername) return wk;
    }
    return nullptr;
};
void workerManager::deleteSingleWorker(worker *temp){
    
    if(!temp){
        std::cout<<"this worker doesn't exist"<<std::endl;
        return;
    }
    temp->pre->next=temp->next;
    temp->next->pre=temp->pre;
    temp->pre=nullptr;
    temp->next=nullptr;
    delete temp;
}
void workerManager::delWorker(int workerid){
    worker *wk=searchWorker(workerid);
    if(!wk){
        std::cout<<"this worker doesn't exist "<<std::endl;
        return;
    }
    deleteSingleWorker(wk->next);
    std::cout<<"successfully delete "<<std::endl; 
    this->save();
    std::system("pause");
}
void workerManager::delWorker(std::string workername){
    worker *wk=searchWorker(workername);
    if(!wk){
        std::cout<<"this worker doesn't exist "<<std::endl;
        return;
    }
    deleteSingleWorker(wk->next);
    std::cout<<"successfully delete "<<std::endl;
    this->save();
    std::system("pause");
};