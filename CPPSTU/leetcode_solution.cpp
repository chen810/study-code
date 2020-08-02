//
// Created by WOOO on 2020/2/14.
// Used for Leetcode study
//
#include "leetcode_solution.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <malloc.h>

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