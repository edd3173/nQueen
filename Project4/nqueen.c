#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int errFlag = 1; // err가 발생함을 알려주는 flag.

int isValid(int* q,int level) { // Total O(N) 
	//(q의) level번째 열에서 퀸의 위치가 가능한가 확인해보자
	//q[level]=i
	if (level == 0) // +1
		return 1; // 0번째 열에서는 아무렇게 놓아도 된다. 겹치는게 없음.
	else { 
		// 0~(level-1)번째 열에서 level열과 충돌을 일으키지 않는지 확인해보자.
		// 여기서 충돌이란,
		// 대각선에 있으면 안됨.
		// 이전 열들과 같은 행에 있으면 안됨.
		for (int j = 0; j < level; j++) { // j가 열 index // +1 ~ +N
			if ((q[j] == q[level]) || (abs(q[j] - q[level]) == abs(j - level))) // + 5 ~ +5N
				return 0;
			// 같은 행에 있거나, 대각선에 있거나.
		}
		return 1;
	}
}

void nQueen(int* q,int level,int length){
	if (level == length) {// count가 length까지 왔다. 다했다.
		errFlag = 0; // 따라서 err발생 X, 0. // +1
		for (int i = 0; i < level; i++) { // +N
			printf("%d ", q[i]);
		}
		exit(0);
	}
	else {
		for (int i = 0; i < length; i++) { // level번째 열에서, 퀸의 위치를 넣어보자. // +N
			q[level] = i; // (q의) level번째 렬에서 퀸의 위치가 i임 // +1
			if (isValid(q, level)) // 어디 확인해보자구 // Total O(N)
				nQueen(q, level + 1, length); // 유효하면 n+1번째 열 로 이동.
			//cascading multiplying lower tree. // O(N!)
		}
	}
}


int main()
{
	int length = -1; // length 초기화 // +1
	printf("input length > ");
	scanf("%d", &length);
	int level = 0; // level 초기화 // +1

	int* q = (int*)malloc(sizeof(int)*length); // queen array, based on col.
	// +1
	nQueen(q, level, length);
	if (errFlag == 1) // +1 ?
		printf("Error!\n"); 

	free(q);
	
	return 0;
}