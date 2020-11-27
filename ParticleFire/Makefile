CXX = clang++

CXXFLAGS = -Wall -F /Library/Frameworks
LDFLAGS = -framework SDL2 -F /Library/Frameworks -I /Library/Frameworks/SDL2.framework/Headers

run: main
	./build/main

main: main.cpp
	mkdir -p ./build
	$(CXX) $(LDFLAGS) $(CSSFLAGS)  main.cpp window.cpp particle.cpp swarm.cpp -o ./build/main

clean:
	rm -r ./build