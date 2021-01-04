//
// Created by WOOO on 2020/2/14.
//
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <malloc.h>
#include <algorithm>
#include "my_base_structs.h"

#ifndef LEETCODE_STU_SOLUTION_H
#define LEETCODE_STU_SOLUTION_H
using namespace std;


class Leetcode_solution {
    static void mergeSort_sort(vector<int> &, int, int);

    static void mergeSort_merge(vector<int> &, int, int, int);

public:
    static void bucketSort(vector<int> &);

    [[maybe_unused]] static void bubbleSort(vector<int> &);

    [[maybe_unused]] static void insertionSort(vector<int> &);

    static void mergeSort(vector<int> &);

    [[maybe_unused]] static bool isPalindrome(int);

    [[maybe_unused]] static bool isMatch_Re(string, string);

    [[maybe_unused]] static int maxArea(vector<int> &);

    [[maybe_unused]] static string intToRoman(int);

    [[maybe_unused]] static int romanToInt(const string &);

    [[maybe_unused]] static string longestCommonPrefix(vector<string> &);

    [[maybe_unused]] static vector<vector<int>> threeSum_1(vector<int> &);

    [[maybe_unused]] static vector<vector<int>> threeSum_2(vector<int> &);

    [[maybe_unused]] static int threeSumClosest(vector<int> &, int);

    [[maybe_unused]] static vector<string> letterCombinations(string);

    [[maybe_unused]] static vector<vector<int>> fourSum(vector<int> &, int);

    [[maybe_unused]] static ListNode *removeNthFromEnd(ListNode *, int);

    [[maybe_unused]] static bool isValid(const string &);

    [[maybe_unused]] static vector<string> generateParenthesis_1(int);

    static void recursion4generateParenthesis_1(vector<string> &, const string &, int, int, int);

    static vector<string> generateParenthesis_2(int);

    [[maybe_unused]] static ListNode *mergeKLists_1(vector<ListNode *> &);

    [[maybe_unused]] static ListNode *mergeKLists_2(vector<ListNode *> &);

    static ListNode *mergeTwoLists(ListNode *, ListNode *);

    [[maybe_unused]] static ListNode *swapPairs_1(ListNode *);

    static ListNode *swapPairs_2(ListNode *);

    static ListNode *reverseKGroup_1(ListNode *, int);

    static ListNode *reverseKGroup_2(ListNode *, int);

    static ListNode *reverseLists(ListNode *);

    [[maybe_unused]] static int removeDuplicates(vector<int> &);

    [[maybe_unused]] static int removeElement(vector<int> &, int);

    [[maybe_unused]] static int strStr_1(const string &, const string &);

    [[maybe_unused]] static int strStr_2(const string &, const string &);

    static vector<int> next_map(string);

    [[maybe_unused]] static int divide(int, int);

    [[maybe_unused]] static vector<int> findSubstring(const string &, vector<string> &);

    [[maybe_unused]] static void nextPermutation(vector<int> &);

    inline static void my_swap(int &, int &);

    [[maybe_unused]] static int longestValidParentheses_1(const string &);

    [[maybe_unused]] static int longestValidParentheses_2(const string &);

    [[maybe_unused]] static int longestValidParentheses_3(const string &);

    [[maybe_unused]] static int search(vector<int> &, int);

    static int divide_search(vector<int> &, int, int, int);

    [[maybe_unused]] static vector<int> searchRange(vector<int> &, int);

    static int search_le(vector<int> &, int, bool);

    [[maybe_unused]] static void merge(vector<int> &, int, vector<int> &, int);

    static bool isValidSudoku(vector<vector<char>> &);

    static bool sudokumnisValid(vector<vector<char>> &, int, int, int, int);

    [[maybe_unused]] static void solveSudoku(vector<vector<char>> &);

    static bool co_solveSudoku(vector<vector<char>> &);

    [[maybe_unused]] static string countAndSay(int n);

    [[maybe_unused]] static int orangesRotting(vector<vector<int>> &);

    static int rotOranges(vector<vector<int>> &, int, int, int, int);

    [[maybe_unused]] static vector<vector<int>> combinationSum(vector<int> &, int);

    static void violenceSwitch(vector<int> &, const vector<int> &, int, int, vector<vector<int>> &);

    [[maybe_unused]] static vector<int> distributeCandies(int, int);

    [[maybe_unused]] static vector<vector<int>> findContinuousSequence_1(int);

    [[maybe_unused]] static vector<vector<int>> findContinuousSequence_2(int);

