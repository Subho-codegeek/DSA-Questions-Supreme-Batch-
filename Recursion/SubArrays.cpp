#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> &arr, vector<string> &ans, int index, int n, string output)
{
    // base case
    if (index >= n)
    {
        ans.push_back(output);
        cout << output << endl;
        return;
    }

    // exclude
    solve(arr, ans, index + 1, n, output);

    // include
    output.push_back(arr[index] + '0');
    solve(arr, ans, index + 1, n, output);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<string> ans;
    string output = "";
    int index = 0;
    int n = arr.size();
    solve(arr, ans, index, n, output);

    // sort(ans.begin(),ans.end());
    // for(int i=0;i<ans.size();i++){
    //   if(ans[i].size()==0){
    //     continue;
    //   }else{
    //     cout<<ans[i]<<" , ";
    //   }
    // }
    return 0;
}