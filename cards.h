//cards.h
//Authors: William Greenwald
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H

#include <iostream>
using namespace std;

class Hand{

    public:


        Hand(); // Constructor
        ~Hand(); // Destructor
        bool insert(int value); // adds currentCard to Hand
        void printPreOrder() const;
        void printInOrder() const;
        string getOriginalValue();
        bool remove(int value);
        int getPredecessor(int value) const;
        int getSuccessor(int value) const;
        bool contains(int value) const;
        int count() const;
        int getSmallest();
        int getLargest();
        string getOriginalValue(int n);
        // void compare(Node* n);

    private:
    
        struct Node{
            int info;
            Node *left, *right, *parent;

            Node(int v=0) : info(v), left(0), right(0), parent(0){}
        };

        Node* root;


        Node* getNodeFor(int value, Node* n) const;
        void clear(Node* n);
        bool insert(int value, Node* n);
        void printPreOrder(Node *n) const;
        void printInOrder(Node* n) const;

        // void compare(Node* n, Node* p);
        Node* getPredecessorNode(int value) const;
        Node* getSuccessorNode(int value) const;
        int count(Node* n) const;
        int getSmallest(Node* n) const;
        int getLargest(Node* n) const;
};


#endif