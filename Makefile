#
# Basic Makefile
#

CC=g++
LD=$(CC)
CPPFLAGS=-g -Wall -std=c++11


LDFLAGS=-L/usr/local/lib -L/System/Library/Frameworks/OpenGL.framework/Libraries \
	-lGL -lGLEW -lglfw3 -lSDL2 -lSDL2_image\
	-lX11 -lXxf86vm -lpthread -lXi -lXrandr

# On Ubuntu, SDL2 is located in /usr/include/SDL2/	
INCLUDES=-I./src -I./include -I/usr/local/include/SDL2 -I/usr/include/SDL2

INSTALL=/usr/bin/install -c

.cpp.o: %.cpp
	$(CC) $(CPPFLAGS) $(INCLUDES) -o $@ -c $<

cabrio: src/main.o src/Config.o src/Game.o src/GameList.o src/Image.o src/Logger.o src/Platform.o \
	src/Quad.o src/Renderer.o src/RendererOpenGL.o src/QuadMap.o
	$(LD) -o $@ $^ $(LDFLAGS)

clean:
	rm -f cabrio src/*.o core core.*
