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