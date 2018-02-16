// you can use includes, for example:
// #include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S, string &T, string &U) {
    // write your code in C++14 (g++ 6.2.0)
    map<pair<string,int>, int> maps;
    map<string, int> installedMaps;
    
    istringstream inputMaps(S);
    string line;
    
    while (getline(inputMaps,line)) {
        string delimiter = ",";
        string area = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        string version = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        string size = line.substr(0, line.find(delimiter));
        maps.emplace(make_pair(area,stoi(version)), stoi(size));
    }
    
    istringstream inputInstalled(T);
    while (getline(inputInstalled,line)) {
        string delimiter = ",";
        string area = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        string version = line.substr(0, line.find(delimiter));
        installedMaps.emplace(area, stoi(version));
    }
    
    int installedVersion;
    auto ptr = installedMaps.find(U);
    if (ptr==installedMaps.end()) {
        installedVersion = 0;
    }
    else installedVersion = ptr->second;     
    
    int sizeToDownload = 0;
    int found = 0;
    
    map<pair<string,int>, int>::iterator iter;
    for (iter = maps.begin(); iter != maps.end(); ++iter) {
        pair<string,int> thisMap = iter->first;
        if (thisMap.first == U) {
            found = 1;
           if (thisMap.second > installedVersion) { 
                sizeToDownload += iter->second;
           }
        }
    }
    if (found)
        return sizeToDownload;
    else return -1;    
}
