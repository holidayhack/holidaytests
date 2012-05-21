default: seasnake
	./seasnake
seasnake: seasnake.o point.o engine.o
	gcc -o seasnake -lncurses obj/seasnake.o obj/point.o obj/engine.o
%.o: %.c
	mkdir -p ./obj
	gcc -fPIC -O -c $< -o obj/$@