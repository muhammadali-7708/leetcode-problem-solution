class Solution {
public:
    void insertNumber(vector<int> &arr, int newNumber) {
        arr.push_back(newNumber);
    }

    bool findNumber(vector<int> &arr, int target) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == target) {
                return true;
            }
        }
        return false;
    }

    bool isHappy(int n) {
        int sum = 0;
        vector<int> arr;
        insertNumber(arr, n); // Fixed here

        do {
            sum = 0;
            int temp = n;
            do {
                sum = sum + pow((temp % 10), 2);
                temp = temp / 10;
            } while (temp != 0);

            if (sum == 1)
                return true;
            n = sum;
            if (findNumber(arr, n))
                return false;

            insertNumber(arr, n);
        } while (sum != 1);
        return false;
    }
};