//main.c
//

#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"

int main(struct multiboot *mboot_ptr)
{

	init_descriptor_tables();

	monitor_clear();

	monitor_write("Hello Kernel");
	asm volatile("int $0x03");
	asm volatile("int $0x04");

	asm volatile("sti");
	init_timer(50);
	
	return 0;
}
