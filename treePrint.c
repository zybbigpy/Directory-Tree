#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_DEPTH 10

/* for test use */
#define new_tree_node(name) \
  TreeNode *name = (TreeNode *)malloc(sizeof(TreeNode))

#define fill_tree_info(name, left_ptr, right_ptr, level_, ch_) \
  name->left_brother = left_ptr;                               \
  name->right_child = right_ptr;                               \
  name->level = level_;                                        \
  name->ch = ch_

typedef struct TreeNode {
  struct TreeNode *left_brother;
  struct TreeNode *right_child;
  char ch;
  int level;
} TreeNode;

void destroy_tree(TreeNode *root) {
  if (root == NULL) return;
  destroy_tree(root->left_brother);
  destroy_tree(root->right_child);
  free(root);
}

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

void test() {
  new_tree_node(R);  // root node
  new_tree_node(a);
  new_tree_node(b);
  new_tree_node(c);
  new_tree_node(d);
  new_tree_node(e);
  new_tree_node(f);
  new_tree_node(g);
  new_tree_node(h);
  new_tree_node(i);
  new_tree_node(j);

  fill_tree_info(R, NULL, a, 0, '0');
  fill_tree_info(a, b, c, 1, 'A');
  fill_tree_info(b, d, e, 1, 'B');
  fill_tree_info(c, f, g, 2, 'C');
  fill_tree_info(d, NULL, j, 1, 'D');
  fill_tree_info(e, h, NULL, 2, 'E');
  fill_tree_info(f, NULL, i, 2, 'F');
  fill_tree_info(g, NULL, NULL, 3, 'G');
  fill_tree_info(h, NULL, NULL, 2, 'H');
  fill_tree_info(i, NULL, NULL, 3, 'I');
  fill_tree_info(j, NULL, NULL, 2, 'J');
  tree_print(R);
  destroy_tree(R);
}

int main() {
  test();
  return 0;
}