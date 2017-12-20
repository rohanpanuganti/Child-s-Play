// Rohan Panuganti
// 5/2/17
// p2.cpp

/*
  PURPOSE: The purpose of this program is to simulate a game about passing
  a balloon between multiple players.

  INPUT: The number of players and the passes are entered. Then the name
  of each player is entered.

  PROCESS: The data is taken in and a node is created containing the
  players' number and name. The linked list is then reversed. Then it
  is swapped around by pairs. Then the linked list is traversed by the
  the number of passes the user gave. The player next to the player
  holding the balloon is removed. The game goes on until there is
  only one player and that player is declared winner.

  OUTPUT: The list of players reversed and then pair swapped. Then
  the program outputs everytime a player is removed.

 */
#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	int num, pass;
	string name;

    for (int i = 0; i < 25; i++){
      cout << endl;
    }
    
    cout << "Hello and welcome the the balloon passing game."<< endl;
    cout << "The balloon is passed from player to player and the "<< endl;
    cout << "player standing next to the player holding a balloon "<< endl;
    cout << "gets eliminated. The last player standing wins." << endl;
    cout << endl;
    
	cout << "Please enter the number"
         <<  " of players and the number of passes." << endl;

	cout << "Players: "; 
	cin >> num;

	cout << "Passes: ";  
	cin >> pass;
    cin.ignore();
    cout << endl;

    // initialize
    Player p(pass);
    
	for(int i = 0; i < num; i++){
		cout << "Player " << i+1 << " enter your name: ";
		getline(cin,name);
		p.appendPlayer(i+1, name);
	}
    cout << endl;

    // reverse and print
    p.reverseList();
    p.printList();
    cout << endl;

    // pair swap and print
    p.pairSwap();
	p.printList();
    cout << endl;

    // the game
	p.deletePlayer();

    return 0;
}
