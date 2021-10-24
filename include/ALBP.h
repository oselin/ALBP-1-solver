#ifndef ALBP_H
#define ALBP_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>



class PrecedenceGraph{
    private:

        std::vector<int> wt;
        std::unordered_map<int,std::vector<int>> tasks;
        int cycleTime;

        std::unordered_map<int,int> get_pattern(int);
        
    public:
        
        PrecedenceGraph(){}
        PrecedenceGraph(std::vector<int> w, std::unordered_map<int,std::vector<int>> t): wt{w}, tasks{t}{}

        std::unordered_map<int,int> RPWs();
        std::vector<int> BKs(int, std::vector<int>);
        void run();

        
};
















int getMax(std::vector<int>, std::vector<int>);

int sum(int, std::unordered_map<int,std::vector<int>>, std::vector<int>);

std::vector<int> RPWs(std::unordered_map<int,std::vector<int>>, std::vector<int>);

std::unordered_map<int,std::vector<int>> loadData(int);

std::vector<int> loadTiming(int);

void run(int,std::unordered_map<int,std::vector<int>>,std::vector<int>);

std::unordered_map<int,std::vector<int>> reversePG(std::unordered_map<int,std::vector<int>>);
#endif //ALBP_H