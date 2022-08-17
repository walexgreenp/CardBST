//cards.cpp
//Authors: William Greenwald
//Implementation of the classes defined in cards.h

#include "cards.h"
#include <iostream>

using std::cout;

// constructor
Hand::Hand() : root(nullptr) { 
    
}

Hand::~Hand(){
    clear(root);
}

void Hand::clear(Node* n){
    if(n){
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

// Insert Function
bool Hand::insert(int value) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(value);
	return true;
    }
    // otherwise use recursive helper
    return insert(value, root);
}
bool Hand::insert(int value, Node *n) {
    if (value == n->info)
	return false;
    if (value < n->info) {
	if (n->left)
	    return insert(value, n->left);
	else {
	    n->left = new Node(value);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if (n->right)
	    return insert(value, n->right);
	else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	}
    }
}

void Hand::printPreOrder() const {
    printPreOrder(root);
}
void Hand::printPreOrder(Node *n) const {
    if (n) {
	    cout << n->info << " ";
	    printPreOrder(n->left);
	    printPreOrder(n->right);
    }
}

void Hand::printInOrder() const{
    printInOrder(root);
}
void Hand::printInOrder(Node* n) const{
    if(n == nullptr){
        return;
    }
    printInOrder(n->left);
    cout << n->info << " ";
    printInOrder(n->right);
}

string Hand::getOriginalValue(){
   return getOriginalValue(root->info);
}
string Hand::getOriginalValue(int n){
    string returnVal = "";
    if(n < 150){
        returnVal.append("c ");
        n = n % 100;
    }
    else if(n < 250){
        returnVal.append("d ");
        n = n % 200;
    }
    else if(n < 350){
        returnVal.append("s ");
        n = n % 300;
    }
    else{
        returnVal.append("h ");
        n = n % 400;
    }

    if(n == 1){
        returnVal.append("a");
    }
    else if(n == 2){
        returnVal.append("2");
    }
    else if(n==3){
        returnVal.append("3");
    }
    else if(n == 4){
        returnVal.append("4");
    }
    else if(n == 5){
        returnVal.append("5");
    }
    else if(n == 6){
        returnVal.append("6");
    }
    else if(n == 7){
        returnVal.append("7");
    }
    else if(n == 8){
        returnVal.append("8");
    }
    else if (n == 9){
        returnVal.append("9");
    }
    else if (n == 10){
        returnVal.append("10");
    }
    else if (n == 11){
        returnVal.append("j");
    }
    else if (n == 12){
        returnVal.append("q");
    }
    else if (n == 13){
        returnVal.append("k");
    }

    return returnVal;
}

Hand::Node* Hand::getNodeFor(int value, Node* n) const{
    if(!n){
        return nullptr;
    }
    else if(n->info == value){
        return n;
    }
    else if(value < n->info){
        return getNodeFor(value, n->left);
    }
    else{
       return getNodeFor(value, n->right);
    }
}

bool Hand::remove(int value){
    Node* currentNode = getNodeFor(value, root); //Start at root
    Node* parent = currentNode->parent; //Making a parent node because we'll change it later

    // 2 Null
    if(currentNode->left == nullptr && currentNode->right == nullptr) {
        if(parent == nullptr){ 
            root = nullptr;
        }
        else if (parent->left == currentNode){ 
            parent->left = nullptr;
        }else{
            parent->right = nullptr;
        }
        delete currentNode;
        return true; 
    }

    // 1 Null
    else if(currentNode->left && currentNode->right == nullptr) { 
        if(parent == nullptr) {
            root = currentNode->left; 
            root->parent = nullptr;
        }
        else if(parent->left == currentNode) {
            parent->left = currentNode->left; 
            currentNode->left->parent = parent;
        }else{
            parent->right = currentNode->left;
            currentNode->left->parent = parent;
        }
        delete currentNode;
        return true;
    }

    else if(currentNode->right && currentNode->left == nullptr) { 
        if(parent == nullptr) { 
            root = currentNode->right;
            root->parent = nullptr;
        }
        else if(parent->left == currentNode) {
            parent->left = currentNode->right;
            currentNode->right->parent = parent;

        }else{
            parent->right = currentNode->right;
            currentNode->right->parent = parent;
        }
        delete currentNode;
        return true;
    } 

    // 2 children
    else {
        Node* successor = getSuccessorNode(value);
        int tempSuccessorValue = successor->info;
        remove(successor->info);
        currentNode->info = tempSuccessorValue;
        return true;
    }

    return false; 
}

Hand::Node* Hand::getPredecessorNode(int value) const{
    Node* n = getNodeFor(value, root);
    if(n == nullptr){
        return nullptr;
    }
    if(root == nullptr){
        return nullptr;
    }

    if(n->left){    
        n = n->left;
        while(n->right){
            n = n->right;
        }
        return n;
    }

    else{
        while(n->parent){
            if(n->parent->info < value){
                return n->parent;
            }
            n = n->parent;
        }
    }

    return n->parent; // REPLACE THIS NON-SOLUTION
}
int Hand::getPredecessor(int value) const{
    return (getPredecessorNode(value)) ? getPredecessorNode(value)->info  : 0;
}

Hand::Node* Hand::getSuccessorNode(int value) const{
    Node* n = getNodeFor(value, root);

    if(n == nullptr){
        return nullptr;
    }

    if(root == nullptr){
        return nullptr;
    }

    if(n->right){
        n = n->right;
        while(n->left){
            n = n->left;
        }
        return n;
    }

    else{
        while (n->parent){
            if(n->parent->info > value){
                return n->parent;
            }
            n = n->parent;
        }
    }

    return n->parent; // REPLACE THIS NON-SOLUTION
}
int Hand::getSuccessor(int value) const{
    return (getSuccessorNode(value)) ? getSuccessorNode(value)->info  : 0;
}

bool Hand::contains(int value) const {
    return (getNodeFor(value, root) != nullptr); // REPLACE THIS NON-SOLUTION
}

int Hand::count() const {
    return count(root);
}
int Hand::count(Node *n) const {
    
    if(n == nullptr){
        return 0;
    }
    else{
        return 1 + count(n->left) + count(n->right);
    } // REPLACE THIS NON-SOLUTION
}

int Hand::getSmallest(){
    return getSmallest(root);
}
int Hand::getSmallest(Node* n) const{
    if(n->left == nullptr){
        return n->info;
    }
    else{
        n = n->left;
        return getSmallest(n);
    }
}

int Hand::getLargest(){
    return getLargest(root);
}
int Hand::getLargest(Node* n) const{
    if(n->right == nullptr){
        return n->info;
    }
    else{
        n = n->right;
        return getLargest(n);
    }
}