#include "bits/stdc++.h"
using namespace std;

const int sz = 1e6 + 1;
int P[sz];		// array to store palindromes at center index
string z = "";


void manachar(string s){
	//  s = #a#b# or whatever with 2n + 1 size
	int center = 0 , right = 0;
    	for ( int i = 1; i < s.size() - 1; i++) {
        // find the corresponding letter in the palindrome subString
        int iMirror = center - (i - center);
        if(right > i) {
            P[i] = min(right - i, P[iMirror]);
        }
        // expanding around center i
        while (s[i + 1 + P[i]] == s[i - 1 - P[i]]){
            P[i]++;
        }
        // Update center,right in case if the palindrome centered at i expands past r,
        if (i + P[i] > right) {
            center = i;              // next center = i
            right = i + P[i];
        }
    }
}


void LongestPalindrome(string str){
	z += '@';
	for(int i = 0 ; str[i] ; i++){
		z += '#';
		z += str[i];
	}
	z += "#$";
	manachar(z);
}
int main(){
	int x = 0;
	string s;
	s = "acncacn";
	LongestPalindrome(s);
	int pos = - 1 , val = -1;
	for(int i = 1 ; i <= 2 * s.size() +  1; i++){
		if(val < P[i]){
			val = P[i];
			pos = i;
		}
	}
	cout << endl;
	// Array P after Manachar Algo
	cout << "Array P -> \n ";
	for(int i = 1 ; i <= 2 * s.size() +  1; i++){
		cout << P[i] << " ";
	}
	cout << endl;
	vector<string> ans;
	/*for(int i = pos - (val - 1) ; i < pos + val ; i++){
		if(z[i]!= '#')cout << z[i];
	}*/
	for(int i = 1 ; i <= 2 * s.size() + 1 ; i++){
		if(P[i] == val){
			string temp = "";
			for(int j = i - (val - 1) ; j < i + val ; j++){
				if(z[j]!= '#')temp += z[j];
			}
			ans.push_back(temp);
		}
	}
	cout << "Palindromes :\n";
	for(auto i : ans){
		cout << i << endl;	
	}
	return 0;
}
