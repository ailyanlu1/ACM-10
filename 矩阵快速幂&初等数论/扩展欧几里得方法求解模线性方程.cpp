ll exgcd(ll a, ll b, ll& x, ll& y) { //��չŷ������㷢�����ax + by = d = gcd(a, b)�Ľ�
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll d = exgcd(b, a%b, x, y), tmp; 
	//x = y', y = x' - a / b * y'
	tmp = x; 
	x = y;
	y = tmp - a / b*y;
	return d;
}
//���ģ���Է��̣�ax = b (mod n) 
//�÷��̵��ҽ��� b|d ʱ��d���⣬ÿ����֮�����n/d
void modular_linear(ll a, ll b, ll n) { 
	if (b == 0) {
		puts("0");
		return;
	}
	ll d, x, y;
	d = exgcd(a, n, x, y);
	if (b % d != 0) {
		printf("FOREVER\n");
	}
	else {
		x = (x*b / d) % n; 
		x = (x % (n / d) + n / d) % (n / d); //�����С�������� �����Ϊ (x+ i * n / d) % n (i = 1,2,3...)
		printf("%I64d\n", x);
	}
}
