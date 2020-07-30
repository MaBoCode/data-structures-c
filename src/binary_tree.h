
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct bt_node {
	int value;
	struct bt_node *left;
	struct bt_node *right;
} bt_node;

typedef struct bt_tree {
	unsigned int size;
	bt_node *root;
} bt_tree;

bt_node *bt_create_node(int value);
bt_tree *bt_create_tree();

void bt_insert(bt_tree *tree, int value);
void bt_delete(bt_tree *tree);

void bt_bfs(bt_tree *tree);
void bt_dfs(bt_tree)
void bt_print_inorder(bt_node *node);
void bt_print_preorder(bt_node *node);
void bt_print_postorder(bt_node *node);

#endif
