# CXX = g++

# # This is the compiler links
# CXXLINKS = -g -Wall -Wextra -Wpedantic

# # This is the compiler flag
# CXXFLAG = -c

# # This are the objects dependencies file
# OBJS = crowd.o 
# # Produce the executable
# .PHONY: all
# all : execute

# execute : Crowd.cpp $(OBJS)
# 	@echo "---------------------------------------"
# 	@echo "Creating the executable for the program"
# 	@echo "---------------------------------------"
# 	$(CXX) $(CXXLINKS) -o $@ $^

# # Produce the test
# # .PHONY: test
# # test : testing

# # testing: test.cpp $(OBJS)
# # 	$(CXX) $(CXXLINKS) -o $@ $^

# %.o : %.cpp
# 	@echo "---------------------------------------"
# 	@echo "Compiling the file $<"
# 	@echo "---------------------------------------"
# 	$(CXX) $(CXXLINKS) $(CXXFLAG) $<

# # For clean up
# .PHONY : clean 
# clean :
# 	@echo "---------------------------------------"
# 	@echo "Clean up $<"
# 	@echo "---------------------------------------"
# 	$(RM) *.o
# 	$(RM) execute
# 	$(RM) testing

# # Dependencies chains
# crowd.o 	: Crowd.cpp

CC = g++
CFLAGS = -g -Wall -Wextra -Wpedantic

SOURCES = Crowd.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = execute

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)