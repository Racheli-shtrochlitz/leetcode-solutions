int triangularSum(int* nums, int numsSize) {
    if(numsSize==1) return nums[0];
    int *newNums = malloc((numsSize-1 )* sizeof(int));
     if (newNums == NULL) {
        printf("שגיאה בהקצאה\n");
        exit(1); 
    }
    for(int i=0; i<numsSize-1; i++){
        newNums[i]=(nums[i]+nums[i+1])% 10;
    }
    int result = triangularSum(newNums, numsSize - 1);
    free(newNums); 
    return result;
}