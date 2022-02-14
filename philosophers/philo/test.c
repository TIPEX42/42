# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdarg.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_timestamp
{
	uint64_t	usecs;
	uint64_t	secs;
}				t_timestamp;

void	set_timestamp(t_timestamp *timestamp)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	timestamp->usecs = time.tv_usec;
	timestamp->secs = time.tv_sec;
}

int	time_elapsed_since(t_timestamp ts, uint64_t time)
{
	struct timeval	current_time;
	uint64_t		elapsedms;

	gettimeofday(&current_time, NULL);
	elapsedms = (current_time.tv_sec - ts.secs) * 1000;
	if ((int64_t)current_time.tv_usec - (int64_t)ts.usecs < 0)
	{
		elapsedms -= 1000;
		elapsedms += (current_time.tv_usec + 1000000 - ts.usecs) / 1000;
	}
	else
		elapsedms += (current_time.tv_usec - ts.usecs) / 1000;
	if (elapsedms > time / 1000)
		return (1);
	return (0);
}

#include <time.h>
#include <stdlib.h>

void	my_sleep(int time)
{
	t_timestamp	ts;

	set_timestamp(&ts);
	while (!time_elapsed_since(ts, time - 4000))
	{
		if (rand() == 10000000)
			return ;
	}
}

int main()
{
	srand(time(NULL));
	my_sleep(500000);
}