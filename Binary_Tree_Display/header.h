#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include "header_node.h"

node *add_node (node *p_tree, int given_key);
void display_tree_basic (node *p_tree);
void display_tree_incr (node *p_tree);
void display_tree_decr(node *p_tree);
void count_nodes (node *p_tree, int &counter);
int find_height(node *p_tree);
bool balanced (node *p_tree);
bool sorted (node *p_tree);
node *delete_tree (node *p_tree);
void menu_display();

#endif // HEADER_H_INCLUDED

