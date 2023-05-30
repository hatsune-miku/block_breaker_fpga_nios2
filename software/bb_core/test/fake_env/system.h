/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios2_gen2_0' in SOPC Builder design 'nios2_kernel'
 * SOPC Builder design path: E:/data/project/block_breaker/nios2_kernel.sopcinfo
 *
 * Generated: Sun Apr 03 00:30:46 NDT 2022
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
/*
 * linker.h - Linker script mapping information
 *
 * Machine generated for CPU 'nios2_gen2_0' in SOPC Builder design 'nios2_kernel'
 * SOPC Builder design path: E:/data/project/block_breaker/nios2_kernel.sopcinfo
 *
 * Generated: Tue Feb 22 23:17:09 NST 2022
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __LINKER_H_
#define __LINKER_H_


/*
 * BSP controls alt_load() behavior in crt0.
 *
 */

#define ALT_LOAD_EXPLICITLY_CONTROLLED


/*
 * Base address and span (size in bytes) of each linker region
 *
 */

#define ONCHIP_MEMORY2_RAM_BEFORE_EXCEPTION_REGION_BASE 0x10000
#define ONCHIP_MEMORY2_RAM_BEFORE_EXCEPTION_REGION_SPAN 32
#define ONCHIP_MEMORY2_RAM_REGION_BASE 0x10020
#define ONCHIP_MEMORY2_RAM_REGION_SPAN 32736
#define ONCHIP_MEMORY2_ROM_REGION_BASE 0x18020
#define ONCHIP_MEMORY2_ROM_REGION_SPAN 32736
#define RESET_REGION_BASE 0x18000
#define RESET_REGION_SPAN 32


/*
 * Devices associated with code sections
 *
 */

#define ALT_EXCEPTIONS_DEVICE ONCHIP_MEMORY2_RAM
#define ALT_RESET_DEVICE ONCHIP_MEMORY2_ROM
#define ALT_RODATA_DEVICE ONCHIP_MEMORY2_RAM
#define ALT_RWDATA_DEVICE ONCHIP_MEMORY2_RAM
#define ALT_TEXT_DEVICE ONCHIP_MEMORY2_RAM


/*
 * Initialization code at the reset address is allowed (e.g. no external bootloader).
 *
 */

#define ALT_ALLOW_CODE_AT_RESET


/*
 * The alt_load() facility is called from crt0 to copy sections into RAM.
 *
 */

#define ALT_LOAD_COPY_RWDATA

#endif /* __LINKER_H_ */


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00020820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x12
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00010020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x12
#define ALT_CPU_NAME "nios2_gen2_0"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00018000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00020820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x12
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00010020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x12
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00018000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_NIOS2_GEN2


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone V"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x21278
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x21278
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x21278
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios2_kernel"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 4
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x21278
#define JTAG_UART_0_IRQ 0
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * onchip_memory2_ram configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_ram altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_RAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_RAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_RAM_BASE 0x10000
#define ONCHIP_MEMORY2_RAM_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_RAM_DUAL_PORT 0
#define ONCHIP_MEMORY2_RAM_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_RAM_INIT_CONTENTS_FILE "nios2_kernel_onchip_memory2_ram"
#define ONCHIP_MEMORY2_RAM_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_RAM_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_RAM_IRQ -1
#define ONCHIP_MEMORY2_RAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_RAM_NAME "/dev/onchip_memory2_ram"
#define ONCHIP_MEMORY2_RAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_RAM_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_RAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_RAM_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_RAM_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_RAM_SIZE_VALUE 32768
#define ONCHIP_MEMORY2_RAM_SPAN 32768
#define ONCHIP_MEMORY2_RAM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_RAM_WRITABLE 1


