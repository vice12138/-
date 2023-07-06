#pragma once
#include<iostream>
#include"worker.h"
#include"inheritWorker.h"
#include<fstream>

#define FILENAME "./File/empFile.txt"



class workerManager{
   
    public:
        
        int EmployeeNum;
        bool FileIsEmpty;
        worker *head,*tail;

        workerManager();
        ~workerManager();
        void show();
        void ExitSystem();
        worker* addAtail(worker *temp);
        void addEm();
        void save();
        void initFromFile();
        void showSingleWorker(const worker* wk);
        void shoWorker();

        worker* searchWorker(int workerid);
        worker* searchWorker(std::string workername);

        void deleteSingleWorker(worker *temp);
        void delWorker(int workerid);
        void delWorker(std::string workername);


};