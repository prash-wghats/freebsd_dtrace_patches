/* PGRAB_RDONLY 
 * ./loop &
 * dtrace -n 'syscall::write:entry /execname == "loop"/ {ustack();}'
 */
#include <stdio.h>

int main()
{	
	int i = 0;
	while (1) {
		printf("hello world %d\n", i++);
		sleep(1);
	}
	return 0;
}
///