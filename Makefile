CCC = g++
CC_FLAGS = -Wall -ggdb -O0

#------------------------------------------------------------------------------
# Folders where the makefile will look for the sources of the rules.
#------------------------------------------------------------------------------
VPATH = test:obj


#------------------------------------------------------------------------------
# List of files to generate the executables
#------------------------------------------------------------------------------

FILES_CSVFile = main_csv_reader.cpp \
				CSVFile.cpp \
				FileBrowser.cpp \
				FileOperation.cpp 


#----------------------------Test files----------------------------------------
FILES_Test_FileOperation = TestFileOperation.cpp \
						   FileOperation.cpp 


#------------------------------------------------------------------------------
# List of objects used to generate the executables
#------------------------------------------------------------------------------

OBJS_CSVFile = $(FILES_CSVFile:.cpp=.o)

OBJS_Test_FileOperation = $(FILES_Test_FileOperation:.cpp=.o)

#------------------------------------------------------------------------------
# Line to compile the executable file
#------------------------------------------------------------------------------
COMPILE_EXECUTABLE = $(CCC) $(CC_FLAGS) -o build/$@ $^ 


default: CSVFile_Reader


CSVFile_Reader: $(patsubst %,obj/%,$(OBJS_CSVFile))
	$(COMPILE_EXECUTABLE)
	@echo OK


Test_FileOperation: $(patsubst %,obj/%,$(OBJS_Test_FileOperation))
	$(COMPILE_EXECUTABLE)
	@echo OK


obj/%.o: %.cpp
	$(CCC)  $(CC_FLAGS) -c $< -o $@


clean:
	rm obj/* build/*
