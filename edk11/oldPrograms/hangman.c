/*hangman game: Eric Kahn*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
   int numChar= 0;
   int i, c, d;
   char wordCheck;
   int a=1;
   int b=1;
   
   char *word= (char*)calloc(20, sizeof(char));//holds user's word
   
   printf("Welcome to hangman! ");
   while(a==1){ //within this loop, the word is input, and there the variable 'a' is used as a check to see if the word input is correct
      numChar= 0;
      printf("Please enter your word\n");

//counting number of characters in word as they are read in
      for(d=0; (c= getchar()) != '\n'; d++){
	 if(c>64 && c<91){//Upper case ASCII values are from 65-90 so converts Upper to lowercase
	    c+=32;//converts all input to lower case
	 }
	 word[d]=c;
	 numChar++;
      }
	
      printf("Your word is: %s\nIf this is your word, type 'y'. If this is not your word, type 'n'\n", word);// prints out word for user to see if it is right
	
      b=1;// if loop using var a is repeated, var b will have been set to 0, so it needs to be reset to 1

/* change below to switch statment*/

      while(b==1){//allows user to check if word is correct and only accepts y or n as answers
	 scanf("%c", &wordCheck);
	 getchar();
	 if(wordCheck == 'y' || wordCheck =='Y'){
	    a=0;
	    b=0;
	 }
	 else if(wordCheck == 'n' || wordCheck == 'N'){
	    printf("Please re-type your word\n");
	    b=0;
	 }
	 else{
	    printf("You did not type 'y' or 'n'. Please retry\n");
	 }
      }
   }

   
   for(i=0; i<47; i++){
      printf("\n");
   }
//word has been input and confirmed by user. 47 new lines are addes so the guesser cannot see the word that was input

   int numGuesses = 10;
   char guess;
   char guess2[numChar+1];
   int check;
   int correctGuess;
   int endGame= 0;//used in giant while loop. Set to 1 if it's the end of game, otherwise 0
   int j, k, l, m;
   int z=0;//used to see if there are any "-" left in wordCopy and therefore if game should continue or end
   int w= 0;//keeps track of what position the program is at in the array wrongGuesses, so letters are added to the correct spot
   int x= 0;//keeps track of the position in the array wrongWord so incorrect words are added to the correct spot
   char *wrongWord= (char*)calloc(10*(numChar+1), sizeof(char));//memory to hold incorrect guesses of entire word
   char *wrongGuesses= (char*)calloc(25, sizeof(char));//memory to hold incorrect guesses
   char *wordCopy= (char*)calloc(numChar, sizeof(char));//will be initiated all to underscores to hold copy of the user's word and will be filled in as game progresses
   
   for(j=0; j<numChar; j++){
      if(word[j]==' '){
	 wordCopy[j]=' ';
      }
      else{
	 wordCopy[j]= '-';
      }
   }
   printf("\nPlease start guessing letters one at a time and press enter after each letter.\n");

   while(endGame==0){
      z=0;
      l=0;
      printf("\nYour word so far: %s\n", wordCopy);
      printf("You have %d mistakes left \nYou have already guessed these letters: %s\nYou have already guessed these words: %s\n", numGuesses, wrongGuesses, wrongWord);
      printf("Enter your guess or type '!' if you want to guess the word\n");
      scanf("%c", &guess);
      getchar();
      if((guess>64 && guess<91) || (guess>96 && guess<123)){ //if character is a letter, run normal program
	 if(guess>64 && guess<91){//if letter is capital, convert to lowercase
	    guess+= 32;
	 }
	 correctGuess= 0;
	 for(k=0; k<numChar; k++){//this begins comparing user's guess to letters in the word
	    if(guess== word[k]){
	       wordCopy[k]=guess;
	       correctGuess=1;
	    }
	 }
	 if(correctGuess==0){//if the current guess does not match any letters in the word, and the guess to wrongGuess list and subtract 1 from numGuesses
	    wrongGuesses[w]= guess;
	    numGuesses--;
	    w++;//incremented so next time there is an incorrect guess, letter is put into the correct spot in array wrongGuesses
	 }
	 while(l<numChar && z==0){
	    if(wordCopy[l]=='-'){
	       z=1;
	    }
	    l++;
	 }
	 if(z==1 && numGuesses==0){
	    printf("GAME OVER! The word was: %s", word);
	    endGame=1;
	 }
	 else if(z==0 && numGuesses>0){
	    printf("YOU WIN! The word was: %s", word);
	    endGame=1;
	 }
      }
//Above is if the user guesses a letter and below is if the user guesses the entire word. Giant if, else if statement      
      else if(guess=='!'){//user enters '!' if they want to guess the entire word
	 printf("What word do you want to guess?\n");
	 fgets(guess2, sizeof(guess2), stdin);
	 getchar();
	 if((check= strcmp(word, guess2))==0){
	    printf("YOU WIN! The word was: %s", word);
	    endGame=1;
	 }
	 else{
	    printf("The word is not %s\n", guess2);
	    numGuesses--;
	    for(m=0; m<(numChar+1); m++){
	       if(m==(numChar)){
		  wrongWord[x]=' ';
		  x++;
	       }
	       else{
		  wrongWord[x]=guess2[m];
		  x++;
	       }
	    }
	 }
      }
   }
   free(word);
   free(wrongWord);
   free(wrongGuesses);
   free(wordCopy);
   return 0;
}
