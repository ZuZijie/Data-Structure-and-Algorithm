#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义二叉树节点数据类型为字符
typedef char DataType;

// 二叉树节点结构体定义
typedef struct BinaryNode
{
	DataType data;              // 节点数据
	struct BinaryNode *left;    // 左子树指针
	struct BinaryNode *right;   // 右子树指针
} BinaryNode, *BinaryTree;

// 函数声明

// 根据前序遍历序列创建二叉树
BinaryTree CreateBinaryTreeFromPreOrderSequence(DataType **s);

// 前序遍历二叉树
void PreOrderTraversal(BinaryTree t, DataType **s);

// 中序遍历二叉树
void InOrderTraversal(BinaryTree t, DataType **s);

// 后序遍历二叉树
void PostOrderTraversal(BinaryTree t, DataType **s);

// 销毁二叉树并释放内存
BinaryTree DestroyTree(BinaryTree *T);


BinaryTree CreateBinaryTreeFromPreOrderSequence(DataType **s){
	if(**s =='\0' || **s=='*'){
		(*s)++;
		return NULL;
	}

	BinaryTree Node = (BinaryTree)malloc(sizeof(BinaryNode));

	Node->data = **s;
	(*s)++;

	Node->left = CreateBinaryTreeFromPreOrderSequence(s);
    Node->right = CreateBinaryTreeFromPreOrderSequence(s);

    return Node;
}

void PreOrderTraversal(BinaryTree t, DataType **s){
	if (t == NULL) {
        **s = '*'; 
        (*s)++;
        return;
    }

    **s = t->data;
    (*s)++;

    PreOrderTraversal(t->left, s);
    PreOrderTraversal(t->right, s);
}

void InOrderTraversal(BinaryTree t, DataType **s){
	if (t == NULL) {
        **s = '*'; 
        (*s)++;
        return;
    }

    InOrderTraversal(t->left, s);

    **s = t->data;
    (*s)++;

    InOrderTraversal(t->right, s);
}

void PostOrderTraversal(BinaryTree t, DataType **s)
{
    if (t == NULL) {
        **s = '*';
        (*s)++;
        return;
    }

    PostOrderTraversal(t->left, s);
    PostOrderTraversal(t->right, s);

    **s = t->data;
    (*s)++;
}

BinaryTree DestroyTree(BinaryTree *T)
{
    if (*T == NULL) {
        return NULL;
    }

    DestroyTree(&((*T)->left));
    DestroyTree(&((*T)->right));

    free(*T);
    *T = NULL;

    return NULL;
}