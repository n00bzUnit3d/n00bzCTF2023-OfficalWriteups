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
    EXIT
};

char program[0x200]; // exploitable with char or need to change?
long stack[0x200];
int sp = 0;
long r[10];

void disable_buffering() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void read_file(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        puts("Error opening file!");
        exit(-1);
    }
    read(fd, program, sizeof(program));
}

void execute() {
    int i = 0;
    int t = 0;
    for (i = 0; i < sizeof(program); i++) {
        switch (program[i]) {
            case EXIT:
                exit(0);
            case NOP:
                puts("NOP");
                continue;
            case PUSH:
                //problem??
                stack[sp++] = r[(int)program[++i]];
                break;
            case POP:
                //problem??
                r[(int)program[++i]] = stack[--sp];
                // printf("r%d = %ld\n", program[i], r[(int)program[i]]);
                break;
            case MOVC:
                // r1 = C
                t = (int)program[(int)++i];
                r[t] = (int)program[++i];
                break;
            case MOV:
                // r1 = r2
                t = (int)program[(int)++i];
                r[t] = r[(int)program[++i]];
                break;
            case ADD:
                // r1 = r1 + r2
                t = (int)program[(int)++i];
                r[t] = r[t] + r[(int)program[i+1]];
                i++;
                break;
            case SUB:
                // r1 = r1 - r2
                t = (int)program[(int)++i];
                r[t] = r[t] - r[(int)program[i+1]];
                i++;
                break;
            case MUL:
                // r1 = r1 * r2
                t = (int)program[(int)++i];
                r[t] = r[t] * r[(int)program[i+1]];
                i++;
                break;
            case DIV:
                // r1 = r1 / r2
                t = (int)program[(int)++i];
                r[t] = r[t] / r[(int)program[i+1]];
                i++;
                break;
            case XOR:
                // r1 = r1 ^ r2
                t = (int)program[(int)++i];
                r[t] = r[t] ^ r[(int)program[i+1]];
                i++;
                break;
            case AND:
                // r1 = r1 & r2
                t = (int)program[(int)++i];
                r[t] = r[t] & r[(int)program[i+1]];
                i++;
                break;
            case OR:
                // r1 = r1 | r2
                t = (int)program[(int)++i];
                r[t] = r[t] | r[(int)program[i+1]];
                i++;
                break;
            case PRINT:
                // prints a register
                printf("%ld\n", r[(int)program[++i]]);
                break;
            case INPUT:
                stack[sp++] = getchar();
                // printf("stack[%d] = %ld\n", sp-1, stack[sp-1]);
                break;
            default:
                puts("ERROR: Unknown instruction!");
                exit(-1);
        }
    }
}

int main(int argc, char **argv) {
    disable_buffering();
    if (argc != 2) {
        printf("Usage: %s [file to execute]\n", argv[0]);
        return -1;
    }
    read_file(argv[1]);
    // init();
    execute();
    return 0;
}
