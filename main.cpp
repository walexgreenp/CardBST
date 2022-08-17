#include <iostream>
#include <fstream>
#include <string>
#include "cards.h"




using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  Hand hand1, hand2;
  int currNodeValue = 0;




  // Reading File 1
  while (getline (cardFile1, line) && (line.length() > 0)){

    // Checking Suit
    switch(line.at(0)){
      case 'c':
        currNodeValue += 100;
        break;
      case 'd':
        currNodeValue += 200;
        break;
      case 's':
        currNodeValue += 300;
        break;
      case 'h':
        currNodeValue += 400;
        break;
    }

    // Checking Value
    switch(line.at(2)){
      case 'a':
        currNodeValue += 1;
        break;
      case '2':
        currNodeValue += 2;
        break;
      case '3':
        currNodeValue += 3;
        break;
      case '4':
        currNodeValue += 4;
        break;
      case '5':
        currNodeValue += 5;
        break;
      case '6':
        currNodeValue += 6;
        break;
      case '7':
        currNodeValue += 7;
        break;
      case '8':
        currNodeValue += 8;
        break;
      case '9':
        currNodeValue += 9;
        break;
      case 'j':
        currNodeValue += 11;
        break;
      case 'q':
        currNodeValue += 12;
        break;
      case 'k':
        currNodeValue += 13;
        break;
      default:
        currNodeValue += 10;
    }

    hand1.insert(currNodeValue);
    currNodeValue = 0;

  }
  cardFile1.close();


  // Reading File 2
  while (getline (cardFile2, line) && (line.length() > 0)){

    // Checking Suit
    switch(line.at(0)){
      case 'c':
        currNodeValue += 100;
        break;
      case 'd':
        currNodeValue += 200;
        break;
      case 's':
        currNodeValue += 300;
        break;
      case 'h':
        currNodeValue += 400;
        break;
    }

    // Checking Value
    switch(line.at(2)){
      case 'a':
        currNodeValue += 1;
        break;
      case '2':
        currNodeValue += 2;
        break;
      case '3':
        currNodeValue += 3;
        break;
      case '4':
        currNodeValue += 4;
        break;
      case '5':
        currNodeValue += 5;
        break;
      case '6':
        currNodeValue += 6;
        break;
      case '7':
        currNodeValue += 7;
        break;
      case '8':
        currNodeValue += 8;
        break;
      case '9':
        currNodeValue += 9;
        break;
      case 'j':
        currNodeValue += 11;
        break;
      case 'q':
        currNodeValue += 12;
        break;
      case 'k':
        currNodeValue += 13;
        break;
      default:
        currNodeValue += 10;
    }

    hand2.insert(currNodeValue);
    currNodeValue = 0;

  }
  cardFile2.close();

  // int currNode1 = hand1.getSmallest();
  // int temp;
  // int currNode2 = hand2.getLargest();
  // bool removedValue = false;


  // while(hand1.getSuccessor(currNode1) != 0 || hand2.getPredecessor(currNode2) != 0){

  //   for(int i = 0; i < hand1.count(); i++){

  //     if(hand2.contains(currNode1)){
  //       cout << "Alice picked matching card " << hand1.getOriginalValue(currNode1) << endl;
  //       temp = hand1.getSuccessor(currNode1);
  //       hand1.remove(currNode1);
  //       hand2.remove(currNode1);
  //       currNode1 = temp;
  //       break;
  //     }
  //     else{
  //       currNode1 = hand1.getSuccessor(currNode1);
  //     }
  //   }

  //   for(int i = 0; i < hand2.count(); i++){
  //     if(hand1.contains(currNode2)){
  //       cout << "Bob picked matching card " << hand2.getOriginalValue(currNode2) << endl;
  //       temp = hand2.getPredecessor(currNode2);
  //       hand1.remove(currNode2);
  //       hand2.remove(currNode2);
  //       currNode2 = temp;
  //       break;
  //     }
  //     else{
  //       currNode2 = hand2.getSuccessor(currNode2);
  //     }
  //   }

  //   currNode1 = hand1.getSmallest();
  //   currNode2 = hand2.getLargest();
  // }

  int currNode1 = hand1.getSmallest();
  int currNode2 = hand2.getLargest();
  bool turn = true;
  int totalBreaks = 0;

  while(hand1.getSuccessor(currNode1) != 0 || hand2.getPredecessor(currNode2) != 0) {
    // Alice's Turn
    while(turn == true) {

      // Sets Nodes, Checks if node is null
      if(currNode1 == 0 ){
        totalBreaks++;
        break;
      }

      // Checks if currNosde1 is in hand 2
      if(hand2.contains(currNode1)) {
        cout << "Alice picked matching card " << hand1.getOriginalValue(currNode1) << endl;
        hand1.remove(currNode1);
        hand2.remove(currNode1);
        turn = false;
        totalBreaks = 0;
        break;
      }

      else {
        currNode1 = hand1.getSuccessor(currNode1);
      }
    }

    // Check if break too many times
    if(totalBreaks > 1){
      break;
    }

    // Bob's Turn
    while(turn == false) {

      if(currNode2==0) {
        totalBreaks++;
        break;
      }

      if(hand1.contains(currNode2)) {
        cout << "Bob picked matching card " << hand2.getOriginalValue(currNode2) << endl;
        hand1.remove(currNode2);
        hand2.remove(currNode2);
        turn = true;
        totalBreaks = 0;
        break;
      }
      else {
        currNode2 = hand2.getPredecessor(currNode2);
      }
    }

    if(totalBreaks > 1){
      break;
    }

    currNode1 = hand1.getSmallest();
    currNode2 = hand2.getLargest();
  }



  cout << endl << "Alice's cards:" << endl;
  currNode1 = hand1.getSmallest();
  while(hand1.getSuccessor(currNode1) != 0){
    cout << hand1.getOriginalValue(currNode1) << endl;
    currNode1 = hand1.getSuccessor(currNode1);
  }
  cout << hand1.getOriginalValue(currNode1) << endl;


  cout << endl << "Bob's cards:" << endl;
  currNode2 = hand2.getSmallest();
  while(hand2.getSuccessor(currNode2) != 0){
    cout << hand2.getOriginalValue(currNode2) << endl;
    currNode2 = hand2.getSuccessor(currNode2);
  }
  cout << hand2.getOriginalValue(currNode2) << endl;

  
  return 0;
}
