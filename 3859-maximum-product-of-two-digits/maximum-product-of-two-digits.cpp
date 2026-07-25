class Solution {
public:
    int maxProduct(int n) {

        int prod = 1;
        vector<int> temp;

        while (n > 0) {
            int d = n % 10;
            temp.push_back(d);
            prod = prod * d;
            n = n / 10;
        }

        sort(temp.rbegin(), temp.rend());
        return temp[0] * temp[1];
    }
};