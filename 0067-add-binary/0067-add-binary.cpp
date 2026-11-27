class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            s.insert(0, 1, '0' + (sum % 2));
            carry = sum / 2;
        }
        return s;
    }
};