/*
 * onchip_memory2_rom configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_memory2_rom altera_avalon_onchip_memory2
#define ONCHIP_MEMORY2_ROM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEMORY2_ROM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEMORY2_ROM_BASE 0x18000
#define ONCHIP_MEMORY2_ROM_CONTENTS_INFO ""
#define ONCHIP_MEMORY2_ROM_DUAL_PORT 0
#define ONCHIP_MEMORY2_ROM_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_ROM_INIT_CONTENTS_FILE "nios2_kernel_onchip_memory2_rom"
#define ONCHIP_MEMORY2_ROM_INIT_MEM_CONTENT 1
#define ONCHIP_MEMORY2_ROM_INSTANCE_ID "NONE"
#define ONCHIP_MEMORY2_ROM_IRQ -1
#define ONCHIP_MEMORY2_ROM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEMORY2_ROM_NAME "/dev/onchip_memory2_rom"
#define ONCHIP_MEMORY2_ROM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEMORY2_ROM_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEMORY2_ROM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEMORY2_ROM_SINGLE_CLOCK_OP 0
#define ONCHIP_MEMORY2_ROM_SIZE_MULTIPLE 1
#define ONCHIP_MEMORY2_ROM_SIZE_VALUE 32768
#define ONCHIP_MEMORY2_ROM_SPAN 32768
#define ONCHIP_MEMORY2_ROM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEMORY2_ROM_WRITABLE 0


/*
 * pio_ball_x configuration
 *
 */

#define ALT_MODULE_CLASS_pio_ball_x altera_avalon_pio
#define PIO_BALL_X_BASE 0x21170
#define PIO_BALL_X_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_BALL_X_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_BALL_X_CAPTURE 0
#define PIO_BALL_X_DATA_WIDTH 16
#define PIO_BALL_X_DO_TEST_BENCH_WIRING 0
#define PIO_BALL_X_DRIVEN_SIM_VALUE 0
#define PIO_BALL_X_EDGE_TYPE "NONE"
#define PIO_BALL_X_FREQ 50000000
#define PIO_BALL_X_HAS_IN 0
#define PIO_BALL_X_HAS_OUT 1
#define PIO_BALL_X_HAS_TRI 0
#define PIO_BALL_X_IRQ -1
#define PIO_BALL_X_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_BALL_X_IRQ_TYPE "NONE"
#define PIO_BALL_X_NAME "/dev/pio_ball_x"
#define PIO_BALL_X_RESET_VALUE 0
#define PIO_BALL_X_SPAN 16
#define PIO_BALL_X_TYPE "altera_avalon_pio"


/*
 * pio_ball_y configuration
 *
 */

#define ALT_MODULE_CLASS_pio_ball_y altera_avalon_pio
#define PIO_BALL_Y_BASE 0x21160
#define PIO_BALL_Y_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_BALL_Y_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_BALL_Y_CAPTURE 0
#define PIO_BALL_Y_DATA_WIDTH 16
#define PIO_BALL_Y_DO_TEST_BENCH_WIRING 0
#define PIO_BALL_Y_DRIVEN_SIM_VALUE 0
#define PIO_BALL_Y_EDGE_TYPE "NONE"
#define PIO_BALL_Y_FREQ 50000000
#define PIO_BALL_Y_HAS_IN 0
#define PIO_BALL_Y_HAS_OUT 1
#define PIO_BALL_Y_HAS_TRI 0
#define PIO_BALL_Y_IRQ -1
#define PIO_BALL_Y_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_BALL_Y_IRQ_TYPE "NONE"
#define PIO_BALL_Y_NAME "/dev/pio_ball_y"
#define PIO_BALL_Y_RESET_VALUE 0
#define PIO_BALL_Y_SPAN 16
#define PIO_BALL_Y_TYPE "altera_avalon_pio"


/*
 * pio_block_data_high configuration
 *
 */

#define ALT_MODULE_CLASS_pio_block_data_high altera_avalon_pio
#define PIO_BLOCK_DATA_HIGH_BASE 0x21150
#define PIO_BLOCK_DATA_HIGH_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_BLOCK_DATA_HIGH_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_BLOCK_DATA_HIGH_CAPTURE 0
#define PIO_BLOCK_DATA_HIGH_DATA_WIDTH 32
#define PIO_BLOCK_DATA_HIGH_DO_TEST_BENCH_WIRING 0
#define PIO_BLOCK_DATA_HIGH_DRIVEN_SIM_VALUE 0
#define PIO_BLOCK_DATA_HIGH_EDGE_TYPE "NONE"
#define PIO_BLOCK_DATA_HIGH_FREQ 50000000
#define PIO_BLOCK_DATA_HIGH_HAS_IN 0
#define PIO_BLOCK_DATA_HIGH_HAS_OUT 1
#define PIO_BLOCK_DATA_HIGH_HAS_TRI 0
#define PIO_BLOCK_DATA_HIGH_IRQ -1
#define PIO_BLOCK_DATA_HIGH_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_BLOCK_DATA_HIGH_IRQ_TYPE "NONE"
#define PIO_BLOCK_DATA_HIGH_NAME "/dev/pio_block_data_high"
#define PIO_BLOCK_DATA_HIGH_RESET_VALUE 0
#define PIO_BLOCK_DATA_HIGH_SPAN 16
#define PIO_BLOCK_DATA_HIGH_TYPE "altera_avalon_pio"


