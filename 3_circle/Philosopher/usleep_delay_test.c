#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

long	timestamp(void)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	mili_sleep(long msec)
{
	long	time = timestamp();
	long	start = timestamp();
	while (time  < start + msec * 1000)
	{
		usleep(10);
		time = timestamp();
	}
}

int main()
{
	long last = timestamp();
	long curr;
	long avr;
	long max = 0;
	for (int i = 0 ; i < 100 ; i++)
	{
		curr = timestamp();
		max = max < (curr - last) ? (curr -last) : max;
		printf("%ld.%ldms\n", (curr - last) / 1000 , (curr - last) % 1000);
		last = curr;
		mili_sleep(100);
	}
	printf("max : %ld.%ldms\n", max / 1000 , max % 1000);
	return (0);
}