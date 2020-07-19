
#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

bt_node* bt_create_node(int value) {
	bt_node* node = (bt_node*) malloc(sizeof(bt_node));

	if (node == NULL) {
		fprintf(stderr, "Can't allocate memory for node\n");
		exit(EXIT_FAILURE);
	}

	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

bt_tree* bt_create_tree() {
	bt_tree* tree = (bt_tree*) malloc(sizeof(bt_tree));

	if (tree == NULL) {
		fprintf(stderr, "Can't allocate memory for tree\n");
		exit(EXIT_FAILURE);
	}

	tree->root = NULL;
	tree->size = 0;
	return tree;
}

void bt_insert(bt_tree* tree, int value) {
	if (tree == NULL) {
		return;
	}

	bt_node* node = bt_create_node(value);

	if (tree->root == NULL) {
		tree->root = node;
		tree->size++;
		return;
	}

	bt_node* tmp = tree->root;

	while (tmp != NULL) {
		if (tmp->value > value) {
			if (tmp->left == NULL) {
				tmp->left = node;
				break;
			} else {
				tmp = tmp->left;
			}
		} else {
			if (tmp->right == NULL) {
				tmp->right = node;
				break;
			} else {
				tmp = tmp->right;
			}
		}
	}
	tree->size++;
}

void bt_delete(bt_tree* tree) {
	if (tree == NULL || tree->root == NULL) {
		return;
	}

	bt_node* tmp = tree->root;

	while (tmp != NULL) {
		
	}
}

void bt_print_inorder(bt_node* node) {
	if (node == NULL) {
		return;
	}

	bt_print_inorder(node->left);
	printf("%d, ", node->value);
	bt_print_inorder(node->right);
}

void bt_print_preorder(bt_node* node) {
	if (node == NULL) {
		return;
	}

	printf("%d, ", node->value);
	bt_print_preorder(node->left);
	bt_print_preorder(node->right);
}

void bt_print_postorder(bt_node* node) {
	if (node == NULL) {
		return;
	}

	bt_print_postorder(node->left);
	bt_print_postorder(node->right);
	printf("%d, ", node->value);
}
