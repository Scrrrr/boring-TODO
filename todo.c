#include"function.h"

int main(int argc, char *argv[])
{
	node *head = malloc(sizeof(node));
	char cmd[10];

	if(argc < 2)
	{
		Usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	strncpy(cmd,argv[1],sizeof(cmd));

	if      (!strcmp(cmd, "show")) show(head);
	else if (!strcmp(cmd,  "add")) {
			if(argc < 3) {
				printf("追加するタスクを入力してください。\n"); exit(EXIT_FAILURE);
			}else{
				add(head,argv[2]);
			}
		}
	else if (!strcmp(cmd, "done")) done(head);
	else if (!strcmp(cmd,  "del")) del(head);
	else    {printf("No such option\n"); exit(EXIT_FAILURE);}

	free(head);
}
