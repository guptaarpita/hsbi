public class Solution {
    public int MissingMultiple(int[] nums, int k) {
        HashSet<int> set = new HashSet<int>(nums);

        int multiple = k;

        while (set.Contains(multiple)) {
            multiple += k;
        }

        return multiple;
    }
}