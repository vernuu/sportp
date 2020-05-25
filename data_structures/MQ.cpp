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
const int INF = 1e9+7;
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define MAX_PI 3.141592653589793
#define CEV 100000


///stack : push() , top() , pop() , swap() , size() , empty()
template < typename T, T MIN_LIM, T MAX_LIM >
struct mq{

     stack < pair < T, pair < T, T > > > A , B;



     void push( T x ){
          T minq = x;
          T maxq = x;
          if( A.size( ) ){
               minq = min( minq, A.top( ).S.F );
               maxq = max( maxq, A.top( ).S.S );
          }
          A.push( { x, { minq, maxq } } );
     }



     void pop( ){

          if( !B.size( ) ){
               while( A.size( ) ){
                    T minq = MAX_LIM;
                    T maxq = MIN_LIM;
                    minq = min( minq, A.top( ).F );
                    maxq = max( maxq, A.top( ).F );
                    B.push( { A.top( ).F, { minq, maxq } } );
                    A.pop( );
               }
          }

          B.pop( );
     }



     T mini( ){
          T minq = MAX_LIM;
          if( A.size() ) minq = min( minq, A.top( ).S.F );
          if( B.size() ) minq = min( minq, B.top( ).S.F );
          return minq;
     }



     T maxi( ){
          T maxq = MIN_LIM;
          if( A.size() ) maxq = max( maxq, A.top( ).S.S );
          if( B.size() ) maxq = max( maxq, B.top( ).S.S );
          return maxq;
     }

};



int32_t main(){

				//freopen("berries.in","r",stdin);
				//freopen("berries.out","w",stdout);
				ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
				ofstream fout("debug");



                    int qt = 1;
                    cin >> qt;




                    mq < int, -MAX_MOD, MAX_MOD > Q;
                    while( qt-- ){

                         char t;
                         cin >> t;
                         if( t == '+' ){
                              int x;
                              cin >> x;

                              Q.push( x );

                         }

                         if( t == '-' ){

                              Q.pop( );

                         }

                         if( t == '?' ){

                              cout << Q.mini( ) << ' ' << Q.maxi( ) << '\n';

                         }


                         cout.flush();

                    }



return 0;}











///owoo
