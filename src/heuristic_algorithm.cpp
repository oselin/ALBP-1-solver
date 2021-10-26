#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <HeuristicAlgorithm.h>



std::unordered_map<int,int> PrecedenceGraph::RPWs(){
    std::unordered_map<int,int> rpws;
    
    for (auto buf : this->tasks){
        int time = 0;
        for (auto pattern : this->get_pattern(buf.first)) {
            time += pattern.second;
        }
        rpws[buf.first] = time;
    }
    
    return rpws;
}


std::unordered_map<int,int> PrecedenceGraph::get_pattern(int key)
{
    std::unordered_map<int,int> vec;
    vec[key] = this->wt[key-1];

    for (int i=0; i<(int)this->tasks[key].size(); i++){
        std::unordered_map<int,int> buffer = this->get_pattern(this->tasks[key][i]);

        for (auto k : buffer){
            if (vec.find(k.first) == vec.end()) vec[k.first] = k.second;
        }
    }

    return vec;
}


std::vector<int> PrecedenceGraph::BKs(int task, std::vector<int> taskAssigned){
    std::vector<int> todo;

    return todo;
}


void PrecedenceGraph::SALBP_1(){
    ////make a list of all the tasks that must be assigned
    //std::vector<int> tasksLeft;
    //for (auto k : this->tasks) tasksLeft.push_back(k.first);
//
    //int index = 1;
//
    ////POINT 1
    ////Estimate all the RPWs of all the tasks
    //std::vector<int> rpws = RPWs(pg, timing);
    //while (index>0){
    //    int workload = 0;
//
    //    
//
    //    //POINT 2
    //    std::vector<int> stations;
    //    while (workload <= c){
    //        //POINT 3
    //        std::vector<int> bk;
    //        
    //        //setting up BK set
    //        if (index==1) bk.push_back(1);
    //        else{
    //            for (int j=0; j<pg[index].size(); j++) bk.push_back(pg[index][j]);
    //            //TO IMPLEMENT
    //        }
//
    //        //POINT 4
    //        if (bk.size() == 0){
    //            //POINT 5
    //            if (tasksLeft.size() == 0) return;
    //            else index++;
    //        }
    //        else{
    //            int max = getMax(bk, rpws);
    //            workload += timing[max];
    //            if (workload < c){
    //                stations.push_back(max);
    //                //erase from the task list
    //                tasksLeft.erase(std::remove(tasksLeft.begin(),tasksLeft.end(),max),tasksLeft.end());
    //            }
    //        }
    //    }
    //}
}

void PrecedenceGraph::SALBP_2(){}

























































/*

//load station and precedences
std::unordered_map<int,std::vector<int>> loadData(int k){

    std::unordered_map<int,std::vector<int>> pg;

    for (int i=1; i<=k; i++){
        std::vector<int> related_tasks;
        int s=1;
        while (s > 0){
            std::cout << "STATION: " << i << " Further linked station: ";
            std::cin >> s;
            if (s > 0){
                related_tasks.push_back(s);
            }
            else s = -1;
        }

        pg[k] = related_tasks;
    }

    return pg;
}

//load time of all the tasks
std::vector<int> loadTiming(int k){
    std::vector<int> timing;
    for (int i=0; i<k; i++){
        int t;
        std::cout << "TIME FOR TASK " << i+1 << ": ";
        std::cin >> t;
        timing.push_back(t);
    }

    return timing;
}


void run(
            int c,
            std::unordered_map<int,std::vector<int>> pg,
            std::vector<int> timing){

    
    std::unordered_map<int,std::vector<int>> solution;

    //make a list of all the tasks that must be assigned
    std::vector<int> tasksLeft;
    for (int i=0; i< timing.size(); i++) tasksLeft.push_back(i);

    int index = 1;

    //POINT 1
    //Estimate all the RPWs of all the tasks
    std::vector<int> rpws = RPWs(pg, timing);
    while (index>0){
        int workload = 0;

        

        //POINT 2
        std::vector<int> stations;
        while (workload <= c){
            //POINT 3
            std::vector<int> bk;
            
            //setting up BK set
            if (index==1) bk.push_back(1);
            else{
                for (int j=0; j<pg[index].size(); j++) bk.push_back(pg[index][j]);
                //TO IMPLEMENT
            }

            //POINT 4
            if (bk.size() == 0){
                //POINT 5
                if (tasksLeft.size() == 0) return;
                else index++;
            }
            else{
                int max = getMax(bk, rpws);
                workload += timing[max];
                if (workload < c){
                    stations.push_back(max);
                    //erase from the task list
                    tasksLeft.erase(std::remove(tasksLeft.begin(),tasksLeft.end(),max),tasksLeft.end());
                }
            }
        }
    }
        
}*/