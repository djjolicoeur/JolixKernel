# Makefile for kernel
#
#

SOURCES=boot.o main.o monitor.o common.o descriptor_tables.o isr.o \
interrupt.o gdt.o timer.o kheap.o paging.o
CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-Tlink.ld
ASFLAGS=-felf

all: $(SOURCES) link 

clean:
	-rm *.o kernel

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

.s.o:
	nasm $(ASFLAGS) $<
