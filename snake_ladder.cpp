#include <bits/stdc++.h>
using namespace std;

struct myQueue{
    int pos;
    int dist;
};

int main() {
	int t;
	cin>>t;

	while(t--){
	    int n;
	    cin>>n;

	    bool visited[31];
	    memset(visited, false, sizeof(visited));

	    int arr[31];
	    memset(arr, -1, sizeof(arr));

	    for(int i=0; i<n; i++){
	        int s,d;
	        cin>>s>>d;
	        arr[s] = d;
	    }

	    struct myQueue start;
	    start.pos = 1;
	    start.dist = 0;

	    queue<struct myQueue> q;
	    q.push(start);
	    visited[1] = true;

	    while(!q.empty()){
	        int curr = q.front().pos;
	        int distance = q.front().dist;
	        q.pop();

	        if(curr == 30){
	            cout<<distance<<endl;
	            break;
	        }

	        for(int i=1; i<=6; i++){
	            if(curr+i <= 30 && !visited[curr+i]){
	                visited[curr+i] = true;

	                struct myQueue temp;
	                if(arr[curr+i] == -1)
	                    temp.pos = curr+i;
	                else
	                    temp.pos = arr[curr+i];
	                temp.dist = distance+1;
	                q.push(temp);
	            }
	        }
	    }
	}
	return 0;
}
