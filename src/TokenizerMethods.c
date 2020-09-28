#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

int space_char(char c)
{
  if((c == ' ') || (c == '\t') && (c != '\0')){  //checks that the character is space
    return 1;
  }
  else{
    return 0;
  }
}

int non_space_char(char c){ //checks that character is not a space
  if((c != ' ') && (c != '\t')&& (c != '\0')){
    return 1;
  }
  else{
    return 0;
  }
}

char *word_start(char *str){ //returns a pointer to the start of the string input
  char *p= str;
  // char c = *p;
  while(space_char(*p)){
    p++;
    // c = *p;
  }
  // printf("%c\n",*p);
  return p;
}

char *word_terminator(char *word){ //returns a pointer to the end of string input
  char *p = word;
  // char c = *p;
  while(non_space_char(*p)){
     p++;
     // c = *p;
  }
  //  printf("%c\n",*p);
  return p;
}

int count_words(char *str){ //counts the words in a string
  int number = 0;
  char *start = word_start(str);  //makes sure the string starts at a char
  char *term;
  while(non_space_char(*start)){ //continues until the start is space
    number++;
    term = word_terminator(start);
    if((*term) == '\0'){
      break;
    }
    start = word_start(term);
  }
  // printf("%d\n", number);  
  return number;
}


char *copy_str(char *inStr, short len){ //returns a copy of the string inputted
  char *p = malloc((len+1)* sizeof(char)); //allocates space for word
  char *start = word_start(inStr); 
  int i = 0;
  for(;non_space_char(*start);start++){
    *(p+i) = *start; //increments the address of p to place value in correct place
    i++;
    // printf("%s\n", p);
    // printf("%s\n", start);
  }
  // char *p = inStr;
  return p;
}
void print_tokens(char **tokens){ 
  int i = 0;
  while(tokens[i] != NULL){ //continues until end of tokens
    printf("%s\n", tokens[i]);
    i++;
  }
}
void free_tokens(char **tokens){ 
  int i = 0;
  while(tokens[i] != NULL){ //continues until end of tokens
    free(tokens[i]);
    i++;
  }
  free(tokens);
} 
char **tokenize(char *s)
{
  int noWords = count_words(s); //counts the words in s
  char **str1 = malloc((noWords+1) * sizeof(char *)); // allocates space for all words 
  char *start = word_start(s);
  char *term = word_terminator(start);
  for(int i = 0; i < noWords; i++){
    str1[i] = copy_str(start, term-start); //sets value of str to a pointer to str
    start = word_start(term);
    term = word_terminator(start);
  }
  str1[noWords] = NULL; //sets last index to NULL to determine when we have reached end
  return str1;
  
  }
