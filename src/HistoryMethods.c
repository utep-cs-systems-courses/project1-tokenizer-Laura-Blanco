#include "history.h"
#include <stdio.h>
#include <stdlib.h>

List *init_history()
{
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  return list;
}
void add_history(List *list, char *str)
{
  int id = 1;
  Item *current = list->root;

  while(current->next != 0){
    current = current->next;
    id++;
  }
  current->next = malloc(sizeof(Item));
}
