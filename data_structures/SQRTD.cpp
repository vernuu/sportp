//✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗
//✗    ✗       ✗      ✗      ✗✗✗    ✗    ✗✗       ✗         ✗         ✗
//✗    ✗       ✗      ✗    ✗         ✗  ✗         ✗         ✗        ✗
//✗    ✗       ✗      ✗    ✗         ✗✗✗✗      ✗✗✗✗✗✗✗   ✗✗✗✗✗✗✗    ✗
//✗    ✗        ✗    ✗     ✗         ✗  ✗✗        ✗         ✗      ✗
//✗    ✗✗✗✗      ✗✗✗✗       ✗✗✗✗    ✗     ✗       ✗         ✗     ✗
//✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗
//#pragma GCC optimize("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("")
#pragma GCC target("sse,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ull uint64_t
#define pll pair<ll,ll>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
//#define int ll
const int inf = 1e7+7;
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define MAX_PI 3.141592653589793


vector < vector < int > > G;
vector < pii > C;
vector < bool > U;
vector < int > R;



template < typename T, T null_value >
struct sqrtd{

     vector < T > V, B;
     int64_t k = 0;


     sqrtd( vector < T > &A ){
          //if( A.size( ) == 0 ) return;
          B = A;
          k = sqrt( A.size( ) );
          V.resize( k, null_value );
          for( int64_t i = 0; i < A.size( ); ++i ){
               V[i / k] += A[i];
          }
     }


     T sum( int64_t l, int64_t r ){
          T sum = null_value;
          for( ; l <= r; ){
               if( l % k == 0 ){
                    if( ( l + k ) <= r ){
                         sum += V[l / k];
                         l += k;
                    }else{
                         sum += B[l];
                         l++;
                    }
               }else{
                    sum += B[l];
                    l++;
               }
          }

          return sum;
     }

};






int32_t main(){

				//freopen("input.txt","r",stdin);
				//freopen("output.txt","w",stdout);
				ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
				ofstream fout("debug");


                    vector < int > A;
                    int n;
                    cin >> n;
                    A.resize( n );

                    for( int i = 0; i < n; ++i ) cin >> A[i];


                    sqrtd < int, 0 > B( A );





                    int qt = 1;
                    cin >> qt;



                    while( qt-- ){


                         int l, r;
                         cin >> l >> r, l--, --r;
                         cout << B.sum( l, r ) << '\n';
                         cout.flush( );

                    }


////////////////////////Use sqrt decomposition

return 0;}











///owoo
