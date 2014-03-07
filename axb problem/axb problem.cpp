/*
Description
  Please calculate a*b

Input
  The first integer T (<=10) indicates the number of cases. There follows T cases.

In every case, there are two integers a, b (0 < a, b < 10^100).
 
Output
  For every case, output a*b on a single line.

Sample Input
 Copy sample input to clipboard
2
2 5
565436543 636543653642332545425425423
Sample Output
10
359925042984109872941743015485432689
*/

#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main(){
	int result[210], aa[101], bb[101];
	string a, b;
	int t;
	cin >> t;
	while (t--){
		memset(result, 0, sizeof(result));
		memset(aa, 0, sizeof(aa));
		memset(bb, 0, sizeof(bb));
		cin >> a >> b;
		int len = a.length();
		for (int i = len-1; i >=0; i--)
			aa[len-1-i] = a[i] - '0';
		len = b.length();
		for (int i = len-1; i >=0; i--)
			bb[len-1-i] = b[i] - '0';

		for (int k = 0; k < b.length(); k++){
			for (int i = 0, j = k; i < a.length(); i++, j++){
				result[j] += (aa[i] * bb[k]) % 10;
				if (result[j] > 9){
					result[j] = result[j] % 10;
					result[j+1]++;
				}
				result[j + 1] += (aa[i] * bb[k]) / 10;
				if (result[j+1] > 9){
					result[j+1] = result[j+1] % 10;
					result[j+2]++;
				}
			}
		}
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
	}
	system("pause");
	return 0;
}