    [[maybe_unused]] static vector<vector<int>> combinationSum2(vector<int> &, int);

    static void violenceSwitch2(vector<int> &, const vector<int> &, int, int, vector<vector<int>> &);

    [[maybe_unused]] static int firstMissingPositive(vector<int> &);

    [[maybe_unused]] static int trap(vector<int> &);

    [[maybe_unused]] static void reverseString(vector<char> &);

    static void reverse_coString(vector<char> &, int, int);

    [[maybe_unused]] static int coinChange(vector<int> &, int);

    [[maybe_unused]] static int maxProfit_1(vector<int> &);

    [[maybe_unused]] static int maxProfit_2(vector<int> &);

    [[maybe_unused]] static int diameterOfBinaryTree(TreeNode *);

    static int deep4Tree(TreeNode *, int &);

    [[maybe_unused]] static bool canThreePartsEqualSum(vector<int> &);

    [[maybe_unused]] static string multiply(string, string);

    [[maybe_unused]] static bool isMatch_Wildcard(string, string);

    [[maybe_unused]] static vector<vector<int>> permute(vector<int> &);

    static void co_permute(vector<int> &, vector<int> &, const vector<int> &, vector<vector<int>> &);

    [[maybe_unused]] static int lengthOfLIS(vector<int> &);

    [[maybe_unused]] static int maxAreaOfIsland(vector<vector<int>> &);

    static int dps_maxAreaOfIsland(vector<vector<int>> &, int, int);

    [[maybe_unused]] static int jump_1(vector<int> &nums);

    [[maybe_unused]] static int jump_2(vector<int> &nums);

    [[maybe_unused]] static string compressString(const string &);

    [[maybe_unused]] static vector<vector<int>> permuteUnique(vector<int> &);

    static void dps_permuteUnique(map<int, int> &, const vector<int> &, vector<vector<int>> &, int);

    [[maybe_unused]] static void rotate(vector<vector<int>> &);

    [[maybe_unused]] static int countCharacters(vector<string> &, const string &);

    [[maybe_unused]] static vector<vector<string>> groupAnagrams(vector<string> &);

    [[maybe_unused]] static vector<vector<string>> solveNQueens(int);

    static void
    solveNQueens_dg(vector<bool> &, vector<bool> &, vector<bool> &, vector<string> &, int, vector<vector<string>> &);

    [[maybe_unused]] static int maxSubArray(vector<int> &);

    [[maybe_unused]] static bool isRectangleOverlap(vector<int> &, vector<int> &);

    [[maybe_unused]] static vector<int> spiralOrder(vector<vector<int>> &);

    [[maybe_unused]] static bool canJump(vector<int> &);

    [[maybe_unused]] static int longestPalindrome(const string &);

    [[maybe_unused]] static vector<int> getLeastNumbers(vector<int> &, int);

    [[maybe_unused]] static vector<vector<int>> mergeRange(vector<vector<int>> &);

    [[maybe_unused]] static vector<vector<int>> insertRange(vector<vector<int>> &, vector<int> &);

    [[maybe_unused]] static int lengthOfLastWord(string);

    [[maybe_unused]] static vector<vector<int>> generateMatrix(int);

    [[maybe_unused]] static string getPermutation(int, int);

    [[maybe_unused]] static bool canMeasureWater(int, int, int);

    [[maybe_unused]] static int majorityElement(vector<int> &);

    [[maybe_unused]] static ListNode *rotateRight(ListNode *, int);

    [[maybe_unused]] static int minIncrementForUnique(vector<int> &);

    [[maybe_unused]] static string gcdOfStrings(string, string);

    [[maybe_unused]] static ListNode *middleNode(ListNode *);

    [[maybe_unused]] static int uniquePaths(int, int);

    [[maybe_unused]] static int uniquePathsWithObstacles(vector<vector<int>> &);

    [[maybe_unused]] static int minPathSum(vector<vector<int>> &);

    [[maybe_unused]] static bool isNumber(const string &);

    [[maybe_unused]] static int massage(vector<int> &);

    [[maybe_unused]] static vector<int> plusOne(vector<int> &);

    [[maybe_unused]] static int surfaceArea(vector<vector<int>> &);

    [[maybe_unused]] static string addBinary(const string &, const string &);

    [[maybe_unused]] static int maxDistance(vector<vector<int>> &);

    [[maybe_unused]] static int lastRemaining(int, int);

    [[maybe_unused]] static vector<int> maxDepthAfterSplit(string);

    [[maybe_unused]] static vector<string> fullJustify(vector<string> &, int);

