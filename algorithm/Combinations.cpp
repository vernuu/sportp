///An empty file)
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ld long double
#define pb push_back



bool next_combination( vector < int > &A, int n ){
     int k = A.size();

     for( int i = k - 1; i >= 0; i-- ){
          if( A[i] < n - k + i + 1 ){
               A[i]++;
               for( int j = i + 1; j < k; ++j ){
                    A[j] = A[j - 1] + 1;
               }

               return 1;
          }
     }

     return 0;
}



int32_t main(){

               cout.tie(0); cin.tie(0); ios_base::sync_with_stdio(0);



               cout << "Enter n & k\n>> ";
               cout.flush();
               int n, k; cin >> n >> k;
               vector < int > A(k);
               for( int i = 0; i < k; i++ ){
                    A[i] = i + 1;
               }




               do{
                    for( int i = 0; i < k; i++ ){
                         cout << A[i] << ' ';
                    }
                    cout << '\n';
                    cout.flush();

               }while( next_combination( A, n ) );






     return 0;
}
