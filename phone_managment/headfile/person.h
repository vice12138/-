#pragma once
#include<iostream>

using namespace std;

struct person{
    string name;
    int sex;
    int age;
    string phone;
    string addr;
    struct person *next,*pre;
    person();
    person(string name,int sex,int age,string phone,string addr);
};

struct addressbooks{
    struct person *head,*tail;
    int size,capacity;
    addressbooks();
    
};
void addperson(struct addressbooks* book);
void showsingleperson(struct person* singleperson);
void showperson(struct addressbooks *book);
struct person* searchperson(struct addressbooks *book);
void deleteperson(struct addressbooks *book);
struct person* changeperson(struct addressbooks *book);
void clearaddressbook(struct addressbooks *book);