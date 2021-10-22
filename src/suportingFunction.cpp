#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include "../include/ALBP.h"

//return the max element in the bk- set
int getMax(std::vector<int> bk, std::vector<int> RPWs){

    std::unordered_map<int, int> toAnalyze;

    for (int i=0; i<bk.size(); i++){
        toAnalyze[bk[i]] = RPWs[bk[i]];
    }
    auto max = *std::max_element(toAnalyze.begin(), toAnalyze.end());
    
    return max.first;

}


//return the sum of all elements included in the vector
int sum(int t, std::unordered_map<int,std::vector<int>> vec, 
                        std::vector<int> timing){
    
    
    if (t==1) return timing[0];
    else{
        int time = 0;
        for (int i=0; i<vec[t].size();i++){
            time += sum(vec[t][i], vec, timing);
        }
        return time;
    }
    
}

//reverse the connetions in the precedence graph
std::unordered_map<int,std::vector<int>> reversePG(std::unordered_map<int,std::vector<int>> vec){
    
    std::unordered_map<int,std::vector<int>> rpg;

    for (int i=1; i<=vec.size(); i++){
        for (int j=0; j<vec[i].size(); j++){
            std::cout << "Element: " << vec[i][j] << std::endl;
            std::cout << "setting " << i << "in " <<  vec[i][j] << std::endl;
            rpg[vec[i][j]].push_back(i);
        }
        rpg[1].push_back(0);
    }

    return rpg;

}


//return a vector including all the RPWs of the precedence graph
std::vector<int> RPWs(
                        std::unordered_map<int,std::vector<int>> vec, 
                        std::vector<int> timing){

    std::vector<int> rpws;

    for (int i=1; i <= vec.size(); i++){
        for (int j=0; j< vec[i].size(); j++){
            int rpw = timing[i-1] + sum(vec[i][j], vec, timing);
            rpws.push_back(rpw);
        }
    }

    return rpws;
}