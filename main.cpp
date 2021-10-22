#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include "include/ALBP.h"


int main(){

    int m;
    int cycleTime;
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

    int c = 36;

    std::unordered_map<int,std::vector<int>> rev = reversePG(pg);


    //run(c, pg, time);
    std::vector<int> r = RPWs(pg, time);

    for (int i=0; i< r.size(); i++){
        std::cout << i << ": " << r[i] << std::endl;
    }
    return 0;
}