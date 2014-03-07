#include<queue>
#include<iostream>
using namespace std;
struct node{
	int a;
	int b;
}
bool cmp(node& a, node& b){
	if (a.b > b.b)
		return true;
	else
		return false;
}
int main(){
	priority_queue<node, cmp> pq;
	node n1, n2, n3;
	n1.a = 1;
	n1.b = 2;
	n2.a = 2;
	n2.b = 1;
	n3.a = 5;
	n3.b = 5;
	pq.push(n1);
	pq.push(n2);
	pq.push(n3);
	while (!pq.empty()){
		cout << pq.top().a << " " << pq.top().b << endl;
		pq.pop();
	}
	system("pause");
	return 0;
}