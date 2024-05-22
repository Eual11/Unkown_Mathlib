COMPILE_FLAGS := -g -Wall -Wextra -std=c++17 -O3

all: vectests mattests transform utils

vectests: testvec2 testvec3 testvec4
testvec2: vec2
	g++ $(COMPILE_FLAGS) ./tests/testvec2.cpp -L./lib -lumlvec2  -o ./build/$@ 

testvec3: vec3
		g++ $(COMPILE_FLAGS) ./tests/testvec3.cpp -L./lib -lumlvec3  -o ./build/$@
testvec4: vec4
	g++ $(COMPILE_FLAGS) ./tests/testvec4.cpp -L./lib -lumlvec4 -o ./build/$@
vec4:
	g++ $(COMPILE_FLAGS) -c ./src/vec4.cpp -o ./bin/$@.o
	ar rcs ./lib/libuml$@.a ./bin/$@.o

vec3:
	g++  $(COMPILE_FLAGS) -c ./src/vec3.cpp -o ./bin/$@.o 
	ar rcs ./lib/libuml$@.a ./bin/$@.o
vec2:
	g++ $(COMPILE_FLAGS) -c ./src/vec2.cpp -o ./bin/$@.o
	ar rcs ./lib/libuml$@.a ./bin/$@.o
transform:
	g++ $(COMPILE_FLAGS) -c ./src/transform.cpp -o ./bin/$@.o
	ar rcs ./lib/libuml$@.a ./bin/$@.o
utils:
	g++ $(COMPILE_FLAGS) -c ./src/utils.cpp -o ./bin/$@.o
	ar rcs ./lib/libuml$@.a ./bin/$@.o



##tests for mat3x3 and mat2x2

mattests: testmat3x3 testmat2x2 testmat4x4


testmat4x4:mat4x4 mat3x3
			g++ $(COMPILE_FLAGS) ./tests/testInverse.cpp -L./lib -lumlmat4x4 -lumlvec2  -o ./build/$@
testmat3x3: mat3x3 mat2x2
			g++ $(COMPILE_FLAGS) ./tests/testmat3x3.cpp -L./lib -lumlmat3x3  -o ./build/$@
testmat2x2:mat2x2
				g++ $(COMPILE_FLAGS) ./tests/testmat2x2.cpp -L./lib -lumlmat2x2  -o ./build/$@
mat3x3: vec3 mat2x2
	g++  $(COMPILE_FLAGS) -L./lib  -c ./src/mat3x3.cpp -o ./bin/$@.o 
	ar rcs ./lib/libuml$@.a ./bin/$@.o ./bin/vec3.o ./bin/mat2x2.o ./bin/vec2.o
mat2x2:
	g++  $(COMPILE_FLAGS) -L./lib  -c ./src/mat2x2.cpp -o ./bin/$@.o 
	ar rcs ./lib/libuml$@.a ./bin/$@.o ./bin/vec2.o
mat4x4: vec4 mat3x3
	g++  $(COMPILE_FLAGS) -L./lib  -c ./src/mat4x4.cpp -o ./bin/$@.o 
	ar rcs ./lib/libuml$@.a ./bin/$@.o ./bin/vec4.o ./bin/mat3x3.o ./bin/mat2x2.o ./bin/vec3.o 


testUtils: utils 
		g++ $(COMPILE_FLAGS) ./tests/testUtils.cpp -L./lib -lumlmat4x4 -lumlvec3 -lumlutils  -o ./build/$@
install:
	mkdir -p ${CPLUS_INCLUDE_PATH}/uml
	cp -f ./include/* "${CPLUS_INCLUDE_PATH}/uml"
	cp -f ./lib/* "${C_LIBRARY_PATH}"

