class Solution {
public:
    void toLower(string& s) {
        for (int a = 0; a < s.length(); a++) {
            if (s[a] >= 'A' && s[a] <= 'Z')
                s[a] = s[a] + 32;
        }
    }
    string revString(const string& ref){
        string temp = ref;
        for (int i = 0, j = ref.length() - 1; i < ref.length(); i++, j--)
            temp[i] = ref[j];
        return temp;
    }
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (!isalnum(s[i])) {
                s.erase(i, 1);
                i--;
            }
        }
        toLower(s);
        string temp = revString(s);
        if (temp == s)
            return true;
        return false;
    }
};