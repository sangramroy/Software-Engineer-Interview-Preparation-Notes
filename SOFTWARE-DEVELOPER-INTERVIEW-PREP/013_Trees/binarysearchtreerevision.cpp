#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class TreeNode{
    public:
  int data;
  TreeNode* left,*right;
  TreeNode(int val)
  {
      data=val;
      left=right=NULL;
  }
};

TreeNode* buildTree(TreeNode* root,int val)
{
    if(root==NULL) return new TreeNode(val);
    if(val<root->data) {
        root->left=buildTree(root->left,val);
    }
    else
        root->right=buildTree(root->right,val);
    return root;
}

void iterativeinorder(TreeNode* root)
{
    cout<<"\n inorder iterative traversal:\n";
    stack<TreeNode*> st;
    TreeNode* curr=root;
    while(curr!=NULL || !st.empty())
    {
        if(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        else
        {   if(st.empty()) return;
            curr=st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
}


void iterativepreorder(TreeNode* root)
{
    cout<<"\n preorder iterative traversal: // N L R \n";
    stack<TreeNode*> st;
    TreeNode* curr;
    st.push(root);
    while(!st.empty())
    {       
            curr=st.top();
            st.pop();
            cout<<curr->data<<" ";
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
        }
}

void iterativepostorder(TreeNode* root)
{
    cout<<"\n postorder iterative traversal: // L R N \n";
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    TreeNode* curr;
    st1.push(root);
    while(!st1.empty())
       {       
            curr=st1.top();
            st1.pop();
            //cout<<curr->data<<" ";
            st2.push(curr);
            if(curr->left) st1.push(curr->left);
            if(curr->right) st1.push(curr->right);
            
        }
        
        while(!st2.empty())
        {
            curr=st2.top();
            st2.pop();
            cout<<curr->data<<" ";
        }
}

// cout<<"\n inorder recursive traversal: // L N R \n";
void recursiveinorder(TreeNode* root)
{
    if(root==NULL) return;
    recursiveinorder(root->left);
    cout<<root->data<<" ";
    recursiveinorder(root->right);
}

// cout<<"\n preorder recursive traversal: // N L R \n";
void recursivepreorder(TreeNode* root)
{
    if(root==NULL) return;
    cout<<root->data<<" ";
    recursivepreorder(root->left);
    recursivepreorder(root->right);
}

// cout<<"\n postorder recursive traversal: // L R N \n";
void recursivepostorder(TreeNode* root)
{
    if(root==NULL) return;
    recursivepostorder(root->left);
    recursivepostorder(root->right);
    cout<<root->data<<" ";
}

//BFS iterative
void iterativelevelorder(TreeNode* root)
{
    cout<<"\n levelorder iterative traversal: //\n";
    queue<TreeNode*> q;
    TreeNode* curr;
    q.push(root);
    while(!q.empty())
       {       
            curr=q.front();
            q.pop();
            cout<<curr->data<<" ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
}


//BFS recursive
int heightoftree(TreeNode* root)
{
    if(root==NULL) return 0;
    int lefttree=heightoftree(root->left);
    int righttree=heightoftree(root->right);
    return max(lefttree,righttree)+1;
}

void printlevel(TreeNode* root,int level)
{
    if(root==NULL) return;
    if(level==0) cout<<root->data<<" ";
    else if(level>0)
    {
        printlevel(root->left,level-1);
        printlevel(root->right,level-1);
    }
}

void recursivelevelorder(TreeNode* root)
{
  for(int i=0;i<heightoftree(root);i++)
  {
      printlevel(root,i);
  }
}

int countallnodes(TreeNode* root)
{
    if(root==NULL) return 0;
    return countallnodes(root->left)+countallnodes(root->right)+1;
}

int sumofallnodes(TreeNode* root)
{
    if(root==NULL) return 0;
    return sumofallnodes(root->left)+sumofallnodes(root->right)+root->data;
}
int countleafnodes(TreeNode* root)
{
    if(!root) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    return countleafnodes(root->left)+countleafnodes(root->right);
}

int sumleafnodes(TreeNode* root)
{
    if(!root) return 0;
    if(root->left==NULL && root->right==NULL) return root->data;
    return sumleafnodes(root->left)+sumleafnodes(root->right);
}

int countnonleafnodes(TreeNode* root)
{
    if(!root) return 0;
    if(root->left==NULL && root->right==NULL) return 0;
    return countnonleafnodes(root->left)+countnonleafnodes(root->right)+1;
}

int sumnonleafnodes(TreeNode* root)
{
    if(!root) return 0;
    if(root->left==NULL && root->right==NULL) return 0;
    return sumnonleafnodes(root->left)+sumnonleafnodes(root->right)+root->data;
}

int diamteroftree(TreeNode* root)
{
    if(!root) return 0;
    int lsubtreediameter=diamteroftree(root->left);
    int rsubtreediameter=diamteroftree(root->right);
    int height=heightoftree(root->left)+heightoftree(root->right)+1;
    return max(height,max(lsubtreediameter,rsubtreediameter));
}

void searchinBST(TreeNode* root,int key)
{
    if(root==NULL) return;
    if(root->data==key) cout<<"key found\n";
    else if(root->data>key)
    {
        searchinBST(root->right,key);
    }
    else
    {
        searchinBST(root->left,key);
    }
}

int min(TreeNode* root)
{
    while(root!=NULL && root->left)
    {
        root=root->left;
    }
    return root->data;
}
int max(TreeNode* root)
{
    while(root!=NULL && root->right)
    {
        root=root->right;
    }
    return root->data;
}

void predecessorsuccessor(TreeNode* root,int &pre,int &succ,int key)
{
    if(root==NULL) return;
    if(root->data==key)
    {
        cout<<"key found: "<<key<<endl;
        TreeNode* temp=root->left;
        TreeNode* temp1=root->right;
        if(temp)
        {
            while(temp->right)
            {
            temp=temp->right;
            }
            pre=temp->data;
        }
        if(temp1)
        {
            while(temp1->left)
            {
            temp1=temp1->left;
            }
            succ=temp1->data;
        }
        return;
    }
    else if(root->data<key)
    {
        succ=root->data;
        predecessorsuccessor(root->right,pre,succ,key);
    }
    else 
    {
         pre=root->data;
         predecessorsuccessor(root->left,pre,succ,key);
    }
}

int main()
{
    cout<<"\n implementing BST:\n";
    vector<int> v={23,5,87,21,44,2,7,98};
    TreeNode* root=NULL;
    for(int i=0;i<v.size();i++)
    {
        root=buildTree(root,v[i]);
    }
    iterativeinorder(root);
   cout<<"\n countallnodes in BST: "<<countallnodes(root);
   cout<<"\n countleafnodes in BST: "<<countleafnodes(root);
   cout<<"\n countnonleafnodes in BST: "<<countnonleafnodes(root);
   cout<<"\n sumofallnodes in BST: "<<sumofallnodes(root);
   cout<<"\n sumleafnodes in BST: "<<sumleafnodes(root);
   cout<<"\n sumnonleafnodes in BST: "<<sumnonleafnodes(root);
   cout<<"\n height of BST: "<<heightoftree(root);
   cout<<"\n diameter of BST: "<<diamteroftree(root);
   cout<<"\n min of BST: "<<min(root);
   cout<<"\n max of BST: "<<max(root);
    cout<<"\n predecessor/successor of BST: "<<endl;
    int pre=-1,succ=-1;
    predecessorsuccessor(root,pre,succ,87);
     cout<<"\n predecessor of BST: "<<pre<<endl;
        cout<<"\n successor of BST: "<<succ<<endl;
   return 0;
}


