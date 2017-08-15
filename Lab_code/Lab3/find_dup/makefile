CC=g++
CFLAGS=-Wall
TARGET = find_dup
SRCS = progress_bar.cpp \
		lab3_io.cpp \
		lab3_cmp.cpp \
		lab3_main.cpp
		
OBJS = $(SRCS:.cpp=.o)
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
