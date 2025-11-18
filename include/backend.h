#ifndef BACKEND_H
#define BACKEND_H

#include <stdbool.h>

typedef struct Backend {
    bool (*apply_vlan)(int vlan_id);
    bool (*remove_vlan)(int vlan_id);
    bool (*assign_port_to_vlan)(const char *port, int vlan_id);
} Backend;

#endif