OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

raices : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o raices

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

clean :
	\rm *.o raices
