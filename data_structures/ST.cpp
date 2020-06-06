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
#define int int64_t
const int inf = 1e7+7;
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define MAX_PI 3.141592653589793




template < typename T, T default_value, T minimal_value, T maximal_value, bool gcd_enable = 0, bool lca_enable = 0, bool min_enable = 0, bool max_enable = 0, bool sum_enable = 0 >
struct st{


     vector < T > tree_gcd;
     vector < T > tree_lca;
     vector < T > tree_min;
     vector < T > tree_max;
     vector < T > tree_sum;


     int64_t tree_sz( ){
          int64_t ansver = 0;
          if( gcd_enable ) if( tree_gcd.size() > ansver ) ansver = tree_gcd.size();
          if( lca_enable ) if( tree_lca.size() > ansver ) ansver = tree_lca.size();
          if( min_enable ) if( tree_min.size() > ansver ) ansver = tree_min.size();
          if( max_enable ) if( tree_max.size() > ansver ) ansver = tree_max.size();
          if( sum_enable ) if( tree_sum.size() > ansver ) ansver = tree_sum.size();
          return ansver;
     }


     T gcd_func( T a, T b ){
          while( b ){
               a %= b;
               swap( a, b );
          }

          return a;
     }


     T lca_func( T a, T b ){
          return ( a * b ) / gcd_func( a, b );
     }


     T min_func( T a, T b ){
          if( a > b ) return b;
          else return a;
     }


     T max_func( T a, T b ){
          if( a < b ) return b;
          else return a;
     }


     T sum_func( T a, T b ){
          return ( a + b );
     }


     void _st_build( vector < T > &A, int64_t v, int64_t l, int64_t r ){
          if( l == r ){
               if( gcd_enable ) tree_gcd[v] = A[l];
               if( lca_enable ) tree_lca[v] = A[l];
               if( min_enable ) tree_min[v] = A[l];
               if( max_enable ) tree_max[v] = A[l];
               if( sum_enable ) tree_sum[v] = A[l];
          }else{
               int64_t mid = ( l + r ) / 2;

               _st_build( A, v * 2, l, mid );
               _st_build( A, v * 2 + 1, mid + 1, r );
               if( gcd_enable ) tree_gcd[v] = gcd_func( tree_gcd[v * 2], tree_gcd[v * 2 + 1] );
               if( lca_enable ) tree_lca[v] = lca_func( tree_lca[v * 2], tree_lca[v * 2 + 1] );
               if( min_enable ) tree_min[v] = min_func( tree_min[v * 2], tree_min[v * 2 + 1] );
               if( max_enable ) tree_max[v] = max_func( tree_max[v * 2], tree_max[v * 2 + 1] );
               if( sum_enable ) tree_sum[v] = sum_func( tree_sum[v * 2], tree_sum[v * 2 + 1] );
          }

     }


     void build( vector < T > &A ){
          if( gcd_enable ) tree_gcd.resize( A.size( ) * 4 );
          if( lca_enable ) tree_lca.resize( A.size( ) * 4 );
          if( min_enable ) tree_min.resize( A.size( ) * 4 );
          if( max_enable ) tree_max.resize( A.size( ) * 4 );
          if( sum_enable ) tree_sum.resize( A.size( ) * 4 );

          _st_build( A, 1, 0, A.size( ) - 1 );
     }


     T _get_gcd_func( int64_t v, int64_t l, int64_t r, int64_t cl, int64_t cr ){
          if( cl > cr ) return default_value;
          if( l == cl && r == cr ) return tree_gcd[v];

          int64_t mid = ( l + r ) / 2;
          int64_t nr = mid, nl = mid + 1;
          if( cr < nr ) nr = cr;
          if( cl > nl ) nl = cl;

          return gcd_func(
               _get_gcd_func( v * 2, l, mid, cl, nr ),
               _get_gcd_func( v * 2 + 1, mid + 1, r, nl, cr )
          );
     }
     T getgcd( int64_t l, int64_t r ){return _get_gcd_func( 1, 0, ( tree_sz( ) / 4 ) - 1, l, r );}



     T _get_lca_func( int64_t v, int64_t l, int64_t r, int64_t cl, int64_t cr ){
          if( cl > cr ) return default_value;
          if( l == cl && r == cr ) return tree_lca[v];

          int64_t mid = ( l + r ) / 2;
          int64_t nr = mid, nl = mid + 1;
          if( cr < nr ) nr = cr;
          if( cl > nl ) nl = cl;

          return lca_func(
               _get_lca_func( v * 2, l, mid, cl, nr ),
               _get_lca_func( v * 2 + 1, mid + 1, r, nl, cr )
          );
     }
     T getlca( int64_t l, int64_t r ){return _get_lca_func( 1, 0, ( tree_sz( ) / 4 ) - 1, l, r );}



