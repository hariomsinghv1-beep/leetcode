class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end) {
        vector<int> temp;

        int i = start;
        int j = mid + 1;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i++]);
        }

        while (j <= end) {
            temp.push_back(nums[j++]);
        }

        for (int k = 0; k < temp.size(); k++) {
            nums[start + k] = temp[k];
        }
    }

    void mergeSort(vector<int>& nums, int start, int end) {
        // Base condition
        if (start >= end) {
            return;
        }

        int mid = start + (end - start) / 2;

        // Sort left half
        mergeSort(nums, start, mid);

        // Sort right half
        mergeSort(nums, mid + 1, end);

        // Merge both sorted halves
        merge(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};