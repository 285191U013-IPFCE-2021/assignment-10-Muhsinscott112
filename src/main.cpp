extern "C"
{
#include <stdio.h>
#include "linked_list.h"

	// Add the header files required to run your main
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{

	int sum;
	node *ns = NULL;
	ns = make_node(1,
				   make_node(2,
							 make_node(3,
									   make_node(4,
												 make_node(5,
														   &SENTINEL_node)))));

	print_list(ns);

	printf("\n");

	printf("Testing for sum squares function: ");
	printf("Sum of squares = %d", sum_squares(ns));

	printf("\n");

	printf("\nTesting for map function\n");

	node *mns = map(ns, square);
	mns = map(ns, square);
	print_list(mns);

	printf("====================================");
	printf("\n All tests passed");
	
	return 0;
}
