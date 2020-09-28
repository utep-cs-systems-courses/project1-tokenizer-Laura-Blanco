testTokenizer: UserInterface.o TokenizerMethods.o HistoryMethods.o 
		cc -o testTokenizer UserInterface.o TokenizerMethods.o HistoryMethods.o 

clean:
	rm -f *.o testTokenizer
UserInterface.o: UserInterface.c tokenizer.h history.h

TokenizerMethods.o: TokenizerMethods.c tokenizer.h

HistoryMethods.o: HistoryMethods.c history.h


