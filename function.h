typedef struct TODO{
	int no;
	char flag;
	char content[100];
	struct TODO *next;
}Todo;

typedef struct NODE{
	Todo *head;
}Node;

extern void Usage(const char *);
extern void load(Node *);
extern void show(Node *);
extern void done(Node *, const char *);
extern void add(Node  *, const char *);
extern void del(Node  *, const char *);
extern void freeall(Node *);

char buff[100];

void load(Node *node)
{
	int count = 1;
	FILE *fp = fopen(FILENAME,"r");
	Todo *tail = NULL;

	if(!fp){
		perror(FILENAME "を開けませんでした。");
		exit(EXIT_FAILURE);
	}

	while(fgets(buff,sizeof buff,fp))
	{
		buff[strcspn(buff,"\n")] = '\0';
		char *p = strchr(buff,' ');

		Todo *new = malloc(sizeof(Todo));
		new->no = count++;
		strcpy(new->content,p + 1);

		if(!strncmp(buff,"N",1))
		{
			new->flag = 'N';
		}else if(!strncmp(buff,"Y",1)){
			new->flag = 'Y';
		}else{
			new->flag = '-';
		}

		new->next = NULL;

		if(!node->head){
			node->head = new;
		}else{
			tail->next = new;
		}
		tail = new;

	}
	fclose(fp);
}

void save(Node *head)
{
	FILE *fp = fopen(FILENAME,"w");
	Todo *now = head->head;

	while(now)
	{
		//printf("no:%d          \n",now->no);
		//printf("flag:%c        \n",now->flag);
		//printf("content:%s     \n",now->content);
		if(now->flag == 'Y')
			fprintf(fp,"Y %s\n",now->content);
		else if(now->flag == 'N')
			fprintf(fp,"N %s\n",now->content);
		else
			fprintf(fp,"- %s\n",now->content);

		now = now->next;
	}
	fclose(fp);

}

void show(Node *head)
{
	Todo *cur = head->head;

	if(!cur)
	{
		puts("全てのタスクは完了しました");
		return;
	}

	puts("[TODO Lists]");
	printf("No 進捗   内容\n");
	char status[16];
	while(cur)
	{
		if      (cur->flag == 'Y')  strcpy(status,"完了　");
		else if (cur->flag == 'N')  strcpy(status,"未完了");
		else                        strcpy(status,"不明　");

		if(cur->no < 10)
			printf("%d  %s %s\n",cur->no,status,cur->content);
		else
			printf("%d %s %s\n",cur->no,status,cur->content);
		cur = cur->next;
	}
}

void add(Node *head,const char *newtodo)
{
	if(strlen(newtodo) > 100)
	{
		printf("文字数は100文字までです。\n");
		exit(EXIT_FAILURE);
	}

	int count = 1;
	Todo *now = head->head;
	Todo *new = malloc(sizeof(Todo));


	new->no = count;
	strcpy(new->content,newtodo);
	new->flag = 'N';
	new->next = NULL;

	if(!head->head)
	{
		head->head = new;
		return;
	}

	while(now->next)
	{
		count++;
		now = now->next;
	}


	Todo *cur = head->head;
	while(cur->next)
	{
		cur = cur->next;
	}
	cur->next = new;
	printf("「%s」を追加しました。\n",new->content);
	
}

void done(Node *head,const char *number)
{
	int n = atoi(number);
	
	Todo *now = head->head;

	while(n != now->no)
	{
		now = now->next;
		if(!now)
		{
			printf("その番号は見つかりませんでした。\n");
			exit(EXIT_FAILURE);
		}
	}

	if(now->flag != 'N')
	{
		printf("そのタスクは既に完了済みのようです\n");
		exit(EXIT_FAILURE);
	}

	now->flag = 'Y';

	printf("番号%dは完了しました！\n",now->no);

}

void del(Node *head,const char *number)
{
	printf("Construction DEL ...\n");
}

void freeall(Node *head)
{
	Todo *now = head->head;
    if(!now)
    {
        //printf("%p\n",(void *)now);
        return;
    }

	while(now->next)
	{
        //printf("%p\n",(void *)now);
		Todo *cur = now;
		now = now->next;
		free(cur);
	}
	free(now);
}

void Usage(const char *name)
{
	printf("\
USAGE:\n\
  %s [OPTIONS] [SUBCOMMAND]\n\
\n\
OPTIONS:\n\
  help          show this help menu\n\
  show          show todo list\n\
  add  <task>   add todo\n\
  done <number> todo update to done\n\
  del  <number> delete todo\n",name);
}

