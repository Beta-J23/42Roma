
#include "push_swap.h"

int	array_filler(t_stack_a *a, char **argv, int argc)
{
	int		i;
	int		z;

	i = 0;
	z = 0;
	array_filler_helper_1(a, argv, argc, i);
	if (argc > 2)
	{
		i = 1;
		z = array_filler_helper_2(a, argc, argv, z);
		a->array_a[z] = '\0';
	}
	//free (a->array_a);
	return (0);
}

int	array_filler_helper_1(t_stack_a *a, char **argv, int argc, int i)
{
	if (argc == 1)
	{
		write (1, "Error: invalid number of args\n", 31);
		exit (0);
	}
	if (argc == 2)
	{
		a->array_a = (char *)ft_calloc(ft_strlen(argv[1]), sizeof(char));
		while (argv[1][i] != '\0')
		{
			a->array_a[i] = argv[1][i];
			i++;
		}
		a->array_a[i] = '\0';
	}
	return (0);
}

int	array_filler_helper_2(t_stack_a *a, int argc, char **argv, int z)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	k = 0;
	while (i < argc)
	{
		while (argv[i][k] != '\0')
		{
			j++;
			k++;
			//ft_printf("J = %d\n", j);
		}
		j++;
		i++;
	}
	// ft_printf ("J FINE CICLO = %d\n", j);
	a->array_a = (char *)ft_calloc(j, sizeof(char));
	z = array_filler_helper_2_1(a, argc, argv, z);
	return (z);
}

int	array_filler_helper_2_1(t_stack_a *a, int argc, char **argv, int z)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			a->array_a[z] = argv[i][j];
			j++;
			z++;
		}
		a->array_a[z] = ' ';
		i++;
		z++;
	}
	return (z);
}