/*
 * pio_block_data_low configuration
 *
 */

#define ALT_MODULE_CLASS_pio_block_data_low altera_avalon_pio
#define PIO_BLOCK_DATA_LOW_BASE 0x21130
#define PIO_BLOCK_DATA_LOW_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_BLOCK_DATA_LOW_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_BLOCK_DATA_LOW_CAPTURE 0
#define PIO_BLOCK_DATA_LOW_DATA_WIDTH 8
#define PIO_BLOCK_DATA_LOW_DO_TEST_BENCH_WIRING 0
#define PIO_BLOCK_DATA_LOW_DRIVEN_SIM_VALUE 0
#define PIO_BLOCK_DATA_LOW_EDGE_TYPE "NONE"
#define PIO_BLOCK_DATA_LOW_FREQ 50000000
#define PIO_BLOCK_DATA_LOW_HAS_IN 0
#define PIO_BLOCK_DATA_LOW_HAS_OUT 1
#define PIO_BLOCK_DATA_LOW_HAS_TRI 0
#define PIO_BLOCK_DATA_LOW_IRQ -1
#define PIO_BLOCK_DATA_LOW_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_BLOCK_DATA_LOW_IRQ_TYPE "NONE"
#define PIO_BLOCK_DATA_LOW_NAME "/dev/pio_block_data_low"
#define PIO_BLOCK_DATA_LOW_RESET_VALUE 0
#define PIO_BLOCK_DATA_LOW_SPAN 16
#define PIO_BLOCK_DATA_LOW_TYPE "altera_avalon_pio"


/*
 * pio_block_data_mid configuration
 *
 */

#define ALT_MODULE_CLASS_pio_block_data_mid altera_avalon_pio
#define PIO_BLOCK_DATA_MID_BASE 0x21140
#define PIO_BLOCK_DATA_MID_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_BLOCK_DATA_MID_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_BLOCK_DATA_MID_CAPTURE 0
#define PIO_BLOCK_DATA_MID_DATA_WIDTH 32
#define PIO_BLOCK_DATA_MID_DO_TEST_BENCH_WIRING 0
#define PIO_BLOCK_DATA_MID_DRIVEN_SIM_VALUE 0
#define PIO_BLOCK_DATA_MID_EDGE_TYPE "NONE"
#define PIO_BLOCK_DATA_MID_FREQ 50000000
#define PIO_BLOCK_DATA_MID_HAS_IN 0
#define PIO_BLOCK_DATA_MID_HAS_OUT 1
#define PIO_BLOCK_DATA_MID_HAS_TRI 0
#define PIO_BLOCK_DATA_MID_IRQ -1
#define PIO_BLOCK_DATA_MID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_BLOCK_DATA_MID_IRQ_TYPE "NONE"
#define PIO_BLOCK_DATA_MID_NAME "/dev/pio_block_data_mid"
#define PIO_BLOCK_DATA_MID_RESET_VALUE 0
#define PIO_BLOCK_DATA_MID_SPAN 16
#define PIO_BLOCK_DATA_MID_TYPE "altera_avalon_pio"


/*
 * pio_button_down configuration
 *
 */

