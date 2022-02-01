
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

tnode talloc(int root_val) {
  tnode t = tnode_alloc(); /* XXX check for NULL return */
  t->val = root_val;
  t->lt = t->rt = t->follower = NULL;
  return t;
}

void print_label(tnode root) {
  if (root) {
    printf(" %u", root->val);
    if (root->follower) printf(" -> %u", root->follower->val);
  }
  puts("");
}

tnode depth_first_print(tnode root, unsigned indent) {
  unsigned i = indent;
  if (root) {
    while (i-- > 0) printf(" |");
    print_label(root);
    depth_first_print(root->lt, indent+1);
    depth_first_print(root->rt, indent+1);
  }
}

void set_all_followers(tnode root) {
  if (!root) return;
  set_all_followers(root->lt);
  set_all_followers(root->rt);
  link_spines(root->lt, root->rt);
}

void link_spines(tnode left_side, tnode right_side) {
  while (left_side && right_side) {
    left_side->follower = right_side;
    left_side  = left_side->rt;
    right_side = right_side->lt;
  }
}
