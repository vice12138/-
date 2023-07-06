#pragma once
#include"../headfile/person.h"

person::person():name("dummy"),sex(-1),age(-1),phone("00000000000"),addr("dummy"),next(nullptr),pre(nullptr){};
person::person(string name,int sex,int age,string phone,string addr):name(name),sex(sex),age(age),phone(phone),addr(addr),next(nullptr),pre(nullptr){};

addressbooks::addressbooks():head(new person()),tail(new person()),size(0),capacity(100){
    head->next=tail;
    tail->pre=head;
};
void addperson(struct addressbooks* book){
    if(book->size>=book->capacity){
        cout<<"the addressbook has exceeded  "<<endl;
        return;
    }

    struct person *newperson=new person();

    cout<<"please input the name "<<endl;
    cin>>newperson->name;

    while(true){
        cout<<"please input the sex,sex=0 means a boy,sex=1 means a girl"<<endl;
        cin>>newperson->sex;
        if(newperson->sex!=0 && newperson->sex!=1){
            cout<<"Invalid Input , please input again ."<<endl;
            continue;
        }
        break;
    }
    
    while(true){
        cout<<"please input the age"<<endl;
        cin>>newperson->age;
        if(newperson->age<0 || newperson->age>110){
            cout<<"Invalid Input , please input again ."<<endl;
            continue;
        }
        break;
    }

    cout<<"please input the phone"<<endl;
    cin>>newperson->phone;

    cout<<"please input the address"<<endl;
    cin>>newperson->addr; 

    newperson->pre=book->tail->pre;
    newperson->next=book->tail;
    book->tail->pre=newperson;
    newperson->pre->next=newperson;

    book->size++;
    return;
};

void showsingleperson(struct person* singleperson){
    if(!singleperson) cout<<"error"<<endl;
    cout<<"name="<<singleperson->name<<"  sex="<<singleperson->sex<<"  age="<<singleperson->age<<"   phonenumber="<<singleperson->phone<<"   address="<<singleperson->addr<<endl;
}
void showperson(struct addressbooks *book){
    if(book->size==0){
        cout<<"the addressbook is empty"<<endl;
        return;
    }
    else cout<<"the addressbook has "<<book->size<<" person"<<endl;
    struct person *cur = book->head;
    while(cur->next->next){
        showsingleperson(cur->next);
        cur=cur->next;
    }
}


struct person* searchperson(struct addressbooks *book){
    cout<<"please input the name of the person you want to search"<<endl;
    string singlepersoname;
    cin>>singlepersoname;
    struct person *cur=book->head;
    while(cur->next){
        if(cur->next->name==singlepersoname) return cur->next;
        cur=cur->next;
    }
    return nullptr;
};

void deleteperson(struct addressbooks *book){
    struct person *res=searchperson(book);
    if(!res) cout<<"this guy doesn't exist "<<endl;
    else{
        res->pre->next=res->next;
        res->next->pre=res->pre;
        book->size--;
        cout<<"this guy has been deleted, his information is as under : "<<endl;
        showsingleperson(res);
    }
}

struct person* changeperson(struct addressbooks *book){
    struct person *res=searchperson(book);
    if(!res) cout<<"this guy doesn't exist "<<endl;
    else{
        int ChangeChoice=-1;
        cout<<"which sector do you want to change ?"<<endl;
        cout<<"name:1,sex:2,age:3,phone:4,addr:5"<<endl;
        cin>>ChangeChoice;
        switch(ChangeChoice){
            case 1:
                cout<<"please input new name"<<endl;
                cin>>res->name;
                break;
            case 2:
                while(true){
                    cout<<"please input new sex,,sex=0 means a boy,sex=1 means a girl"<<endl;
                    cin>>res->sex;
                    if(res->sex!=0  && res->sex!=1){
                        cout<<"Invalid input,please input again"<<endl;
                        continue;
                    }
                    break;
                }
                break;
            case 3:
                while(true){
                    cout<<"please input new age "<<endl;
                    cin>>res->age;
                    if(res->age < 0  || res->age > 110){
                        cout<<"Invalid input,please input again"<<endl;
                        continue;
                    }
                    break;
                }
                break;
            case 4:
                cout<<"please input new phone"<<endl;
                cin>>res->phone;
                break;
            case 5:
                cout<<"please input new address"<<endl;
                cin>>res->addr;
                break;
            default:
                cout<<"Invalid Input"<<endl;
                break;
        }

    }
    return res;

}

void clearaddressbook(struct addressbooks *book){
    book->size=0;
    book->head->next=book->tail;
    book->tail->pre=book->head;
    return;
}