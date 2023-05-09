CXX = g++
CXXFLAGS = -std=c++11 -O2

build: slidingBlock.cpp Grid.h Piece.h Movement.h 
	$(if $(filter $(OS),Windows_NT), if exist slidingBlock (del slidingBlock), rm -f slidingBlock)
	$(CXX) $(CXXFLAGS) -o slidingBlock slidingBlock.cpp Grid.h Piece.h Movement.h

run:
	.\slidingBlock.exe '.\Data Files\proj3a.data'

clean:
	rm -f slidingBlock
