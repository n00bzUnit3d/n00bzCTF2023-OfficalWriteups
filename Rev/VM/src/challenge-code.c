#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

enum INSTR {
    NOP,
    PUSH,
    POP,
    MOV,
    MOVC,
    ADD,
    SUB,
    MUL,
    DIV,
    XOR,
    AND,
    OR,
    PRINT,
    INPUT,
    EXIT,
};

char program[0x200];

void write_file(char *filename) {
    int fd = open(filename, O_RDWR|O_CREAT);
    if (fd < 0) {
        puts("Error opening file!");
        exit(-1);
    }
    int w = write(fd, program, sizeof(program));
    if (w < 0) {
        puts("Error writing to file!");
        exit(-1);
    }
    close(fd);
}

void compile_code() {
    int commands[] = {
        INPUT,
        POP, 0,
        MOVC, 1, 'n',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, '0',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, '0',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, 'b',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, 'z',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, '{',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, 'x',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, '0',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, 'r',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, '_',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, 'X',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, 'o',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, 'R',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, '_',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, 'x',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, 'O',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, 'R',
        XOR, 0, 1,
        PRINT, 0,

        INPUT,
        POP, 0,
        MOVC, 1, '}',
        XOR, 0, 1,
        PRINT, 0,

        EXIT
    };
    for (int i = 0; i < sizeof(commands); i++) {
        program[i] = commands[i];
    }
}

int main(int argc, char **argv) {
    // if (argc != 2) {
    //     printf("Usage: %s [file to write to]", argv[0]);
    //     return -1;
    // }
    compile_code();
    write_file("exploit_code");
    return 0;
}
