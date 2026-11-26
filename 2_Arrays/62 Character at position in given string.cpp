

/// Approach: TC-O(log(pos)) SC-O(1)
class Solution {
public:
    char posInfinite(string &s, int pos) {

        int len = s.length(), step = 0;

        // Calculate the length of the constructed string
        // until it becomes greater than or equal to pos.
        // At step i: new length = 2 * previous length + i.
        while (len < pos) {
            step++;
            len = 2 * len + step;
        }

        // Traverse the construction steps in reverse order
        // to map the required position back to the original string.
        while (step > 0) {

            // Recover the length of the string before this step.
            // len = 2 * prevLen + step.
            int prevLen = (len - step) / 2;

            // Case 1: Position belongs to the previous string.
            // Its position remains unchanged.
            if (pos <= prevLen) {
                // No position mapping required.
            }

            // Case 2: Position belongs to the newly appended '$' section.
            else if (pos <= prevLen + step) {
                return '$';
            }

            // Case 3: Position belongs to the reversed string.
            // Map it back to the corresponding position
            // in the previous string.
            else {
                pos = len - pos + 1;
            }

            // Move to the previous construction step.
            step--;
            len = prevLen;
        }

        // Once all steps are reversed, the position belongs
        // to the original string. Convert 1-based to 0-based indexing.
        return s[pos - 1];
    }
};
