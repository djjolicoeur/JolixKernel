#include "kheap.h"


extern u32int end;
u32int placement_address = (u32int)&end;

u32int _kmalloc(u32int sz, int align, u32int *phys)
{
    if(align == 1 && (placement_address & 0xFFFFF000))
    {
        placement_address &= 0xFFFFF000;
        placement_address += 0x1000;
    }
    if (phys)
    {
        *phys = placement_address;
    }
    u32int old_addr = placement_address;
    placement_address += sz;
    return old_addr;
}

u32int kmalloc_physical(u32int sz, u32int *phys )
{
    return _kmalloc(sz,0,phys);
}

u32int kmalloc_aligned(u32int sz)
{
    return _kmalloc(sz,1,0);
}

u32int kmalloc_aligned_physical(u32int sz, u32int *phys)
{
   return  _kmalloc(sz,1,phys);
}

u32int kmalloc(u32int sz)
{
    return _kmalloc(sz,0,0);
}
