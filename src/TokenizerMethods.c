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
  char *p = str;
  while(space_char(p)){
    p++;
  }
  return *p;
}

char *word_terminator(char *word){
  char *p = word
  /* possibly use word count here?? */ 
   while(non_space_char(p)){
      p++;
    }
    return *p;
    }

int count_words(char *str){
  return 0;

  
  }
