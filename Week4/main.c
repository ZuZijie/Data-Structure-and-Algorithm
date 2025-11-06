#include "def.c"
#include <stdlib.h>

int main(int argc, char*argv[])
{
	// int n=0;
	// scanf("%d",&n);
	// int *op = (int*)malloc(n * sizeof(int));
	// for(int i=0;i<n;++i)
	// 	scanf("%d",&op[i]);
	int op[7]={1,2,3,4,5,6,7};
	int n = 7;
	int i;
	DataType *s;
	DataType *pre1 = "abd*f***ce***";//preorder traversal sequence
	DataType *in1 = "*d*f*b*a*e*c*";//inorder traversal sequence
	DataType *post1 = "***fd*b**e*ca";//postorder traversal sequence
	DataType *pre2 = "ab**c*d*e**";
	DataType *in2 = "*b*a*c*d*e*";
	DataType *post2 = "**b****edca";
	BinaryTree T;
	s = "*";
	DataType ret[13];
	DataType ret1[11];
	for(int i=0;i<n;++i)
	{
		switch(op[i])
		{
			case 1:
				s = pre1;
				T = CreateBinaryTreeFromPreOrderSequence(&s);
				s = ret;
				PreOrderTraversal(T, &s);
				for(int i=0;i<13;i++)
				{
					printf("%c",ret[i]);
				}
				break;
			case 2:
				s=pre1;
				T=CreateBinaryTreeFromPreOrderSequence(&s);
				s=ret;
				InOrderTraversal(T, &s);
				for(int i=0;i<13;i++)
				{
                                      	printf("%c",ret[i]);
                                }
                                break;
                        case 3:
                                s=pre1;
                                T=CreateBinaryTreeFromPreOrderSequence(&s);
       	                        s=ret;
                                PostOrderTraversal(T, &s);
                                for(int i=0;i<13;i++)
				{
                                       printf("%c",ret[i]);
                                }
                                break;
                        case 4:
                                s=pre2;
                                T=CreateBinaryTreeFromPreOrderSequence(&s);
                                s=ret1;
                                PreOrderTraversal(T, &s);
                                for(int i=0;i<11;i++)
				{
                                       printf("%c",ret1[i]);
                                }
                                break;
                        case 5:
                                s=pre2;
                                T=CreateBinaryTreeFromPreOrderSequence(&s);
                                s=ret1;
                                InOrderTraversal(T, &s);
                                for(int i=0;i<11;i++)
				{
                                        printf("%c",ret1[i]);
                                }
                                break;
                        case 6:
                                s=pre2;
                                T=CreateBinaryTreeFromPreOrderSequence(&s);
                                s=ret1;
                                PostOrderTraversal(T, &s);
                                for(int i=0;i<11;i++)
				{
                                       printf("%c",ret1[i]);                     
				}
                                break;
                        case 7:
                                s=pre2;
                                T=CreateBinaryTreeFromPreOrderSequence(&s);
                                s=ret1;
                                InOrderTraversal(T, &s);
                                for(int i=0;i<11;i++)
				{
                                      printf("%c",ret1[i]);              
				}
				T = DestroyTree(&T);
				printf("\n");
				if(!T)
					printf("100");
                                break;
				
		}
	}
	return 0;

}
