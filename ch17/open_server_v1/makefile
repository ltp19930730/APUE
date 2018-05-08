CC=gcc
CFLAGS = -Wall
objects = client.o csopen.o recv_fd.o error.o 

client : $(objects)
	$(CC) -o client $(objects) $(CFLAGS)

client.o csopen.o : open.h
recv_fd.o error.o : apue.h

.PHONY: clean
clean : 
	rm client $(objects)

