.SUFFIXES: .c .cpp .o .x .h

DIR = Zestaw_2

NAME1 = obsluga
NAME2 = wysylaj
NAME3 = grupa

EXEC1 = $(NAME1).x  
OBJS1 = $(NAME1).o

EXEC2 = $(NAME2).x
OBJS2 = $(NAME2).o

EXEC3 = $(NAME3).x
OBJS3 = $(NAME3).o

HEADS1 = 
HEADS2 = 
HEADS3 = 

LIBS1 =  
LIBS2 =
LIBS3 = 

###############################################
CFLAGS = -Wall -O 
LFLAGS = -Wall -O

LDLIBS = -lm

CO = gcc
LD = $(CO)

AR = ar

ARFLAGS = rv
###############################################
%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<

%.o: %.c
	$(CO) $(CFLAGS) -c $<

.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3)

###############################################
# Program 1 : obsluga
$(EXEC1): $(OBJS1) $(LIBS1) 
	$(LD) -o $@ $(LFLAGS) $^

#$(OBJS1): $(HEADS1)

###############################################
.PHONY: obsluga
###############################################
# Uruchom program $(EXEC1);
obsluga: $(EXEC1)
	./$(EXEC1)
	
###############################################
#Program 2 : wysylaj
$(EXEC2): $(OBJS2) $(LIBS2) 
	$(LD) -o $@ $(LFLAGS) $^ $(LDLIBS)

$(OBJS2): $(HEADS1)

###############################################
.PHONY: wysylaj
###############################################
# Uruchom program $(EXEC2); 
wysylaj: $(EXEC2)
	./$(EXEC2)
	
###############################################
#Program 3 : grupa
$(EXEC3): $(OBJS3) $(LIBS3) 
	$(LD) -o $@ $(LFLAGS) $^ $(LDLIBS)

.PHONY: grupa
###############################################
# Uruchom program $(EXEC3); 
grupa: $(EXEC3)
	./$(EXEC3)

###############################################

.PHONY: clean tar
clean:
	rm -f *.o  *~ *.a *.x core core* a.out
# Archiwizacja i kompresja
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )
