#include "history.h"
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

List *init_history()
{
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  return list;
}
void add_history(List *list, char *str)
{
  int ident = 1;
  Item *current = list->root;

  while(current->next != NULL){
    current = current->next;
    ident++;
  }
  current->next = malloc(sizeof(Item));
  char *start = word_start(str);
  char *term = word_terminator(start);
  current->next->str = copy_str(start, term-start);
  current->next->id = ident;
}

char *get_history(List *list, int id)
{
  Item *current = list->root;

  while(current != NULL){
    if(current->id == id){
      break;
    }
    current = current->next;
  }
  return current->str;
}

void print_history(List *list)
{
  Item *current = list->root->next;

  while(current != NULL){
    printf("%d. %s\n",current->id, current->str);
    current = current->next;
  }
}

void free_history(List *list)
{
  Item *current = list->root;
  Item *temp;

  while(current != NULL){
    temp = current->next;
    free(current);
    current = temp;
  }
  free(list);
}
