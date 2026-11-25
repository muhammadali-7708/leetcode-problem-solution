class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() -1;
        int n = s.size()/2;
        while(i < n){
            char a = s[i];
            s[i] = s[j];
            s[j] = a;
            i++; j--;
        }
    }
};