#define ALT_MODULE_CLASS_pio_button_down altera_avalon_pio
#define PIO_BUTTON_DOWN_BASE 0x21210
#define PIO_BUTTON_DOWN_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_BUTTON_DOWN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_BUTTON_DOWN_CAPTURE 0
#define PIO_BUTTON_DOWN_DATA_WIDTH 1
#define PIO_BUTTON_DOWN_DO_TEST_BENCH_WIRING 0
#define PIO_BUTTON_DOWN_DRIVEN_SIM_VALUE 0
#define PIO_BUTTON_DOWN_EDGE_TYPE "NONE"
#define PIO_BUTTON_DOWN_FREQ 50000000
#define PIO_BUTTON_DOWN_HAS_IN 1
#define PIO_BUTTON_DOWN_HAS_OUT 0
#define PIO_BUTTON_DOWN_HAS_TRI 0
#define PIO_BUTTON_DOWN_IRQ 4
#define PIO_BUTTON_DOWN_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PIO_BUTTON_DOWN_IRQ_TYPE "LEVEL"
#define PIO_BUTTON_DOWN_NAME "/dev/pio_button_down"
#define PIO_BUTTON_DOWN_RESET_VALUE 0
#define PIO_BUTTON_DOWN_SPAN 16
#define PIO_BUTTON_DOWN_TYPE "altera_avalon_pio"


/*
 * pio_button_left configuration
 *
 */

#define ALT_MODULE_CLASS_pio_button_left altera_avalon_pio
#define PIO_BUTTON_LEFT_BASE 0x21240
#define PIO_BUTTON_LEFT_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_BUTTON_LEFT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_BUTTON_LEFT_CAPTURE 0
#define PIO_BUTTON_LEFT_DATA_WIDTH 1
#define PIO_BUTTON_LEFT_DO_TEST_BENCH_WIRING 0
#define PIO_BUTTON_LEFT_DRIVEN_SIM_VALUE 0
#define PIO_BUTTON_LEFT_EDGE_TYPE "NONE"
#define PIO_BUTTON_LEFT_FREQ 50000000
#define PIO_BUTTON_LEFT_HAS_IN 1
#define PIO_BUTTON_LEFT_HAS_OUT 0
#define PIO_BUTTON_LEFT_HAS_TRI 0
#define PIO_BUTTON_LEFT_IRQ 1
#define PIO_BUTTON_LEFT_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PIO_BUTTON_LEFT_IRQ_TYPE "LEVEL"
#define PIO_BUTTON_LEFT_NAME "/dev/pio_button_left"
#define PIO_BUTTON_LEFT_RESET_VALUE 0
#define PIO_BUTTON_LEFT_SPAN 16
#define PIO_BUTTON_LEFT_TYPE "altera_avalon_pio"


/*
 * pio_button_right configuration
 *
 */

#define ALT_MODULE_CLASS_pio_button_right altera_avalon_pio
#define PIO_BUTTON_RIGHT_BASE 0x21230
#define PIO_BUTTON_RIGHT_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_BUTTON_RIGHT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_BUTTON_RIGHT_CAPTURE 0
#define PIO_BUTTON_RIGHT_DATA_WIDTH 1
#define PIO_BUTTON_RIGHT_DO_TEST_BENCH_WIRING 0
#define PIO_BUTTON_RIGHT_DRIVEN_SIM_VALUE 0
#define PIO_BUTTON_RIGHT_EDGE_TYPE "NONE"
#define PIO_BUTTON_RIGHT_FREQ 50000000
#define PIO_BUTTON_RIGHT_HAS_IN 1
#define PIO_BUTTON_RIGHT_HAS_OUT 0
#define PIO_BUTTON_RIGHT_HAS_TRI 0
#define PIO_BUTTON_RIGHT_IRQ 2
#define PIO_BUTTON_RIGHT_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PIO_BUTTON_RIGHT_IRQ_TYPE "LEVEL"
#define PIO_BUTTON_RIGHT_NAME "/dev/pio_button_right"
#define PIO_BUTTON_RIGHT_RESET_VALUE 0
#define PIO_BUTTON_RIGHT_SPAN 16
#define PIO_BUTTON_RIGHT_TYPE "altera_avalon_pio"


/*
 * pio_button_up configuration
 *
 */

