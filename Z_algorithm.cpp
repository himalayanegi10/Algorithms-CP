#include "bits/stdc++.h"
using namespace std;

int* ZAlgorithm(string str){
	int left = 0 , right = 0;
	int len = str.size();
	int *Z = new int[len];
	for(int i = 0 ; i < len ; i++){
		if(i > right){
			left = right = i;
			while(i < len and str[right] == str[right - left])right++;
			Z[i] = right - left;
			right--;
		}
		else{
			int j = i - left;
			if(Z[j]+i <= right){
				Z[i] = Z[j];
			}
			else{
				left = i;
				while(i < len and str[right] == str[right - left])right++;
				Z[i] = right - left;
				right--;
			}
		}
	}
	return Z;
}


int* buildZ(string pattern , string text){
	string str = pattern + "$" + text;
	int *Z = ZAlgorithm(str);
	return Z;
}

int main(){
	string pattern = "abc";
	string text = "xabcabzabc";
	int *Z = buildZ(pattern , text);
	Z[0] = -1;
	cout << "Z array is :: ";
	int len = pattern.size() + text.size() + 1 ;
	for(int i = 0 ; i < len ; i++)cout << Z[i] << " ";
	cout << "\n";
	return 0;
}
