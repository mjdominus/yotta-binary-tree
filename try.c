
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>             /* for getpid() */
#include "tree.h"

tnode full_tree(unsigned, int);
tnode worst_case_tree(unsigned, int);
tnode random_tree(unsigned, int);

int main(void) {
  tnode t;
  t = full_tree(4, 1);
  /* t = worst_case_tree(8, 1); */
  /* t = full_tree(4, 1); */
  srandom((unsigned) getpid());
  t = random_tree(23, 1);
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

/* return the root of a tree that is actually a linked list of
   length n */
tnode worst_case_tree(unsigned n, int root_label) {
  tnode first = NULL, cur;
  if (n == 0) return NULL;
  cur = first = talloc(root_label);   /* XXX check for malloc error */
  while (--n) {
    root_label++;
    cur->lt = cur->follower = NULL;
    cur->rt = talloc(root_label);
    cur = cur->rt;
  }
  cur->rt = NULL;
  return first;
}

/* random tree with exactly n nodes; it's up to the caller to ensure
   that the PRNG is properly seeded with srandom(3)

   on return, if `count` was non-NULL, it will contain the total 
   number of nodes in the returned tree; this will not exceed n
*/
tnode random_tree(unsigned n, int root_label) {
  n--;                          /* root node */
  if (n == 0) return NULL;

  long int left_count = random() % n;
  long int right_count = n - left_count;
  tnode root = talloc(root_label++);
  root->lt = random_tree(left_count, root_label);
  root_label += left_count;
  root->rt = random_tree(right_count, root_label + left_count);
  return root;
}