#define ALT_MODULE_CLASS_pio_button_up altera_avalon_pio
#define PIO_BUTTON_UP_BASE 0x21220
#define PIO_BUTTON_UP_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_BUTTON_UP_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_BUTTON_UP_CAPTURE 0
#define PIO_BUTTON_UP_DATA_WIDTH 1
#define PIO_BUTTON_UP_DO_TEST_BENCH_WIRING 0
#define PIO_BUTTON_UP_DRIVEN_SIM_VALUE 0
#define PIO_BUTTON_UP_EDGE_TYPE "NONE"
#define PIO_BUTTON_UP_FREQ 50000000
#define PIO_BUTTON_UP_HAS_IN 1
#define PIO_BUTTON_UP_HAS_OUT 0
#define PIO_BUTTON_UP_HAS_TRI 0
#define PIO_BUTTON_UP_IRQ 3
#define PIO_BUTTON_UP_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PIO_BUTTON_UP_IRQ_TYPE "LEVEL"
#define PIO_BUTTON_UP_NAME "/dev/pio_button_up"
#define PIO_BUTTON_UP_RESET_VALUE 0
#define PIO_BUTTON_UP_SPAN 16
#define PIO_BUTTON_UP_TYPE "altera_avalon_pio"


/*
 * pio_hex0 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_hex0 altera_avalon_pio
#define PIO_HEX0_BASE 0x211b0
#define PIO_HEX0_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_HEX0_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_HEX0_CAPTURE 0
#define PIO_HEX0_DATA_WIDTH 7
#define PIO_HEX0_DO_TEST_BENCH_WIRING 0
#define PIO_HEX0_DRIVEN_SIM_VALUE 0
#define PIO_HEX0_EDGE_TYPE "NONE"
#define PIO_HEX0_FREQ 50000000
#define PIO_HEX0_HAS_IN 0
#define PIO_HEX0_HAS_OUT 1
#define PIO_HEX0_HAS_TRI 0
#define PIO_HEX0_IRQ -1
#define PIO_HEX0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_HEX0_IRQ_TYPE "NONE"
#define PIO_HEX0_NAME "/dev/pio_hex0"
#define PIO_HEX0_RESET_VALUE 0
#define PIO_HEX0_SPAN 16
#define PIO_HEX0_TYPE "altera_avalon_pio"


/*
 * pio_hex1 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_hex1 altera_avalon_pio
#define PIO_HEX1_BASE 0x21200
#define PIO_HEX1_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_HEX1_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_HEX1_CAPTURE 0
#define PIO_HEX1_DATA_WIDTH 7
#define PIO_HEX1_DO_TEST_BENCH_WIRING 0
#define PIO_HEX1_DRIVEN_SIM_VALUE 0
#define PIO_HEX1_EDGE_TYPE "NONE"
#define PIO_HEX1_FREQ 50000000
#define PIO_HEX1_HAS_IN 0
#define PIO_HEX1_HAS_OUT 1
#define PIO_HEX1_HAS_TRI 0
#define PIO_HEX1_IRQ -1
#define PIO_HEX1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_HEX1_IRQ_TYPE "NONE"
#define PIO_HEX1_NAME "/dev/pio_hex1"
#define PIO_HEX1_RESET_VALUE 0
#define PIO_HEX1_SPAN 16
#define PIO_HEX1_TYPE "altera_avalon_pio"


/*
 * pio_hex2 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_hex2 altera_avalon_pio
#define PIO_HEX2_BASE 0x211f0
#define PIO_HEX2_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_HEX2_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_HEX2_CAPTURE 0
#define PIO_HEX2_DATA_WIDTH 7
#define PIO_HEX2_DO_TEST_BENCH_WIRING 0
#define PIO_HEX2_DRIVEN_SIM_VALUE 0
#define PIO_HEX2_EDGE_TYPE "NONE"
#define PIO_HEX2_FREQ 50000000
#define PIO_HEX2_HAS_IN 0
#define PIO_HEX2_HAS_OUT 1
#define PIO_HEX2_HAS_TRI 0
#define PIO_HEX2_IRQ -1
#define PIO_HEX2_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_HEX2_IRQ_TYPE "NONE"
#define PIO_HEX2_NAME "/dev/pio_hex2"
#define PIO_HEX2_RESET_VALUE 0
#define PIO_HEX2_SPAN 16
#define PIO_HEX2_TYPE "altera_avalon_pio"


/*
 * pio_hex3 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_hex3 altera_avalon_pio
#define PIO_HEX3_BASE 0x211e0
#define PIO_HEX3_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_HEX3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_HEX3_CAPTURE 0
#define PIO_HEX3_DATA_WIDTH 7
#define PIO_HEX3_DO_TEST_BENCH_WIRING 0
#define PIO_HEX3_DRIVEN_SIM_VALUE 0
#define PIO_HEX3_EDGE_TYPE "NONE"
#define PIO_HEX3_FREQ 50000000
#define PIO_HEX3_HAS_IN 0
#define PIO_HEX3_HAS_OUT 1
#define PIO_HEX3_HAS_TRI 0
#define PIO_HEX3_IRQ -1
#define PIO_HEX3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_HEX3_IRQ_TYPE "NONE"
#define PIO_HEX3_NAME "/dev/pio_hex3"
#define PIO_HEX3_RESET_VALUE 0
#define PIO_HEX3_SPAN 16
#define PIO_HEX3_TYPE "altera_avalon_pio"


/*
 * pio_hex4 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_hex4 altera_avalon_pio
#define PIO_HEX4_BASE 0x211d0
#define PIO_HEX4_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_HEX4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_HEX4_CAPTURE 0
#define PIO_HEX4_DATA_WIDTH 7
#define PIO_HEX4_DO_TEST_BENCH_WIRING 0
#define PIO_HEX4_DRIVEN_SIM_VALUE 0
#define PIO_HEX4_EDGE_TYPE "NONE"
#define PIO_HEX4_FREQ 50000000
#define PIO_HEX4_HAS_IN 0
#define PIO_HEX4_HAS_OUT 1
#define PIO_HEX4_HAS_TRI 0
#define PIO_HEX4_IRQ -1
#define PIO_HEX4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_HEX4_IRQ_TYPE "NONE"
#define PIO_HEX4_NAME "/dev/pio_hex4"
#define PIO_HEX4_RESET_VALUE 0
#define PIO_HEX4_SPAN 16
#define PIO_HEX4_TYPE "altera_avalon_pio"


/*
 * pio_hex5 configuration
 *
 */

