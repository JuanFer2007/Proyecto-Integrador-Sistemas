# Systems Engineering Integrated Project — Advanced Linux Infrastructures

## Research Group Members & Operational Roles
* **Juan Pindo Reinoso (Lead Systems Architect):** Engineered the freestanding monolithic 64-bit Kernel boot architecture, low-level Multiboot2 boundary alignment, and multi-level identity-mapped paging directories.
* **Jose (Operating System Distribution Engineer):** Executed the custom OS compilation pipeline, package lifecycle pruning, and persistent master profile provisioning (`/etc/skel`) via Cubic.
* **Dheivid (Infrastructure Lab Deployment Specialist):** Orchestrated the Black Hat Bash multi-network containerized environment and isolated security topology parameters.
* **Luis (Offensive Security Systems Analyst):** Performed low-level perimetric reconnaissance, passive target mapping, and automated shell execution trace auditing.

---

## 📹 Multi-System Unified Demonstration Video
To satisfy the automated verification requirements, our comprehensive video demonstration detailing the operational lifecycle of all three decoupled architectural components can be viewed here:
 **[https://drive.google.com/file/d/1AwaRPEuGuYYBGbUk5LDIJOQ2MsJBn4cp/view?usp=sharing]**

---

## Stable Engineering Artifacts & Executable Downloads
To adhere to clean repository workflows (*Tidy repo* parameters), large compiled binary components are securely decoupled from our standard source trees and hosted inside our releases pipeline [1.10]:
* **Custom Enterprise Linux ISO (Part 1):** Available for direct media bootstrapping at our [v1.0 Releases Workspace](https://github.com/JuanFer2007/Proyecto-Integrador-Sistemas/releases/tag/v1.0).
* **Freestanding 64-bit Core Kernel Image (Part 2):** Hosted as an independent boot disk inside our asset layer at [v1.0 Releases Workspace](https://github.com/JuanFer2007/Proyecto-Integrador-Sistemas/releases/tag/v1.0).

---

## Complete Technical Reproducibility Instructions

### Part 1 — Custom Operating System Provisioning (Cubic Architecture)
1. Initialize the customized build context on an Ubuntu derivative environment by executing the staging repository hooks:
   ```bash
   sudo apt-add-repository -y ppa:cubic-wizard/release && sudo apt update && sudo apt install -y cubic
   ```
2. Import the source `ubuntu-24.04-desktop-amd64.iso` installation disk within Cubic, spin up the isolated virtual command-line execution context (`Chroot`), and execute our custom dependency suite:
   ```bash
   apt update && apt install -y neovim git build-essential tmux && apt purge -y firefox && apt install -y librewolf
   ```
3. Establish default environment persistence for fresh session initializations by appending our branding banners to the system configuration tree:
   ```bash
   mkdir -p /etc/skel/.config && echo "echo 'Welcome to the Custom Distro'" >> /etc/skel/.bashrc
   ```
4. Compress the modified root filesystem structure utilizing high-ratio **XZ** compression protocols to extract the final bootable ISO.

### Part 2 — Freestanding Monolithic Kernel Compilation & Bare-Metal Bootstrap
1. Enter the isolated low-level subsystem workspace directory:
   ```bash
   cd parte2-kernel/parte2-kernel
   ```
2. Purgue legacy object binaries, map the assembly parameters, and automatically generate the functional target iso image:
   ```bash
   sudo rm -rf build dist && mkdir build dist && make x86_64
   ```
3. Emulate the bare-metal kernel environment over the standalone QEMU hardware platform interface:
   ```bash
   qemu-system-x86_64 -cdrom dist/x86_64/kernel.iso -cpu max
   ```

### Part 3 — Black Hat Bash Isolated Multi-Network Container Cluster
1. Route your working session execution into the specialized laboratory deployment tree:
   ```bash
   cd parte3-lab
   ```
2. Spawn the vulnerable multi-layered target containers in background detached mode via the Docker orchestration engine:
   ```bash
   docker compose up -d
   ```
3. Validate perimeter health routing and interface discovery matrices against the private sandboxed subnets by running:
   ```bash
   make test
   ```
