/*
Description
  Cheer is going to give a surprise to Jessie Lin on Christmas¡¯ Eve. He gives Jessie three pipes and some balls. There is one word on each ball. Cheer will ask Jessie to take N actions. The three pipes are numbered 1,2,3 and each action would be the kind of ¡°Take¡±, ¡°Push¡±, ¡°Pop¡± or ¡°Read¡±:

Take X: Here X stands for a word. Jessie should take the ball which with the word X on it and put it into Pipe 1 and that ball will be the top ball in Pipe 1.
Push: If there is no ball in Pipe 1, just ignore this action. Otherwise Jessie should take away the BOTTOM BALL from Pipe 1 and then put it into Pipe 2 and also that ball will be the top ball in Pipe 2.
Pop: If there is no ball in Pipe 2, just ignore this action. Otherwise Jessie should take away the TOP BALL from Pipe 2 and then put it into Pipe 3 and also that ball will be the top ball in Pipe 3.
Read: Jessie should read the words on the balls in Pipe 3 from top to bottom. There will be only one ¡°Read¡± action and no more action follows.
Sometimes Jessie won¡¯t have time to finish all these actions, so Cheer has to prepare a program to do these actions in case of it. Help Cheer to finish the job!
Input
  There are multiple test cases.

The first line is an integer T, the number of test cases.
 
For each test case, there will be a sequence of actions from ¡°Take X¡±, ¡±Push¡± ,Pop¡± and ¡°Read¡±, one action a line, ending with a ¡°Read¡± action, as described before. All the words on the balls are consisted of no more than 10 letters. There will be no more than 100 ¡°Take X¡± actions. There will be at least one ball in Pipe 3 after all the actions. See the sample input for more details.  
Output
  For each test case, output one line containing the result from the ¡°Read¡± action. Each word should be separated by exactly one space. There should not be any blanks in the end of each line. See the sample output for more details.

Sample Input
 Copy sample input to clipboard
2

Take world
Push 
Take Hello
Pop
Push
Pop
Pop
Read

Take I 
Take Lin 
Take forever
Take Jessie 
Take love 
Push
Push 
Push 
Pop
Pop
Push 
Pop
Push 
Pop
Pop
Read
Sample Output
hello world
I love Jessie Lin forever
*/

#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

int main(){
	int t;
	string command, word;
	stack<string> pipe2, pipe3;
	vector<string> pipe1;
	cin >> t;
	while (t--){
		pipe1.clear();
		while (!pipe2.empty())
			pipe2.pop();
		while (!pipe3.empty())
			pipe3.pop();
		while (true){
			cin >> command;
			if (command == "Take"){
				cin >> word;
				pipe1.insert(pipe1.begin(), word);
			}
			else if (command == "Push"){
				if (!pipe1.empty()){
					pipe2.push(pipe1[pipe1.size()-1]);
					pipe1.erase(pipe1.end()-1);
				}
			}
			else if (command == "Pop"){
				if (!pipe2.empty()){
					pipe3.push(pipe2.top());
					pipe2.pop();
				}
			}
			else if (command == "Read"){
				if (!pipe3.empty()){
					cout << pipe3.top();
					pipe3.pop();
				}
				while (!pipe3.empty()){
					cout << " " << pipe3.top();
					pipe3.pop();
				}
				cout << endl;
				break;
			}
			else{;}
		}
	}
	system("pause");
	return 0;
}