#define ALT_MODULE_CLASS_pio_hex5 altera_avalon_pio
#define PIO_HEX5_BASE 0x211c0
#define PIO_HEX5_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_HEX5_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_HEX5_CAPTURE 0
#define PIO_HEX5_DATA_WIDTH 7
#define PIO_HEX5_DO_TEST_BENCH_WIRING 0
#define PIO_HEX5_DRIVEN_SIM_VALUE 0
#define PIO_HEX5_EDGE_TYPE "NONE"
#define PIO_HEX5_FREQ 50000000
#define PIO_HEX5_HAS_IN 0
#define PIO_HEX5_HAS_OUT 1
#define PIO_HEX5_HAS_TRI 0
#define PIO_HEX5_IRQ -1
#define PIO_HEX5_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_HEX5_IRQ_TYPE "NONE"
#define PIO_HEX5_NAME "/dev/pio_hex5"
#define PIO_HEX5_RESET_VALUE 0
#define PIO_HEX5_SPAN 16
#define PIO_HEX5_TYPE "altera_avalon_pio"


/*
 * pio_leds configuration
 *
 */

#define ALT_MODULE_CLASS_pio_leds altera_avalon_pio
#define PIO_LEDS_BASE 0x21250
#define PIO_LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_LEDS_CAPTURE 0
#define PIO_LEDS_DATA_WIDTH 10
#define PIO_LEDS_DO_TEST_BENCH_WIRING 0
#define PIO_LEDS_DRIVEN_SIM_VALUE 0
#define PIO_LEDS_EDGE_TYPE "NONE"
#define PIO_LEDS_FREQ 50000000
#define PIO_LEDS_HAS_IN 0
#define PIO_LEDS_HAS_OUT 1
#define PIO_LEDS_HAS_TRI 0
#define PIO_LEDS_IRQ -1
#define PIO_LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_LEDS_IRQ_TYPE "NONE"
#define PIO_LEDS_NAME "/dev/pio_leds"
#define PIO_LEDS_RESET_VALUE 0
#define PIO_LEDS_SPAN 16
#define PIO_LEDS_TYPE "altera_avalon_pio"


/*
 * pio_random configuration
 *
 */

