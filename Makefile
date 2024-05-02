COMPILE_FLAGS := -g -Wall -Wextra -std=c++17

all: tests

tests: testvec2 testvec3 testvec4
testvec2: vec2
	g++ $(COMPILE_FLAGS) ./src/testvec2.cpp -L./lib -lvec2  -o ./build/$@ 

testvec3: vec3
		g++ $(COMPILE_FLAGS) ./src/testvec3.cpp -L./lib -lvec3  -o ./build/$@
testvec4: vec4
	g++ $(COMPILE_FLAGS) ./src/testvec4.cpp -L./lib -lvec4 -o ./build/$@
vec4:
	g++ $(COMPILE_FLAGS) -c ./src/vec4.cpp -o ./bin/$@.o
	ar rcs ./lib/lib$@.a ./bin/$@.o

vec3:
	g++  $(COMPILE_FLAGS) -c ./src/vec3.cpp -o ./bin/$@.o 
	ar rcs ./lib/lib$@.a ./bin/$@.o
vec2:
	g++ $(COMPILE_FLAGS) -c ./src/vec2.cpp -o ./bin/$@.o
	ar rcs ./lib/lib$@.a ./bin/$@.o
