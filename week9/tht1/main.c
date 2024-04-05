// main part of the program
#include <stdio.h>
#include <stdlib.h>
#include "sum.h"

// changed a bit for step II
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <num1> <num2> <num3>\n", argv[0]);
        return 1;
    }

    // step I
    // int num1 = atoi(argv[1]);
    // int num2 = atoi(argv[2]);

    // int result = add(num1, num2);

    // stepp II
    MyStruct s;
    s.a = atoi(argv[1]);
    s.b = atoi(argv[2]);
    s.c = atoi(argv[3]);

    int result = add(s);

    printf("Result of (%d + %d) * %d is: %d\n", s.a, s.b, s.c, result);

    return 0;
}