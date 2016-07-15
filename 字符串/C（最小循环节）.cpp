// ACMdata.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<cstdio>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;
const int N = 15;

int Next[1000001];
char s[1000001];
void getNext() {
	int j = 0, k = -1;
	Next[0] = -1;
	while (s[j] != '\0') {
		while (k != -1 && s[k] != s[j])
			k = Next[k];
		Next[++j] = ++k;
	}
}


int main()	
{
	int n ,cnt = 1;
	while (~scanf("%d", &n) && n) {
		scanf("%s", s);
		getNext();
		printf("Test case #%d\n", cnt++);
		for (int i = 1; i <= n; i++) {
			// ��ʾǰ׺��ȫ�����ѭ���ڹ��ɣ����ȡģ������0�Ļ�˵����aaaab���������a����Сѭ����,��ֻ�ܹ���ĳ���ִ�
			if (Next[i] > 0 && i%(i-Next[i]) == 0) {
				printf("%d %d\n", i, i / (i - Next[i]));
			}
		}
		printf("\n");
	}



    return 0;
}
