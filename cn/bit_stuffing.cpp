#include <stdio.h>
#include <string.h>

int n;

bool check(int nums[],int k,int ct){
    return ((nums[k] == 1) && (k < n) && (ct < 5));
}

void bitStuffing(int nums[])
{
    int temp[30];
    int i = 0, j = 0, ct = 1;
    for(;i<n;i++)
    {
        if (nums[i] == 1)
        {
            temp[j] = nums[i];

            for (int k = i + 1; check(nums,k,ct); k++)
            {
                temp[++j] = nums[k];
                if (++ct == 5)  temp[++j] = 0;
               
                i = k;
            }
        }
        else temp[j] = nums[i];
        j++;
    }

    printf("The Output bitstring after bit stuffing is\n");
    for (i = 0; i < j; ++i)
        printf("%d", temp[i]);
}

int main()
{
    printf("Enter the size of input bitstring\n");
    scanf("%d", &n);

    int nums[n];
    printf("Enter the input bitstring\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    bitStuffing(nums);
    return 0;
}
