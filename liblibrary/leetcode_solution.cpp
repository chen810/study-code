//
// Created by WOOO on 2020/2/14.
// Used for Leetcode study
//
#include "leetcode_solution.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <malloc.h>
#include <stack>
#include <queue>

using namespace std;


// 创建链表,vector<int>为链表值,bool值为控制是否排序
ListNode* makeListNodeChain(vector<int> s, bool sortControl){
    if(sortControl){
        sort(s.begin(),s.end());
    }
    auto *head = new ListNode(0);
    auto p=head;
    for(auto i:s){
        p->next = new ListNode(i);
        p = p->next;
    }
    return head->next;
}
// 打印链表,按顺序打印,end可控制分隔符
void printListNodeChain(ListNode * head, const string& end){
    while(head!= nullptr){
        cout << head->val;
        if(head->next){
            cout << end;
        }
        head= head->next;
    }
}


/* 以上为辅助函数算法
 * =========================================================================
 * 以下为Solution算法实现
 * */


// 桶排序算法
/* 取最大值max和最小值min用来计算计数容器count大小max-min
 * 取待排序的数值i将其减去min得映射为下标的数字(i-min),并使count[i-min]自加1
 * 自加完成后,从count中循环将数值输出,若count[n]大于0,则将其加上min得到原数字(n+min)
 * 将原数字按序填入原排序容器,即完成排序
 * O = 2*n
 * 时间复杂度O(n)
 * */
void Solution::bucketSort(vector<int> &nums){
    // 容器中数字数量大于1才进行排序
    if(nums.size()>1){
        // 判断排序数据的最大值与最小值
        int max=nums[0],min=nums[0];
        for(auto i:nums){
            if(i>max){
                max = i;
            }
            if(i<min){
                min = i;
            }
        }
        // 建立count计数容器
        vector<int> count(max-min+1,0);
        // 计数,将数值映射为下标,并进行自加
        for(auto i:nums){
            ++count[i-min];
        }
        // 将下标映射为数值,按顺序填入原排序容器,并对count对应位置进行自减操作
        int k=0;
        for(int n=0; n < max - min + 1; ++n){
            while(count[n]){
                nums[k] = n + min;
                --count[n];
                ++k;
            }
        }
    }
}

// 冒泡排序算法
/* 从后向前牌,从前往后扫到待排位,比较相邻两个,将较大数字后移
 * 待排位到达首位则结束排序
 * O = 1+2+3+4+5+···+(n-1)
 * 时间复杂度为O(n*n)
 * */
void Solution::bubbleSort(vector<int> &nums) {
    // 取长度
    int le = nums.size();
    // 倒着遍历至第一个待求数值
    for(int i=le-1;i>=0;--i){
        // 从第一对数值,两两遍历至末尾,若后一个小于前一个则换位
        for(int k=1;k<=i;++k){
            if(nums[k-1] > nums[k]){
                int temp = nums[k];
                nums[k] = nums[k-1];
                nums[k-1] = temp;
            }
        }
    }
}

// 插入排序算法
/* 循环遍历待排数值
 * 向前判断插入位置,若大于一个数或者到了开头,则执插入操作
 * O = 1+2+3+4+5+···+(n-1)
 * 时间复杂度O(n*n)
 * */
void Solution::insertionSort(vector<int> &nums){
    // 从第一个待求数值位遍历到末尾
    for(int i=0;i<nums.size();++i){
        // 保存待排数值,并循环向前检测下一个取得的数值
        int temp = nums[i],j=i;
        // 待排数值到达头部或者大于一个数,并插在开头或者那个数之后
        while(j>0&&nums[j-1]>temp){
            nums[j] = nums[j-1];
            --j;
        }
        nums[j] = temp;
    }
}

// 归并排序算法:主函数-mergeSort,辅助函数mergeSort_sort,mergeSort_merge
/* 归并排序,利用分治思想,使用mergeSort_sort将其分为一个个小的数列,直至为1
 * 再通过mergeSort_merge进行合并两个区块
 * */
void Solution::mergeSort(vector<int> &nums){
    // 执行递归运算,为其添加初始值
    int l = nums.size();
    mergeSort_sort(nums,0,l-1);
}
void Solution::mergeSort_sort(vector<int> &nums, int left, int right) {
    // 若左指针大于等于右指针说明,元素数量达到最少,即不用排序
    if(left>=right){
        return;
    }
    // 取中点位置,使其分为两小块,进行排序,将排序完成的两小块进行合并，即可得到结果
    int mid = (left+right)/2;
    mergeSort_sort(nums,left,mid);
    mergeSort_sort(nums,mid+1,right);
    mergeSort_merge(nums,left,mid,right);
}
void Solution::mergeSort_merge(vector<int> &nums, int left, int mid, int right) {
    int mp = mid+1;
    int st = left;
    // 一个临时容器存储
    vector<int> temp(right-left+1);
    int index = 0;
    // 两个容器中数值进行比较,直到有一个容器中的数值被取完,则停止循环
    while(st <= mid&&mp<=right){
        int num = nums[st] <= nums[mp]?nums[st++]:nums[mp++];
        temp[index++] = num;
    }
    // 若左半段未被取完,则整串接在临时容器后面
    while(st <= mid){
        temp[index++] = nums[st++];
    }
    // 若右半段未被取完,则整串接在临时容器后面
    while(mp <= right){
        temp[index++] = nums[mp++];
    }
    // 将临时容器中的数值拷贝回原容器
    for(int k=0;k<temp.size();++k){
        nums[k+left] = temp[k];
    }
}

// 回文数:
/* 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数
 * */
bool Solution::isPalindrome(int x){
    if(x<0||(x%10==0&&x!=0)){
        return false;
    }
    int t=0;
    while(x > t){
        t = t*10 + x%10;
        x /= 10;
    }
    return x==t||t/10 == x;
}

// 正则表达式匹配:
/*
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串
 * 说明:
 * s 可能为空，且只包含从 a-z 的小写字母
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *
 * */
bool Solution::isMatch_Re(string s, string p) {
    // 建立一个空间存储每个匹配节点
    bool dp[s.length()+1][p.length()+1];
    dp[0][0]=true;
    //更新周围行,标出连续a*a*a*....
    for(int i=0;i<p.length();i++){
        dp[0][i + 1] = p[i] == '*' && dp[0][i - 1];
    }
    //列置空为0
    for(int i=1;i<s.length()+1;i++){
        dp[i][0]=false;
    }
    // 遍历匹配字符串
    for(int i=0;i<s.length();i++){
        // 遍历模式字符串
        for(int j=0;j<p.length();j++){
            // 如果匹配上，即模式串中字符一样或是.
            if(s[i]==p[j] || p[j]=='.'){
                // 匹配成功则同时延长，即s的前i个可以由p前j个匹配
                dp[i+1][j+1]=dp[i][j];
            }else if(p[j]=='*'){
                // 匹配失败，则判断是否为x*格式，故判断之前的一个是否相等
                if(p[j-1]!=s[i] && p[j-1]!='.'){
                    //　如果之前的不匹配，则跳过此位置表示s前i个，可以有p的前j-2个匹配
                    dp[i+1][j+1]=dp[i+1][j-1];
                }else{
                    // 之前可以匹配，则判断附近几个是否匹配，有一个匹配即可
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j] || dp[i + 1][j - 1];
                }
            }else{
                // 匹配不上则此位置将自己置为否
                dp[i+1][j+1]=false;
            }
        }
    }
    // 返回最后一个的匹配情况，即s的前length个是否匹配p的前length个
    return dp[s.length()][p.length()];
}

// 盛水最多的容器
/* 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai)
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水
 * X   X
 * X-X-X-------X
 * X-X-X-X---X-X
 * X-X-X-X-X-X-X
 * 横线部分为水，图示为第一和最后一个之间的水
 * */
int Solution::maxArea(vector<int> &height) {
    // 初始化两个变量分别用于存储最大值，和每次算出来的值
    int max=0,temp=0;
    // 创建两个指针，一个指向首元素，一个指向尾元素
    int p=0,q= static_cast<int>(height.size())-1;
    // 两个指针相遇时结束判断
    while(p < q){
        // 初始化为长方形的长
        temp = q-p;
        // 较矮的一边为宽，相乘并且将对应短边指针向内靠拢
        temp *= height[p] < height[q]?height[p++]:height[q--];
        // 判断是否更新最大值
        max = max > temp?max:temp;
    }
    return max;
}

// 整数转罗马数字
/* 罗马数字包含以下七种字符:
 * I V X  L  C   D   M
 * 1 5 10 50 100 500 1000
 * 特例:4-IV 9-IX 40-XL 90-XC 400-CD 900-CM
 * 输入数字范围1-3999
 * */
string Solution::intToRoman(int num) {
    // 建立转换表按顺序IXCMVLD排序
    string s,p("IXCMVLD");
    // 记录下当前权重,sign记录罗马数字权重,temp用于存储临时变量
    int flag = 1000,sign=4,temp;
    // 输入值为0-3999运行程序
    while(num > 0&&num<4000){
        // 判断权的系数，并将之减去，权重下降
        temp = num/flag;
        num -= temp*flag;
        flag /=10;
        --sign;
        // 系数为0则不进行处理
        if(!temp){
            continue;
        }
        // 将4,9与其他数字分开，四九由两个罗马数字组成，判断两次根据权重使用什么罗马数字
        if(temp%5==4){
            s += p[sign];
            s += temp==9?p[sign+1]:p[sign+4];
        }else{
            // 若大于5，则输出5的部分并减去5
            if(temp>=5) {
                s += p[sign+4];
                temp -= 5;
            }
            // 将剩余部分重复temp次，此处用string直接初始化一定数量的相同字符构成的字符串
            s += string(temp,p[sign]);
        }
    }
    return s;
}

// 罗马数字转整数
/* 罗马数字包含以下七种字符:
 * I V X  L  C   D   M
 * 1 5 10 50 100 500 1000
 * 特例:4-IV 9-IX 40-XL 90-XC 400-CD 900-CM
 * 输出数字范围1-3999
 * */
