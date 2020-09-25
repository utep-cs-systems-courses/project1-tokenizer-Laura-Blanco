#include "tokenizer.h"
#include <stdio.h>
int main()
{
  char str[50];
  printf("$");
  scanf("%[^\n]",str); /* [^\n] tells compilerr to read characters until \n is not found (until you find newline) */
  printf("%s\n",str);
  int savedF = space_char(' ');
  /*printf("%d\n", savedF);
  savedF = space_char('\0');
  printf("%d\n", savedF);
  savedF = space_char('\t');
  printf("%d\n", savedF);*/
  char *str1 = "  happy";
  word_start(str1);
  // count_words(str1);
  // str1 = "happy  ";
  // count_words(str1);
  copy_str(str1,5);
  
}
  
