#ifndef __STULIST__H
#define __STULIST__H 

struct
{
	int no;
	char name[8];
	char sex[2];
	char classes[4];
}Stud[7]={
	{1,"zhangbin","m","9901"},
	{2,"liuli","f","9902"},
	{3,"liying","f","9901"},
	{4,"chenhua","m","9902"},
	{5,"wangqi","m","9901"},
	{6,"dongqiang","m","9902"},
	{7,"wangping","f","9901"}
};

typedef struct studnode
{
	int no;
	char name[8];
	char sex[2];
	char classes[4];
	struct studnode *next;
}StudType;

#endif