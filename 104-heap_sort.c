#include "sort.h"
#include "stdio.h"

/**
  * heap_sort - Sorts an array using heap sort algorithm
  * @array: Array to sort
  * @size: Size of array
  *
  * Return: Void (Nothing)
  */
void heap_sort(int *array, size_t size)
{
	heapint_t *root = NULL, *rt;
	size_t uter;
	int pos, itemp, iter;

	if (!array || size < 2)
		return;
	for (uter = 0; uter < size; uter++)
	{
		rt = malloc(sizeof(*rt));
		if (!rt)
			return;
		rt->pos = uter;
		rt->parent = NULL;
		rt->cleft = NULL;
		rt->cright = NULL;
		fill_heap(&root, rt, array);
	}
	for (iter = size - 1; iter >= 0; iter--)
	{
		pos = pop_heap(&root, array);
		if (iter != pos)
		{
			itemp = array[iter];
			array[iter] = array[pos];
			array[pos] = itemp;
			rt = find_pos(root, iter);
			rt->pos = pos;
		}
		print_array(array, size);
	}
}

/**
  * find_pos - Find the node with specified position
  * @root: Root of heap
  * @pos: Specified position
  *
  * Return: Void (Nothing)
  */
heapint_t *find_pos(heapint_t *root, size_t pos)
{
	heapint_t *hp;

	if (!root)
		return (NULL);
	if (root->pos == pos)
		return (root);
	hp = find_pos(root->cleft, pos);
	if (hp)
		return (hp);
	hp = find_pos(root->cright, pos);
	if (hp)
		return (hp);
	return (NULL);
}

/**
  * fill_heap - Populates a heap with respect array positions
  * @root: Root of the heap
  * @node: Node to insert
  * @array: Array used for heap population
  *
  * Return: Void (Nothing)
  */
void fill_heap(heapint_t **root, heapint_t *node, int *array)
{
	heapint_t *rt = *root;

	if (!(*root))
	{
		*root = node;
		return;
	}
	if (array[rt->pos] < array[node->pos])
	{
		*root = node;
		node->parent = rt->parent;
		node->cleft = rt->cleft;
		node->cright = rt->cright;
		rt->parent = NULL;
		rt->cleft = NULL;
		rt->cright = NULL;
		node = rt;
		rt = *root;

	}
	if (!(rt->cright))
	{
		node->parent = rt;
		if (!(rt->cleft))
		{
			rt->cleft = node;
			return;
		}
		rt->cright = node;
		return;
	}
	fill_heap(&((*root)->cleft), node, array);
}

/**
  * insert_branch - Incorporate side branch into main heap
  * @root: Root of branch
  * @plucked: Side branch
  * @array: Array to sort
  *
  * Return: Void (Nothing)
  */
void insert_branch(heapint_t **root, heapint_t *plucked, int *array)
{
	heapint_t *rt = *root, *htemp;

	while (plucked)
	{
		if (!(rt->cright))
		{
			if (rt->cleft)
			{
				rt->cright = plucked;
				plucked->parent = rt;
			}
			else
			{
				rt->cleft = plucked->cleft;
				rt->cright = plucked->cright;
				plucked->cleft = NULL;
				plucked->cright = NULL;
				fill_heap(&rt, plucked, array);
			}
			plucked = NULL;
			continue;
		}
		if (array[(rt->cleft->pos)] < array[plucked->pos])
		{
			htemp = rt->cleft;
			rt->cleft = plucked;
			plucked = htemp;
		}
		else if (array[rt->cright->pos] < array[plucked->pos])
		{
			htemp = rt->cright;
			rt->cright = plucked;
			plucked = htemp;
		}
		rt = rt->cleft;
	}
}

/**
  * pop_heap - Pops the root node from heap
  * @root: Root of heap
  * @array: Array to sort
  *
  * Return: Void (Nothing)
  */
int pop_heap(heapint_t **root, int *array)
{
	heapint_t *rt = *root, *plucked = NULL;
	int ind;

	if (!rt)
		return (-1);
	ind = rt->pos;
	if (!(rt->cleft))
	{
		free(rt);
		*root = NULL;
		return (ind);
	}
	if (!(rt->cright))
	{
		*root = rt->cleft;
		(*root)->parent = NULL;
		free(rt);
		return (ind);
	}
	if (array[(rt->cleft)->pos] >= array[rt->cright->pos])
	{
		*root = rt->cleft;
		plucked = rt->cright;
	}
	else
	{
		*root = rt->cright;
		plucked = rt->cleft;
	}
	free(rt);
	rt = *root;
	rt->parent = NULL;
	insert_branch(root, plucked, array);
	return (ind);
}
