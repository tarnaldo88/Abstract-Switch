#ifndef BACKEND_H
#define BACKEND_H

#include <stdbool.h>

typedef struct Backend {
    bool (*apply_vlan)(int vlan_id);
}