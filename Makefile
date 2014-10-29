#
# Basic Makefile
#

CC=g++
LD=$(CC)
CPPFLAGS=-std=c++11
DEBUG=-g -Wall
#LDFLAGS=-lGL -lSDL -lSDL_image -lSDL_gfx 
INCLUDES=-I./src -I./include

INSTALL=/usr/bin/install -c

.cpp.o: %.cpp
	$(CC) $(CPPFLAGS) $(DEBUG) $(INCLUDES) -o $@ -c $<

cabrio: src/main.o src/Config.o src/Game.o src/GameList.o src/Platform.o src/SDLGraphics.o
	$(LD) -o $@ $^ $(LDFLAGS)

clean:
	rm -f cabrio src/*.o core core.*