int Solution::romanToInt(const string& s) {
    // 转换表,标明每个罗马数字的权重
    map<char,int> m{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    // sum为总和即结果，p看做为指针
    int sum=0,p= static_cast<int>(s.size())-1;
    // 循环判断,若小于之前判断的一个则自身被减去
    while(p>=0){
        sum += s[p]==s.size()-1||m[s[p+1]]<=m[s[p]]?m[s[p]]:-m[s[p]];
        --p;
    }
    return sum;
}

// 最长公共前缀
/* 编写一个函数来查找字符串数组中的最长公共前缀
 * 如果不存在公共前缀，返回空字符串 ""
 * 示例：
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * */
string Solution::longestCommonPrefix(vector<string> &strs) {
    // 若提供的容器为空则直接返回空串
    if(strs.empty()){ return "";}
    // 取出第一个
    auto p = strs[0];
    // 遍历容器,并进行比较,p字串会越变越短,遍历完成后剩余的p即答案
    for(const auto& i:strs){
        for(int j=0;j<i.size();++j){
            // 不等则截断p
            if(p[j]!=i[j]){
                p = string(p.begin(),p.begin()+j);
                break;
            }
            // i遍历到尾部直接将其赋值给p
            if(j==i.size()-1){
                p = i;
                break;
            }
        }
    }
    return p;
}

// 三数之和
/* 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c
 * 使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组
 * 注意：答案中不可以包含重复的三元组
 * */
// 三数之和120ms算法
vector<vector<int>> Solution::threeSum_1(vector<int> &nums) {
    // 排序算法,内置排序，类似于快排,时间复杂度为N*log2N
    sort(nums.begin(),nums.end());
    int le=nums.size();
    // 存储结果的容器
    vector<vector<int>> sp;
    int i=0;
    // 由于是三个数,只需从0遍历到n-2
    while(i<le-2&&nums[i]<=0){
        int times =1;
        // 判断与此时取得的数字相同的个数
        while(i+times < le&&nums[i+times]==nums[i]){
            ++times;
        }
        // 构造[nums[i],X,X]结构的结果,因此可以排除重复--只要nums[i]不同，在排好序前提下不会出现重复
        if(times >=1){
            int left = i+1;
            int right = le-1;
            // 定一个值,剩余部分两端使用指针,左指针指向nums[i]的下一个,右指针指向倒数第一个值,同时向内收缩
            while(left!=right){
                if(nums[left]==nums[i]){
                    ++left;
                    continue;
                }
                // 判断和的大小
                int temp = nums[i]+nums[left]+nums[right];
                if(temp > 0){
                    // 若大于0,右指针向左移动
                    --right;
                }else if(temp < 0){
                    // 若小于0,左指针向右移动
                    ++left;
                }else{
                    // 若等于0，左指针移到下一个值(跳过重复),右指针重置
                    sp.push_back({nums[i],nums[left],nums[right]});
                    int jump = nums[left];
                    while(left<le-1&&jump==nums[left]){
                        ++left;
                    }
                    right = le -1;
                }
            }
        }
        // 定两个值,均为自身,从剩下与自己不相等的数字中找到一个与自己相加为0
        if(times >=2){
            for(int k=i+times;k<le&&nums[k]+2*nums[i]<=0;++k){
                if(nums[k]+2*nums[i]==0){
                    sp.push_back({nums[i],nums[i],nums[k]});
                    break;
                }
            }
        }
        // 定3个值,若和为0,仅当都为0成立
        if(times>=3&&nums[i]==0){
            sp.push_back({0,0,0});
        }
        // 进入下一个值的判断
        i += times;
    }
    return sp;
}
// 三数之和50ms算法
vector<vector<int>> Solution::threeSum_2(vector<int> & nums) {
    // 重拍,从小到大
    sort(nums.begin(),nums.end());
    vector<vector<int>> sp;
    int n=nums.size();
    // 对于每个元素执行操作,由于3个数,到end-3处终止
    for(auto i=nums.begin();i!=nums.end()-2;){
        // 若第一个值大于0,则三个数必定大于0，跳出循环
        if(*i > 0){ break;}
        auto st = i+1;
        auto en = nums.end()-1;
        // 从第i+1个数判断到第end-1个数
        while(st < en){
            // 若最右端小于0,则和必定小于0,跳出循环
            if(*en < 0){break;}
            // 与0进行比较
            if(*st+*en+*i>0){
                // 大于0,指针向前跳过所有一样的数
                int temp =*en;
                while(en!=st&&temp==*en){
                    --en;
                }
            }else if(*st+*en+*i<0){
                // 小于0,指针向后跳过所有一样的数
                int temp = *st;
                while(en!=st&&temp==*st){
                    ++st;
                }
            }else{
                // 等于0,指针向内移动,两端各跳过所有一样的数
                int temp1 = *st;
                int temp2 = *en;
                sp.push_back({*i,*st,*en});
                while(en!=st&&temp1==*st){
                    ++st;
                }
                while(en!=st&&temp2==*en){
                    --en;
                }
            }
        }
        // 将与自身相同的数跳过(若处理则结果重复)
        int temp = *i;
        while(i!=nums.end()-2&&*i==temp){
            ++i;
        }
    }
    return sp;
}

// 最接近的三数之和
/* 给定一个包括 n 个整数的数组 nums 和 一个目标值 target
 * 找出 nums 中的三个整数，使得它们的和与 target 最接近,返回这三个数的和
 * 假定每组输入只存在唯一答案
 * */
int Solution::threeSumClosest(vector<int>& nums, int target) {
    // 重新排序后,采用定一个值,两指针的解法
    sort(nums.begin(),nums.end());
    int min = nums[0]+nums[1]+nums[2]-target,res=nums[0]+nums[1]+nums[2];
    min = min > 0?min:-min;
    // 遍历容器中每个元素
    for(auto i = nums.begin();i!=nums.end()-2;){
        auto st = i+1;
        auto en = nums.end()-1;
        // 在i之后固定两指针向内收缩
        while(st < en){
            int fix = *i+*st+*en-target;
            // 若三数之和与target差值为0,则找不到任何一个更小差值了,返回三数之和
            if(fix==0){ return target;}
            if(fix < 0){
                // 若差值小于0则将左指针向右移动,使其逼近于0,若差值小于目前记录的最小值,则更新和与差值
                if(-fix < min){
                    min = -fix;
                    res = fix+target;
                }
                // 跳过重复值
                int left = *st;
                while(st!=en&&*st==left){
                    ++st;
                }

            }else if(fix > 0){
                // 若差值大于0,则将左指针向右移动,使其逼近于0,若差值小于目前记录的最小值,则更新和与差值
                if(fix < min){
                    min = fix;
                    res = fix+target;
                }
                // 跳过重复值
                int right = *en;
                while(en!=st&&*en==right){
                    --en;
                }
            }
        }
        // 跳过重复值
        int temp = *i;
        while(i<nums.end()-2&&temp==*i){
            ++i;
        }
    }
    return res;
}

// 电话号码的字母组合
/* 给定一个仅包含数字 2-9 的字符串,返回所有它能表示的字母组合
 * 给出数字到字母的映射如下(与电话按键相同)注意1不对应任何字母
 * 2:"abc",3:"def",4:"ghi",5:"jkl",6:"mno",7:"pqrs",8:"tuv",9:"wxyz"
 * */
vector<string> Solution::letterCombinations(string digits) {
    // 制作一个映射表'2'->0->"abc",其中'2'-50 = 0,2-9依次排下去
    vector<string> s{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"},p{""};
    // 依次判断digits中的数字字符将其映射为字符串
    auto st=digits.begin();
    while(st!=digits.end()){
        vector<string> q;
        // 从前几个数字字符所构成的字符串中取出一个进行下一个数字的追加
        for(const auto& j:p){
            // 取出从映射表中取出字符串，并逐个处理追加到之前字符串的后面
            for(auto i:s[*st-50]){
                // 存储到一个容器
                q.push_back(j+i);
            }
        }
        // 添加后的vector进行传回
        p=q;
        ++st;
    }
    return p;
}

// 四数之和
/* 给定一个包含 n 个整数的数组 nums 和一个目标值 target
 * 判断 nums 中是否存在四个元素 a,b,c 和 d,使得 a + b + c + d 的值与 target 相等?
 * 找出所有满足条件且不重复的四元组
 * */
vector<vector<int>> Solution::fourSum(vector<int>& nums, int target){
    // 算法参照Solution::threeSum解法,为三数之和拓展版,采用先固定一个数改为三数之和问题
    vector<vector<int>> res;
    if(nums.size()<4){ return res;}
    // 排序有助于去除重复结果
    sort(nums.begin(),nums.end());
    // 固定一个值用i作为迭代器
    for(auto i = nums.begin();i!=nums.end()-3;){
        // 固定第二个值用j作为迭代器
        for(auto j=i+1;j!=nums.end()-2;){
            // 使用双指针,分别指向第二个数的下一个,与整个数列的最后一个
            auto left = j+1;
            auto right = nums.end()-1;
            // 指针相遇结束判断
            while(left < right){
                // 判断四数之和与target直接关系
                if(*i+*j+*left+*right-target>0){
                    // 若大于则右侧指针向左移动至下一个不相等的数字
                    auto temp_r = *right;
                    while(right!=left&&*right==temp_r){
                        --right;
                    }
                }else if(*i+*j+*left+*right-target<0){
                    // 若小于则左侧指针向右移动至下一个不相等的数字
                    auto temp_l = *left;
                    while(right!=left&&*left==temp_l){
                        ++left;
                    }
                }else{
                    // 若等于则将答案加入结果,两侧指针同时收缩到下一个不相等的值
                    res.push_back({*i,*j,*left,*right});
                    auto temp_r = *right;
                    auto temp_l = *left;
                    while(right!=left&&*right==temp_r){
                        --right;
                    }
                    while(right!=left&&*left==temp_l){
                        ++left;
                    }
                }
            }
            // 移动第二个固定点
            auto temp_j = *j;
            while(j!=nums.end()-2&&*j==temp_j){
                ++j;
            }
        }
        // 移动第一个固定点
        auto temp_i = *i;
        while(i!=nums.end()-3&&*i==temp_i){
            ++i;
        }
    }
    return res;
}

//删除链表的倒数第N个节点
/*给定一个链表,删除链表的倒数第 n 个节点,并且返回链表的头结点
 * 链表结构
 *  struct ListNode{
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 *  };
 * */
ListNode* Solution::removeNthFromEnd(ListNode* head, int n){
    // 创建一个哑节点,避免讨论删除头结点情况
    auto *p=new ListNode(0);
    p->next = head;
    // 先让一个指针移动N位,然后两指针保持间距同时向后移动
    auto *st=head;
    auto *en=p;
    // 前面指针先移动N位
    while(n>0){
        st = st->next;
        --n;
    }
    // 两指针同时移动,直到前一指针移动到末尾
    while(st!= nullptr){
        st = st->next;
        en = en->next;
    }
    // 替换后面一指针的next节点为下一节点的next节点地址
    auto temp = en->next;
    en->next = temp->next;
    // 释放被删除的节点
    delete temp;
    // 从哑节点下一个开始返回,因此返回p->next
    return p->next;
}

// 有效的括号
/* 给定一个只包括 '('，')','{'，'}','['，']' 的字符串,判断字符串是否有效
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合
 * 左括号必须以正确的顺序闭合
 * 注意空字符串可被认为是有效字符串。
 * */
bool Solution::isValid(const string& s) {
    // 创建一个vector<char>作为存储字符的栈使用
    vector<char> res;
    // 逐个判读,若栈的最后一个字符,与新取得的字符能成一对括号,则将最后一字符弹出,否则将新字符插入
    for(char i : s){
        if(!res.empty()&&((*res.rbegin()=='('&&i==')')||(*res.rbegin()=='{'&&i=='}')||(*res.rbegin()=='['&&i==']'))){
            res.pop_back();
        }else{
            res.push_back(i);
        }
    }
    // 若栈中不存在字符串中括号完全配对,否则则说明不能完全配对，存在剩余字符
    return res.empty();
}

// 括号生成
/* 给出 n 代表生成括号的对数
 * 请你写出一个函数,使其能够生成所有可能的并且有效的括号组合
 * 结果中不存在重复
 * */
// 算法1:回溯法-->递归
vector<string> Solution::generateParenthesis_1(int n) {
    vector<string> res;
    if(n==0){return res;}
    recursion4generateParenthesis_1(res,"",0,0,n);
    return res;
}
// 括号生成算法1:回溯法的递归函数,传需要修改的值时采用引用而非传值
void Solution::recursion4generateParenthesis_1(vector<string>& res, const string& temp, int left, int right, int max){
    if(temp.size()==2*max){
        // 如果长度达到一定长度则将其添加到存储答案的容器中
        res.push_back(temp);
        return;
    }
    // 如果左括弧未达到最大值,末尾可以添加一个左括号'('
    if(left < max){
        recursion4generateParenthesis_1(res,temp+'(',left+1,right,max);
    }
    // 如果右括弧小于左括号,末尾可以添加一个右括号')'
    if(right<left){
        recursion4generateParenthesis_1(res,temp+')',left,right+1,max);
    }
}
// 算法2:闭包数法-->递归
vector<string> Solution::generateParenthesis_2(int n) {
    // 若长度为空则返回一空串
    if(n==0){
        return vector<string>{""};
    }
    // 存储答案的res
    vector<string> res;
    // 使左串长度增长,长度为i,最大为n-1,右串与之互补,长度为n-1-i,后将其放置在括号(left)right对应位置处
    for(int i=0;i<n;++i){
        // 遍历左串长度为i的情况,逐个取出为left
        for(const auto& left:generateParenthesis_2(i)){
            // 遍历左串长度为i的情况,逐个取出为right
            for(const auto& right:generateParenthesis_2(n-1-i)){
                // 将其连接起来并加入到答案中
                string temp;
                temp += "(";
                temp += left;
                temp += ")";
                temp += right;
                res.push_back(temp);
            }
        }
    }
    return res;
}

// 合并K个排序列表
/* 返回合并后的排序链表
 * */
// 暴力法:将给定链表进行直接串联,取出节点的值,进行整体排序,在合成链表上进行赋值,返回其首节点
ListNode* Solution::mergeKLists_1(vector<ListNode *>& lists) {
    // 若未给任何链表,则直接返回空指针
    if(lists.empty()){return nullptr;}
    // 新建一个哑节点,避免所给链表中出现nullptr
    ListNode head(0);
    ListNode *p=&head;
    // 存储所有的数字
    vector<int> s;
    // 遍历链表,遍历过程中,若节点存在则将节点的值存入vector中,当到达每个链表结尾时,进行续接
    for(auto & list : lists){
        // 新链表地址为空则跳过,不为空则接在上一节点之后,并将链表指针后移
        if(list!= nullptr){
            p->next = list;
            p=p->next;
        }else{
            continue;
        }
        // 遍历取出值,在短链的最后一个值进行跳出
        while(p!= nullptr){
            s.push_back(p->val);
            if(p->next){
                p=p->next;
            }else{
                break;
            }
        }
    }
    // 排序
    sort(s.begin(),s.end());
    // 链表指针重置为首地址,将排序后链表值填入
    p=head.next;
    int i=0;
    while(p!= nullptr){
        p->val=s[i];
        p=p->next;
        ++i;
    }
    // 返回链表首地址(去除哑结点)
    return head.next;
}
// 分治法:将相邻两个链表合并排序,多次执行直到仅剩1条链
ListNode* Solution::mergeKLists_2(vector<ListNode *>& lists){
    if(lists.empty()){ return nullptr;}
    int dx = 1;
    int le = lists.size();
    while(dx<le){
        for(int l=0;l<le;l+=2*dx){
            if(l+dx<le){
                lists[l] = mergeTwoLists(lists[l],lists[l+dx]);
            }
        }
        dx *= 2;
    }
    return lists[0];
}
// 分治法采用的双链按序原位合并(合并两个有序链表)
ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode head(0);
    ListNode* p=&head;
    // 合并链,若两条链都有数值则进行比较,否则直接接在后面
    while(l1||l2){
        if(l1&&l2){
            if(l1->val < l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }else{
            while(l1){
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            while(l2){
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
    }
    // 剔除哑结点进行返回
    return head.next;
}

// 两两交换链表中的节点
/* 给定一个链表,两两交换其中相邻的节点,并返回交换后的链表
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换
 * */
// 迭代法,分别标记要交换的两节点以及前驱节点,交换节点完成后前驱节点移动到下一组的前驱节点位置
ListNode *Solution::swapPairs_1(ListNode *head) {
    // 创建哑结点
    ListNode temp(0);
    temp.next = head;
    // 设置初始前驱节点,首先设定在哑结点处
    ListNode *p=&temp;
    // 记录要交换的两个节点
    ListNode *left= nullptr,*right= nullptr;
    // 若剩余两个及其以上则进行交换并移动前驱节点,否则不交换
    while(p->next&&p->next->next){
        left=p->next;
        right=left->next;
        left->next = right->next;
        right->next = left;
        p->next = right;
        p = left;
    }
    // 剔除哑结点进行返回
    return temp.next;
}
// 递归法,两两判断,将后面所有的传入进行递归
ListNode *Solution::swapPairs_2(ListNode *head) {
    // 若节点数为0或者1则直接原样返回
    if(!head||!head->next){
        return head;
    }
    // 取出待交换两节点
    ListNode *left=head,*right=head->next;
    // 将右侧节点之后的进行递归再次判断,将交换之后的接在左侧节点之后,右侧节点指向左侧节点,完成交换
    left->next = swapPairs_2(right->next);
    right->next = left;
    // 返回头结点,即原来第二个节点
    return right;
}

// K个一组翻转链表
/* 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表
 * k 是一个正整数，它的值小于或等于链表的长度
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序
 * */
// 利用栈原理,使用一个容器进行存储,再反向链接
ListNode *Solution::reverseKGroup_1(ListNode *head, int k) {
    // 建立存储节点的容器
    vector<ListNode*> temp(k);
    ListNode *p = head;
    // 将节点按序存入容器
    int t=0;
    while(t<k&&p){
        temp[t++] = p;
        p=p->next;
    }
    // 判断容器是否填满,若填满则进行倒置,若未填满则直接返回原链
    if(t==k){
        // 将剩余部分通过递归继续分块翻转,再续接到取出的链表块的第一个节点之后
        temp[0]->next = reverseKGroup_1(temp[k-1]->next,k);
        // 将容器内数值反向输出为链表
        while(t>1){
            temp[t-1]->next = temp[t-2];
            --t;
        }
        // 头结点即为链表块的最后一个节点
        return temp[k-1];
    }else{
        return head;
    }
}
// 使用递归进行翻转被分块的链表
ListNode *Solution::reverseKGroup_2(ListNode *head, int k) {
    // 创建指针并将指针指向链表块的最后一个节点
    ListNode *p = head;
    int t=0;
    while(t<k-1&&p){
        p = p->next;
        ++t;
    }
    // 若取到成功取得一整块链表,则进行翻转操作
    if(t==k-1&&p){
        // 将此区块之后的利用递归进行翻转,结果保存为temp
        ListNode *temp = reverseKGroup_2(p->next,k);
        // 将此区块的最后一个节点置空执行翻转操作
        p->next = nullptr;
        auto reverseChain = reverseLists(head);
        // 在翻转后的链的末尾加上此区块后面的链表
        ListNode *m = reverseChain;
        while(m->next){
            m = m->next;
        }
        m->next = temp;
        // 返回翻转了区块的链表
        return reverseChain;
    }else{
        return head;
    }
}
// 翻转整个链表
ListNode *Solution::reverseLists(ListNode *head) {
    // 若链表长度为0或1则直接返回原链表
    if(!head||!head->next){
        return head;
    }
    // 创建要反向的两个节点的指针和右节点的下一个节点的翻转链头指针
    ListNode *left = head;
    ListNode *right = head->next;
    ListNode *en = right->next;
    head->next = nullptr;
    // 将左链接到右节点上,将左节点指针移动到链的头部,右节点指针和带翻转链头指针向后移动
    while(en){
        right->next = left;
        left = right;
        right = en;
        en = en->next;
    }
    // 当右节点指针到达末尾时,将左链接在右节点之后,并返回右节点
    right->next = left;
    return right;
}

// 删除排序数组中的重复项
/* 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度
 * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成
 * */
// 算法：双指针+上一个值的记录
int Solution::removeDuplicates(vector<int> &nums) {
    // 数组为空则返回0
    if(nums.empty()){
        return 0;
    }
    // 初始化双指针在第二个数,上一个值记录为第一个数
    int left=1,right,max=nums[0],le=nums.size();
    // 循环判断,若右指针所指的值与上一个取得的值不相等则插入到左指针处,若插入则左指针后移
    for(right=1;right<le;++right){
        if(nums[right]!=max){
            max = nums[right];
            nums[left++] = max;
        }
    }
    return left;
}

// 移除元素
/* 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度
 * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成
 * 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素
 * */
int Solution::removeElement(vector<int> &nums, int val) {
    int left=0,right,le=nums.size();
    // 循环判断,若右指针所指的值与待删除的值不相等则插入到左指针处,若插入则左指针后移
    for(right=0;right<le;++right){
        if(nums[right]!=val){
            nums[left++] =nums[right];
        }
    }
    return left;
}

// 实现strStr()
/* 给定一个 haystack 字符串和一个 needle 字符串
 * 在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)
 * 如果不存在，则返回 -1。
 * */
// 暴力搜索,效率低重复判断多,时间复杂度O(MN)
int Solution::strStr_1(const string& haystack, const string& needle) {
    if(needle.empty()){
        return 0;
    }
    int flag = 1;
    // 逐个比较,如果第一个字符匹配则查看之后字符是否匹配,不匹配则重新进行匹配第一个字母
    for(int i=0;i<haystack.size();++i){
        for(int j=0;j<needle.size();++j){
            if(haystack[i+j]!=needle[j]){
                flag = 0;
                break;
            }
        }
        // 若匹配完整个待搜索字符串,则flag应为1,返回此时的下标
        if(flag){
            return i;
        }
        flag = 1;
    }
    return -1;
}
// KMP算法,避免了反复回退,时间复杂度为O(N),先制作一个自身的映射,根据映射合理回退带匹配的字符串,辅助函数next_map
int Solution::strStr_2(const string &haystack, const string &needle) {
    // 若带匹配字符串为空则返回0
    if(needle.empty()){
        return 0;
    }
    int k=0;
    // 生成公共前后缀长度表,link[i]表示待匹配字符串前i个字符中公共的前后缀字符串长度大小
    vector<int> link = next_map(needle);
    // 扫描待搜索字符串,若其相等则待匹配字符串指针后移,否则由后缀跳到前缀位置,减少不必要的判断
    for(auto i=0;i<haystack.size();++i){
        // 若待匹配字符串指针不为第一个且判断不相等,则进行向前跳转
        while(k>0&&haystack[i]!=needle[k]){
            k = link[k-1];
        }
        // 若相等,待匹配字符串指针后移
        if(haystack[i]==needle[k]){
            ++k;
        }
        // 若已经匹配完成则进行返回
        if(k==needle.size()){
            return i-k+1;
        }
    }
    // 若未搜索到则返回-1
    return -1;
}
// KMP算法辅助函数,用于生成待匹配字符串的最长公共前后缀长度,用数组进行记录
vector<int> Solution::next_map(string p) {
    int le = p.size(),k=0;
    vector<int> table(le);
    // 前0个字符匹配固定为0
    table[0] = 0;
    // 进行扫描,若前指针等于尾指针处的值,则将k自增1并赋值给数组对应位置
    for(int i=1;i<le;++i){
        // 若满足条件这说明需要向前跳转,因此查看前一个的跳转位置
        while(k>0&&p[k]!=p[i]){
            k = table[k-1];
        }
        // 相等则公共前后缀长度自增1
        if(p[k]==p[i]){
            ++k;
        }
        table[i] = k;
    }
    return table;
}

// 两数相除
/* 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符
 * 返回被除数 dividend 除以除数 divisor 得到的商
 * 被除数和除数均为 32 位有符号整数
 * 除数不为 0
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是[INT_MIN, INT_MAX]
 * 本题中，如果除法结果溢出，则返回INT_MAX
 * */
int Solution::divide(int dividend, int divisor) {
    // 若被除数为0或者除数为1则直接返回被除数
    if(dividend==0||divisor==1){
        return dividend;
    }
    // 若被除数为限且除数为-1则会溢出,直接返回INT_MAX
    if(dividend==INT_MIN&&divisor==-1){
        return INT_MAX;
    }
    // 记录符号,全部转负后处理符号使用
    int flag = 1;
    if(dividend > 0){
        flag = 0-flag;
        dividend = 0-dividend;
    }
    if(divisor>0){
        flag = 0-flag;
        divisor = 0-divisor;
    }

    int bdv = divisor; // 翻倍用
    int count = 1; // 记录翻倍后相对于初始值的倍数
    int res = 0; // 记录总数
    // 递减的数字每减一次进行一次翻倍,若超过限定值,则重新从最小开始翻倍,减的次数即答案
    while(dividend <= divisor){
        if(dividend - bdv> divisor){
            bdv = divisor;
            count = 1;
        }
        dividend -= bdv;
        res += count;
        if(bdv > INT_MIN/2){
            bdv = bdv + bdv;
            count = count + count;
        }
    }
    // 若不为号则进行取负数
    if(flag==-1){
        res = 0-res;

    }
    return res;
}

// 串联所有单词子串
/* 给定一个字符串 s 和一些长度相同的单词 words
 * 找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序
 * */
// 采用窗口按单词判断,若出现了指定次数则进行添加开始位置
vector<int> Solution::findSubstring(const string& s, vector<string> &words) {
    // 存储答案的下标
    vector<int> res;
    // 若s或words为空则返回一个空的结果
    if (s.empty() || words.empty()) {
        return res;
    }
    // 取得单词数量word_count,单词长度one_word,待搜索s的长度s_len,窗口大小win_len
    int word_count = words.size();
    int one_word = words[0].size();
    int s_len = s.size();
    // int win_len = word_count * one_word;
    unordered_map<string, int> refer;
    for (const auto& word : words) {
        ++refer[word];
    }
    // 从第一个单词的不同位置开始,以避免长度不同而导致的漏掉结果
    for (int i = 0; i < one_word; ++i) {
        // 窗口左指针left,右指针right,计数器count
        int left = i, right = i,count=0;
        // 用于记录当前窗口中的各个单词数量
        unordered_map<string, int> sign;
        // 循环向后判断,直至最后没有单词
        while (right + one_word <= s_len) {
            // 取出单词放入窗口
            string temp = s.substr(right, one_word);
            right += one_word;
            // 取得的单词不存在待选单词中,则进行清空sign,count置零,left移动至right处
            if (refer[temp] == 0) {
                count = 0;
                left = right;
                sign.clear();
            }
            else{
                // 取词成功,进行增加,若取完词之后大于所给数量则left右移以去除重复单词
                ++count;
                ++sign[temp];
                while (sign[temp] > refer[temp]) {
                    string po = s.substr(left, one_word);
                    --count;
                    left += one_word;
                    --sign[po];
                }
                // 若窗口中的单词数量与所给数量一致则将窗口开始下标加入到结果中
                if (count == word_count) {
                    res.push_back(left);
                }
            }
        }
    }
    return res;
}

// 下一个排列
/* 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）
 * 必须原地修改，只允许使用额外常数空间
 * 思路:若为最大值我们需要检测师傅为递减
 * 若不为递减,将递减部分的前一个数值进行增大,从递减部分找一个较大的值进行替换
 * 后逆序成递增达到扩大之后的最小值
 * 如：4132,只能通过增加1的大小来增大数值,因此从32中选一个大于1的最小值进行替换
 * 变换成4231此时并不是以42开头的最小数,因此将31逆序变成4213即大于4132的下一个数
 * */
void Solution::nextPermutation(vector<int> &nums) {
    // 为空不进行操作
    if(nums.empty()){
        return;
    }
    // 取得数组长度,从后向前两个两个进行比较,若前一个比后一个小则停止,指针指向较小的那个数
    int le = nums.size();
    int st=le-2;
    while(st>=0&&nums[st]>=nums[st+1]){
        --st;
    }
    // 若指针停留在第0个的前一个,说明整个数组递减,此时跳过
    if(st!=-1){
        int temp = nums[st];
        int en = le-1;
        // 从后向前取,取得第一个大于nums[st]的值
        while(en>st&&nums[en] <= temp){
            --en;
        }
        // 将较大的那个值与nums[st]进行交换
        my_swap(nums[st],nums[en]);
    }
    // 将所取的st指针后方的所有值进行翻转
    int l = st+1;
    int r = le-1;
    while(r>l){
        my_swap(nums[l],nums[r]);
        ++l;
        --r;
    }
}
// 交换两个值,内联函数,辅助简化书写
inline void Solution::my_swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}

// 最长有效括号
/* 给定一个只包含 '(' 和 ')' 的字符串
 * 找出最长的包含有效括号的子串的长度。
 * */
// 栈辅助,利用弹栈时的差的最大值获取最大长度,较为玄学
int Solution::longestValidParentheses_1(const string& s) {
    int max=0;
    // 建立栈预先压入-1
    vector<int> stackTemp;
    stackTemp.push_back(-1);
    for(int i=0;i<s.size();++i){
        if(s[i]=='('){
            // 遇到左括号直接压入
            stackTemp.push_back(i);
        }else{
            // 遇到右括号直接先弹出原有的值,若为空则将自己置入,否则计算长度,保证里面总有一个值
            stackTemp.pop_back();
            if(stackTemp.empty()){
                stackTemp.push_back(i);
            }else{
                int t = *stackTemp.rbegin();
                max = i-t> max?i-t:max;
            }
        }
    }
    return max;
}
// 动态规划,利用数组存储每个字符之前所能构成的有效扩号长度
int Solution::longestValidParentheses_2(const string &s) {
    int le = s.size();
    // 动规数组,dp[i]表示以第i位结尾的有效括号长度
    vector<int> dp(le,0);
    int max = 0;
    // 由于第一位是'('还是')',其dp[0]=0,直接从第二个括号开始判断
    for(int i=1;i<le;++i){
        // 如果是右括号,判断前一位的括号
        if(s[i]==')'){
            // 若组成'()'则将'X()'中X处的有效括号长度加2赋值给此时的dp[i]
            if(s[i-1]=='('){
                dp[i] = (i>1?dp[i-2]:0)+2;
            }else if(i>dp[i-1]&&s[i-dp[i-1]-1]=='('){
                // 若组成'))'则判断前方有效括号的另一端是否为'(',若是则将这对有效括号的前面和中间两串有效括号连接起来
                dp[i] = dp[i-1]+(i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0)+2;
            }
        }
        // 修改dp[i]完成后,进行判断是否更新最大值
        max = dp[i]>max?dp[i]:max;
    }
    return max;
}
// 双向遍历,分别计算两个方向的有效括号长度,取较大值
int Solution::longestValidParentheses_3(const string &s) {
    // 初始化一个left和right用于记录左右括号数量,和记录最大值的max
    int right=0,left=0,max=0;
    // 正向判断,若右括号大于左括号数量,则进行重置,如果相等则进行计算最大值
    for(char i : s){
        // 计数
        if(i=='('){
            ++left;
        }else{
            ++right;
        }
        // 判断是否应该重置,否则进行计算最大值
        if(right > left){
            right = 0;
            left = 0;
        }else if(right==left){
            max = 2 * right > max ? 2 * right : max;
        }
    }
    left = right = 0;
    // 反向判断同正向
    for(auto i=s.rbegin();i!=s.rend();++i){
        // 计数
        if(*i=='('){
            ++left;
        }else{
            ++right;
        }
        // 判断是否应该重置,否则进行计算最大值
        if(right < left){
            left = right = 0;
        }else if(right==left){
            max = 2 * right > max ? 2 * right : max;
        }
    }
    return max;
}

// 搜索旋转排序数组
/* 假设按照升序排序的数组在预先未知的某个点上进行了旋转
 * 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2]
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1
 * 你可以假设数组中不存在重复的元素
 * 你的算法时间复杂度必须是 O(log n) 级别
 * */
// 递归,二分查找
int Solution::search(vector<int> &nums, int target) {
    if(nums.empty()){
        return -1;
    }
    int le = nums.size(),res=-1,pot=le-1;
    int st=0;
    // 二分查找查找翻转点
    while(st<=pot){
        int mid = (st+pot)/2;
        cout << mid << endl;
        if(mid<le-1&&nums[mid]>nums[mid+1]){
            pot = mid;
            break;
        }else{
            if(nums[mid] < nums[st]){
                pot = mid-1;
            }else{
                st = mid+1;
            }
        }
    }
    cout << pot << endl;
    // 和尾部值进行比较,即翻转前前半段的最大值,若大于最大值则在翻转点之前进行查找,否则在翻转点之后进行查找
    if(target>nums[le-1]||pot==le-1){
        res =divide_search(nums,0,pot,target);
    }else{
        res =divide_search(nums,pot+1,le-1,target);
    }
    return res;
}
// 二分查找算法,循环版
int Solution::divide_search(vector<int>& nums,int left,int right,int target) {
    while(left<=right){
        int mid = (left+right)/2;
        if(nums[mid]>target){
            right = mid-1;
        }else if(nums[mid]<target){
            left = mid+1;
        }else{
            return mid;
        }
    }
    return -1;
}

// 在排序数组中查找元素的第一个和最后一个位置
/* 给定一个按照升序排列的整数数组 nums
 * 和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置
 * 你的算法时间复杂度必须是 O(log n) 级别
 * 如果数组中不存在目标值，返回 [-1, -1]
*/
// 二分法搜索第一个大于等于target的值,搜索第一个大于target的值
vector<int> Solution::searchRange(vector<int>& nums, int target){
    vector<int> res(2,-1);
    // 先查一个大于等于target的值,若不存在则返回{-1,-1}
    int temp = search_le(nums,target, true);
    if(temp==nums.size()||nums[temp]!=target){
        return res;
    }
    // 若存在target则再查找一个大于target的值,其下标减1则为最后一个target
    res[0] = temp;
    res[1] = search_le(nums,target, false)-1;
    return res;
}
// 辅助二分查找算法,>=查找第一个等于target,>查找第一个大于target
int Solution::search_le(vector<int> &nums,int target,bool left) {
    int st=0,en=nums.size();
    while(st<en){
        int mid = (st+en)/2;
        if(nums[mid]>target||(left&&nums[mid]==target)){
            en = mid;
        }else{
            st = mid+1;
        }
    }
    return st;
}

// 面试题 10.01. 合并排序的数组
/* 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序
 * 初始化 A 和 B 的元素数量分别为 m 和 n
 * 输入:
 * A = [1,2,3,0,0,0], m = 3
 * B = [2,5,6],       n = 3
 * 输出: [1,2,2,3,5,6]
 * */
// 两两比较按序插入临时数组,排序完成复制回A
void Solution::merge(vector<int> &A, int m, vector<int> &B, int n) {
    int left=0,right=0;
    vector<int> res(m+n,0);
    while(left<m&&right<n){
        if(A[left] > B[right]){
            res[left+right] = B[right];
            ++right;
        }else{
            res[left+right] = A[left];
            ++left;
        }
    }
    while(right<n){
        res[left+right] = B[right];
        ++right;
    }
    while(left<m){
        res[left+right] = A[left];
        ++left;
    }
    for (int i = 0; i < m + n; ++i) {
        A[i] = res[i];
    }
}

// 有效的数独
/* 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可
 * 数字 1-9 在每一行只能出现一次
 * 数字 1-9 在每一列只能出现一次
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次
 * 测试用例
 * vector<vector<char>> info{
           {'5','3','.','.','7','.','.','.','.'},
           {'6','.','.','1','9','5','.','.','.'},
           {'.','9','8','.','.','.','.','6','.'},
           {'8','.','.','.','6','.','.','.','3'},
           {'4','.','.','8','.','3','.','.','1'},
           {'7','.','.','.','2','.','.','.','6'},
           {'.','6','.','.','.','.','2','8','.'},
           {'.','.','.','4','1','9','.','.','5'},
           {'.','.','.','.','8','.','.','7','9'}
   };
 * */
// 分别按行,按列,按3×3方格进行判断
bool Solution::isValidSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; ++i) {
        if(!sudokumnisValid(board,i,0,1,9)){
            return false;
        }
    }
    for (int i = 0; i < 9; ++i) {
        if(!sudokumnisValid(board,0,i,9,1)){
            return false;
        }
    }
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < 3; ++i) {
            if(!sudokumnisValid(board,3*j,3*i,3,3)){
                return false;
            }
        }
    }
    return true;
}
// 将范围内的数字字符进行计数,若存在大于1个则返回false,否则范湖true
bool Solution::sudokumnisValid(vector<vector<char>> &board, int x, int y,int dx, int dy) {
    vector<int> res(9,0);
    for (int i = 0; i < dx; ++i) {
        for (int j = 0; j < dy; ++j) {
            int temp = board[x+i][y+j];
            if(temp !='.'){
                if(res[temp-49]){
                    return false;
                }
                ++res[temp-49];
            }
        }
    }
    return true;
}
// 解数独
/* 编写一个程序，通过已填充的空格来解决数独问题
 * */
