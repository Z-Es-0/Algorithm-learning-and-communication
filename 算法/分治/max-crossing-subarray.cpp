/*
 * @Author: Z-Es-0 zes18642300628@qq.com
 * @Date: 2024-09-26 19:13:16
 * @LastEditors: Z-Es-0 zes18642300628@qq.com
 * @LastEditTime: 2024-09-26 20:44:01
 * @FilePath: \Algorithm-learning-and-communication\算法\分治\max-crossing-subarray.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int find_max_with_mid(vector<int>& arr, int l, int r, int mid) {//以mid为中心的最大子数组
    int ans1 = INT_MIN, ans2 = INT_MIN, qz = 0;

 
    for (int i = mid; i <= r; i++) {
        qz += arr[i];
        ans1 = max(ans1, qz);
    }

    qz = 0;


    for (int i = mid - 1; i >= l; i--) {
        qz += arr[i];
        ans2 = max(ans2, qz);
    }

    return ans1 + ans2;
}

int solve(vector<int>& arr, int l, int r) { // 分治找最大子数组
    if (r == l) {
        return arr[l];
    }

    if (r < l) {
        return INT_MIN;
    }

    int mid = (l + r) / 2;

   
    int a = solve(arr, l, mid);
    int b = solve(arr, mid + 1, r);
    
   
    int c = find_max_with_mid(arr, l, r, mid);

   
    return max({a, b, c});
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << solve(arr, 0, n - 1) << endl;

    return 0;
}
