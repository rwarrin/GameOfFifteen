# Game Of Fifteen
#

all: clean fifteen fifteenw

fifteen: fifteen.c gamefunctions.c gamefunctions.h
	gcc -ggdb -std=c99 -Wall -Werror -o fifteen fifteen.c gamefunctions.c -lm

fifteenw: fifteen.c gamefunctions.c gamefunctions.h
	gcc -ggdb -std=c99 -Wall -Werror -mno-cygwin -o fifteenw fifteen.c gamefunctions.c -lm
clean:
	rm -f *.o a.out core fifteen

