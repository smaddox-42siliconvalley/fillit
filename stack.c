#include "fillit.h"


stack *init_stack(int size)
{
	stack *address_stack;
	address_stack = (stack*)malloc(sizeof(struct STACK));
	address_stack->capacity = size;
	address_stack->top = -1;
	address_stack->array = (t_cell**)malloc(size * sizeof(t_cell*));
	return(address_stack);
}


int is_full(stack *address_stack)
{
	if(address_stack->top == address_stack->capacity - 1)
		return(1);
	return(0);
}

int is_empty(stack *address_stack)
{
	if(address_stack->top == -1)
		return(1);
	return(0);
}

void  push(stack *address_stack, t_cell *choice)
{
//	printf("push ");
//	print_choice(choice);
	if(is_full(address_stack))
	{
		printf("full\n");
		return;
	}
	address_stack->array[++address_stack->top] = choice;
}

t_cell *pop(stack *address_stack)
{
//	printf("pop ");
//	print_choice(address_stack->array[address_stack->top]);
	if(is_empty(address_stack))
			return(NULL);
	return(address_stack->array[address_stack->top--]);
}

void show_stack(stack *address_stack)
{
	while(!(is_empty(address_stack)))
		print_choice(pop(address_stack));
}

