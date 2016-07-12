//�����ֽ��������

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define inf 10000000000

using namespace std;

typedef long long ll;

const int N = 1000000;
const int mod = 9973;

int main()
{
	int T, g, l;
	scanf("%d", &T);
	while(T --){
		scanf("%d%d", &g, &l);
		int ans = 1, ct;
		if (l % g != 0 || g > l) {
			puts("0");
		}
		else {
			l /= g;
			int m = (int)sqrt(l + 0.5);
			// ��2������n���б�������Ϊһ���������һ�����ڸ���n��������
			for (int i = 2; i <= m ; i++) { 
				if (l % i == 0) {
					ct = 0;
					while (l % i == 0) {
						ct++;
						l /= i;
					}
					//�ݳ�ԭ�� ȫ�� - ������0�� - ������ai�� + ��������0Ҳ������ai��
					ans *= ((ct + 1)*(ct + 1)*(ct + 1) - 2 * ct*ct*ct + (ct - 1)*(ct - 1)*(ct - 1));
				}
			}
			if (l > 1) //����1˵����һ�����ڸ���n��������
				ans *= 6;
			printf("%d\n", ans);
		}
	}
	return 0;
}