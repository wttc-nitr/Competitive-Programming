#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main(void){
     ios::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
/*
// write logic here 
*/	int n,m,c;

	while (cin >> n >> m >> c){
  		if (!n && !m && !c)
  			return 0;

  		bool parity = (n+m) & 1 ? 0 : 1; // 8 + 8 is already even, so only check for n+m
  		bool p8 = 0;
  		if (parity){
  			if (c)
  				p8 = 1;
  		}
  		else {
  			if (!c)
  				p8 = 1;
  		}
  		//cout << p8 << '\n';
  		ll ans = 0;
  		ll r;

  		if (p8){
  			r = 1;
  			r += (m-8)/2;
  		}
  		else {
  			r = 0;
  			r += (m-8 + 1)/2; 
  		}
  		//cout << r << '\n';
  		
  		if (n & 1){
  			if (p8){
  				ans += (n-8+1)/2 * r;
  				ans += (n-8+1)/2 * (m & 1 ? r : (r-1));
  			}
  			else {
  				ans += (n-8+1)/2  * r;
  				ans += (n-8+1)/2 * (m & 1 ? r : (r+1));
  			}
  		}
  		else {
  			if (p8){
  				ans += ((n-8)/2 + 1) * r;
  				ans += (n-8)/2 * (m & 1 ? r : (r-1));
  			}
  			else {
  				ans += ((n-8)/2 +1) * r;
  				ans += (n-8)/2 * (m & 1 ? r : (r+1));
  			}
  		}

  		cout << ans << '\n';
	}
 
return 0;
}