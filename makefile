# Define executable name
BIN = Computing

# Define source files
SRCS = SharedMain.cpp SharedMemory.cpp Board.cpp Board742.cpp Board752.cpp Trace.cpp Mathematic.cpp

# Define header file paths
INCPATH = -I./

# Define the -L library path(s)
LDFLAGS =-fprofile-arcs -ftest-coverage

# Define the -l library name(s)
LIBS =

# Only in special cases should anything be edited below this line
OBJS      = $(CPP_SRCS:.cpp=.o)
CXXFLAGS  = -g -Wall -ansi -pedantic -fprofile-arcs -ftest-coverage
DEP_FILE  = .depend
GOV       = *.gcno
HTML      = *.html


.PHONY = all clean distclean


# Main entry point
#
all: depend $(BIN)


# For linking object file(s) to produce the executable
#
$(BIN): $(OBJS)
	@echo Linking $@
	@$(CXX) $(SRCS) $(LDFLAGS) $(LIBS) -o $@


# For compiling source file(s)
#
.cpp.o:
	@echo Compiling $<
	@$(CXX) -c $(CXXFLAGS) $(INCPATH) $<


# For cleaning up the project
#
clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) $(BIN)
	$(RM) $(DEP_FILE)
	$(RM) $(GOV)
	$(RM) $(HTML)


# For determining source file dependencies
#
depend: $(DEP_FILE)
	@touch $(DEP_FILE)

$(DEP_FILE):
	@echo Generating dependencies in $@
	@-$(CXX) -E -MM $(CXXFLAGS) $(INCPATH) $(SRCS) >> $(DEP_FILE)

ifeq (,$(findstring clean,$(MAKECMDGOALS)))
ifeq (,$(findstring distclean,$(MAKECMDGOALS)))
-include $(DEP_FILE)
endif
endif

gcov:
	gcovr -r . --html -o coverage.html --html-details
