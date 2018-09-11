/**
 * 位运算：异或操作
 */
int missingNumber(int* nums, int numsSize) {
    int xor1 = 0, xor2=0,i;
    for(i=0;i<numsSize;i++)
        xor1 ^= nums[i];
    for(i=1;i<=numsSize;i++)
        xor2 ^= i;
    
    return xor1^xor2;
}
