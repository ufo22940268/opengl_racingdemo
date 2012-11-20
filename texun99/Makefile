UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
    CFLAG := -framework GLUT -framework OpenGL -g -Wall
else
    CFLAG := -lm -lglut -lGL -lGLU -g -Wall
endif

PUB_SRC := util.c plane.c dot.c linked_dots.c controller.c time_data.c
SRC := main.c $(PUB_SRC)
TEST_SRC := test.c $(PUB_SRC)

.PHONY : main
main: $(SRC)
	gcc $(CFLAG) $(SRC)

.PHONY : test
test: $(TEST_SRC)
	gcc $(CFLAG) $(TEST_SRC)
