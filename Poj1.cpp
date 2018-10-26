#include <iostream>
#include <time.h>
#include <vector>


using namespace std;

/* Name:Cordale Parker		Course:	CS 231	Project # 1		*/
/* File name:Proj1CP.cpp						Date:2/21/18		*/
/* Computer will select a random word and then prompt the user for a game of hangman */

// Declare all function interfaces
int game(string cw, string uw);

//vector containing all the words the computer can select from
vector<string> words ={"INCREDIBLE","COMPUTATION", "BEAUTY", "SILLY","DANGEROUS", "LAMENT","COMET","AVERAGE",                         
"ILLUMINATION","COMPLICATION","WALLET","SUSTAIN","PAVEMENT","BASEMENT","FOOTBALL","UNIVERSITY","EDUCATION",                       
"EDIBLE","FREEDOM","SHOPPING","SHIPPING","SHRINKING","SWELLING","EXCUSE","DOCUMENT","INCREMENT","CORRECTION",                     
"DETECTION","SPEAKER","TOGETHER","PROGRAMMING","PROLONGING","APPROPRIATE","DIRECTORY","PROJECTION","INTERSECTION"};

//main function 
int main() {
	
	//initialize variable for looping the game at user's request
	string play_again = "";
	
	
	//greet user,explain rules, ask if the user wants to play
	cout << "Welcome to hangman! I have chosen a random word and your job is to guess the word letter by letter! \n";
	cout << "You can only guess incorrectly 10 times. Duplicate guesses count as an incorrect guess! \n";
	cout << "Would you like to play?(y/n) ";
	cin >> play_again;
	
	//loop using the user's input 
	while (play_again == "y"){
		
		//variables in the while loop to choose different words every loop
		int n = words.size();    //an integer of the number of words in the vector of words
		srand(time(NULL));      //uses current computer clock for an initial seed to random # generator
		int p = rand() % n;    //selects a random integer which corresponds to a word in the vector
		string cw= words[p];  //cw (conputer's word) is set to the word in the vector at index [p]
		string uw ;          //initialize uw (user's word)
		
		
	// tells the user the game is starting
	cout << "Let's begin! \n";
	
	// calls the game function and passes the cw and uw variables to it
	game(cw,uw) ;
	
	//prompts the user to repeat the game or to exit
	cout << "Would you like to play again? (y/n) \n ";
	cin >> play_again;
	
}//end of while loop

//says farewell when the user decides to stop playing hangman
cout << "Thanks for playing!";
	return 0;
	
}//end of main


// define all other functions 
int game(string cw, string uw){
	
	//int variables for missed guesses and correct guesses
	int miss = 0;
	int correct = 0;
	
	//uw = cw . makes the user word match in length to the computer word
	uw = cw;
	
	//for loop to replace every character in the userword with a "blank"
	for(int i =0; i<uw.length();i++)
		uw[i] = '_';
		
		//while loop for the main part of hangman game stops when 10 incorrect guesses or entire word guessed
	while((correct < uw.length()) && (miss <10)){
		
		//prompts user for letter input and displays current word with any correctly guessed letters
		cout <<"Enter a letter: ";
		cout<<uw<<" : ";
		char guess;
		cin >>guess;
		
		//converts user input to uppercase to match the words in the vector
		guess = toupper(guess);
		
		//bool value to help count correct or missed guesses
		bool correctguess = false;
		
		//for loop to evaluate guesses
		for (int i = 0; i<uw.length(); i++)
		
			//if and else for evaluating the guess
			if(guess == cw[i]){
				
				//first determines if the guess is a duplicate
				if(uw[i] == cw[i]){
					
					//tells user that the guess is a duplicate and then breaks to repeat from the top of the while loop
					cout<< guess << " was already guessed!";
					break;
					
				//else statement for correct guesses. Also sets correctguess to true to prevent the miss count from increasing
				}else{
				uw[i] = cw[i];
				correct++;
				correctguess = true;
			}//end of else statement
		}//end of if statement
		
	//if statement for incorrect guesses. Increases miss count and tells user the guess is incorrect.	
	if (correctguess == false){
		miss++;
		cout<<guess<<" is not in the word.\n";
		
		//switch for progressive counts of incorrect guesses.
		switch(miss){
			case 1:
				cout << "  O  \n";
				break;
			case 2:
				cout << "  O  \n";
				cout << "  |  \n";
				break;
			case 3:
				cout << "  O  \n";
				cout << "  |  \n";
				cout << " /    \n";
				break;
			case 4:
				cout << "  O   \n";
				cout << "  |   \n";
				cout << " / \\   \n";
				break;
			case 5:
				cout << "  O   \n";
				cout << " /|   \n";
				cout << " / \\  \n";
				break;
			case 6:
				cout << "  O   \n";
				cout << " /|\\  \n";
				cout << " / \\  \n";
				break;
			case 7:
				cout << "  O   \n";
				cout << " /|\\  \n";
				cout << "// \\  \n";
				break;
			case 8:
				cout << "  O   \n";
				cout << " /|\\  \n";
				cout << "// \\\\ \n";
				break;
			case 9:
				cout << "  O   \n";
				cout << " /|\\  \n";
				cout << "// \\\\ \n";
				cout << "/      \n";
				break;
			case 10:
				cout << "  O   \n";
				cout << " /|\\  \n";
				cout << "// \\\\ \n";
				cout << "/   \\ \n";
				break;
		}//switch loop
	}//if loop 
}//while loop

	//if loop that checks if the user has completed the word. If true it compliments the user on winning
	if (correct == uw.length()){
		cout << "\n   Congratulations! You win! \n";

	//else if that checks for too many incorrect guesses. If true it tells the user they have lost and displays the correct word.
	}else if (miss == 10){
		cout << "Sorry! Better luck next time! \n";
		cout <<"The word was: " << cw << " . \n";

	}//end of if and else if statements

return 0;
}//end of game function

