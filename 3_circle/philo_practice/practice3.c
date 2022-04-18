#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

long	get_ltime(void)
{
	struct timeval	time;
	long			mili_sec;
	
	gettimeofday(&time, NULL);
	mili_sec = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (mili_sec);
}

int main()
{
	long start = get_ltime();
	usleep(1000 * 10);
	long now = get_ltime();

	printf("%ld %ld %ld\n", now, start, now - start);
}