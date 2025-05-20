CXX = g++
CXXFLAGS = -Wall -Iinclude

SOURCES = src/Book.cpp src/LibraryException.cpp src/LibraryItem.cpp src/LibrarySystem.cpp src/Magazine.cpp src/User.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = library_system

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXECUTABLE)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	del /Q src\Book.o src\LibraryException.o src\LibraryItem.o src\LibrarySystem.o src\Magazine.o src\User.o main.o del /Q logs\transactions.txt  $(EXECUTABLE) $(EXECUTABLE).exe

run: $(EXECUTABLE)
	$(EXECUTABLE).exe