/*Program Name: crap_game.cpp
 *Author: Zain Rajani
 *Created: July 11, 2019
 *Program Statement:
 *A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5 and 6 spots.
 *After the dice have come to rest,the sum of the spots on the two upward faces is calculated.
 *If the sum is 7 or 11 on the first roll, the player wins. If the sum is 2, 3 or 12 on the first roll
 *(called“craps”),the player loses (i.e., the “house” wins). If the sum is 4, 5, 6, 8,9 or 10 on the first roll,
 *then that sum becomes the player’s “point.” To win, you must continue rolling the dice until you
 *“make your point.”. The player loses by rolling a 7 before making the point.
 */
#include <iostream>  // Library Import for standard input and output
#include <fstream>   // Library Import for file operation

using namespace std;  // For using cout,cin, endl,etc usage

int dice_Value()   // Function to generate random numbers from 1-6 and take sum of two dices
{
	return ((rand()%6+1)+(rand()%6+1));
}

void game_Rules(int a) // Function for implementing the game rules
{
	if (a==7||a==11) // sum of two dices if 7 or 11 or first roll win condition
	{
		//Printing statements on console
		cout<<"You have rolled number "<<a<<" on your first roll."<<endl<<endl;
		cout<<"You Win on first roll!"<<endl<<endl;
		ofstream first_win; // Output file operation with object creation
		first_win.open("first_win.txt"); // Creation of file name first_win
		// Writing the below 2 statements in the file
		first_win<<"You have rolled number "<<a<<" on your first roll."<<endl<<endl;
		first_win<<"You Win on first roll!"<<endl<<endl;
		first_win.close(); //Close the opened file
	}
	else  // First Roll Loose condition
	{
		if (a==2||a==3||a==12) // sum of two dices if 2 or 3 or 12
		{
			//Printing statements on console
			cout<<"You have rolled number "<<a<<" on your first roll."<<endl<<endl;
			cout<<"You Loose on first roll!"<<endl<<endl;
			ofstream first_roll_loose; // Output file operation with object creation
			first_roll_loose.open("first_loose.txt"); // Creation of file name first_roll_loose
			// Writing the below 2 statements in the file
			first_roll_loose<<"You have rolled number "<<a<<" on your first roll."<<endl<<endl;
			first_roll_loose<<"You Loose on first roll!"<<endl<<endl;
			first_roll_loose.close(); //Close the opened file
		}
		else  // sum of two dices if 4 or 5 or 6 or 8 or 9 or 10
		{
			//Printing statements on console
			cout<<"You have rolled number "<<a<<" on your first roll."<<endl<<endl;
			cout<<"Your first roll point is "<<a<<"."<<endl<<endl;
			ofstream second_round; // Output file operation with object creation
			second_round.open("second_round.txt");  // Creation of file name second_round
			// Writing the below 2 statements in the file
			second_round<<"You have rolled number "<<a<<" on your first roll."<<endl<<endl;
			second_round<<"Your first roll point is "<<a<<"."<<endl<<endl;
			int sum; // Integer variable to roll second time
			do
			{
				sum=dice_Value(); // Random value generate number on second roll
				cout<<"You have rolled "<<sum<<endl<<endl; // Printing Statements on console and writing file
				second_round<<"You have rolled "<<sum<<endl; // Printing Statements on console and writing file
				if (sum==a) // if new roll is same as first roll
				{
					// Printing Statements on console
					cout<<"You have made your win point"<<endl<<endl;
					// Printing Statements in the opened file
					second_round<<"You have made your win point"<<endl<<endl;
					second_round.close(); //close file
				}
				else if (sum==7)
				{
					// Printing Statements on console
					cout<<"You were not able to make your win point. You Loose!!"<<endl<<endl;
					// Printing Statements in the opened file
					second_round<<"You were not able to make your win point. You Loose!!"<<endl<<endl;
					second_round.close();//close file
				}
			}
			while (a!=sum && sum!=7); // Continue to repeat do till you get 7 or first roll number
		}
	}
}

int main() // Start of the main code
{
	int a; // dice value variable
	char d; // character input storage variable to play the game or no
	time_t tp; //Storing system time value in tp
	srand((int)time(&tp)); //Pseudo random generator taking time as seed
	cout<<"--------WELCOM TO THE CRAP CASINO GAME---------"<<endl<<endl;
	do //Continuous repeating the game until user types N or n (means NO)
	{
		// Printing statements on Console
		cout<<"Do you want to start the game?"<<endl;
		cout<<"Press Y to start and N to quit your chance: ";
		cin>>d;  // Accepting User Inputs
		cout<<endl;
		if (d=='Y' || d=='y') // If user wants to play game
		{
			for (int x=0;x<1;++x)
			{
				a=dice_Value();   // Function Call to generate random values
			}
			game_Rules(a);  // Implement Game rules
		}
		else
			//If User Enters No chance passed to next player
			cout<<"Thank You Visit Again!"<<endl<<"Next Player Please!!"<<endl<<endl;
	}
	while (d!='Y' || d!='y');  //repeat the game till user presses NO
}
