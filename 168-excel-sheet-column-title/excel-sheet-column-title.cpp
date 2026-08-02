class Solution {
public:
    string convertToTitle(int columnNumber) {

        string ans;

        // Keep converting until number becomes 0
        while (columnNumber > 0) {

            // Excel columns are 1-based, so convert to 0-based
            columnNumber--;

            // Get current character
            char ch = 'A' + (columnNumber % 26);

            // Add character
            ans += ch;

            // Move to next position
            columnNumber /= 26;
        }

        // Characters are generated in reverse order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};