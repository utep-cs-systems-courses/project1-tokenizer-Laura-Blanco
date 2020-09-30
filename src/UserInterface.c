#include "tokenizer.h"
#include <string.h>
#include <stdio.h>
#include "history.h"

int main()
{
  char str[75]; //array
  List *list = init_history();
  
  printf("Welcome\n");

  while(1){ //infinite while loop until break
    printf("Select from the following options:\n");
    printf("Input s to enter a sentence\n");
    printf("Or input h to see all history\n");
    printf("Or input !n where n is a number to retireve a specific history\n");
    printf("Or input q to quit\n");
    printf("$");
    fgets(str, 75, stdin);

    if(str[0] == 'h'){ //check if the first char in the array is h if it is it prints history
      print_history(list);
    }
    else if (str[0] == 'q'){ //if the first char is q then it quits
      free_history(list); //frees any history
      printf("Goodbye\n");
      break; //breaks out of loop
    }
    else if (str[0] == '!'){ //if the first char is the ! it will find a specific history
      int i = str[1] - '0'; //converts the second char in array to int
      printf("%s\n",get_history(list,i)); //prints what history returns
    }
    else if( str[0] == 's'){ //if the option is s then it will tokenize the sentence
      printf("Enter sentence\n");
      fgets(str,75,stdin);
      char **tokens = tokenize(str); //calls the tokenize function with str input by user
      print_tokens(tokens); 
      add_history(list, str);
      free_tokens(tokens); 

    }
    else{
      printf("\nUnrecognized option, please try again\n");
    }
    printf("\n");
   }
}
    
      
      
      /*      
  char str[50];
  printf("$");
  scanf("%[^\n]",str); // [^\n] tells compilerr to read characters until \n is not found (until you find newline) 
  printf("%s\n",str);
  int savedF = space_char(' ');
  //printf("%d\n", savedF);
 // savedF = space_char('\0');
 // printf("%d\n", savedF);
 // savedF = space_char('\t');
 // printf("%d\n", savedF);
  char *str1 = " happy happy  joy  joy ";
  char **tokens = tokenize(str1);
  print_tokens(tokens);
  // printf("%s\n", tokens[0]);
  // printf("%s\n", tokens[1]);
  // printf("%s\n", tokens[2]);
  // printf("%s\n", tokens[3]);
  // word_start(str1);
  // count_words(str1);
  // str1 = "happy  ";
  // count_words(str1);
  // copy_str(str1,5);
  List *list = init_history();
  add_history(list,"happy");
  print_history(list);
  add_history(list,"joyful");
  print_history(list);
  
  } */
