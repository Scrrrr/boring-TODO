#include<stdio.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

#define DEBUG 0

#define FILENAME "todo.txt"
#include"function.h"

int main(int argc, char *argv[])
{
	char cmd[10];
	Node node = {NULL};
	Node *head = &node;


	if(argc < 2)
	{
		Usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	load(head);
	strncpy(cmd,argv[1],sizeof(cmd));

	if      (!strcmp(cmd, "help")) Usage(argv[0]);
	else if (!strcmp(cmd, "show")) show(head);
	else if (!strcmp(cmd,  "add")) 
			{
				if(argc < 3) {
					printf("追加するタスクを入力してください。\n");
					exit(EXIT_FAILURE);
				}else{
					add(head,argv[2]);
					save(head);
				}
			}
	else if (!strcmp(cmd, "done"))
			{
				if(argc < 3) {
					printf("マークするタスク番号を指定してください\n");
					exit(EXIT_FAILURE);
				}else{
					done(head,argv[2]);
					save(head);
				}
			}
	else if (!strcmp(cmd,  "del")) 
			{
				if(argc < 3) {
					printf("削除するタスク番号を指定してください\n"); 
					exit(EXIT_FAILURE);
				}else{
					del(head,argv[2]);
					save(head);
				}
			}
	else    {
		printf("No such option\n");
		exit(EXIT_FAILURE);
	}

	freeall(head);

}
