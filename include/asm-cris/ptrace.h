#ifndef _CRIS_PTRACE_H
#define _CRIS_PTRACE_H

#include <asm/arch/ptrace.h>

/* Arbitrarily choose the same ptrace numbers as used by the Sparc code. */
#define PTRACE_GETREGS            12
#define PTRACE_SETREGS            13

#endif /* _CRIS_PTRACE_H */
