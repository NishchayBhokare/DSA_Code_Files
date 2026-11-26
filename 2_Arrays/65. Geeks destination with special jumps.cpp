//GFG - Hard problem. optimised approach is very hard so understand at least normal approach.
//brute force approach. TC-O((r-l)*d/(a-b)). SC-O(1)
class Solution {
public:
    int minTime(int a, int b, int d, int l, int r) {

        long long totalTime = 0;
        long long mod = 1e9 + 7;

        for(int j = l; j <= r; j++) {

            long long pos = j, t = 1;
            int last = 0;

            while(pos < d) {

                if(last == 0) {

                    long long req = a;

                    if(pos + a > d)
                        req = d - pos;

                    pos += req;
                    t += req;
                    last = 1;
                }
                else {
                    pos -= b;
                    t += b;
                    last = 0;
                }
            }

            totalTime = (totalTime + t) % mod;
        }

        return totalTime;
    }
};