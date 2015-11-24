#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//구조체및 구조체 포인터 정의
typedef struct node* nodeptr;
typedef struct node
{
	int key;
	nodeptr left;
	nodeptr right;
} spiral_node;

//선언함수 정의
void make_node(int value);
void spiral_print(int max);
int travel(char direction, int max);

//격자각각 노드를 가리키는 포인터
nodeptr root = NULL;
nodeptr print = NULL;

int main(int argc, char* argv[])
{
	int max;
	int i, j;
	nodeptr tmp = NULL; //matrix 생성 검증용

	//입력값이 없을 경우 기본 4로 지정
	if ( argv[1] == NULL )
	{
		max = 4;
	}
	else
	{
		max = atoi(argv[1]);
	}

	//입력받은 값이 1~100 사이의 값인지 검사
	if ( max <= 0 || max > 100 )
	{
		printf("input range : 1 ~ 100\n");
		return 0;
	}
	//matrix 생성
	for ( i = 1 ; i <= max*max ; i++ )
	{
		make_node(i);
	}
	printf("%d X %d matrix created\n", max, max);

	//matrix 생성결과 표시
	tmp = root;
	for ( i = 0 ; i < max ; i++ )
	{
		for ( j = 0 ; j < max ; j++ )
		{
			printf("%d\t", tmp->key);
			tmp = tmp->right;
		}
		printf("\n");
	}

	//매트릭스 생성확인
	tmp = root;
	printf("\n첫 번째 값~마지막 값까지 assert()로 검사합니다.\n");
	for ( i = 1 ; i <= max*max ; i++ )
	{
		assert( tmp->key == i );
		printf("%d번째노드값 검사  ", i);
		tmp = tmp->right;
	}
	printf("\n");

	//matrix를 정해진 순서대로 출력
	printf("\nReverse spiral printring\n");
	spiral_print( max );

	return 0;
}

void make_node(int value)
{
	nodeptr temp = (nodeptr)malloc(sizeof(spiral_node));
	nodeptr seeker = NULL;

	temp->key = value;
	temp->left = NULL;
	temp->right = NULL;

	if ( root == NULL )
	{
		root = temp;
	}
	else
	{
		seeker = root;
		while ( seeker != NULL )
		{
			if ( seeker->right == NULL )
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
		if ( print->right == NULL )
		{
			break;
		}
		print = print->right;
	}

	//첫번째 항목 출
	printf("%d ", print->key);

	while ( print_count < 2*max-1 )
	{	
		//printf("(max-call : %d)", max-call_minus);
		switch ( mode )
		{
			case 0: //up
				for ( i = 0 ; i < max-call_minus ; i++ )
				{
					printf("%d ", travel('u',max));
				}
				mode=1;
				break;
			case 1: //left
				for ( i = 0 ; i < max-call_minus ; i++ )
				{
					printf("%d ", travel('l',max));
				}
				mode=2;
				break;
			case 2: //down
				for ( i = 0 ; i < max-call_minus ; i++ )
				{
					printf("%d ", travel('d',max));
				}
				mode=3;
				break;
			case 3: //right
				for ( i = 0 ; i < max-call_minus ; i++ )
				{
					printf("%d ", travel('r',max));
				}
				mode=0;
				break;
		}
		if ( print_count == 2 || (print_count - tmp_count) == 2 )
		{
			tmp_count = print_count;
			call_minus++;
		}
		print_count++;
	}
	printf("\n\n");
}

int travel(char direction, int max)
{
	int i;

	switch ( direction )
	{
		case 'r':
			print=print->right;
			break;
		case 'l':
			print=print->left;
			break;
		case 'u':
			for ( i = 0 ; i < max; i++ )
			{
				print=print->left;
			}
			break;
		case 'd':
			for ( i = 0 ; i < max ; i++ )
			{
				print=print->right;
			}
			break;
	}

	return print->key;
}
