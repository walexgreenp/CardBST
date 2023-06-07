#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <thread>

using namespace std;


void linearSearchCompare(vector<string> handA, vector<string> handB, int delay){
    // Simulate finding/printing shared cards
    string aConcat = "";
    string bConcat = "";
    for(int i = 0; i < handA.size(); i++){
        for(int j = 0; j < handB.size(); j++){
            if(handA[i] == handB[j]){
                // Simulating print delay
                std::chrono::nanoseconds duration(delay);
                std::this_thread::sleep_for(duration);

                // Setting same values to -1
                handA[i] = "-1";
                handB[i] = "-1";
                break;
            }
        }
    }

    // Simulate finding/printing remaining cards
    for(int i = 0; i < handA.size(); i++){
        if(handA[i] != "-1"){
            // Simulating print delay.
            std::chrono::nanoseconds duration(delay);
            std::this_thread::sleep_for(duration);
        }
    } 
    for(int j = 0; j < handB.size(); j++){
        if(handB[j] != "-1"){
            // Simulating print delay.
            std::chrono::nanoseconds duration(delay);
            std::this_thread::sleep_for(duration);
        }
    }
}