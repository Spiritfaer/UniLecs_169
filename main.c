#include <stdio.h>
#include <stdint.h>
#include <malloc.h>

typedef struct	s_arr
{
	int32_t 	*arr;
	int32_t 	size;
}				t_arr;

t_arr*	constructor_arr(int32_t const *arr, int32_t size)
{
	t_arr *var;
	if (!arr || size <= 0)
		return (NULL);
	if (!(var = (t_arr*)malloc(sizeof(t_arr))))
		return (NULL);
	var->size = size;
	if (!(var->arr = (int32_t*)malloc(sizeof(int32_t) * size)))
	{
		var->size = 0;
		free(var);
		var = NULL;
		return (NULL);
	}
	for (int32_t i =0; i < size; i++)
		var->arr[i] = arr[i];
	return (var);
}

void	destructor_arr(t_arr **var)
{
	(*var)->size = 0;
	free((*var)->arr);
	(*var)->arr = NULL;
	free(*var);
	*var = NULL;
}

int32_t	get_min_element(t_arr *one, t_arr *two, t_arr *three)
{
	int32_t i,j,k;
	i = j = k = 0;
	while (i < one->size && j < two->size && k < three->size)
	{
		if (one->arr[i] == two->arr[j] && one->arr[i] == three->arr[k])
			return (one->arr[i]);
		if (one->arr[i] <= two->arr[j] && one->arr[i] <= three->arr[k])
			i++;
		else if (two->arr[j] <= one->arr[i] && two->arr[j] <= three->arr[k])
			j++;
		else if (three->arr[k] <= one->arr[i] && three->arr[k] <= two->arr[j])
			k++;
	}
	return (0);
}

int main(void) {

	int32_t arr_1[] = { -10,3,5,7,10,11,12,25,36};
	int32_t arr_2[] = { -10,0,3,4,11,12,44};
	int32_t arr_3[] = { -10, -2,3,4,5,12,13,24};

	t_arr *one = constructor_arr(arr_1, sizeof(arr_1)/sizeof(int32_t));
	t_arr *two = constructor_arr(arr_2, sizeof(arr_2)/sizeof(int32_t));
	t_arr *three = constructor_arr(arr_3, sizeof(arr_3)/sizeof(int32_t));

	printf("Min element is = %d\n", get_min_element(one,two,three));

	destructor_arr(&one);
	destructor_arr(&two);
	destructor_arr(&three);
	return (0);
}
