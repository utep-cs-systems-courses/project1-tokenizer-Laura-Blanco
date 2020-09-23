#include "tokenizer.h"
#include <stdio.h>
main()
{
  char str[50];
  printf("$");
  scanf("%[^\n]",str); /* [^\n] tells compilerr to read characters until \n is not found (until you find newline) */
  printf("%s\n",str);
  int saver;
  saver = non_space_char('p');
  printf(saver);
}
  
