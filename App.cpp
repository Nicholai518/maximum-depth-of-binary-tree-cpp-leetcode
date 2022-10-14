#include <iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  class Solution {
  public:
      int maxDepth(TreeNode* root) {

          // empty root = 0 depth
          if (root == NULL) {
              return 0;
          }

          // because the root is NOT null
          // find the depth of the left subtree
          int left = maxDepth(root->left);
          // find the depth of the right subtree
          int right = maxDepth(root->right);

          // return the larger depth (number)
          // +1 to include the root node
          int answer = 0;
          if (left > right) {
              answer = left + 1;
          }
          else {
              answer = right + 1;
          }
          return answer;
      }
  };

int main()
{
    Solution solution;

    TreeNode fifteen(15);
    TreeNode seven(7);
    TreeNode twenty(20, &fifteen, &seven);

    TreeNode nine(9);

    TreeNode root(3, &nine, &twenty);

    cout << "Example One : " << solution.maxDepth(&root) << endl;

	return 0;
}
