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




struct SQRT_TreeV1{

     int Operation( int a, int b ){
          return min( a, b );
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



     SQRT_TreeV1( vector < int > &A ){
          V = A;
          n = V.size( );
          lg = Log2( n );
          Clz.resize( ( 1 << lg ), 0 );
          OnLayer.resize( lg + 1 );
          //Clz[0] = 0;


          for( int i = 1; i < ( 1 << lg ); ++ i ){
               Clz[i] = Clz[( i >> 1 )] + 1;
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







int32_t main( ){



          ios_base::sync_with_stdio( 0 );
          cin.tie( 0 ); cout.tie( 0 );



          int n, m, l, r;
          cin >> n >> m;
          vector < int > A( n );
          cin >> A[0] >> l >> r;



          int mod = 16714589;
          for( int i = 1; i < n; i ++ ){
               A[i] = ( 23 * A[i - 1] + 21563 ) % mod;
          }
          SQRT_TreeV1 Tree( A );


          for( int i = 0; i < m - 1; ++ i ){
               int ans;
               if( r < l ) ans = Tree.Query( r - 1, l - 1 );
               else        ans = Tree.Query( l - 1, r - 1 );
               //cout << ans << '\n';
               //cerr << l << ' ' << r << '\n';
               l = ( 17 * l + ans + 751 + 2 * ( i + 1 ) ) % n;
               ++ l;

               r = ( 13 * r + ans + 593 + 5 * ( i + 1 ) ) % n;
               ++ r;
          }


          int ans;
          if( r < l ) ans = Tree.Query( r - 1, l - 1 );
          else        ans = Tree.Query( l - 1, r - 1 );
          cout << l << ' ' << r << ' ' << ans << '\n';



     return 0;
}





























////owoo
