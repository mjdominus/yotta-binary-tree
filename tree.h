
typedef struct tnode_st {
  unsigned val;
  struct tnode_st *lt, *rt;
  struct tnode_st *follower;     /* next node at the SAME level */
} *tnode;

#define tnode_alloc() (malloc(sizeof(struct tnode_st)))

tnode depth_first_print(tnode, unsigned);
void  link_spines(tnode, tnode);
void  print_label(tnode);
void  set_all_followers(tnode);
tnode talloc(int);


