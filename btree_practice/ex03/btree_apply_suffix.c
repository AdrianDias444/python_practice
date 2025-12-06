#include "ft_btree.h"

void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
    if(!root)
        return ;

    btree_apply_suffix(root->left, applyf);
    btree_apply_suffix(root->right, applyf);

    applyf(root->item);
}


t_btree *btree_create_node(void *item)
{
    t_btree *new_node;
    
    if(!item)
        return (NULL);

    new_node = malloc(sizeof(t_btree));
    if(!new_node)
        return (NULL);

    new_node -> item = item;
    new_node -> left = 0;
    new_node -> right = 0;
    
    return(new_node);
}

void ft_putstr(void *str)
{
    char *s = (char *)str;

    int i = 0;

    while(s[i])
        write(1, &s[i++], 1);

}

int main(void)
{
    t_btree *node1 = btree_create_node("1");
    t_btree *node2 = btree_create_node("2");
    t_btree *node3 = btree_create_node("3");
    t_btree *node4 = btree_create_node("4");
    t_btree *node5 = btree_create_node("5");
    t_btree *node6 = btree_create_node("6");
    t_btree *node7 = btree_create_node("7");

    node1 -> left = node2;
    node1 -> right = node3;

    node2 -> left = node4;
    node2 -> right = node5;

    node3 -> left = node6;
    node3 -> right  = node7;

    btree_apply_suffix(node1, ft_putstr);
}
