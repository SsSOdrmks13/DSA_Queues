#include<iostream>
#include<deque>
#include<vector>

using namespace std;

vector<int> findAns(int arr[], int n, int k){
    deque<int> dq;
    vector<int> ans;

    // first window traversal, storing indexes of negative elements of first window
    for(int i = 0; i < k; i++){
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }

    // storing the ans of first k sized window
    if(!dq.empty()){
        ans.push_back(arr[dq.front()]);
    }else{
        ans.push_back(0);
    }


    // for remaining windows in array :-
    for(int i = k; i < n; i++){
        // removing indexes of previou windows in dequeue
        if(!dq.empty() && i - dq.front() >= k){
            dq.pop_front();
        } 

        // Adding indexes of negative elements
        if(arr[i] < 0){
            dq.push_back(i);
        }

        // storing the answer
        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }

    return ans;

}

int main(){
    int arr[6] = {-5, 2, 3, -4, 7, -10};   
    int n = 6;

    int k = 3; // to give the first appearing negative integer in each window of size k = 2

    vector<int> ans = findAns(arr, n, k);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }





    return 0;
}