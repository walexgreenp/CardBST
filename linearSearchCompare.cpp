#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <vector>

using namespace std;


void linearSearchCompare(vector<string> handA, vector<string> handB){
    // Simulate finding/printing shared cards
    string aConcat = "";
    string bConcat = "";
    for(int i = 0; i < handA.size(); i++){
        for(int j = 0; j < handB.size(); j++){
            if(handA[i] == handB[j]){
                aConcat += handA[i];
                bConcat += handB[i];
                break;
            }
        }
    }


    // Simulate finding/printing remaining cards
    string stallVariable = "";
    for(int i = 0; i < handA.size() - (aConcat.size()/2); i++){
        stallVariable += handA[i];
    }  
    for(int j = 0; j < handB.size()- (bConcat.size()/2); j++){
        stallVariable += handB[j];
    }

}