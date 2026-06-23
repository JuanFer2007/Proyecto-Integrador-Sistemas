# Part 2 — Monolithic 64-bit Operating System Kernel

##  Architecture Overview
This subsystem represents a custom, freestanding monolithic kernel compiled natively in `elf64` format. It executes a full bootstrap sequence from a 32-bit protected mode environment up into a 64-bit Long Mode execution layer, entirely decoupling itself from standard user-space libraries.

---

##  Low-Level Boot Flow and Subsystem Roles

The kernel development is strictly segmented into synchronized modular source structures:

### 1. Boot Verification and Paging Initialization (`src/main.asm`)
* **Role:** This module establishes the transition state. It reserves hardware boundaries in the `.bss` section for the CPU's memory management unit. It configures the initial 4-level paging directory registers (`P4`, `P3`, and `P2`) to identity-map the first Gigabyte of physical memory using 2-Megabyte Huge Pages, an architectural prerequisite for the x86_64 processor.
* **GDT Setup:** It initializes a 64-bit Global Descriptor Table (`gdt64`) defining a flat memory model and maps the system code segments before executing the long jump.

### 2. Multiboot2 Header Compliance (`src/header.asm`)
* **Role:** Employs the `0xe85250d6` magic identification number. Crucially, it incorporates the `align 8` structural alignment directive. This alignment is strictly required by the Multiboot2 specification; without it, the GNU GRUB bootloader fails to identify the kernel structure within the ISO image, leading to hardware virtualization exceptions.

### 3. Long Mode Gateway (`src/main64.asm`)
* **Role:** Captures execution control inside pure 64-bit Long Mode. It clears the CPU segment registers (`ss`, `ds`, `es`, `fs`, `gs`), enforces a strict 16-byte stack pointer alignment (`and rsp, -16`) to comply with the System V AMD64 ABI calling convention, and securely branches execution to the high-level C entry point.

### 4. Direct VGA Text-Mode Framebuffer Manipulation (`src/main.c`)
* **Role:** Since the system operates in a freestanding mode (`-ffreestanding`), standard I/O streams like `printf` are non-existent. The kernel interacts directly with hardware by assigning a volatile character pointer to the physical VGA video memory boundary at address `0xb8000`. It loops through the character array, applying the `0x0A` color attribute attribute byte to project a high-contrast green string across the screen without software optimization interference.

---

## Compilation Tooling (`Makefile`)
The automation layer forces explicit compiler optimization overrides to ensure safe kernel linking:
* **Bands:** `-m64 -ffreestanding -O2 -fno-stack-protector -fno-pic -mcmodel=kernel`
* **Purpose:** Instructs `GCC` to target the absolute kernel memory address spaces, prevents the injection of position-independent code blocks (`PIC`), disables standard operating system stack-smashing guards, and links everything through the strict rules specified in the `linker.ld` descriptor script.

---

##  Hardware Emulation Evidences
The following screenshots document the operational viability of our freestanding kernel operating within a system emulator:

### 1. GNU GRUB MultiBoot2 Initial Boot Selection Interface
![GRUB Bootloader Verification](grub.png)

### 2. High-Level Freestanding C Kernel Execution Rendered in VGA Video Memory
![64-bit Long Mode Live Screen](kernel.png)

