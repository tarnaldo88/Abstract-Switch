#include "switch.h"

void switch_init(Switch * sw, Backend *b) {
    sw->vlan_count = 0;
    sw->port_count = 0;
    sw->backend = b;
}

bool switch_create_vlan(Switch *sw, int vlan_id) {
    if(sw->vlan_count >= MAX_VLANS) return false;

    sw->vlans[sw->vlan_count++].id = vlan_id;

    return sw->backend->apply_vlan(vlan_id);
}

bool switch_delete_vlan(Switch *sw, int vlan_id) {
    for(int i = 0; i < sw->vlan_count; i++) {
        if(sw->vlans[i].id == vlan_id) {
            //shift the array
            for(int j = i; j < sw->vlan_count - 1; j++) {
                sw->vlans[j] = sw->vlans[j+1];
            }

            sw->vlan_count--;

            return sw->backend->remove_vlan(vlan_id);
        }
    }
    return false;
}

bool switch_add_port(Switch *sw, const char *name) {
    if(sw->port_count >= MAX_PORTS) return false;

    strcpy(sw->ports[sw->port_count].name, name);
    sw->ports[sw->port_count].vlan_id = -1;
    sw->port_count++;

    return true;
}

bool switch_assign_port(Switch *sw, const char* name, int vlan_id) {
    for(int i = 0; i < sw->port_count; i ++) {
        if(!strcmp(sw->ports[i].name, name)) {
            sw->ports[i].vlan_id = vlan_id;
            return sw->backend->assign_port_to_vlan(name, vlan_id);
        }
    }
    return false;
}

void switch_show(Switch *sw) {
    printf("\n=== Ports ===\n");

    for(int i = 0; i < sw->vlan_count; i++) {
        printf("  VLAN %d\n", sw->vlans[i].id);
    }

    printf("\n=== Ports ===\n");
    for (int i = 0; i < sw->port_count; i++) {
        printf("  %s  -> VLAN %d\n", sw->ports[i].name, sw->ports[i].vlan_id);
    }
}