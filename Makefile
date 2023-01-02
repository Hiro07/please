#==========================================
#    Makefile: makefile for please command
#	Copyright 2023
#                 Hiroyuki Kikuchi (hjfk07@gmail.com)
#	Last Modified: 2023/01/02
#==========================================

CC=gcc
CFLAGS=-O -Wall

all: please

please: please.c
	$(CC) $(CFLAGS) -o please please.c

clean:
	rm -f please

distclean: clean