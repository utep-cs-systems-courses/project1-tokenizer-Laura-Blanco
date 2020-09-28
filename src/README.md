Project 1: Tokenizer
====================
In this program we will ask the user to input a sentence then the program will
tokenize the input. This means we will break apart the sentence word by word
and print it back broken down. In order to do this we will allocate memory for
the pointers that will point to the words. We will also use pointers to find
where each word starts and ends. After the word has been tokenized we will add
it to a linked list. By placing it in a linked list we can access the word
later if the user wishes to see the history of tokenized words.Sidenote
history starts at 1. 

The commands the user can select are q to quit, h to see all the history, !
followed by a number n for example !n to see n specific number in
history. Lastly, there is a command s which will prompt the use to input the
sentence they want to tokenize. Any other input will prompt the user to try
another input as it is invalid. 

