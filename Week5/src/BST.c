 #include "BST.h"

/*
Args:
* root: The root pointer of the BST
   arr: The pointer to a integer array
   len: The length of the data, which needs to be stored in BST

Description:
* Create an BST with arr whose length is len
*/


BST_P SearchBSTF(BST_P *root, DataType data)
{
	if (((*root) == NULL) || (((*root)->data == data))) { return NULL; }
	else if (((*root)->lchild == NULL) && ((*root)->rchild == NULL)) { return NULL; }
	else if ((*root)->lchild == NULL)
	{
		if (((*root)->rchild->data) == data) { return (*root); }
		else { return SearchBSTF(&((*root)->rchild), data); }
	}
	else if ((*root)->rchild == NULL)
	{
		if (((*root)->lchild->data) == data) { return (*root); }
		else { return SearchBSTF(&((*root)->lchild), data); }
	}
	else if ((((*root)->lchild->data) == data)|| (((*root)->rchild->data) == data)) { return (*root); }
	else if (((*root)->lchild->data) > data) { return SearchBSTF(&((*root)->lchild), data); }
	else if (((*root)->rchild->data) < data) { return SearchBSTF(&((*root)->rchild), data); }
	else
	{
		if (SearchBSTF(&((*root)->lchild), data) == NULL) { return SearchBSTF(&((*root)->rchild), data); }
		else { return SearchBSTF(&((*root)->lchild), data); }
	}
}

#define DestoryBST DestroyBST
void CreateBST(BST_P *root, int *arr, int len)
{
	for(int i=0;i<len;i++){
		InsertBSTNode(root,arr[i]);
	}

}



/*
Args:
* root: The root pointer of the BST

Description:
* Destroy root BST, free all the memory of root BST
*/
void DestroyBST(BST_P *root)
{
    if (*root == NULL) return;
    DestroyBST(&(*root)->lchild);
    DestroyBST(&(*root)->rchild);
    free(*root);
    *root = NULL; 


}
/*
Args:
* root: The root pointer of the BST
  data: The data you want to insert into BST

Description:
* Insert data into the root BST,return true.
* ATTENTION: If data already exist in BST, DO NOTIHNG and return false.
*/
bool InsertBSTNode(BST_P *root, DataType data)
{
	if(!(*root)){
		*root=malloc(sizeof(BST_T));

		(*root)->data=data;
		(*root)->lchild=NULL;
		(*root)->rchild=NULL;

		return true;
	}

	if(data > (*root)->data){

		return InsertBSTNode(&(*root)->rchild, data);
	}

	else if (data < (*root)->data)
	{

		return InsertBSTNode(&(*root)->lchild, data);
	}

	else return false;
	

}


/*
Args:
* root: The root pointer of the BST
  data: The data you want to delete from BST

Description:
* Delete data from the root BST, and free the memory
* ATTENTION: If data doesn't exist in BST, DO NOTIHNG and return false.
*/
bool DeleteBSTNode(BST_P *root, DataType data)
{
    if (*root == NULL) return false;

    if (data < (*root)->data)
        return DeleteBSTNode(&(*root)->lchild, data);
    else if (data > (*root)->data)
        return DeleteBSTNode(&(*root)->rchild, data);
    else {
        // 找到节点
        BST_P temp = *root;
        if ((*root)->lchild == NULL)
            *root = (*root)->rchild;
        else if ((*root)->rchild == NULL)
            *root = (*root)->lchild;
        else {
            // 找右子树最小节点
            BST_P *p = &(*root)->rchild;
            while ((*p)->lchild)
                p = &(*p)->lchild;

            (*root)->data = (*p)->data;
            return DeleteBSTNode(p, (*p)->data);
        }
        free(temp);
        return true;
    }
}

/*
Args:
* root: The root pointer of the BST
  data: The data you want to search

Description:
* Search data within the root BST, and return its BST pointer
* ATTENTION: If data doesn't exist in BST, return NULL.
*/
BST_P SearchBST(BST_P *root, DataType data)
{
	if(!*root) return NULL;
	if(data > (*root)->data){

		return SearchBST(&(*root)->rchild, data);
	}

	else if (data < (*root)->data)
	{

		return SearchBST(&(*root)->lchild, data);
	}
	
	else return *root;
}



/*
Args:
* root: The root pointer of the BST

Description:
* visualize the MidOrderTraverse of root BST
*/
void MidOrderTraverse(BST_P root)
{
	if (root!=NULL)
	{
		MidOrderTraverse(root->lchild);
		printf("%d, ", root->data);
		MidOrderTraverse(root->rchild); 
	}
}
