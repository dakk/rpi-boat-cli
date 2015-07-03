all:
	gcc -c main.c -o main.o
	gcc -c boat.c -o boat.o -I/usr/local/include
	gcc boat.o main.o -lwiringPi -o boatcli


clean:
	rm *.o
