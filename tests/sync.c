/* sync.c
 * Test program for synchronous signal behavior in
 * dtrace.
 * 
 * cc -o sync sync.c
 * dtrace -s sync.d -c ./sync
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ucontext.h>
#include <signal.h>

void sig(int no, siginfo_t *si, void *data)
{
	ucontext_t *uc = (ucontext_t *) data;
	int i , j;
	
	printf("Caught SIGFPE at IP %lx\n", uc->uc_mcontext.mc_rip);
	
	uc->uc_mcontext.mc_rip += 2;
	i = j / 7;
	
	
}

int main()
{
	struct sigaction sa, osa;
	 int b = 5;
	
	sa.sa_flags = SA_ONSTACK | SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = sig;
	sigaction(SIGFPE, &sa, &osa);
	
	b = b / 0;
	printf("Done\n");
	return 0;
}

