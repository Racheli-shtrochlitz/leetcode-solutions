int triangularSum(int* nums, int numsSize) {
    for (int step = numsSize; step > 1; step--) {
        for (int i = 0; i < step - 1; i++) {
            nums[i] = (nums[i] + nums[i + 1]) % 10;
        }
    }
    return nums[0];
}