#include<stdio.h>
#include<stdlib.h>
#define MAX 50
typedef struct node NODE;
struct node
{
	char data;
	int index;
	int isEndofString;
	struct node *left,*eq,*right;	
};
NODE* newNode(char data)
{
	NODE *tmp = (NODE*) malloc(sizeof(NODE));
	tmp->data = data;
	tmp->isEndofString =  0;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->eq = NULL;
	return tmp;
}
void insert(NODE** root, char *word,int i)
{
	if(!(*root))
	{
		*root = newNode(*word);
	}
	if((*word) < (*root)->data)
	{
		insert(&((*root)->left),word,i);
	}
	else if((*word)>(*root)->data)
	{
		insert(&((*root)->right),word,i);
	}
	else
	{
		if(*(word+1))
			insert(&((*root)->eq),word+1,i);
		else
		{
			(*root)->isEndofString = 1;
			(*root)->index = i;
		}
	}
}
void traverseTSTUtil(NODE* root,char* buffer,int depth)
{
	if(root)
	{
		traverseTSTUtil(root->left,buffer,depth);

		buffer[depth] = root->data;
		if(root->isEndofString)
		{
			buffer[depth+1] = '\0';
			printf("%s %d\n",buffer,root->index);
		}
		traverseTSTUtil(root->eq,buffer,depth+1);
		traverseTSTUtil(root->right,buffer,depth);
	}
}
void traverseTST(NODE* root)
{
	char buffer[MAX];
	traverseTSTUtil(root,buffer,0);
}
int searchTST(NODE* root,char *word)
{
	if(!root)
	{	
		return 0;
	}
	if(*word<(root)->data)
	{
		return searchTST(root->left,word);
	}
	else if(*word > (root)->data)
	{
		return searchTST(root->right,word);
	}
	else
	{
		if(*(word+1) == '\0')
			return root->isEndofString;
		return searchTST(root->eq,word+1);
	}
}
int main()
{
	int i = 9;
	NODE* root = NULL;
	insert(&root,"CGMI",1);	
	insert(&root,"CGMM",2);	
	insert(&root,"CGSN",3);	
	insert(&root,"CSCS",4);	
	insert(&root,"CGMR",5);	
	insert(&root,"CIMI",6);
	insert(&root,"CIMI?",7);
	insert(&root,"CIMI=?",8);
	insert(&root,"CMUX",i++);
	insert(&root,"WS46",i++);
	insert(&root,"CPWC",i++);
	insert(&root,"CHUP",i++);
	insert(&root,"CBST",i++);
	insert(&root,"CRLP",i++);
	insert(&root,"CR",i++);
	insert(&root,"CEER",i++);
	insert(&root,"CRC",i++);
	insert(&root,"CSNS",i++);
	insert(&root,"CVHU",i++);
	insert(&root,"CNUM",i++);
	insert(&root,"COPN",i++);
	insert(&root,"CREG",i++);
	insert(&root,"COPS",i++);
	insert(&root,"CLCK",i++);
	insert(&root,"CPWD",i++);
	insert(&root,"CLIP",i++);
	insert(&root,"CLIR",i++);
	insert(&root,"CCFC",i++);
	insert(&root,"CCWA",i++);
	insert(&root,"CHLD",i++);
	insert(&root,"CUSD",i++);
	insert(&root,"CAOC",i++);
	insert(&root,"CLCC",i++);
	insert(&root,"CSSN",i++);
	insert(&root,"CCUG",i++);
	insert(&root,"CPOL",i++);
	insert(&root,"CPLS",i++);
	insert(&root,"CTFR",i++);
	insert(&root,"CFUN",i++);
	insert(&root,"CPIN",i++);
	insert(&root,"CPAS",i++);
	
	traverseTST(root);
	char a[] = "CSCS"; 
	searchTST(root,a) ? printf("Found\n") : printf("Not found\n");
	
	return 0;		
	
}

















