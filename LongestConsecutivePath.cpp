#include <bits/stdc++.h> 
using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int data;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
class Solution {
  public:
    int ans=0;
    int longestConsecutive(Node* root) {
        // code here
        dfs(root,root->data-1,0);
        return ans==1 ? -1:ans;
    }
    void dfs(Node* root,int prev,int len){
        if(root==nullptr) return;
        
        if(prev+1==root->data) len++;
        else len=1;
        
        ans=max(ans,len);
        
        dfs(root->left,root->data,len);
        dfs(root->right,root->data,len);
    }
};
Node* buildTree(vector<int>& nums){
    Node* root=new Node(nums[0]);
    int n=nums.size();
    queue<Node*> q;
    q.push(root);
    int i=1;
    while(!q.empty() && i<n){
        Node* curr=q.front();
        q.pop();

        if(i<n && nums[i]!=-1){
            curr->left=new Node(nums[i]);
            q.push(curr->left);
        }
        i++;
        if(i<n && nums[i]!=-1){
            curr->right=new Node(nums[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
int main(){
    Solution sol;
    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the values of array: "<<endl;
    for(int i=0;i<n;i++) cin>>nums[i];
    Node* root=buildTree(nums);
    cout<<"Longest consecutive path is "<<sol.longestConsecutive(root)<<endl;
    return 0;
}