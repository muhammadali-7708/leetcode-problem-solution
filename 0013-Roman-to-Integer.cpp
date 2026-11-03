class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        char prev = ' ';
        for(auto val : s){
            switch(val){
                case 'I':
                    ans = ans + 1;
                    break;
                case 'V':
                    if(prev == 'I'){
                        ans = ans + 5 - 2*1;
                    }
                    else ans = ans + 5;
                    break;
                case 'X':
                    if(prev == 'I'){
                        ans = ans + 10 - 2*1;
                    }
                    else ans = ans + 10;
                    break;
                case 'L':
                    if(prev == 'X'){
                        ans = ans + 50 - 2*10;
                    }
                    else ans = ans + 50;
                    break;
                case 'C':
                    if(prev == 'X'){
                        ans = ans + 100 - 2*10;
                    }
                    else ans = ans + 100;
                    break;
                case 'D':
                    if(prev == 'C'){
                        ans = ans + 500 - 2*100;
                    }
                    else ans = ans + 500;
                    break;
                case 'M':
                    if(prev == 'C'){
                        ans = ans + 1000 - 2*100;
                    }
                    else ans = ans + 1000;
                    break;
            }
            prev = val;  
        }
        return ans;
    }
};