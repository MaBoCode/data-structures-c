#include "binary_tree.h"

int main(void) {

	bt_tree* tree = bt_create_tree();

	bt_insert(tree, 3);
	bt_insert(tree, 1);
	bt_insert(tree, 0);
	bt_insert(tree, 7);
	bt_insert(tree, 6);

	bt_print_inorder(tree->root);
	printf("\n");

	bt_print_preorder(tree->root);
	printf("\n");

	bt_print_postorder(tree->root);
	printf("\n");

	printf("BFS: ");
	bt_bfs(tree);
	return 0;
}
