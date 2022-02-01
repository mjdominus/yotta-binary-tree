
typedef struct tnode_s {
  unsigned val;
  struct tnode_s *lt, *rt;
  struct tnode_s *follower;     /* next node at the SAME level */
} *tnode;

tnode depth_first_print(tnode, unsigned);
void print_label(tnode);
tnode talloc(int);


