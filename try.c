
#include <stdio.h>
#include "tree.h"

tnode full_tree(unsigned, int);

int main(void) {
  tnode t = full_tree(4, 1);
  
  set_all_followers(t);
  depth_first_print(t, 0);
}

/* return the root of a full tree with depth d */
tnode full_tree(unsigned d, int root_label) {
  tnode t = NULL;
  if (d == 0) return NULL;
  t = talloc(root_label);
  t->lt = full_tree(d-1, root_label*2);
  t->rt = full_tree(d-1, t->lt ? t->lt->val + 1 : root_label*2 + 1);
  t->follower = NULL;
  return t;
}


