int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0;
    int right = numbersSize - 1;
    int *array = (int *)malloc(2*sizeof(int));
    *returnSize = 2;
    while(left <= right){
        if(numbers[left] + numbers[right] == target){
            break;
        }
        else if(numbers[left] + numbers[right] < target){
            left += 1;
        }
        else
            right -= 1;
    }
    array[0] = left + 1;
    array[1] = right + 1;
    return array;
}
