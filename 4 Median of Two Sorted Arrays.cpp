// 4 Median of Two Sorted Arrays.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m > n) return findMedianSortedArrays(B, n, A, m);
        
        // imax = m Ϊ����i��ָ��A�����һ��Ԫ��֮���λ��
        // ����A�е�����Ԫ�ض�����λ�������,��ʱi = m
        //     left            right
        // A[0]...A[i-1]  |  
        // B[0]...B[j-1]  |  B[j]...B[n-1]
        int imin = 0, imax = m;
        
        // half = (m + n + 1) >> 1
        // ��Ϊ���������m+n��������ʱȡ��ߵ�������
        // ������ߵ�Ԫ�ظ��������ұߵ�Ԫ�ظ��������1��
        int half = (m + n + 1) >> 1;
        
        bool totalNumberIsOdd = (m + n) & 1;
        int i, j;
        
        // ��m+n��������ʱ��num1������λ��
        // ��m+n����ż��ʱ��num1�������������num2���ұ���С����
        // mid = (num1 + num2) / 2.0
        int num1, num2;
        
        
/*         
         ��������Ϊһ��������������ֱ߽����
         
         1. i == 0, ��ʱ����Ļ�������
             left             right
                        |  A[0]...A[m-1] 
         B[0]...B[j-1]  |  B[j]...B[n-1]
         ��Ȼnum1 = B[j-1]
        
         2. j == 0
             left             right
         A[0]...A[i-1]  |  A[i]...A[m-1] 
                        |  B[0]...B[n-1]
         ��Ȼnum1 = A[i-1]
        
         3. i == m
             left             right
         A[0]...A[m-1]  |   
         B[0]...B[j-1]  |  B[j]...B[n-1]
         ��Ȼnum2 = B[j]
        
         4. j == n
             left             right
         A[0]...A[i-1]  |  A[i]...A[m-1]  
         B[0]...B[n-1]  |  
         ��Ȼnum2 = A[i]
         
         ���ǻ���֤��ÿ��������Ѿ������Ļ��֡�
         ����һ������� i == 0
         ���ڽ��뵽�˷�֧3����ô�϶�û�о�����֧2������A[i(=0)] >= B[j-1]
         �����ұ�����Ԫ�ز�С���������Ԫ��
         ����Ϊ����������ģ����Դ�ʱ�Ѿ������Ļ��֡�
         ͬ���֤2��3��4��
*/   

        while (imin <= imax) {
            i = (imin + imax) >> 1;
            j = half - i;
            if (i > 0 && j < n && A[i-1] > B[j]) {
                imax = i - 1; // ��֧1
            } else if (j > 0 && i < m && A[i] < B[j-1]) {
                imin = i + 1; // ��֧2
            } else { // ��֧3
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

