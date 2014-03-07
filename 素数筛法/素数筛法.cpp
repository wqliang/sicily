#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

const int MAX = 10000;
bool prime[MAX + 1];

void searchprime() {
  memset(prime, true, sizeof(prime));
  prime[1] = false;
  for (int i = 2; i <= (int) floor(sqrt((double)MAX)); ++i) {
    if (prime[i]) {
      int j = i * 2;
      while (j <= MAX) {
        prime[j] = false;
        j += i;
	  }
	}
  }
}


int main(){
	searchprime();
	for (int i = 0 ;i < MAX + 1;++i)
		if (prime[i])
			cout << i << " ";
	system("pause");
	return 0;
}
	
  
