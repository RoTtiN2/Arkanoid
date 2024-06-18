bin/tui :  src/tui_test.cpp
	g++ src/tui_test.cpp -o bin/tui -I include -lftxui-screen -lftxui-dom -lftxui-component -std=c++2a

run : bin/tui
	./bin/tui

bin/grid :  src/grid_test.cpp
	g++ src/grid_test.cpp -o bin/grid -I include -lftxui-screen -lftxui-dom -lftxui-component -std=c++2a

runGrid : bin/grid
	./bin/grid