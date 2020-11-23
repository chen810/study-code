//
// Created by WOOO on 2020/2/14.
//

#ifndef LEETCODE_STU_LEETCODE_SOLUTION_H
#define LEETCODE_STU_LEETCODE_SOLUTION_H
#include <string>
#include <vector>
#include <map>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

ListNode *makeListNodeChain(vector<int>, bool = true);
void printListNodeChain(ListNode *, const string& = "->");


class Solution {
    static void mergeSort_sort(vector<int>&, int, int);
    static void mergeSort_merge(vector<int>&, int, int, int);
public:
    static void bucketSort(vector<int>&);
    static void bubbleSort(vector<int>&);
    static void insertionSort(vector<int>&);
    static void mergeSort(vector<int>&);
    static bool isPalindrome(int);
    static bool isMatch_Re(string, string);
    static int maxArea(vector<int>&);
    static string intToRoman(int);
    static int romanToInt(const string&);
    static string longestCommonPrefix(vector<string>&);
    static vector<vector<int>> threeSum_1(vector<int>&);
    static vector<vector<int>> threeSum_2(vector<int>&);
    static int threeSumClosest(vector<int>&, int);
    static vector<string> letterCombinations(string);
    static vector<vector<int>> fourSum(vector<int>&, int);
    static ListNode* removeNthFromEnd(ListNode* , int);
    static bool isValid(const string&);
    static vector<string> generateParenthesis_1(int);
    static void recursion4generateParenthesis_1(vector<string> &, const string&, int, int, int);
    static vector<string> generateParenthesis_2(int);
    static ListNode* mergeKLists_1(vector<ListNode*>&);
    static ListNode* mergeKLists_2(vector<ListNode*>&);
    static ListNode* mergeTwoLists(ListNode*, ListNode*);
    static ListNode* swapPairs_1(ListNode*);
    static ListNode* swapPairs_2(ListNode*);
    static ListNode* reverseKGroup_1(ListNode*, int);
    static ListNode* reverseKGroup_2(ListNode*, int);
    static ListNode* reverseLists(ListNode*);
    static int removeDuplicates(vector<int>&);
    static int removeElement(vector<int>& , int);
    static int strStr_1(const string&, const string&);
    static int strStr_2(const string&, const string&);
    static vector<int> next_map(string);
    static int divide(int , int);
    static vector<int> findSubstring(const string&, vector<string>&);
    static void nextPermutation(vector<int>&);
    inline static void my_swap(int &,int &);
    static int longestValidParentheses_1(const string&);
    static int longestValidParentheses_2(const string&);
    static int longestValidParentheses_3(const string&);
    static int search(vector<int>&, int );
    static int divide_search(vector<int>&,int,int,int);
    static vector<int> searchRange(vector<int>&, int);
    static int search_le(vector<int>&,int,bool);
    static void merge(vector<int>&, int, vector<int>&, int);
    static bool isValidSudoku(vector<vector<char>>&);
    static bool sudokumnisValid(vector<vector<char>>&, int, int, int, int);
    static void solveSudoku(vector<vector<char>>&);
    static bool co_solveSudoku(vector<vector<char>>&);
    static string countAndSay(int n);
    static int orangesRotting(vector<vector<int>>&);
    static int rotOranges(vector<vector<int>>&,int,int,int,int);
    static vector<vector<int>> combinationSum(vector<int> &, int);
    static void violenceSwitch(vector<int>&,const vector<int>&, int,int,vector<vector<int>>&);
    static vector<int> distributeCandies(int, int);
    static vector<vector<int>> findContinuousSequence_1(int);
    static vector<vector<int>> findContinuousSequence_2(int);
    static vector<vector<int>> combinationSum2(vector<int> &, int );
    static void violenceSwitch2(vector<int> &,const vector<int> &,int,int,vector<vector<int>> &);
    static int firstMissingPositive(vector<int> &);
    static int trap(vector<int> &);
    static void reverseString(vector<char> &);
    static void reverse_coString(vector<char> &, int, int);
    static int coinChange(vector<int> &, int);
    static int maxProfit_1(vector<int> &);
    static int maxProfit_2(vector<int> &);
    static int diameterOfBinaryTree(TreeNode *);
    static int deep4Tree(TreeNode *,int &);
    static bool canThreePartsEqualSum(vector<int> &);
    static string multiply(string, string );
    static bool isMatch_Wildcard(string , string );
    static vector<vector<int>> permute(vector<int> &);
    static void co_permute(vector<int> &, vector<int>&,const vector<int>&,vector<vector<int>>& );
    static int lengthOfLIS(vector<int> &);
    static int maxAreaOfIsland(vector<vector<int>> &);
    static int dps_maxAreaOfIsland(vector<vector<int>> &, int , int);
    static int jump_1(vector<int> &nums);
    static int jump_2(vector<int> &nums);
    static string compressString(const string&);
    static vector<vector<int>> permuteUnique(vector<int> &);
    static void dps_permuteUnique(map<int,int> &, const vector<int> &, vector<vector<int>> &,int);
    static void rotate(vector<vector<int>> &);
    static int countCharacters(vector<string> &, const string& );
    static vector<vector<string>> groupAnagrams(vector<string> &);
    static vector<vector<string>> solveNQueens(int);
    static void solveNQueens_dg(vector<bool> &, vector<bool> &, vector<bool> &, vector<string> &, int,vector<vector<string>> &);
    static int maxSubArray(vector<int> &);
    static bool isRectangleOverlap(vector<int> &, vector<int> &);
    static vector<int> spiralOrder(vector<vector<int>> &);
    static bool canJump(vector<int> &);
    static int longestPalindrome(const string&);
    static vector<int> getLeastNumbers(vector<int> &, int);
    static vector<vector<int>> mergeRange(vector<vector<int>> &);
    static vector<vector<int>> insertRange(vector<vector<int>> &, vector<int> &);
    static int lengthOfLastWord(string);
    static vector<vector<int>> generateMatrix(int);
    static string getPermutation(int, int);
    static bool canMeasureWater(int, int, int);
    static int majorityElement(vector<int> &);
    static ListNode *rotateRight(ListNode *, int);
    static int minIncrementForUnique(vector<int> &);
    static string gcdOfStrings(string , string );
    static ListNode *middleNode(ListNode *);
    static int uniquePaths(int, int);
    static int uniquePathsWithObstacles(vector<vector<int>> &);
    static int minPathSum(vector<vector<int>> &);
    static bool isNumber(const string&);
    static int massage(vector<int> &);
    static vector<int> plusOne(vector<int> &);
    static int surfaceArea(vector<vector<int>> &);
    static string addBinary(const string&, const string&);
    static int maxDistance(vector<vector<int>> &);
    static int lastRemaining(int, int);
    static vector<int> maxDepthAfterSplit(string);
    static vector<string> fullJustify(vector<string> &, int);
    static void gameOfLife(vector<vector<int>> &);
    static string simplifyPath(string);
    static int minDistance(string, string);
    static void setZeroes(vector<vector<int>> &);
    static bool searchMatrix(vector<vector<int>> &, int);
    static void sortColors(vector<int> &);
    static string minWindow(const string&, const string&);
    static vector<vector<int>> combine(int, int);
    static void co_combine(int,int,int, vector<int> &,vector<vector<int>> &);
    static vector<vector<int>> subsets(vector<int> &);
    static void co_subsets(int, vector<int>&, vector<int> &, vector<vector<int>> &);
    static bool exist(vector<vector<char>> &, const string&);
    static bool co_exist(vector<vector<char>> &, const string&, int, int, int);
    static int removeDuplicates2(vector<int> &);
    static int movingCount(int, int, int);
    static int co_movingCount(int);
    static string reverseWords(string);
    static int superEggDrop(int, int);
    static bool searchII(vector<int> &, int);
    static ListNode *deleteDuplicates(ListNode *);
    static ListNode *deleteDuplicatesII(ListNode *);
    static ListNode *addTwoNumbers(ListNode *, ListNode *);
    static vector<vector<int>> updateMatrix(vector<vector<int>> &);
    static int largestRectangleArea(vector<int> &);
    static int getMaxRepetitions(string, int , string , int );
    static int numIslands(vector<vector<char>> &);
    static void numIslandsBFS(vector<vector<char>> &, int , int );
    static int numberOfSubArrays(vector<int> &, int);
    static vector<int> rightSideView(TreeNode *);
    static void co_rightSideView(TreeNode *, int &,int ,vector<int> &);
    static int maximalRectangle(vector<vector<char>> &);
    static int maximalSquare(vector<vector<char>> &);
    static ListNode *partition(ListNode *, int );
    static vector<int> singleNumbers(vector<int> &);
    static bool isScramble(const string& , const string& );
    static bool isScrambleRecursion(const string& , const string& );
    static bool isHappy(int);
    static int isHappyNext(int);
    static void arrayMerge(vector<int> &, int , vector<int> &, int);
    static vector<int> grayCode(int );
    static vector<vector<int>> subsetsWithDup(vector<int> &);
    static void recursiveSubsetsWithDup(vector<int> &, vector<vector<int>> &, vector<int> &,int );
    static int numDecoding(string);
    static ListNode *reverseBetween(ListNode *, int, int);
    static vector<string> restoreIpAddresses(string);
    static void coRestoreIpAddresses(string &, vector<string> &, const string& ,int, int);
    static vector<int> inorderTraversal(TreeNode *);
    static vector<TreeNode *> generateTrees(int);
    static vector<TreeNode *> generate_trees(int, int);
    static int numTrees(int);
    static bool isInterleave(string, string, string);
    static bool isValidBST(TreeNode *);
    static int mincostTickets(vector<int> &, vector<int> &);
    static bool isSameTree(TreeNode *, TreeNode *);
    static bool isSymmetric(TreeNode *);
    static bool coIsSymmetric(TreeNode *, TreeNode *);
    static vector<vector<int>> levelOrder(TreeNode *);
    static int singleNumber(vector<int> &);
    static vector<vector<int>> zigzagLevelOrder(TreeNode *root);
    static int subarraySum(vector<int> &nums, int k);
    static TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder);
    static TreeNode *coBuildTree1(vector<int> &preorder, int x, int y, vector<int> &inorder, int p, int q);
    static TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder);
    static TreeNode *coBuildTree2(vector<int> &inorder, int x, int y, vector<int> &postorder, int p, int q);
    static int numPairsDivisibleBy60(vector<int> &time);
    static int maxProduct(vector<int> &nums);
    static bool validPalindrome(string s);
    static bool checkPalindrome(const string &s, int low, int high);
    static int hammingWeight(uint32_t n);
    static int minDepth(TreeNode *root);
    static int findTheLongestSubstring(string s);
    static bool hasPathSum(TreeNode *root, int sum);
    static vector<vector<int>> pathSum(TreeNode *root, int sum);
    static void coPathSum(TreeNode *root, int sum, vector<int> &temp,vector<vector<int>> &res);
    static string decodeString(string s);
    static int rob1(vector<int> &nums, int start, int end);
    static int rob2(vector<int> &nums);
    static int rob3(TreeNode *root);
    static void rob3dp(TreeNode *root, int &left, int &right);
    static bool isPalindrome(ListNode *head);
    static vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies);
    static int minimumTotal(vector<vector<int>> &triangle);
    static vector<int> productExceptSelf(vector<int> &nums);
    static int longestConsecutive(vector<int> &nums);
    static bool possibleBipartition(int N, vector<vector<int>> &dislikes);
    static bool possibleBipartitiondfs(int node, int c, vector<int> &color, vector<vector<int>> &graph);
    static vector<int> dailyTemperatures(vector<int> &T);
    static bool wordBreak(const string& s, vector<string> &wordDict);
    static int minSubArrayLen(int s, vector<int> &nums);
    static vector<int> divingBoard(int shorter, int longer, int k);
    static vector<int> countSmaller(vector<int> &nums);
    static int calculateMinimumHP(vector<vector<int>> &dungeon);
    static int longestIncreasingPath(vector<vector<int>> &matrix);
    static string addStrings(string num1, string num2);
    static vector<string> ommonChars(vector<string> &A);

    static bool isLongPressedName(string name, string typed);

    static vector<int> partitionLabels(string S);

    static int videoStitching(vector<vector<int>> &clips, int T);

    static int longestMountain(vector<int> &A);

    static int mySqrt(int x);

    static int findMin(vector<int> &nums);

    static vector<int> findClosestElements(vector<int> &arr, int k, int x);

    static int findRotateSteps(string ring, string key);

    static int canCompleteCircuit(vector<int> &gas, vector<int> &cost);

    static ListNode *insertionSortList(ListNode *head);

    static int findMinArrowShots(vector<vector<int>> &points);
};

#endif //LEETCODE_STU_LEETCODE_SOLUTION_H
