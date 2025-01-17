#ifndef _INCLUDE_UTRAP_H
#define _INCLUDE_UTRAP_H

/*  
 * This is used for dasics utrap handler, include all struct and handler
 */

#include <stdint.h>
#include <stddef.h>

typedef unsigned long reg_t;


/**
 * The register which needed to be saved by the callee will be save properly 
 * by the standered RISCV ABI
 */
struct ucontext_trap
{
	reg_t uepc;
	reg_t utval;
	reg_t ucause;

    /* Saved main processor registers.*/
	reg_t ra;
	reg_t sp;
	reg_t t0;
	reg_t t1;
	reg_t t2;
	reg_t t3;
	reg_t t4;
	reg_t t5;
	reg_t t6;	
    reg_t a0;
	reg_t a1;
	reg_t a2;
	reg_t a3;
	reg_t a4;
	reg_t a5;
	reg_t a6;
	reg_t a7;
};


#define OFFSET_TRAP_UEPC    (8*0)
#define OFFSET_TRAP_UTVAL   (8*1)
#define OFFSET_TRAP_UCAUSE  (8*2)
#define OFFSET_TRAP_RA      (8*3)
#define OFFSET_TRAP_SP      (8*4)
#define OFFSET_TRAP_T0      (8*5)
#define OFFSET_TRAP_T1      (8*6)
#define OFFSET_TRAP_T2      (8*7)
#define OFFSET_TRAP_T3      (8*8)
#define OFFSET_TRAP_T4      (8*9)
#define OFFSET_TRAP_T5      (8*10)
#define OFFSET_TRAP_T6      (8*11)
#define OFFSET_TRAP_A0      (8*12)
#define OFFSET_TRAP_A1      (8*13)
#define OFFSET_TRAP_A2      (8*14)
#define OFFSET_TRAP_A3      (8*15)
#define OFFSET_TRAP_A4      (8*16)
#define OFFSET_TRAP_A5      (8*17)
#define OFFSET_TRAP_A6      (8*18)
#define OFFSET_TRAP_A7      (8*19)


#define OFFSET_SIZE         (8*20)

/* DASICS exceptions */
#define EXC_DASICS_UCHECK_FAULT     24

/* DASICS ufault reasons */
#define DFR_NO_DASICS_FAULT 		0
#define DFR_ECALL_DASICS_FAULT 		1
#define DFR_LOAD_DASICS_FAULT 		2
#define DFR_STORE_DASICS_FAULT 		3
#define DFR_JUMP_DASICS_FAULT 		4
#define DFR_LOAD_MPK_FAULT 			5
#define DFR_STORE_MPK_FAULT 		6

typedef int (*utrap_handler)(struct ucontext_trap * regs);

/*
 * Three types of U-exception types
 */
int handle_DasicsUFetchFault(struct ucontext_trap * regs);
int handle_DasicsULoadFault(struct ucontext_trap * regs);
int handle_DasicsUStoreFault(struct ucontext_trap * regs);
int handle_DasicsUEcallFault(struct ucontext_trap * regs);


extern long invoke_syscall(struct ucontext_trap * regs);



#endif