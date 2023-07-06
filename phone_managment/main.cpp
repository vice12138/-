#include<iostream>
#include"./headfile/showMenu.h"
#include"./sourcefile/showMenu.cpp"
#include"./headfile/person.h"
#include"./sourcefile/person.cpp"



using namespace std;


int main(){

    struct addressbooks* book=new addressbooks();
    showMenu(book);
    system("pause");
    return 0;

}