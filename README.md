##### Program 2: A Game of Hangman
This program is written in the C++ language. This program runs a simple version of hangman with which you can play along. The purpose for this program is to practice handling constantly changing arrays of data. The data that changes is never consistent as players can guess whatever they want. The main focus of this program is to create a robust system that can handle input that could potentially lead to errors while keeping a game running.
The program has a set array of words to choose from. It challenges the player to a game. If the challenge is accepted the program chooses a word from the array randomly. The program outputs a ui for the player. The ui shows the length of the word represented by underscores along with their current hangman progress. A score is kept of the amount of incorrect guesses. For each incorrect guess the score goes up and a new piece of the hangman is displayed. Once the hangman is fully displayed and the score is at the maximum value, the player loses. If the player manages to guess all the letters in the word without losing, a congratulatory message is displayed for the player. In either case the player is prompted to play again. Only until the player declines the offer to play does the program terminate.
This is the display for the hangman as represented in the program:

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
	}
This is a switch statement that checks for the number of missed guesses (previously referred to as the score). With each missed guess, another piece of the hangman is displayed. When the number of misses finally reaches 10 the entire hangman is displayed, and the player loses.
Arrays are the focus of the logic behind the game. Every word is converted into an array. The player's current guesses are their own array filled with the appropriate amount of blank spaces. The two arrays are referenced against each other as more and more guesses are made. When a correct guess is made the player's array is update to replace the blank spaces with the correct letter. When an incorrect guess is made, the program notifies the player and proceeds to count it as a miss. The end result is a fun little game of hangman.
