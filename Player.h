// Rohan Panuganti
// 5/2/17
// Player.h

#include <iostream>
#ifndef PLAYER_H
#define PLAYER_H

/*
  PURPOSE: The purpose of this file is to initialize the Player class.
  This contains all the member functions that are both public and private.
 */
using namespace std;

class Player {

public:
  // constructor
  Player(int num);

  // destructor
  ~Player();

  // PRE: constructor initialized
  // POST: queue will have value 
  void appendPlayer(int num, string nam);

  // PRE: PlayerNode must have nodes
  // POST: the queue will have one less value
  void deletePlayer();

  // PRE: PlayerNode must have nodes
  // POST: the list will be reversed
  void reverseList();

  // PRE: list must be full
  // POST: pairs are swapped
  void pairSwap();

  // PRE: constructor initialized
  // POST: values are displayed
  void printList() const;

  // PRE: constructor initialized
  // POST: bool returned
  bool isEmpty() const;

private:
  struct PlayerNode{
    int value;
    string name;
    PlayerNode *next;
  };

  PlayerNode * head;  //front of the queue
  int n;             // number of nodes
  int m;            //  number of passes
  
};
#endif
