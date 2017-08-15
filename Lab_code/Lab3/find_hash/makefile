CC=g++
CFLAGS=-Wall
TARGET = find_hash
SRCS = listdir.cpp \
		hashtable.cpp \
		find_hash.cpp 
		
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
