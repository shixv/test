CC=gcc
CFLAGS= -g -Wall
CPPFLAGS= -I./Headers
LINKSO=-shared -Wl,-soname,
LINKA=ar rs
LIBSO=../libso/
LIBA=../liba/
F5=sudo ldconfig
LINKCURSES= -lncurses


SRC=$(wildcard *)
SRC+= NULL.h
CFILE=$(filter %.c,$(SRC))
HFILE=$(filter %.h,$(SRC))
OBJ=$(patsubst %.c, %.o, $(CFILE))

######################################## exec ###################################

exec:$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LINKCURSES)
%.o:%.c file.i 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
file.i:$(CFILE)
	$(CC) -E $^ > $@
####################################### move .h files ###########################

mvh:
	mkdir Headers
	touch NULL.h
	mv $(HFILE) ./Headers

###################################### create lib.so ###########################

creatso:libcalcu.so
	ln -s $<.1.0 $(LIBSO)$<
	$(RM) *.o
libcalcu.so:$(OBJ) upldconfig
	$(CC) $(LINKSO)$@.1 -o $(LIBSO)$@.1.0 $(OBJ)
	$(F5)
upldconfig:
	sudo echo /home/akaedu/ace/c/date15/makefiletest/libso/ >> /etc/ld.so.conf
%.o:%.c
	$(CC) $(CPPFLAGS) -c $< -o $@
	
##################################### create lib.a #############################

creata:$(OBJ)
	$(LINKA) $(LIBA)libcalcu.a $^
	$(RM) *.o	

#################################### CLEAN        ##############################

.PHONY: cl

cl:
	$(RM) exec *.o NULL.h *.i
	@echo "clean COMPLETED!"
distclean:
	$(RM) exec *.o NULL.h *.i
#	$(RM) ./Headers/*
	@echo "ALL CLEAN!"
display:
