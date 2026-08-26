public class Solution {
    public string ShortestBeautifulSubstring(string s, int k) {
        int n = s.Length;
        int left = 0;
        int ones = 0;
        int minLen = int.MaxValue;
        string answer = "";

        for (int right = 0; right < n; right++) {
            if (s[right] == '1')
                ones++;

            // Shrink while we have at least k ones.
            while (left <= right && ones >= k) {
                if (ones == k) {
                    int len = right - left + 1;
                    string candidate = s.Substring(left, len);

                    if (len < minLen ||
                        (len == minLen && candidate.CompareTo(answer) < 0)) {
                        minLen = len;
                        answer = candidate;
                    }
                }

                if (s[left] == '1')
                    ones--;

                left++;
            }
        }

        return answer;
    }
}