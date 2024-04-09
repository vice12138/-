#pragma once
#include<iostream>
#include<vector>
#include<unordered_map>
#include"./speaker.h"

using namespace std;

class speechmanager{
    public:
    
    speechmanager();
    ~speechmanager();
    void showMenu();
    void show();
    void ExitSystem();
    void initspeech();
    void creatSpeaker();
    void startSpeech();
    void speechDraw();
    void speechContest();
    void showScore();

    private:

    vector<int> v1, v2, winner;
    unordered_map<int, speaker*> map;
    int idx;

};