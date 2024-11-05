#include<bits/stdc++.h>
using namespace std;


struct segmenttree {
	vector<int> st;
	int n;

	void init(int _n) {
		n = _n;
		st.resize(4*n,0);
	}


	void build_helper(vector<int> &arr, int start, int end , int node) {
		if(start==end) {
			 st[node] = arr[start];
			 return;
		}

		int mid = start + (end-start)/2;
		build_helper(arr,start,mid,2*node+1);
		build_helper(arr,mid+1,end,2*node+2);

		st[node] = max(st[2*node+1],st[2*node+2]);
	}

	void build(vector<int> arr) {
		build_helper(arr,0,n-1,0);
	}

	int query_helper(int L ,int R, int start, int end , int node) {
		if(start>=L && end <= R) {
			return st[node];
		}

		if(end < L || start > R) return 0;


		int mid = start + (end - start)/2;
		int L_ans = query_helper(L,R,start,mid,2*node+1);
		int R_ans = query_helper(L,R,mid+1,end,2*node+2);

		return max(L_ans,R_ans);
	}




	int query(int L, int R) {
		return query_helper(L,R,0,n-1,0);
	}

};
/*


-- is question em hame maximum nikalna

-- array is given
-- we have to build segment tree
-- nodes are part of segment tree
-- segment tree


*/

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int n = 7;
	vector<int> arr = {7,8,10,6,3,4,13};

	segmenttree tree;
	tree.init(n);
	tree.build(arr);
	int t;
	cin>>t;
	while(t--) {
		int a, b;
		cin>>a>>b;
		cout<<"maximum value in range "<<a<<":"<<b<<" is "<<tree.query(a,b)<<"\n";
	}

	/*
	5
0 4 10
0 6 13
0 1 8
1 2 10
4 6 13
	*/



}