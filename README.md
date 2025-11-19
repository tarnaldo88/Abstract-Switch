# Abstract Switch

A C-based network switch simulation with VLAN management capabilities. This project implements an abstract network device API that allows for creating and managing virtual LANs (VLANs) and assigning ports to them.

## Features

- **VLAN Management**: Create and delete VLANs with unique IDs
- **Port Management**: Add ports and assign them to specific VLANs
- **Abstract Backend**: Pluggable backend interface for different implementations
- **Interactive CLI**: Command-line interface for real-time switch management
- **Mock Backend**: Included mock backend for testing and demonstration

## Project Structure

```
Abstract-Switch/
├── include/           # Header files
│   ├── backend.h      # Backend interface definition
│   ├── port.h         # Port data structures
│   ├── switch.h       # Switch API and structures
│   └── vlan.h         # VLAN data structures
├── src/               # Source files
│   ├── backend.c      # Mock backend implementation
│   ├── main.c         # Main application and CLI
│   └── switch.c       # Switch core functionality
├── Makefile           # Build configuration
└── README.md          # This file
```

## Building

Compile the project using the provided Makefile:

```bash
make
```

This will create the `switch.exe` executable.

To clean build artifacts:

```bash
make clean
```

## Usage

Run the compiled executable:

```bash
./switch.exe
```

### Available Commands

- `vlan-add <id>` - Create a new VLAN with the specified ID
- `vlan-del <id>` - Delete an existing VLAN
- `port-add <name>` - Add a new port with the specified name
- `assign <port> <vlan>` - Assign a port to a VLAN
- `show` - Display current VLAN and port configuration
- `exit` - Exit the application

### Example Session

```
switch> vlan-add 10
[MockBackend] Creating VLAN 10
switch> vlan-add 20
[MockBackend] Creating VLAN 20
switch> port-add eth0
switch> port-add eth1
switch> assign eth0 10
[MockBackend] Assigning port eth0 to VLAN 10
switch> assign eth1 20
[MockBackend] Assigning port eth1 to VLAN 20
switch> show

=== Ports ===
  VLAN 10
  VLAN 20

=== Ports ===
  eth0  -> VLAN 10
  eth1  -> VLAN 20
switch> exit
```

## Architecture

### Core Components

1. **Switch**: Main switch abstraction managing VLANs and ports
2. **Backend**: Abstract interface for hardware-specific implementations
3. **VLAN**: Virtual LAN representation
4. **Port**: Network port representation with VLAN assignment

### Backend Interface

The project uses an abstract backend pattern allowing for different implementations:

```c
typedef struct {
    bool (*apply_vlan)(int vlan_id);
    bool (*remove_vlan)(int vlan_id);
    bool (*assign_port_to_vlan)(const char *port, int vlan_id);
} Backend;
```

### Limitations

- Maximum 128 VLANs supported
- Maximum 64 ports supported
- Port names limited to 32 characters
- Mock backend only simulates operations (no actual network configuration)

## Requirements

- C compiler (GCC/Clang/MSVC)
- Make utility
- Standard C library

## Future Enhancements

- Support for more VLAN/port configurations
- Multiple backend implementations (real hardware, simulation)
- Configuration file support
- Network protocol implementation
- Port statistics and monitoring

## License

This project is provided as-is for educational and development purposes.

## Contributing

Feel free to submit issues and enhancement requests to improve the abstract switch implementation.