    [[maybe_unused]] static void gameOfLife(vector<vector<int>> &);

    [[maybe_unused]] static string simplifyPath(string);

    [[maybe_unused]] static int minDistance(string, string);

    [[maybe_unused]] static void setZeroes(vector<vector<int>> &);

    [[maybe_unused]] static bool searchMatrix(vector<vector<int>> &, int);

    [[maybe_unused]] static void sortColors(vector<int> &);

    [[maybe_unused]] static string minWindow(const string &, const string &);

    [[maybe_unused]] static vector<vector<int>> combine(int, int);

    static void co_combine(int, int, int, vector<int> &, vector<vector<int>> &);

    [[maybe_unused]] static vector<vector<int>> subsets(vector<int> &);

    static void co_subsets(int, vector<int> &, vector<int> &, vector<vector<int>> &);

    [[maybe_unused]] static bool exist(vector<vector<char>> &, const string &);

    static bool co_exist(vector<vector<char>> &, const string &, int, int, int);

    [[maybe_unused]] static int removeDuplicates2(vector<int> &);

    [[maybe_unused]] static int movingCount(int, int, int);

    static int co_movingCount(int);

    [[maybe_unused]] static string reverseWords(string);

    [[maybe_unused]] static int superEggDrop(int, int);

    [[maybe_unused]] static bool searchII(vector<int> &, int);

    [[maybe_unused]] static ListNode *deleteDuplicates(ListNode *);

    [[maybe_unused]] static ListNode *deleteDuplicatesII(ListNode *);

    [[maybe_unused]] static ListNode *addTwoNumbers(ListNode *, ListNode *);

    [[maybe_unused]] static vector<vector<int>> updateMatrix(vector<vector<int>> &);

    [[maybe_unused]] static int largestRectangleArea(vector<int> &);

    [[maybe_unused]] static int getMaxRepetitions(string, int, string, int);

    [[maybe_unused]] static int numIslands(vector<vector<char>> &);

    static void numIslandsBFS(vector<vector<char>> &, int, int);

    [[maybe_unused]] static int numberOfSubArrays(vector<int> &, int);

    [[maybe_unused]] static vector<int> rightSideView(TreeNode *);

    static void co_rightSideView(TreeNode *, int &, int, vector<int> &);

    [[maybe_unused]] static int maximalRectangle(vector<vector<char>> &);

    [[maybe_unused]] static int maximalSquare(vector<vector<char>> &);

    [[maybe_unused]] static ListNode *partition(ListNode *, int);

    [[maybe_unused]] static vector<int> singleNumbers(vector<int> &);

    [[maybe_unused]] static bool isScramble(const string &, const string &);

    static bool isScrambleRecursion(const string &, const string &);

    [[maybe_unused]] static bool isHappy(int);

    static int isHappyNext(int);

    [[maybe_unused]] static void arrayMerge(vector<int> &, int, vector<int> &, int);

    static vector<int> grayCode(int);

    [[maybe_unused]] static vector<vector<int>> subsetsWithDup(vector<int> &);

    static void recursiveSubsetsWithDup(vector<int> &, vector<vector<int>> &, vector<int> &, int);

    [[maybe_unused]] static int numDecoding(string);

    [[maybe_unused]] static ListNode *reverseBetween(ListNode *, int, int);

    [[maybe_unused]] static vector<string> restoreIpAddresses(string);

    static void coRestoreIpAddresses(string &, vector<string> &, const string &, int, int);

    [[maybe_unused]] static vector<int> inorderTraversal(TreeNode *);

    [[maybe_unused]] static vector<TreeNode *> generateTrees(int);

    static vector<TreeNode *> generate_trees(int, int);

    [[maybe_unused]] static int numTrees(int);

    [[maybe_unused]] static bool isInterleave(string, string, string);

    [[maybe_unused]] static bool isValidBST(TreeNode *);

    [[maybe_unused]] static int mincostTickets(vector<int> &, vector<int> &);

    static bool isSameTree(TreeNode *, TreeNode *);

    [[maybe_unused]] static bool isSymmetric(TreeNode *);

    static bool coIsSymmetric(TreeNode *, TreeNode *);

    [[maybe_unused]] static vector<vector<int>> levelOrder(TreeNode *);

    [[maybe_unused]] static int singleNumber(vector<int> &);

    [[maybe_unused]] static vector<vector<int>> zigzagLevelOrder(TreeNode *root);

    [[maybe_unused]] static int subarraySum(vector<int> &nums, int k);

