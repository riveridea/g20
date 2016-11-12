/*


*/

class Solution {
public:
      struct BinarySearchTreeNode *insert(Struct BinarySearchTreeNode *root, int data) {
          if (root == NULL) {
              return root;
          } 
          
          if (data < root->data) {
              root->left = insert(root->left, data);
          }
          
          if (data > root->data) {
              root->right = insert(root->left, data);
          }
    
          if (data == root->data) {
              return root;
          }
    
      }

};
