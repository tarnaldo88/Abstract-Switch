#include <stdio.h>
#include <stdbool.h>
#include "backend.h"

//MOCK BACKEND 

bool apply_vlan(int vlan_id) {
    printf("[MockBackend] Creating VLAN %d\n", vlan_id);
    return true;
}

bool remove_vlan(int vlan_id) {
    printf("[MockBackend] Removing VLAN %d\n", vlan_id);
    return true;
}

bool assign_port(const char *port, int vlan_id) {
    printf("[MockBackend] Assigning port %s to VLAN %d\n", port, vlan_id);
    return true;
}

Backend MockBackend = {
    .apply_vlan = apply_vlan,
    .remove_vlan = remove_vlan,
    .assign_port_to_vlan = assign_port
};