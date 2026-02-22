#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        
        for (int i = 0; i < size; i++) {
            // check if current plot is empty
            if (flowerbed[i] == 0) {
                // check if left and right are empty (or at boundaries)
                bool emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRight = (i == size - 1) || (flowerbed[i + 1] == 0);
                
                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1; // plant it
                    count++;
                    
                    if (count >= n) return true;
                }
            }
        }
        return count >= n;
    }
};