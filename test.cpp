/* This is the console executable, that makes use of the BullCowClaas
This acts as the view in a MVC pattern, and is responsible for all
user action, For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PlayGame();
void PrintIntro();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int32 main(){
	do {
		PrintIntro();
		PlayGame();
	}while (AskToPlayAgain());
	return 0;
}

//int32roduce the game
void PrintIntro(){
	std::cout << "Welcome to bulls and cows" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
}

void PlayGame(){
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	//repeat the guess back to them
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){
		FText Guess = GetGuess();
		
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
	
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << std::endl;
	}
}

//Get the guess from the player
FText GetGuess(){
	EWordStatus Status = EWordStatus::Invalid;
	FText Guess;
	do{
	
	std::cout  << "Try " << BCGame.GetCurrentTry() << ": ";
	std::getline(std::cin,Guess);
	
	Status = BCGame.CheckGuessValidity(Guess);	
	switch (Status){
		case EWordStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EWordStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating characters.\n";
			break;
		case EWordStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			//Guess is vlaid
			break;
	}
	std::cout << std::endl;
	}while (Status != EWordStatus::OK);
	return Guess;
}

bool AskToPlayAgain(){
	std::cout << "Do you want to play again?";
	FText Response;
	std::getline(std::cin,Response);
	if (Response[0] == 'y' || Response[0] == 'Y') return true;
	return false;
}