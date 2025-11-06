#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "def.c"

// Test function declarations
void test_create_tree_from_preorder();
void test_preorder_traversal();
void test_inorder_traversal();
void test_postorder_traversal();
void test_destroy_tree();
void test_empty_tree();
void test_single_node_tree();

int main() {
    printf("Testing binary tree functions from def.c...\n\n");
    
    test_create_tree_from_preorder();
    test_preorder_traversal();
    test_inorder_traversal();
    test_postorder_traversal();
    test_destroy_tree();
    test_empty_tree();
    test_single_node_tree();
    
    printf("\nAll tests passed!\n");
    return 0;
}

// Test creating tree from preorder sequence
void test_create_tree_from_preorder() {
    printf("Test 1: Create tree from preorder sequence\n");
    
    // Test case 1: Normal binary tree
    // Tree structure: A(B(D,E),C(F,G))
    // Preorder sequence: ABD**E**CF**G**
    char preorder1[] = "ABD**E**CF**G**";
    char *ptr1 = preorder1;
    BinaryTree tree1 = CreateBinaryTreeFromPreOrderSequence(&ptr1);
    
    assert(tree1 != NULL);
    assert(tree1->data == 'A');
    assert(tree1->left->data == 'B');
    assert(tree1->right->data == 'C');
    assert(tree1->left->left->data == 'D');
    assert(tree1->left->right->data == 'E');
    assert(tree1->right->left->data == 'F');
    assert(tree1->right->right->data == 'G');
    
    printf("  Test case 1 passed: Normal tree created successfully\n");
    
    // Clean up memory
    DestroyTree(&tree1);
}

// Test preorder traversal
void test_preorder_traversal() {
    printf("Test 2: Preorder traversal test\n");
    
    // Create test tree: A(B(D,E),C(F,G))
    char preorder[] = "ABD**E**CF**G**";
    char *ptr = preorder;
    BinaryTree tree = CreateBinaryTreeFromPreOrderSequence(&ptr);
    
    // Execute preorder traversal
    char result[100] = {0};
    char *result_ptr = result;
    PreOrderTraversal(tree, &result_ptr);
    
    // Expected result: ABD*E**CF*G**
    assert(strcmp(result, "ABD*E**CF*G**") == 0);
    
    printf("  Preorder traversal test passed\n");
    
    // Clean up memory
    DestroyTree(&tree);
}

// Test inorder traversal
void test_inorder_traversal() {
    printf("Test 3: Inorder traversal test\n");
    
    // Create test tree: A(B(D,E),C(F,G))
    char preorder[] = "ABD**E**CF**G**";
    char *ptr = preorder;
    BinaryTree tree = CreateBinaryTreeFromPreOrderSequence(&ptr);
    
    // Execute inorder traversal
    char result[100] = {0};
    char *result_ptr = result;
    InOrderTraversal(tree, &result_ptr);
    
    // Expected result: *D*B*E*A*F*C*G*
    assert(strcmp(result, "*D*B*E*A*F*C*G*") == 0);
    
    printf("  Inorder traversal test passed\n");
    
    // Clean up memory
    DestroyTree(&tree);
}

// Test postorder traversal
void test_postorder_traversal() {
    printf("Test 4: Postorder traversal test\n");
    
    // Create test tree: A(B(D,E),C(F,G))
    char preorder[] = "ABD**E**CF**G**";
    char *ptr = preorder;
    BinaryTree tree = CreateBinaryTreeFromPreOrderSequence(&ptr);
    
    // Execute postorder traversal
    char result[100] = {0};
    char *result_ptr = result;
    PostOrderTraversal(tree, &result_ptr);
    
    // Expected result: **D**E*B**F**G*C*A
    assert(strcmp(result, "**D**E*B**F**G*C*A") == 0);
    
    printf("  Postorder traversal test passed\n");
    
    // Clean up memory
    DestroyTree(&tree);
}

// Test tree destruction
void test_destroy_tree() {
    printf("Test 5: Destroy tree test\n");
    
    // Create test tree
    char preorder[] = "ABD**E**CF**G**";
    char *ptr = preorder;
    BinaryTree tree = CreateBinaryTreeFromPreOrderSequence(&ptr);
    
    // Verify tree exists
    assert(tree != NULL);
    
    // Destroy tree
    DestroyTree(&tree);
    
    // Verify tree has been destroyed
    assert(tree == NULL);
    
    printf("  Destroy tree test passed\n");
}

// Test empty tree
void test_empty_tree() {
    printf("Test 6: Empty tree test\n");
    
    // Test empty tree creation
    char empty_preorder[] = "*";
    char *ptr = empty_preorder;
    BinaryTree tree = CreateBinaryTreeFromPreOrderSequence(&ptr);
    
    assert(tree == NULL);
    
    printf("  Empty tree test passed\n");
}

// Test single node tree
void test_single_node_tree() {
    printf("Test 7: Single node tree test\n");
    
    // Create single node tree
    char preorder[] = "A**";
    char *ptr = preorder;
    BinaryTree tree = CreateBinaryTreeFromPreOrderSequence(&ptr);
    
    assert(tree != NULL);
    assert(tree->data == 'A');
    assert(tree->left == NULL);
    assert(tree->right == NULL);
    
    // Test preorder traversal
    char result[100] = {0};
    char *result_ptr = result;
    PreOrderTraversal(tree, &result_ptr);
    assert(strcmp(result, "A**") == 0);
    
    // Test inorder traversal
    memset(result, 0, sizeof(result));
    result_ptr = result;
    InOrderTraversal(tree, &result_ptr);
    assert(strcmp(result, "*A*") == 0);
    
    // Test postorder traversal
    memset(result, 0, sizeof(result));
    result_ptr = result;
    PostOrderTraversal(tree, &result_ptr);
    assert(strcmp(result, "**A") == 0);
    
    printf("  Single node tree test passed\n");
    
    // Clean up memory
    DestroyTree(&tree);
}
