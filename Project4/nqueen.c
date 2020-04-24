#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int errFlag = 1; // err�� �߻����� �˷��ִ� flag.

int isValid(int* q,int level) { // Total O(N) 
	//(q��) level��° ������ ���� ��ġ�� �����Ѱ� Ȯ���غ���
	//q[level]=i
	if (level == 0) // +1
		return 1; // 0��° �������� �ƹ����� ���Ƶ� �ȴ�. ��ġ�°� ����.
	else { 
		// 0~(level-1)��° ������ level���� �浹�� ����Ű�� �ʴ��� Ȯ���غ���.
		// ���⼭ �浹�̶�,
		// �밢���� ������ �ȵ�.
		// ���� ����� ���� �࿡ ������ �ȵ�.
		for (int j = 0; j < level; j++) { // j�� �� index // +1 ~ +N
			if ((q[j] == q[level]) || (abs(q[j] - q[level]) == abs(j - level))) // + 5 ~ +5N
				return 0;
			// ���� �࿡ �ְų�, �밢���� �ְų�.
		}
		return 1;
	}
}

void nQueen(int* q,int level,int length){
	if (level == length) {// count�� length���� �Դ�. ���ߴ�.
		errFlag = 0; // ���� err�߻� X, 0. // +1
		for (int i = 0; i < level; i++) { // +N
			printf("%d ", q[i]);
		}
		exit(0);
	}
	else {
		for (int i = 0; i < length; i++) { // level��° ������, ���� ��ġ�� �־��. // +N
			q[level] = i; // (q��) level��° �Ŀ��� ���� ��ġ�� i�� // +1
			if (isValid(q, level)) // ��� Ȯ���غ��ڱ� // Total O(N)
				nQueen(q, level + 1, length); // ��ȿ�ϸ� n+1��° �� �� �̵�.
			//cascading multiplying lower tree. // O(N!)
		}
	}
}


int main()
{
	int length = -1; // length �ʱ�ȭ // +1
	printf("input length > ");
	scanf("%d", &length);
	int level = 0; // level �ʱ�ȭ // +1

	int* q = (int*)malloc(sizeof(int)*length); // queen array, based on col.
	// +1
	nQueen(q, level, length);
	if (errFlag == 1) // +1 ?
		printf("Error!\n"); 

	free(q);
	
	return 0;
}