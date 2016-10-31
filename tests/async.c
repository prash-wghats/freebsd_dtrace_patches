/* async.c
 * Test program for asynchronous signal behavior in
 * dtrace.
 * 
 * cc -o async async.c -pthread
 * dtrace -s async.d -c ./async
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

void 
func(int *p)
{
	int i, j;

	while (1) {
		int		k;

		usleep(1000);
		for (k = 0; k < 80; k++)
			j = i / 99;
	}

}

void 
sig_func(int no, siginfo_t * si, void *data)
{
	ucontext_t *uc = (ucontext_t *) data;
	int i, j;

	printf("Caught signal %d at IP %lx\n", no, uc->uc_mcontext.mc_rip);
	j = i / 99;
}

int 
main()
{
	pthread_t tid;
	pthread_attr_t attr;
	int d = 10;
	struct sigaction sa, osa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_func;
	sigaction(SIGILL, &sa, &osa);

	pthread_attr_init(&attr);
	pthread_create(&tid, &attr, (void *)func, &d);
	
	while (1) {
		usleep(1000000);
		pthread_kill(tid, SIGILL);
	}

	pthread_join(tid, NULL);
	
	return 0;
}


