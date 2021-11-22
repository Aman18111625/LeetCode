//Question: Construt Binary Tree from INORDER and POSTORDER Traversal(https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)
//Difficulty Level: Medium
//Pre-requisite:- INORDER and POSTORDER traversal in Binary Tree

//Approach-1 
//TC:-O(N^2) SC:-O(N)
/*
Thought Process:-
When we do an INORDER traversal, we have the left subtree, then somewhere in the middle the root, then the right subtree.
When we do POSTORDER traversal, we have the root at the end.
*/
//IF you want to a detailed explained then please visit pepcoding youtube channel .
TreeNode* helper(vector<int>& postorder,int psi,int pei,vector<int>& inorder,int isi,int iei)
{
        if(isi>iei) return NULL;
        TreeNode* node=new TreeNode(postorder[pei]);//make root
         int idx=isi;
        while(postorder[pei]!=inorder[idx]) idx++;
        int countOfLeftSubTreeElem=idx-isi;//left-Subtree
        node->left=helper(postorder,psi,psi+countOfLeftSubTreeElem-1,inorder,isi,idx-1);//call for left-Subtree
        node->right=helper(postorder,psi+countOfLeftSubTreeElem,pei-1,inorder,idx+1,iei);//call for right-Subtree
      return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
        int n=inorder.size();
        return helper(postorder,0,n-1,inorder,0,n-1);
}
*/
//Approach-2 
//TC:-O(N) SC:O(N)
/*
We know that, the last element of POSTORDER array contains main ROOT Node. and In INORDER array we see that the left side of the ROOT element contains the LEFT side element and Right side contains all the RIGHT side element.
So, we have to find out the index of ROOT element in INORDER Element.
So,
int inorderIndex = m[postorder[postIndex]];
and Make ROOT =
TreeNode *root =new TreeNode(inorder[inorderIndex]);
and postIndex decreament by 1 for the next purpose.
And then we go to the Right side first and make the Right side of the ROOT. Here the start index is inorderIndex+1 cause all Right Part is in the Right Side of the inorder Array.
root->right=solve(inorder,postorder,inorderIndex+1,end,postIndex);

And then we go to the Left Side and make the Left side of the ROOT. Here the end index is inorderIndex-1 cause all left Part is in the left Side of the inorder Array.
root->left=solve(inorder,postorder,start,inorderIndex-1,postIndex);

And Now the base case, when we stop our Recursion:
We all know when, start> end, we return NULL;
if(start>end) return NULL;

And Last we return ROOT;
*/
 unordered_map<int,int>m;
TreeNode* solve(vector<int>& inorder,vector<int>& postorder,int start,int end,int &postIndex)
{
        if(start>end) return NULL;
         int inorderIndex = m[postorder[postIndex]];

        TreeNode* root = new TreeNode(inorder[inorderIndex]);    
        
        (postIndex)--;
       root->right=solve(inorder,postorder,inorderIndex+1,end,postIndex);
        root->left=solve(inorder,postorder,start,inorderIndex-1,postIndex);    
        return root;
}
    
public:    
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
        int n=inorder.size();
        for(int i=0;i<n;i++){
           m[inorder[i]] = i;      
        }
        int postIndex=n-1;
        return solve(inorder,postorder,0,n-1,postIndex);
}