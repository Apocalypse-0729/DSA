// Given a necklace consisting of only red (R) and blue (B) stones,
// you need to make the number of red and blue stones equal.
// You can only remove stones from either the left or right end.
// Return the minimum number of removals required to achieve this.

// Example:
// Input: "BBRRBRBRBRBBR"
// Output: 1

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size(), maxLen = 0, prefix = 0;
    unordered_map<int, int> first;
    first[0] = -1; 

    for (int i = 0; i < n; i++){
        prefix += (s[i] == 'R' ? 1 : -1);
        if (first.find(prefix) == first.end())
            first[prefix] = i; 
        else {
            int len = i - first[prefix];
            if (len > maxLen) maxLen = len;
        }
    }
    
    cout << n - maxLen << "\n";
    return 0;
}
