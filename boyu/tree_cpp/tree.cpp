/*#include<iostream>
#include<stack>
using namespace std;
struct BinTreeNode
{
	int info;
	BinTreeNode *llink,*rlink;
};
void createTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree!=NULL)
	{
		return;
	}
	int tmp;
	cin>>tmp;
	if(tmp==0)
	{
		return;
	}
	*ptree=new BinTreeNode;
	(*ptree)->info=tmp;
	(*ptree)->llink=(*ptree)->rlink=NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void deleteTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
	{
		return;
	}
	deleteTree(&(*ptree)->llink);
	deleteTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree=NULL;
}
void preOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	cout<<tree->info<<" ";
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void nPreOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p)
		{
			cout<<p->info<<" ";
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
void inOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	inOrder(tree->llink);
	cout<<tree->info<<" ";
	inOrder(tree->rlink);
}
void nInOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	while(p||!st.empty())
	{
		while(p)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->info<<" ";
		p=p->rlink;
	}
	cout<<endl;
}
void postOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout<<tree->info<<" ";
}
void nPostOrder(BinTreeNode *tree)
{
	if(tree==NULL)
	{
		return;
	}
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	BinTreeNode *pp=NULL;
	while(p||!st.empty())
	{
		while(p)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==NULL)
			{
				p=pp;
			}
		}
		p=st.top();
		st.pop();
		cout<<p->info<<" ";
		if(!st.empty()&&st.top()->llink==p)
		{
			p=st.top()->rlink;
		}
		else
		{
			p=NULL;
		}
	}
	cout<<endl;
}
int main()
{
	BinTreeNode *tree=NULL;
	createTree(&tree);
	preOrder(tree);
	cout<<endl;
	nPreOrder(tree);

	inOrder(tree);
	cout<<endl;
	nInOrder(tree);

	postOrder(tree);
	cout<<endl;
	nPostOrder(tree);

	deleteTree(&tree);
	return 0;
}*/
#include<iostream>
#include<stack>
using namespace std;
struct BinTreeNode{
	int info;
	BinTreeNode *llink,*rlink;
};
void createTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree!=NULL)
		return;
	int tmp;
	cin>>tmp;
	if(tmp==0)
		return;
	*ptree=new BinTreeNode;
	(*ptree)->info=tmp;
	(*ptree)->llink=(*ptree)->rlink=NULL;
	createTree(&(*ptree)->llink);
	createTree(&(*ptree)->rlink);
}
void destroyTree(BinTreeNode **ptree)
{
	if(ptree==NULL||*ptree==NULL)
		return;
	destroyTree(&(*ptree)->llink);
	destroyTree(&(*ptree)->rlink);
	delete *ptree;
	*ptree=NULL;
}
void preOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	cout<<tree->info<<' ';
	preOrder(tree->llink);
	preOrder(tree->rlink);
}
void nPreOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	st.push(p);
	while(!st.empty())
	{
		p=st.top();
		st.pop();
		if(p!=NULL)
		{
			cout<<p->info<<' '; 
			st.push(p->rlink);
			st.push(p->llink);
		}
	}
	cout<<endl;
}
void inOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	inOrder(tree->llink);
	cout<<tree->info<<' ';
	inOrder(tree->rlink);
}
void nInOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	while(p||!st.empty())
	{
		while(p)
		{
			st.push(p);
			p=p->llink;
		}
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		p=p->rlink;
	}
	cout<<endl;
}
void postOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	postOrder(tree->llink);
	postOrder(tree->rlink);
	cout<<tree->info<<' ';
}
void nPostOrder(BinTreeNode *tree)
{
	if(tree==NULL)
		return;
	stack<BinTreeNode*> st;
	BinTreeNode *p=tree;
	BinTreeNode *pp=NULL;
	while(p||!st.empty())
	{
		while(p)
		{
			st.push(p);
			pp=p->rlink;
			p=p->llink;
			if(p==NULL)
			{
				p=pp;
			}
		}
		p=st.top();
		st.pop();
		cout<<p->info<<' ';
		if(!st.empty()&&st.top()->llink==p)
		{
			p=st.top()->rlink;
		}
		else
		{
			p=NULL;
		}
	}
	cout<<endl;
}
int max(int x,int y)
{
	return (x>y)? x:y;
}
int len_int(int x)
{
	int len=0;
	while(x)
	{
		len++;
		x/=10;
	}
	return len;
}
void int_to_str(int x,char *str)
{
	int len=len_int(x);
	while(x)
	{
		str[--len]=x%10+'0';
		x/=10;
	}
}
int getHeight(BinTreeNode *tree)
{
	if(tree==NULL)
		return 0;
    int h = 2;
    int hl = tree->llink==NULL? 0 : getHeight(tree->llink);
    int hr = tree->rlink==NULL? 0 : getHeight(tree->rlink);
    return h +max(hl,hr);
}

int getWidth(BinTreeNode *tree)
{
	if(tree==NULL)
		return 0;
    int w = len_int(tree->info);
    if(tree->llink!=NULL) w += getWidth(tree->llink);
    if(tree->rlink!=NULL) w += getWidth(tree->rlink);
    return w;
}

int getRootPos(BinTreeNode *tree,int x)
{
	return tree->llink==NULL? x : x + getWidth(tree->llink);
}

void printInBuf(BinTreeNode *tree,char **buf, int x, int y)
{
	//String sv = "" + v;
	int root_len=len_int(tree->info);
	int p1 = tree->llink==NULL? x : getRootPos(tree->llink,x);
	int p2 = getRootPos(tree,x);
	int p3 = tree->rlink==NULL? p2 : getRootPos(tree->rlink,p2+root_len);

	buf[y][p2] = '|';
	for(int i=p1; i<=p3; i++) buf[y+1][i]='-';

	//for(int i=0; i<sv.length(); i++) buf[y+1][i+p2]=sv.charAt(i);  
	int_to_str(tree->info,&buf[y+1][p2]);

	if(p1<p2) buf[y+1][p1] = '/';
	if(p3>p2) buf[y+1][p3] = '\\';

	if(tree->llink!=NULL) printInBuf(tree->llink,buf,x,y+2);
	if(tree->rlink!=NULL) printInBuf(tree->rlink,buf,p2+root_len,y+2);
}

 
void showBuf(char **buf,int x,int y)
{
	for(int i=0; i<y; i++){
	    for(int j=0; j<x; j++)
	        cout<<(buf[i][j]==0? ' ':buf[i][j]);
	    cout<<endl;
	}
}
    
void show(BinTreeNode *tree)
{
	int x=getWidth(tree);
	int y=getHeight(tree);
	char **buf=new char*[y];
	for(int i=0;i<y;i++)
		buf[i]=new char[x];
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
			buf[i][j]=0;
	printInBuf(tree,buf,0,0);
	showBuf(buf,x,y);
	for(int i=0;i<y;i++)
		delete[]buf[i];
	delete[]buf;
}

int main()
{
	BinTreeNode *tree=NULL;
	createTree(&tree);
	preOrder(tree);
	cout<<endl;
	nPreOrder(tree);

	inOrder(tree);
	cout<<endl;
	nInOrder(tree);

	postOrder(tree);
	cout<<endl;
	nPostOrder(tree);
	show(tree);
	destroyTree(&tree);
	return 0;
}
