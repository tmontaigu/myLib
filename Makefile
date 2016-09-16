CCC = g++
CC_FLAGS = -Wall -ggdb -O0

#------------------------------------------------------------------------------
# Folders where the makefile will look for the sources of the rules.
#------------------------------------------------------------------------------
VPATH = test:obj:src:include:example

#------------------------------------------------------------------------------
# Paths to the .hpp files used
#----------------------------------------------------------------------------
INCLUDES= -I include
#------------------------------------------------------------------------------
# List of files to generate the executables
#------------------------------------------------------------------------------

FILES_CSVFile = main_csv_reader.cpp \
				CSVFile.cpp \
				FileBrowser.cpp \
				FileOperation.cpp 
				
FILES_Demo_Bar = main_demo_bar.cpp \
				ProgressBar.cpp \
				WaitingBar.cpp
				
FILE_Example_MathUtilities = main_MathUtilities.cpp 


#----------------------------Test files----------------------------------------
FILES_Test_FileOperation = TestFileOperation.cpp \
						   FileOperation.cpp 


#------------------------------------------------------------------------------
# List of objects used to generate the executables
#------------------------------------------------------------------------------

OBJS_CSVFile = $(FILES_CSVFile:.cpp=.o)
OBJS_Demo_Bar = $(FILES_Demo_Bar:.cpp=.o)

OBJS_Example_MathUtilities = $(FILE_Example_MathUtilities:.cpp=.o);

OBJS_Test_FileOperation = $(FILES_Test_FileOperation:.cpp=.o)

#------------------------------------------------------------------------------
# Line to compile the executable file
#------------------------------------------------------------------------------
COMPILE_EXECUTABLE = $(CCC) $(CC_FLAGS) -o build/$@ $^ 


default: CSVFile_Reader


CSVFile_Reader: $(patsubst %,obj/%,$(OBJS_CSVFile))
	$(COMPILE_EXECUTABLE)
	@echo Success!

Demo_Bar: $(patsubst %,obj/%,$(OBJS_Demo_Bar))
	$(COMPILE_EXECUTABLE)
	@echo Success!
	
Example_MathUtilities: $(patsubst %,obj/%,$(OBJS_Example_MathUtilities))
	$(COMPILE_EXECUTABLE)
	@echo Success!

Test_FileOperation: $(patsubst %,obj/%,$(OBJS_Test_FileOperation))
	$(COMPILE_EXECUTABLE)
	@echo Success!


obj/%.o: %.cpp
	$(CCC)  $(INCLUDES) $(CC_FLAGS) -c $< -o $@


clean:
	rm obj/* build/*
