// 4 Median of Two Sorted Arrays.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m > n) return findMedianSortedArrays(B, n, A, m);
        
        // imax = m 为了让i能指向A中最后一个元素之后的位置
        // 表明A中的所有元素都在中位数的左边,此时i = m
        //     left            right
        // A[0]...A[i-1]  |  
        // B[0]...B[j-1]  |  B[j]...B[n-1]
        int imin = 0, imax = m;
        
        // half = (m + n + 1) >> 1
        // 因为下面代码在m+n等于奇数时取左边的最大的数
        // 所以左边的元素个数等于右边的元素个数（或加1）
        int half = (m + n + 1) >> 1;
        
        bool totalNumberIsOdd = (m + n) & 1;
        int i, j;
        
        // 当m+n等于奇数时，num1就是中位数
        // 当m+n等于偶数时，num1是左边最大的数，num2是右边最小的数
        // mid = (num1 + num2) / 2.0
        int num1, num2;
        
        
/*         
         下面代码分为一种正常情况和四种边界情况
         
         1. i == 0, 此时数组的划分如下
             left             right
                        |  A[0]...A[m-1] 
         B[0]...B[j-1]  |  B[j]...B[n-1]
         显然num1 = B[j-1]
        
         2. j == 0
             left             right
         A[0]...A[i-1]  |  A[i]...A[m-1] 
                        |  B[0]...B[n-1]
         显然num1 = A[i-1]
        
         3. i == m
             left             right
         A[0]...A[m-1]  |   
         B[0]...B[j-1]  |  B[j]...B[n-1]
         显然num2 = B[j]
        
         4. j == n
             left             right
         A[0]...A[i-1]  |  A[i]...A[m-1]  
         B[0]...B[n-1]  |  
         显然num2 = A[i]
         
         但是还需证明每种情况下已经是最后的划分。
         看第一种情况： i == 0
         由于进入到了分支3，那么肯定没有经过分支2，所以A[i(=0)] >= B[j-1]
         符合右边所有元素不小于左边所有元素
         又因为数组是有序的，所以此时已经是最后的划分。
         同理可证2、3、4。
*/   

        while (imin <= imax) {
            i = (imin + imax) >> 1;
            j = half - i;
            if (i > 0 && j < n && A[i-1] > B[j]) {
                imax = i - 1; // 分支1
            } else if (j > 0 && i < m && A[i] < B[j-1]) {
                imin = i + 1; // 分支2
            } else { // 分支3
                if (i == 0) 
                    num1 = B[j-1];
                else if (j == 0)
                    num1 = A[i-1];
                else 
                    num1 = A[i-1] > B[j-1] ? A[i-1] : B[j-1];
                
                if (totalNumberIsOdd)
                    return num1;
                    
                if (i == m)
                    num2 = B[j];
                else if (j == n)
                    num2 = A[i];
                else 
                    num2 = A[i] > B[j] ? B[j] : A[i];
                return (num1 + num2) / 2.0;
            }
            
        }
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
/*	int B[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int A[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	*/
	
	int A[] = {0, 1, 2, 3, 4};
	int B[] = {5, 6, 7, 8, 9, 10, 11};
	cout << solution.findMedianSortedArrays(A, 5, B, 7);
	
	


	return 0;
}

