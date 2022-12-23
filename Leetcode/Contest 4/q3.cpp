#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(int mid, vector<int> v , int K)
    {
        int ct = 0;
        int s = 0;
        for (int i = 0; i < v.size(); i++)
        {

            if (v[i] > mid)
                return false;

            s += v[i];

            if (s > mid)
            {
                ct++;
                s = v[i];
            }
        }
        ct++;

        if (ct <= K)
            return true;
        return false;
    }
    int distributeCookies(vector<int> &cookies, int k)
    {
        auto mx = max_element(cookies.begin(),cookies.end());
        int low = *mx;
        int high = 0;

        for (int i = 0; i < cookies.size(); i++)
        {
            high += cookies[i]; 
        }

        int answer = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (check(mid, cookies, k))
            {
                answer = mid; 
                high = mid - 1;
            }
            else
            {
                low= mid + 1;
            }
        }

        return answer;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}

// bool check(int mid, int array[], int n, int K)
// {
//     int count = 0;
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {

//         // If individual element is greater
//         // maximum possible sum
//         if (array[i] > mid)
//             return false;

//         // Increase sum of current sub - array
//         sum += array[i];

//         // If the sum is greater than
//         // mid increase count
//         if (sum > mid)
//         {
//             count++;
//             sum = array[i];
//         }
//     }
//     count++;

//     // Check condition
//     if (count <= K)
//         return true;
//     return false;
// }

// Function to find maximum subarray sum
// which is minimum
// int solve(int array[], int n, int K)
// {
// int *max = max_element(array, array + n);
// int start = *max; //Max subarray sum, considering subarray of length 1
// int end = 0;

// for (int i = 0; i < n; i++)
// {
//     end += array[i]; //Max subarray sum, considering subarray of length n
// }

// // Answer stores possible
// // maximum sub array sum
// int answer = 0;
// while (start <= end)
// {
//     int mid = (start + end) / 2;

//     // If mid is possible solution
//     // Put answer = mid;
//     if (check(mid, array, n, K))
//     {
//         answer = mid;
//         end = mid - 1;
//     }
//     else
//     {
//         start = mid + 1;
//     }
// }

// return answer;
// }