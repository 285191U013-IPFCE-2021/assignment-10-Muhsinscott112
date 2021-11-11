extern "C"{
    
    #include <stdio.h>
    #include "linked_list.h"

    // Add the header files required to run your main 
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{

    	int sum;
      node *ns = NULL;
    	ns = make_node (1,
			make_node (2,
				   make_node (3,
					      make_node (4,
							  make_node (5,
								    &SENTINEL_node)))));

node *mns = map (ns, square);

mns = map (ns, square);

print_list(mns);


struct tree_node *root = NULL;

  root = Initialize (root);
  root = Insert (20, root);
  root = Insert (5, root);
  root = Insert (1, root);
  root = Insert (15, root);
  root = Insert (9, root);
  root = Insert (7, root);
  root = Insert (12, root);
  root = Insert (30, root);
  root = Insert (25, root);
  root = Insert (40, root);
  root = Insert (45, root);
  root = Insert (42, root);

  REQUIRE(Contains (20, root) == 1);
  REQUIRE (Contains (5, root) == 1);
  REQUIRE (Contains (1, root) == 1);
  REQUIRE (Contains (15, root) == 1);
  REQUIRE (Contains (9, root) == 1);
  REQUIRE (Contains (7, root) == 1);
  REQUIRE (Contains (12, root) == 1);
  REQUIRE (Contains (30, root) == 1);
  REQUIRE (Contains (25, root) == 1);
  REQUIRE (Contains (40, root) == 1);
  REQUIRE (Contains (45, root) == 1);
  REQUIRE (Contains (42, root) == 1);
  REQUIRE (Contains (2, root) == 0);
  REQUIRE (Contains (3, root) == 0);



  // (A)
  REQUIRE (Empty (Initialize (NULL)));


  // (B) and (C)

  root = Insert (3, root);

  REQUIRE (Contains (3, root) == 1);

  root = Remove (3, root);

  REQUIRE (Contains (20, root) == 1);
  REQUIRE (Contains (5, root) == 1);
  REQUIRE (Contains (1, root) == 1);
  REQUIRE (Contains (15, root) == 1);
  REQUIRE (Contains (9, root) == 1);
  REQUIRE (Contains (7, root) == 1);
  REQUIRE (Contains (12, root) == 1);
  REQUIRE (Contains (30, root) == 1);
  REQUIRE (Contains (25, root) == 1);
  REQUIRE (Contains (40, root) == 1);
  REQUIRE (Contains (45, root) == 1);
  REQUIRE (Contains (42, root) == 1);

  REQUIRE (Contains (2, root) == 0);
  REQUIRE (Contains (3, root) == 0);





  // (D) and (E)
  root = Insert (-1, root);
  root = Insert (-1, root);
  root = Remove (-1, root);
  REQUIRE (Contains (-1, root) == 1);
  root = Remove (-1, root);
  REQUIRE (Contains (-1, root) == 0);


  //REQUIRE (Full (root) == false);

  root = Remove (45, root);
  root = Remove (42, root);
  root = Insert (16, root);


  REQUIRE (Contains (20, root) == 1);
  REQUIRE (Contains (5, root) == 1);
  REQUIRE (Contains (1, root) == 1);
  REQUIRE (Contains (15, root) == 1);
  REQUIRE (Contains (9, root) == 1);
  REQUIRE (Contains (7, root) == 1);
  REQUIRE (Contains (12, root) == 1);
  REQUIRE (Contains (30, root) == 1);
  REQUIRE (Contains (25, root) == 1);
  REQUIRE (Contains (40, root) == 1);
  REQUIRE (Contains (45, root) == 0);
  REQUIRE (Contains (42, root) == 0);
  REQUIRE (Contains (16, root) == 1);

  REQUIRE (Full (root) == 1);

  root = Remove (7, root);

  REQUIRE (Contains (16, root) == 1);
  REQUIRE (Contains (20, root) == 1);
  REQUIRE (Contains (5, root) == 1);
  REQUIRE (Contains (1, root) == 1);
  REQUIRE (Contains (15, root) == 1);
  REQUIRE (Contains (9, root) == 1);
  REQUIRE (Contains (7, root) == 0);
  REQUIRE (Contains (12, root) == 1);
  REQUIRE (Contains (30, root) == 1);
  REQUIRE (Contains (25, root) == 1);
  REQUIRE (Contains (40, root) == 1);
  REQUIRE (Contains (45, root) == 0);


  root = Remove (1, root);
  root = Remove (7, root);
  root = Remove (12, root);
  root = Remove (9, root);
  root = Remove (15, root);
  root = Remove (5, root);
  root = Remove (42, root);
  root = Remove (45, root);
  root = Remove (25, root);
  root = Remove (40, root);
  root = Remove (30, root);
  root = Remove (20, root);
  root = Remove (16, root);


  free (root);


    return 0;

}
