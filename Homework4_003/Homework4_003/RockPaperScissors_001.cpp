//Krystal Maughan
//CSIS 135, Wednesday Night Class Homework #4

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int getComputerChoice();
int getPlayerChoice();
string convertIntToString(int);
bool isTie(int, int);
bool isPlayerWinner(int, int);



int main()
{
	//programme should keep running unless asked to quit
	char userChoice = '\0'; // for initial menu; (for 'p' or 'q' values)

	int userChoice1 = 0; //int version of userChoice
	int computerChoice = 0; //int version of computerChoice

	string ChoiceStringUser; //rock paper scissors version output for user
	string ChoiceStringComputer; //rock paper scissors version output for computer


	srand((unsigned int)time(NULL));

	while (userChoice != 'q')
	{
		cout << endl;
		cout << "ROCK PAPER SCISSORS MENU" << endl;
		cout << "------------------------" << endl;


		cout << "p) Play Game" << endl;
		cout << "q) Quit" << endl;
		cout << "Please enter your choice : " << endl;
		cin >> userChoice; //userchoice is a character! 

		if (userChoice == 'p')
		{

			//if user plays game, proceed to get functions for computer 
			//(both string and int)

			computerChoice = getComputerChoice(); //needs int value to call Function
			userChoice1 = getPlayerChoice(); // needs int value to call Function

			ChoiceStringUser = convertIntToString(userChoice1); //string value of choice
			ChoiceStringComputer = convertIntToString(computerChoice); // string value of choice

			cout << "You chose : " << ChoiceStringUser << endl;
			cout << "The computer chose : " << ChoiceStringComputer << endl << endl;


			//if (either tie, win or lose, based on isTie function, etc

			//if isTie is TRUE, return it's a TIE
			if (isTie(userChoice1, computerChoice))
			{
				cout << " It's a TIE!" << endl;
			}
			//if isPlayer TRUE, return YOU WIN, else, if FALSE, return YOU LOSE
			else if (isPlayerWinner(userChoice1, computerChoice))
			{
				cout << " You WIN!" << endl;
			}
			else
			{
				cout << " Sorry you LOSE!";
				cout << endl << endl;
			}


		}
		if (userChoice1 == 'q'){
		 cout << "You have chosen to quit the program. " << endl;
		cout << "Thank you for using the program!" << endl;
		exit(0);
	}
		

	}
	cout << "You have chosen to quit the program. " << endl;
	cout << "Thank you for using the program!" << endl;

	//system("PAUSE");
	return 0;
}

int getComputerChoice()
{
	int computerChoice = rand() % 3 + 1;
	//should generate a random number 1 through 3
	//if 1: Rock, if 2: Paper, if 3: Scissors
	// return an int and make the function have no arguments
	
	return computerChoice;

	//int should be return value that IS an int
}


int getPlayerChoice()
{
	//user's choice is represented by a number. Similar to getComputerChoice: 1, 2, 3.
	//Do not allow the user to enter an invalid choice; they must enter 1,2,3
	//use integers instead of chars (2)

	int userChoice1 = 0;
	while (userChoice1 < 1 || userChoice1 > 3 || userChoice1 == 0)
	{
		cout << "Rock, Paper or Scissors?" << endl;
		cout << "1) Rock" << endl;
		cout << "2) Paper" << endl;
		cout << "3) Scissors" << endl;
		cout << "Please enter your choice : " << endl << endl;

		cin >> userChoice1;
		// player enters an int


		if (userChoice1 < 1 || userChoice1 > 3)
		{
			cout << "Invalid selection." << endl;
			cout << "Try again." << endl;
			cin >> userChoice1;
		}
		return userChoice1;
	}



}
string convertIntToString(int choice){


	if (choice == 1){
		return "Rock";
	}
	else if (choice == 2){
		return "Paper";
	}
	else if (choice == 3){
		return "Scissors";
	}
	else{
		return "Invalid Choice";
	}
}




bool isTie(int computerChoice, int userChoice1)
{

	//is the computer choice matched with the user's choice? Compare ints
	if ((computerChoice == 1) && (userChoice1 == 1))
	{
		return true;
	}
	else if ((computerChoice == 2) && (userChoice1 == 2))
	{
		return true;
	}
	else if ((computerChoice == 3) && (userChoice1 == 3)){
		return true;
	}
	else if ((computerChoice == userChoice1) && userChoice1 == computerChoice)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isPlayerWinner(int userChoice1, int computerChoice)
{



	//since player choice is not tie, is it a win?
	//go through corresponding numbers for hierarchy of Paper rock and figure out
	//which is win vs lose
	if (userChoice1 == computerChoice)
	{
		return false;
	}

	bool result;

	if ((userChoice1 == computerChoice) && (computerChoice == userChoice1))
	{
		return false;
	}
	else if ((userChoice1 == 1) && (computerChoice == 3))
	{
		return true;
	}
	else if ((userChoice1 == 3) && (computerChoice == 2))
	{
		return true;
	}
	else if ((userChoice1 == 2) && (computerChoice == 1))
	{
		return true;
	}
	else
	{
		return false;
	}

	return result;
}