// Problem#: 1153
// Submission#: 2184275
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<time.h>
using namespace std;

struct node{
    int x, y, toNext;
    string path;
};

const string str[65]={"","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15",
    "16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34",
    "35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52",
    "53","54","55","56","57","58","59","60","61","62","63","64"};

int x[8] = {-2, -1, +1, +2, -2, -1, +1, +2};
int y[8] = {-1, -2, -2, -1, +1, +2, +2, +1};

bool valid(node next){
    return (0 <= next.x && next.x < 8 && 0 <= next.y && next.y < 8);
}

bool cmp(node n1, node n2){
    return n1.toNext < n2.toNext;
}

vector<node> findNext(node cur, int visit[]){
    node next, next2;
    vector<node> tmp;
    for (int i = 0; i < 8; ++i){
        next.x = cur.x + x[i];
        next.y = cur.y + y[i];
        if (valid(next)){
            int index = next.y * 8 + next.x + 1;
            if (visit[index] == 0){
                next.path = str[index];
                next.toNext = 0;
                for (int j = 0; j < 8; ++j){
                    next2.x = next.x + x[j];
                    next2.y = next.y + y[j];
                    if (valid(next2)){
                        int index2 = next2.y * 8 + next2.x + 1;
                        if (visit[index2] == 0)
                            ++next.toNext;
                    }
                }
                tmp.push_back(next);
            }
        }
    }
    sort(tmp.begin(), tmp.end(), cmp);
    return tmp;
}

string dfs(int visit[], node cur, int step){
    if (step == 64){
        return cur.path;
    }
    else{
        vector<node> nexts = findNext(cur, visit);
        for (int i = 0; i < nexts.size(); ++i){
            int index = nexts[i].y * 8 + nexts[i].x + 1;
            visit[index] = 1;
            string c = dfs(visit, nexts[i], step+1);
            if (c == "")
                visit[index] = 0;
            else
				return (cur.path + " " + c);
        }
    }
    return "";
}

int main (){
    node* grid = new node[65];
    for (int i = 1; i < 65; ++i){
        grid[i].x = (i - 1) % 8;
        grid[i].y = (i - 1) / 8;
        grid[i].path = str[i];
    }
    int step = 1;
    int start;
    while (cin >> start && start != -1){
        int visited[65] = {0};
        visited[start] = 1;
		clock_t s = clock();
        string path = dfs(visited, grid[start], step);
		clock_t e = clock();
		cout << "time:" << 1000*(e - s)/ CLOCKS_PER_SEC << "  ms\n";
        cout << path << "\n";
    }
	system("pause");
    return 0;
}                                 