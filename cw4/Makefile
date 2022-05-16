.SUFFIXES: .c .cpp .o .x .h

DIR = `basename $(CURDIR)`

NAME1 = 4A

EXEC1  = $(NAME1).x
OBJS1  = $(NAME1).o

CFLAGS = -Wall -std=c99 -pedantic
LFLAGS = -Wall -std=c99 -pedantic

CO = gcc
LD = $(CO)


%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<

%.o: %.c
	$(CO) $(CFLAGS) -c $<

$(EXEC1): $(OBJS1) $(LIBS1) 
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: all
all: $(EXEC1)


program: $(EXEC1)
	./$(EXEC1) $(RFILE) $(WFILE)
	bash -c "diff -s $(RFILE) $(WFILE)"


.PHONY: clean tar

clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
	
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )

