// ACMdata.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<cstdio>
#define inf 1000001
using namespace std;



int a[1000001], b[10001], Next[10001];
int n, m, T;

//����next����δ�Ż�������������ѭ����
void getNext1() {
	int j = 0, k = -1;
	Next[0] = -1;
	while (b[j] != inf) {
		while (k != -1 && b[j] != b[k]) {
			k = Next[k];
		}
		i++; j++;
		Next[j] = k;
	}
}

//�Ż����next����
void getNext() {
	int j = 0, k = -1;
	Next[0] = -1;
	while (b[j] != inf) {
		while (k != -1 && b[j] != b[k]) {
			k = Next[k];
		}
		if (b[++j] == b[++k])
			Next[j] = Next[k];
		else
			Next[j] = k;
	}
}

int kmp() {
	getNext();
	int ans = 0, i = 0, j = 0;
	while (a[i] != inf) {
		while (j != -1 && a[i] != b[j])
			j = Next[j];
		i++;
		j++;
		if (j != -1 && b[j] == inf) {
			return i - j + 1;
		}
	}
	return -1;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int j = 0; j < m; j++) 
			scanf("%d", &b[j]);
		a[n] = b[m] = inf;
		getNext();
		printf("%d\n", kmp());
	}
	
    return 0;
}

