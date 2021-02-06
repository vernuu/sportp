//https://codeforces.com/group/thOWHpwJb2/contest/315198/problem/B
//✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗
//✗    ✗       ✗      ✗      ✗✗✗    ✗    ✗✗       ✗          ✗          ✗
//✗    ✗       ✗      ✗    ✗         ✗  ✗          ✗          ✗         ✗
//✗    ✗       ✗      ✗    ✗         ✗✗✗      ✗✗✗✗✗✗✗  ✗✗✗✗✗✗✗    ✗
//✗    ✗        ✗    ✗     ✗         ✗   ✗        ✗          ✗        ✗
//✗    ✗✗✗✗     ✗✗✗        ✗✗✗     ✗    ✗✗     ✗          ✗       ✗
//✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗✗
#pragma GCC optimize("Ofast")
//#pragma GCC optimization ("O3")
//#pragma GCC optimize("unroll-loops")
#pragma once
//#pragma GCC optimize("")
#pragma GCC target("sse,sse2,sse3,sse4,mmx,avx,avx2")
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
const int inf = 1e9+7;
clock_t start;
mt19937 gen( chrono::high_resolution_clock::now( ).time_since_epoch( ).count( ) );
typedef int (*func)(int a, int b);




struct SQRT_TreeV1{

     func FunctionT;
     int Operation( int &a, int &b ){
          return FunctionT( a, b );
     }



     int n, lg;
     vector < int > Layers, V, OnLayer, Clz;
     vector < vector < int > > Prefix, Suffix, Central;


     int Log2( int v ){
          int res = 0;
          while( ( 1 << res ) < n ) ++ res;
          return res;
     }


     void Build( int layer, int L, int R ){
          if( layer >= Layers.size( ) ) return;

          int BlockCountLog = ( Layers[layer]     ) >> 1;
          int BlockSizeLog  = ( Layers[layer] + 1 ) >> 1;
          int BlockSize     = ( 1 << BlockSizeLog      );
          int BlockCount    = 0;

          for( int i = L; i < R; i += BlockSize ){


               BlockCount ++;
               int r = min( i + BlockSize, R );


               Prefix[layer][i] = V[i];
               for( int j = i + 1; j < r; j ++ ){
                    Prefix[layer][j] = Operation( Prefix[layer][j - 1], V[j] );
               }


               Suffix[layer][r - 1] = V[r - 1];
               for( int j = r - 2; j >= i; j -- ){
                    Suffix[layer][j] = Operation( Suffix[layer][j + 1], V[j] );
               }


               Build( layer + 1, i, r );

          }


          for( int i = 0; i < BlockCount; ++ i ){
               int ans = 0;
               for( int j = i; j < BlockCount; ++ j ){

                    if( i == j ){
                         ans = Suffix[layer][L + ( j << BlockSizeLog )];
                    }else{
                         ans = Operation( ans, Suffix[layer][L + ( j << BlockSizeLog )] );
                    }

                    Central[layer][L + ( i << BlockCountLog ) + j] = ans;
               }
          }

     }





     int Query( int L, int R ){
          if( L == R ) return V[L];
          if( R - 1 == L ) return Operation( V[L], V[R] );

          int layer         = ( OnLayer[Clz[L^R]] );
          int BlockCountLog = ( Layers[layer]     ) >> 1;
          int BlockSizeLog  = ( Layers[layer] + 1 ) >> 1;
          int l             = ( ( L >> Layers[layer] ) << Layers[layer] );
          int LeftBlock     = ( ( L - l ) >> BlockSizeLog ) + 1;
          int RightBlock    = ( ( R - l ) >> BlockSizeLog ) - 1;
          int ans           = ( Suffix[layer][L] );

          if( LeftBlock <= RightBlock ){
               ans = Operation( ans, Central[layer][l + ( LeftBlock << BlockCountLog ) + RightBlock] );
          }

          ans = Operation( ans, Prefix[layer][R] );

          return ans;
     }



     SQRT_TreeV1( vector < int > &A, func EAR ){
          FunctionT = EAR;
          V = A;
          n = V.size( );
          lg = Log2( n );
          Clz.resize( ( 1 << lg ), 0 );
          OnLayer.resize( lg + 1 );
          //Clz[0] = 0;


          for( int i = 1; i < ( 1 << lg ); ++ i ){
               Clz[i] = Clz[( i >> 1 )] + 1;
               //cerr << Clz[i] << '\n';
          }


          int tlg = lg;
          while( tlg > 1 ){
               OnLayer[tlg] = ( int ) Layers.size( );
               Layers.pb( tlg );
               tlg = ( tlg + 1 ) >> 1;
          }


          for( int i = lg - 1; i >= 0; -- i ){
               OnLayer[i] = max( OnLayer[i], OnLayer[i + 1] );
          }

          Prefix.assign( Layers.size( ), vector < int > ( n ) );
          Suffix.assign( Layers.size( ), vector < int > ( n ) );
          Central.assign( Layers.size( ), vector < int > ( 1 << lg ) );

          Build( 0, 0, n );

     }



};



int min_f132( int a, int b ){
     return min( a, b );
}




int32_t main( ){
          ///https://codeforces.com/group/thOWHpwJb2/contest/315198/problem/B


          ios_base::sync_with_stdio( 0 );
          cin.tie( 0 ); cout.tie( 0 );



          int n, ans = -1000000007;
          cin >> n;
          vector < int > A( n );
          for( int i = 0; i < n; ++ i ) cin >> A[i];


          SQRT_TreeV1 TreeMin( A, &min_f132 ),
                      TreeGcd( A, __gcd );
          //SQRT_TreeV2 TreeGcd( A );


          int l = 0, r = n - 1;
          while( l <= r ){
               int mid = ( l + r ) >> 1;
               bool f = 0;

               for( int i = 0; i + mid < n; ++ i ){
                    int Min = TreeMin.Query( i, i + mid );
                    int Gcd = TreeGcd.Query( i, i + mid );
                    if( Min == Gcd ){
                         f = 1;
                         //cerr << i << ' ' << mid << '\n';
                         break;
                    }
               }


               if( f == 1 ){
                    ans = max( ans, mid );
                    l = mid + 1;
               }else{
                    r = mid - 1;
               }

          }


          //cerr << ans << '\n';
          if( ans == 0 ){
               cout << n << " 0\n";
               for( int i = 0; i < n; ++ i ) cout << i + 1 << ' ';
               cout << '\n';
               return 0;
          }


          vector < int > E;
          int cnt = 0;
          for( int i = 0; i + ans < n; ++ i ){
               int Min = TreeMin.Query( i, i + ans );
               int Gcd = TreeGcd.Query( i, i + ans );
               if( Min == Gcd ){
                    cnt ++;
                    E.pb( i );
               }
          }


          cout << cnt << ' ' << ans << '\n';
          for( int i = 0; i < cnt; ++ i ){
               cout << E[i] + 1 << ' ';
          }
          cout << '\n';



     return 0;
}





























////owoo