// 暴力法,对于每个空格进行填入1-9,判断是否有效,若有效则继续向下填,直到所有空格填完
void Solution::solveSudoku(vector<vector<char>> &board) {
    bool res = co_solveSudoku(board);
}
// 暴力法的递归辅助函数,若成立则进行深入,不成立则回退
bool Solution::co_solveSudoku(vector<vector<char>> &board) {
    // 找出下一个待填空格
    int left = 0, right = 0;
    for (left = 0; left < 9; ++left) {
        for (right = 0; right < 9; ++right) {
            if (board[left][right] == '.') {
                break;
            }
        }
        if (right < 9&&board[left][right] == '.') {
            break;
        }
    }
    // 到达末尾这说明解决问题,进行跳出
    if (left == 9 && right == 9 && board[left-1][right-1] != '.') {
        return true;
    }
    // 首先填入,判断是否有效,若无效则进行重新填入,若有效则判断递归的是否成立不成立则将自己置空进行回退
    bool res;
    for (int i = 0; i < 9; ++i) {
        board[left][right] = i+49;
        bool temp = isValidSudoku(board);
        if (temp) {
            res = co_solveSudoku(board);
            if(res){
                return true;
            }else{
                board[left][right] = '.';
            }
        }else{
            board[left][right] = '.';
        }
    }
    return false;
}
/* 递归-回溯法,取3个二维数组,分别记录每一行,每一列,每一个小块的内部值
 * 若所填的值在任何一个数组中,则跳过填下一个数,若填入成功,更新对应行列与小块
 * 数组初始值取初始数独表的值,若填入失败或者无数可填则进行回退
 * 此处仅记录思路
 * */
// 外观数组
/* 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 被读作  "one 1"  ("一个一") , 即 11
 * 11 被读作 "two 1s" ("两个一"）, 即 21
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
 * */
string Solution::countAndSay(int n) {
    string ori("1");
    while(n>1){
        string new_s;
        int count = 1;
        char count_c = ori[0];
        for (int i = 1; i < ori.size(); ++i) {
            if(ori[i]==count_c){
                ++count;
            }else{
                new_s += static_cast<char>(count+48);
                new_s += count_c;
                count = 1;
                count_c = ori[i];
            }
        }
        new_s += static_cast<char>(count+48);
        new_s += count_c;
        ori.swap(new_s);
        --n;
    }
    return ori;
}

// 腐烂的橘子
/* 在给定的网格中，每个单元格可以有以下三个值之一:
 * 值 0 代表空单元格
 * 值 1 代表新鲜橘子
 * 值 2 代表腐烂的橘子
 * 每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂
 * 返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1
 * */
int Solution::orangesRotting(vector<vector<int>>& grid){
    // 如果为空则返回-1
    if(grid.empty()||grid[0].empty()){
        return -1;
    }
    // 记录感染分钟,判定是否发生了感染lock为1为未发生感染,lock为0为发生了感染
    int count = 0,lock=0;
    int row = grid.size(),col = grid[0].size();
    auto temp = grid;
    // 反复执行,直到不发生感染
    while(true){
        // 判定是否有腐烂橘子如果有则进行感染,并丢弃原先腐烂的橘子,四周若有橘子则成为感染体
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if(temp[i][j]==2){
                    grid[i][j] = 0;
                    // 如果成功感染则将判定是否发生过感染的开关置为正数
                    lock += rotOranges(grid,i,j,row,col);
                }
            }
        }
        // 若未发生感染则跳出循环
        if(!lock){
            break;
        }
        // 初始化下一轮判断
        temp = grid;
        ++count;
        lock = 0;
    }
    // 判断是否还有幸存者,若存在幸存者则返回-1
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if(grid[i][j]==1){
                return -1;
            }
        }
    }
    return count;
}
// 腐烂的橘子--感染函数,判断是否超出边界,并将橘子感染
int Solution::rotOranges(vector<vector<int>>& grid, int x,int y,int row,int col) {
    int count = 0;
    if(x-1>=0&&grid[x-1][y]==1){
        grid[x-1][y]=2;
        ++count;
    }
    if(y-1>=0&&grid[x][y-1]==1){
        grid[x][y-1]=2;
        ++count;
    }
    if(x+1<row&&grid[x+1][y]==1){
        grid[x+1][y]=2;
        ++count;
    }
    if(y+1<col&&grid[x][y+1]==1){
        grid[x][y+1]=2;
        ++count;
    }
    return count;
}

// 组合总和
/* 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合
 * candidates 中的数字可以无限制重复被选取
 * */
vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> res;
    violenceSwitch(candidates,vector<int>{},target,0,res);
    return res;
}
void Solution::violenceSwitch(vector<int>& candidates,const vector<int>& numberLists,int target,int num, vector<vector<int>>& res){
    auto en = candidates.end();
    for(auto i = candidates.begin();i!=en;++i){
        auto temp = numberLists;
        if(num+*i>target){
            continue;
        }else if(num+*i==target){
            temp.push_back(*i);
            res.push_back(temp);
        }else{
            temp.push_back(*i);
            vector<int> s(i,en);
            violenceSwitch(s,temp,target,num+*i,res);
        }
    }
}

// 分糖果II
/* 排排坐，分糖果
 * 我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友
 * 给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果
 * 然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗
 * 依此类推，直到给最后一个小朋友 2 * n 颗糖果
 * 重复上述过程（每次都比上一次多给出一颗糖果，当到达队伍终点后再次从队伍起点开始）
 * 直到我们分完所有的糖果。注意，就算我们手中的剩下糖果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友
 * 返回一个长度为 num_people、元素之和为 candies 的数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i 个小朋友分到的糖果数）。
 * */
// 暴力--分发按顺序给
vector<int> Solution::distributeCandies(int candies, int num_people) {
    // 存储结果
    vector<int> res(num_people,0);
    // 该分发的个数
    int give_num=1;
    while(candies > 0){
        for (int i = 0; i < num_people; ++i) {
            // 先扣除此次要分发的糖果
            candies -= give_num;
            // 如果小于0了说明不够或刚好发完我们需要跳出,不够就把最后的都给最后一个人
            if(candies > 0){
                res[i] += give_num;
            }else{
                res[i] += candies;
                res[i] += give_num;
                break;
            }
            // 下一次分发的值
            ++give_num;
        }
    }
    // 返回结果
    return res;
}

// 和为s的连续正数数列
/* 输入一个正整数 target ，输出所有和为 target 的连续正整数序列(至少含有两个数)
 * 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
 * */
// 使用vector当做窗口
vector<vector<int>> Solution::findContinuousSequence_1(int target){
    // 记录结果
    vector<vector<int>> res;
    vector<int> getList;
    int sum = 0;
    int numList = 0;
    // 确认窗口最大值
    while(sum<target){
        getList.push_back(++numList);
        sum += numList;
    }
    // 窗口向后移动,根据和target的值的比较进行变动窗口
    while(getList.size()>1&&numList<=target/2+1){
        if(sum==target){    // 加入答案,并且窗口后移
            res.push_back(getList);
            sum -= getList[0];
            getList.erase(getList.begin());
            getList.push_back(++numList);
            sum += numList;
        }else if(sum > target){ //窗口缩短
            sum -= getList[0];
            getList.erase(getList.begin());
        }else{  // 窗口加长
            getList.push_back(++numList);
            sum += numList;
        }
    }
    return res;
}
// 使用双指针作为窗口边界,窗口内总值使用求和公式
vector<vector<int>> Solution::findContinuousSequence_2(int target){
    // 存储答案
    vector<vector<int>> res;
    int left=1,right=2;
    // 窗口左端顶多到target/2,每次循环计算窗口内数值总和
    while(left<=target/2){
        int sum = (left+right)*(right-left+1)/2;
        if(sum < target){   // 若小于,窗口右边界后移,总和变大
            ++right;
        }else if(sum > target){ // 若大于,窗口左边界后移,总和变小
            ++left;
        }else{  // 若等于,记录整个窗口,窗口整体后移
            vector<int> temp;
            for(int i = left;i<=right;++i){
                temp.push_back(i);
            }
            res.push_back(temp);
            ++left;
        }
    }
    return res;
}
// 组合总和 II
/* 给定一个数组 candidates 和一个目标数 target
 * 找出 candidates 中所有可以使数字和为 target 的组合
 * candidates 中的每个数字在每个组合中只能使用一次
 * */
// 暴力法,先进行排序,再进行选数在同一层中避免选择同一个数
vector<vector<int>> Solution::combinationSum2(vector<int>& candidates, int target){
    mergeSort(candidates);
    vector<vector<int>> res;
    violenceSwitch2(candidates,vector<int>{},target,0,res);
    return res;
}
void Solution::violenceSwitch2(vector<int>& candidates,const vector<int>& numberLists,int target,int num, vector<vector<int>>& res){
    auto en = candidates.end();
    int before=-1;
    for(auto i = candidates.begin();i!=en;++i){
        // 跳过相同的数
        if(before==*i){
            continue;
        }else{
            before = *i;
        }
        auto temp = numberLists;
        if(num+*i>target){
            continue;
        }else if(num+*i==target){
            temp.push_back(*i);
            res.push_back(temp);
        }else{
            temp.push_back(*i);
            vector<int> s(i+1,en);
            violenceSwitch2(s,temp,target,num+*i,res);
        }
    }
}

// 缺失的第一个正数
/* 给定一个未排序的整数数组，找出其中没有出现的最小的正整数
 * */
// 很容易想到若复杂度为n则需要桶排序,然而空间复杂度为1,我们不能额外创建桶,因此我们原位使用符号进行标记
int Solution::firstMissingPositive(vector<int>& nums) {
    // 检查是否含有1,若不含有则直接返回1
    int sign = 0;
    for(auto i:nums){
        if(i==1){
            sign = 1;
            break;
        }
    }
    if(sign != 1){
        return 1;
    }
    // 将大于长度的数和非正数改为1,用于简化计算
    int le=nums.size();
    for(auto &i:nums){
        if(i<=0||i>le){
            i = 1;
        }
    }
    // 数组中全为正数,若不产生新的空间,则在原位用符号标记是否存在,-号代表出现过这个数,比较时使用绝对值
    for(int i=0;i<nums.size();++i){
        int temp = nums[i] < 0?-nums[i]:nums[i];
        if(nums[temp-1]>0){
            nums[temp-1] *= -1;
        }
    }
    // 取到的第一个正数为缺失的数,若未取到则说明前面不缺失,返回n+1
    for(int i=0;i<le;++i){
        if(nums[i]>0){
            return i+1;
        }
    }
    return le+1;
}

// 接雨水
/* 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图
 * 计算按此排列的柱子，下雨之后能接多少雨水
 * */
/* 暴力法,扫描每一个柱子,在两边找一对最高的柱子,则在柱子上的蓄水量为两边较小值减去柱子高度
 * 将所有柱子上的水进行相加则为总水量
 * 时间复杂度O(n^2),空间复杂度O(1)
 * */
/* 动态规划,相对于暴力法每次向两边扫描,我们可以将两边柱子最高高度进行保存
 * 建立两个数组dp_right,dp_left用于存储最大值
 * 其中dp_right[i]代表第i个柱子的右边最大值,dp_left[i]代表柱子左边的最大值
 * 后采用暴力法过程
 * 时间复杂度O(n),空间复杂度O(n)
 * */
/* 栈:分别压入数据,若新列的高度大于前一个则说明可以填充
 * 向前弹出并且计算填充大小,知道所有的列全部扫描完成
 * */
// 双指针法,若左端存在一个大于自己的柱子则自己一定被填满
int Solution::trap(vector<int>& height){
    int le = height.size();
    int left_max=0,right_max=0,left=0,right=le-1,sum=0;
    while(left<right){
        if(height[left] < height[right]){
            if(height[left]>=left_max){
                left_max = height[left];
            }else{
                sum += left_max - height[left];
            }
            ++left;
        }else{
            if(height[right]>=right_max){
                right_max = height[right];
            }else{
                sum += right_max - height[right];
            }
            --right;
        }
    }
    return sum;
}

// 反转字符串递归法
/* 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题
 * 你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符
 * */
void Solution::reverseString(vector<char>& s){
    int le = s.size();
    reverse_coString(s,0,le-1);
}
void Solution::reverse_coString(vector<char>& s,int left,int right){
    if(left<right){
        int temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        reverse_coString(s,left+1,right-1);
    }
}

// 零钱兑换
/* 给定不同面额的硬币 coins 和一个总金额 ori
 * 编写一个函数来计算可以凑成总金额所需的最少的硬币个数
 * 如果没有任何一种硬币组合能组成总金额，返回 -1
 * */
int Solution::coinChange(vector<int>& coins, int amount) {
    int Max = amount + 1;
    vector<int> dp(amount + 1, Max);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

// 买卖股票的最佳时机
/* 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格
 * 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润
 * 注意你不能在买入股票前卖出股票
 * */
// 动态规划1--利用了dp数组,时间复杂度O(n),空间复杂度O(n)
int Solution::maxProfit_1(vector<int>& prices) {
    // 取得长度,若为0则返回0,否则创建一个dp数组,从后向前遍历,最后一个直接跳过
    int le=prices.size();
    if(le==0){
        return 0;
    }
    vector<int> dp(le,0);
    dp[le-1]=prices[le-1];
    int max = 0;
    // dp[i]内存储第i个数之后的最大值
    for(auto i=le-2;i>=0;--i){
        // 更新dp
        if(prices[i]>dp[i+1]){
            dp[i] = prices[i];
        }else{
            dp[i] = dp[i+1];
        }
        // 判断此位置的利润并且与后面取得的最大利润相比
        int temp = dp[i]-prices[i];
        max = temp>max?temp:max;
    }
    return max;
}
// 动态规划2--1的优化,时间复杂度O(n),空间复杂度O(1)
int Solution::maxProfit_2(vector<int>& prices) {
    // 取得长度,若为0则返回0
    int le=prices.size();
    if(le==0){
        return 0;
    }
    // get_num存储第i个数之后的最大值,max存储最大差值
    int get_num = prices[le-1];
    int max = 0;
    for(auto i=le-2;i>=0;--i){
        // 更新get_num
        if(prices[i]>get_num){
            get_num = prices[i];
        }
        // 判断此位置的利润并且与后面取得的最大利润相比
        int temp = get_num-prices[i];
        max = temp>max?temp:max;
    }
    return max;
}

// 二叉树的直径
/* 给定一棵二叉树，你需要计算它的直径长度
 * 一棵二叉树的直径长度是任意两个结点路径长度中的最大值
 * 这条路径可能穿过根结点
 * */
// 分别计算每个节点作为根节点时的长度,若大于max则更新max
int Solution::diameterOfBinaryTree(TreeNode* root) {
    int max=1;
    deep4Tree(root,max);
    return max-1;
}
// 计算每个根节点处的长度
int Solution::deep4Tree(TreeNode* root,int& max){
    // 根节点为nullptr返回0
    if(root==nullptr){
        return 0;
    }
    // 调用自身进行递归,在递归时已经检测了之后节点的可能性
    int left = deep4Tree(root->left,max);
    int right = deep4Tree(root->right,max);
    // 总长度为左长度加右长度加上根节点1
    int sum = left+right+1;
    // 更新最大值
    max = max>sum?max:sum;
    // 返回root节点之后的深度
    return (right>left?right:left)+1;
}

// 将数组分成和相等的三个部分
/* 给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false
 * 形式上，如果可以找出索引 i+1 < j 且满足
 * (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])
 * 就可以将数组三等分
 * */
// 将其分为三份可以先将其总和求出来取查看是否能取出来两份,再判断第三份是否为空
bool Solution::canThreePartsEqualSum(vector<int>& A){
    // 求和数组
    int sum=0;
    for(const auto &i:A){
        sum += i;
    }
    // 若不能被3平分则返回false
    if(sum%3){
        return false;
    }
    // 均分为3份
    sum /= 3;
    int index=0;
    int count = 0;
    int temp=0;
    int le=A.size();
    // 循环相加,当等于sum时计数加一,加到2时跳出循环
    while(index!=le){
        temp += A[index];
        ++index;
        if(temp==sum){
            temp=0;
            ++count;
            if(count==2){
                break;
            }
        }

    }
    // 若已经取出两份且第三份不为空则说明足以被分为三份
    return count == 2&&index!=le;
}

// 字符串相乘
/* 给定两个以字符串形式表示的非负整数 num1 和 num2
 * 返回 num1 和 num2 的乘积
 * 它们的乘积也表示为字符串形式
 * 如："12"×"5"="60"
 * */
// 列竖式进行相乘
string Solution::multiply(string num1, string num2) {
    // 任意一个值为零则结果必定为0
    if(num1=="0"||num2=="0"){
        return "0";
    }
    // m位和n位相乘最长是m+n位,创建一个长为m+n的字符串进行存储
    int l1=num1.size();
    int l2=num2.size();
    string res(l1+l2,'0');
    // 存储进位
    int over_sign=0;
    // 取出num1的一个数分别于num2中的每个相乘
    for(int i=l1-1;i!=-1;--i){
        int left=num1[i]-48;
        for (int j = l2-1; j>=0; --j) {
            int right=num2[j]-48;
            // 更新竖式的第i+j+1位,将原先的值,进位值,乘积值进行相加取个位数,其他作为进位
            int temp = left*right+over_sign+res[i+j+1]-48;
            over_sign = temp/10;
            res[i+j+1] = static_cast<char>(temp%10+48);
        }
        // 进位值存储在当前的最高位以清空进位值
        if(over_sign){
            res[i] = static_cast<char>(over_sign+48);
            over_sign = 0;
        }
    }
    // 去除字符串头部部分的0
    auto st = res.begin();
    while(*st=='0'){
        ++st;
    }
    return string(st,res.end());
}

// 通配符匹配
/* 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配
 * '?' 可以匹配任何单个字符
 * '*' 可以匹配任意字符串（包括空字符串）
 * 两个字符串完全匹配才算匹配成功。
 */
// 进行匹配,在dp[i-1][j-1]为真的情况下,分别对?,*进行匹配 ※※※
bool Solution::isMatch_Wildcard(string s, string p) {
    // 若相等或者直接匹配整个字符串则直接返回真
    if(s==p||p=="*"){
        return true;
    }
    // 若其中一个为空则无法匹配为假
    if(p.empty()||s.empty()){
        return false;
    }
    // 创建一个dp数组并将所有元素其置为假,dp[0][0]初始化为false
    int ls = s.size();
    int lp = p.size();
    bool dp[lp+1][ls+1];
    for(int i=0;i<lp+1;++i){
        for(int j=0;j<ls+1;++j){
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    // 用模式字符串的每个字符去匹配待匹配的字符串
    for(auto p_index=1;p_index<lp+1;++p_index){
        // 若模式字符为*,则匹配已经匹配部分之后的所有字符
        // 若为？则匹配所有已经匹配字符后的一个字符
        // 其他则匹配已经匹配之后的相同字符
        if(p[p_index-1]=='*'){
            int s_index=1;
            // 查找已经匹配的位置的首位置
            while(!dp[p_index-1][s_index-1]&&s_index<ls+1){
                ++s_index;
            }
            dp[p_index][s_index-1] = dp[p_index-1][s_index-1];
            while(s_index<ls+1){
                dp[p_index][s_index++] = true;
            }
        }else if(p[p_index-1]=='?'){
            // 查找已经匹配字符的下一个
            for(int s_index=1;s_index<ls+1;++s_index){
                dp[p_index][s_index] = dp[p_index-1][s_index-1];
            }
        }else{
            // 匹配已经匹配字符下一个相同的字符
            for(int s_index = 1; s_index < ls + 1; s_index++) {
                dp[p_index][s_index] = dp[p_index - 1][s_index - 1] &&(p[p_index - 1] == s[s_index - 1]);
            }
        }
    }
    return dp[lp][ls];
}

// 全排列
/* 给定一个没有重复数字的序列，返回其所有可能的全排列
 * */
// 递归生成全排列
vector<vector<int>> Solution::permute(vector<int>& nums) {
    int le=nums.size();
    vector<int> temp;
    vector<vector<int>> res;
    vector<int> map_my(le,1);
    co_permute(nums,map_my,temp,res);
    return res;
}
// 递归生成全排列
void Solution::co_permute(vector<int>& nums,vector<int>& my_map,const vector<int>& li,vector<vector<int>> &res){
    int le=nums.size();
    if(li.size()==le){
        res.push_back(li);
    }
    for(int i=0;i<le;++i){
        auto temp = li;
        if(my_map[i]){
            my_map[i] = 0;
            temp.push_back(nums[i]);
            co_permute(nums,my_map,temp,res);
            my_map[i] = 1;
        }
    }
}

// 最长上升子序列
/* 给定一个无序的整数数组，找到其中最长上升子序列的长度
 * */
// 动态规划--复杂度O(n^2),dp存储由当前数字结尾的上升子序列的长度
int Solution::lengthOfLIS(vector<int>& nums) {
    // 创建dp数组,用于存储最大长度
    int le = nums.size();
    vector<int> dp(le,1);
    // 填充dp数组
    for(int i=1;i<le;++i){
        for(int j=0;j<i;++j){
            if(nums[i]>nums[j]&&dp[j]>=dp[i]){
                dp[i] = dp[j]+1;
            }
        }
    }
    // 取出最大值
    int max=0;
    for(int k=0;k<le;++k){
        max = max>dp[k]?max:dp[k];
    }
    return max;
}

// 岛屿的最大面积
/* 给定一个包含了一些 0 和 1的非空二维数组 grid
 * 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合
 * 你可以假设二维矩阵的四个边缘都被水包围着
 * 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0)
 * */
// 深度搜索-dps
int Solution::maxAreaOfIsland(vector<vector<int>>& grid){
    // 判断是否存在元素
    if(grid.empty()||grid[0].empty()){
        return 0;
    }
    //记录最大值和二维数组大小
    int max = 0;
    int row = grid.size();
    int col = grid[0].size();
    // 遍历将遍历到的部分进行扩展搜索直到无法扩展
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if(grid[i][j] == 1){
                // 进行深度遍历,最后返回总块数
                int temp = dps_maxAreaOfIsland(grid,i,j);
                // 更新最大值
                max = max>temp?max:temp;
            }
        }
    }
    return max;
}

int Solution::dps_maxAreaOfIsland(vector<vector<int>>& grid,int dx,int dy){
    // 越界或所在格子为0则直接返回0
    if(dx<0||dy<0||dx>=grid.size()||dy>=grid[0].size()||grid[dx][dy]==0){
        return 0;
    }
    // 将自身置为0,防止重复遍历
    grid[dx][dy] = 0;
    int max = 1;
    // 查询上面
    max += dps_maxAreaOfIsland(grid,dx-1,dy);
    // 查询下面
    max += dps_maxAreaOfIsland(grid,dx+1,dy);
    // 查询右面
    max += dps_maxAreaOfIsland(grid,dx,dy+1);
    // 查询左面
    max += dps_maxAreaOfIsland(grid,dx,dy-1);
    // 返回总的块数
    return max;
}


// 动态规划-复杂度为O(n^2)
int Solution::jump_1(vector<int>& nums) {
    int le = nums.size();
    if(le==0){
        return 0;
    }
    int *dp = static_cast<int*>(malloc(sizeof(int)*le));
    for(int i=0;i<le;++i){
        dp[i] = 0;
    }
    for(int i=le-2;i>=0;--i){
        int min=dp[i+1];
        for(int j=1;j<nums[i]+1&&i+j<le;++j){
            min = min<dp[i+j]?min:dp[i+j];
        }
        dp[i] = min+1;
    }
    int res = dp[0];
    free(dp);
    return dp[0];
}
// 模拟跳跃
int Solution::jump_2(vector<int>& nums) {
    int le=nums.size();
    int steps=0;
    int start = 0;
    int end = 1;
    // 找到每次跳跃使得下一次跳跃达到的最远的距离
    while(end<le){
        int max = 0;
        for(int i=start;i<end;++i){
            max = max>i+nums[i]?max:i+nums[i];
        }
        start = end;
        end = max+1;
        ++steps;
    }
    return steps;
}

// 字符串压缩
/* 利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能
 * 比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串
 * 你可以假设字符串中只包含大小写英文字母（a至z）
 * */
// 一次遍历,若出现重复则计数，不重复则加入
string Solution::compressString(const string& S) {
    if(S.empty()){
        return S;
    }
    string res;
    char temp = S[0];
    res += temp;
    int count = 1;
    for(int i=1;i<S.size();++i){
        if(S[i]!=temp){
            res += to_string(count);
            // res += static_cast<char>(count+48);
            temp = S[i];
            res += temp;
            count = 1;
        }else{
            ++count;
        }
    }
    res += to_string(count);
    // res += static_cast<char>(count+48);
    return res.size()<S.size()?res:S;
}

// 全排列 II
/* 给定一个可包含重复数字的序列，返回所有不重复的全排列
 * */
// 利用map去重,同时保证得以不会漏掉结果
vector<vector<int>> Solution::permuteUnique(vector<int>& nums) {
    // 生成map
    map<int,int> info;
    for(auto i:nums){
        ++info[i];
    }
    vector<vector<int>> res;
    vector<int> temp;
    dps_permuteUnique(info,temp,res,nums.size());
    return res;
}
// 取map里的值进行全排列,在同一个层中每个数只能取一次
void Solution::dps_permuteUnique(map<int,int>& my_map,const vector<int>& li,vector<vector<int>> &res,int size){
    int le=my_map.size();
    // 长度足够则进行返回
    if(li.size()==size){
        res.push_back(li);
    }
    // 取出不同的数进行全排列
    for(auto i:my_map){
        auto temp = li;
        if(my_map[i.first]){
            // 将数量减一,移交下一次递归
            --my_map[i.first];
            temp.push_back(i.first);
            dps_permuteUnique(my_map,temp,res,size);
            // 从下一层递归返回,恢复数量
            ++my_map[i.first];
        }
    }
}

// 旋转图像
/* 给定一个 n × n 的二维矩阵表示一个图像
 * 将图像顺时针旋转 90 度
 * */
// 对每个位置进行旋转操作,仅仅移动为操作过的部分,时间复杂度为O(n^2),空间复杂度为O(1)
void Solution::rotate(vector<vector<int>>& matrix) {
    // 矩阵维数n
    int n = matrix.size();
    // 遍历未移动的数字,数量为n^2/4个每个进行4次移动,即一次旋转操作
    for(int i=0;i<n/2;++i){
        for(int j=0;j<n-1-2*i;++j){
            int x=i;
            int y = i+j;
            int temp = matrix[x][y];
            matrix[x][y] = matrix[n-1-y][x];
            matrix[n-1-y][x] = matrix[n-1-x][n-1-y];
            matrix[n-1-x][n-1-y] = matrix[y][n-1-x];
            matrix[y][n-1-x] = temp;

        }
    }
}

// 拼写单词
/* 给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars
 * 假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词
 * 注意：每次拼写时，chars 中的每个字母都只能用一次
 * 返回词汇表 words 中你掌握的所有单词的 长度之和
 * */
// 利用哈希表进行检索,每个单词一个哈希表,单词哈希表每项应该小于给定字母组合的哈希表
int Solution::countCharacters(vector<string>& words, const string& chars) {
    // 两个用于对照的哈希表
    int info[26];
    int ch[26];
    for(int i=0;i<26;++i){
        *(info+i) = 0;
        *(ch+i) = 0;
    }
    for(auto i:chars){
        ++ch[i-'a'];
    }
    int count=0;
    // 对单词进行计数
    for(const auto& word:words){
        int le = word.size();

        for(auto c:word){
            ++info[c-'a'];
        }
        // 比较哈希表是否小于
        int flag = 1;
        for(int j=0;j<26;++j){
            if(flag&&info[j]>ch[j]){
                flag = 0;
            }
            info[j] = 0;
        }
        count += flag?le:0;
    }
    return count;
}

// 字母异位词分组
/* 给定一个字符串数组，将字母异位词组合在一起
 * 字母异位词指字母相同，但排列不同的字符串
 * */
// 哈希表做法
vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
    // 以哈希表为map下标进行存储字符串
    map<vector<int>,vector<string>> info;
    for(const auto& word:strs){
        vector<int> temp(26,0);
        for(auto i:word){
            ++temp[i-'a'];
        }
        info[temp].push_back(word);
    }
    // 将每组字符串移动进入数组
    vector<vector<string>> res;
    res.reserve(info.size());
    for(const auto& m:info){
        res.push_back(m.second);
    }
    return res;
}

