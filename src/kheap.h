/* 
 * File:   kmalloc.h
 * Author: dan
 *
 * Created on October 11, 2012, 1:14 PM
 */
#include "common.h"
#ifndef KMALLOC_H
#define	KMALLOC_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    
u32int kmalloc_aligned(u32int sz);
u32int kmalloc_physical(u32int sz, u32int *phys );
u32int kmalloc_aligned_physical(u32int sz, u32int *phys);
u32int kmalloc(u32int sz);



#ifdef	__cplusplus
}
#endif

#endif	/* KMALLOC_H */


        