#define ALT_MODULE_CLASS_pio_random altera_avalon_pio
#define PIO_RANDOM_BASE 0x211a0
#define PIO_RANDOM_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_RANDOM_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_RANDOM_CAPTURE 0
#define PIO_RANDOM_DATA_WIDTH 8
#define PIO_RANDOM_DO_TEST_BENCH_WIRING 0
#define PIO_RANDOM_DRIVEN_SIM_VALUE 0
#define PIO_RANDOM_EDGE_TYPE "NONE"
#define PIO_RANDOM_FREQ 50000000
#define PIO_RANDOM_HAS_IN 1
#define PIO_RANDOM_HAS_OUT 0
#define PIO_RANDOM_HAS_TRI 0
#define PIO_RANDOM_IRQ -1
#define PIO_RANDOM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_RANDOM_IRQ_TYPE "NONE"
#define PIO_RANDOM_NAME "/dev/pio_random"
#define PIO_RANDOM_RESET_VALUE 0
#define PIO_RANDOM_SPAN 16
#define PIO_RANDOM_TYPE "altera_avalon_pio"


/*
 * pio_tray_len configuration
 *
 */

#define ALT_MODULE_CLASS_pio_tray_len altera_avalon_pio
#define PIO_TRAY_LEN_BASE 0x21180
#define PIO_TRAY_LEN_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_TRAY_LEN_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_TRAY_LEN_CAPTURE 0
#define PIO_TRAY_LEN_DATA_WIDTH 16
#define PIO_TRAY_LEN_DO_TEST_BENCH_WIRING 0
#define PIO_TRAY_LEN_DRIVEN_SIM_VALUE 0
#define PIO_TRAY_LEN_EDGE_TYPE "NONE"
#define PIO_TRAY_LEN_FREQ 50000000
#define PIO_TRAY_LEN_HAS_IN 0
#define PIO_TRAY_LEN_HAS_OUT 1
#define PIO_TRAY_LEN_HAS_TRI 0
#define PIO_TRAY_LEN_IRQ -1
#define PIO_TRAY_LEN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_TRAY_LEN_IRQ_TYPE "NONE"
#define PIO_TRAY_LEN_NAME "/dev/pio_tray_len"
#define PIO_TRAY_LEN_RESET_VALUE 0
#define PIO_TRAY_LEN_SPAN 16
#define PIO_TRAY_LEN_TYPE "altera_avalon_pio"


/*
 * pio_tray_pos configuration
 *
 */

#define ALT_MODULE_CLASS_pio_tray_pos altera_avalon_pio
#define PIO_TRAY_POS_BASE 0x21190
#define PIO_TRAY_POS_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_TRAY_POS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_TRAY_POS_CAPTURE 0
#define PIO_TRAY_POS_DATA_WIDTH 16
#define PIO_TRAY_POS_DO_TEST_BENCH_WIRING 0
#define PIO_TRAY_POS_DRIVEN_SIM_VALUE 0
#define PIO_TRAY_POS_EDGE_TYPE "NONE"
#define PIO_TRAY_POS_FREQ 50000000
#define PIO_TRAY_POS_HAS_IN 0
#define PIO_TRAY_POS_HAS_OUT 1
#define PIO_TRAY_POS_HAS_TRI 0
#define PIO_TRAY_POS_IRQ -1
#define PIO_TRAY_POS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_TRAY_POS_IRQ_TYPE "NONE"
#define PIO_TRAY_POS_NAME "/dev/pio_tray_pos"
#define PIO_TRAY_POS_RESET_VALUE 0
#define PIO_TRAY_POS_SPAN 16
#define PIO_TRAY_POS_TYPE "altera_avalon_pio"


/*
 * sysid_qsys_0 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_qsys_0 altera_avalon_sysid_qsys
#define SYSID_QSYS_0_BASE 0x21270
#define SYSID_QSYS_0_ID 0
#define SYSID_QSYS_0_IRQ -1
#define SYSID_QSYS_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_QSYS_0_NAME "/dev/sysid_qsys_0"
#define SYSID_QSYS_0_SPAN 8
#define SYSID_QSYS_0_TIMESTAMP 1648954371
#define SYSID_QSYS_0_TYPE "altera_avalon_sysid_qsys"

#endif /* __SYSTEM_H_ */
