#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include "../include/ALBP.h"



void printUMAP(std::unordered_map<int,std::vector<int>> vec){
    for (int i=1; i<=(int)vec.size(); i++){
        std::cout << i << ": {";
        for (int j=0; j<(int)vec[i].size(); j++) {
            std::cout << vec[i][j] << ", ";
        }
        std::cout << "}"<< std::endl;
    }
}
//return the max element in the bk- set
int getMax(std::vector<int> bk, std::vector<int> RPWs){

    std::unordered_map<int, int> toAnalyze;

    for (int i=0; i<(int)bk.size(); i++){
        toAnalyze[bk[i]] = RPWs[bk[i]];
    }
    auto max = *std::max_element(toAnalyze.begin(), toAnalyze.end());
    
    return max.first;

}


//return the sum of all elements included in the vector
int sum(std::vector<int> links, 
        std::unordered_map<int,std::vector<int>> vec, 
        std::vector<int> timing){

        //int s = 0;

        //for (int i=0; i<links.size(); i++){
//
        //}
    
    return 1;
    
    
}

//reverse the connetions in the precedence graph
std::unordered_map<int,std::vector<int>> reversePG(std::unordered_map<int,std::vector<int>> vec){
    
    std::unordered_map<int,std::vector<int>> rpg;

    for (int i=1; i<=(int)vec.size(); i++){
        for (int j=0; j<(int)vec[i].size(); j++){
            std::cout << "Element: " << vec[i][j] << std::endl;
            std::cout << "setting " << i << "in " <<  vec[i][j] << std::endl;
            rpg[vec[i][j]].push_back(i);
        }
        
    }

    rpg[1].push_back(0);
    return rpg;

}


//return a vector including all the RPWs of the precedence graph
//std::vector<int> RPWs(
//                        std::unordered_map<int,std::vector<int>> vec, 
//                        std::vector<int> timing){
//
//    std::vector<int> rpws;
//
//    //vec = reversePG(vec);
//
//    printUMAP(vec);
//    for (int i=1; i <=(int) vec.size(); i++){
//        std::cout << "CHECK"<<i << ": ";
//        int rpw;
//        for (int j=0; j<(int) vec[i].size(); j++){
//            std::cout << "----------" << i << std::endl;
//            rpw = timing[i-1] + sum(vec[i][j], vec, timing);
//            
//        }
//        rpws.push_back(rpw);
//        std::cout << rpw << std::endl;
//    }
//
//    return rpws;
//}
//
