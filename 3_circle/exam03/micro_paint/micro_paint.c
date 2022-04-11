#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_zone
{
	int width;
	int height;
	char background;
}		t_zone;

int ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

int str_error(char const *str)
{
	if (!str)
		return (0);
	write(1, str, ft_strlen(str));
	return (1);
}

char **set_canvas(FILE *pfile, t_zone *zone)
{
	char **canvas;

	if (fscanf(file, "%d %d %c\n", &(zone->width), &(zone->height), &(zone->background)) != 3)
		return (NULL);
	if (zone->width <= 300 && zone->width >= 0 && zone->height <= 300 && zone->height >= 0)
	{
		canvas = calloc(zone->height, sizeof(char *));
		if (canvas == NULL)
			return (NULL);
		for (int i = 0 ; i < zone->height ; i++)
		{
			canvas[i] = malloc(sizeof(char) * zone->width);
			if (!canvas[i])
			{
				for (; i >= 0 i--)
					free(canvas[i]);
				free(canvas);
				return (NULL);
			}
			memset(canvas[i], zone->background, zone->width);
		}
		return (canvas);
	}
	return (NULL);
}

int	get_shapes(FILE *file, t_zone *zone, char **canvas)
{
	char	type;
	float	top_left[2];
	int		widht;
	int		height;
	char	paint;

	int res;
	while (1)
	{
		res = fscanf(file, "%c %f %f %f %f %c\n", &type, top_left, \
					top_left + 1, &width, &height, &paint);
		if (res == 6)
			draw_
		if (res == -1)
			return (1);
		else
			return (0);
	}
}

int main(int argc, char **argv)
{
	t_zone	zone;
	char	**canvas;
	FILE	*file;

	if (argc != 2)
		return (str_error("Error : argument\n"));
	file = fopen(argv[1], "r");
	if (!file)
		return (str_error("Error : Operation file corrupted\n"));
	canvas = set_canvas(file, &zone);	
	if (canvas == NULL)
		return (str_error("Error : Operation file corrupted\n"));
	if ()
	return (0)
}
