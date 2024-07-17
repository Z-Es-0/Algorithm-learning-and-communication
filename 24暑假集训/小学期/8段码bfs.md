```cpp
#include <bits/stdc++.h>
using namespace std;

struct zt {
    vector<int> tu;
    int there;

    bool operator<(const zt& other) const {
        if (there != other.there) {
            return there < other.there;
        }
        return tu < other.tu;
    }

    bool operator==(const zt& other) const {
        return there == other.there && tu == other.tu;
    }

    zt& operator=(const zt& other) {
        if (this != &other) {
            there = other.there;
            tu = other.tu;
        }
        return *this;
    }
};

set<zt> st;
queue<zt> q;
map<zt, zt> mp;
vector<int> goal = {1, 2, 3, 4, 5, 6, 7, 8, 0};
int tiao[] = {3, -3, 1, -1};

bool checkkk(int a, int i) {
    if (a % 3 == 0 && i == -1) return false;
    if (a % 3 == 2 && i == 1) return false;
    return true;
}

void print_ans(const zt& ans) {
    stack<zt> path;
    zt current = ans;
    while (mp.count(current) > 0) {
        path.push(current);
        current = mp[current];
    }
    path.push(current);

    while (!path.empty()) {
        current = path.top();
        path.pop();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << current.tu[i * 3 + j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}

void bfs(const zt& begin) {
    st.clear();
    q.push(begin);
    st.insert(begin);
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            cout << begin.tu[i * 3 + j] << ' ';
//        }
//        cout << endl;
//    }
//    cout << endl;

    while (!q.empty()) {
        zt x = q.front();
        q.pop();

        for (int i : tiao) {
            if (x.there + i >= 0 && x.there + i < 9 && checkkk(x.there, i)) {
                zt next = x;
                next.there = x.there + i;
                swap(next.tu[x.there], next.tu[next.there]);

                if (st.count(next) == 0) {
                    q.push(next);
                    mp[next] = x;
                    st.insert(next);

                    if (next.tu == goal) {
                        cout << "Solution found!\n";
                        print_ans(next);
                        return;
                    }
                }
            }
        }
    }

    cout << "No solution found.\n";
}
int s[9];

bool ck(int i ,int p){
    for (int j = 0; j < i; ++j) {
        if (p == s[j]) return false;
    }
    return true;
}
int check(){
    int count =0;
    for (int i = 0; i < 9; ++i) {
        for (int j = i+1; j < 9; ++j) {
            if (s[j]<s[i] && s[j]!=0 && s[i]!=0)count++;
        }
    }
    return count;
}
vector<int> start(9);
void solve() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < 9; ++i)
    {
        int p =(int ) rand ()%9;
        while (!ck(i,p)){
            p =(int ) rand ()%9;
        }
        s[i]=p;
    }
    for (int i = 0; i < 9; ++i) {
        start[i]=s[i];
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout<<s[i*3+j]<<' ';
        }
        cout<<endl;
    }
    cout<<check()<<endl;
    zt firstt;
    firstt.tu = start;
    for (int i = 0; i < 9; ++i) {
        if (start[i] == 0) {
            firstt.there = i;
            break;
        }
    }
//    for (int i = 0; i < 3; ++i) {
//        for (int j = 0; j < 3; ++j) {
//            cout << start[i * 3 + j] << ' ';
//        }
//        cout << endl;
//    }
//    cout << endl;

    bfs(firstt);
}

int main() {
    int a =clock();
    solve();
    int b =clock();
    cout<<"run "<<b-a<<" ms "<<endl;
    return 0;
}
```



