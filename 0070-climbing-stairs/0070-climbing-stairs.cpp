class Solution {
public:
    int climbStairs(int n) {
    int steps = 0;
    if(n == 1)
        return 1;
    if (n == 2)
        return 2;
    else if (n == 3)
        return 3;
    else {
        int arr[2] = { 2,3 };
        n = n - arr[1];
        while (n != 0) {
            steps = arr[0] + arr[1];
            arr[0] = arr[1];
            arr[1] = steps;
            n--;
        }
    }
    return steps;
}
};