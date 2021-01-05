#include <bits/stdc++.h>
using namespace std;
//#define int int64_t
#define pb push_back
#define F first
#define S second
mt19937 gen( chrono::high_resolution_clock::now( ).time_since_epoch( ).count( ) );



struct Hash{

     uint64_t *H, *D, allocated_memory = 0, used_memory = 0, memory_border = 0;
     double realloc_trigger_percent = 0, realloc_multiplier = 0;
     bool react_to_issues = 0;
     uint64_t P = 239017;




     void Resize( ){
          H = ( uint64_t* ) realloc( H, ( allocated_memory + 2 ) * sizeof( uint64_t ) );
          D = ( uint64_t* ) realloc( D, ( allocated_memory + 2 ) * sizeof( uint64_t ) );
     }


     void CapacityCheck( ){
          if( realloc_trigger_percent <= 0 || realloc_multiplier == 0 ) return;
          if( ( double ) allocated_memory * realloc_trigger_percent - used_memory < 0 ){
               if( allocated_memory < used_memory ) allocated_memory = used_memory;
               allocated_memory = uint64_t( double( allocated_memory * realloc_multiplier ) );
               if( memory_border != 0 ){
                    allocated_memory = min( allocated_memory, memory_border - 2 );
               }
               Resize( );
          }
          if( ( double ) allocated_memory * realloc_trigger_percent - used_memory < 0 ){
               cerr << "Memory issue!\n";
               cerr << " Available : \t" << allocated_memory << '\n';
               cerr << " Used : \t" << used_memory << '\n';
               //cerr << realloc_trigger_percent << ' ' << realloc_multiplier << '\n';
               cerr << ( double ) allocated_memory * realloc_trigger_percent - used_memory << '\n';
               if( react_to_issues == 1 ) exit( 0 );
          }
     }


     void Build( string &s ){
          used_memory = s.size( );
          CapacityCheck( );
          H[0] = 0, D[0] = 1;

          for( int i = 0; i < used_memory; ++ i ){
               H[i + 1] = H[i] * P + s[i];
               D[i + 1] = D[i] * P;
          }
          D[used_memory] = D[used_memory - 1] * P;
     }


     void Clear( ){
          free( H );
     }


     Hash( ){}
     ///[rp]Default realloc value = 0.75[75%]( 0.0 or less to use constant sz )
     ///[rm]Default realloc multiplier = 2.0[200%][sz_new->2*sz]( 1.0 to use constant sz )
     ///[sz]Default alloc value = 1
     ///[sl]Memory limiter = 0[INF]( will limit available memory, 0 = INF, sz=min(sz,sl) )
     ///[ri]React to issues = 1 -> exit when issue found, = 0 -> try to continue
     Hash( string &s, uint64_t sz = 1, double rp = 0.75, double rm = 2, uint64_t sl = 0, bool ri = 0 ){
          realloc_trigger_percent = rp;
          realloc_multiplier = rm;
          allocated_memory = sz;
          //Resize( );
          H = ( uint64_t* ) malloc( sizeof( uint64_t ) );
          D = ( uint64_t* ) malloc( sizeof( uint64_t ) );
          Build( s );
     }
     ~Hash( ){
          Clear( );
     }


     uint64_t GetHash( int l, int r ){
          return H[r + 1] - H[l] * D[r - l + 1];
     }



};





int32_t main( ){



          //ios_base::sync_with_stdio( 0 );
          //cin.tie( 0 ); cout.tie( 0 );


          /*_*/
          string s;
          cin >> s;
          Hash H( s );
          int qt = 1;
          cin >> qt;


          while( qt -- ){///0-index
               int l, r;
               cin >> l >> r;
               cout << H.GetHash( l, r ) << '\n';
               cout.flush( );
          }

          //V.Diagnostic_v1( );

     return 0;
}





























////owoo
