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
  if((c != ' ') || (c != '\t')&& (c != '\0')){
    return 1;
  }
  else{
    return 0;
  }
}

char *word_start(char *str){
  char *p= str;
  char c = *p;
  
  // printf("%p\n",*p);
  // printf("%p\n",*str);
  while(space_char(c)){
    *(p++);
    c = *p;
  }
  printf("%c\n",*p);
  return *p;
}

char *word_terminator(char *word){
  char *p = word;
  char c = *p;
  /* possibly use word count here?? */ 
  while(non_space_char(c)){
     *(p++);
     c = *p;
  }
  printf("%c\n",*p);
  return *p;
}

int count_words(char *str){
  return 0;

  
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
