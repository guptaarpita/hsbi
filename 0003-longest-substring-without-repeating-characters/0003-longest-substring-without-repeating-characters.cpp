class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> charIndex;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];

            // If character is already in map and inside current window
            if (charIndex.find(currentChar) != charIndex.end() && charIndex[currentChar] >= left) {
                left = charIndex[currentChar] + 1;
            }

            charIndex[currentChar] = right;  // Update character index
            maxLength = std::max(maxLength, right - left + 1);  // Update max length
        }

        return maxLength;
    }
};

