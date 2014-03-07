#include<iostream>
#include<string>
#include<string.h>
using namespace std;

bool nosmallthan(const int* a, int pos, const int* b, int size){
	for (int i = size - 1; i >= 0; i--){
		if (a[pos+i] > b[i])
			return true;
		else if (a[pos+i] == b[i])
			continue;
		else
			return false;
	}
	return true;
}

void subs(int* a, int pos, int* b, int len){
	for (int i = len - 1; i >= 0; i--){
		if (a[pos+i] < b[i]){
			a[pos+i+1]--;
			a[pos+i] += 10;
		}
		a[pos + i] -= b[i];
	}
}

int main(){
	int result[210], aa[101], bb[101], remainder[101];
	string a, b;
	int t;
	cin >> t;
	while (t--){
		memset(result, 0, sizeof(result));
		memset(aa, 0, sizeof(aa));
		memset(bb, 0, sizeof(bb));
		memset(remainder, 0, sizeof(remainder));
		cin >> a >> b;
		int len = a.length();
		for (int i = len-1; i >=0; i--)
			aa[len-1-i] = a[i] - '0';
		len = b.length();
		for (int i = len-1; i >=0; i--)
			bb[len-1-i] = b[i] - '0';

		//计算a/b；
		for (int k = a.length()-b.length(); k >= 0 ; k--){
			while (nosmallthan(aa, k, bb, len+1)){
				subs(aa, k, bb, len+1);
				result[k]++;
			}
		}
		//输出商
		bool flag = false;
		for (int i = a.length()+b.length(); i >=0; i--){
			if (result[i] == 0 && !flag){
				if (i == 0)
					cout << 0;
				continue;
			}
			flag = true;
			cout << result[i];
		}
		cout << endl;
		//输出余数；
		flag = false;
		for (int i = a.length()+b.length(); i >=0; i--){
			if (aa[i] == 0 && !flag){
				if (i == 0)
					cout << 0;
				continue;
			}
			flag = true;
			cout << aa[i];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
