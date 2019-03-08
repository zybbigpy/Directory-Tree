#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_DEPTH 10

typedef struct TreeNode {
  struct TreeNode *left_brother;
  struct TreeNode *right_child;
  char ch;
  int level;
} TreeNode;

int rec[MAX_TREE_DEPTH] = {0};  // record the level information
void tree_print(TreeNode *root) {
  if (root == NULL) {
    return;
  } else {
    if (root->left_brother) {
      rec[root->level] = 1;
    } else {
      rec[root->level] = 0;
    }

    for (size_t i = 0; i < root->level; i++) {
      if (rec[i] == 0) {
        printf("    ");
      } else {
        printf("|   ");
      }
    }
    printf("+---%c\n", root->ch);
    tree_print(root->right_child);
    tree_print(root->left_brother);
  }
}

int main() {
  TreeNode *R = (TreeNode *)malloc(sizeof(TreeNode));  // root
  TreeNode *a = (TreeNode *)malloc(sizeof(TreeNode));
  TreeNode *b = (TreeNode *)malloc(sizeof(TreeNode));
  TreeNode *c = (TreeNode *)malloc(sizeof(TreeNode));
  TreeNode *d = (TreeNode *)malloc(sizeof(TreeNode));
  TreeNode *e = (TreeNode *)malloc(sizeof(TreeNode));
  TreeNode *f = (TreeNode *)malloc(sizeof(TreeNode));
  TreeNode *g = (TreeNode *)malloc(sizeof(TreeNode));
  TreeNode *h = (TreeNode *)malloc(sizeof(TreeNode));
  TreeNode *i = (TreeNode *)malloc(sizeof(TreeNode));
  TreeNode *j = (TreeNode *)malloc(sizeof(TreeNode));

  R->ch = '0';
  R->left_brother = NULL;
  R->right_child = a;
  R->level = 0;

  a->ch = 'A';
  a->left_brother = b;
  a->right_child = c;
  a->level = 1;

  b->ch = 'B';
  b->left_brother = d;
  b->right_child = e;
  b->level = 1;

  c->ch = 'C';
  c->left_brother = f;
  c->right_child = g;
  c->level = 2;

  d->ch = 'D';
  d->left_brother = NULL;
  d->right_child = j;
  d->level = 1;

  e->ch = 'E';
  e->left_brother = h;
  e->right_child = NULL;
  e->level = 2;

  f->ch = 'F';
  f->left_brother = NULL;
  f->right_child = i;
  f->level = 2;

  g->ch = 'G';
  g->left_brother = NULL;
  g->right_child = NULL;
  g->level = 3;

  h->ch = 'H';
  h->left_brother = NULL;
  h->right_child = NULL;
  h->level = 2;

  i->ch = 'I';
  i->left_brother = NULL;
  i->right_child = NULL;
  i->level = 3;

  j->ch = 'J';
  j->left_brother = NULL;
  j->right_child = NULL;
  j->level = 2;

  tree_print(R);
  // printf("hello world\n");
  return 0;
}