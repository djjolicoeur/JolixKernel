//common.c

#include "common.h"

void outb(u16int port, u8int value)
{
	asm volatile ("outb %1, %0": : "dN" (port), "a" (value));
}

u8int inb(u16int port)
{
	u8int ret;
	asm volatile("inb %1, %0": "=a" (ret) : "dN" (port));
	return ret;
}

u16int inw(u16int port)
{
   u16int ret;
   asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}

void memcpy(u8int *dest, const u8int *src, u32int len)
{
	const u8int *sp = (const u8int *)src;
	u8int *dp = (u8int *)dest;
	for(; len != 0; len--) *dp++ = *sp++;
}

void memset(u8int *dest, u8int val, u32int len)
{
	u8int *tmp = (u8int *)dest;
	for(; len != 0; len--) *tmp ++ = val;
}

extern void panic(const char *message, const char *file, u32int line)
{
    // We encountered a massive problem and have to stop.
    asm volatile("cli"); // Disable interrupts.

    monitor_write("PANIC(");
    monitor_write(message);
    monitor_write(") at ");
    monitor_write(file);
    monitor_write(":");
    monitor_write_dec(line);
    monitor_write("\n");
    // Halt by going into an infinite loop.
    for(;;);
}

extern void panic_assert(const char *file, u32int line, const char *desc)
{
    // An assertion failed, and we have to panic.
    asm volatile("cli"); // Disable interrupts.

    monitor_write("ASSERTION-FAILED(");
    monitor_write(desc);
    monitor_write(") at ");
    monitor_write(file);
    monitor_write(":");
    monitor_write_dec(line);
    monitor_write("\n");
    // Halt by going into an infinite loop.
    for(;;);
}
                                     
