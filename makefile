
### 6. Crear `Makefile`

Para facilitar la compilación, se puede crear un Makefile.

```makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC = src/main.cpp src/game.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = arcanoid

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
