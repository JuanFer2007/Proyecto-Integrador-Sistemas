BUILD_DIR = build
DIST_DIR = dist
TARGET_DIR = targets/x86_64

X86_64_ASM_OBJS = $(BUILD_DIR)/header.o $(BUILD_DIR)/main.o $(BUILD_DIR)/main64.o
X86_64_C_OBJS = $(BUILD_DIR)/main_c.o
X86_64_OBJS = $(X86_64_ASM_OBJS) $(X86_64_C_OBJS)

.PHONY: all clean build-x86_64 x86_64

all: x86_64

$(BUILD_DIR)/header.o: src/header.asm
	mkdir -p $(BUILD_DIR)
	nasm -f elf64 src/header.asm -o $(BUILD_DIR)/header.o

$(BUILD_DIR)/main.o: src/main.asm
	mkdir -p $(BUILD_DIR)
	nasm -f elf64 src/main.asm -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/main64.o: src/main64.asm
	mkdir -p $(BUILD_DIR)
	nasm -f elf64 src/main64.asm -o $(BUILD_DIR)/main64.o

$(BUILD_DIR)/main_c.o: src/main.c
	mkdir -p $(BUILD_DIR)
	gcc -m64 -c src/main.c -o $(BUILD_DIR)/main_c.o -ffreestanding -O2 -fno-stack-protector -fno-pic -mcmodel=kernel

$(DIST_DIR)/x86_64/kernel.bin: $(X86_64_OBJS)
	mkdir -p $(DIST_DIR)/x86_64
	ld -n -o $(DIST_DIR)/x86_64/kernel.bin -T $(TARGET_DIR)/linker.ld $(X86_64_OBJS)

build-x86_64: $(DIST_DIR)/x86_64/kernel.bin

x86_64: build-x86_64
	mkdir -p $(DIST_DIR)/x86_64/iso/boot/grub
	cp $(DIST_DIR)/x86_64/kernel.bin $(DIST_DIR)/x86_64/iso/boot/kernel.bin
	cp $(TARGET_DIR)/grub.cfg $(DIST_DIR)/x86_64/iso/boot/grub/grub.cfg
	grub-mkrescue -o $(DIST_DIR)/x86_64/kernel.iso $(DIST_DIR)/x86_64/iso
	@echo "¡ISO creada con éxito en $(DIST_DIR)/x86_64/kernel.iso!"

clean:
	sudo rm -rf $(BUILD_DIR) $(DIST_DIR)


