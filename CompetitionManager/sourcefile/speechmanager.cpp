#pragma once
#include <string>
#include "../headfile/speechmanager.h"
#include "../headfile/speaker.h"
#include<algorithm>
#include<deque>
#include<map>
#include<numeric>


speechmanager::speechmanager(){
    this->initspeech();
    return;

};

speechmanager::~speechmanager(){
    return;
};

void speechmanager::showMenu(){

        std::cout<<"                                  "<<std::endl;
        std::cout<<"     0: exit workermanagement     "<<std::endl;
        std::cout<<"     1: start the speech   "<<std::endl;
        std::cout<<"     2: show worker information   "<<std::endl;
        std::cout<<"     3: delete worker             "<<std::endl;
        std::cout<<"     4: change worker             "<<std::endl;
        std::cout<<"     5: search worker             "<<std::endl;
        std::cout<<"     6: sort all worker           "<<std::endl;
        std::cout<<"     7: clean the file            "<<std::endl;
        std::cout<<"                                  "<<std::endl;
};

void speechmanager::show(){
    while(true){
        this->showMenu();

        int choice=-1;

        std::cout<<"please input your choice :"<<std::endl;

        std::cin>>choice;


        switch(choice){
            case 0:;
                this->ExitSystem();
                break;
            case 1:
                this->startSpeech();
                break;
            case 2:
              
                break;
            case 3:
          
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

void speechmanager::ExitSystem(){
    std::cout<<"exit the speechmanager.system "<<std::endl;
    std::system("pause");
    exit(0);
};

void speechmanager::initspeech(){
    this->v1.clear();
    this->v2.clear();
    this->winner.clear();
    this->map.clear();
    this->idx = 1;
    this->creatSpeaker();
}

void speechmanager::creatSpeaker(){
    string tmp = "abcdefghijkl";
    for(int i = 0; i < tmp.size(); ++i){
        string name  = "Speaker";
        name += tmp[i];
        speaker* newspeaker = new speaker(name);
        int idxx = 100001 + i;
        this->v1.push_back(idxx);
        map[idxx] = newspeaker;
    }
}

void speechmanager::startSpeech(){
    this->speechDraw();
    this->speechContest();
    this->showScore();

    this->idx++;
    this->speechDraw();
    this->speechContest();
    this->showScore();
}
void speechmanager::speechDraw(){
    std::cout << "this is " << this->idx << "  draw" << std::endl;
    if(this->idx == 1){
        random_shuffle(this->v1.begin(), this->v1.end());
        std::cout << "they are as follows: " << std::endl;
        for(auto it : this->v1) std::cout << it << "  ";
    }
    else if(this->idx == 2){
        random_shuffle(this->v2.begin(), this->v2.end());
        std::cout << "they are as follows: " << std::endl;
        for(auto it : this->v2) std::cout << it << "  ";
    }
    system("pause");
}

void speechmanager::speechContest(){
    std::cout << "contest " << this->idx << " has begun ." << std::endl;
    multimap<double, int, greater<double>> group;
    vector<int> v;

    int num = 0;
    if(this->idx == 1) v =  this->v1;
    else v = this->v2;
    // std::cout << v.size() << std::endl;
    for(auto it : v){
        num++;
        vector<double> vec;
        for(int i = 0; i < 10; ++i){
            double tmpscore = (rand() % 401 + 600) / 10.f;
   
            vec.push_back(tmpscore);
        }

  
        sort(vec.begin(), vec.end());
        
        double sum = 0.0;
        for(int i = 1; i < vec.size() - 1; ++i) sum += vec[i];
   
        double averageScore = sum / (double)(vec.size() - 2);

        this->map[it]->score[this->idx - 1] = averageScore;

        group.insert(pair<double, int>(averageScore, it));  

        if (num % 6 == 0){
			for (auto tmp = group.begin(); tmp != group.end(); tmp++)
			{
				cout << "idx = " << tmp->second << " name = " << this->map[tmp->second]->name << " score = " << this->map[tmp->second]->score[this->idx - 1] << endl;
			}
			int count = 0;
			for (auto tmp = group.begin(); tmp != group.end() && count < 3; tmp++, count++){
				if (this->idx == 1) this->v2.push_back(tmp->second);
				else this->winner.push_back(tmp->second);	
			}
			group.clear();
		}

    }
    std::system("pause");  
}

void speechmanager::showScore(){
    std::cout << "loop = " << this->idx << std::endl;
    vector<int> vec;
    if(this->idx == 1) vec = this->v2;
    else vec = this->winner;
    for(auto it : vec){
        std::cout << "idx = " << it << " name = " << this->map[it]->name << " score = " << this->map[it]->score[this->idx - 1] << std::endl;
    }
    std::system("pause");
}