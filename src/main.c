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

        if(!strcmp(command, "exit")) { 
            break;
        } else if(!strcmp(command, "show")) {
            switch_show(&sw);
        }
        else if (!strcmp(command, "vlan-add")) {
            int vid;
            scanf("%d", &vid);
            switch_create_vlan(&sw, vid);
        }
        else if (!strcmp(command, "vlan-del")) {
            int vid;
            scanf("%d", &vid);
            switch_delete_vlan(&sw, vid);
        }
        else if (!strcmp(command, "port-add")) {
            char name[32];
            scanf("%s", name);
            switch_add_port(&sw, name);
        }
        else if (!strcmp(command, "assign")) {
            char name[32];
            int vid;
            scanf("%s %d", name, &vid);
            switch_assign_port(&sw, name, vid);
        }


    }
    return 0;
}