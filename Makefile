all: 
	gcc -o a.out NIC-Link-Status.c

clean:
	rm -rf a.out *.tmp *~