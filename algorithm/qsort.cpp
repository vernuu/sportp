#pragma GCC optimization ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ii int
#define ull uint64_t
#define pll pair<ll,ll>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
//const int combo = 1844607;

vector <ll> a;



void qtt(ll l, ll r){
	ll mid=a[(l+r)/2],lx=l,rx=r;
	do{
		while(a[lx]<mid) lx++;
		while(a[rx]>mid) rx--;
		if(lx<=rx){swap(a[lx],a[rx]); lx++; rx--;}

	}while(lx<=rx);
	if(l<rx) qtt(l,rx);
	if(lx<r) qtt(lx,r);

}



int main(){
               //freopen("input.txt","r",stdin);
               //freopen("output.txt","w",stdout);
               //ofstream fout("debug.txt");
               //fout.open("debug.txt");
               ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);




               ll n; cin >> n;
               srand (time(NULL));
               for(ll i=0;i<n;i++){
                    a.pb(rand()%100000000000);
               }

               clock_t start;



               start=clock();
               qtt(0,n-1);
               cout << (double(clock()-start))/ CLOCKS_PER_SEC << '\n';





return 0;}








///owoo
