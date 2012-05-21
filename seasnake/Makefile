default: seasnake
	./seasnake
seasnake: seasnake.o point.o engine.o
	gcc -o seasnake -lncurses seasnake.o point.o engine.o
%.o: %.c
	gcc -fPIC -O -c $< -o $@