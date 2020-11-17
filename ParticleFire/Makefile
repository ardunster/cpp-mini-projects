CXX = clang++

CXXFLAGS = -Wall -F /Library/Frameworks
LDFLAGS = -framework SDL2 -F /Library/Frameworks -I /Library/Frameworks/SDL2.framework/Headers

run: main
	./build/main

main: main.cpp
	mkdir -p ./build
	$(CXX) $(LDFLAGS) $(CSSFLAGS) -o ./build/main main.cpp

testrun: test.cpp
	mkdir -p ./build
	$(CXX) $(LDFLAGS) $(CSSFLAGS) -o ./build/test test.cpp
	./build/test

clean:
	rm -r ./build