//main.c
//

#include "monitor.h"
#include "descriptor_tables.h"
//#include "timer.h"
#include "paging.h"

int main(struct multiboot *mboot_ptr)
{

	init_descriptor_tables();

	monitor_clear();

	monitor_write("Hello Kernel\n");
	//asm volatile("int $0x03");
	//asm volatile("int $0x04");

	//asm volatile("sti");
	//init_timer(50);
        init_paging();
        monitor_write("Paging Inititialized");
        
        u32int *ptr = (u32int*)0xA0000000;
        u32int do_page_fault = *ptr;
                
        
	
	return 0;
}
