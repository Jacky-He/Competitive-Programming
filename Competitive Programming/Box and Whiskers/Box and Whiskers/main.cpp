#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, num;
deque <int> nums;
deque <int> nums1;
deque <int> nums2;

int main ()
{
    scanf ("%d", &n);
    for (int x = 0; x < n; x++)
    {
        scanf ("%d", &num);
        nums.push_back (num);
    }
    sort (nums.begin(), nums.end());
    int maxi = 0, mini = INF;
    double q1 = 0, q2 = 0, q3 = 0;
    for (int each : nums)
    {
        maxi = max (maxi, each);
        mini = min (mini, each);
    }
    for (int x = 1; x <= int(n/double(2)); x++)
    {
        nums1.push_back(nums [x - 1]);
        nums2.push_back (nums [n - x]);
    }
    
    while (nums.size() > 2)
    {
        nums.pop_front();
        nums.pop_back();
    }
    while (nums1.size() > 2)
    {
        nums1.pop_front();
        nums1.pop_back();
    }
    while (nums2.size() > 2)
    {
        nums2.pop_front();
        nums2.pop_back();
    }
    
    q1 = nums1.size() == 1 ? nums1 [0] : (nums1 [0] + nums1 [1])/double(2);
    q2 = nums.size() == 1 ? nums [0] : (nums [0] + nums [1])/double(2);
    q3 = nums2.size() == 1 ? nums2 [0] : (nums2 [0] + nums2 [1])/double(2);

    printf ("%d %d %f %f %f\n", mini, maxi, q1, q2, q3);
    
    return 0;
}
