#
# MAKEFILE FOR THE MIPS LINUX BOOTLOADER AND ROM DEBUGGER
#
# i-data Networks
#
# Author: Thomas Horsten <thh@i-data.com>
#

ifndef Version
 Version = "$(USER)-test"
endif

MKLASATIMG = mklasatimg
MKLASATIMG_ARCH = mq2,mqpro,sp100,sp200
KERNEL_IMAGE = $(TOPDIR)/vmlinux
KERNEL_START = $(shell $(NM) $(KERNEL_IMAGE) | grep " _text" | cut -f1 -d\ )
KERNEL_ENTRY = $(shell $(NM) $(KERNEL_IMAGE) | grep kernel_entry | cut -f1 -d\ )

LDSCRIPT= -L$(obj) -Tromscript.normal

AFLAGS_head.o += -D_kernel_start=0x$(KERNEL_START) \
		-D_kernel_entry=0x$(KERNEL_ENTRY) \
		-D VERSION="\"$(Version)\"" \
		-D TIMESTAMP=$(shell date +%s) 

head.o: $(KERNEL_IMAGE)

obj-y = head.o kImage.o

rom.sw:	$(obj)/rom.sw

$(obj)/rom.sw:	$(obj)/rom.bin
	$(MKLASATIMG) -o $@ -k $^ -m $(MKLASATIMG_ARCH)

$(obj)/rom.bin: $(obj)/rom
	$(OBJCOPY) -O binary -S $^ $@

# Rule to make the bootloader
$(obj)/rom: $(addprefix $(obj)/,$(obj-y))
	$(LD) $(LDFLAGS) $(LDSCRIPT) -o $@ $^

$(obj)/%.o: $(obj)/%.gz
	$(LD) -r -o $@ -b binary $<

$(obj)/%.gz: $(obj)/%.bin
	gzip -cf -9 $< > $@

$(obj)/kImage.bin: $(KERNEL_IMAGE)
	$(OBJCOPY) -O binary -S $^ $@

clean:
	rm -f rom rom.bin rom.sw kImage.bin kImage.o
