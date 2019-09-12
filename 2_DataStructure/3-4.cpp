#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	
    // initialization, precalculation 
    vector<long long> h1(s.size()+1);
    vector<long long> h2(s.size()+1);

    long long m1 = 1000000007;
    long long m2 = 1000000009;
    long long x = 10;

    h1[0] = 0;
    h2[0] = 0;

    for (int i=1; i<=s.size(); i++){
        h1[i] = ((x*h1[i-1] % m1 + s[i-1] % m1 + m1) % m1);
        //cout << h1[i] << " " ;
        h2[i] = ((x*h2[i-1] % m2 + s[i-1] % m2 + m2) % m2);
    }
    //cout << endl;

	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;

        long long ha1 = (h1[a+l] % m1 - (long long)(pow(x,l))*h1[a] % m1 + m1) % m1;
        long long ha2 = (h2[a+l] % m2 - (long long)(pow(x,l))*h2[a] % m2 + m2) % m2;
        long long hb1 = (h1[b+l] % m1 - (long long)(pow(x,l))*h1[b] % m1 + m1) % m1;
        long long hb2 = (h2[b+l] % m2 - (long long)(pow(x,l))*h2[b] % m2 + m2) % m2;

        //cout << ha1 << endl;
        //cout << hb1 << endl;

		//cout << ((ha1==hb1)&&(ha2==hb2) ? "Yes\n" : "No\n");
        
        
        if ((ha1==hb1)&&(ha2==hb2)){
            if (s.substr(a, l) == s.substr(b, l)){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else{
                cout << "No" << endl;
        }
	}

    return 0;
}
