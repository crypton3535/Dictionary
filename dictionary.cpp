//TRIE DATA STRUCTURE
#include<iostream>
#include<cstdio>
//#include<alloc.h>
#include<cstdlib>
#include<cstring>
#include<iomanip>
//#include<cstdbool>
#define alpha 26

using namespace std;

struct Trienode
{
	struct Trienode *children[alpha];
	bool isLeaf;
	char meaning[50];
};
struct Trienode* getNode()
{
	struct Trienode *temp=(struct Trienode*)malloc(sizeof(struct Trienode));
	temp->isLeaf=false;
	for(int i=0;i<alpha;i++)
	{
		temp->children[i]=NULL;
	}
	return temp;
}
int insert(struct Trienode *root,const char*key,const char*means)
{
	int index;
	struct Trienode *temp=root;
	int k=strlen(key);
	for(int i=0;i<k;i++)
	{
		if(key[i]>96)
			index=key[i]-97;
		else
			index=key[i]-65;
		if(temp->children[index]==NULL)
		{
			temp->children[index]=getNode();
		}
		temp=temp->children[index];
	}
	temp->isLeaf=true;
	strcpy(temp->meaning,means);
	return 1;
}
int search(struct Trienode *root,const char *key)
{
	int index;
	struct Trienode*temp=root;
	int k=strlen(key);
	for(int i=0;i<k;i++)
	{
		if(key[i]>96)
			index=key[i]-97;
		else
			index=key[i]-65;
		if(temp->children[index]==NULL)
		{
			cout<<"Error : Your search "<<key<<" not found"<<endl;
		   return 0;
		}
		else
		{
			temp=temp->children[index];
		}
	}
	if(temp->isLeaf==true)
	{
		cout<<"Your Search :   "<<key<<endl<<"\tWord found:"<<key<<" : "<<temp->meaning<<endl;
		return 1;
	}
	else
	{
		cout<<"Error : Your search "<<key<<" not found"<<endl;
		return 0;
	}
}
int main()
{
	char ch,word[100],meaning[100],src[100];
	int num,n;
	char keys[][20]={"jatinder","dictionary","trie","I"};
	char meanings[][40]={"He's who has written this.","Its me","It is a data structure that made me","I am I"};
	struct Trienode *root=getNode();
	char output[][35]={"Key is not present in Trie\n","Key is present in Trie \n"};
	char status[][35]={"Element can't be inserted\n","Element inserted successfully\n"};
	for(int i=0;i<sizeof(keys)/sizeof(keys[0]);i++)
	{
		insert(root,keys[i],meanings[i]);
	}
	cout<<"Do you want to load dictionary from external source(y/n)"<<endl;
	cout<<"*** Check documentation and format first ***\t";
	cin>>ch;
	if(ch=='y')
	{
		cout<<"Enter source followed by filename\t";
		cin>>src;
		FILE *fp=fopen(src,"r");
		//cout<<"I am"<<endl;
		fscanf(fp,"%d",&num);
		//cout<<"Here"<<endl;
		for(int i=0;i<num;i++)
		{
		//	cout<<"Here"<<endl;
			fscanf(fp,"%s %s[^'\n']",&word,&meaning);
			//cout<<word<<meaning<<endl;
			insert(root,word,meaning);
		}
		cout<<"File loaded successfully"<<endl;
	}
	int test;
	cout<<"Enter number of elements you want to insert in dictionary\t";
	cin>>n;
	cout<<"Enter words and their meanings\n";
	while(n--)
	{
		cout<<"Word : ";
		cin>>word;
		fflush(stdin);
		cout<<"Meaning : ";
		gets(meaning);
		cout<<status[insert(root,word,meaning)];
	}
	cout<<"Enter number of key searches\t";
	cin>>test;
	cout<<"Enter keys to search\n";
	char str[100];
	while(test--)
	{
	cin>>str;
	search(root,str);
	}
	cout<<"Program about to terminate..."<<endl;
	cout<<"Enter y/n if you want to create a permanent storage of all dictionary words"<<endl;
	cin>>ch;
	fflush(stdin);
	if(ch=='y')
	{
		char words[10000][100];
		char meanings[10000][100];
		struct Trienode*temp=root;
		cout<<"Permanent storage option currently down , will be added later"<<endl;
	}
	return 0;
}