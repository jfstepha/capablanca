##
##  fics - An internet chess server.
##  Copyright (C) 1993  Richard V. Nash
##  Copyright (C) 2000  Dan Papasian.  All rights reserved.
##  Copyright (C) Andrew Tridgell 2002
##  Copyright (C) Daniel Dugovic 2013
##
##  This program is free software; you can redistribute it and/or modify
##  it under any terms you see fit as long as this message, the
##  copyright message, and the disclaimer below remain intact.
## 
##
##  This program is distributed in the hope that it will be useful,
##  but WITHOUT ANY WARRANTY; without even the implied warranty of
##  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
##
##
##  This is the Makefile template; see machine dependant config.h for
##  more configuration options.


SHELL = /bin/sh
srcdir = .


CHESSD_CFLAGS = 
CC=gcc

##
##  Where to install FICS
##
PREFIX = /usr/local
exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin

PICFLAG = -fPIC
DYNEXP=-rdynamic

##
##  Binaries and Options to use
##
CFLAGS += $(PICFLAG) -Wall -g -O2 ${CHESSD_CFLAGS}

INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644
LIBS = -ltdb -lm -ldl -lcrypt 
LNFLAGS =  ${LIBS}
CHESSDDIR = ${PREFIX}/chessd

GEN_SRCS=adminproc.c algcheck.c board.c command.c talkproc.c comproc.c \
	formula.c gamedb.c gamedb_old.c gameproc.c config.c \
	lists.c malloc.c reload.c follow.c help.c news.c \
	movecheck.c multicol.c network.c playerdb.c playerdb_old.c ratings.c \
	utils.c variable.c eco.c matchproc.c \
	obsproc.c pending.c gics.c setup.c shutdown.c seekproc.c \
	parsers/parser.c parsers/genparser.c iset.c \
	crypt.c timeseal.c ach.c

SRCS=$(GEN_SRCS) fics_addplayer.c ficsmain.c makerank.c

OBJS=$(GEN_SRCS:.c=.o)

ALL= chessd chessd.so chessd_addplayer makerank

all: ${ALL}

.autoheaders: proto.h vers.h parsers/parse_info.h
	touch .autoheaders

chessd: .autoheaders ficsmain.o
	$(CC) $(DYNEXP) $(CFLAGS) $(LNFLAGS) -o chessd ficsmain.o $(LIBS)

chessd.so: .autoheaders $(OBJS)
	$(CC) -shared -o chessd.so $(OBJS) $(LIBS)

chessd_addplayer: .autoheaders fics_addplayer.o $(OBJS) 
	$(CC) fics_addplayer.o $(CFLAGS) $(OBJS) $(LNFLAGS) -o chessd_addplayer $(LIBS)

makerank: .autoheaders makerank.o 
	$(CC) makerank.o $(OBJS) -o makerank $(LIBS)

depend:
	makedepend -- ${CFLAGS} ${MAKEDEPMORECFLAGS} -- ${SRCS}

proto.h: $(GEN_SRCS)
	awk -f mkproto.awk $(GEN_SRCS) > proto.h

vers.h:
	./vers.sh > vers.h