     T _get_min_func( int64_t v, int64_t l, int64_t r, int64_t cl, int64_t cr ){
          if( cl > cr ) return maximal_value;
          if( l == cl && r == cr ) return tree_min[v];

          int64_t mid = ( l + r ) / 2;
          int64_t nr = mid, nl = mid + 1;
          if( cr < nr ) nr = cr;
          if( cl > nl ) nl = cl;

          return min_func(
               _get_min_func( v * 2, l, mid, cl, nr ),
               _get_min_func( v * 2 + 1, mid + 1, r, nl, cr )
          );
     }
     T getmin( int64_t l, int64_t r ){return _get_min_func( 1, 0, ( tree_sz( ) / 4 ) - 1, l, r );}



     T _get_max_func( int64_t v, int64_t l, int64_t r, int64_t cl, int64_t cr ){
          if( cl > cr ) return minimal_value;
          if( l == cl && r == cr ) return tree_max[v];

          int64_t mid = ( l + r ) / 2;
          int64_t nr = mid, nl = mid + 1;
          if( cr < nr ) nr = cr;
          if( cl > nl ) nl = cl;

          return max_func(
               _get_max_func( v * 2, l, mid, cl, nr ),
               _get_max_func( v * 2 + 1, mid + 1, r, nl, cr )
          );
     }
     T getmax( int64_t l, int64_t r ){return _get_max_func( 1, 0, ( tree_sz( ) / 4 ) - 1, l, r );}



     T _get_sum_func( int64_t v, int64_t l, int64_t r, int64_t cl, int64_t cr ){
          if( cl > cr ) return default_value;
          if( l == cl && r == cr ) return tree_sum[v];

          int64_t mid = ( l + r ) / 2;
          int64_t nr = mid, nl = mid + 1;
          if( cr < nr ) nr = cr;
          if( cl > nl ) nl = cl;

          return sum_func(
               _get_sum_func( v * 2, l, mid, cl, nr ),
               _get_sum_func( v * 2 + 1, mid + 1, r, nl, cr )
          );
     }
     T getsum( int64_t l, int64_t r ){return _get_sum_func( 1, 0, ( tree_sz( ) / 4 ) - 1, l, r );}


     void _update_element( int64_t v, int64_t l, int64_t r, int64_t pos, int64_t x ){
          if( l == r ){
               if( gcd_enable ) tree_gcd[v] = x;
               if( lca_enable ) tree_lca[v] = x;
               if( min_enable ) tree_min[v] = x;
               if( max_enable ) tree_max[v] = x;
               if( sum_enable ) tree_sum[v] = x;
          }else{
               int mid = ( l + r ) / 2;

               if( pos <= mid ){
                    _update_element( v * 2, l, mid, pos, x );
               }else{
                    _update_element( v * 2 + 1, mid + 1, r, pos, x );
               }

               if( gcd_enable )
                    tree_gcd[v] = gcd_func( tree_gcd[v * 2], tree_gcd[v * 2 + 1] );
               if( lca_enable )
                    tree_lca[v] = lca_func( tree_lca[v * 2], tree_lca[v * 2 + 1] );
               if( min_enable )
                    tree_min[v] = min_func( tree_min[v * 2], tree_min[v * 2 + 1] );
               if( max_enable )
                    tree_max[v] = max_func( tree_max[v * 2], tree_max[v * 2 + 1] );
               if( sum_enable )
                    tree_sum[v] = sum_func( tree_sum[v * 2], tree_sum[v * 2 + 1] );
          }
     }
     void update_e( int64_t p, int64_t x ){ _update_element( 1, 0, ( tree_sz( ) / 4 ) - 1, p, x ); }


     void _update_segment( int64_t v, int64_t l, int64_t r, int64_t cl, int64_t cr, int64_t x ){
          if( cl > cr ) return;
          //if( l == cl && r == cr )
     }
     void update_s( int64_t l, int64_t r, int64_t x ){ _update_segment( 1, 0, ( tree_sz( ) / 4 ) - 1, l, r, x ); }

};






int32_t main(){

				//freopen("berries.in","r",stdin);
				//freopen("berries.out","w",stdout);
				ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
				ofstream fout("debug");


                    int n;
                    cin >> n;
                    vector < int > A( n );


                    for( int i = 0; i < n; ++i ){
                         cin >> A[i];
                    }


                    st < int, 0, -MAX_MOD, MAX_MOD, 1, 1, 1, 1, 1 > T;
                    T.build( A );


                    int qt = 1;
                    cin >> qt;



                    while( qt-- ){

                         string s;
                         int l, r;
                         cin >> s >> l >> r, l--, --r;

                         if( s == "gcd" ) cout << T.getgcd( l, r ) << '\n';
                         if( s == "lca" ) cout << T.getlca( l, r ) << '\n';
                         if( s == "min" ) cout << T.getmin( l, r ) << '\n';
                         if( s == "max" ) cout << T.getmax( l, r ) << '\n';
                         if( s == "sum" ) cout << T.getsum( l, r ) << '\n';
                         if( s == "upd1el" ) T.update_e( l, r + 1 );
                         if( s == "updseg" ){
                              int x;
                              cin >> x;
                              T.update_s( l, r, x );
                         }
                         cout.flush( );

                    }



return 0;}











///owoo
