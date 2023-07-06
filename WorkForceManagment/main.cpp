#include<iostream>
#include"./HeadFile/workerManager.h"
#include"./SourceFile/workerManager.cpp"
#include"./HeadFile/worker.h"
#include"./HeadFile/inheritWorker.h"
#include"./SourceFile/inheritWorker.cpp"



int main(){
    
    workerManager *wm = new workerManager();
    wm->show();
    std::system("pause");
    return 0;
}