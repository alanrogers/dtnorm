vpath %.c ../src

#opt := -DNDEBUG -O3  -finline-functions  # For full optimization
opt :=  -O0 -fno-inline-functions -DDEBUG     # For debugging
#prof := -pg -rdynamic                    # For profiling
prof :=
incl := -I/usr/local/include -I/opt/local/include -I../src
tests := xdtnorm

CC := gcc

# Flags to determine the warning messages issued by the compiler
warn := \
 -Wall \
 -Wcast-align \
 -Wcast-qual \
 -Wmissing-declarations \
 -Wmissing-prototypes \
 -Wnested-externs \
 -Wpointer-arith \
 -Wstrict-prototypes \
 -Wno-unused-parameter \
 -Wno-unused-function \
 -Wshadow \
 -Wundef \
 -Wwrite-strings

CFLAGS := -g -std=gnu99 $(warn) $(incl) $(opt) $(prof) $(osargs)

lib := -L/usr/local/lib -lgsl -lgslcblas -lpthread -lm

.c.o:
	$(CC) $(CFLAGS) -c -o ${@F}  $<

all : $(tests)

test : $(tests)
	-./xdtnorm
	@echo "ALL UNIT TESTS WERE COMPLETED."

XDTNORM := xdtnorm.o dtnorm.o
xdtnorm : $(XDTNORM)
	$(CC) $(CFLAGS) -o $@ $(XDTNORM) $(lib)

EXAMPLE := example.o dtnorm.o
example : $(EXAMPLE)
	$(CC) $(CFLAGS) -o $@ $(EXAMPLE) $(lib)

# Make dependencies file
depend : *.c
	echo '#Automatically generated dependency info' > depend
	$(CC) -MM $(incl) *.c >> depend

clean :
	rm -f *.a *.o *~ gmon.out *.tmp $(targets) $(tests) core.* vgcore.*

include depend

.SUFFIXES:
.SUFFIXES: .c .o
.PHONY: clean

