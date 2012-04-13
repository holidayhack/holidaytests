default:
	gcc -fPIC -O -c heapsort.c -o heapsort.o
	gcc -o heapsort heapsort.o
	./heapsort
	head -4 ./out/output.txt
	@echo ---
	@tail -4 ./out/output.txt
