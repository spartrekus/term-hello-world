all: helloterm

helloterm: helloterm.c
	gcc -o helloterm helloterm.c 

clean:
	rm helloterm 