    [[maybe_unused]] static TreeNode *buildTree1(vector<int> &preorder, vector<int> &inorder);

    static TreeNode *coBuildTree1(vector<int> &preorder, int x, int y, vector<int> &inorder, int p, int q);

    [[maybe_unused]] static TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder);

    static TreeNode *coBuildTree2(vector<int> &inorder, int x, int y, vector<int> &postorder, int p, int q);

    [[maybe_unused]] static int numPairsDivisibleBy60(vector<int> &time);

    [[maybe_unused]] static int maxProduct(vector<int> &nums);

    [[maybe_unused]] static bool validPalindrome(string s);

    static bool checkPalindrome(const string &s, int low, int high);

    [[maybe_unused]] static int hammingWeight(uint32_t n);

    [[maybe_unused]] static int minDepth(TreeNode *root);

    [[maybe_unused]] static int findTheLongestSubstring(string s);

    static bool hasPathSum(TreeNode *root, int sum);

    [[maybe_unused]] static vector<vector<int>> pathSum(TreeNode *root, int sum);

    static void coPathSum(TreeNode *root, int sum, vector<int> &temp, vector<vector<int>> &res);

    [[maybe_unused]] static string decodeString(string s);

    static int rob1(vector<int> &nums, int start, int end);

    [[maybe_unused]] static int rob2(vector<int> &nums);

    [[maybe_unused]] static int rob3(TreeNode *root);

    static void rob3dp(TreeNode *root, int &left, int &right);

    [[maybe_unused]] static bool isPalindrome(ListNode *head);

    [[maybe_unused]] static vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies);

    [[maybe_unused]] static int minimumTotal(vector<vector<int>> &triangle);

    [[maybe_unused]] static vector<int> productExceptSelf(vector<int> &nums);

    [[maybe_unused]] static int longestConsecutive(vector<int> &nums);

    [[maybe_unused]] static bool possibleBipartition(int N, vector<vector<int>> &dislikes);

    static bool possibleBipartitiondfs(int node, int c, vector<int> &color, vector<vector<int>> &graph);

    [[maybe_unused]] static vector<int> dailyTemperatures(vector<int> &T);

    [[maybe_unused]] static bool wordBreak(const string &s, vector<string> &wordDict);

    [[maybe_unused]] static int minSubArrayLen(int s, vector<int> &nums);

    [[maybe_unused]] static vector<int> divingBoard(int shorter, int longer, int k);

    [[maybe_unused]] static vector<int> countSmaller(vector<int> &nums);

    [[maybe_unused]] static int calculateMinimumHP(vector<vector<int>> &dungeon);

    [[maybe_unused]] static int longestIncreasingPath(vector<vector<int>> &matrix);

    [[maybe_unused]] static string addStrings(string num1, string num2);

    [[maybe_unused]] static vector<string> ommonChars(vector<string> &A);

    [[maybe_unused]] static bool isLongPressedName(string name, string typed);

    [[maybe_unused]] static vector<int> partitionLabels(string S);

    [[maybe_unused]] static int videoStitching(vector<vector<int>> &clips, int T);

    [[maybe_unused]] static int longestMountain(vector<int> &A);

    [[maybe_unused]] static int mySqrt(int x);

    [[maybe_unused]] static int findMin(vector<int> &nums);

    [[maybe_unused]] static vector<int> findClosestElements(vector<int> &arr, int k, int x);

    [[maybe_unused]] static int findRotateSteps(string ring, string key);

    [[maybe_unused]] static int canCompleteCircuit(vector<int> &gas, vector<int> &cost);

    [[maybe_unused]] static ListNode *insertionSortList(ListNode *head);

    [[maybe_unused]] static int findMinArrowShots(vector<vector<int>> &points);

    static bool exists(TreeNode *root, int level, int k);

    [[maybe_unused]] static int countNodes(TreeNode *root);

    [[maybe_unused]] static int maximumGap(vector<int> &nums);

    [[maybe_unused]] static void flatten(TreeNode *root);

    static int isBalancedTreeheight(TreeNode *root);

    [[maybe_unused]] static bool isBalanced(TreeNode *root);

    [[maybe_unused]] static int countPrimes(int n);

    [[maybe_unused]] static int matrixScore(vector<vector<int>> &A);

    [[maybe_unused]] static int monotoneIncreasingDigits(int N);

    [[maybe_unused]] static bool wordPattern(string pattern, string s);

    [[maybe_unused]] static string removeDuplicateLetters(string &s);
};

#endif //LEETCODE_STU_SOLUTION_H
