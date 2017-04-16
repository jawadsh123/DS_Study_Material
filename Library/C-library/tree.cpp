#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *tree;
void create_tree(struct node *);
struct node *insert(struct node *,int);
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
struct node *smallest(struct node *);
struct node *largest(struct node *);
struct node *delnode(struct node *,int);
int totalnodes(struct node *);
int height(struct node *);
struct node *deltree(struct node *);
int main()
{
	int option,val;
	struct node *ptr;
	create_tree(tree);
	do
	{
		printf("\n1.Insert Element");
		printf("\n2. Preorder Traversal");
		printf("\n3. Inorder Traversal");
		printf("\n4. Postorder Traversal");
		printf("\n5. Smallest Element");
		printf("\n6. Largest Element");
		printf("\n7. Delete a node");
		printf("\n8. Height of a tree");
		printf("\n9. Total nodes of a tree");
		printf("\n10. Exit");
		printf("\n\nEnter your option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\nEnter the value of the node to be inserted : ");
				scanf("%d",&val);
				tree=insert(tree,val);
				break;
			case 2:
				printf("\nThe elements of the tree in PreOrder Traversal are : \n");
				preorder(tree);
				break;
			case 3:
				printf("\nThe elements of the tree in InOrder Traversal are :  \n");
				inorder(tree);
				break;
			case 4:
				printf("\nThe elements of the tree in the PostOrder Traversal are : \n");
				postorder(tree);
				break;
			case 5:
				ptr=smallest(tree);
				printf("\nThe smallest element in the tree is : %d",ptr->data);
				break;
			case 6:
				ptr=largest(tree);
				printf("\nThe largest element in the tree is : %d",ptr->data);
				break;
			case 7:
				printf("\nEnter the element of the tree to be deleted : ");
				scanf("%d",&val);
				tree=delnode(tree,val);
				break;
			case 8:
				printf("\nThe height of the Binary Tree is %d",height(tree));
				break;
			case 9:
				printf("\nThe total nodes of the Tree is %d",totalnodes(tree));
				break;
		}
	}while(option!=10);
	return 0;
}

void create_tree(struct node *tree)
{
	tree=NULL;
}
struct node *insert(struct node *tree,int val)
{
	struct node *ptr,*parentptr,*nodeptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	ptr->left=NULL;
	ptr->right=NULL;
	if(tree==NULL)
	{
		tree=ptr;
		tree->left=NULL;
		tree->right=NULL;
	}
	else
	{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL)
		{
			parentptr=nodeptr;
			if(val<nodeptr->data)
				nodeptr=nodeptr->left;
			else
				nodeptr=nodeptr->right;
		}
		if(val<parentptr->data)
			parentptr->left = ptr;
		else
			parentptr->right = ptr;
	}
	return tree;
}

void preorder(struct node *tree)
{
	if(tree!=NULL)
	{
		printf("%d\t",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void inorder(struct node *tree)
{
	if(tree!=NULL)
	{
		inorder(tree->left);
		printf("%d\t",tree->data);
		inorder(tree->right);
	}
}

void postorder(struct node *tree)
{
	if(tree!=NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%d\t",tree->data);
	}
}

struct node *smallest(struct node *tree)
{
	if((tree == NULL) || (tree->left==NULL))
		return tree;
	else
		return smallest(tree->left);
}

struct node *largest(struct node *tree)
{
	if((tree == NULL) || (tree->right == NULL))
		return tree;
	else
		return largest(tree->right);
}

struct node *delnode(struct node *tree,int val)
{
	struct node *cur,*parent,*suc,*psuc,*ptr;
//	printf("\n1");																//checkpoints
	if(tree->left==NULL && tree->right==NULL && tree->data!=val)				//root is the only node in the tree but isn't the value to be deleted
	{
		printf("\n The value to be deleted is not present in the tree ");
		return (tree);
	}
	
	if(tree->left==NULL && tree->right==NULL && tree->data==val)				//if root is the node to be deleted & it is the only node in the tree
	{
		return NULL;
	}
//	printf("\n2");																//checking the reachability
	parent = tree;
//	printf("\n3");
	/*
	DEBUGGING
	printf("%d\t%d\t%d\t%d",tree->left->data,tree->right->data,tree->data,val);
	
	if(tree->left->data<val)
		cur = tree->right;		//assuming that the value to be deleted is smaller than the root
	else
		cur = tree->left;		//determining direction for the initial movement
			
	printf("\n%d\n",cur->data);
	*/
//	printf("\n4");
	if(tree->left!=NULL && tree->right!=NULL)		//realised to check this condition when the root had no left child which gave me Runtime Error
	{												//for the input set 45 54 56 78
		if(tree->left->data<val)					//given wrong in the Book		
			cur = tree->right;		
		else
			cur = tree->left;
			
		printf("\n%d\n",cur->data);
//		printf("\n5");		
	}
	else if(tree->left==NULL)					//root only has right child
	{
		cur = tree->right;
	}
	else										//root only has left child
	{
		cur = tree->right;	
	}
	while(cur!=NULL && val!= cur->data)
	{
		parent = cur;
		cur = (val<cur->data)?cur->left:cur->right;
	}
//	printf("\n6");
	if(cur == NULL)		//Tree is empty
	{
		printf("\nThe value to be deleted is not present in the tree.\n");
		return (tree);
	}
	if(cur->left == NULL)				//only right child
		ptr = cur->right;
	else if(cur->right == NULL)			//only left child
		ptr = cur->left;				
	else								//node to be deleted has 2 children
	{									//we will find the inorder 
		psuc = cur;
		cur  = cur->left;
		while(suc->left!=NULL)
		{
			psuc = suc;
			suc = suc->left;
		}
		if(cur==psuc)
		{
			suc->left = cur->right;
		}
		else
		{
			suc->left = cur->left;
			psuc->left = suc->right;
			suc->right = cur->right;
		}
		ptr=suc;
	}
	if(parent->left == cur)
		parent->left=ptr;
	else
		parent->right=ptr;
		
	free(cur);
	return tree;	
}

int totalnodes(struct node *tree)
{
	if(tree==NULL)
	return 0;
	else
	return (totalnodes(tree->left) + totalnodes(tree->right) +1);
}

int height(struct node *tree)
{
	int leftheight,rightheight;
	if(tree==NULL)
	return 0;
	else
	{
		leftheight = height(tree->left);
		rightheight = height(tree->right);
		if(leftheight>rightheight)
			return (leftheight+1);
		else
			return (rightheight+1);
	}
}
