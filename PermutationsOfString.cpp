/**
 * Given a string S. The task is to print all permutations of a given string. 
 * Note : All Permutations must be lexicographically sorted.
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void permute(string str, string out) {
    // When size of str becomes 0, out has a 
    // permutation (length of out is n) 
    if (str.size() == 0) 
    { 
        cout << out << " "; 
        return; 
    } 
  
    // One be one move all characters at 
    // the beginning of out (or result) 
    for (int i = 0; i < str.size(); i++) 
    { 
        char ch = str[i]; 

		// Rest of the string after excluding 
		// the ith character 
		string ros = str.substr(0, i) + 
					str.substr(i + 1); 

		// Recurvise call 
		permute(ros, out + ch);
        
    } 
}
int main() {
	//code
	int t;
	cin>>t;
		while(t-- > 0) {
		    string s;
		    cin>>s;
		    sort(s.begin(), s.end());
		    permute(s, "");
		    
		    cout<<endl;
		}
	return 0;
}
