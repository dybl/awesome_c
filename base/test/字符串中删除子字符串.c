#include<stdio.h>
#include<string.h>
//删除子串
void deletesubstring(char *s,char *t);
//判断是否子串，是则返回首个字符下标，否则返回-1
int issubstring(char *s,char *t);
//类似于strlen(s)

int len(char *s);

void main()
{
	char s[100],t[100];
	int IsSub;
	printf("Please input string s:\n");
	gets(s);
	printf("Please input substring t:\n");
	gets(t);
    if(issubstring(s,t))
    	deletesubstring(s,t);
    printf("%s\n",s);
}
void deletesubstring(char *s,char *t)
{
	int pos;
	int i,tlength,slength;
	tlength=len(t);
	slength=len(s);
	while(pos=issubstring(s,t)>=0)
	{
		//从pos开始移动slength-tlength-pos-1个字符
		for(i=0;i<slength-tlength-pos;i++)
			*(s+pos+i)=*(s+pos+i+tlength);
		*(s+pos+i)='\0';
	}
}
int issubstring(char *s,char*t)
{
	int i,j;
	int tlength,slength;
	char *ps=s,*pt=t;
	slength=len(s);
	tlength=len(t);
	if(tlength>slength)
		return -1;
	i=0;
	while(i<=slength-tlength)
	{
		j=0;
		while(j<tlength)
	    {
	    	if(*ps==*pt)
		    {
		    	ps++;
			    pt++;
			    j++;
		    }
		    //有不同字符，需要从下一个字符开始重新判断
		    else
		    {
		    	i++; 
			    ps=s+i;
			    pt=t;
			    break;
		    }
	    }
	    if(j>tlength)
	    	return i;
	}
	return -1;
}
int length(char *s)
{
	int length=0;
	while(*(s+length)!='\0')
		length++;
	return length;
}
