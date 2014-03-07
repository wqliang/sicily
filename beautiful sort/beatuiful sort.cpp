/*
Description
 Sorted array is beautiful and your task here is to make it. 
 Given N positive integer numbers, please output all the odd numbers in increasing order 
 and the all the even numbers in decreasing order.
 
Input
 The first line is a positive integer T (0<T<=10), T test cases follow.
For each of the test case, the first line will be a positive integer N (0<N<=100), 
the second line will be N integers less than 10000.

Output
  For each of the test cases output one line, first output all the odd numbers in increasing order 
  and the all the even numbers in decreasing order. Please separate the integers with one blank character. 
  There should not be any leading or tailing blank characters.

Sample Input
 Copy sample input to clipboard
2
6
5 3 4 2 9 6
3
1 2 3
Sample Output
3 5 9 6 4 2
1 3 2
*/

#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){
	if (a % 2 == 0 && b % 2 == 0)
		return a > b;
	if (a % 2 == 1 && b % 2 == 1)
		return a < b;
	if (a % 2 == 0 && b % 2 ==1){
		if (a > b)
			return a < b;
		else
			return a > b;
	}
	if (a % 2 == 1 && b % 2 == 0){
		if (a > b)
			return a > b;
		else
			return a < b;
	}
}

int main(){
	int t, size;
	int arr[101];
	cin >> t;
	while (t--){
		cin >> size;
		for (int i = 0; i < size; ++i)
			cin >> arr[i];
		sort(arr, arr+size, cmp);
		cout << arr[0];
		for (int i = 1; i < size; ++i)
			cout << " " << arr[i];
		cout << endl;
	}
	system("pause");
	return 0;
}