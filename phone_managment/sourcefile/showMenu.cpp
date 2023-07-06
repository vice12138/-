#pragma once
#include"../headfile/showMenu.h"
#include"../headfile/person.h"
#include"./person.cpp"

void showMenu(struct addressbooks *book){
    while(true){

        

        cout<<"                           "<<endl;
        cout<<"  1:add the person         "<<endl;
        cout<<"  2:show the person        "<<endl;
        cout<<"  3:delete the person      "<<endl;
        cout<<"  4:search the person      "<<endl;
        cout<<"  5:change the person      "<<endl;
        cout<<"  6:clear the addressbook  "<<endl;
        cout<<"  0:edit the addressbook   "<<endl;
        cout<<"                           "<<endl;

        int choice=-1;
        cout<<"please input your choice:"<<endl;
        cin>>choice;
        struct person *res=nullptr;

        switch(choice){
            case 1:
                addperson(book); 
                break;
            case 2:
                showperson(book);
                break;
            case 3:
                deleteperson(book);
                break;
            case 4:
                res=searchperson(book);
                if(!res) cout<<"this guy doesn't exist "<<endl;
                else{
                    cout<<"the information of this guy : "<<endl;
                    showsingleperson(res);
                }
                break; 

            case 5:
                res=changeperson(book);
                cout<<"after the change , the information of this guy is as follows :"<<endl;
                showsingleperson(res);
                break;
            case 6:
                clearaddressbook(book);
                cout<<"the addressbook has been cleared "<<endl;
                break;
            case 0:
                cout<<"Edit !."<<endl;
                system("pause");
                return;
                break;
            default:
                break;
        }
    }
}