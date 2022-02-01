
typedef struct tnode_s {
  unsigned val;
  struct tnode_s *lt, *rt;
  struct tnode_s *follower;     /* next node at the SAME level */
} *tnode;

tnode talloc(int);
tnode depth_first_print(tnode, unsigned);


