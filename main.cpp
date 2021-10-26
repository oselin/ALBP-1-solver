#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "include/HeuristicAlgorithm.h"


int main(){

    std::unordered_map<int,std::vector<int>> pg;

    pg[1] = {2,3};
    pg[2] = {4,5};
    pg[3] = {6};
    pg[4] = {8};
    pg[5] = {6,8};
    pg[6] = {7};
    pg[7] = {9};
    pg[8] = {10};
    pg[9] = {10};
    pg[10] = {};

    std::vector<int> time = {3,7,20,1,8,4,9,11,6,6};


    //int c = 36;



    PrecedenceGraph p (time, pg);

    for (auto i : p.RPWs()) std::cout << i.first << ": " << i.second << std::endl;

}