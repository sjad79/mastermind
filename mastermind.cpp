//SAJJAD 55265318

#include <iostream>
#include <ctime>
using namespace std;

void mMtest() { //this is void function
	int rand4[4], guess[4], testrand4[4]; //the arrays to store 4 random int digits, users guess and copy of the 4 random digits respectively
	int round = 1; //to start with round 1

	for (int i = 0; i <= 3; i++) //for generating 4 random digits and assign it into array rand4[]
		rand4[i] = rand() % 6 + 1; // we want digits 1-6 only

	cout << "Mastermind (For checking: ";

	for (int i = 0; i <= 3; i++) //tell you the 4 random digits, the correct answer, only for this homework
		cout << rand4[i];
	cout << ")" << endl;
	cout << endl;

	cout << "Enter four digits (1-6) seperated by a space" << endl;
	cout << "--------------------------------------------" << endl;


	while (true) { //this is to loop until user guess the correct answer
		//no. of hashes and circles 0 in the start and will be 0 for every loop
		int hash = 0;
		int circle = 0;

		for (int i = 0; i <= 3; i++) //get a duplicate of the original array to not corrupts it throughout the game
			testrand4[i] = rand4[i];

		cout << "Round " << round << ":" << endl;
		cout << "Enter Guess:  ";

		for (int i = 0; i <= 3; i++) //to get user's 4 digits guess
			cin >> guess[i];

		for (int i = 0; i <= 3; i++) { //this is to get circles "O", if the position and the value of the integer is the same 
			if (testrand4[i] == guess[i]) {
				circle++; //count "O"
				testrand4[i] = 0; //if the position and the value of the integer is the same, both the digits which are the same will become 0, as a way to indirectly remove the digits from the array
				guess[i] = 0;
			}
		}
		//this is to get hashes "#", if the digits are equal but only the position is not the same 
		for (int t = 0; t <= 3; t++) { //this loop is to scan through the duplicate of the array of the correct answer
			for (int i = 0; i <= 3; i++) { //this loop is to scan through the user's guess array
				if (testrand4[t] == 0 || guess[i] == 0) {
					t++;
					t--; //skip if the digits are equal to 0 or in other words already taken
				}
				else if (testrand4[t] == guess[i]) { //if they are equal regardless of the position
					hash++; //count "#"
					testrand4[t] = 0; //if the digits are equal regardless of their position, make them 0. so to remove them from the array
					guess[i] = 0;
				}
			}
		}

		for (int i = 0; i < circle; i++) //to print first the "O"s
			cout << "O";
		for (int i = 0; i < hash; i++) //to print "#" after that
			cout << "#";

		cout << endl;
		cout << "--------------------------------------------" << endl;

		if (circle == 4) { //when the user guess the correct answer the following statement is printed with the total no of rounds
			cout << "Congratulations! You win the game in " << round;
			cout << (round > 1 ? " steps" : " step") << endl; //print wether 1 step or more than 1 steps
			break;
		}

		else
			round++; // the round no will keep on increasing by 1
	}
}

int main() { //main function
	srand(time(NULL)); //to generate random 

	mMtest(); //the function to play mastermind

	system("pause"); //pause the screen
	return 0;
}