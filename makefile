
OBJS	= stdMain.o 
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
DEPS	= fileInputOutput.h studentInfo.h 

all: stdMain

stdMain: $(OBJS)
	$(CC) $(CCFLAGS) -o stdMain stdMain.cpp fileInputOutputImp.cpp studentInfoImp.cpp $(DEPS)

# -----
# clean by removing object files.

clean:
	rm *.o stdMain
