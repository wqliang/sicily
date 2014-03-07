#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int main(){
	int n, m, t, hightest, index, time;
	int priority[101];
	cin >> t;
	while (t--){
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> priority[i];
		int my_pri = priority[m];
		priority_queue<int> pq(priority, priority+n);
		index = 0;
		time = 0;
		hightest = pq.top();
		while (my_pri < hightest || index != m){
			if (hightest <= priority[index]){
				time++;
				priority[index] = 0-1;
				pq.pop();
				hightest = pq.top();
			}
			index++;
			if (index >= n)
				index = 0;
			
		}
		cout << time+1 << endl;
	}


	system("pause");
	return 0;
}