/******************************************************************************
*                                                                             *
* License Agreement                                                           *
*                                                                             *
* Copyright (c) 2003 Altera Corporation, San Jose, California, USA.           *
* All rights reserved.                                                        *
*                                                                             *
* Permission is hereby granted, free of charge, to any person obtaining a     *
* copy of this software and associated documentation files (the "Software"),  *
* to deal in the Software without restriction, including without limitation   *
* the rights to use, copy, modify, merge, publish, distribute, sublicense,    *
* and/or sell copies of the Software, and to permit persons to whom the       *
* Software is furnished to do so, subject to the following conditions:        *
*                                                                             *
* The above copyright notice and this permission notice shall be included in  *
* all copies or substantial portions of the Software.                         *
*                                                                             *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         *
* DEALINGS IN THE SOFTWARE.                                                   *
*                                                                             *
* This agreement shall be governed in all respects by the laws of the State   *
* of California and by the laws of the United States of America.              *
*                                                                             *
******************************************************************************/

#ifndef __ALTERA_AVALON_PIO_REGS_H__
#define __ALTERA_AVALON_PIO_REGS_H__

// #include <io.h>

#define IOADDR_ALTERA_AVALON_PIO_DATA(base)          
#define IORD_ALTERA_AVALON_PIO_DATA(base) (0)           
#define IOWR_ALTERA_AVALON_PIO_DATA(base, data)      

#define IOADDR_ALTERA_AVALON_PIO_DIRECTION(base)     
#define IORD_ALTERA_AVALON_PIO_DIRECTION(base) (0)      
#define IOWR_ALTERA_AVALON_PIO_DIRECTION(base, data) 

#define IOADDR_ALTERA_AVALON_PIO_IRQ_MASK(base)      
#define IORD_ALTERA_AVALON_PIO_IRQ_MASK(base) (0)       
#define IOWR_ALTERA_AVALON_PIO_IRQ_MASK(base, data)  

#define IOADDR_ALTERA_AVALON_PIO_EDGE_CAP(base)      
#define IORD_ALTERA_AVALON_PIO_EDGE_CAP(base) (0)       
#define IOWR_ALTERA_AVALON_PIO_EDGE_CAP(base, data)  


#define IOADDR_ALTERA_AVALON_PIO_SET_BIT(base)       
#define IORD_ALTERA_AVALON_PIO_SET_BITS(base) (0)       
#define IOWR_ALTERA_AVALON_PIO_SET_BITS(base, data)  
    
#define IOADDR_ALTERA_AVALON_PIO_CLEAR_BITS(base)    
#define IORD_ALTERA_AVALON_PIO_CLEAR_BITS(base) (0)     
#define IOWR_ALTERA_AVALON_PIO_CLEAR_BITS(base, data)
     

 
/* Defintions for direction-register operation with bi-directional PIOs */
#define ALTERA_AVALON_PIO_DIRECTION_INPUT  0
#define ALTERA_AVALON_PIO_DIRECTION_OUTPUT 1

#endif /* __ALTERA_AVALON_PIO_REGS_H__ */
