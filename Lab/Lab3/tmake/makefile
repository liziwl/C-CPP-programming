CC=gcc
CFLAGS=-Wall
INC = -I ./xname -I ./yname
TARGET = lab3_tmake
SRCS = lab3_main.c \
		./xname/x.c \
		./yname/y.c \
		./lab3.h
		
OBJS = $(SRCS:.c=.o) 
#OBJS += lab3.h
$(TARGET) : $(OBJS)
	#echo TARGET:$@
	#echo OBJECTS:$^ 

	#$(CC) $(CFLAGS) $(INC) -o $@ $^
	$(CC) $(CFLAGS)  -o $@ $^

%.o:%.c
	$(CC) $(CFLAGS)  -o $@ -c $^

.PHONY : clean
clean : 
	find . -name "*.o"  | xargs rm -f
	find . -name "*.exe" | xargs rm -f
