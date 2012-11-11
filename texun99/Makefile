UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
    CFLAG := -framework GLUT -framework OpenGL -g
else
    CFLAG := -lm -lglut -lGL -lGLU -g
endif

PUB_SRC := util.c plane.c dot.c dot_stack.c
SRC := main.c $(PUB_SRC)
TEST_SRC := test.c $(PUB_SRC)

.PHONY : main
main: $(SRC)
	gcc $(CFLAG) $(SRC)

.PHONY : test
test: $(TEST_SRC)
	gcc $(CFLAG) $(TEST_SRC)