// N皇后
/* n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上,并且使皇后彼此之间不能相互攻击
 * 给定一个整数 n,返回所有不同的 n 皇后问题的解决方案
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案,该方案中 'Q' 和 '.' 分别代表了皇后和空位
 * */
// 递归回溯法-时间复杂度O(n!),空间复杂度O(n),需要5*N的空间分别报存行,对角线信息
vector<vector<string>> Solution::solveNQueens(int n) {
    // 存储结果
    vector<vector<string>> res;
    // 存储可供填写的棋盘
    vector<string> temp(n,string(n,'.'));
    // 判断在列上是否存在皇后,由(x,y)映射为col[y]
    vector<bool> col(n,true);
    // 判断左斜对角线上是否有皇后,由(x,y)映射为x-y+n-1
    vector<bool> left_line(2*n-1,true);
    // 判断右斜对角线上是否有皇后,由(x,y)映射为x+y
    vector<bool> right_line(2*n-1,true);
    // 递归进行摆放棋子,回溯进行删减
    solveNQueens_dg(col,left_line,right_line,temp,0,res);
    return res;
}
// 用于递归填入棋子并将结果存入res
void Solution::solveNQueens_dg(vector<bool>& col, vector<bool>& left, vector<bool>& right, vector<string>& temp, int deep, vector<vector<string>> &res){
    int n=col.size();
    // 深度即为已经放置的棋子数量,因此当深度等于要摆放的总棋子数时将答案加入
    if(deep==n){
        res.push_back(temp);
        return;
    }
    // 由于将要摆放的棋子一定不在同一行,因此我们直接在已摆放下一行之内寻找,即deep行
    for(int i=0;i<n;++i){
        // 如果在各个方向均无皇后则说明可以填入
        if(col[i] && right[deep + i] && left[deep - i + n - 1]){
            // 填入棋子
            col[i] = false;
            right[deep + i] = false;
            left[deep - i + n - 1] = false;
            temp[deep][i] = 'Q';
            // 在已经填入棋子的基础上进行再次填入
            solveNQueens_dg(col, left, right, temp, deep + 1, res);
            // 进行回溯
            temp[deep][i] = '.';
            col[i] = true;
            right[deep + i] = true;
            left[deep - i + n - 1] = true;
        }
    }
}

// 最大子序和
/* 给定一个整数数组 nums
 * 找到一个具有最大和的连续子数组（子数组最少包含一个元素）
 * 返回其最大和
 * */
// 动态规划,贪心算法-时间复杂度O(n),空间复杂度O(1)
int Solution::maxSubArray(vector<int>& nums) {
    int le = nums.size();
    int dp = nums[0];
    int before_num = nums[0];
    // 将每个数和之前的最大和相比较直到,若之前为负数则后一个直接取得,否则加在之前的上面,再进行取最大值操作
    for(int i=1;i<le;++i){
        before_num = before_num>0?before_num+nums[i]:nums[i];
        dp = dp>before_num?dp:before_num;
    }
    return dp;
}

// 矩形重叠
/* 矩形以列表 [x1, y1, x2, y2] 的形式表示，其中 (x1, y1) 为左下角的坐标，(x2, y2) 是右上角的坐标
 * 如果相交的面积为正，则称两矩形重叠。需要明确的是，只在角或边接触的两个矩形不构成重叠
 * 给出两个矩形，判断它们是否重叠并返回结果
 * */
// 若想不覆盖则需要满足:
// 矩形左边应大于另一个右边,右边应该小于另一个左边,下边应大于另一个上边,上边应小于另一个下边
// 因此若是覆盖则应该不满足以上条件
bool Solution::isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    return !(rec2[2]<=rec1[0]||rec2[0]>=rec1[2]||rec2[3]<=rec1[1]||rec2[1]>=rec1[3]);
}

// 螺旋矩阵
/* 给定一个包含 m x n 个元素的矩阵(m 行,n 列)
 * 请按照顺时针螺旋顺序，返回矩阵中的所有元素
 * */
// 转圈模拟取值
vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
    // 存储数字
    vector<int> res;
    if(matrix.empty()){
        return res;
    }
    // 创建定位坐标
    int row = matrix.size();
    int col = matrix[0].size();
    int r1 = 0, r2 = row - 1;
    int c1 = 0, c2 = col - 1;
    while (r1 <= r2 && c1 <= c2) {
        // 扫描上方一横行
        for (int c = c1; c <= c2; c++){
            res.push_back(matrix[r1][c]);
        }
        // 扫描最右一竖行
        for (int r = r1 + 1; r <= r2; r++){
            res.push_back(matrix[r][c2]);
        }
        // 若不在同一行同一列则扫描下方一横行和左方一横行
        if (r1 < r2 && c1 < c2) {
            for (int c = c2 - 1; c > c1; c--) {
                res.push_back(matrix[r2][c]);
            }
            for (int r = r2; r > r1; r--) {
                res.push_back(matrix[r][c1]);
            }
        }
        // 定位坐标向内收缩一层
        r1++;
        r2--;
        c1++;
        c2--;
    }
    return res;
}

// 跳跃游戏
/* 给定一个非负整数数组，你最初位于数组的第一个位置
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度
 * 判断你是否能够到达最后一个位置
 * */
// 模拟跳跃,若跳过去末尾则说明可以达到末尾,若leftPoint超越rightPoint说明已经无法前进则无法到达终点
bool Solution::canJump(vector<int>& nums) {
    int leftPoint = 0;
    int rightPoint = 0;
    int maxReach = 0;
    int le = nums.size();
    // 模拟跳跃
    while(leftPoint <= rightPoint){
        for(int i=leftPoint; i <= rightPoint; ++i){
            int temp = i+nums[i];
            maxReach = maxReach > temp ? maxReach : temp;
            // 到达终点
            if(maxReach >= le - 1){
                return true;
            }
        }
        // 向后移动判断区域,新区域[上一次末尾,能跳到的最远距离]
        leftPoint = rightPoint + 1;
        rightPoint = maxReach;
    }
    return false;
}
// 最长回文串
/* 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串
 * 注意:
 * 假设字符串的长度不会超过 1010
 * */
// 哈希表
int Solution::longestPalindrome(const string& s) {
    // 小写映射为前26个,大写映射为后26个
    int counter[52] = {0};
    for(auto i:s){
        if(i>='a'&&i<='z'){
            ++counter[i-'a'];
        }else{
            ++counter[i-'A'+26];
        }

    }
    // 是否存在奇数
    int flag = 0;
    int theLen = 0;
    // 奇数只取偶数长度
    for(int temp : counter){
        if(temp%2){
            theLen += temp-1;
            flag = 1;
        }else{
            theLen += temp;
        }
    }
    // 若存在奇数,最中央可以单独填一个
    theLen += flag;
    return theLen;
}

// 最小的k个数
/* 输入整数数组 arr ，找出其中最小的 k 个数
 * */
// 桶排序
vector<int> Solution::getLeastNumbers(vector<int>& arr, int k) {
    int info[10001]={0};
    for(auto i:arr){
        ++info[i];
    }
    int index = 0;
    vector<int> res;
    while(k>0){
        if(info[index]){
            res.push_back(index);
            --info[index];
            --k;
        }else{
            ++index;
        }
    }
    return res;
}

// 合并区间
/* 给出一个区间的集合，请合并所有重叠的区间
 * */
// 先将区间排序,则可合并的区间一定是连续的区间,后只需要一次遍历即可
vector<vector<int>> Solution::mergeRange(vector<vector<int>>& intervals) {
    if(intervals.empty()){
        return intervals;
    }
    vector<vector<int>> res;
    sort(intervals.begin(),intervals.end());
    res.push_back(intervals[0]);
    int index = 0;
    for(int i=1;i<intervals.size();++i){
        if(intervals[i][0]<=res[index][1]){
            if(res[index][1] < intervals[i][1]){
                res[index][1] = intervals[i][1];
            }
        }else{
            res.push_back(intervals[i]);
            ++index;
        }
    }
    return res;
}

// 插入区间
/* 给出一个无重叠的 ，按照区间起始端点排序的区间列表
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠(如果有必要的话，可以合并区间)
 * */
// 一次遍历,在插入位置进行插入,后接合并
vector<vector<int>> Solution::insertRange(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int index = -1;
    int t = 0;
    // 寻找插入位置
    while(t<intervals.size()&&intervals[t][0]<newInterval[0]){
        if(intervals[t][1]>newInterval[0]){
            res.push_back(intervals[t]);
            ++index;
            ++t;
            break;
        }
        res.push_back(intervals[t]);
        ++index;
        ++t;
    }
    // 插入新区间,若需要合并则合并
    if(index>=0&&newInterval[0]<=res[index][1]){
        if(res[index][1] < newInterval[1]){
            res[index][1] = newInterval[1];
        }
    }else{
        res.push_back(newInterval);
        ++index;
    }
    // 从插入位置之后继续拷贝
    while(t<intervals.size()){
        if(intervals[t][0]<=res[index][1]){
            if(res[index][1] < intervals[t][1]){
                res[index][1] = intervals[t][1];
            }
        }else{
            res.push_back(intervals[t]);
            ++index;
        }
        ++t;
    }
    return res;
}

// 最后一个单词的长度
/* 给定一个仅包含大小写字母和空格 ' ' 的字符串 s,返回其最后一个单词的长度
 * 如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词
 * 如果不存在最后一个单词，请返回 0
 * 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串
 * */
// 先去尾部空格,然后扫描下一个空格的位置,作差即为长度
int Solution::lengthOfLastWord(string s) {
    int l = s.size();
    int wordLen = 0;
    int t = l-1;
    while(s[t]==' '){
        --t;
    }
    wordLen = t;
    while(s[t]!=' '){
        --t;
    }
    return wordLen-t;
}

// 螺旋矩阵 II
/* 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵
 * */
// 模拟旋转生成矩阵
vector<vector<int>> Solution::generateMatrix(int n) {
    vector<vector<int>> res(n,vector<int>(n,0));
    int numPut=0,deep=0,p = 0,q=0,dp=0,dq=1;
    while(n*n > numPut){
        numPut++;
        res[p][q] = numPut;
        if(p == deep && q == n - 1 - deep){
            dp = 1;
            dq = 0;
        }else if(p== n - 1 - deep && q == n - 1 - deep){
            dp = 0;
            dq = -1;
        }else if(p== n - 1 - deep && q == deep){
            dp = -1;
            dq = 0;
        }else if(p == deep + 1 && q == deep){
            dp = 0;
            dq = 1;
            deep+=1;
        }
        p += dp;
        q += dq;
    }
    return res;
}

// 第k个排列
/* 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列
 * 给定 n 和 k，返回第 k 个排列
 * */
// 通过阶乘进行映射,k除以对应位置下一位的阶乘可以得到偏移量,从而直接从剩余数字中选择出对应位置数字
string Solution::getPermutation(int n, int k) {
    // res存储结果,初始化为n个'0'
    string res(n,'0');
    // 生成阶乘数组和标志数组
    int *info = static_cast<int *>(malloc(sizeof(int)*n));
    info[0] = 1;
    for(int i=1;i<n;++i){info[i] = info[i-1]*i;}
    bool *counter = static_cast<bool *>(malloc(sizeof(bool)*n));
    for(int i=0;i<n;++i){counter[i] = true;}
    int index = 0;
    --k;
    // 循环填入数字
    while(index<n){
        int temp = k/info[n-index-1];
        k -= temp*info[n-index-1];
        // 扫描counter从而选出一个未被使用的数字,先进行偏移量的计算
        for(int j=0;j<n;++j){
            if(counter[j]){
                if(temp==0){
                    counter[j] = false;
                    res[index] += j+1;
                    ++index;
                    break;
                }
                --temp;
            }
        }
    }
    free(info);
    free(counter);
    return res;
}

// 水壶问题
/* 有两个容量分别为x升和y升的水壶以及无限多的水
 * 请判断能否通过使用这两个水壶，从而可以得到恰好z升的水？
 * 如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升水
 * 你允许：
 * 装满任意一个水壶
 * 清空任意一个水壶
 * 从一个水壶向另外一个水壶倒水，直到装满或者倒空
 * */
// 模拟加水逐步增加,比目标值小则加较少的水,比目标值大则减去较大的水
bool Solution::canMeasureWater(int x, int y, int z) {
    // 两个偶数杯子不能产生奇数水量且两个杯子应该能盛放下目标水量
    if((x%2==0&&y%2==0&&z%2)||x+y<z){
        return false;
    }
    int min = x<y?x:y;
    int max = x==min?y:x;
    int sum = 0;
    while(sum!=z){
        if(sum<z){
            // 加水过程,不因加水而导致溢出故选择减少水量
            if(sum+min<=x+y){
                cout << sum << "L\t" <<"加上:" << min << "L" << endl;
                sum += min;
            }else{
                cout << sum << "L\t" <<"倒掉:" << max << "L" << endl;
                sum -= max;
            }
        }else if(sum > z){
            // 倒水过程,不因倒水而导致产生负值故选择增加水量
            if(sum-max>=0){
                cout << sum << "L\t" <<"倒掉:" << max << "L" << endl;
                sum -= max;
            }else{
                cout << sum << "L\t" <<"加上:" << min << "L" << endl;
                sum += min;
            }
        }
        // 当存在既不能加水也不能倒水的情况则会产生负值与溢出,因此若被检测到则说明不能完成
        if(sum<=0||sum>x+y){
            cout << "水量异常！！！"<< endl;
            return false;
        }
    }
    return true;
}

// 多数元素
/* 给定一个大小为 n 的数组，找到其中的多数元素
 * 多数元素是指在数组中出现次数大于 n/2的元素
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素
 * */
// 由于是多数元素,可以依靠人数碾压,先取一个候选多数元素,当不同时进行多数元素-1,到最后一定只有多数元素是由于>0被保存下来
int Solution:: majorityElement(vector<int>& nums) {
    int k = 0;
    int temp = nums[0];
    for(auto i:nums){
        if(k==0){
            temp = i;
        }
        k += i==temp?1:-1;
    }
    return temp;
}

// 旋转链表
/* 给定一个链表,旋转链表,将链表每个节点向右移动 k 个位置,其中 k 是非负数
 * */
// 形成闭合链表环,重新选取断点
ListNode* Solution::rotateRight(ListNode* head, int k) {
    // 形成闭环并计数
    int len = 1;
    auto p = head;
    while(p->next){
        p = p->next;
        ++len;
    }
    p->next = head;
    auto left = p;
    auto right = head;
    // 计算移动次数
    int counter = len-k%len;
    while(counter>0){
        left = left->next;
        right = right->next;
        --counter;
    }
    // 截断返回
    left->next = nullptr;
    return right;
}
// 使数组唯一的最小增量
/* 给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1
 * 返回使 A 中的每个值都是唯一的最少操作次数
 * */
int Solution::minIncrementForUnique(vector<int>& A) {
    if(A.empty()){
        return 0;
    }
    sort(A.begin(),A.end());
    int le = A.size();
    int res = 0;
    for(int j=1;j<le;++j){
        if(A[j]<=A[j-1]){
            res += A[j-1]+1-A[j];
            A[j] = A[j-1]+1;
        }
    }
    return res;
}
// 字符串的最大公因子
/* 对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”
 * 返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2
 * */
// 辗转相除法,求字符串最大公因式
string Solution::gcdOfStrings(string str1, string str2) {
    int a=0,b=str1.size();
    int c=0,d=str2.size();
    while(a<b&&c<d){
        int i=a,j=c;
        while(i<b&&j<d){
            if(str1[i]!=str2[j]){
                return "";
            }
            ++i;
            ++j;
        }
        if(i==b&&j==d){
            break;
        }
        if(i==b){
            c = j;
        }
        if(j==d){
            a = i;
        }

    }
    return string(str1.begin(),str1.begin()+b-a);
}

// 链表的中间结点
/* 给定一个带有头结点 head 的非空单链表，返回链表的中间结点
 * 如果有两个中间结点，则返回第二个中间结点
 * */
// 快慢指针法-快指针走两步,慢指针走一步从而使得当快指针到末尾时,慢指针置走了一半
ListNode* Solution::middleNode(ListNode* head) {
    auto left = head;
    auto right = head;
    // 步进指针
    while(right&&right->next){
        left = left->next;
        right = right->next->next;
    }
    // 当快指针无法继续前进时慢指针刚好指向所要求的节点的位置
    return left;
}

// 不同路径 I
/* 一个机器人位于一个 m x n 网格的左上角,起始点在下图中标记为“Start”
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）
 * 问总共有多少条不同的路径？
 * */
// 动态规划
int Solution::uniquePaths(int m, int n) {
    // 存储上一行的总路径数
    auto counter = static_cast<int *>(malloc(sizeof(int)*m));
    for(int i=0;i<m;++i){
        counter[i] = 1;
    }
    // 重复修改数组
    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            counter[j] = counter[j-1]+counter[j];
        }
    }
    int res = counter[m-1];
    free(counter);
    // 最后一行,最后一个即为结果
    return counter[m-1];
}

// 不同路径 II
/* 一个机器人位于一个 m x n 网格的左上角,起始点在下图中标记为“Start”
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角,在下图中标记为“Finish”
 * 现在考虑网格中有障碍物,那么从左上角到右下角将会有多少条不同的路径？
 * */
// 动态规划在不同路径的基础上,将有障碍物的点置为0
int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    // 若起点或者终点有障碍物则不存在路径,返回0
    if(obstacleGrid[0][0]||obstacleGrid[n-1][m-1]){
        return 0;
    }
    auto counter = static_cast<int *>(malloc(sizeof(int)*m));
    // 判断第一行每个点的路径数,如果右边路径不通,则直接为0
    counter[0] = obstacleGrid[0][0]?0:1;
    for(int i=1;i<m;++i){
        counter[i] = counter[i-1]&&!obstacleGrid[0][i]?1:0;
    }
    // 每一层开始时,第一列是否有障碍物
    for(int i=1;i<n;++i){
        counter[0] = counter[0]&&!obstacleGrid[i][0]?1:0;
        for(int j=1;j<m;++j){
            if(obstacleGrid[i][j]){
                counter[j] = 0;
            }else{
                counter[j] = counter[j-1]+counter[j];
            }
        }
    }
    int res = counter[m-1];
    free(counter);
    return res;
}

// 最小路径和
/* 给定一个包含非负整数的 m x n 网格,请找出一条从左上角到右下角的路径,使得路径上的数字总和为最小
 * 说明：每次只能向下或者向右移动一步
 * */
// 动态规划-使用一行数组存储上一行取得的最大值
int Solution::minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    auto dp = static_cast<int *>(malloc(sizeof(int) * m));
    // 判断第一行每个点的总和,和为前一个加上自身
    dp[0] = grid[0][0];
    for(int i=1;i<m;++i){
        dp[i] = dp[i - 1] + grid[0][i];
    }
    // 每一层开始求和,对于每行每个位置有dp[j] = dp[j] + min{dp[j-1],dp[j]}
    for(int i=1;i<n;++i){
        dp[0] = dp[0] + grid[i][0];
        for(int j=1;j<m;++j){
            if(dp[j - 1] < dp[j]){
                dp[j] += dp[j-1];
            }
            dp[j] += grid[i][j];
        }
    }
    // free分配的内存
    int res = dp[m - 1];
    free(dp);
    return res;
}

// 有效数字
/* 验证给定的字符串是否可以解释为十进制数字
 * */
// 有限状态机解法
bool Solution::isNumber(const string& s) {
    // 状态机映射表,将{BLANK,SIGN,NUM,DOT,E}映射为要跳转的状态
    int info[9][5]{
            {0 , 1, 2, 3,-1},   // 0状态,未检测状态
            {-1,-1, 2, 3,-1},   // 1状态,检测到符号
            { 8,-1, 2, 4, 5},   // 2状态,检测到数字
            {-1,-1, 4,-1,-1},   // 3状态,检测到点
            { 8,-1, 4,-1, 5},   // 4状态,检测到数字
            {-1, 6, 7,-1,-1},   // 5状态,检测到e
            {-1,-1, 7,-1,-1},   // 6状态,检测到符号
            { 8,-1, 7,-1,-1},   // 7状态,检测到数字
            { 8,-1,-1,-1,-1}    // 8状态,检测完成
    };
    int state = 0;
    int le = s.size();
    for(int index=0;index<le;++index){
        int t = 0;
        // 判断取得的字符
        switch(s[index]){
            case ' ': t = 0;break;
            case '+':
            case '-': t = 1;break;
            case '.': t = 3;break;
            case 'e': t = 4;break;
            default:
                if(s[index] >= 48 && s[index] <= 57){
                    t = 2;
                }else{
                    return false;
                }
        }
        state = info[state][t];
        if(state==-1){
            return false;
        }
    }
    // 追加空格判断使得可以结束的地方跳转到末状态8
    state = info[state][0];
    return state==8;
}

// 按摩师
/* 一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接
 * 在每次预约服务之间要有休息时间，因此她不能接受相邻的预约
 * 给定一个预约请求序列,替按摩师找到最优的预约集合(总预约时间最长),返回总的分钟数
 * */
// 动态规划,若扫描到nums[i]则只需要将nums[i]加上前i-2个数字中的最大值即可为以当前数字结尾的最大值
int Solution::massage(vector<int>& nums) {
    // 避免出现空数组
    if(nums.empty()){
        return 0;
    }
    int le = nums.size();
    // 保存第i-1个数字
    int before_right = 0;
    // 保存第i-2个数字
    int before_left = 0;
    // 保存i-2之前数字最大值
    int before_max=0;
    // 扫描并更新所需数值
    for(int i=0;i<le;++i){
        before_max = i > 1 && before_max < before_left ? before_left : before_max;
        before_left = i > 0 ? before_right : 0;
        before_right = nums[i] + before_max;
    }
    // 结果一定存在于最后两个数值其中一个,若出现三个数则说明一定可以再次预约一个
    return before_left>before_right?before_left:before_right;
}

// 加一
/* 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字
 * 你可以假设除了整数 0 之外，这个整数不会以零开头
 * */
// 从末尾判断是否溢出,只要存在一次不溢出则直接返回原数组,遍历完毕若溢出则进行头部加1
vector<int> Solution::plusOne(vector<int>& digits) {
    int le = static_cast<int>(digits.size())-1;
    // 标记是否要+1,默认为有个1要加
    bool overflow_flag = true;
    while(le>=0){
        if(overflow_flag){
            if(digits[le]!=9){
                digits[le] += 1;
                overflow_flag = false;
            }else{
                digits[le] = 0;
            }
        }else{
            return digits;
        }
        --le;
    }
    // 全为9则需要进行扩增数组
    if(overflow_flag){
        digits.insert(digits.begin(),1);
    }
    return digits;
}
// 三维形体的表面积
/* 在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体
 * 每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上
 * 请你返回最终形体的表面积
 * */
// 求出总的方块数,总的接触面数,将总面数减去接触面抵消的面从而得到表面积
int Solution::surfaceArea(vector<vector<int>>& grid) {
    int n = grid.size();
    // 总块数
    int blockNum = 0;
    // 总接触面数
    int touchNum = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            // 判断上方接触面数量
            if(i>0){
                touchNum += grid[i][j] > grid[i - 1][j] ? grid[i - 1][j] : grid[i][j];
            }
            // 判断左面接触面数量
            if(j>0){
                touchNum += grid[i][j] > grid[i][j - 1] ? grid[i][j - 1] : grid[i][j];
            }
            // 判断由于叠置而导致的接触面数量
            if(grid[i][j]>1){
                touchNum += grid[i][j]-1;
            }
            // 块数累加
            blockNum += grid[i][j];
        }
    }
    // 表面积
    return 6*blockNum-2*touchNum;
}

// 二进制求和
/* 给定两个二进制字符串，返回他们的和（用二进制表示）
 * 输入为非空字符串且只包含数字 1 和
 * */
// 进行逐位加和,标记是否溢出,溢出为在下一位被处理
string Solution::addBinary(const string& a, const string& b) {
    int l1 = a.size();
    int l2 = b.size();
    int lr = l1>l2?l1:l2;
    bool ofs = false;
    string res(lr,'0');
    // 逐位加和
    for(int i=lr-1;i>=0;--i){
        // 上一次溢出处理
        if(ofs){
            res[i] += 1;
            ofs = false;
        }
        // 加和两个对应位置
        if(l1>0&&a[l1-1]=='1'){
            res[i] += 1;
        }
        --l1;
        if(l2>0&&b[l2-1]=='1'){
            res[i] += 1;
        }
        --l2;
        // 处理溢出,并重置下一次计算的溢出标记
        if(res[i]>'1'){
            ofs = true;
            res[i] -= 2;
        }
    }
    // 若仍有溢出则在字符串开头添加'1'
    return ofs?'1'+res:res;
}

// 地图分析
/* 你现在手里有一份大小为 N x N 的『地图』(网格)grid,上面的每个『区域』(单元格)都用 0 和 1 标记好了
 * 其中 0 代表海洋，1 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离
 * 我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1|
 * 如果我们的地图上只有陆地或者海洋，请返回 -1
 * */
// 动态规划-从左上角扫描后再从右下角扫描,取最大值为结果
int Solution::maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    int INF = int(1E6);
    vector<vector<int>> f(n,vector<int>(n,0));
    vector<vector<int>>& a = grid;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            f[i][j] = (a[i][j] ? 0 : INF);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j]) continue;
            if (i - 1 >= 0) f[i][j] = min(f[i][j], f[i - 1][j] + 1);
            if (j - 1 >= 0) f[i][j] = min(f[i][j], f[i][j - 1] + 1);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (a[i][j]) continue;
            if (i + 1 < n) f[i][j] = min(f[i][j], f[i + 1][j] + 1);
            if (j + 1 < n) f[i][j] = min(f[i][j], f[i][j + 1] + 1);
        }
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!a[i][j]) {
                ans = max(ans, f[i][j]);
            }
        }
    }

    if (ans == INF) return -1;
    else return ans;
}


// 面试题62. 圆圈中最后剩下的数字
/* 0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字
 * 例如，0、1、2、3、4这5个数字组成一个圆圈
 * 从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3
 * */
// 约瑟夫环问题,在多次删除后,只剩下一个数字其下标为0,根据分析下标变化可反推出剩余的数字在原数组的位置
int Solution::lastRemaining(int n, int m) {
    // 初始下标
    int index = 0;
    // 反推,上一次下标=(步长+当前下标)%上一次长度
    for (int i = 2; i != n + 1; ++i)
        index = (m + index) % i;
    return index;
}

// 有效括号的嵌套深度
/* 有效括号字符串 定义：对于每个左括号，都能找到与之对应的右括号，反之亦然。详情参见题末「有效括号字符串」部分
 * 嵌套深度 depth 定义：即有效括号字符串嵌套的层数。详情参见题末「嵌套深度」部分
 * 给你一个「有效括号字符串」 seq，请你将其分成两个不相交的有效括号字符串 A 和 B:
 * 不相交：每个 seq[i] 只能分给 A 和 B 二者中的一个，不能既属于 A 也属于 B
 * A 或 B 中的元素在原字符串中可以不连续
 * A.length + B.length = seq.length
 * 请你选出 任意 这样的 A 和 B，使得 max(depth(A), depth(B)) 的可能取值最小
 * 其中 depth(A) 表示 A 的嵌套深度，depth(B) 表示 B 的嵌套深度
 * 请你返回一个长度为 seq.length 的答案数组 answer，编码规则如下：
 * answer[i] = 0，seq[i] 分给 A
 * answer[i] = 1，seq[i] 分给 B
 * 即便有多个满足要求的答案存在,你也只需返回其中任意一个
 * */
// 求出每个括号所在深度,并从中间分开或者根据奇偶性分开
vector<int> Solution::maxDepthAfterSplit(string seq) {
    // 取得深度表,将深度大于一半的置为1,否则置为0
    /*if(seq.empty()){return vector<int>{};}
    int le = seq.size();
    vector<int> res(le, 0);
    int max = 1;
    for(int i=1;i<le;++i){
        res[i] = res[i - 1];
        if(seq[i]==seq[i-1]){
            res[i] += seq[i] == '(' ? 1 : -1;
        }
        max = max>res[i]?max:res[i];
    }
    max /= 2;
    for(auto &i:res){
        i = i>max?1:0;
    }
    return res;*/
    // 取得深度表，将深度偶数置为1,奇数置为0
    int le = seq.size();
    vector<int> res(le, 0);
    int deep = 0;
    // 若形成((则deep+1,若形成))则deep-1,若形成)(或()则deep不变
    for(int i=1;i<le;++i){
        if(seq[i]==seq[i-1]){
            deep += seq[i] == '(' ? 1 : -1;
        }
        res[i] = deep%2;
    }
    return res;
}

// 文本左右对齐
/* 给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本
 * 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词
 * 必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符
 * 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格
 * 说明:
 * 单词是指由非空格字符组成的字符序列
 * 每个单词的长度大于 0，小于等于 maxWidth
 * 输入单词数组 words 至少包含一个单词
*/
// 首先按照单词间间隔一个空格进行分行,若无法容纳更多单词,则将剩余空格进行分配
vector<string> Solution::fullJustify(vector<string>& words, int maxWidth) {
    int wordsSum = words.size();
    vector<string> res;
    // 遍历单词
    for(int i=0;i<wordsSum;++i){
        int st = i;         // 记录行开始位置
        int line = words[i].size();         // 记录行单词空格占用数量
        // 循环取词,直到放不下
        while(i+1 < wordsSum && line + words[i + 1].size() < maxWidth){
            line += (int)words[i+1].size()+1;
            ++i;
        }
        // 计算空格总长
        int blanks=maxWidth-line+i-st;
        if(i == wordsSum - 1){          // 若包含了最后一个单词,则使用左对齐且用一个空格隔开
            string temp(words[st]);
            for(int index= st + 1; index <= i; ++index){
                --blanks;
                temp += ' ';
                temp += words[index];
            }
            temp += string(blanks,' ');     // 补齐空格
            res.push_back(temp);
        }else if(i==st){        // 只有一个单词,空格接在后面
            res.push_back(words[i]+string(blanks,' '));
        }else{          // 多个单词进行平均分配空格
            int nums = i-st;
            vector<int> info(i-st,blanks/nums);
            blanks %= nums;
            while(blanks>0){
                ++info[blanks-1];
                --blanks;
            }
            string temp(words[st]);
            for(int index= st + 1; index <= i; ++index){
                temp += string(info[index - st - 1], ' ');
                temp += words[index];
            }
            res.push_back(temp);
        }
    }
    return res;
}

// 生命游戏
/* 根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机
 * 给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞
 * 每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）
 * 每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
 * 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
 * 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
 * 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
 * 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
 * 根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态
 * 下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的
 * */
// 将状态映射为唯一值并将映射值分成两类,分别填入1,0
void Solution::gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();
    for(int row=0;row<m;++row){
        for(int col=0;col<n;++col){
            int temp = 0;
            for(int i=-1;i<2;++i){
                for(int j=-1;j<2;++j){
                    if(i==0&&j==0){
                        continue;
                    }
                    temp += row+i>=0&&col+j>=0&&row+i<m&&col+j<n&&board[row+i][col+j]>0?1:0;
                }
            }
            // 原来存活的细胞映射为正数,原来死亡的细胞映射为负数,周围存活细胞数为temp
            board[row][col] = board[row][col]?9-temp:temp-9;
        }
    }
    // 映射为-6,,6,7的细胞变为了活细胞,其余变成了死细胞
    for(int row=0;row<m;++row){
        for(int col=0;col<n;++col){
            int t = board[row][col];
            board[row][col] = t==-6||t==6||t==7?1:0;
        }
    }
}

// 简化路径
/* 以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径
 * 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身
 * 此外，两个点 （..） 表示将目录切换到上一级（指向父目录）
 * 两者都可以是复杂相对路径的组成部分
 * 请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /
 * 最后一个目录名（如果存在）不能以 / 结尾
 * 此外,规范路径必须是表示绝对路径的最短字符串
 * */
string Solution::simplifyPath(string path) {
    path += '/';
    int le = path.size();
    vector<int> dv(le,0);
    int before = 0;
    string res(le,'/');
    int s_index = 0;
    int temp = 0;
    for(int k=0;k<le;++k){
        switch(path[k]){
            case '/':
                if(res[s_index]!='/'){
                    ++s_index;
                    res[s_index] =  '/';
                    dv[s_index] = before;
                    before = s_index;
                }
                break;
            case '.':
                if(path[k-1]=='/'){
                    while(k<le&&path[k]=='.'){
                        ++temp;
                        ++k;
                        ++s_index;
                        dv[s_index] = before;
                        res[s_index] = '.';
                    }
                    if(k==le||path[k]=='/'){
                        if(temp==1){
                            s_index -= 1;
                        }else if(temp==2){
                            s_index -= 2;
                            s_index = dv[s_index];
                            before = s_index;
                        }else{
                            --k;
                        }
                    }else{
                        --k;
                    }
                    temp = 0;
                    break;
                }
            default:
                ++s_index;
                dv[s_index] = before;
                res[s_index] = path[k];
        }
    }
    return s_index==0?"/":res.substr(0,s_index);
}

// 编辑距离
/* 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数
 * 你可以对一个单词进行如下三种操作：
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * */
// dp数组记录对应字符段的最少距离
int Solution::minDistance(string word1, string word2) {
    int l1 = word1.size();
    int l2 = word2.size();
    vector<vector<int>> dp(l2 + 1, vector<int>(l1 + 1, 0));
    for(int i=0;i<l1+1;++i){
        dp[0][i] = i;
    }
    for(int i = 0;i<l2+1;++i){
        dp[i][0] = i;
    }
    for(int i=0;i<l2;++i){
        for(int j=0;j<l1;++j){
            int temp = word1[j]==word2[i] ? dp[i][j] - 1 : dp[i][j];
            temp = temp > dp[i + 1][j] ? dp[i + 1][j] : temp;
            temp = temp > dp[i][j + 1] ? dp[i][j + 1] : temp;
            dp[i + 1][j + 1] = temp + 1;
        }
    }
    return dp[l2][l1];
}

// 矩阵置零
/* 给定一个 m x n 的矩阵，如果一个元素为 0
 * 则将其所在行和列的所有元素都设为 0,请使用原地算法
 * */
void Solution::setZeroes(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<bool> info_col(col,false);
    vector<bool> info_row(row,false);
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if(matrix[i][j]==0){
                info_row[i] = true;
                info_col[j] = true;
            }
        }
    }
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if(info_row[i]||info_col[j]){
                matrix[i][j] = 0;
            }
        }
    }
}

// 搜索二维矩阵
/* 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 每行中的整数从左到右按升序排列
 * 每行的第一个整数大于前一行的最后一个整数
 * */
// 当做是一个一维数组,进行二分法,判断值大小时采用坐标映射(x,y)=(mid/col,mid%col)
bool Solution::searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty()||matrix[0].empty()){
        return false;
    }
    int row = matrix.size();
    int col = matrix[0].size();
    int left = 0;
    int right = row*col-1;
    while(left<=right){
        int mid = (left+right)/2;
        int temp= matrix[mid/col][mid%col];
        // cout <<mid<<"|"<<temp << endl;
        if(temp>target){
            right = mid-1;
        }else if(temp<target){
            left = mid+1;
        }else{
            return true;
        }
    }
    return false;
}

// 颜色分类
/* 给定一个包含红色、白色和蓝色，一共 n 个元素的数组,原地对它们进行排序
 * 使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列
 * 此题中,我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色
 * 注意:
 * 不能使用代码库中的排序函数来解决这道题
 * */
// 分拣法,将0分在右边,2分在左边,中间就为1;
void Solution::sortColors(vector<int>& nums) {
    int left = -1;
    int right = nums.size();
    for(int i=0;i<right;++i){
        if(nums[i]==0){
            ++left;
            int temp = nums[left];
            nums[left] = nums[i];
            nums[i] = temp;
        }else if(nums[i]==2){
            --right;
            int temp = nums[right];
            nums[right] = nums[i];
            nums[i] = temp;
            --i;
        }
    }
}

// 最小覆盖子串
/* 给你一个字符串S、一个字符串T,请在字符串S里面找出:包含 T 所有字母的最小子串
 * */
// 哈希表记录待取字母和已经取得字母,采用滑动窗口,若多取及时舍弃,利用哈希表的总数来核实是否匹配从而降低复杂度
string Solution::minWindow(const string& s, const string& t) {
    int needs[128]={0}; // 模拟哈希表
    int hadGet[128]={0};// 模拟哈希表
    int needSum = 0;    // 统计哈希表needs的总数
    int getSum = 0;     // 统计已经取到的总数
    int res_st = 0;     // 保存符合条件字符串的开始位置
    int res_le = 0;     // 保存符合条件字符串的长度
    int left = 0;       // 取左指针
    // 将t录入哈希表,并计算needs总数
    for(auto i:t){++needs[i];}
    for(int need : needs){needSum += need;}
    // 右指针进行向后扫描
    for(int right=0; right < s.size(); ++right){
        // 判断插入的是否为关键字母,仅在关键字母插入时更新窗口
        if(needs[s[right]] != 0){
            if(hadGet[s[right]] < needs[s[right]]){++getSum;}
            ++hadGet[s[right]];
            // 若字母不在要求范围内或者比要求的多则将其去除
            while(left<=right&&(needs[s[left]] == 0 || (hadGet[s[left]] > needs[s[left]]))){
                if(hadGet[s[left]]!=0){--hadGet[s[left]];}
                ++left;
            }
            // 判断是否符合要求,若匹配成功,则进行更新字符串起始位置和长度
            if(getSum==needSum&&(res_le==0||res_le>right-left+1)){
                res_st = left;
                res_le = right-left+1;
            }
        }
    }
    return s.substr(res_st,res_le);
}

// 组合
/* 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合
 * */
// 递归当长度符合条件时进行插入
vector<vector<int>> Solution::combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> temp;
    co_combine(1,n+1,k,temp,res);
    return res;
}
void Solution::co_combine(int start,int n,int max,vector<int> &p,vector<vector<int>> &res){
    if(p.size()==max){
        res.push_back(p);
    }
    for(int i=start;i<n;++i){
        p.push_back(i);
        co_combine(i+1,n,max,p,res);
        p.pop_back();
    }
}

// 子集
/* 给定一组不含重复元素的整数数组 nums
 * 返回该数组所有可能的子集（幂集）
 * 说明：解集不能包含重复的子集
 * */
// 递归--在每一层都进行加入结果、直到和所给数组长度一致
vector<vector<int>> Solution::subsets(vector<int>& nums) {
    vector<vector<int>> res{{}};
    vector<int> temp;
    co_subsets(0,nums,temp,res);
    return res;
}
void Solution::co_subsets(int start,vector<int>& nums,vector<int> &p,vector<vector<int>> &res){
    // 当长度满足时进行中止
    if(p.size()==nums.size()){
        return;
    }
    // 进行递归--先压入进行递归、再弹出压入结果
    for(int i=start;i<nums.size();++i){
        p.push_back(nums[i]);
        co_subsets(i+1,nums,p,res);
        res.push_back(p);
        p.pop_back();
    }
}

// 单词搜索
/* 给定一个二维网格和一个单词，找出该单词是否存在于网格中
 * 单词必须按照字母顺序,通过相邻的单元格内的字母构成,其中“相邻”单元格是那些水平相邻或垂直相邻的单元格
 * 同一个单元格内的字母不允许被重复使用
 * */
// 递归-首先寻找第一个字母、从第一个字母处开始深度搜索、期间利用#占位防止重复搜索
bool Solution::exist(vector<vector<char>>& board, const string& word) {
    int row = board.size();
    int col = board[0].size();
    // 寻找第一个字母作为起点进行深度搜索
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if(board[i][j]==word[0]){
                // #占位、深度搜索、返回结果后进行删除占位
                board[i][j] = '#';
                bool res = co_exist(board,word,1,i,j);
                board[i][j] = word[0];
                // 若搜索完成存在单词则直接返回true
                if(res){
                    return true;
                }
            }
        }
    }
    // 若未搜索到则返回false
    return false;
}
bool Solution::co_exist(vector<vector<char>>& board, const string& word,int index,int x,int y) {
    // 搜索到末尾则直接返回true
    if(index==word.size()){
        return true;
    }
    int row = board.size();
    int col = board[0].size();
    // 判断下方
    if(x+1<row&&board[x+1][y]!='#'&&board[x+1][y]==word[index]){
        board[x+1][y] = '#';
        bool temp = co_exist(board,word,index+1,x+1,y);
        board[x+1][y] = word[index];
        if(temp){
            return true;
        }
    }
    // 判断上方
    if(x-1>=0&&board[x-1][y]!='#'&&board[x-1][y]==word[index]){
        board[x-1][y] = '#';
        bool temp = co_exist(board,word,index+1,x-1,y);
        board[x-1][y] = word[index];
        if(temp){
            return true;
        }
    }
    // 判断右方
    if(y+1<col&&board[x][y+1]!='#'&&board[x][y+1]==word[index]){
        board[x][y+1] = '#';
        bool temp = co_exist(board,word,index+1,x,y+1);
        board[x][y+1] = word[index];
        if(temp){
            return true;
        }
    }
    // 判断左方
    if(y-1>=0&&board[x][y-1]!='#'&&board[x][y-1]==word[index]){
        board[x][y-1] = false;
        bool temp = co_exist(board,word,index+1,x,y-1);
        board[x][y-1] = word[index];
        if(temp){
            return true;
        }
    }
    return false;
}

// 删除排序数组中的重复项 II
/* 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度
 * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成
 * */
// 遍历并填入
int Solution::removeDuplicates2(vector<int>& nums) {
    int index = -1;
    int count = 1;
    for(int i=0;i<nums.size();++i){
        cout <<nums[i]<<" ";
        if(i==0||nums[i]!=nums[index]){
            ++index;
            nums[index] = nums[i];
            count = 1;
        }else if(count<2&&nums[i]==nums[index]){
            ++index;
            nums[index] = nums[i];
            ++count;
        }
    }
    return index+1;
}

// 机器人的运动范围
/* 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1]
 * 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外）
 * 也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18
 * 但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
 * */
// 判断上方和左方是否有路径,有路径即可到达
int Solution::movingCount(int m, int n, int k) {
    if (!k) return 1;
    vector<vector<int> > vis(m, vector<int>(n, 0));
    int ans = 1;
    vis[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i == 0 && j == 0) || co_movingCount(i) + co_movingCount(j) > k){
                continue;
            }
            // 边界判断,位操作需要对无符号进行操作,故提前进行转换
            if (i - 1 >= 0){
                auto temp = static_cast<unsigned int>(vis[i][j]);
                temp |= static_cast<unsigned int>(vis[i - 1][j]);
                vis[i][j] = temp;
            }
            if (j - 1 >= 0){
                auto temp = static_cast<unsigned int>(vis[i][j]);
                temp |= static_cast<unsigned int>(vis[i][j - 1]);
                vis[i][j] = temp;
            }
            ans += vis[i][j];
        }
    }
    return ans;
}
// 计算纵横坐标各位数之和
int Solution::co_movingCount(int x) {
    int res=0;
    for (; x; x /= 10){
        res += x % 10;
    }
    return res;
}

// 翻转字符串里的单词
/* 给定一个字符串，逐个翻转字符串中的每个单词
 * */
// 从后向前扫描单词起始点后进行拷贝最后进行输出
string Solution::reverseWords(string s) {
    int le = s.size();
    int en = le;
    string res;
    for(int i=le-1;i>=0;--i){
        if(s[i]!=' '&&(i==le-1||s[i+1]==' ')){
            en = i+1;
        }
        if(s[i]!=' '&&(i==0||s[i-1]==' ')){
            res += s.substr(i,en-i);
            res += ' ';
        }
    }
    return res.substr(0,res.size()-1);
}

// 鸡蛋掉落
/* 你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑
 * 每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去
 * 你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破
 * 每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）
 * 你的目标是确切地知道 F 的值是多少
 * 无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少?
 * */
int Solution::superEggDrop(int K, int N) {
    // 鸡蛋数量为k时,每层的次数
    int dp[N + 1];
    // 对于每层楼1个鸡蛋所需要的投掷次数
    for (int i = 0; i <= N; ++i) dp[i] = i;
    // 对于每层楼K个鸡蛋所需要的投掷次数
    for (int k = 2; k <= K; ++k) {
        int dp2[N + 1];
        int x = 1;
        dp2[0] = 0;
        // 动态规划,首先求1层时的次数逐步求出N层时的次数
        for (int n = 1; n <= N; ++n) {
            // 在每种情况中寻找最小值,由于先减后增故发现第一个增加的时候或到末尾时进行跳出
            while (x < n && max(dp[x-1], dp2[n-x]) >= max(dp[x], dp2[n-x-1])) {
                x++;
            }
            // 使用在x层投掷的结果更新第n层次数
            dp2[n] = 1 + max(dp[x-1], dp2[n-x]);
        }
        // 刷新dp数组
        for (int n = 1; n <= N; ++n) dp[n] = dp2[n];
    }
    return dp[N];
}

// 搜索旋转排序数组 II
/* 假设按照升序排序的数组在预先未知的某个点上进行了旋转
 * ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )
 * 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false
 * */
// 相对于I将两端重复值去掉一边即可
bool Solution::searchII(vector<int>& nums, int target) {
    if(nums.empty()){
        return -1;
    }
    int le = nums.size(),res=-1,pot=le-1;
    int st=0;
    // 二分查找查找翻转点
    while(nums[st]==nums[pot]){
        --pot;
    }
    while(st<=pot){
        int mid = (st+pot)/2;
        if(mid<le-1&&nums[mid]>nums[mid+1]){
            pot = mid;
            break;
        }else{
            if(nums[mid] < nums[st]){
                pot = mid-1;
            }else{
                st = mid+1;
            }
        }
    }
    cout << pot <<endl;
    // 和尾部值进行比较,即翻转前前半段的最大值,若大于最大值则在翻转点之前进行查找,否则在翻转点之后进行查找
    if(target>nums[le-1]||pot==le-1){
        // 调用之前写过的二分算法
        res =divide_search(nums,0,pot,target);
    }else{
        res =divide_search(nums,pot+1,le-1,target);
    }
    return res!=-1;
}

// 删除排序链表中的重复元素
/* 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次
 * */
// 和记录中上一个值相比较看是否相同,相同则跳过
ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode res(0);
    ListNode *index = &res;
    ListNode *p = head;
    int temp = p->val+1;
    while(p){
        auto t = p;
        p = p->next;
        if(t->val!=temp){
            temp = t->val;
            index->next = t;
            index = index->next;
        }else{
            delete t;
        }
    }
    index->next = nullptr;
    return res.next;
}

// 删除排序链表中的重复元素 II
/* 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现的数字
 * */
// 和记录的末尾相比较,若相同则删除末尾并跳过
ListNode* Solution::deleteDuplicatesII(ListNode* head) {
    ListNode res(0);
    ListNode *index = &res;
    ListNode *p = head;
    index->next = p;
    p = p->next;
    while(p){
        // 不同直接插入
        if(index->next->val!=p->val){
            index = index->next;
            index->next = p;
            p = p->next;
        }else{
            // 跳过相同值的节点
            while(p&&p->val==index->next->val){
                p = p->next;
            }
            index->next = p;
            // 判断是否到达末尾
            if(!index->next){
                return res.next;
            }
            p = p->next;
        }
    }
    return res.next;
}

// 两数相加 II
/* 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置
 * 它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头
 * */
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while (l1) {
        s1.push(l1 -> val);
        l1 = l1 -> next;
    }
    while (l2) {
        s2.push(l2 -> val);
        l2 = l2 -> next;
    }
    int carry = 0;
    ListNode* ans = nullptr;
    while (!s1.empty() or !s2.empty() or carry != 0) {
        int a = s1.empty() ? 0 : s1.top();
        int b = s2.empty() ? 0 : s2.top();
        if (!s1.empty()) s1.pop();
        if (!s2.empty()) s2.pop();
        int cur = a + b + carry;
        carry = cur / 10;
        cur %= 10;
        auto curnode = new ListNode(cur);
        curnode -> next = ans;
        ans = curnode;
    }
    return ans;
}

// 01矩阵
/* 给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离
 * 两个相邻元素间的距离为 1
 * */
vector<vector<int>> Solution::updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    // 初始化动态规划的数组，所有的距离值都设置为一个很大的数
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX / 2));
    // 如果 (i, j) 的元素为 0，那么距离为 0
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }
    // 只有 水平向左移动 和 竖直向上移动，注意动态规划的计算顺序
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - 1 >= 0) {
                dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
            }
            if (j - 1 >= 0) {
                dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
            }
        }
    }
    // 只有 水平向右移动 和 竖直向下移动，注意动态规划的计算顺序
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i + 1 < m) {
                dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
            }
            if (j + 1 < n) {
                dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
    }
    return dist;
}

// 柱状图中最大的矩形
/* 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积
 * */
int Solution::largestRectangleArea(vector<int>& heights) {
    if(heights.empty()){
        return 0;
    }
    int le = heights.size();
    // 模拟栈--存储下标
    int *dp = (int *)malloc(sizeof(int)*(le+1));
    int index = 0;
    dp[0] = -1;
    int max = 0;
    for(int i=0;i<le+1;++i){
        while(index!=0&&(i==le||heights[i]< heights[dp[index]])){
            // 弹出栈顶
            int temp = heights[dp[index--]];
            // 计算面积
            int sum = temp*(i-dp[index]-1);
            max = max>sum?max:sum;
        }
        if(i<le){
            dp[++index] = i;
        }
    }
    free(dp);
    return max;
}

// 统计重复个数
/* 由 n 个连接的字符串 s 组成字符串 S，记作 S = [s,n]。例如，["abc",3]=“abcabcabc”
 * 如果我们可以从 s2 中删除某些字符使其变为 s1，则称字符串 s1 可以从字符串 s2 获得
 * 例如，根据定义，"abc" 可以从 “abdbec” 获得，但不能从 “acbbe” 获得
 * 现在给你两个非空字符串 s1 和 s2（每个最多 100 个字符长）和两个整数 0 ≤ n1 ≤ 106 和 1 ≤ n2 ≤ 106
 * 现在考虑字符串 S1 和 S2，其中 S1=[s1,n1] 、S2=[s2,n2]
 * 请你找出一个可以满足使[S2,M] 从 S1 获得的最大整数 M
 * */
// 贪心,当可以整组划分时之后使用除法进行化简
int Solution::getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int l1 = s1.size();
    int l2 = s2.size();
    int i=0;
    int j=0;
    int sum = 0;
    // 计算有多少组s2
    while(n1>0){
        if(s1[i]==s2[j]){
            ++j;
            if(j==l2){
                ++sum;
                j=0;
            }
        }
        ++i;
        if(i==l1){
            --n1;
            i=0;
        }
    }
    // 除法得出组数
    return sum/n2;
}

// 岛屿数量
/* 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成
 * 此外，你可以假设该网格的四条边均被水包围
 * */
// 广度搜索BFS
int Solution::numIslands(vector<vector<char>>& grid) {
    if(grid.empty()||grid[0].empty()){
        return 0;
    }
    int row = grid.size();
    int col = grid[0].size();
    int res = 0;
    // 对每个进行广度搜索,搜索过的为一个整岛,置空
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if(grid[i][j]=='1'){
                ++res;
                numIslandsBFS(grid,i,j);
            }
        }
    }
    return res;
}
void Solution::numIslandsBFS(vector<vector<char>>& grid,int x,int y){
    int row = grid.size();
    int col = grid[0].size();
    grid[x][y] = '0';
    if(x-1>=0&&grid[x-1][y]=='1'){
        numIslandsBFS(grid,x-1,y);
    }
    if(x+1<row&&grid[x+1][y]=='1'){
        grid[x+1][y] = '0';
        numIslandsBFS(grid,x+1,y);
    }
    if(y-1>=0&&grid[x][y-1]=='1'){
        numIslandsBFS(grid,x,y-1);
    }
    if(y+1<col&&grid[x][y+1]=='1'){
        numIslandsBFS(grid,x,y+1);
    }
}

// 统计「优美子数组」
/* 给你一个整数数组 nums 和一个整数 k
 * 如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」
 * 请返回这个数组中「优美子数组」的数目
 * */
int Solution::numberOfSubArrays(vector<int>& nums, int k) {
    int le = nums.size();
    int left=0;
    int right=0;
    int count=0;
    int res = 0;
    // 划分奇偶性,取并为1为奇,取并为0为偶
    for(auto &i:nums){
        i = static_cast<unsigned int>(i)&0x1u;
    }
    // 窗口,通过放缩窗口进行取奇数
    while(left<le&&right<le){
        if(nums[right]){
            ++count;
        }
        ++right;
        // 判断前方有多少0以及后方有多少0,乘积即为包含这k个1的优美子数组个数
        if(count==k){
            int c_left=0;
            int c_right=0;
            while(left<le&&!nums[left]){
                ++left;
                ++c_left;
            }
            while(right<le&&!nums[right]){
                ++right;
                ++c_right;
            }
            res +=(c_right+1)*(c_left+1);
            ++left;
            --count;
        }
    }
    return  res;
}

// 二叉树的右视图
/* 给定一棵二叉树,想象自己站在它的右侧,按照从顶部到底部的顺序,返回从右侧所能看到的节点值
 * */
// 按照右->根->左进行遍历树,同时记录当前最深层数,仅当刷新最深层数时进行插入结果
vector<int> Solution::rightSideView(TreeNode* root) {
    vector<int> res;
    int max = -1;
    co_rightSideView(root,max,0,res);
    return res;
}
void Solution::co_rightSideView(TreeNode* root,int &max,int deep,vector<int> &res) {
    if(root){
        if(deep>max){
            res.insert(res.begin(),root->val);
            max += 1;
        }
        co_rightSideView(root->right,max,deep+1,res);
        co_rightSideView(root->left,max,deep,res);
    }
}

// 最大矩形
/* 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积
 * */
// 栈做法(类似柱状图)-时间O(MN),空间O(M)
int Solution::maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty()||matrix[0].empty()){
        return 0;
    }
    int row = matrix.size();
    int col = matrix[0].size();
    int max = 0;
    int *dp = static_cast<int *>(malloc(sizeof(int)*(col+1)));
    int index = 0;
    dp[0] = -1;
    for(int i=0;i<row;++i){
        for(int j=0;j<col+1;++j){
            if(i>0&&j<col&&matrix[i][j]=='1'){
                matrix[i][j] = matrix[i-1][j]+matrix[i][j]-48;
            }
            if(j<col){
                cout << matrix[i][j] <<" ";
            }
            while(index!=0&&(j==col||matrix[i][j]<matrix[i][dp[index]])){
                int temp = matrix[i][dp[index--]]-48;
                int s = (j-dp[index]-1)*temp;
                max = max<s?s:max;
            }
            if(j<col){
                dp[++index] = j;
            }
        }
        cout <<endl;
    }
    free(dp);
    return max;
}

// 最大正方形
/* 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积
 * */
// 动态规划,自己为1,且当左,左上,上均为n×n的时候,才能扩充为(n+1)×(n+1)
int Solution::maximalSquare(vector<vector<char>>& matrix){
    if(matrix.empty()||matrix[0].empty()){
        return 0;
    }
    int row = matrix.size();
    int col = matrix[0].size();
    // 压缩数组,一维代替二维
    int *dp = new int[col+1];
    for(int index=0;index<=col;++index){
        dp[index] = 0;
    }
    int maxN = 0;
    // 动规遍历
    for(int i=1;i<=row;++i){
        int temp = 0;
        for(int j=1;j<=col;++j){
            int sign = dp[j];
            if(matrix[i-1][j-1]=='1'){
                dp[j] = min(min(dp[j-1],dp[j]),temp)+1;     // 扩充正方形
                if(maxN<dp[j]){
                    maxN = dp[j];
                }
            }else{
                dp[j] = 0;
            }
            temp = sign;
        }
    }
    // 删除分配的数组
    delete [] dp;
    return maxN*maxN;
}

// 分隔链表
/* 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前
 * 你应当保留两个分区中每个节点的初始相对位置
 * */
// 利用哑节点作为两个篮子,以x作为分界,放入篮子
ListNode* Solution::partition(ListNode* head, int x) {
    ListNode left(0);
    ListNode right(0);
    ListNode* p=head;
    ListNode* pl = &left;
    ListNode* pr = &right;
    while(p){
        if(p->val<x){
            pl->next = p;
            pl = pl->next;
        }else{
            pr->next = p;
            pr = pr->next;
        }
        p = p->next;
    }
    pr->next = nullptr;
    pl->next = right.next;
    return left.next;
}

// 数组中数字出现的次数
/*一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字
 * 要求时间复杂度是O(n)，空间复杂度是O(1)
 * */
// 利用了亦或的特性,0^1=1,0^0=1^1=0,若两数字相同则会亦或为0,最后结果为不同数字的亦或
vector<int> Solution::singleNumbers(vector<int>& nums) {
    unsigned int ret = 0;
    // 得到两个不同数字的亦或,其余成为0
    for (int n : nums)
        ret ^= static_cast<unsigned int>(n);
    unsigned int div = 1;
    // 寻找一个为1的位,作为区分两个数字的特征,将数字分为两部分
    while ((div & ret) == 0)
        div <<= 1u;
    unsigned int a = 0, b = 0;
    // 分别对每组进行亦或,每组仅有一个不同的数字,亦或结果即为不同的两个数字
    for (int n : nums)
        if (div & static_cast<unsigned int>(n))
            a ^= static_cast<unsigned int>(n);
        else
            b ^= static_cast<unsigned int>(n);
    return vector<int>{static_cast<int>(a), static_cast<int>(b)};
}

// 扰乱字符串
/* 给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树
 * 在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点
 * 同样地，如果我们继续交换节点的子节点，将会产生另一个新的扰乱字符串
 * 给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串
 * */
// 若为扰乱字符串,则其子串也为扰乱字符串
bool Solution::isScramble(const string& s1, const string& s2) {
    if (s1.size() != s2.size())
        return false;
    return isScrambleRecursion(s1, s2);
}
bool Solution::isScrambleRecursion(const string& s1, const string& s2)
{
    if (s1 == s2)
        return true;
    //防止超时，若s1中所有字符在s2中不都存在，说明s1无论怎么分割和s2无法匹配，直接返回false，大大优化效率
    string t1 = s1, t2 = s2;
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    if (t1 != t2)
        return false;
    //i从1到s1.size-1，不能从下标0开始，至少分割1个字符出来，否则无法跳出循环
    for (int i = 1; i < s1.size(); i++)
    {
        //将s1分割成[0,i)[i,s1.size)对应s2匹配可能是[0,i)[i,s1.size)也可能是[s2.size-i,s2.size)[0,s2.size()-i)
        bool flag1 = isScrambleRecursion(s1.substr(0, i), s2.substr(0, i)) && isScrambleRecursion(s1.substr(i,s1.size()-i), s2.substr(i,s2.size()-i));
        bool flag2 = isScrambleRecursion(s1.substr(0, i), s2.substr(s2.size() - i, i)) && isScrambleRecursion(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i));
        if (flag1 || flag2)
            return true;
    }
    return false;
}

// 快乐数
/* 编写一个算法来判断一个数 n 是不是快乐数
 *「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1
 * 如果 可以变为  1，那么这个数就是快乐数
 * 如果 n 是快乐数就返回 True ；不是，则返回 False
 * */
// 快慢指针法,若不能为1则会陷入循环,慢指针将会追上快指针,isHappyNext用于生成下一个数
bool Solution::isHappy(int n) {
    int slow = n;
    int fast = n;
    do{
        slow = isHappyNext(slow);
        fast = isHappyNext(isHappyNext(fast));
        cout <<slow << " " << fast <<endl;
        if(fast==1){
            return true;
        }
    }while(slow!=fast);
    return false;
}
int Solution::isHappyNext(int n) {
    int res=0;
    while(n){
        int temp = n%10;
        res += temp*temp;
        n /= 10;
    }
    return res;
}


// 合并两个有序数组
/* 给你两个有序整数数组 nums1 和 nums2
 * 请你将 nums2 合并到 nums1 中
 * 使 nums1 成为一个有序数组
 * */
// 从第m+n位置进行插入,比较插入,最后若nums2不为空则将剩余数字直接插入
void Solution::arrayMerge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    while(m&&n){
        if(nums1[m-1] >= nums2[n-1]){
            nums1[m + n - 1]=nums1[m-1];
            --m;
        }else{
            nums1[m + n - 1]=nums2[n-1];
            --n;
        }
    }
    while(n){
        nums1[n-1] = nums2[n-1];
        --n;
    }
}

// 格雷编码
/* 格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异
 * 给定一个代表编码总位数的非负整数 n，打印其格雷编码序列
 * 即使有多个不同答案，你也只需要返回其中一种
 * 格雷编码序列必须以 0 开头
 * */
// 镜像翻转法,翻转n-1情况下的结果,与1<<=n-1进行并处理,同时追加入
vector<int> Solution::grayCode(int n) {
    // 0和1时的特殊情况
    if(n==0){
        return vector<int>{0};
    }
    if(n==1){
        return vector<int>{0,1};
    }
    // 通过x与数字取交,将倒数第n位上打上1
    unsigned int x = 1;
    x <<= static_cast<unsigned int>(n-1);
    // 生成n-1位的格雷编码
    auto res = grayCode(n - 1);
    int l = res.size();
    // 镜像n-1的格雷编码并与x取交,将结果加入回n-1格雷编码队列,此时结果为
    for(int i=l-1;i>=0;--i){
        res.push_back(x | static_cast<unsigned int>(res[i]));
    }
    // 返回格雷编码
    return res;
}
// 格雷编码循环版本解法,相比于递归版,减少了数组的拷贝
/*vector<int> Solution::grayCode(int n) {
    vector<int> res;
    res.push_back(0);
    if(n==0){
        return res;
    }
    res.push_back(1);
    if(n==1){
        return res;
    }
    unsigned int x = 1;
    x <<= 2u;
    for(int i=0;i<n-2;++i){
        int l = res.size();
        for(int j=l-1;j>=0;--j){
            res.push_back(x | static_cast<unsigned int>(res[j]));
        }
        x <<= 1u;
    }
    return res;
}*/

// 子集II
/* 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）
 * 说明：解集不能包含重复的子集
 * */
// 主函数进行排序,并调用递归;递归进行查重,并压入结果
vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<int> temp;
    vector<vector<int>> res{vector<int>{}};
    // 初始化递归,答案为空,已选为空,起始点为0
    recursiveSubsetsWithDup(nums,res,temp,0);
    return res;
}
void Solution::recursiveSubsetsWithDup(vector<int>& nums,vector<vector<int>> &res,vector<int> &temp,int deep) {
    int ln = nums.size();
    // 长度符合要求则停止递归
    if(ln==temp.size()){
        return;
    }
    // 当同一层遇到重复数字时跳过,递归时,下一层从所选数字下一个进行选择
    for(int i=deep;i<ln;++i){
        if(i==deep||nums[i]!=nums[i-1]){
            temp.push_back(nums[i]);
            res.push_back(temp);
            recursiveSubsetsWithDup(nums,res,temp,i+1);
            temp.pop_back();
        }
    }
}


// 解码方法
/* 一条包含字母 A-Z 的消息通过以下方式进行了编码
 * "A"-1..."z"-26
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数
 * */
// 类似斐波那契,爬楼梯
int Solution::numDecoding(string s) {
    int l = s.size();
    if(s[0]=='0'){
        return 0;
    }
    int left = 1;   // 末尾为两个一组的个数
    int right = 1;  // 末尾为单个一组的个数
    for(int i=1;i<l;++i){
        int temp = 0;
        // 末尾两个可以组成两位数的情况,1X和2[0-6]
        if(s[i-1]=='1'||s[i-1]=='2'&&s[i]<'7'){
            temp += left;
        }
        // 自己可以单独成一个的情况,X!=0
        if(s[i]!='0'){
            temp += right;
        }
        left = right;
        right = temp;
    }
    return right;
}

// 反转链表 II
/* 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转
 * 说明: 1 ≤ m ≤ n ≤ 链表长度
 * */
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    ListNode nodeFirst(0);  //使用哑节点避免head为nullptr
    nodeFirst.next = head;
    ListNode *p = nodeFirst.next;   // 遍历元素
    ListNode *q = &nodeFirst;   // 记录翻转起始点
    ListNode *tail = q; // 记录末尾
    int c = 1;
    while(p){
        if(c>=m&&c<=n){
            // 插入,先调整tail与q的位置,之后再q之后进行插入
            if(c==m){
                tail->next = p;
                p=p->next;
                tail = tail->next;
            }else{
                ListNode *temp = q->next;
                q->next = p;
                p=p->next;
                q->next->next = temp;
            }
        }else{
            // 跟随,直接接在tail后面
            tail->next = p;
            p=p->next;
            q = tail->next;
            tail = tail->next;
        }
        ++c;
    }
    tail->next = nullptr;
    return nodeFirst.next;
}

// 复原IP地址
/* 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式
 * */
// 分段截取,截取4段数字,3个点,若最后长度为s.size()+3==temp.size(),说明点的位置正确,加入结果,否则舍去
vector<string> Solution::restoreIpAddresses(string s) {
    vector<string> res;
    string temp;
    coRestoreIpAddresses(s,res,temp,0,0);
    return res;
}
void Solution::coRestoreIpAddresses(string &s,vector<string> &res,const string& temp,int st,int dot) {
    // cout <<temp <<endl;
    if(dot==4){
        if(temp.size()==s.size()+3){
            res.push_back(temp);
        }
        return;
    }
    for(int i=1;i<4&&i+st<=s.size();++i){
        string p(s.substr(st,i));
        if(p.size()!=1&&p[0]=='0'){
            return;
        }
        if(i==1||i==2||((p[0]<'3')&&(p[0]=='1'||p[1]<'5'||(p[1]=='5'&&p[2]<='5')))){
            if(dot==3){
                coRestoreIpAddresses(s,res,temp+p,st+i,dot+1);
            }else{
                coRestoreIpAddresses(s,res,temp+p+'.',st+i,dot+1);
            }
        }
    }
}

// 二叉树的中序遍历
/* 给定一个二叉树，返回它的中序遍历
 * */
// 栈做法,连续压入左节点,直到不能压入,后弹出并记录左根右
vector<int> Solution::inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}

// 不同的二叉搜索树 II
/* 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树
 * */
// 取一节点将数字分为两部分,进行递归求解
vector<TreeNode*> Solution::generateTrees(int n) {
    if (n == 0) {
        return vector<TreeNode*>{};
    }
    return generate_trees(1, n);
}
vector<TreeNode*> Solution::generate_trees(int start, int end) {
    // 存储[start,end]的解
    vector<TreeNode*> all_trees;
    // 当start>end时无法递归插入,故插入nullptr返回
    if (start > end) {
        all_trees.push_back(nullptr);
        return all_trees;
    }
    // 取分隔点
    for (int i = start; i <= end; i++) {
        auto left_trees = generate_trees(start,i-1);
        auto right_trees = generate_trees(i+1,end);
        // 将结果插入分隔点两边,共有m×n个
        for (auto l : left_trees) {
            for (auto r : right_trees) {
                auto current_tree = new TreeNode(i);
                current_tree->left = l;
                current_tree->right = r;
                all_trees.push_back(current_tree);
            }
        }
    }
    return all_trees;
}

// 不同的二叉搜索树
/* 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * */
// 即计算卡特兰数,可采取动态规划和公式
int Solution::numTrees(int n) {
    vector<int> G(n+1,0);
    G[0] = 1;
    G[1] = 1;
    // 笛卡尔积,取分隔点,左部分为j个右部分为i-j个
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            G[i] += G[j - 1] * G[i - j];
        }
    }
    return G[n];
}

// 交错字符串
/* 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的
 * */
// 动态规划,二维数组压缩一维
bool Solution::isInterleave(string s1, string s2, string s3) {
    if (s3.length() != s1.length() + s2.length()) {
        return false;
    }
    vector<bool> dp(s2.size()+1,false);
    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            if (i == 0 && j == 0) {
                dp[j] = true;
            } else if (i == 0) {
                dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
            } else if (j == 0) {
                dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
            } else {
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
    }
    return dp[s2.size()];
}

// 验证二叉搜索树
/* 给定一个二叉树，判断其是否是一个有效的二叉搜索树
 * 假设一个二叉搜索树具有如下特征：
 * 节点的左子树只包含小于当前节点的数
 * 节点的右子树只包含大于当前节点的数
 * 所有左子树和右子树自身必须也是二叉搜索树
 * */
// (迭代)中序遍历结果为升序,即右>根>左
bool Solution::isValidBST(TreeNode* root) {
    long long res = static_cast<long long>(INT_MIN)-1;
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        if(curr->val<=res){
            return false;
        }
        res = curr->val;
        curr = curr->right;
    }
    return true;
}

// 最低票价
/* 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行
 * 在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出
 * 每一项是一个从 1 到 365 的整数
 * 火车票有三种不同的销售方式：
 * 一张为期一天的通行证售价为 costs[0] 美元
 * 一张为期七天的通行证售价为 costs[1] 美元
 * 一张为期三十天的通行证售价为 costs[2] 美元
 * 通行证允许数天无限制的旅行
 * 返回你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费
 * */
// 倒序递归
int Solution::mincostTickets(vector<int>& days, vector<int>& costs) {
    int le = days.size();
    int dp[366]={0};
    int index = le-1;
    for(int i=365;i>0;--i){
        if(i==days[index]){
            dp[i] = min(min((i<365?dp[i+1]:0)+costs[0],(i<358?dp[i+7]:0)+costs[1]),(i<335?dp[i+30]:0)+costs[2]);
            --index;
            if(index<0){
                dp[1] = dp[i];
                break;
            }
        }else if(i<365){
            dp[i] = dp[i+1];
        }
    }
    return dp[1];
}


// 相同的树
/* 给定两个二叉树，编写一个函数来检验它们是否相同
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的
 * */
bool Solution::isSameTree(TreeNode* p, TreeNode* q) {
    if(p==nullptr||q==nullptr){
        return p==q;
    }
    if(p->val==q->val){
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
    return false;
}

// 对称二叉树
/* 给定一个二叉树，检查它是否是镜像对称的
 * */
bool Solution::isSymmetric(TreeNode* root) {
    return coIsSymmetric(root,root);
}
bool Solution::coIsSymmetric(TreeNode* root_l,TreeNode* root_r) {
    if(root_l==nullptr||root_r==nullptr){
        return root_l==root_r;
    }
    return (root_l->val==root_r->val)&&coIsSymmetric(root_l->left,root_r->right)&&coIsSymmetric(root_l->right,root_r->left);
}

// 二叉树的层序遍历
/* 给你一个二叉树，请你返回其按层序遍历得到的节点值
 * 即逐层地，从左到右访问所有节点
 * */
// 队列迭代法
vector<vector<int>> Solution::levelOrder(TreeNode* root) {
    queue<TreeNode*> platform;
    if(root){
        platform.push(root);
    }
    vector<vector<int>> res;
    while(!platform.empty()){
        queue<TreeNode*> nextQueue;
        vector<int> temp;
        while(!platform.empty()){
            auto p =platform.front();
            platform.pop();
            temp.push_back(p->val);
            if(p->left){
                nextQueue.push(p->left);
            }
            if(p->right){
                nextQueue.push(p->right);
            }
        }
        res.push_back(temp);
        swap(platform,nextQueue);
    }
    return res;
}

// 只出现一次的数字
/* 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素
 * 说明：
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗
 * */
int Solution::singleNumber(vector<int>& nums) {
    unsigned int sign=0;
    for(auto i:nums){
        sign ^= static_cast<unsigned int>(i);
    }
    return static_cast<int>(sign);
}

// 二叉树的锯齿形层次遍历
/* 给定一个二叉树，返回其节点值的锯齿形层次遍历
 * 即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行
 */
// 层序遍历生成层序结果,奇数翻转偶数不翻转
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*> platform;
    if(root){
        platform.push(root);
    }
    vector<vector<int>> res;
    while(!platform.empty()){
        queue<TreeNode*> nextQueue;
        vector<int> temp;
        while(!platform.empty()){
            auto p =platform.front();
            platform.pop();
            temp.push_back(p->val);
            if(p->left){
                nextQueue.push(p->left);
            }
            if(p->right){
                nextQueue.push(p->right);
            }
        }
        res.push_back(temp);
        swap(platform,nextQueue);
    }
    for(int k=0;k<res.size();++k){
        if(k%2){

            for(int f=0;f<res[k].size()/2;++f){
                int temp = res[k][f];
                res[k][f] = res[k][res[k].size()-1-f];
                res[k][res[k].size()-1-f] = temp;
            }

        }
    }
    return res;
}

// 和为K的子数组
/* 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数
 * */
// 根据递推公式pre[i] = pre[i-1] + nums[i]和dp[i][j] = dp[0][j] - dp[0][i]进行优化
int Solution::subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp; // 记录和出现的次数
    mp[0] = 1;  // 和为0必定出现1次
    int count = 0, pre = 0; // 计数和已遍历的所有项总和
    for (auto& x:nums) {    // 遍历,更新pre
        pre += x;
        if (mp.find(pre - k) != mp.end()){
            count += mp[pre - k];   //查看是否存在和为pre-k的情况,若存在则说明可以进行截断,并将次数相加
        }
        mp[pre]++;  // 更新对应和出现次数
    }
    return count;
}

// 从前序与中序遍历序列构造二叉树
/* 根据一棵树的前序遍历与中序遍历构造二叉树
 * 注意:你可以假设树中没有重复的元素
 * */
// 利用前序与中序性质递归建树,前序第一个为根节点,中序以前序的根节点为间隔分为左右两树
TreeNode* Solution::buildTree1(vector<int>& preorder, vector<int>& inorder) {
    return coBuildTree1(preorder,0,preorder.size(),inorder,0,inorder.size());
}
TreeNode* Solution::coBuildTree1(vector<int>& preorder,int x,int y,vector<int>& inorder,int p,int q){
    if(x>=y||p>=q){
        return nullptr;
    }
    int rootNum = preorder[x];
    auto *root = new TreeNode(rootNum);
    int i=p;
    while(rootNum != inorder[i]&&i<q){
        ++i;
    }
    root->left = coBuildTree1(preorder,x+1,x+i-p+1,inorder,p,i);
    root->right = coBuildTree1(preorder,x+i-p+1,y,inorder,i+1,q);
    return root;
}

// 从中序与后序遍历序列构造二叉树
/* 根据一棵树的中序遍历与后序遍历构造二叉树
 * 注意:你可以假设树中没有重复的元素
 * */
// 利用中序与后序性质递归建树,后序最后一个为根节点,中序以前序的根节点为间隔分为左右两树
TreeNode* Solution::buildTree2(vector<int>& inorder, vector<int>& postorder) {
    return coBuildTree2(inorder,0,inorder.size(),postorder,0,postorder.size());
}
TreeNode* Solution::coBuildTree2(vector<int>& inorder,int x,int y,vector<int>& postorder,int p,int q) {
    if(x>=y||p>=q){
        return nullptr;
    }
    int rootNum = postorder[q-1];
    auto *root = new TreeNode(rootNum);
    int i=x;
    while(rootNum != inorder[i]&&i<y){
        ++i;
    }
    root->left = coBuildTree2(inorder,x,i,postorder,p,p+i-x);
    root->right = coBuildTree2(inorder,i+1,y,postorder,p+i-x,q-1);
    return root;
}

// 总持续时间可被 60 整除的歌曲
/* 在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒
 * 返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量
 * 形式上，我们希望索引的数字 i 和 j 满足  i < j 且有 (time[i] + time[j]) % 60 == 0
 * */
// 余数仅不能整除的部分起作用,故对每项取余并记录个数,可以在O(1)的时间复杂度内取得另一半的个数
int Solution::numPairsDivisibleBy60(vector<int>& time) {
    int dp[60] = {0};
    int s=0;
    for(auto i:time){
        int temp = i%60;
        s += dp[(60-temp)%60];
        ++dp[temp];
    }
    return s;
}


// 乘积最大子数组
/* 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积
 * */
// 建立两个数组maxF,minF,一个存储最大值,一个存储最小值,当nums[i]为负数时最小值将会可能大于最大值
// maxF[i]存储maxF[i-1]*nums[i],minF[i]*nums[i],nums[i]最大值
// minF[i]存储maxF[i-1]*nums[i],minF[i]*nums[i],nums[i]最小值
int Solution::maxProduct(vector<int>& nums) {
    int maxF = nums[0], minF = nums[0], ans = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        int mx = maxF, mn = minF;
        maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
        minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
        ans = max(maxF, ans);
    }
    return ans;
}

// 验证回文字符串 Ⅱ
/* 给定一个非空字符串 s，最多删除一个字符
 * 判断是否能成为回文字符串
 * */
// 双向向内收缩,若出现不匹配则删除两端其中一个且删除后为回文串
// validPalindrome主函数,checkPalindrome回文串判断函数
bool Solution::validPalindrome(string s) {
    int low = 0, high = static_cast<int>(s.size()) - 1;
    while (low < high) {
        char c1 = s[low], c2 = s[high];
        if (c1 == c2) {
            ++low;
            --high;
        }
        else {
            return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
        }
    }
    return true;
}
bool Solution::checkPalindrome(const string& s, int low, int high) {
    for (int i = low, j = high; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

// 位1的个数
/* 编写一个函数,输入是一个无符号整数,返回其二进制表达式中数字位数为 ‘1’ 的个数,也被称为汉明重量
 * */
int Solution::hammingWeight(uint32_t n) {
    int weight = 0;
    while(n){
        ++weight;
        n &= n-1u;
    }
    return weight;
}

// 二叉树的最小深度
/* 给定一个二叉树，找出其最小深度
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量
 * 说明: 叶子节点是指没有子节点的节点
 * */
// 以nullptr分层,不压入nullptr,层序遍历的第一个无子节点的深度即为结果
int Solution::minDepth(TreeNode* root) {
    if(root==nullptr){
        return 0;
    }
    queue<TreeNode*> floor;
    floor.push(root);
    floor.push(nullptr);
    int c = 1;
    while(floor.size()!=1){
        auto temp = floor.front();
        floor.pop();
        if(temp == nullptr){
            ++c;
            floor.push(nullptr);
            continue;
        }
        if(temp->left==nullptr&&temp->right==nullptr){
            break;
        }else{
            if(temp->left!=nullptr){
                floor.push(temp->left);
            }
            if(temp->right!=nullptr){
                floor.push(temp->right);
            }
        }
    }
    return c;
}

// 验证回文串
/* 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写
 * 说明：本题中，我们将空字符串定义为有效的回文串
 * */
// 解法1：将字母数字单独挑出来,大写转小写，然后进行回文判断;解法2,非字母数字转换为空格,判断回文时自动跳过空格
bool isPalindrome(string s) {
    for(auto &i:s){
        if(i>='A'&&i<='Z'){
            i -= 'A'-'a';
        }
        if(i>='0'&&i<='9'||i>='a'&&i<='z'){
            continue;
        }
        i = ' ';
    }
    int left  = 0;
    int right = static_cast<int>(s.size())-1;
    while(left<right){
        while(left<s.size()&&(s[left]==' ')){
            ++left;
        }
        while(right>=0&&(s[right]==' ')){
            --right;
        }
        if(left<right&&(s[left]!=s[right])){
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

// 每个元音包含偶数次的最长子字符串
/* 给你一个字符串 s
 * 请你返回满足以下条件的最长子字符串的长度
 * 每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次
 * */
int Solution::findTheLongestSubstring(string s) {
    unsigned int status = 0, n = s.length();
    int ans = 0;
    vector<int> pos(1u << 5u, -1);
    pos[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            status ^= 1u<<0u;
        } else if (s[i] == 'e') {
            status ^= 1u<<1u;
        } else if (s[i] == 'i') {
            status ^= 1u<<2u;
        } else if (s[i] == 'o') {
            status ^= 1u<<3u;
        } else if (s[i] == 'u') {
            status ^= 1u<<4u;
        }
        if (~static_cast<unsigned int>(pos[status])) {
            ans = max(ans, i + 1 - pos[status]);
        } else {
            pos[status] = i + 1;
        }
    }
    return ans;
}

// 路径总和
/* 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和
 * 说明: 叶子节点是指没有子节点的节点
 * */
bool Solution::hasPathSum(struct TreeNode* root, int sum){
    if(root==nullptr){
        return sum==0;
    }
    if(root->left==nullptr&&root->left==root->right){
        return root->val==sum;
    }
    int signL = hasPathSum(root->left,sum-root->val);
    int signR = hasPathSum(root->right,sum-root->val);
    return signL||signR;
}

// 路径总和 II
/* 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径
 * */
vector<vector<int>> Solution::pathSum(TreeNode* root, int sum) {
    vector<int> temp;
    vector<vector<int>> res;
    coPathSum(root,sum,temp,res);
    return res;
}
void Solution::coPathSum(struct TreeNode* root, int sum,vector<int> &temp,vector<vector<int>> &res){
    if(root!=nullptr){
        temp.push_back(root->val);
        if(root->left==nullptr&&root->left==root->right){
            if(root->val==sum){
                res.push_back(temp);
            }
        }else{
            coPathSum(root->left,sum-root->val,temp,res);
            coPathSum(root->right,sum-root->val,temp,res);
        }
        temp.pop_back();
    }
}

// 字符串解码
/* 给定一个经过编码的字符串，返回它解码后的字符串
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入
 * */
// 类似于等式求值操作为[],参数为a,b,等式为a[b]=bbb···b<共a个>
string Solution::decodeString(string s) {
    if(s.empty()){
        return "";
    }
    stack<string> nums;
    stack<string> ops;
    int i = 0;
    while(i<s.size()){
        cout << i << endl;
        if(s[i]>='0'&&s[i]<='9'){
            string temp;
            while(i<s.size()&&(s[i]>='0'&&s[i]<='9')) temp += s[i++];
            nums.push(temp);
        }else if(s[i]=='['){
            string temp;
            temp += s[i++];
            ops.push(temp);
        }else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            string temp;
            while(i<s.size()&&((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))) temp += s[i++];
            ops.push(temp);
        }else if(s[i]==']'){
            string temp;
            string p = ops.top();
            int l = stoi(nums.top());
            ops.pop();
            nums.pop();
            if(!ops.empty()&&(ops.top()=="[")){
                ops.pop();
            }
            string q;
            for(int k=0;k<l;++k){
                q += p;
            }
            if(!ops.empty()&&(ops.top()!="[")){
                temp += ops.top();
                ops.pop();
            }
            temp += q;
            ops.push(temp);
            ++i;
        }
    }
    return ops.top();
}

// 打家劫舍 I
/* 你是一个专业的小偷，计划偷窃沿街的房屋
 * 每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统
 * 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额
 * */
int Solution::rob1(vector<int>& nums,int start,int end) {
    int left = 0;
    int right = 0;
    for(int i=start;i<end;++i){
        int temp = left+nums[i];
        left = left>right?left:right;
        right = temp;
    }
    return right>left?right:left;
}

// 打家劫舍 II
/* 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金
 * 这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的
 * 同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额
 * */
// 环形转两个单排利用打家劫舍 I的单排算法
int Solution::rob2(vector<int>& nums) {
    int st = 0;
    int en = nums.size();
    int left = rob1(nums,st,en-1);
    int right = rob1(nums,st+1,en);
    return left>right?left:right;
}

// 打家劫舍 III
/* 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区
 * 这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连
 * 一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”
 * 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警
 * 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额
 * */
int Solution::rob3(TreeNode* root) {
    int left=0,right=0;
    rob3dp(root,left,right);
    return max(left,right);

}
void Solution::rob3dp(TreeNode* root,int &left,int &right) {
    if(root!=nullptr){
        int m=0,n=0,p=0,q=0;
        rob3dp(root->left,m,n);
        rob3dp(root->right,p,q);
        left = max(m,n)+max(p,q);
        right = root->val+m+p;
    }
}

// 回文链表
/* 请判断一个链表是否为回文链表
 * */
bool Solution::isPalindrome(ListNode* head) {
    ListNode *fast=head;
    ListNode *slow=head;
    int l=0;
    while(fast){
        fast=fast->next;
        ++l;
    }
    ListNode temp(0);
    ListNode *t = nullptr;
    for(int i=0;i<l/2;++i){
        t = temp.next;
        temp.next = slow;
        slow = slow->next;
        temp.next->next = t;
    }
    if(l%2){
        slow = slow->next;
    }
    fast = temp.next;
    while(fast&&slow){
        if(fast->val!=slow->val){
            return false;
        }
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}

// 拥有最多糖果的孩子
/* 给你一个数组 candies 和一个整数 extraCandies ，其中 candies[i] 代表第 i 个孩子拥有的糖果数目
 * 对每一个孩子，检查是否存在一种方案，将额外的 extraCandies 个糖果分配给孩子们之后，此孩子有 最多 的糖果。注意，允许有多个孩子同时拥有 最多 的糖果数目
 * */
// 6.1儿童节快乐
vector<bool> Solution::kidsWithCandies(vector<int>& candies, int extraCandies) {
    int max = 0;
    vector<bool> res(candies.size());
    for(auto i:candies){
        max = max>i?max:i;
    }
    for(int i=0;i<candies.size();++i){
        res[i] = candies[i]+extraCandies>=max;
    }
    return res;
}

// 三角形最小路径和
/* 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上
 * 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点
 * */
int Solution::minimumTotal(vector<vector<int>>& triangle) {
    int row = triangle.size();
    vector<int> temp(row,0);
    for(int i=row-1;i>=0;--i){
        for(int j=0;j<triangle[i].size();++j){
            temp[j] = i==row-1?0:min(temp[j],temp[j+1]);
            temp[j] += triangle[i][j];
        }
    }
    return temp[0];
}

// 除自身以外数组的乘积
/* 给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output
 * 其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积
 * */
vector<int> Solution::productExceptSelf(vector<int>& nums) {
    int le = nums.size();
    vector<int> res(le,1);
    for(int i=1;i<le;++i){
        res[i] = res[i-1]*nums[i-1];
    }
    int temp = 1;
    for(int i=le-1;i>=0;--i){
        res[i] = temp*res[i];
        temp *= nums[i];
    }
    return res;
}

// 最长连续序列
/* 给定一个未排序的整数数组，找出最长连续序列的长度
 * 要求算法的时间复杂度为 O(n)*/
int Solution::longestConsecutive(vector<int>& nums) {
    unordered_set<int> map;
    for(auto i:nums){
        map.insert(i);
    }
    int res = 1;
    int cur = 1;
    for(auto i:map){
        if(map.find(i-1)==map.end()){
            cur = 1;
            while(map.find(i+cur)!=map.end()){
                cur++;
            }
            res = res>cur?res:cur;
        }
    }
    return res;
}

// 可能的二分法
/* 给定一组 N 人（编号为 1, 2, ..., N）， 我们想把每个人分进任意大小的两组
 * 每个人都可能不喜欢其他人，那么他们不应该属于同一组
 * 形式上，如果 dislikes[i] = [a, b]，表示不允许将编号为 a 和 b 的人归入同一组
 * 当可以用这种方法将每个人分进两组时，返回 true；否则返回 false
 * */
bool Solution::possibleBipartition(int N, vector<vector<int>>& dislikes){
    vector<vector<int>> graph(N+1,vector<int>(0));
    for(auto &i:dislikes){
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    vector<int> color(N+1,-1);
    for (int node = 1; node <= N; ++node)
        if (color[node]==-1 && !possibleBipartitiondfs(node, 0,color,graph))
            return false;
    return true;
}
bool Solution::possibleBipartitiondfs(int node, int c,vector<int> &color,vector<vector<int>> &graph) {
    if (color[node]!=-1){
        return color[node]== c;
    }
    color[node]=c;
    for (int nei: graph[node])
        if (!possibleBipartitiondfs(nei, c^1u,color,graph))
            return false;
    return true;
}

// 每日温度
/* 请根据每日 气温 列表，重新生成一个列表
 * 对应位置的输出为：要想观测到更高的气温，至少需要等待的天数
 * 如果气温在这之后都不会升高，请在该位置用 0 来代替
 *例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
 * 你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]
 * 提示：气温 列表长度的范围是 [1, 30000]
 * 每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数
 * */
vector<int> Solution::dailyTemperatures(vector<int>& T) {
    vector<int> stackTemp(T.size(),-1);
    vector<int> res(T.size(),0);
    int indexTop = -1;
    for(int i=0;i<T.size();i++){
        if(indexTop!=-1&&(T[stackTemp[indexTop]]<T[i])){
            while(indexTop!=-1&&T[stackTemp[indexTop]]<T[i]){
                res[stackTemp[indexTop]] = i-stackTemp[indexTop];
                indexTop--;
            }
        }
        stackTemp[++indexTop] = i;
    }
    return res;
}

// 单词拆分
/* 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict
 * 判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词
 * 说明：
 * 拆分时可以重复使用字典中的单词
 * 你可以假设字典中没有重复的单词
 * */
bool Solution::wordBreak(const string& s, vector<string>& wordDict) {
    auto wordDictSet = unordered_set <string> ();
    for (auto &word: wordDict) {
        wordDictSet.insert(word);
    }
    auto dp = vector <bool> (s.size() + 1);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

// 长度最小的子数组
/* 给定一个含有 n 个正整数的数组和一个正整数 s
 * 找出该数组中满足其和 ≥ s 的长度最小的连续子数组
 * 并返回其长度。如果不存在符合条件的连续子数组，返回 0
 * */
int Solution::minSubArrayLen(int s, vector<int>& nums) {
    int st = -1;    // 左开
    int en = -1;    // 右闭
    int sum = 0;    // 总和
    int l = 0;      // 最小长度
    bool flag = true;   // 判断是否存在，若存在先将最短长度置为数组长度
    for(auto i:nums){   // 右侧进行加入数字
        en++;
        sum += i;
        while(en>=st&&sum>=s){  // 先判断长度是否更新，后左侧去除数字循环判断
            if(flag){
                l = nums.size();
                flag = false;
            }
            l = en-st<=l?en-st:l;
            st++;
            sum -= nums[st];
        }
    }
    return l;   // 返回最小长度
}

// 跳水板
/* 你正在使用一堆木板建造跳水板
 * 有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer
 * 你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度
 * 返回的长度需要从小到大排列
 * */
vector<int> Solution::divingBoard(int shorter, int longer, int k) {
    if(k==0){
        return vector<int>{};
    }
    int orient = shorter*k;
    if(shorter==longer){
        return vector<int>{orient};
    }
    vector<int> res;
    res.push_back(orient);
    for(int i=0;i<k;++i){
        orient += longer-shorter;
        res.push_back(orient);
    }
    return res;
}

// 计算右侧小于当前元素的个数
/* 给定一个整数数组 nums，按要求返回一个新数组 counts
 * 数组 counts 有该性质:counts[i]的值是nums[i]右侧小于nums[i]的元素的数量
 * */
vector<int> Solution::countSmaller(vector<int>& nums) {
    int l = nums.size();
    vector<int> res(l,0);
    if(l>1){
        for(int i=l-2;i>=0;--i){
            for(int j=i+1;j<l;++j){
                if(nums[i]>nums[j]){
                    res[i] += 1;
                }
            }
        }
    }
    return res;
}

// 地下城游戏
/* 一些恶魔抓住了公主（P）并将她关在了地下城的右下角
 * 地下城是由 M x N 个房间组成的二维网格
 * 我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主
 * 骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡
 * 有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）
 * 其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）
 * 为了尽快到达公主，骑士决定每次只向右或向下移动一步
 * */
int Solution::calculateMinimumHP(vector<vector<int>>& dungeon) {
    int row = dungeon.size();
    int col = dungeon[0].size();
    vector<vector<int>> temp(row,vector<int>(col,1));
    for(int i=row-1;i>=0;i--){
        for(int j=col-1;j>=0;j--){
            int k;
            if(j==col-1&&i==row-1){
                k = 1-dungeon[i][j];
            }else if(i==row-1||j==col-1){
                k = temp[i+(j==col-1)][j+(i==row-1)]-dungeon[i][j];
            }else{
                k = min(temp[i+1][j],temp[i][j+1])-dungeon[i][j];
            }
            temp[i][j] = max(k,1);
        }
    }
    return temp[0][0];
}

// 矩阵中的最长递增路径
/* 给定一个整数矩阵，找出最长递增路径的长度
 * 对于每个单元格，你可以往上，下，左，右四个方向移动
 * 你不能在对角线方向上移动或移动到边界外（即不允许环绕）
 * */
int Solution::longestIncreasingPath(vector<vector<int>>& matrix) {
    if(matrix.empty()||matrix[0].empty()){
        return 0;
    }
    int row = matrix.size();
    int col = matrix[0].size();
    vector<vector<int>> temp(row,vector<int>(col,1));
    int max = 1;
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            int m = 0;
            if(i-1>=0&&matrix[i][j]<matrix[i-1][j]&&temp[i-1][j]>m){
                m = temp[i-1][j];
            }
            if(i+1<row&&matrix[i][j]<matrix[i+1][j]&&temp[i+1][j]>m){
                m = temp[i+1][j];
            }
            if(j-1>=0&&matrix[i][j]<matrix[i][j-1]&&temp[i][j-1]>m){
                m = temp[i][j-1];
            }
            if(j+1<col&&matrix[i][j]<matrix[i][j+1]&&temp[i][j+1]>m){
                m = temp[i][j+1];
            }
            temp[i][j] += m;
            cout << m<<" ";
            max = max<temp[i][j]?temp[i][j]:max;
        }
        cout <<endl;
    }
    return max;
}

// 字符串相加
/* 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和
 * 提示:
 * num1 和num2 的长度都小于 5100
 * num1 和num2 都只包含数字 0-9
 * num1 和num2 都不包含任何前导零
 * */
string Solution::addStrings(string num1, string num2) {
    if(num1=="0"){
        return num2;
    }else if(num2=="0"){
        return num1;
    }
    int l1 = num1.size();
    int l2 = num2.size();
    int lr = max(l1,l2)+1;
    int flagOF = 0;
    string res(lr,'0');
    for(int i=0;i<lr;++i){
        if(i<l1){
            res[lr-1-i] = num1[l1-1-i];
        }
        int temp = res[lr-1-i]+flagOF-'0';
        if(i<l2){
            temp += num2[l2-1-i]-'0';
            flagOF = temp/10;
            res[lr-1-i] = temp-flagOF*10+'0';
        }
        flagOF = temp/10;
        res[lr-1-i] = temp-flagOF*10+'0';
    }
    if(res[0]=='0'){
        return res.substr(1,lr);
    }
    return res;
}

// 查找常用字符
/*给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表
 * 例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次
 * 你可以按任意顺序返回答案
 * */
vector<string> Solution::ommonChars(vector<string>& A) {
    vector<string> p;
    if(A.empty()){  // 如果A数组为空则直接返回空
        return p;
    }
    int res[26] = {0};  // 初始化前n-1个单词的共同字符
    for(auto i:A[0]){   // 首先载入第一个单词
        res[i-'a']++;
    }
    for(int i=1;i<A.size();++i){    // 取出第n个单词进行计数
        int temp[26] = {0};
        for(auto j:A[i]){   // 计数
            temp[j-'a']++;
        }
        for(int k=0;k<26;k++){  // 取数组每个字母的最小个数
            res[k] = res[k]>temp[k]?temp[k]:res[k];
        }
    }
    for(int i=0;i<26;++i){  // 从数组构建结果
        for(int j=0;j<res[i];++j){  // 多个字母时循环
            p.push_back(string{static_cast<char>('a'+i)});
        }
    }
    return p;
}

// 长按键入
/*你的朋友正在使用键盘输入他的名字 name
 * 偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次
 * 你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True
 * */
bool Solution::isLongPressedName(string name, string typed) {
    int left = 0;
    int right = 0;
    while(right<typed.size()){
        if(left<name.size()&&name[left]==typed[right]){ // 第一种情况:相同字母同时向后移动
            left++;
            right++;
        }else if(right>0&&typed[right]==typed[right-1]){ // 第二种情况:不同，但是与前一个相同，忽略字符
            right++;
        }else{  // 第三种情况不与对应字母相同，也不与之前字母相同，返回FALSE
            return false;
        }
    }
    return left==name.size();   // 结果应该扫描完全部名称
}

//  划分字母区间
/* 字符串 S 由小写字母组成
 * 我们要把这个字符串划分为尽可能多的片段
 * 同一个字母只会出现在其中的一个片段
 * 返回一个表示每个字符串片段的长度的列表
 * */
vector<int> Solution::partitionLabels(string S) {
    int last[26];
    int length = S.size();
    for (int i = 0; i < length; i++) {
        last[S[i] - 'a'] = i;
    }
    vector<int> partition;
    int start = 0, end = 0;
    for (int i = 0; i < length; i++) {
        end = max(end, last[S[i] - 'a']);
        if (i == end) {
            partition.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return partition;
}

// 视频拼接
/* 你将会获得一系列视频片段，这些片段来自于一项持续时长为 T 秒的体育赛事
 * 这些片段可能有所重叠，也可能长度不一
 * 视频片段 clips[i] 都用区间进行表示：开始于 clips[i][0] 并于 clips[i][1] 结束
 * 我们甚至可以对这些片段自由地再剪辑，例如片段 [0, 7] 可以剪切成 [0, 1] + [1, 3] + [3, 7] 三部分
 * 我们需要将这些片段进行再剪辑，并将剪辑后的内容拼接成覆盖整个运动过程的片段（[0, T]）
 * 返回所需片段的最小数目，如果无法完成该任务，则返回 -1
 * */
int Solution::videoStitching(vector<vector<int>>& clips, int T) {
    vector<int> dp(T + 1, INT_MAX - 1); // dp[i]表示[0,i)的最优解
    dp[0] = 0;  // 当[0，0)时解的个数为0
    for (int i = 1; i <= T; i++) {  // 对每个位置进行计算dp[i]
        for (auto& it : clips) {    // 考察每个区间,若数组包含自己则更新dp[i]
            if (it[0] < i && i <= it[1]) {  // 在多个包含自己的数组种寻找到一个最小次数的数组
                dp[i] = min(dp[i], dp[it[0]] + 1);  // 此处可能溢出,故在最初采用INT_MAX-1作为初始值
            }
        }
    }
    return dp[T] == INT_MAX - 1 ? -1 : dp[T];   // 判断是否改变了末尾的值,若无则说明未到到达末尾
}
/*
 * 贪心算法
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int> maxn(T);
        int last = 0, ret = 0, pre = 0;
        for (vector<int>& it : clips) { // 确定每个从i处起点的最长区间
            if (it[0] < T) {
                maxn[it[0]] = max(maxn[it[0]], it[1]);
            }
        }
        for (int i = 0; i < T; i++) {   // 遍历每个起始点
            last = max(last, maxn[i]);  // 更新last,last为能到达的最大地方即max(曾经最大,当前位置末尾)
            if (i == last) {    // 若最后的位置和当前位置重合,则无法向后移动,返回-1
                return -1;
            }
            if (i == pre) { //当i到达正在使用的区间的末尾时进行跳转到下一个区间末尾,计数器+1
                ret++;
                pre = last;
            }
        }
        return ret; // 若成功则可以返回
    }
*/

// 数组中的最长山脉
/* 我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”
 * B.length >= 3
 * 存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
 * （注意：B 可以是 A 的任意子数组，包括整个数组 A。）
 * 给出一个整数数组 A，返回最长 “山脉” 的长度
 * 如果不含有 “山脉” 则返回 0
 * */
int Solution::longestMountain(vector<int>& A) {
    int n = A.size();
    int ans = 0;
    int left = 0;
    while (left + 2 < n) {  // 山脉最短长度为3
        int right = left + 1;   // 山脉右山脚在左山脚后面
        if (A[left] < A[left + 1]) {    // 如果左山腰呈递增
            while (right + 1 < n && A[right] < A[right + 1]) {  // 寻找递增的左山腰
                ++right;
            }
            if (right < n - 1 && A[right] > A[right + 1]) { // 如果右山腰出现递减
                while (right + 1 < n && A[right] > A[right + 1]) {  // 寻找递减的右山腰
                    ++right;
                }
                ans = max(ans, right - left + 1);   // 比较和计算山脉长度
            }
            else {  // 若右山腰不递减则+1并重置左山脚
                ++right;
            }
        }
        left = right;   // 左山脚等于原右山脚
    }
    return ans; // 返回最大值
}
/*
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();   // 取得数组总长度
        if (!n) {   // 数组不应为空
            return 0;
        }
        vector<int> left(n);    // 从左向右数递增长度,比前一个大则+1,否则等于0
        for (int i = 1; i < n; ++i) {
            left[i] = (A[i - 1] < A[i] ? left[i - 1] + 1 : 0);
        }
        vector<int> right(n);   // 从右向左数递增长度,比前一个大则+1,否则等于0
        for (int i = n - 2; i >= 0; --i) {
            right[i] = (A[i + 1] < A[i] ? right[i + 1] + 1 : 0);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {   // 以每个位置作为山峰计算山脉长度left[i] + right[i] + 1
            if (left[i] > 0 && right[i] > 0) {
                ans = max(ans, left[i] + right[i] + 1);
            }
        }
        return ans; // 返回结果
    }
};
*/

// x 的平方根
/* 实现 int sqrt(int x) 函数
 * 计算并返回 x 的平方根，其中 x 是非负整数
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去
 * */
// 此处采用二分查找的第二类模板,当符合mid^2<=x时,left移动到mid+1处,并记录mid.
int Solution::mySqrt(int x) {
    int res = 0;
    int left = 1,right = x;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(mid*mid<=x){
            res = mid;
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return res;
}

// 寻找旋转排序数组中的最小值
/* 假设按照升序排序的数组在预先未知的某个点上进行了旋转
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )
 * 请找出其中最小的元素
 * 你可以假设数组中不存在重复元素
 * */
int Solution::findMin(vector<int>& nums) {
    if(nums.size()==1){ // 仅有一个元素则唯一元素为最小
        return nums[0];
    }
    int left = 0, right = static_cast<int>(nums.size())-1;
    if(nums[left]<nums[right]){ // 若左端小于右端说明是增序，故第一个数最小
        return nums[left];
    }
    while (right >= left) { // 二分查找
        int mid = left + (right - left) / 2;    // 取中间元素
        // 由于数组非完全递增,故此处mid不可能取到nums.size()位置
        if (nums[mid] > nums[mid + 1]) {    // 如果元素比下一个元素大,则下一个元素必是最小值
            return nums[mid + 1];
        }
        // 由于数组非完全递增,故此处mid不可能取到0位置
        if (nums[mid - 1] > nums[mid]) {    // 如果前一个元素比自己大,则自己必是最小的
            return nums[mid];
        }
        if (nums[mid] > nums[0]) {  // 若中间值比第一个值大,则前半段未被翻转过,搜索后半段;否则搜索前半段
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// 找到 K 个最接近的元素
/* 给定一个排序好的数组，两个整数 k 和 x
 * 从数组中找到最靠近 x（两数之差最小）的 k 个数
 * 返回的结果必须要是按升序排好的
 * 如果有两个数与 x 的差值一样，优先选择数值较小的那个数
 * */
vector<int> Solution::findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0, right = static_cast<int>(arr.size()) - k;   // 结果相当于一个长度为k的窗口
    while (left < right) {  // 二分法寻找窗口的左侧起始点
        int mid = left + (right - left) / 2;
        if (x - arr[mid] > arr[mid + k] - x) left = mid + 1;    // 若右侧更靠近x则窗口向右移动
        else right = mid;   // 左侧靠近向左靠近
    }
    return vector<int>(arr.begin() + left, arr.begin() + left + k); // 返回结果
}

// 自由之路
/* 视频游戏“辐射4”中，任务“通向自由”要求玩家到达名为“Freedom Trail Ring”的金属表盘，并使用表盘拼写特定关键词才能开门
 * 给定一个字符串 ring，表示刻在外环上的编码；给定另一个字符串 key，表示需要拼写的关键词
 * 您需要算出能够拼写关键词中所有字符的最少步数
 * 最初，ring 的第一个字符与12:00方向对齐
 * 您需要顺时针或逆时针旋转 ring 以使 key 的一个字符在 12:00 方向对齐
 * 然后按下中心按钮，以此逐个拼写完 key 中的所有字符
 * 旋转 ring 拼出 key 字符 key[i] 的阶段中：
 * 您可以将 ring 顺时针或逆时针旋转一个位置，计为1步
 * 旋转的最终目的是将字符串 ring 的一个字符与 12:00 方向对齐，并且这个字符必须等于字符 key[i]
 * 如果字符 key[i] 已经对齐到12:00方向，您需要按下中心按钮进行拼写，这也将算作 1 步
 * 按完之后，您可以开始拼写 key 的下一个字符（下一阶段）, 直至完成所有拼写
 * */
int Solution::findRotateSteps(string ring, string key) {
    int n = ring.size(), m = key.size();
    vector<int> pos[26];
    for (int i = 0; i < n; ++i) {
        pos[ring[i] - 'a'].push_back(i);
    }
    int dp[m][n];
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (auto& i: pos[key[0] - 'a']) {
        dp[0][i] = min(i, n - i) + 1;
    }
    for (int i = 1; i < m; ++i) {
        for (auto& j: pos[key[i] - 'a']) {
            for (auto& k: pos[key[i - 1] - 'a']) {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + min(abs(j - k), n - abs(j - k)) + 1);
            }
        }
    }
    return *min_element(dp[m - 1], dp[m - 1] + n);
}


// 加油站
/* 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升
 * 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升
 * 你从其中的一个加油站出发，开始时油箱为空
 * 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1
 * 说明:
 * 如果题目有解，该答案即为唯一答案
 * 输入数组均为非空数组，且长度相同
 * 输入数组中的元素均为非负数
 * */
/* 1、首先尝试暴力方法,对于i属于[0，n)的每个值,向后进行遍历
 * 若汽油和小于消耗和,则无法前进,进入下一个循环
 * 若汽油和大于消耗和,向后遍历指针向后移动,直到回到原处结束并返回结果
 * 均无法返回原位,返回-1
 * 2、优化:根据观察,若从i处可以到达j处,可以得到当使用(i,j)之间的位置作为起点时
 * 最远只能到达j处,故结果只能在[i,j]区间之外寻找
 * 故当i处循环结束后,无法到达之后,只需要从可以到达的最远处,即i+1处开始遍历即可
 * */
int Solution::canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size(); // gas 的长度
    int i = 0;  // 遍历起始点
    while (i < n) { // 从每个位置计算一次
        int sumOfGas = 0, sumOfCost = 0;    // gas总和,cost总和
        int cnt = 0;    // 区间长度
        while (cnt < n) {   // 区间长度应该小于n
            int j = (i + cnt) % n;  // 取余确定区间最后一个位置所在环的位置
            sumOfGas += gas[j]; // 叠加gas
            sumOfCost += cost[j];   // 叠加cost
            if (sumOfCost > sumOfGas) { // 汽油大于花费则不能到达,跳出循环
                break;
            }
            cnt++;  // 延迟区间长度
        }
        if (cnt == n) { // 如果能回到原位则返回起始点,否则将下一次循环起始点移动到i + cnt + 1处
            return i;
        } else {
            i = i + cnt + 1;
        }
    }
    return -1;  // 失败返回-1
}







