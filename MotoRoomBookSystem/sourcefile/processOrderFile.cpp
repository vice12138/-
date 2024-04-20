#pragma once
#include"../headfile/processOrderFile.h"

processOrderFile :: processOrderFile(){
    ifstream ifs;
    ifs.open(ORDER_FILE, ios :: in);
    string date, interval, id, name, room, state;
    this->file_size = 0;
    while(ifs >> date && ifs >> interval && ifs >> id && ifs >> name && ifs >> room && ifs >> state){
        string key, value;
        unordered_map<string, string> tmp_map;
        int pos = date.find(":");
        key = date.substr(0, pos);
        value = date.substr(pos + 1, date.size() - pos - 1);
        tmp_map.insert({key, value});

        pos = interval.find(":");
        key = interval.substr(0, pos);
        value = interval.substr(pos + 1, interval.size() - pos - 1);
        tmp_map.insert({key, value});
        
        pos = id.find(":");
        key = id.substr(0, pos);
        value = id.substr(pos + 1, id.size() - pos - 1);
        tmp_map.insert({key, value});

        pos = name.find(":");
        key = name.substr(0, pos);
        value = name.substr(pos + 1, name.size() - pos - 1);
        tmp_map.insert({key, value});

        pos = room.find(":");
        key = room.substr(0, pos);
        value = room.substr(pos + 1, room.size() - pos - 1);
        tmp_map.insert({key, value});

        pos = state.find(":");
        key = state.substr(0, pos);
        value = state.substr(pos + 1, state.size() - pos - 1);
        tmp_map.insert({key, value});

        this->map.insert({this->file_size, tmp_map});
        this->file_size ++;
    }
    ifs.close();
};
void processOrderFile :: printSingleOrder(int idx){
    if(idx < 0 || idx >= this->file_size){
        cout << "the idx is invalid" << endl;
        return;
    }
    cout << "order.txt_idx:" << idx << " date:" << this->map[idx]["date"] << " interval:" << this->map[idx]["interval"]
         << " studentID" << this->map[idx]["studentID"] << " name:" << this->map[idx]["name"]
         << " room" << this->map[idx]["room"] << " state:" << this->map[idx]["state"] << endl;
}
void processOrderFile :: updateOrderFile(){
    if(this->file_size == 0) return;
    ofstream ofs;
    ofs.open(ORDER_FILE, ios :: out | ios :: trunc);
    for(int i = 0; i < this->file_size; ++i){
        
        ofs << "date:" << this->map[i]["date"] << " ";
        ofs << "interval:" << this->map[i]["interval"] << " ";
        ofs << "studentID:" << this->map[i]["studentID"] << " ";
        ofs << "name:" << this->map[i]["name"] << " ";
        ofs << "room:" << this->map[i]["room"] << " ";
        ofs << "state:" << this->map[i]["state"] << endl;

    }
    ofs.close();
}