.SUFFIXES: .c .cpp .o .x .h

DIR = `basename $(CURDIR)`

NAME1 = 5A
NAME2 = producent
NAME3 = konsument

PROG1def = producent
PROG2def = konsument
RFILEdef = wejscie
WFILEdef = wyjscie
FIFOdef = myfifo

EXEC1  = $(NAME1).x
OBJS1  = $(NAME1).o

EXEC2  = $(NAME2).x
OBJS2  = $(NAME2).o

EXEC3  = $(NAME3).x
OBJS3  = $(NAME3).o

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

$(EXEC2): $(OBJS2) $(LIBS2) 
	$(LD) -o $@ $(LFLAGS) $^

$(EXEC3): $(OBJS3) $(LIBS3) 
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3)

program: $(EXEC1) $(EXEC2) $(EXEC3)
	./$(EXEC1) $(PROG1) $(PROG2) $(FIFO) $(RFILE) $(WFILE)
	bash -c "diff -s $(RFILE) $(WFILE)"

programdef: $(EXEC1) $(EXEC2) $(EXEC3)
	./$(EXEC1) $(PROG1def) $(PROG2def) $(FIFOdef) $(RFILEdef) $(WFILEdef)
	bash -c "diff -s $(RFILEdef) $(WFILEdef)"

producent: $(EXEC2)
	./$(EXEC2) $(FIFOdef) $(RFILEdef)

konsument: $(EXEC3)
	./$(EXEC3) $(FIFOdef) $(WFILEdef)
	bash -c "diff -s $(RFILEdef) $(WFILEdef)"

rmfifo:
	rm -f myfifo
mkfifo:
	mkfifo myfifo

.PHONY: clean tar
clean:                                                     
	rm -f *.o  *~ *.a *.so *.x core core* a.out; rm -rf ${LIB_DIR}
	
tar: clean rmfifo
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )

