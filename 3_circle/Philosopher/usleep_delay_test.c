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
	long	start = timestamp();
	while (timestamp()  < start + msec * 1000)
		usleep(10);
}

int	lminl(long *arr, int size)
{
	long min = 21474836474800L;
	int min_i = 0;

	int i = 0;
	while (i < size)
	{
		if (min > arr[i])
		{
			min = arr[i];
			min_i = i;
		}
		i++;
	}
	return (min_i);
}

#include <string.h>
#define SIZE 20
int main()
{
	long last;
	long curr;
	long avg = 0;
	long max = 0;
	for (int i = 1 ; i <= 100 ; i++)
	{
		last = timestamp();
		mili_sleep(200);
		curr = timestamp();
		max = max < (curr - last) ? (curr - last) : max;
		avg	= (avg * (i - 1) + (curr - last)) / i; 
		printf("%ld.%03ldms\n", (curr - last) / 1000 , (curr - last) % 1000);
	}
	printf("min of max : %ld.%03ld\n", max / 1000, max % 1000);
	printf("min of avg : %ld.%03ld\n", avg / 1000, avg % 1000);
	return (0);
}