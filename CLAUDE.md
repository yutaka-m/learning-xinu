# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a Xinu operating system implementation designed to run on Virtual Box (VBox) using QEMU system emulation. Xinu is a Unix-like operating system used for educational purposes, originally described in "Operating System Design -- The Xinu Approach" by Douglas Comer.

## Build Commands

### Docker-based Development (Recommended)
```bash
# Build the Docker container
docker build -t xinu-qemu-system-i386 .

# Run the container and start Xinu
docker run -it xinu-qemu-system-i386 sh
qemu-system-i386 -m 16 -kernel build/compile/xinu.elf -nographic -append "console=ttyS0"
```

### Direct Build (requires gcc-4.8)
```bash
# Build from compile directory
cd compile
make

# Clean build
make clean

# Rebuild configuration
make configure
```

### Configuration Management
```bash
# Rebuild configuration files (conf.h and conf.c)
cd config
make clean all install
```

## System Architecture

### Core Components

- **Kernel (`system/`)**: Core OS functionality including process management, memory management, scheduling, and system initialization
  - `initialize.c`: System initialization and null process
  - `main.c`: Main process that creates the shell
  - Process management: `create.c`, `kill.c`, `resume.c`, `suspend.c`
  - Memory management: `getmem.c`, `freemem.c`, `meminit.c`
  - Scheduling: `resched.c`, `ready.c`

- **Device Drivers (`device/`)**: Hardware abstraction layer
  - `tty/`: Terminal/console driver for UART
  - `eth/`: Ethernet driver for Intel 82545EM (E1000E)
  - `ram/`: RAM disk driver
  - `lfs/`: Local file system
  - `rfs/`: Remote file system
  - `pipe/`: Inter-process communication pipes

- **Network Stack (`net/`)**: TCP/IP networking
  - `ip.c`, `udp.c`, `icmp.c`: Protocol implementations
  - `arp.c`: Address Resolution Protocol
  - `dhcp.c`: DHCP client
  - `tftp.c`: TFTP client

- **Shell (`shell/`)**: Interactive command-line interface
  - Built-in commands: `ps`, `kill`, `ls`, `cat`, `ping`, `memstat`, etc.
  - Command table in `shell.c:cmdtab[]`

- **Configuration (`config/`)**: Device and system configuration
  - `Configuration`: Device specification file
  - Generates `conf.h` and `conf.c` via config program
  - Uses lex/yacc for parsing

### Key Architecture Points

- **Process Model**: Cooperative multitasking with priority-based scheduling
- **Memory Management**: Simple free list with basic allocation/deallocation
- **Device I/O**: Uniform device interface with function pointers for operations
- **File Systems**: Both local (LFS on RAM disk) and remote (RFS over UDP) file systems
- **Networking**: Full TCP/IP stack with DHCP, ARP, ICMP, UDP support

### Important Constants (config/Configuration)
- `NPROC`: 100 processes maximum
- `NSEM`: 100 semaphores maximum  
- Clock frequency: 200 MHz
- Quantum: 2ms time slices

### Entry Points
- System starts in `system/start.S` (assembly)
- Transitions to `initialize.c:nulluser()` 
- Creates startup process which creates main process
- Main process (`system/main.c`) creates shell and file system

### Build System Notes
- Uses custom configuration system (`config/`) to generate device tables
- Requires gcc-4.8 specifically for compatibility
- Links with custom linker script (`compile/ld.script`)
- Produces ELF binary suitable for QEMU or GRUB booting