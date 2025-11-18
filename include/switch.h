#ifndef SWITCH_H
#define SWITCH_H

#include "vlan.h"
#include "port.h"
#include "backend.h"
#include <stdio.h>
#include <string.h>

#define MAX_VLANS 128
#define MAX_PORTS 64

typedef struct {
    VLAN vlans[MAX_VLANS];
    int vlan_count;

    Port ports[MAX_PORTS];
    int port_count;

    Backend *backend;
} Switch;

void switch_init(Switch *sw, Backend *b);
bool switch_create_vlan(Switch *sw, int vlan_id);
bool switch_delete_vlan(Switch *sw, int vlan_id);
bool switch_add_port(Switch *sw, const char *name);
bool switch_assign_port(Switch *sw, const char *name, int vlan_id);
void switch_show(Switch *sw);

#endif