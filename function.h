#include<stdio.h>
#include<ctype.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define FILENAME "todo.txt"
#define DEBUG 0

typedef struct TODO{
	int no;
	char content[100];
	struct TODO *next;
}todo;

typedef struct Node{
	struct todo *head;
}node;


void Usage(const char *);
void show(node *);
void done(node *);
void add(node *, const char *);
void del(node *);

void Usage(const char *name)
{
	printf("\
USAGE:\n\
  %s [OPTIONS] [SUBCOMMAND]\n\
\n\
OPTIONS:\n\
  show        show todo list\n\
  add  <task> add todo\n\
  done        todo update to done\n\
  del         delete todo\n\
  ",name);
}
	

void show(node *head)
{
	FILE *fp = fopen(FILENAME,"r");
	char ch;
	int count = 1;

	if(!fp)
	{
		perror(FILENAME "の読み込みに失敗しました。");
		exit(EXIT_FAILURE);
	}

	if((ch = fgetc(fp)) == EOF)
	{
		printf("全てのタスクは完了しました\n");
		fclose(fp);
		return;
	}else{
		rewind(fp);
		printf("1: ");
		while((ch = fgetc(fp)) != EOF)
		{
			putchar(ch);
			if(ch == '\n')
			{
				count++;
				printf("%d: ",count);
			}
		}
	}

	fclose(fp);

}

void add(node *head,const char *newtodo)
{
	//printf("%s\n",newtodo);
	if(strlen(newtodo) > 100)
	{
		printf("文字数は100文字までです。\n");
		exit(EXIT_FAILURE);
	}
	
	FILE *fp = fopen(FILENAME,"a");
	fprintf(fp,"%s\n",newtodo);
	fclose(fp);
}

void del(node *head)
{
	printf("del\n");
}

void done(node *head)
{
	printf("done\n");
}
