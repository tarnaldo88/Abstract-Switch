#include "switch.h"

void switch_init(Switch * sw, Backend *b) {
    sw->vlan_count = 0;
    sw->port_count = 0;
    sw->backend = b;
}