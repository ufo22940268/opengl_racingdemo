UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
        CFLAG = -framework GLUT -framework OpenGL
else
        CFLAG = -lm -lglut -lGL -lGLU
endif

SRC = main.c util.c plane.c dot.c
all: $(SRC)
	gcc $(CFLAG) $(SRC)
