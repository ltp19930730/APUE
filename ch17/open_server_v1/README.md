### Makefile:
'''
CC=gcc
CFLAGS =-Wall
objects_c = client.o csopen.o recv_fd.o
objects_s = server.o send_fd_uf.o handle_request.o send_err.o 
share = error.o

all : client opend

client : $(objects_c) $(share)
	$(CC) -o client $(objects_c) $(share) $(CFLAGS)

opend : $(objects_s) $(share)
	$(CC) -o opend $(objects_s) $(share) $(CFLAGS)

client.o csopen.o : open.h
recv_fd.o error.o send_fd_uf.o send_err.o : apue.h
server.o handle_request.o : opend.h

.PHONY: clean
clean : 
	rm client $(objects_c)
	rm opend $(objects_s)
	rm $(share)

'''
After make file, ./client to run the client.
