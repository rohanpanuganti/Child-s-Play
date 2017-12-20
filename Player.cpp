// Rohan Panuganti
// 5/2/17
// Player.cpp

#include <iostream>
#include "Player.h"

using namespace std;

Player::Player (int num) {
  n = 0;
  m = num;
  head = nullptr;
}


Player::~Player(){
  PlayerNode * ptrNode = head->next;
  PlayerNode * deleteNode = nullptr;
  m = 0;
  n = 0;
  if(!isEmpty()){
    while(ptrNode->next != head){
      deleteNode = ptrNode;
      ptrNode = ptrNode->next;
      delete deleteNode;
    }
    ptrNode = ptrNode->next;
    delete ptrNode;
    head = nullptr;
  }
}



void Player::deletePlayer(){
  PlayerNode * nodePtr = head;
  PlayerNode * deleteNode = nullptr;
  while(n != 1) {
    for(int i = 0; i < m; i++){
      nodePtr = nodePtr->next;
    }
    deleteNode = nodePtr->next;
    nodePtr->next = deleteNode->next;
    cout <<"Player " << deleteNode->value << ", "
         << deleteNode->name << " has been removed." << endl;
    delete deleteNode;
    n--;
  }
  head = nodePtr;
  cout << endl;
  cout <<"Player " << nodePtr->value << ", "
       << nodePtr->name << " has won!" << endl; 
}

void Player::appendPlayer(int num, string nam){
  
  PlayerNode * nodePtr = nullptr;
  PlayerNode * newPtr = new PlayerNode;
  newPtr->value = num;
  newPtr->name = nam;
  newPtr->next = nullptr;

  if(!head) {
    head = newPtr;
    newPtr->next = head;
    n++;
  }

  else {
    nodePtr = head;
    while(nodePtr->next != head){
      nodePtr = nodePtr->next;
    }
    nodePtr->next = newPtr;
    newPtr->next = head;
    n++;
  }
}

void Player::reverseList() {
  PlayerNode * currNode = head;
  PlayerNode * prevNode = head;
  PlayerNode * nextNode = nullptr;
  
  while (prevNode->next != head) {
    prevNode = prevNode->next;
  }
  while (currNode->next != head) {
    nextNode = currNode->next;
    currNode->next = prevNode;
    prevNode = currNode;
    currNode = nextNode;
  }
  nextNode = currNode->next;
  currNode->next = prevNode;
  prevNode = currNode;
  currNode = nextNode;
  head = prevNode;
}

void Player::pairSwap(){
  PlayerNode * endNode = head;
  while(endNode->next != head){
    endNode = endNode->next;
  }
  endNode->next = nullptr;

  PlayerNode * prevNode = nullptr;
  PlayerNode * currNode = head;
  PlayerNode * nextNode = nullptr;

  head = currNode->next;

  while(currNode && currNode->next){
    nextNode = currNode->next;
    currNode->next = nextNode->next;
    prevNode = currNode->next;
    nextNode->next = currNode;
    if(prevNode && prevNode->next){
      currNode->next = currNode->next->next;
    }
    currNode = prevNode;
  }
  if(n%2 == 1){
    currNode->next = head;
  }
  else {
    nextNode->next->next = head;
  }
}

void Player::printList() const {
  PlayerNode * currNode = head;

  cout << "Player " << currNode->value << ": " << currNode->name << endl;
  currNode = currNode->next;
  
  while(currNode != head){
    cout << "Player " << currNode->value << ": " << currNode->name << endl;
    currNode = currNode->next; 
  }
}

bool Player::isEmpty() const{
  if(!head){
    return true;
  }
  return false;
}
