#include <stdio.h>
#include<limits.h>

/*
* Function recursively only finds valid minimum apex elements, merges and checks the two middle elements, and checks corner cases only at the highest level.
*/

int findApex(int A[], int low, int high, int n) 
{
	printf("low,high: %d,%d \n", low,high);
	int smlstapex = -1;
	if(high-low > 1)
	{
		/*
		* DIVIDE IF SIZE IS LARGER THAN THREE
		*/
		int mid = (low + high) / 2;
		int lAIdx = findApex(A, low, mid, n);
		int rAIdx = findApex(A, mid+1, high, n);
		int check = mid;
		printf("low, mid, high, lAIdx, rAidx: %d, %d, %d, %d, %d \n", low,mid,high,lAIdx,rAIdx );
		/*
		* MERGE AND CHECK MID BOUNDARY ELEMENTS
		*/
		
		// check if mid is an apex candidate
		if(A[check] >= A[check-1] && A[check] >= A[check+1])
		{
			if(lAIdx == -1 || A[lAIdx] > A[check])
			{
				lAIdx = check;
			}
		}
		printf("low, mid, high, lAIdx, rAidx: %d, %d, %d, %d, %d \n", low,mid,high,lAIdx,rAIdx );
		// check if mid+1 is an apex candidate
		check = mid + 1;
		if(high > mid+1 && A[check] >= A[check-1] && A[check] >= A[check+1])
		{
			if(rAIdx == -1 || A[rAIdx] > A[check])
			{
				rAIdx = check;
			}
		}
		if(lAIdx == -1)
			smlstapex = rAIdx;
		else if(rAIdx == -1)
			smlstapex = lAIdx;
		else
		{
			if(A[lAIdx] < A[rAIdx])
				smlstapex = lAIdx;
			else
				smlstapex = rAIdx;
		}
		printf("low, mid, high, lAIdx, rAidx: %d, %d, %d, %d, %d \n", low,mid,high,lAIdx,rAIdx );

	}
	/*
	* CHECK CORNER CASES
	*/
	if(high-low+1 == n) 
	{
		// check corners
		if(A[low] >= A[low+1])
		{
			if(smlstapex == -1 || A[low] < A[smlstapex])
				smlstapex = low;
		}
		if(A[high] >= A[high-1])
		{
			if(smlstapex == -1 || A[high] < A[smlstapex])
				smlstapex = high;
		}
	}
	printf("smlst: %d \n",smlstapex);
	return smlstapex;
	
}
	
	
int main(){
    //int A[] = {3, 6, 10, 4, 7, 8, 10, 11, 8, 44, 33, 2};
		int A[] = {7,19,6,4,8,2,5,10 };
	int n = sizeof(A) / sizeof(A[0]);
	int idx = findApex(A, 0, n-1 ,n);
    printf("Smallest Apex element  is %d at index %d \n", A[idx],idx);
    return 0;
}
