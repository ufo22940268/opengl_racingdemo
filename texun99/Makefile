UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
    CFLAG := -framework GLUT -framework OpenGL
else
    CFLAG := -lm -lglut -lGL -lGLU
endif

SRC := main.c util.c plane.c dot.c
TEST_SRC := util.c plane.c dot.c test.c

main: $(SRC)
	gcc $(CFLAG) $(SRC)

test: $(TEST_SRC)
	gcc $(CFLAG) $(TEST_SRC)