parsers/parse_info.h: $(shell /bin/ls *.h | sed s/proto.h//g)
	parsers/genstruct.pl -o parsers/parse_info.h $(CC) -E $(CFLAGS) includes.h

clean: 
	rm -f *.o $(OBJS) ${ALL} *~ proto.h vers.h parsers/parse_info.h .autoheaders

distclean: clean
	rm -rf Makefile autoconfig.h config.status config.cache config.log

# useful dependency
command.o: command_list.h

parsers/parser.o: parsers/parse_info.h

# this is needed to handle compilers that insist on putting code in the current
# directory with -c
.c.o:
	$(CC) -c $(CFLAGS) -o $*.o $*.c

install: $(ALL)
	install -d -m0755 ${CHESSDDIR}
	install -d -m0755 ${CHESSDDIR}/bin
	install -d -m0755 ${CHESSDDIR}/lib
	install -m0755 chessd ${CHESSDDIR}/bin
	install -m0755 chessd.so ${CHESSDDIR}/lib
	install -m0755 makerank ${CHESSDDIR}/bin
	install -m0755 chessd_addplayer ${CHESSDDIR}/bin
	install -d -m0755 ${CHESSDDIR}/players
	install -d -m0755 ${CHESSDDIR}/spool
	install -d -m0755 ${CHESSDDIR}/data/admin
	install -d -m0755 ${CHESSDDIR}/data/book
	install -d -m0755 ${CHESSDDIR}/data/help
	install -d -m0755 ${CHESSDDIR}/data/usage
	install -d -m0755 ${CHESSDDIR}/data/messages
	install -d -m0755 ${CHESSDDIR}/data/stats
	install -d -m0755 ${CHESSDDIR}/data/boards/wild
	install -d -m0755 ${CHESSDDIR}/data/boards/capablanca
	install -d -m0755 ${CHESSDDIR}/data/boards/knightmate
	install -d -m0755 ${CHESSDDIR}/data/boards/gothic
	install -d -m0755 ${CHESSDDIR}/data/boards/super
	install -d -m0755 ${CHESSDDIR}/data/boards/crazyhouse
	install -d -m0755 ${CHESSDDIR}/data/boards/fischerandom
	install -d -m0755 ${CHESSDDIR}/data/boards/fr
	install -d -m0755 ${CHESSDDIR}/data/boards/zh
	install -d -m0755 ${CHESSDDIR}/data/boards/shatranj
	install -d -m0755 ${CHESSDDIR}/data/boards/xiangqi
	install -d -m0755 ${CHESSDDIR}/data/boards/shogi
	install -d -m0755 ${CHESSDDIR}/data/boards/caparandom
	install -d -m0755 ${CHESSDDIR}/data/boards/courier
	install -d -m0755 ${CHESSDDIR}/data/boards/fairy
	install -d -m0755 ${CHESSDDIR}/data/boards/great
	install -d -m0755 ${CHESSDDIR}/data/boards/seirawan
	install -d -m0755 ${CHESSDDIR}/data/boards/spartan
	install -d -m0755 ${CHESSDDIR}/games/history
	install -d -m0755 ${CHESSDDIR}/games/journal
	install -d -m0755 ${CHESSDDIR}/games/adjourned
	install -d -m0755 ${CHESSDDIR}/data/stats/player_data
	install -d -m0755 ${CHESSDDIR}/data/lists
	cp -u ${srcdir}/../data/lists/td ${CHESSDDIR}/data/lists
	cp -u ${srcdir}/../data/admin/[a-z]* ${CHESSDDIR}/data/admin
	cp -u ${srcdir}/../data/book/[a-z]* ${CHESSDDIR}/data/book
	cp -u ${srcdir}/../data/help/[a-z]* ${CHESSDDIR}/data/help
	cp -u ${srcdir}/../data/usage/[a-z]* ${CHESSDDIR}/data/usage
	cp -u ${srcdir}/../data/messages/[a-z]* ${CHESSDDIR}/data/messages
	cp -u ${srcdir}/../data/boards/capablanca/* ${CHESSDDIR}/data/boards/capablanca
	cp -u ${srcdir}/../data/boards/gothic/* ${CHESSDDIR}/data/boards/gothic
	cp -u ${srcdir}/../data/boards/knightmate/* ${CHESSDDIR}/data/boards/knightmate
	cp -u ${srcdir}/../data/boards/fischerandom/* ${CHESSDDIR}/data/boards/fischerandom
	cp -u ${srcdir}/../data/boards/shatranj/* ${CHESSDDIR}/data/boards/shatranj
	cp -u ${srcdir}/../data/boards/crazyhouse/* ${CHESSDDIR}/data/boards/crazyhouse
	cp -u ${srcdir}/../data/boards/super/* ${CHESSDDIR}/data/boards/super
	cp -u ${srcdir}/../data/boards/wild/* ${CHESSDDIR}/data/boards/wild
	cp -u ${srcdir}/../data/boards/xiangqi/* ${CHESSDDIR}/data/boards/xiangqi
	cp -u ${srcdir}/../data/boards/shogi/* ${CHESSDDIR}/data/boards/shogi
	cp -u ${srcdir}/../data/boards/courier/* ${CHESSDDIR}/data/boards/courier
	cp -u ${srcdir}/../data/boards/fairy/* ${CHESSDDIR}/data/boards/fairy
	cp -u ${srcdir}/../data/boards/great/* ${CHESSDDIR}/data/boards/great
	cp -u ${srcdir}/../data/boards/caparandom/* ${CHESSDDIR}/data/boards/caparandom
	cp -u ${srcdir}/../data/boards/seirawan/* ${CHESSDDIR}/data/boards/seirawan
	cp -u ${srcdir}/../data/boards/spartan/* ${CHESSDDIR}/data/boards/spartan
	perl -e 'mkdir("${CHESSDDIR}/players/$$_",0755) for ("a".."z")'
	perl -e 'mkdir("${CHESSDDIR}/games/history/$$_",0755) for ("0".."99")'
	perl -e 'mkdir("${CHESSDDIR}/games/journal/$$_",0755) for ("a".."z")'
	perl -e 'mkdir("${CHESSDDIR}/data/stats/player_data/$$_",0755) for ("a".."z")'
	perl -e 'mkdir("${CHESSDDIR}/games/adjourned/$$_",0755) for ("a".."z")'

etags:
	etags *.[ch] */*.[ch]

findglobal:
	nm $(OBJS) | grep ' C '
	nm $(OBJS) | grep ' D '
