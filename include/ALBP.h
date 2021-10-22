#ifndef ALBP_H
#define ALBP_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

int getMax(std::vector<int>, std::vector<int>);

int sum(int, std::unordered_map<int,std::vector<int>>, std::vector<int>);

std::vector<int> RPWs(std::unordered_map<int,std::vector<int>>, std::vector<int>);

std::unordered_map<int,std::vector<int>> loadData(int);

std::vector<int> loadTiming(int);

void run(int,std::unordered_map<int,std::vector<int>>,std::vector<int>);

std::unordered_map<int,std::vector<int>> reversePG(std::unordered_map<int,std::vector<int>>);
#endif //ALBP_H