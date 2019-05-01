#include <bits/stdc++.h>
using namespace std;

template <class T> class myQueue{
public:
  static const int MAX = 1e7;
  int head;
  int tail;
  T *Q;

  myQueue(){
    head = 0; tail = 0;
    Q = new T[MAX];
  }
  bool isEmpty(){
    return head == tail;
  }
  bool isFull(){
    return head == (tail + 1) % MAX;
  }
  void enqueue(T x){
    if(isFull()) {cerr << "isFull" << endl; return;}
    Q[tail] = x;
    tail = (tail + 1) % MAX;
  }
  T dequeue(){
    if(isEmpty()) {cerr << "isEmpty" << endl;}
    T x = Q[head];
    head = (head + 1) % MAX;
    return x;
  }
};
int main(){
  int n, q; cin >> n >> q;
  myQueue<pair<string, int>> a;
//  queue<pair<string, int>> a;
  for(int i = 0; i < n; i++){
    string name; cin >> name;
    int time; cin >> time;
    a.enqueue(make_pair(name, time));
//    a.push(make_pair(name, time));
  }
  int temp = 0;
  while(!a.isEmpty()){
    pair<string, int> proc = a.dequeue();
    if(proc.second <= q){
      temp += proc.second;
      cout << proc.first << ' ' << temp << endl;
    }
    else{
      temp += q;
      a.enqueue(make_pair(proc.first, proc.second - q));
    }
  }
}
