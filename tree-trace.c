
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tnode talloc(int root_val) {
  tnode t = malloc(sizeof(struct tnode_s)); /* XXX check for NULL return */
  t->val = root_val;
  t->lt = t->rt = t->follower = NULL;
  return t;
}

tnode depth_first_print(tnode root, unsigned indent) {
  unsigned i = indent;
  if (root) {
    while (i-- > 0) printf(" |");
    printf(" %u\n", root->val);
    depth_first_print(root->lt, indent+1);
    depth_first_print(root->rt, indent+1);
  }
}