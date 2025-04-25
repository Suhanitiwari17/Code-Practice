class Solution {
    public boolean rotateString(String s, String goal) {
        if (s.length() != goal.length()) return false;
        String rotated = s + s;
        return rotated.contains(goal);
    }
}