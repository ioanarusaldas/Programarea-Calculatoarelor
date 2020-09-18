default: build
task1.o: task1.c
	gcc -c -Wall  task1.c
task2.o: task2.c
	gcc -c -Wall task2.c
task3.o: task3.c
	gcc -c -Wall task3.c

build: task1.o task2.o task3.o
	gcc -Wall task1.o -o  task1
	gcc -Wall task2.o -o task2
	gcc -Wall task3.o -o task3



run_task1:
	./task1
run_task2:
	./task2
run_task3:
	./task3

clean:
	rm -f *.o
	rm -f task1
	rm -f task2
	rm -f task3
	rm -f *.bmp

