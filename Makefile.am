AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS  = ${ACLOCAL_FLAGS}

AM_CXXFLAGS=-g -Wall -Werror \
						`sdl-config --cflags` \
						-I./include
LDLIBS=`sdl-config --libs`

bin_PROGRAMS = CApp
CApp_SOURCES = include/CApp.h \
							 src/CApp.cpp \
							 src/CApp_on_init.cpp \
							 src/CApp_on_event.cpp \
							 src/CApp_on_loop.cpp \
							 src/CApp_on_render.cpp \
							 src/CApp_on_cleanup.cpp

dist_noinst_SCRIPT = autogen.sh
