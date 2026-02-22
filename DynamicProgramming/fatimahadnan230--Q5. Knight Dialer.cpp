#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) return 10;
        
        long long mod = 1e9 + 7;
        // neighbors[i] represents the digits a knight can reach from digit i
        vector<vector<int>> neighbors = {
            {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0},
            {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}
        };
        
        // current_ways[i] is the number of ways to end on digit i
        vector<long long> current_ways(10, 1);
        
        for (int step = 1; step < n; step++) {
            vector<long long> next_ways(10, 0);
            for (int i = 0; i < 10; i++) {
                for (int neighbor : neighbors[i]) {
                    next_ways[neighbor] = (next_ways[neighbor] + current_ways[i]) % mod;
                }
            }
            current_ways = next_ways;
        }
        
        long long total = 0;
        for (long long ways : current_ways) {
            total = (total + ways) % mod;
        }
        
        return (int)total;
    }
};