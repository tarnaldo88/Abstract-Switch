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