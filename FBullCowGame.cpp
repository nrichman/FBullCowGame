#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset(){
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

bool FBullCowGame::IsGameWon() const {
	return bGameIsWon;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const{
	if (false){
		return EWordStatus::Not_Isogram;
	}
	else if (false){
		return EWordStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength() ){
		return EWordStatus::Wrong_Length;
	}
	else {
		return EWordStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess){
	MyCurrentTry++;
	
	FBullCowCount BullCowCount;
	
	for (int32 i = 0; i < MyHiddenWord.length(); i++){
		 for (int32 j=0 ; j < MyHiddenWord.length(); j++){
		 	if (Guess[i] == MyHiddenWord[j]) {
		 		if (i == j) BullCowCount.Bulls++;
		 		else BullCowCount.Cows++;
		 	}
		 }
	}
	if (BullCowCount.Bulls == GetHiddenWordLength()){
		bGameIsWon = true;
	} else { 
	    bGameIsWon = false;
	}
	return BullCowCount;
}