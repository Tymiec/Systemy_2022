.SUFFIXES: .c .cpp .o .x .h

DIR = `basename $(CURDIR)`

NAME1 = powielacz
NAME2 = program
NAME3 = sem

HEADS6 = $(NAME3).h

EXEC1  = $(NAME1).x
OBJS1  = $(NAME1).o

EXEC2  = $(NAME2).x
OBJS2  = $(NAME2).o

OBJS3  = $(NAME3).o

CFLAGS = -Wall -std=c99 -pedantic -pthread
LFLAGS = -Wall -std=c99 -pedantic -pthread

CO = gcc
LD = $(CO)

%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<

%.o: %.c
	$(CO) $(CFLAGS) -c $<

$(EXEC1): $(OBJS1) $(OBJS3) $(LIBS1) 
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC2): $(OBJS2) $(OBJS3) $(LIBS2) 
	$(LD) -o $@ $(LFLAGS) $^


.PHONY: all
all: $(EXEC1) $(EXEC2)

program: $(EXEC1) $(EXEC2)
	./$(EXEC1) $(PROG1) $(NPROCES) $(NCSESION)


.PHONY: clean tar

clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
tar: clean 
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )

