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
};

#endif //LEETCODE_STU_LEETCODE_SOLUTION_H
