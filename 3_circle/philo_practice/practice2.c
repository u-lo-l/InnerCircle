#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef pthread_mutex_t	t_mutex;

struct table;

typedef struct temp
{
	int			id;
	int			count;
	t_mutex		*left;
	t_mutex		*right;
	t_mutex		*put_log;
	pthread_t	thread;
	struct table *tab;
}		t_temp;

typedef struct table
{
	int		total_num;
	int		total_cnt;
	t_mutex	log;
	t_mutex	*mutex_arr;
	t_temp	*temp_arr;
}			t_table;

t_mutex	mut;

void	*two_mut_func(void *vargp)
{
	t_temp	*temp = vargp;

	pthread_mutex_lock(&mut);
	printf("=====VARG INFO=====\n");
	printf("ID : %d\n", temp->id);
	printf("L  : %p\n", temp->left);
	printf("R  : %p\n", temp->right);
	printf("===================\n");
	pthread_mutex_unlock(&mut);

	pthread_mutex_lock(temp->left);
	printf("%d locked left\n", temp->id);
	pthread_mutex_lock(temp->right);
	printf("%d locked right\n", temp->id);
	pthread_mutex_lock(&mut);
	printf("%d wait for 1sec\n", temp->id);
	int k;
	printf("@@@@@@\n");
	for (k = 0 ; k < temp->tab->total_cnt ; k++)
	{
		printf("%d->%d\n", temp->id, k + 1);
		usleep(1000000 / temp->tab->total_cnt);
	}
	printf("@@@@@@\n");
	pthread_mutex_unlock(&mut);
	pthread_mutex_unlock(temp->left);
	pthread_mutex_unlock(temp->right);
	printf("%d unlock\n\n", temp->id);
}

int main()
{
	t_table	table;

	table.total_num = 5;
	table.total_cnt	= 3;
	table.mutex_arr = malloc(sizeof(t_mutex) * table.total_num);
	table.temp_arr = malloc(sizeof(t_temp) * table.total_num);
	
	pthread_mutex_init(&mut, NULL);
	for (int i = 0 ; i < table.total_num ; i++)
		pthread_mutex_init(table.mutex_arr + i , NULL);
	for (int i = 0 ; i < table.total_num ; i++)
	{
		table.temp_arr[i].id = i + 1;
		table.temp_arr[i].tab = &table;
		table.temp_arr[i].left = &table.mutex_arr[i];
		table.temp_arr[i].right = &table.mutex_arr[(i + 1) % table.total_num];
		pthread_create(&(table.temp_arr[i].thread), NULL, two_mut_func, &(table.temp_arr[i]));
		usleep(1);
	}
	for (int i = 0 ; i < table.total_num ; i++)
		pthread_join(table.temp_arr[i].thread, NULL);
	for (int i = 0 ; i < table.total_num; i++)
		pthread_mutex_destroy(table.mutex_arr + i);
	free(table.mutex_arr);
	free(table.temp_arr);
	return (0);
}