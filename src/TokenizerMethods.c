#include "tokenizer.h"
#include <stdio.h>


int space_char(char c)
{
  if((c == ' ') || (c == '\t') && (c != '\0')){
    return 1;
  }
  else{
    return 0;
  }
}

int non_space_char(char c){
  if((c != ' ') && (c != '\t')&& (c != '\0')){
    return 1;
  }
  else{
    return 0;
  }
}

char *word_start(char *str){
  char *p= str;
  // char c = *p;
  while(space_char(*p)){
    p++;
    // c = *p;
  }
  // printf("%c\n",*p);
  return p;
}

char *word_terminator(char *word){
  char *p = word;
  // char c = *p;
  while(non_space_char(*p)){
     p++;
     // c = *p;
  }
  //  printf("%c\n",*p);
  return p;
}

int count_words(char *str){
  int number = 0;
  char *start = word_start(str);
  char *term;
  while(non_space_char(*start)){
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
char *copy_str(char *inStr, short len){
  char *p = inStr;
  return *p;
}
/*
void print_tokens(char**){
}
void free_tokens(char**){
}
char **tokenize(char *s){
  }*/
