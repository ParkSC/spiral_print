#include <stdio.h>
#include <stdlib.h>

typedef struct node* nodeptr;
typedef struct node
{
	int key;
	nodeptr left;
	nodeptr right;
} spiral_node;

void make_node(int value);
void spiral_print(int max);
int travel(char direction, int max);

nodeptr root = NULL;
nodeptr print = NULL;

int main(int argc, char* argv[])
{
	int max = atoi(argv[1]);
	int i;
//	nodeptr tmp = NULL;

	//입력받은 값이 1~100 사이의 값인지 검사
	if (max < 0 || max > 100)
	{
		printf("input range : 1 ~ 100\n");
		return 0;
	}
	//matrix 생성
	for (i=1; i<=max*max; i++)
	{
		make_node(i);
	}
	printf("%d X %d matrix created\n", max, max);
	//matrix를 정해진 순서대로 출력
	spiral_print(max);

	return 0;
}

void make_node(int value)
{
	nodeptr temp = (nodeptr)malloc(sizeof(spiral_node));
	nodeptr seeker = NULL;

	temp->key = value;
	temp->left = NULL;
	temp->right = NULL;

	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		seeker = root;
		while (seeker != NULL)
		{
			if (seeker->right == NULL)
			{
				break;
			}
			seeker = seeker->right;
		}

		seeker->right = temp;
		temp->left = seeker;
	}
}

void spiral_print(int max)
{
	int i, mode=0;
	int print_count=0, call_minus=1, tmp_count=0;
	//프린트용 포인터에 root의 주소를 복사, 가장 끝 노드로 이동
	print = root;
	while (1)
	{
		if (print->right == NULL)
		{
			break;
		}
		print = print->right;
	}

	//첫번째 항목 출력
	printf("%d ", print->key);

	while (print_count < 2*max-1)
	{	
		//printf("(max-call : %d)", max-call_minus);
		switch ( mode )
		{
			case 0: //up
				for (i=0; i<max-call_minus; i++)
				{
					printf("%d ", travel('u',max));
				}
				mode=1;
				break;
			case 1: //left
				for (i=0; i<max-call_minus; i++)
				{
					printf("%d ", travel('l',max));
				}
				mode=2;
				break;
			case 2: //down
				for (i=0; i<max-call_minus; i++)
				{
					printf("%d ", travel('d',max));
				}
				mode=3;
				break;
			case 3: //right
				for (i=0; i<max-call_minus; i++)
				{
					printf("%d ", travel('r',max));
				}
				mode=0;
				break;
		}
		if (print_count == 2 || (print_count - tmp_count) == 2)
		{
			tmp_count = print_count;
			call_minus++;
		}
		print_count++;
	}
	printf("\n\n");
/*
	//max*max 최초값출력
	printf("%d ", print->key);
	//(max*max)-max*1, (max*max)-max*2, (max*max)-max*3 = t
	for (i=0; i<max-1; i++)
	{
		printf("%d ", travel('u',max));
	}
	//t-1, t-2, t-3
	for (i=0; i<max-1; i++)
	{
		printf("%d ", travel('l',max));
	}
	//(t-3)+max*1,(t-3)+max*2,(t-3)+max*3 = r
	for (i=0; i<max-1; i++)
	{
		printf("%d ", travel('d',max));
	}
	//r+1, r+2
	for (i=0; i<max-2; i++)
	{
		printf("%d ", travel('r',max));
	}
	//(r+2)-max*1, (r+2)-max*2 = y
	for (i=0; i<max-2; i++)
	{
		printf("%d ", travel('u',max));
	}
	//y-1
	for(i=0; i<max-3; i++)
	{
		printf("%d ", travel('l',max));
	}
	//(y-1)+max*1
	for(i=0; i<max-3; i++)
	{
		printf("%d ",travel('d',max));
	}
*/
}

int travel(char direction, int max)
{
	int i;

	switch (direction)
	{
		case 'r':
			print=print->right;
			break;
		case 'l':
			print=print->left;
			break;
		case 'u':
			for (i=0; i<max; i++)
			{
				print=print->left;
			}
			break;
		case 'd':
			for (i=0; i<max; i++)
			{
				print=print->right;
			}
			break;
	}

	return print->key;
}
