.PHONY:clean run format-code

treePrint:treePrint.c
	gcc -o treePrint treePrint.c
clean:
	rm treePrint
run: 
	./treePrint
format-code:
	clang-format-3.8 -i *.c