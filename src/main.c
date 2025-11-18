#include <stdio.h>
#include <string.h>
#include "switch.h"
#include "backend.h"

extern Backend MockBackend;

int main() {
    Switch sw;
    switch_init(&sw, &MockBackend);

    char command[64];

    while(1) {
        printf("switch> ");
        scanf("%s", command);

        if(!strcmp(command, "exit")) break;

        
    }
    return 0;
}