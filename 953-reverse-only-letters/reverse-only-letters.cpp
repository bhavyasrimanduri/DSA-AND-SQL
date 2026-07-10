class Solution {
public:
    string reverseOnlyLetters(string s) {
         int j = 0;
        int i = s.size() - 1;

        while (j < i) {
            if (!isalpha(s[j])) {
                j++;
            }
            else if (!isalpha(s[i])) {
                i--;
            }
            else {
                swap(s[j], s[i]);
                j++;
                i--;
            }
        }

        return s;
    }
};