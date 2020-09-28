#include "history.h"
#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

List *init_history()
{
  List *list = malloc(sizeof(List)); //allocates memory for a list
  list->root = malloc(sizeof(Item)); //allocates memory for the item in the list
  return list;
}
void add_history(List *list, char *str) 
{
  int ident = 1;
  Item *current = list->root;

  while(current->next != NULL){ //continues until we reach end
    current = current->next; //updates current
    ident++;
  }
  current->next = malloc(sizeof(Item)); //allocates memory for item
  char *term = word_terminator(str);
  current->next->str = copy_str(str, term-str); //sets the item value str but gets a copy of it
  current->next->id = ident; //sets id for item
}

char *get_history(List *list, int id)
{
  Item *current = list->root;

  while(current != NULL){ //traverses through entire list until it finds the id that macthes
    if(current->id == id){ //compares current id to id parameter if it matches we retur it
      return current->str;
    }
    current = current->next;
  }
  return "Not found"; //if it doesn't find it it will return this
}

void print_history(List *list)
{
  Item *current = list->root->next; //since I didn't set value to root I skip it

  while(current != NULL){ //as long as cur isnt NULL it continues to end
    printf("%d. %s\n",current->id, current->str); //prints id and str value
    current = current->next;
  }
}

void free_history(List *list)
{
  Item *current = list->root; 
  Item *temp;

  while(current != NULL){
    temp = current->next; //sets temp to the next value of current to save it and not loose it
    free(current);//frees the current 
    current = temp; //sets current to saved temp
  }
  free(list); //frees the entire list
}
