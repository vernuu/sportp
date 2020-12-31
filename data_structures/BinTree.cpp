#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC optimization ("O3")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("")
//#pragma GCC target("sse,sse2,sse3,sse4,mmx,avx,avx2")
using namespace std;


bool broken = 0;
clock_t start;
template < typename T, bool dynamic_memory_alloc = 1 >
struct BinTree{



     struct Node_Type1{
          T value;
          //Node_Type1 *Left = NULL, *Right = NULL;
          int32_t Left = -1, Right = -1;
          /*
          Node_Type1( T a = default_value ){
               value = a;
          }
          /**/
          /*Not tested( keep default_value unused )*/
          Node_Type1( ){}
          Node_Type1( T a ){
               value = a;
          }
          /**/
     };



     Node_Type1 *Tree;
     int32_t used = 0;
     double realloc_percent = 0;
     int32_t size_of_tree = 0;


     void Resize( int32_t sz = 0 ){///experemental
          size_of_tree = sz;
          Tree = ( Node_Type1 * ) malloc( sz * sizeof( Node_Type1 ) );
     }


     BinTree( int32_t const_size_of_tree = 0, double const_realloc_percent = 0.75 ){
          realloc_percent = const_realloc_percent;
          size_of_tree = const_size_of_tree;
          //Tree = ( Node_Type1 * ) calloc( size_of_tree, sizeof( Node_Type1 ) );
          Tree = ( Node_Type1 * ) malloc( size_of_tree * sizeof( Node_Type1 ) );
     }


     ~BinTree( ){
          free( Tree );
     }


     void CapacityCheck( ){
          //if( size_of_tree == 0 ) size_of_tree = 1;
          if( dynamic_memory_alloc == 1 ){
               if( ( double ) size_of_tree * realloc_percent - used < 0 ){
                    size_of_tree = size_of_tree + max( size_of_tree, 1 );
                    Tree = ( Node_Type1 * ) realloc( Tree, size_of_tree * sizeof( Node_Type1 ) );
                    //Tree = ( Node_Type1 * ) calloc( Tree, size_of_tree * sizeof( Node_Type1 ) );
               }
          }else{
               if( used == size_of_tree ){
                    used --;
                    cerr << "Memory limit reached ( last element replaced )\n";
               }
          }
     }


     void Add( T x ){
          used ++;
          CapacityCheck( );
          Tree[used - 1].value = x;
          Tree[used - 1].Left = -1;
          Tree[used - 1].Right = -1;


          if( used != 1 ){
               int32_t p = 0;
               while( ( Tree[p].Left + Tree[p].Right != -2 ) ){
                    if( x == Tree[p].value ) return;
                    //cerr << p << '\n';
                    if( x < Tree[p].value ){
                         if( Tree[p].Left == -1 ){
                              Tree[p].Left = used - 1;
                              return;
                         }
                         p = Tree[p].Left;
                    }
                    if( x > Tree[p].value ){
                         if( Tree[p].Right == -1 ){
                              Tree[p].Right = used - 1;
                              return;
                         }
                         p = Tree[p].Right;
                    }
               }

               if( x < Tree[p].value ){
                    Tree[p].Left = used - 1;
               }
               if( x > Tree[p].value ){
                    Tree[p].Right = used - 1;
               }
          }
     }


     bool Find_old_v0_1( T x ){
          if( used == 0 ) return 0;
          int32_t p = 0;
          while( ( Tree[p].value != x ) ){
               if( Tree[p].value == x ) return 1;
               if( x < Tree[p].value ){
                    p = Tree[p].Left;
               }
               if( x > Tree[p].value ){
                    p = Tree[p].Right;
               }
               if( p == -1 ) return 0;
               if( Tree[p].value == x ) return 1;
               if( ( Tree[p].Left + Tree[p].Right == -2 ) ) return 0;
          }

          if( Tree[p].value == x ) return 1; else return 0;
     }


     bool Find( T x ){
          if( used == 0 ) return 0;
          int32_t p = 0;
          while( 1 ){
               if( x == Tree[p].value ) return 1; else
               //cerr << p << '\n';
               if( x < Tree[p].value ){
                    /*
                    if( Tree[p].Left == -1 ){
                         return 0;
                    }
                    /**/
                    p = Tree[p].Left;
               }else
               if( x > Tree[p].value ){
                    /*
                    if( Tree[p].Right == -1 ){
                         return 0;
                    }
                    /**/
                    p = Tree[p].Right;
               }
               if( p == -1 ) return 0;
          }

          //if( Tree[p].Left != -1 ) if( Tree[Tree[p].Left].value == x ) return 1;
          //if( Tree[p].Right != -1 ) if( Tree[Tree[p].Right].value == x ) return 1;
          return 0;

     }


     void Diagnostic_v1( int n = 0 ){
          if( n == 0 ) n = max( used, n );
          cerr << "---Diagnostic---\n";
          for( int i = 0; i < min( size_of_tree, n ); ++ i ){
               cerr << i + 1 << "->  " << Tree[i].value << "   " << Tree[i].Left + 1 << "   " << Tree[i].Right + 1 << '\n';
          }
          cerr << "---Diagnostic---\n";
     }


};
BinTree < int32_t > V;



void catchError( ){
     while( !broken ){
          ifstream checker1132A;
          checker1132A.open( "delta1132A" );
          if( !checker1132A.is_open( ) ){
               cerr << "Locked(or Killed)\n";
               checker1132A.close( );
               V.Diagnostic_v1( );
               cerr << (long double) ( clock( ) - start ) / CLOCKS_PER_SEC << '\n';
               exit( 2 );
          }
          checker1132A.close( );
          cerr << "No issues\n";
          system( "sleep 2" );
     }
     cerr << "Error hAb catched\n";
     V.Diagnostic_v1( );
     cerr << (long double) ( clock( ) - start ) / CLOCKS_PER_SEC << '\n';
     exit( 1 );
}



int32_t main( ){



          //ios_base::sync_with_stdio( 0 );
          //cin.tie( 0 ); cout.tie( 0 );


          /*_*/
          start = clock( );
          ofstream temp1132A( "delta1132A" );
          temp1132A << "KEY\n";
          temp1132A.close( );
          srand( time( 0 ) );
          //V.Resize( 9000000 );
          thread error_catcher( catchError );
          unordered_set < int32_t > S;
          //ifstream fin( "input.txt" );
          int ans1 = 0, ans2 = 0, n = 1000000;
          while( n -- ){
               bool f = 0, d = 0;
               int x = (rand( ) + 1) % 10000000;
               //cerr << x << '\n';
               //int x = 1;
               //fin >> x;
               /**/
               if( V.Find( x ) == 0 ){
                    //cerr << "Found\n";
                    ans1 ++;
                    f = 1;
                    V.Add( x );
                    //cerr << "Added\n";
               }
               /*
               if( S.count( x ) == 0 ){
                    ans2 ++;
                    d = 1;
                    S.insert( x );
               }
               /**/
               //cerr << n << '\n';
          }


          cout << ans1 << ' ' << ans2 << '\n';


     error_catcher.detach( );
     cerr << (long double) ( clock( ) - start ) / CLOCKS_PER_SEC << '\n';
     return 0;
}





























////owoo
