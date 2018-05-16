CC=gcc
CFLAGS =-Wall
objects_c = client.o csopen.o recv_fd.o cli_conn.o
objects_s = server.o send_fd_uf.o loop.o handler.o send_err.o server_handler.o errorlog.o daemonize.o serv_accept.o serv_listen.o#loop_poll.o
share = error.o

all : client opend

client : $(objects_c) $(share)
	$(CC) -o client $(objects_c) $(share) $(CFLAGS)

opend : $(objects_s) $(share)
	$(CC) -o opend $(objects_s) $(share) $(CFLAGS)

client.o csopen.o : open.h
recv_fd.o error.o send_fd_uf.o send_err.o cli_conn.o errorlog.o daemonize.o loop.o serv_accept.o serv_listen.o: apue.h
server.o handler.o server_hander.o loop.o: opend.h

.PHONY: clean
clean : 
	rm client $(objects_c)
	rm opend $(objects_s)
	rm $(share)
