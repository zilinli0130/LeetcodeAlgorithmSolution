int** dfs(int *nums,int numsSize,int* returnSize,int** returnColumnSizes,int *visited,int *temp,int idx,int **res) {
    
    if (idx == numsSize) {
        res[*returnSize] = malloc(sizeof(int)*numsSize);
        memcpy(res[*returnSize],temp,sizeof(int)*numsSize);
        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return 0;
    }
    
    for (int i = 0;i < numsSize;i++) {
        if (!visited[i]) {
            visited[i] = 1;
            temp[idx] = nums[i];
            dfs(nums,numsSize,returnSize,returnColumnSizes,visited,temp,idx + 1,res);
            temp[idx] = 0;
            visited[i] = 0;
        }
    }
    return res;
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    int *visited = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize;i++) {
        visited[i] = 0;
    }
    int *temp = malloc(sizeof(int)*numsSize);
    int **res = malloc(sizeof(int *)*10002);
    
    
    *returnSize = 0;
    (*returnColumnSizes) = malloc(sizeof(int)*10002);
    dfs(nums, numsSize, returnSize, returnColumnSizes, visited, temp, 0, res);
    return res;
}
