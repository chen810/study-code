//
// Created by WOOO on 2020/2/14.
// Used for Leetcode study
//
#include "leetcode_solution.h"
#include <iostream>
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


// ��������,vector<int>Ϊ����ֵ,boolֵΪ�����Ƿ�����
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
// ��ӡ����,��˳���ӡ,end�ɿ��Ʒָ���
void printListNodeChain(ListNode * head, const string& end){
    while(head!= nullptr){
        cout << head->val;
        if(head->next){
            cout << end;
        }
        head= head->next;
    }
}


/* ����Ϊ���������㷨
 * =========================================================================
 * ����ΪSolution�㷨ʵ��
 * */


// Ͱ�����㷨
/* ȡ���ֵmax����Сֵmin���������������count��Сmax-min
 * ȡ���������ֵi�����ȥmin��ӳ��Ϊ�±������(i-min),��ʹcount[i-min]�Լ�1
 * �Լ���ɺ�,��count��ѭ������ֵ���,��count[n]����0,�������min�õ�ԭ����(n+min)
 * ��ԭ���ְ�������ԭ��������,���������
 * O = 2*n
 * ʱ�临�Ӷ�O(n)
 * */
void Solution::bucketSort(vector<int> &nums){
    // ������������������1�Ž�������
    if(nums.size()>1){
        // �ж��������ݵ����ֵ����Сֵ
        int max=nums[0],min=nums[0];
        for(auto i:nums){
            if(i>max){
                max = i;
            }
            if(i<min){
                min = i;
            }
        }
        // ����count��������
        vector<int> count(max-min+1,0);
        // ����,����ֵӳ��Ϊ�±�,�������Լ�
        for(auto i:nums){
            ++count[i-min];
        }
        // ���±�ӳ��Ϊ��ֵ,��˳������ԭ��������,����count��Ӧλ�ý����Լ�����
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

// ð�������㷨
/* �Ӻ���ǰ��,��ǰ����ɨ������λ,�Ƚ���������,���ϴ����ֺ���
 * ����λ������λ���������
 * O = 1+2+3+4+5+������+(n-1)
 * ʱ�临�Ӷ�ΪO(n*n)
 * */
void Solution::bubbleSort(vector<int> &nums) {
    // ȡ����
    int le = nums.size();
    // ���ű�������һ��������ֵ
    for(int i=le-1;i>=0;--i){
        // �ӵ�һ����ֵ,����������ĩβ,����һ��С��ǰһ����λ
        for(int k=1;k<=i;++k){
            if(nums[k-1] > nums[k]){
                int temp = nums[k];
                nums[k] = nums[k-1];
                nums[k-1] = temp;
            }
        }
    }
}

// ���������㷨
/* ѭ������������ֵ
 * ��ǰ�жϲ���λ��,������һ�������ߵ��˿�ͷ,��ִ�������
 * O = 1+2+3+4+5+������+(n-1)
 * ʱ�临�Ӷ�O(n*n)
 * */
void Solution::insertionSort(vector<int> &nums){
    // �ӵ�һ��������ֵλ������ĩβ
    for(int i=0;i<nums.size();++i){
        // ���������ֵ,��ѭ����ǰ�����һ��ȡ�õ���ֵ
        int temp = nums[i],j=i;
        // ������ֵ����ͷ�����ߴ���һ����,�����ڿ�ͷ�����Ǹ���֮��
        while(j>0&&nums[j-1]>temp){
            nums[j] = nums[j-1];
            --j;
        }
        nums[j] = temp;
    }
}

// �鲢�����㷨:������-mergeSort,��������mergeSort_sort,mergeSort_merge
/* �鲢����,���÷���˼��,ʹ��mergeSort_sort�����Ϊһ����С������,ֱ��Ϊ1
 * ��ͨ��mergeSort_merge���кϲ���������
 * */
void Solution::mergeSort(vector<int> &nums){
    // ִ�еݹ�����,Ϊ����ӳ�ʼֵ
    int l = nums.size();
    mergeSort_sort(nums,0,l-1);
}
void Solution::mergeSort_sort(vector<int> &nums, int left, int right) {
    // ����ָ����ڵ�����ָ��˵��,Ԫ�������ﵽ����,����������
    if(left>=right){
        return;
    }
    // ȡ�е�λ��,ʹ���Ϊ��С��,��������,��������ɵ���С����кϲ������ɵõ����
    int mid = (left+right)/2;
    mergeSort_sort(nums,left,mid);
    mergeSort_sort(nums,mid+1,right);
    mergeSort_merge(nums,left,mid,right);
}
void Solution::mergeSort_merge(vector<int> &nums, int left, int mid, int right) {
    int mp = mid+1;
    int st = left;
    // һ����ʱ�����洢
    vector<int> temp(right-left+1);
    int index = 0;
    // ������������ֵ���бȽ�,ֱ����һ�������е���ֵ��ȡ��,��ֹͣѭ��
    while(st <= mid&&mp<=right){
        int num = nums[st] <= nums[mp]?nums[st++]:nums[mp++];
        temp[index++] = num;
    }
    // ������δ��ȡ��,������������ʱ��������
    while(st <= mid){
        temp[index++] = nums[st++];
    }
    // ���Ұ��δ��ȡ��,������������ʱ��������
    while(mp <= right){
        temp[index++] = nums[mp++];
    }
    // ����ʱ�����е���ֵ������ԭ����
    for(int k=0;k<temp.size();++k){
        nums[k+left] = temp[k];
    }
}

// ������:
/* �ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ��������
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

// ������ʽƥ��:
/*
 * ����һ���ַ��� s ��һ���ַ����� p��������ʵ��һ��֧�� '.' �� '*' ��������ʽƥ��
 * '.' ƥ�����ⵥ���ַ�
 * '*' ƥ���������ǰ�����һ��Ԫ��
 * ��νƥ�䣬��Ҫ���� ���� �ַ��� s�ģ������ǲ����ַ���
 * ˵��:
 * s ����Ϊ�գ���ֻ������ a-z ��Сд��ĸ
 * p ����Ϊ�գ���ֻ������ a-z ��Сд��ĸ���Լ��ַ� . �� *
 * */
bool Solution::isMatch_Re(string s, string p) {
    // ����һ���ռ�洢ÿ��ƥ��ڵ�
    bool dp[s.length()+1][p.length()+1];
    dp[0][0]=true;
    //������Χ��,�������a*a*a*....
    for(int i=0;i<p.length();i++){
        dp[0][i + 1] = p[i] == '*' && dp[0][i - 1];
    }
    //���ÿ�Ϊ0
    for(int i=1;i<s.length()+1;i++){
        dp[i][0]=false;
    }
    // ����ƥ���ַ���
    for(int i=0;i<s.length();i++){
        // ����ģʽ�ַ���
        for(int j=0;j<p.length();j++){
            // ���ƥ���ϣ���ģʽ�����ַ�һ������.
            if(s[i]==p[j] || p[j]=='.'){
                // ƥ��ɹ���ͬʱ�ӳ�����s��ǰi��������pǰj��ƥ��
                dp[i+1][j+1]=dp[i][j];
            }else if(p[j]=='*'){
                // ƥ��ʧ�ܣ����ж��Ƿ�Ϊx*��ʽ�����ж�֮ǰ��һ���Ƿ����
                if(p[j-1]!=s[i] && p[j-1]!='.'){
                    //�����֮ǰ�Ĳ�ƥ�䣬��������λ�ñ�ʾsǰi����������p��ǰj-2��ƥ��
                    dp[i+1][j+1]=dp[i+1][j-1];
                }else{
                    // ֮ǰ����ƥ�䣬���жϸ��������Ƿ�ƥ�䣬��һ��ƥ�伴��
                    dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j] || dp[i + 1][j - 1];
                }
            }else{
                // ƥ�䲻�����λ�ý��Լ���Ϊ��
                dp[i+1][j+1]=false;
            }
        }
    }
    // �������һ����ƥ���������s��ǰlength���Ƿ�ƥ��p��ǰlength��
    return dp[s.length()][p.length()];
}

// ʢˮ��������
/* ���� n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ���� (i, ai)
 * �������ڻ� n ����ֱ�ߣ���ֱ�� i �������˵�ֱ�Ϊ (i, ai) �� (i, 0)
 * �ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ
 * X   X
 * X-X-X-------X
 * X-X-X-X---X-X
 * X-X-X-X-X-X-X
 * ���߲���Ϊˮ��ͼʾΪ��һ�����һ��֮���ˮ
 * */
int Solution::maxArea(vector<int> &height) {
    // ��ʼ�����������ֱ����ڴ洢���ֵ����ÿ���������ֵ
    int max=0,temp=0;
    // ��������ָ�룬һ��ָ����Ԫ�أ�һ��ָ��βԪ��
    int p=0,q= static_cast<int>(height.size())-1;
    // ����ָ������ʱ�����ж�
    while(p < q){
        // ��ʼ��Ϊ�����εĳ�
        temp = q-p;
        // �ϰ���һ��Ϊ����˲��ҽ���Ӧ�̱�ָ�����ڿ�£
        temp *= height[p] < height[q]?height[p++]:height[q--];
        // �ж��Ƿ�������ֵ
        max = max > temp?max:temp;
    }
    return max;
}

// ����ת��������
/* �������ְ������������ַ�:
 * I V X  L  C   D   M
 * 1 5 10 50 100 500 1000
 * ����:4-IV 9-IX 40-XL 90-XC 400-CD 900-CM
 * �������ַ�Χ1-3999
 * */
string Solution::intToRoman(int num) {
    // ����ת����˳��IXCMVLD����
    string s,p("IXCMVLD");
    // ��¼�µ�ǰȨ��,sign��¼��������Ȩ��,temp���ڴ洢��ʱ����
    int flag = 1000,sign=4,temp;
    // ����ֵΪ0-3999���г���
    while(num > 0&&num<4000){
        // �ж�Ȩ��ϵ��������֮��ȥ��Ȩ���½�
        temp = num/flag;
        num -= temp*flag;
        flag /=10;
        --sign;
        // ϵ��Ϊ0�򲻽��д���
        if(!temp){
            continue;
        }
        // ��4,9���������ַֿ����ľ�����������������ɣ��ж����θ���Ȩ��ʹ��ʲô��������
        if(temp%5==4){
            s += p[sign];
            s += temp==9?p[sign+1]:p[sign+4];
        }else{
            // ������5�������5�Ĳ��ֲ���ȥ5
            if(temp>=5) {
                s += p[sign+4];
                temp -= 5;
            }
            // ��ʣ�ಿ���ظ�temp�Σ��˴���stringֱ�ӳ�ʼ��һ����������ͬ�ַ����ɵ��ַ���
            s += string(temp,p[sign]);
        }
    }
    return s;
}

// ��������ת����
/* �������ְ������������ַ�:
 * I V X  L  C   D   M
 * 1 5 10 50 100 500 1000
 * ����:4-IV 9-IX 40-XL 90-XC 400-CD 900-CM
 * ������ַ�Χ1-3999
 * */
int Solution::romanToInt(const string& s) {
    // ת����,����ÿ���������ֵ�Ȩ��
    map<char,int> m{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    // sumΪ�ܺͼ������p����Ϊָ��
    int sum=0,p= static_cast<int>(s.size())-1;
    // ѭ���ж�,��С��֮ǰ�жϵ�һ����������ȥ
    while(p>=0){
        sum += s[p]==s.size()-1||m[s[p+1]]<=m[s[p]]?m[s[p]]:-m[s[p]];
        --p;
    }
    return sum;
}

// �����ǰ׺
/* ��дһ�������������ַ��������е������ǰ׺
 * ��������ڹ���ǰ׺�����ؿ��ַ��� ""
 * ʾ����
 * ����: ["flower","flow","flight"]
 * ���: "fl"
 * */
string Solution::longestCommonPrefix(vector<string> &strs) {
    // ���ṩ������Ϊ����ֱ�ӷ��ؿմ�
    if(strs.empty()){ return "";}
    // ȡ����һ��
    auto p = strs[0];
    // ��������,�����бȽ�,p�ִ���Խ��Խ��,������ɺ�ʣ���p����
    for(const auto& i:strs){
        for(int j=0;j<i.size();++j){
            // ������ض�p
            if(p[j]!=i[j]){
                p = string(p.begin(),p.begin()+j);
                break;
            }
            // i������β��ֱ�ӽ��丳ֵ��p
            if(j==i.size()-1){
                p = i;
                break;
            }
        }
    }
    return p;
}

// ����֮��
/* ����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c
 * ʹ�� a + b + c = 0 ���ҳ��������������Ҳ��ظ�����Ԫ��
 * ע�⣺���в����԰����ظ�����Ԫ��
 * */
// ����֮��120ms�㷨
vector<vector<int>> Solution::threeSum_1(vector<int> &nums) {
    // �����㷨,�������������ڿ���,ʱ�临�Ӷ�ΪN*log2N
    sort(nums.begin(),nums.end());
    int le=nums.size();
    // �洢���������
    vector<vector<int>> sp;
    int i=0;
    // ������������,ֻ���0������n-2
    while(i<le-2&&nums[i]<=0){
        int times =1;
        // �ж����ʱȡ�õ�������ͬ�ĸ���
        while(i+times < le&&nums[i+times]==nums[i]){
            ++times;
        }
        // ����[nums[i],X,X]�ṹ�Ľ��,��˿����ų��ظ�--ֻҪnums[i]��ͬ�����ź���ǰ���²�������ظ�
        if(times >=1){
            int left = i+1;
            int right = le-1;
            // ��һ��ֵ,ʣ�ಿ������ʹ��ָ��,��ָ��ָ��nums[i]����һ��,��ָ��ָ������һ��ֵ,ͬʱ��������
            while(left!=right){
                if(nums[left]==nums[i]){
                    ++left;
                    continue;
                }
                // �жϺ͵Ĵ�С
                int temp = nums[i]+nums[left]+nums[right];
                if(temp > 0){
                    // ������0,��ָ�������ƶ�
                    --right;
                }else if(temp < 0){
                    // ��С��0,��ָ�������ƶ�
                    ++left;
                }else{
                    // ������0����ָ���Ƶ���һ��ֵ(�����ظ�),��ָ������
                    sp.push_back({nums[i],nums[left],nums[right]});
                    int jump = nums[left];
                    while(left<le-1&&jump==nums[left]){
                        ++left;
                    }
                    right = le -1;
                }
            }
        }
        // ������ֵ,��Ϊ����,��ʣ�����Լ�����ȵ��������ҵ�һ�����Լ����Ϊ0
        if(times >=2){
            for(int k=i+times;k<le&&nums[k]+2*nums[i]<=0;++k){
                if(nums[k]+2*nums[i]==0){
                    sp.push_back({nums[i],nums[i],nums[k]});
                    break;
                }
            }
        }
        // ��3��ֵ,����Ϊ0,������Ϊ0����
        if(times>=3&&nums[i]==0){
            sp.push_back({0,0,0});
        }
        // ������һ��ֵ���ж�
        i += times;
    }
    return sp;
}
// ����֮��50ms�㷨
vector<vector<int>> Solution::threeSum_2(vector<int> & nums) {
    // ����,��С����
    sort(nums.begin(),nums.end());
    vector<vector<int>> sp;
    int n=nums.size();
    // ����ÿ��Ԫ��ִ�в���,����3����,��end-3����ֹ
    for(auto i=nums.begin();i!=nums.end()-2;){
        // ����һ��ֵ����0,���������ض�����0������ѭ��
        if(*i > 0){ break;}
        auto st = i+1;
        auto en = nums.end()-1;
        // �ӵ�i+1�����жϵ���end-1����
        while(st < en){
            // �����Ҷ�С��0,��ͱض�С��0,����ѭ��
            if(*en < 0){break;}
            // ��0���бȽ�
            if(*st+*en+*i>0){
                // ����0,ָ����ǰ��������һ������
                int temp =*en;
                while(en!=st&&temp==*en){
                    --en;
                }
            }else if(*st+*en+*i<0){
                // С��0,ָ�������������һ������
                int temp = *st;
                while(en!=st&&temp==*st){
                    ++st;
                }
            }else{
                // ����0,ָ�������ƶ�,���˸���������һ������
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
        // ����������ͬ��������(�����������ظ�)
        int temp = *i;
        while(i!=nums.end()-2&&*i==temp){
            ++i;
        }
    }
    return sp;
}

// ��ӽ�������֮��
/* ����һ������ n ������������ nums �� һ��Ŀ��ֵ target
 * �ҳ� nums �е�����������ʹ�����ǵĺ��� target ��ӽ�,�������������ĺ�
 * �ٶ�ÿ������ֻ����Ψһ��
 * */
int Solution::threeSumClosest(vector<int>& nums, int target) {
    // ���������,���ö�һ��ֵ,��ָ��Ľⷨ
    sort(nums.begin(),nums.end());
    int min = nums[0]+nums[1]+nums[2]-target,res=nums[0]+nums[1]+nums[2];
    min = min > 0?min:-min;
    // ����������ÿ��Ԫ��
    for(auto i = nums.begin();i!=nums.end()-2;){
        auto st = i+1;
        auto en = nums.end()-1;
        // ��i֮��̶���ָ����������
        while(st < en){
            int fix = *i+*st+*en-target;
            // ������֮����target��ֵΪ0,���Ҳ����κ�һ����С��ֵ��,��������֮��
            if(fix==0){ return target;}
            if(fix < 0){
                // ����ֵС��0����ָ�������ƶ�,ʹ��ƽ���0,����ֵС��Ŀǰ��¼����Сֵ,����º����ֵ
                if(-fix < min){
                    min = -fix;
                    res = fix+target;
                }
                // �����ظ�ֵ
                int left = *st;
                while(st!=en&&*st==left){
                    ++st;
                }

            }else if(fix > 0){
                // ����ֵ����0,����ָ�������ƶ�,ʹ��ƽ���0,����ֵС��Ŀǰ��¼����Сֵ,����º����ֵ
                if(fix < min){
                    min = fix;
                    res = fix+target;
                }
                // �����ظ�ֵ
                int right = *en;
                while(en!=st&&*en==right){
                    --en;
                }
            }
        }
        // �����ظ�ֵ
        int temp = *i;
        while(i<nums.end()-2&&temp==*i){
            ++i;
        }
    }
    return res;
}

// �绰�������ĸ���
/* ����һ������������ 2-9 ���ַ���,�����������ܱ�ʾ����ĸ���
 * �������ֵ���ĸ��ӳ������(��绰������ͬ)ע��1����Ӧ�κ���ĸ
 * 2:"abc",3:"def",4:"ghi",5:"jkl",6:"mno",7:"pqrs",8:"tuv",9:"wxyz"
 * */
vector<string> Solution::letterCombinations(string digits) {
    // ����һ��ӳ���'2'->0->"abc",����'2'-50 = 0,2-9��������ȥ
    vector<string> s{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"},p{""};
    // �����ж�digits�е������ַ�����ӳ��Ϊ�ַ���
    auto st=digits.begin();
    while(st!=digits.end()){
        vector<string> q;
        // ��ǰ���������ַ������ɵ��ַ�����ȡ��һ��������һ�����ֵ�׷��
        for(const auto& j:p){
            // ȡ����ӳ�����ȡ���ַ��������������׷�ӵ�֮ǰ�ַ����ĺ���
            for(auto i:s[*st-50]){
                // �洢��һ������
                q.push_back(j+i);
            }
        }
        // ��Ӻ��vector���д���
        p=q;
        ++st;
    }
    return p;
}

// ����֮��
/* ����һ������ n ������������ nums ��һ��Ŀ��ֵ target
 * �ж� nums ���Ƿ�����ĸ�Ԫ�� a,b,c �� d,ʹ�� a + b + c + d ��ֵ�� target ���?
 * �ҳ��������������Ҳ��ظ�����Ԫ��
 * */
vector<vector<int>> Solution::fourSum(vector<int>& nums, int target){
    // �㷨����Solution::threeSum�ⷨ,Ϊ����֮����չ��,�����ȹ̶�һ������Ϊ����֮������
    vector<vector<int>> res;
    if(nums.size()<4){ return res;}
    // ����������ȥ���ظ����
    sort(nums.begin(),nums.end());
    // �̶�һ��ֵ��i��Ϊ������
    for(auto i = nums.begin();i!=nums.end()-3;){
        // �̶��ڶ���ֵ��j��Ϊ������
        for(auto j=i+1;j!=nums.end()-2;){
            // ʹ��˫ָ��,�ֱ�ָ��ڶ���������һ��,���������е����һ��
            auto left = j+1;
            auto right = nums.end()-1;
            // ָ�����������ж�
            while(left < right){
                // �ж�����֮����targetֱ�ӹ�ϵ
                if(*i+*j+*left+*right-target>0){
                    // ���������Ҳ�ָ�������ƶ�����һ������ȵ�����
                    auto temp_r = *right;
                    while(right!=left&&*right==temp_r){
                        --right;
                    }
                }else if(*i+*j+*left+*right-target<0){
                    // ��С�������ָ�������ƶ�����һ������ȵ�����
                    auto temp_l = *left;
                    while(right!=left&&*left==temp_l){
                        ++left;
                    }
                }else{
                    // �������򽫴𰸼�����,����ָ��ͬʱ��������һ������ȵ�ֵ
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
            // �ƶ��ڶ����̶���
            auto temp_j = *j;
            while(j!=nums.end()-2&&*j==temp_j){
                ++j;
            }
        }
        // �ƶ���һ���̶���
        auto temp_i = *i;
        while(i!=nums.end()-3&&*i==temp_i){
            ++i;
        }
    }
    return res;
}

//ɾ������ĵ�����N���ڵ�
/*����һ������,ɾ������ĵ����� n ���ڵ�,���ҷ��������ͷ���
 * ����ṹ
 *  struct ListNode{
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 *  };
 * */
ListNode* Solution::removeNthFromEnd(ListNode* head, int n){
    // ����һ���ƽڵ�,��������ɾ��ͷ������
    auto *p=new ListNode(0);
    p->next = head;
    // ����һ��ָ���ƶ�Nλ,Ȼ����ָ�뱣�ּ��ͬʱ����ƶ�
    auto *st=head;
    auto *en=p;
    // ǰ��ָ�����ƶ�Nλ
    while(n>0){
        st = st->next;
        --n;
    }
    // ��ָ��ͬʱ�ƶ�,ֱ��ǰһָ���ƶ���ĩβ
    while(st!= nullptr){
        st = st->next;
        en = en->next;
    }
    // �滻����һָ���next�ڵ�Ϊ��һ�ڵ��next�ڵ��ַ
    auto temp = en->next;
    en->next = temp->next;
    // �ͷű�ɾ���Ľڵ�
    delete temp;
    // ���ƽڵ���һ����ʼ����,��˷���p->next
    return p->next;
}

// ��Ч������
/* ����һ��ֻ���� '('��')','{'��'}','['��']' ���ַ���,�ж��ַ����Ƿ���Ч
 * ��Ч�ַ��������㣺
 * �����ű�������ͬ���͵������űպ�
 * �����ű�������ȷ��˳��պ�
 * ע����ַ����ɱ���Ϊ����Ч�ַ�����
 * */
bool Solution::isValid(const string& s) {
    // ����һ��vector<char>��Ϊ�洢�ַ���ջʹ��
    vector<char> res;
    // ����ж�,��ջ�����һ���ַ�,����ȡ�õ��ַ��ܳ�һ������,�����һ�ַ�����,�������ַ�����
    for(char i : s){
        if(!res.empty()&&((*res.rbegin()=='('&&i==')')||(*res.rbegin()=='{'&&i=='}')||(*res.rbegin()=='['&&i==']'))){
            res.pop_back();
        }else{
            res.push_back(i);
        }
    }
    // ��ջ�в������ַ�����������ȫ���,������˵��������ȫ��ԣ�����ʣ���ַ�
    return res.empty();
}

// ��������
/* ���� n �����������ŵĶ���
 * ����д��һ������,ʹ���ܹ��������п��ܵĲ�����Ч���������
 * ����в������ظ�
 * */
// �㷨1:���ݷ�-->�ݹ�
vector<string> Solution::generateParenthesis_1(int n) {
    vector<string> res;
    if(n==0){return res;}
    recursion4generateParenthesis_1(res,"",0,0,n);
    return res;
}
// ���������㷨1:���ݷ��ĵݹ麯��,����Ҫ�޸ĵ�ֵʱ�������ö��Ǵ�ֵ
void Solution::recursion4generateParenthesis_1(vector<string>& res, const string& temp, int left, int right, int max){
    if(temp.size()==2*max){
        // ������ȴﵽһ������������ӵ��洢�𰸵�������
        res.push_back(temp);
        return;
    }
    // ���������δ�ﵽ���ֵ,ĩβ�������һ��������'('
    if(left < max){
        recursion4generateParenthesis_1(res,temp+'(',left+1,right,max);
    }
    // ���������С��������,ĩβ�������һ��������')'
    if(right<left){
        recursion4generateParenthesis_1(res,temp+')',left,right+1,max);
    }
}
// �㷨2:�հ�����-->�ݹ�
vector<string> Solution::generateParenthesis_2(int n) {
    // ������Ϊ���򷵻�һ�մ�
    if(n==0){
        return vector<string>{""};
    }
    // �洢�𰸵�res
    vector<string> res;
    // ʹ�󴮳�������,����Ϊi,���Ϊn-1,�Ҵ���֮����,����Ϊn-1-i,�������������(left)right��Ӧλ�ô�
    for(int i=0;i<n;++i){
        // �����󴮳���Ϊi�����,���ȡ��Ϊleft
        for(const auto& left:generateParenthesis_2(i)){
            // �����󴮳���Ϊi�����,���ȡ��Ϊright
            for(const auto& right:generateParenthesis_2(n-1-i)){
                // �����������������뵽����
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

// �ϲ�K�������б�
/* ���غϲ������������
 * */
// ������:�������������ֱ�Ӵ���,ȡ���ڵ��ֵ,������������,�ںϳ������Ͻ��и�ֵ,�������׽ڵ�
ListNode* Solution::mergeKLists_1(vector<ListNode *>& lists) {
    // ��δ���κ�����,��ֱ�ӷ��ؿ�ָ��
    if(lists.empty()){return nullptr;}
    // �½�һ���ƽڵ�,�������������г���nullptr
    ListNode head(0);
    ListNode *p=&head;
    // �洢���е�����
    vector<int> s;
    // ��������,����������,���ڵ�����򽫽ڵ��ֵ����vector��,������ÿ�������βʱ,��������
    for(auto & list : lists){
        // �������ַΪ��������,��Ϊ���������һ�ڵ�֮��,��������ָ�����
        if(list!= nullptr){
            p->next = list;
            p=p->next;
        }else{
            continue;
        }
        // ����ȡ��ֵ,�ڶ��������һ��ֵ��������
        while(p!= nullptr){
            s.push_back(p->val);
            if(p->next){
                p=p->next;
            }else{
                break;
            }
        }
    }
    // ����
    sort(s.begin(),s.end());
    // ����ָ������Ϊ�׵�ַ,�����������ֵ����
    p=head.next;
    int i=0;
    while(p!= nullptr){
        p->val=s[i];
        p=p->next;
        ++i;
    }
    // ���������׵�ַ(ȥ���ƽ��)
    return head.next;
}
// ���η�:��������������ϲ�����,���ִ��ֱ����ʣ1����
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
// ���η����õ�˫������ԭλ�ϲ�(�ϲ�������������)
ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode head(0);
    ListNode* p=&head;
    // �ϲ���,��������������ֵ����бȽ�,����ֱ�ӽ��ں���
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
    // �޳��ƽ����з���
    return head.next;
}

// �������������еĽڵ�
/* ����һ������,���������������ڵĽڵ�,�����ؽ����������
 * �㲻��ֻ�ǵ����ĸı�ڵ��ڲ���ֵ��������Ҫʵ�ʵĽ��нڵ㽻��
 * */
// ������,�ֱ���Ҫ���������ڵ��Լ�ǰ���ڵ�,�����ڵ���ɺ�ǰ���ڵ��ƶ�����һ���ǰ���ڵ�λ��
ListNode *Solution::swapPairs_1(ListNode *head) {
    // �����ƽ��
    ListNode temp(0);
    temp.next = head;
    // ���ó�ʼǰ���ڵ�,�����趨���ƽ�㴦
    ListNode *p=&temp;
    // ��¼Ҫ�����������ڵ�
    ListNode *left= nullptr,*right= nullptr;
    // ��ʣ������������������н������ƶ�ǰ���ڵ�,���򲻽���
    while(p->next&&p->next->next){
        left=p->next;
        right=left->next;
        left->next = right->next;
        right->next = left;
        p->next = right;
        p = left;
    }
    // �޳��ƽ����з���
    return temp.next;
}
// �ݹ鷨,�����ж�,���������еĴ�����еݹ�
ListNode *Solution::swapPairs_2(ListNode *head) {
    // ���ڵ���Ϊ0����1��ֱ��ԭ������
    if(!head||!head->next){
        return head;
    }
    // ȡ�����������ڵ�
    ListNode *left=head,*right=head->next;
    // ���Ҳ�ڵ�֮��Ľ��еݹ��ٴ��ж�,������֮��Ľ������ڵ�֮��,�Ҳ�ڵ�ָ�����ڵ�,��ɽ���
    left->next = swapPairs_2(right->next);
    right->next = left;
    // ����ͷ���,��ԭ���ڶ����ڵ�
    return right;
}

// K��һ�鷭ת����
/* ����һ������ÿ k ���ڵ�һ����з�ת�����㷵�ط�ת�������
 * k ��һ��������������ֵС�ڻ��������ĳ���
 * ����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��
 * */
// ����ջԭ��,ʹ��һ���������д洢,�ٷ�������
ListNode *Solution::reverseKGroup_1(ListNode *head, int k) {
    // �����洢�ڵ������
    vector<ListNode*> temp(k);
    ListNode *p = head;
    // ���ڵ㰴���������
    int t=0;
    while(t<k&&p){
        temp[t++] = p;
        p=p->next;
    }
    // �ж������Ƿ�����,����������е���,��δ������ֱ�ӷ���ԭ��
    if(t==k){
        // ��ʣ�ಿ��ͨ���ݹ�����ֿ鷭ת,�����ӵ�ȡ���������ĵ�һ���ڵ�֮��
        temp[0]->next = reverseKGroup_1(temp[k-1]->next,k);
        // ����������ֵ�������Ϊ����
        while(t>1){
            temp[t-1]->next = temp[t-2];
            --t;
        }
        // ͷ��㼴Ϊ���������һ���ڵ�
        return temp[k-1];
    }else{
        return head;
    }
}
// ʹ�õݹ���з�ת���ֿ������
ListNode *Solution::reverseKGroup_2(ListNode *head, int k) {
    // ����ָ�벢��ָ��ָ�����������һ���ڵ�
    ListNode *p = head;
    int t=0;
    while(t<k-1&&p){
        p = p->next;
        ++t;
    }
    // ��ȡ���ɹ�ȡ��һ��������,����з�ת����
    if(t==k-1&&p){
        // ��������֮������õݹ���з�ת,�������Ϊtemp
        ListNode *temp = reverseKGroup_2(p->next,k);
        // ������������һ���ڵ��ÿ�ִ�з�ת����
        p->next = nullptr;
        auto reverseChain = reverseLists(head);
        // �ڷ�ת�������ĩβ���ϴ�������������
        ListNode *m = reverseChain;
        while(m->next){
            m = m->next;
        }
        m->next = temp;
        // ���ط�ת�����������
        return reverseChain;
    }else{
        return head;
    }
}
// ��ת��������
ListNode *Solution::reverseLists(ListNode *head) {
    // ��������Ϊ0��1��ֱ�ӷ���ԭ����
    if(!head||!head->next){
        return head;
    }
    // ����Ҫ����������ڵ��ָ����ҽڵ����һ���ڵ�ķ�ת��ͷָ��
    ListNode *left = head;
    ListNode *right = head->next;
    ListNode *en = right->next;
    head->next = nullptr;
    // �������ӵ��ҽڵ���,����ڵ�ָ���ƶ�������ͷ��,�ҽڵ�ָ��ʹ���ת��ͷָ������ƶ�
    while(en){
        right->next = left;
        left = right;
        right = en;
        en = en->next;
    }
    // ���ҽڵ�ָ�뵽��ĩβʱ,�����������ҽڵ�֮��,�������ҽڵ�
    right->next = left;
    return right;
}

// ɾ�����������е��ظ���
/* ����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³���
 * ��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ�����������
 * */
// �㷨��˫ָ��+��һ��ֵ�ļ�¼
int Solution::removeDuplicates(vector<int> &nums) {
    // ����Ϊ���򷵻�0
    if(nums.empty()){
        return 0;
    }
    // ��ʼ��˫ָ���ڵڶ�����,��һ��ֵ��¼Ϊ��һ����
    int left=1,right,max=nums[0],le=nums.size();
    // ѭ���ж�,����ָ����ָ��ֵ����һ��ȡ�õ�ֵ���������뵽��ָ�봦,����������ָ�����
    for(right=1;right<le;++right){
        if(nums[right]!=max){
            max = nums[right];
            nums[left++] = max;
        }
    }
    return left;
}

// �Ƴ�Ԫ��
/* ����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³���
 * ��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ�����������
 * Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ��
 * */
int Solution::removeElement(vector<int> &nums, int val) {
    int left=0,right,le=nums.size();
    // ѭ���ж�,����ָ����ָ��ֵ���ɾ����ֵ���������뵽��ָ�봦,����������ָ�����
    for(right=0;right<le;++right){
        if(nums[right]!=val){
            nums[left++] =nums[right];
        }
    }
    return left;
}

// ʵ��strStr()
/* ����һ�� haystack �ַ�����һ�� needle �ַ���
 * �� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)
 * ��������ڣ��򷵻� -1��
 * */
// ��������,Ч�ʵ��ظ��ж϶�,ʱ�临�Ӷ�O(MN)
int Solution::strStr_1(const string& haystack, const string& needle) {
    if(needle.empty()){
        return 0;
    }
    int flag = 1;
    // ����Ƚ�,�����һ���ַ�ƥ����鿴֮���ַ��Ƿ�ƥ��,��ƥ�������½���ƥ���һ����ĸ
    for(int i=0;i<haystack.size();++i){
        for(int j=0;j<needle.size();++j){
            if(haystack[i+j]!=needle[j]){
                flag = 0;
                break;
            }
        }
        // ��ƥ���������������ַ���,��flagӦΪ1,���ش�ʱ���±�
        if(flag){
            return i;
        }
        flag = 1;
    }
    return -1;
}
// KMP�㷨,�����˷�������,ʱ�临�Ӷ�ΪO(N),������һ�������ӳ��,����ӳ�������˴�ƥ����ַ���,��������next_map
int Solution::strStr_2(const string &haystack, const string &needle) {
    // ����ƥ���ַ���Ϊ���򷵻�0
    if(needle.empty()){
        return 0;
    }
    int k=0;
    // ���ɹ���ǰ��׺���ȱ�,link[i]��ʾ��ƥ���ַ���ǰi���ַ��й�����ǰ��׺�ַ������ȴ�С
    vector<int> link = next_map(needle);
    // ɨ��������ַ���,����������ƥ���ַ���ָ�����,�����ɺ�׺����ǰ׺λ��,���ٲ���Ҫ���ж�
    for(auto i=0;i<haystack.size();++i){
        // ����ƥ���ַ���ָ�벻Ϊ��һ�����жϲ����,�������ǰ��ת
        while(k>0&&haystack[i]!=needle[k]){
            k = link[k-1];
        }
        // �����,��ƥ���ַ���ָ�����
        if(haystack[i]==needle[k]){
            ++k;
        }
        // ���Ѿ�ƥ���������з���
        if(k==needle.size()){
            return i-k+1;
        }
    }
    // ��δ�������򷵻�-1
    return -1;
}
// KMP�㷨��������,�������ɴ�ƥ���ַ����������ǰ��׺����,��������м�¼
vector<int> Solution::next_map(string p) {
    int le = p.size(),k=0;
    vector<int> table(le);
    // ǰ0���ַ�ƥ��̶�Ϊ0
    table[0] = 0;
    // ����ɨ��,��ǰָ�����βָ�봦��ֵ,��k����1����ֵ�������Ӧλ��
    for(int i=1;i<le;++i){
        // ������������˵����Ҫ��ǰ��ת,��˲鿴ǰһ������תλ��
        while(k>0&&p[k]!=p[i]){
            k = table[k-1];
        }
        // ����򹫹�ǰ��׺��������1
        if(p[k]==p[i]){
            ++k;
        }
        table[i] = k;
    }
    return table;
}

// �������
/* �������������������� dividend �ͳ��� divisor�������������Ҫ��ʹ�ó˷��������� mod �����
 * ���ر����� dividend ���Գ��� divisor �õ�����
 * �������ͳ�����Ϊ 32 λ�з�������
 * ������Ϊ 0
 * �������ǵĻ���ֻ�ܴ洢 32 λ�з�������������ֵ��Χ��[INT_MIN, INT_MAX]
 * �����У�����������������򷵻�INT_MAX
 * */
int Solution::divide(int dividend, int divisor) {
    // ��������Ϊ0���߳���Ϊ1��ֱ�ӷ��ر�����
    if(dividend==0||divisor==1){
        return dividend;
    }
    // ��������Ϊ���ҳ���Ϊ-1������,ֱ�ӷ���INT_MAX
    if(dividend==INT_MIN&&divisor==-1){
        return INT_MAX;
    }
    // ��¼����,ȫ��ת���������ʹ��
    int flag = 1;
    if(dividend > 0){
        flag = 0-flag;
        dividend = 0-dividend;
    }
    if(divisor>0){
        flag = 0-flag;
        divisor = 0-divisor;
    }

    int bdv = divisor; // ������
    int count = 1; // ��¼����������ڳ�ʼֵ�ı���
    int res = 0; // ��¼����
    // �ݼ�������ÿ��һ�ν���һ�η���,�������޶�ֵ,�����´���С��ʼ����,���Ĵ�������
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
    // ����Ϊ�������ȡ����
    if(flag==-1){
        res = 0-res;

    }
    return res;
}

// �������е����Ӵ�
/* ����һ���ַ��� s ��һЩ������ͬ�ĵ��� words
 * �ҳ� s ��ǡ�ÿ����� words �����е��ʴ����γɵ��Ӵ�����ʼλ��
 * ע���Ӵ�Ҫ�� words �еĵ�����ȫƥ�䣬�м䲻���������ַ���������Ҫ���� words �е��ʴ�����˳��
 * */
// ���ô��ڰ������ж�,��������ָ�������������ӿ�ʼλ��
vector<int> Solution::findSubstring(const string& s, vector<string> &words) {
    // �洢�𰸵��±�
    vector<int> res;
    // ��s��wordsΪ���򷵻�һ���յĽ��
    if (s.empty() || words.empty()) {
        return res;
    }
    // ȡ�õ�������word_count,���ʳ���one_word,������s�ĳ���s_len,���ڴ�Сwin_len
    int word_count = words.size();
    int one_word = words[0].size();
    int s_len = s.size();
    // int win_len = word_count * one_word;
    unordered_map<string, int> refer;
    for (const auto& word : words) {
        ++refer[word];
    }
    // �ӵ�һ�����ʵĲ�ͬλ�ÿ�ʼ,�Ա��ⳤ�Ȳ�ͬ�����µ�©�����
    for (int i = 0; i < one_word; ++i) {
        // ������ָ��left,��ָ��right,������count
        int left = i, right = i,count=0;
        // ���ڼ�¼��ǰ�����еĸ�����������
        unordered_map<string, int> sign;
        // ѭ������ж�,ֱ�����û�е���
        while (right + one_word <= s_len) {
            // ȡ�����ʷ��봰��
            string temp = s.substr(right, one_word);
            right += one_word;
            // ȡ�õĵ��ʲ����ڴ�ѡ������,��������sign,count����,left�ƶ���right��
            if (refer[temp] == 0) {
                count = 0;
                left = right;
                sign.clear();
            }
            else{
                // ȡ�ʳɹ�,��������,��ȡ���֮���������������left������ȥ���ظ�����
                ++count;
                ++sign[temp];
                while (sign[temp] > refer[temp]) {
                    string po = s.substr(left, one_word);
                    --count;
                    left += one_word;
                    --sign[po];
                }
                // �������еĵ�����������������һ���򽫴��ڿ�ʼ�±���뵽�����
                if (count == word_count) {
                    res.push_back(left);
                }
            }
        }
    }
    return res;
}

// ��һ������
/* ʵ�ֻ�ȡ��һ�����еĺ������㷨��Ҫ���������������������г��ֵ�������һ�����������
 * �����������һ����������У��������������г���С�����У����������У�
 * ����ԭ���޸ģ�ֻ����ʹ�ö��ⳣ���ռ�
 * ˼·:��Ϊ���ֵ������Ҫ���ʦ��Ϊ�ݼ�
 * ����Ϊ�ݼ�,���ݼ����ֵ�ǰһ����ֵ��������,�ӵݼ�������һ���ϴ��ֵ�����滻
 * ������ɵ����ﵽ����֮�����Сֵ
 * �磺4132,ֻ��ͨ������1�Ĵ�С��������ֵ,��˴�32��ѡһ������1����Сֵ�����滻
 * �任��4231��ʱ��������42��ͷ����С��,��˽�31������4213������4132����һ����
 * */
void Solution::nextPermutation(vector<int> &nums) {
    // Ϊ�ղ����в���
    if(nums.empty()){
        return;
    }
    // ȡ�����鳤��,�Ӻ���ǰ�����������бȽ�,��ǰһ���Ⱥ�һ��С��ֹͣ,ָ��ָ���С���Ǹ���
    int le = nums.size();
    int st=le-2;
    while(st>=0&&nums[st]>=nums[st+1]){
        --st;
    }
    // ��ָ��ͣ���ڵ�0����ǰһ��,˵����������ݼ�,��ʱ����
    if(st!=-1){
        int temp = nums[st];
        int en = le-1;
        // �Ӻ���ǰȡ,ȡ�õ�һ������nums[st]��ֵ
        while(en>st&&nums[en] <= temp){
            --en;
        }
        // ���ϴ���Ǹ�ֵ��nums[st]���н���
        my_swap(nums[st],nums[en]);
    }
    // ����ȡ��stָ��󷽵�����ֵ���з�ת
    int l = st+1;
    int r = le-1;
    while(r>l){
        my_swap(nums[l],nums[r]);
        ++l;
        --r;
    }
}
// ��������ֵ,��������,��������д
inline void Solution::my_swap(int &x,int &y){
    int temp = x;
    x = y;
    y = temp;
}

// ���Ч����
/* ����һ��ֻ���� '(' �� ')' ���ַ���
 * �ҳ���İ�����Ч���ŵ��Ӵ��ĳ��ȡ�
 * */
// ջ����,���õ�ջʱ�Ĳ�����ֵ��ȡ��󳤶�,��Ϊ��ѧ
int Solution::longestValidParentheses_1(const string& s) {
    int max=0;
    // ����ջԤ��ѹ��-1
    vector<int> stackTemp;
    stackTemp.push_back(-1);
    for(int i=0;i<s.size();++i){
        if(s[i]=='('){
            // ����������ֱ��ѹ��
            stackTemp.push_back(i);
        }else{
            // ����������ֱ���ȵ���ԭ�е�ֵ,��Ϊ�����Լ�����,������㳤��,��֤��������һ��ֵ
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
// ��̬�滮,��������洢ÿ���ַ�֮ǰ���ܹ��ɵ���Ч���ų���
int Solution::longestValidParentheses_2(const string &s) {
    int le = s.size();
    // ��������,dp[i]��ʾ�Ե�iλ��β����Ч���ų���
    vector<int> dp(le,0);
    int max = 0;
    // ���ڵ�һλ��'('����')',��dp[0]=0,ֱ�Ӵӵڶ������ſ�ʼ�ж�
    for(int i=1;i<le;++i){
        // �����������,�ж�ǰһλ������
        if(s[i]==')'){
            // �����'()'��'X()'��X������Ч���ų��ȼ�2��ֵ����ʱ��dp[i]
            if(s[i-1]=='('){
                dp[i] = (i>1?dp[i-2]:0)+2;
            }else if(i>dp[i-1]&&s[i-dp[i-1]-1]=='('){
                // �����'))'���ж�ǰ����Ч���ŵ���һ���Ƿ�Ϊ'(',�����������Ч���ŵ�ǰ����м�������Ч������������
                dp[i] = dp[i-1]+(i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0)+2;
            }
        }
        // �޸�dp[i]��ɺ�,�����ж��Ƿ�������ֵ
        max = dp[i]>max?dp[i]:max;
    }
    return max;
}
// ˫�����,�ֱ���������������Ч���ų���,ȡ�ϴ�ֵ
int Solution::longestValidParentheses_3(const string &s) {
    // ��ʼ��һ��left��right���ڼ�¼������������,�ͼ�¼���ֵ��max
    int right=0,left=0,max=0;
    // �����ж�,�������Ŵ�������������,���������,����������м������ֵ
    for(char i : s){
        // ����
        if(i=='('){
            ++left;
        }else{
            ++right;
        }
        // �ж��Ƿ�Ӧ������,������м������ֵ
        if(right > left){
            right = 0;
            left = 0;
        }else if(right==left){
            max = 2 * right > max ? 2 * right : max;
        }
    }
    left = right = 0;
    // �����ж�ͬ����
    for(auto i=s.rbegin();i!=s.rend();++i){
        // ����
        if(*i=='('){
            ++left;
        }else{
            ++right;
        }
        // �ж��Ƿ�Ӧ������,������м������ֵ
        if(right < left){
            left = right = 0;
        }else if(right==left){
            max = 2 * right > max ? 2 * right : max;
        }
    }
    return max;
}

// ������ת��������
/* ���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת
 * ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2]
 * ����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� -1
 * ����Լ��������в������ظ���Ԫ��
 * ����㷨ʱ�临�Ӷȱ����� O(log n) ����
 * */
// �ݹ�,���ֲ���
int Solution::search(vector<int> &nums, int target) {
    if(nums.empty()){
        return -1;
    }
    int le = nums.size(),res=-1,pot=le-1;
    int st=0;
    // ���ֲ��Ҳ��ҷ�ת��
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
    // ��β��ֵ���бȽ�,����תǰǰ��ε����ֵ,���������ֵ���ڷ�ת��֮ǰ���в���,�����ڷ�ת��֮����в���
    if(target>nums[le-1]||pot==le-1){
        res =divide_search(nums,0,pot,target);
    }else{
        res =divide_search(nums,pot+1,le-1,target);
    }
    return res;
}
// ���ֲ����㷨,ѭ����
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

// �����������в���Ԫ�صĵ�һ�������һ��λ��
/* ����һ�������������е��������� nums
 * ��һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ��
 * ����㷨ʱ�临�Ӷȱ����� O(log n) ����
 * ��������в�����Ŀ��ֵ������ [-1, -1]
*/
// ���ַ�������һ�����ڵ���target��ֵ,������һ������target��ֵ
vector<int> Solution::searchRange(vector<int>& nums, int target){
    vector<int> res(2,-1);
    // �Ȳ�һ�����ڵ���target��ֵ,���������򷵻�{-1,-1}
    int temp = search_le(nums,target, true);
    if(temp==nums.size()||nums[temp]!=target){
        return res;
    }
    // ������target���ٲ���һ������target��ֵ,���±��1��Ϊ���һ��target
    res[0] = temp;
    res[1] = search_le(nums,target, false)-1;
    return res;
}
// �������ֲ����㷨,>=���ҵ�һ������target,>���ҵ�һ������target
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

// ������ 10.01. �ϲ����������
/* ������������������ A �� B������ A ��ĩ�����㹻�Ļ���ռ����� B�� ��дһ���������� B �ϲ��� A ������
 * ��ʼ�� A �� B ��Ԫ�������ֱ�Ϊ m �� n
 * ����:
 * A = [1,2,3,0,0,0], m = 3
 * B = [2,5,6],       n = 3
 * ���: [1,2,2,3,5,6]
 * */
// �����Ƚϰ��������ʱ����,������ɸ��ƻ�A
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

// ��Ч������
/* �ж�һ�� 9x9 �������Ƿ���Ч��ֻ��Ҫ�������¹�����֤�Ѿ�����������Ƿ���Ч����
 * ���� 1-9 ��ÿһ��ֻ�ܳ���һ��
 * ���� 1-9 ��ÿһ��ֻ�ܳ���һ��
 * ���� 1-9 ��ÿһ���Դ�ʵ�߷ָ��� 3x3 ����ֻ�ܳ���һ��
 * ��������
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
// �ֱ���,����,��3��3��������ж�
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
// ����Χ�ڵ������ַ����м���,�����ڴ���1���򷵻�false,���򷶺�true
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
// ������
/* ��дһ������ͨ�������Ŀո��������������
 * */
// ������,����ÿ���ո��������1-9,�ж��Ƿ���Ч,����Ч�����������,ֱ�����пո�����
void Solution::solveSudoku(vector<vector<char>> &board) {
    bool res = co_solveSudoku(board);
}
// �������ĵݹ鸨������,���������������,�����������
bool Solution::co_solveSudoku(vector<vector<char>> &board) {
    // �ҳ���һ������ո�
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
    // ����ĩβ��˵���������,��������
    if (left == 9 && right == 9 && board[left-1][right-1] != '.') {
        return true;
    }
    // ��������,�ж��Ƿ���Ч,����Ч�������������,����Ч���жϵݹ���Ƿ�������������Լ��ÿս��л���
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
/* �ݹ�-���ݷ�,ȡ3����ά����,�ֱ��¼ÿһ��,ÿһ��,ÿһ��С����ڲ�ֵ
 * �������ֵ���κ�һ��������,����������һ����,������ɹ�,���¶�Ӧ������С��
 * �����ʼֵȡ��ʼ�������ֵ,������ʧ�ܻ���������������л���
 * �˴�����¼˼·
 * */
// �������
/* ��������С���һ���������У������� 1 ��ʼ�������е�ÿһ��Ƕ�ǰһ���������ǰ��������
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 ������  "one 1"  ("һ��һ") , �� 11
 * 11 ������ "two 1s" ("����һ"��, �� 21
 * 21 ������ "one 2",  "one 1" ��"һ����" ,  "һ��һ") , �� 1211
 * ����һ�������� n��1 �� n �� 30�������������еĵ� n �
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

// ���õ�����
/* �ڸ����������У�ÿ����Ԫ���������������ֵ֮һ:
 * ֵ 0 ����յ�Ԫ��
 * ֵ 1 ������������
 * ֵ 2 �����õ�����
 * ÿ���ӣ��κ��븯�õ����ӣ��� 4 ���������ϣ����ڵ��������Ӷ��ḯ��
 * ����ֱ����Ԫ����û����������Ϊֹ�����뾭������С����������������ܣ����� -1
 * */
int Solution::orangesRotting(vector<vector<int>>& grid){
    // ���Ϊ���򷵻�-1
    if(grid.empty()||grid[0].empty()){
        return -1;
    }
    // ��¼��Ⱦ����,�ж��Ƿ����˸�ȾlockΪ1Ϊδ������Ⱦ,lockΪ0Ϊ�����˸�Ⱦ
    int count = 0,lock=0;
    int row = grid.size(),col = grid[0].size();
    auto temp = grid;
    // ����ִ��,ֱ����������Ⱦ
    while(true){
        // �ж��Ƿ��и����������������и�Ⱦ,������ԭ�ȸ��õ�����,���������������Ϊ��Ⱦ��
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if(temp[i][j]==2){
                    grid[i][j] = 0;
                    // ����ɹ���Ⱦ���ж��Ƿ�������Ⱦ�Ŀ�����Ϊ����
                    lock += rotOranges(grid,i,j,row,col);
                }
            }
        }
        // ��δ������Ⱦ������ѭ��
        if(!lock){
            break;
        }
        // ��ʼ����һ���ж�
        temp = grid;
        ++count;
        lock = 0;
    }
    // �ж��Ƿ����Ҵ���,�������Ҵ����򷵻�-1
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if(grid[i][j]==1){
                return -1;
            }
        }
    }
    return count;
}
// ���õ�����--��Ⱦ����,�ж��Ƿ񳬳��߽�,�������Ӹ�Ⱦ
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

// ����ܺ�
/* ����һ�����ظ�Ԫ�ص����� candidates ��һ��Ŀ���� target ���ҳ� candidates �����п���ʹ���ֺ�Ϊ target �����
 * candidates �е����ֿ����������ظ���ѡȡ
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

// ���ǹ�II
/* �����������ǹ�
 * ��������һЩ�ǹ� candies����������Ƿָ��źöӵ� n = num_people ��С����
 * ����һ��С���� 1 ���ǹ����ڶ���С���� 2 �ţ��������ƣ�ֱ�������һ��С���� n ���ǹ�
 * Ȼ�������ٻص��������㣬����һ��С���� n + 1 ���ǹ����ڶ���С���� n + 2 ��
 * �������ƣ�ֱ�������һ��С���� 2 * n ���ǹ�
 * �ظ��������̣�ÿ�ζ�����һ�ζ����һ���ǹ�������������յ���ٴδӶ�����㿪ʼ��
 * ֱ�����Ƿ������е��ǹ���ע�⣬�����������е�ʣ���ǹ�������������ǰһ�η������ǹ��ࣩ����Щ�ǹ�Ҳ��ȫ��������ǰ��С����
 * ����һ������Ϊ num_people��Ԫ��֮��Ϊ candies �����飬�Ա�ʾ�ǹ������շַ�������� ans[i] ��ʾ�� i ��С���ѷֵ����ǹ�������
 * */
// ����--�ַ���˳���
vector<int> Solution::distributeCandies(int candies, int num_people) {
    // �洢���
    vector<int> res(num_people,0);
    // �÷ַ��ĸ���
    int give_num=1;
    while(candies > 0){
        for (int i = 0; i < num_people; ++i) {
            // �ȿ۳��˴�Ҫ�ַ����ǹ�
            candies -= give_num;
            // ���С��0��˵��������պ÷���������Ҫ����,�����Ͱ����Ķ������һ����
            if(candies > 0){
                res[i] += give_num;
            }else{
                res[i] += candies;
                res[i] += give_num;
                break;
            }
            // ��һ�ηַ���ֵ
            ++give_num;
        }
    }
    // ���ؽ��
    return res;
}

// ��Ϊs��������������
/* ����һ�������� target ��������к�Ϊ target ����������������(���ٺ���������)
 * �����ڵ�������С�������У���ͬ���а����׸����ִ�С�������С�
 * */
// ʹ��vector��������
vector<vector<int>> Solution::findContinuousSequence_1(int target){
    // ��¼���
    vector<vector<int>> res;
    vector<int> getList;
    int sum = 0;
    int numList = 0;
    // ȷ�ϴ������ֵ
    while(sum<target){
        getList.push_back(++numList);
        sum += numList;
    }
    // ��������ƶ�,���ݺ�target��ֵ�ıȽϽ��б䶯����
    while(getList.size()>1&&numList<=target/2+1){
        if(sum==target){    // �����,���Ҵ��ں���
            res.push_back(getList);
            sum -= getList[0];
            getList.erase(getList.begin());
            getList.push_back(++numList);
            sum += numList;
        }else if(sum > target){ //��������
            sum -= getList[0];
            getList.erase(getList.begin());
        }else{  // ���ڼӳ�
            getList.push_back(++numList);
            sum += numList;
        }
    }
    return res;
}
// ʹ��˫ָ����Ϊ���ڱ߽�,��������ֵʹ����͹�ʽ
vector<vector<int>> Solution::findContinuousSequence_2(int target){
    // �洢��
    vector<vector<int>> res;
    int left=1,right=2;
    // ������˶��ൽtarget/2,ÿ��ѭ�����㴰������ֵ�ܺ�
    while(left<=target/2){
        int sum = (left+right)*(right-left+1)/2;
        if(sum < target){   // ��С��,�����ұ߽����,�ܺͱ��
            ++right;
        }else if(sum > target){ // ������,������߽����,�ܺͱ�С
            ++left;
        }else{  // ������,��¼��������,�����������
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
// ����ܺ� II
/* ����һ������ candidates ��һ��Ŀ���� target
 * �ҳ� candidates �����п���ʹ���ֺ�Ϊ target �����
 * candidates �е�ÿ��������ÿ�������ֻ��ʹ��һ��
 * */
// ������,�Ƚ�������,�ٽ���ѡ����ͬһ���б���ѡ��ͬһ����
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
        // ������ͬ����
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

// ȱʧ�ĵ�һ������
/* ����һ��δ������������飬�ҳ�����û�г��ֵ���С��������
 * */
// �������뵽�����Ӷ�Ϊn����ҪͰ����,Ȼ���ռ临�Ӷ�Ϊ1,���ǲ��ܶ��ⴴ��Ͱ,�������ԭλʹ�÷��Ž��б��
int Solution::firstMissingPositive(vector<int>& nums) {
    // ����Ƿ���1,����������ֱ�ӷ���1
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
    // �����ڳ��ȵ����ͷ�������Ϊ1,���ڼ򻯼���
    int le=nums.size();
    for(auto &i:nums){
        if(i<=0||i>le){
            i = 1;
        }
    }
    // ������ȫΪ����,���������µĿռ�,����ԭλ�÷��ű���Ƿ����,-�Ŵ�����ֹ������,�Ƚ�ʱʹ�þ���ֵ
    for(int i=0;i<nums.size();++i){
        int temp = nums[i] < 0?-nums[i]:nums[i];
        if(nums[temp-1]>0){
            nums[temp-1] *= -1;
        }
    }
    // ȡ���ĵ�һ������Ϊȱʧ����,��δȡ����˵��ǰ�治ȱʧ,����n+1
    for(int i=0;i<le;++i){
        if(nums[i]>0){
            return i+1;
        }
    }
    return le+1;
}

// ����ˮ
/* ���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ
 * ���㰴�����е����ӣ�����֮���ܽӶ�����ˮ
 * */
/* ������,ɨ��ÿһ������,��������һ����ߵ�����,���������ϵ���ˮ��Ϊ���߽�Сֵ��ȥ���Ӹ߶�
 * �����������ϵ�ˮ���������Ϊ��ˮ��
 * ʱ�临�Ӷ�O(n^2),�ռ临�Ӷ�O(1)
 * */
/* ��̬�滮,����ڱ�����ÿ��������ɨ��,���ǿ��Խ�����������߸߶Ƚ��б���
 * ������������dp_right,dp_left���ڴ洢���ֵ
 * ����dp_right[i]�����i�����ӵ��ұ����ֵ,dp_left[i]����������ߵ����ֵ
 * ����ñ���������
 * ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
 * */
/* ջ:�ֱ�ѹ������,�����еĸ߶ȴ���ǰһ����˵���������
 * ��ǰ�������Ҽ�������С,֪�����е���ȫ��ɨ�����
 * */
// ˫ָ�뷨,����˴���һ�������Լ����������Լ�һ��������
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

// ��ת�ַ����ݹ鷨
/* ��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ����
 * ��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ����
 * ����Լ��������е������ַ����� ASCII ����еĿɴ�ӡ�ַ�
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

// ��Ǯ�һ�
/* ������ͬ����Ӳ�� coins ��һ���ܽ�� ori
 * ��дһ��������������Դճ��ܽ����������ٵ�Ӳ�Ҹ���
 * ���û���κ�һ��Ӳ�����������ܽ����� -1
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

// ������Ʊ�����ʱ��
/* ����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
 * ��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������
 * ע���㲻���������Ʊǰ������Ʊ
 * */
// ��̬�滮1--������dp����,ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
int Solution::maxProfit_1(vector<int>& prices) {
    // ȡ�ó���,��Ϊ0�򷵻�0,���򴴽�һ��dp����,�Ӻ���ǰ����,���һ��ֱ������
    int le=prices.size();
    if(le==0){
        return 0;
    }
    vector<int> dp(le,0);
    dp[le-1]=prices[le-1];
    int max = 0;
    // dp[i]�ڴ洢��i����֮������ֵ
    for(auto i=le-2;i>=0;--i){
        // ����dp
        if(prices[i]>dp[i+1]){
            dp[i] = prices[i];
        }else{
            dp[i] = dp[i+1];
        }
        // �жϴ�λ�õ������������ȡ�õ�����������
        int temp = dp[i]-prices[i];
        max = temp>max?temp:max;
    }
    return max;
}
// ��̬�滮2--1���Ż�,ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
int Solution::maxProfit_2(vector<int>& prices) {
    // ȡ�ó���,��Ϊ0�򷵻�0
    int le=prices.size();
    if(le==0){
        return 0;
    }
    // get_num�洢��i����֮������ֵ,max�洢����ֵ
    int get_num = prices[le-1];
    int max = 0;
    for(auto i=le-2;i>=0;--i){
        // ����get_num
        if(prices[i]>get_num){
            get_num = prices[i];
        }
        // �жϴ�λ�õ������������ȡ�õ�����������
        int temp = get_num-prices[i];
        max = temp>max?temp:max;
    }
    return max;
}

// ��������ֱ��
/* ����һ�ö�����������Ҫ��������ֱ������
 * һ�ö�������ֱ�������������������·�������е����ֵ
 * ����·�����ܴ��������
 * */
// �ֱ����ÿ���ڵ���Ϊ���ڵ�ʱ�ĳ���,������max�����max
int Solution::diameterOfBinaryTree(TreeNode* root) {
    int max=1;
    deep4Tree(root,max);
    return max-1;
}
// ����ÿ�����ڵ㴦�ĳ���
int Solution::deep4Tree(TreeNode* root,int& max){
    // ���ڵ�Ϊnullptr����0
    if(root==nullptr){
        return 0;
    }
    // ����������еݹ�,�ڵݹ�ʱ�Ѿ������֮��ڵ�Ŀ�����
    int left = deep4Tree(root->left,max);
    int right = deep4Tree(root->right,max);
    // �ܳ���Ϊ�󳤶ȼ��ҳ��ȼ��ϸ��ڵ�1
    int sum = left+right+1;
    // �������ֵ
    max = max>sum?max:sum;
    // ����root�ڵ�֮������
    return (right>left?right:left)+1;
}

// ������ֳɺ���ȵ���������
/* ����һ���������� A��ֻ�п��Խ��仮��Ϊ��������ȵķǿղ���ʱ�ŷ��� true�����򷵻� false
 * ��ʽ�ϣ���������ҳ����� i+1 < j ������
 * (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])
 * �Ϳ��Խ��������ȷ�
 * */
// �����Ϊ���ݿ����Ƚ����ܺ������ȡ�鿴�Ƿ���ȡ��������,���жϵ������Ƿ�Ϊ��
bool Solution::canThreePartsEqualSum(vector<int>& A){
    // �������
    int sum=0;
    for(const auto &i:A){
        sum += i;
    }
    // �����ܱ�3ƽ���򷵻�false
    if(sum%3){
        return false;
    }
    // ����Ϊ3��
    sum /= 3;
    int index=0;
    int count = 0;
    int temp=0;
    int le=A.size();
    // ѭ�����,������sumʱ������һ,�ӵ�2ʱ����ѭ��
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
    // ���Ѿ�ȡ�������ҵ����ݲ�Ϊ����˵�����Ա���Ϊ����
    return count == 2&&index!=le;
}

// �ַ������
/* �����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2
 * ���� num1 �� num2 �ĳ˻�
 * ���ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ
 * �磺"12"��"5"="60"
 * */
// ����ʽ�������
string Solution::multiply(string num1, string num2) {
    // ����һ��ֵΪ�������ض�Ϊ0
    if(num1=="0"||num2=="0"){
        return "0";
    }
    // mλ��nλ������m+nλ,����һ����Ϊm+n���ַ������д洢
    int l1=num1.size();
    int l2=num2.size();
    string res(l1+l2,'0');
    // �洢��λ
    int over_sign=0;
    // ȡ��num1��һ�����ֱ���num2�е�ÿ�����
    for(int i=l1-1;i!=-1;--i){
        int left=num1[i]-48;
        for (int j = l2-1; j>=0; --j) {
            int right=num2[j]-48;
            // ������ʽ�ĵ�i+j+1λ,��ԭ�ȵ�ֵ,��λֵ,�˻�ֵ�������ȡ��λ��,������Ϊ��λ
            int temp = left*right+over_sign+res[i+j+1]-48;
            over_sign = temp/10;
            res[i+j+1] = static_cast<char>(temp%10+48);
        }
        // ��λֵ�洢�ڵ�ǰ�����λ����ս�λֵ
        if(over_sign){
            res[i] = static_cast<char>(over_sign+48);
            over_sign = 0;
        }
    }
    // ȥ���ַ���ͷ�����ֵ�0
    auto st = res.begin();
    while(*st=='0'){
        ++st;
    }
    return string(st,res.end());
}

// ͨ���ƥ��
/* ����һ���ַ��� (s) ��һ���ַ�ģʽ (p) ��ʵ��һ��֧�� '?' �� '*' ��ͨ���ƥ��
 * '?' ����ƥ���κε����ַ�
 * '*' ����ƥ�������ַ������������ַ�����
 * �����ַ�����ȫƥ�����ƥ��ɹ���
 */
// ����ƥ��,��dp[i-1][j-1]Ϊ��������,�ֱ��?,*����ƥ�� ������
bool Solution::isMatch_Wildcard(string s, string p) {
    // ����Ȼ���ֱ��ƥ�������ַ�����ֱ�ӷ�����
    if(s==p||p=="*"){
        return true;
    }
    // ������һ��Ϊ�����޷�ƥ��Ϊ��
    if(p.empty()||s.empty()){
        return false;
    }
    // ����һ��dp���鲢������Ԫ������Ϊ��,dp[0][0]��ʼ��Ϊfalse
    int ls = s.size();
    int lp = p.size();
    bool dp[lp+1][ls+1];
    for(int i=0;i<lp+1;++i){
        for(int j=0;j<ls+1;++j){
            dp[i][j] = false;
        }
    }
    dp[0][0] = true;
    // ��ģʽ�ַ�����ÿ���ַ�ȥƥ���ƥ����ַ���
    for(auto p_index=1;p_index<lp+1;++p_index){
        // ��ģʽ�ַ�Ϊ*,��ƥ���Ѿ�ƥ�䲿��֮��������ַ�
        // ��Ϊ����ƥ�������Ѿ�ƥ���ַ����һ���ַ�
        // ������ƥ���Ѿ�ƥ��֮�����ͬ�ַ�
        if(p[p_index-1]=='*'){
            int s_index=1;
            // �����Ѿ�ƥ���λ�õ���λ��
            while(!dp[p_index-1][s_index-1]&&s_index<ls+1){
                ++s_index;
            }
            dp[p_index][s_index-1] = dp[p_index-1][s_index-1];
            while(s_index<ls+1){
                dp[p_index][s_index++] = true;
            }
        }else if(p[p_index-1]=='?'){
            // �����Ѿ�ƥ���ַ�����һ��
            for(int s_index=1;s_index<ls+1;++s_index){
                dp[p_index][s_index] = dp[p_index-1][s_index-1];
            }
        }else{
            // ƥ���Ѿ�ƥ���ַ���һ����ͬ���ַ�
            for(int s_index = 1; s_index < ls + 1; s_index++) {
                dp[p_index][s_index] = dp[p_index - 1][s_index - 1] &&(p[p_index - 1] == s[s_index - 1]);
            }
        }
    }
    return dp[lp][ls];
}

// ȫ����
/* ����һ��û���ظ����ֵ����У����������п��ܵ�ȫ����
 * */
// �ݹ�����ȫ����
vector<vector<int>> Solution::permute(vector<int>& nums) {
    int le=nums.size();
    vector<int> temp;
    vector<vector<int>> res;
    vector<int> map_my(le,1);
    co_permute(nums,map_my,temp,res);
    return res;
}
// �ݹ�����ȫ����
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

// �����������
/* ����һ��������������飬�ҵ���������������еĳ���
 * */
// ��̬�滮--���Ӷ�O(n^2),dp�洢�ɵ�ǰ���ֽ�β�����������еĳ���
int Solution::lengthOfLIS(vector<int>& nums) {
    // ����dp����,���ڴ洢��󳤶�
    int le = nums.size();
    vector<int> dp(le,1);
    // ���dp����
    for(int i=1;i<le;++i){
        for(int j=0;j<i;++j){
            if(nums[i]>nums[j]&&dp[j]>=dp[i]){
                dp[i] = dp[j]+1;
            }
        }
    }
    // ȡ�����ֵ
    int max=0;
    for(int k=0;k<le;++k){
        max = max>dp[k]?max:dp[k];
    }
    return max;
}

// �����������
/* ����һ��������һЩ 0 �� 1�ķǿն�ά���� grid
 * һ�� ���� �����ĸ����� (ˮƽ��ֱ) �� 1 (��������) ���ɵ����
 * ����Լ����ά������ĸ���Ե����ˮ��Χ��
 * �ҵ������Ķ�ά���������ĵ��������(���û�е��죬�򷵻����Ϊ0)
 * */
// �������-dps
int Solution::maxAreaOfIsland(vector<vector<int>>& grid){
    // �ж��Ƿ����Ԫ��
    if(grid.empty()||grid[0].empty()){
        return 0;
    }
    //��¼���ֵ�Ͷ�ά�����С
    int max = 0;
    int row = grid.size();
    int col = grid[0].size();
    // �������������Ĳ��ֽ�����չ����ֱ���޷���չ
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if(grid[i][j] == 1){
                // ������ȱ���,��󷵻��ܿ���
                int temp = dps_maxAreaOfIsland(grid,i,j);
                // �������ֵ
                max = max>temp?max:temp;
            }
        }
    }
    return max;
}

int Solution::dps_maxAreaOfIsland(vector<vector<int>>& grid,int dx,int dy){
    // Խ������ڸ���Ϊ0��ֱ�ӷ���0
    if(dx<0||dy<0||dx>=grid.size()||dy>=grid[0].size()||grid[dx][dy]==0){
        return 0;
    }
    // ��������Ϊ0,��ֹ�ظ�����
    grid[dx][dy] = 0;
    int max = 1;
    // ��ѯ����
    max += dps_maxAreaOfIsland(grid,dx-1,dy);
    // ��ѯ����
    max += dps_maxAreaOfIsland(grid,dx+1,dy);
    // ��ѯ����
    max += dps_maxAreaOfIsland(grid,dx,dy+1);
    // ��ѯ����
    max += dps_maxAreaOfIsland(grid,dx,dy-1);
    // �����ܵĿ���
    return max;
}


// ��̬�滮-���Ӷ�ΪO(n^2)
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
// ģ����Ծ
int Solution::jump_2(vector<int>& nums) {
    int le=nums.size();
    int steps=0;
    int start = 0;
    int end = 1;
    // �ҵ�ÿ����Ծʹ����һ����Ծ�ﵽ����Զ�ľ���
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

// �ַ���ѹ��
/* �����ַ��ظ����ֵĴ�������дһ�ַ�����ʵ�ֻ������ַ���ѹ������
 * ���磬�ַ���aabcccccaaa���Ϊa2b1c5a3������ѹ��������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ���
 * ����Լ����ַ�����ֻ������СдӢ����ĸ��a��z��
 * */
// һ�α���,�������ظ�����������ظ������
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

// ȫ���� II
/* ����һ���ɰ����ظ����ֵ����У��������в��ظ���ȫ����
 * */
// ����mapȥ��,ͬʱ��֤���Բ���©�����
vector<vector<int>> Solution::permuteUnique(vector<int>& nums) {
    // ����map
    map<int,int> info;
    for(auto i:nums){
        ++info[i];
    }
    vector<vector<int>> res;
    vector<int> temp;
    dps_permuteUnique(info,temp,res,nums.size());
    return res;
}
// ȡmap���ֵ����ȫ����,��ͬһ������ÿ����ֻ��ȡһ��
void Solution::dps_permuteUnique(map<int,int>& my_map,const vector<int>& li,vector<vector<int>> &res,int size){
    int le=my_map.size();
    // �����㹻����з���
    if(li.size()==size){
        res.push_back(li);
    }
    // ȡ����ͬ��������ȫ����
    for(auto i:my_map){
        auto temp = li;
        if(my_map[i.first]){
            // ��������һ,�ƽ���һ�εݹ�
            --my_map[i.first];
            temp.push_back(i.first);
            dps_permuteUnique(my_map,temp,res,size);
            // ����һ��ݹ鷵��,�ָ�����
            ++my_map[i.first];
        }
    }
}

// ��תͼ��
/* ����һ�� n �� n �Ķ�ά�����ʾһ��ͼ��
 * ��ͼ��˳ʱ����ת 90 ��
 * */
// ��ÿ��λ�ý�����ת����,�����ƶ�Ϊ�������Ĳ���,ʱ�临�Ӷ�ΪO(n^2),�ռ临�Ӷ�ΪO(1)
void Solution::rotate(vector<vector<int>>& matrix) {
    // ����ά��n
    int n = matrix.size();
    // ����δ�ƶ�������,����Ϊn^2/4��ÿ������4���ƶ�,��һ����ת����
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

// ƴд����
/* ����һ�ݡ��ʻ�����ַ������飩 words ��һ�š���ĸ�����ַ����� chars
 * ����������� chars �еġ���ĸ�����ַ���ƴд�� words �е�ĳ�������ʡ����ַ���������ô���Ǿ���Ϊ���������������
 * ע�⣺ÿ��ƴдʱ��chars �е�ÿ����ĸ��ֻ����һ��
 * ���شʻ�� words �������յ����е��ʵ� ����֮��
 * */
// ���ù�ϣ����м���,ÿ������һ����ϣ��,���ʹ�ϣ��ÿ��Ӧ��С�ڸ�����ĸ��ϵĹ�ϣ��
int Solution::countCharacters(vector<string>& words, const string& chars) {
    // �������ڶ��յĹ�ϣ��
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
    // �Ե��ʽ��м���
    for(const auto& word:words){
        int le = word.size();

        for(auto c:word){
            ++info[c-'a'];
        }
        // �ȽϹ�ϣ���Ƿ�С��
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

// ��ĸ��λ�ʷ���
/* ����һ���ַ������飬����ĸ��λ�������һ��
 * ��ĸ��λ��ָ��ĸ��ͬ�������в�ͬ���ַ���
 * */
// ��ϣ������
vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
    // �Թ�ϣ��Ϊmap�±���д洢�ַ���
    map<vector<int>,vector<string>> info;
    for(const auto& word:strs){
        vector<int> temp(26,0);
        for(auto i:word){
            ++temp[i-'a'];
        }
        info[temp].push_back(word);
    }
    // ��ÿ���ַ����ƶ���������
    vector<vector<string>> res;
    res.reserve(info.size());
    for(const auto& m:info){
        res.push_back(m.second);
    }
    return res;
}

// N�ʺ�
/* n �ʺ������о�������ν� n ���ʺ������ n��n ��������,����ʹ�ʺ�˴�֮�䲻���໥����
 * ����һ������ n,�������в�ͬ�� n �ʺ�����Ľ������
 * ÿһ�ֽⷨ����һ����ȷ�� n �ʺ���������ӷ��÷���,�÷����� 'Q' �� '.' �ֱ�����˻ʺ�Ϳ�λ
 * */
// �ݹ���ݷ�-ʱ�临�Ӷ�O(n!),�ռ临�Ӷ�O(n),��Ҫ5*N�Ŀռ�ֱ𱨴���,�Խ�����Ϣ
vector<vector<string>> Solution::solveNQueens(int n) {
    // �洢���
    vector<vector<string>> res;
    // �洢�ɹ���д������
    vector<string> temp(n,string(n,'.'));
    // �ж��������Ƿ���ڻʺ�,��(x,y)ӳ��Ϊcol[y]
    vector<bool> col(n,true);
    // �ж���б�Խ������Ƿ��лʺ�,��(x,y)ӳ��Ϊx-y+n-1
    vector<bool> left_line(2*n-1,true);
    // �ж���б�Խ������Ƿ��лʺ�,��(x,y)ӳ��Ϊx+y
    vector<bool> right_line(2*n-1,true);
    // �ݹ���аڷ�����,���ݽ���ɾ��
    solveNQueens_dg(col,left_line,right_line,temp,0,res);
    return res;
}
// ���ڵݹ��������Ӳ����������res
void Solution::solveNQueens_dg(vector<bool>& col, vector<bool>& left, vector<bool>& right, vector<string>& temp, int deep, vector<vector<string>> &res){
    int n=col.size();
    // ��ȼ�Ϊ�Ѿ����õ���������,��˵���ȵ���Ҫ�ڷŵ���������ʱ���𰸼���
    if(deep==n){
        res.push_back(temp);
        return;
    }
    // ���ڽ�Ҫ�ڷŵ�����һ������ͬһ��,�������ֱ�����Ѱڷ���һ��֮��Ѱ��,��deep��
    for(int i=0;i<n;++i){
        // ����ڸ���������޻ʺ���˵����������
        if(col[i] && right[deep + i] && left[deep - i + n - 1]){
            // ��������
            col[i] = false;
            right[deep + i] = false;
            left[deep - i + n - 1] = false;
            temp[deep][i] = 'Q';
            // ���Ѿ��������ӵĻ����Ͻ����ٴ�����
            solveNQueens_dg(col, left, right, temp, deep + 1, res);
            // ���л���
            temp[deep][i] = '.';
            col[i] = true;
            right[deep + i] = true;
            left[deep - i + n - 1] = true;
        }
    }
}

// ��������
/* ����һ���������� nums
 * �ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ�
 * ����������
 * */
// ��̬�滮,̰���㷨-ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
int Solution::maxSubArray(vector<int>& nums) {
    int le = nums.size();
    int dp = nums[0];
    int before_num = nums[0];
    // ��ÿ������֮ǰ��������Ƚ�ֱ��,��֮ǰΪ�������һ��ֱ��ȡ��,�������֮ǰ������,�ٽ���ȡ���ֵ����
    for(int i=1;i<le;++i){
        before_num = before_num>0?before_num+nums[i]:nums[i];
        dp = dp>before_num?dp:before_num;
    }
    return dp;
}

// �����ص�
/* �������б� [x1, y1, x2, y2] ����ʽ��ʾ������ (x1, y1) Ϊ���½ǵ����꣬(x2, y2) �����Ͻǵ�����
 * ����ཻ�����Ϊ��������������ص�����Ҫ��ȷ���ǣ�ֻ�ڽǻ�߽Ӵ����������β������ص�
 * �����������Σ��ж������Ƿ��ص������ؽ��
 * */
// ���벻��������Ҫ����:
// �������Ӧ������һ���ұ�,�ұ�Ӧ��С����һ�����,�±�Ӧ������һ���ϱ�,�ϱ�ӦС����һ���±�
// ������Ǹ�����Ӧ�ò�������������
bool Solution::isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    return !(rec2[2]<=rec1[0]||rec2[0]>=rec1[2]||rec2[3]<=rec1[1]||rec2[1]>=rec1[3]);
}

// ��������
/* ����һ������ m x n ��Ԫ�صľ���(m ��,n ��)
 * �밴��˳ʱ������˳�򣬷��ؾ����е�����Ԫ��
 * */
// תȦģ��ȡֵ
vector<int> Solution::spiralOrder(vector<vector<int>>& matrix) {
    // �洢����
    vector<int> res;
    if(matrix.empty()){
        return res;
    }
    // ������λ����
    int row = matrix.size();
    int col = matrix[0].size();
    int r1 = 0, r2 = row - 1;
    int c1 = 0, c2 = col - 1;
    while (r1 <= r2 && c1 <= c2) {
        // ɨ���Ϸ�һ����
        for (int c = c1; c <= c2; c++){
            res.push_back(matrix[r1][c]);
        }
        // ɨ������һ����
        for (int r = r1 + 1; r <= r2; r++){
            res.push_back(matrix[r][c2]);
        }
        // ������ͬһ��ͬһ����ɨ���·�һ���к���һ����
        if (r1 < r2 && c1 < c2) {
            for (int c = c2 - 1; c > c1; c--) {
                res.push_back(matrix[r2][c]);
            }
            for (int r = r2; r > r1; r--) {
                res.push_back(matrix[r][c1]);
            }
        }
        // ��λ������������һ��
        r1++;
        r2--;
        c1++;
        c2--;
    }
    return res;
}

// ��Ծ��Ϸ
/* ����һ���Ǹ��������飬�����λ������ĵ�һ��λ��
 * �����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶�
 * �ж����Ƿ��ܹ��������һ��λ��
 * */
// ģ����Ծ,������ȥĩβ��˵�����Դﵽĩβ,��leftPoint��ԽrightPoint˵���Ѿ��޷�ǰ�����޷������յ�
bool Solution::canJump(vector<int>& nums) {
    int leftPoint = 0;
    int rightPoint = 0;
    int maxReach = 0;
    int le = nums.size();
    // ģ����Ծ
    while(leftPoint <= rightPoint){
        for(int i=leftPoint; i <= rightPoint; ++i){
            int temp = i+nums[i];
            maxReach = maxReach > temp ? maxReach : temp;
            // �����յ�
            if(maxReach >= le - 1){
                return true;
            }
        }
        // ����ƶ��ж�����,������[��һ��ĩβ,����������Զ����]
        leftPoint = rightPoint + 1;
        rightPoint = maxReach;
    }
    return false;
}
// ����Ĵ�
/* ����һ��������д��ĸ��Сд��ĸ���ַ������ҵ�ͨ����Щ��ĸ����ɵ���Ļ��Ĵ�
 * �ڹ�������У���ע�����ִ�Сд������ "Aa" ���ܵ���һ�������ַ���
 * ע��:
 * �����ַ����ĳ��Ȳ��ᳬ�� 1010
 * */
// ��ϣ��
int Solution::longestPalindrome(const string& s) {
    // Сдӳ��Ϊǰ26��,��дӳ��Ϊ��26��
    int counter[52] = {0};
    for(auto i:s){
        if(i>='a'&&i<='z'){
            ++counter[i-'a'];
        }else{
            ++counter[i-'A'+26];
        }

    }
    // �Ƿ��������
    int flag = 0;
    int theLen = 0;
    // ����ֻȡż������
    for(int temp : counter){
        if(temp%2){
            theLen += temp-1;
            flag = 1;
        }else{
            theLen += temp;
        }
    }
    // ����������,��������Ե�����һ��
    theLen += flag;
    return theLen;
}

// ��С��k����
/* ������������ arr ���ҳ�������С�� k ����
 * */
// Ͱ����
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

// �ϲ�����
/* ����һ������ļ��ϣ���ϲ������ص�������
 * */
// �Ƚ���������,��ɺϲ�������һ��������������,��ֻ��Ҫһ�α�������
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

// ��������
/* ����һ�����ص��� ������������ʼ�˵�����������б�
 * ���б��в���һ���µ����䣬����Ҫȷ���б��е�������Ȼ�����Ҳ��ص�(����б�Ҫ�Ļ������Ժϲ�����)
 * */
// һ�α���,�ڲ���λ�ý��в���,��Ӻϲ�
vector<vector<int>> Solution::insertRange(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int index = -1;
    int t = 0;
    // Ѱ�Ҳ���λ��
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
    // ����������,����Ҫ�ϲ���ϲ�
    if(index>=0&&newInterval[0]<=res[index][1]){
        if(res[index][1] < newInterval[1]){
            res[index][1] = newInterval[1];
        }
    }else{
        res.push_back(newInterval);
        ++index;
    }
    // �Ӳ���λ��֮���������
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

// ���һ�����ʵĳ���
/* ����һ����������Сд��ĸ�Ϳո� ' ' ���ַ��� s,���������һ�����ʵĳ���
 * ����ַ����������ҹ�����ʾ����ô���һ�����ʾ��������ֵĵ���
 * ������������һ�����ʣ��뷵�� 0
 * ˵����һ��������ָ������ĸ��ɡ��������κοո��ַ��� ������ַ���
 * */
// ��ȥβ���ո�,Ȼ��ɨ����һ���ո��λ��,���Ϊ����
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

// �������� II
/* ����һ�������� n������һ������ 1 �� n2 ����Ԫ�أ���Ԫ�ذ�˳ʱ��˳���������е������ξ���
 * */
// ģ����ת���ɾ���
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

// ��k������
/* �������� [1,2,3,��,n]��������Ԫ�ع��� n! ������
 * ���� n �� k�����ص� k ������
 * */
// ͨ���׳˽���ӳ��,k���Զ�Ӧλ����һλ�Ľ׳˿��Եõ�ƫ����,�Ӷ�ֱ�Ӵ�ʣ��������ѡ�����Ӧλ������
string Solution::getPermutation(int n, int k) {
    // res�洢���,��ʼ��Ϊn��'0'
    string res(n,'0');
    // ���ɽ׳�����ͱ�־����
    int *info = static_cast<int *>(malloc(sizeof(int)*n));
    info[0] = 1;
    for(int i=1;i<n;++i){info[i] = info[i-1]*i;}
    bool *counter = static_cast<bool *>(malloc(sizeof(bool)*n));
    for(int i=0;i<n;++i){counter[i] = true;}
    int index = 0;
    --k;
    // ѭ����������
    while(index<n){
        int temp = k/info[n-index-1];
        k -= temp*info[n-index-1];
        // ɨ��counter�Ӷ�ѡ��һ��δ��ʹ�õ�����,�Ƚ���ƫ�����ļ���
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

// ˮ������
/* �����������ֱ�Ϊx����y����ˮ���Լ����޶��ˮ
 * ���ж��ܷ�ͨ��ʹ��������ˮ�����Ӷ����Եõ�ǡ��z����ˮ��
 * ������ԣ������������ˮ���е�һ��������ʢ��ȡ�õ� z��ˮ
 * ������
 * װ������һ��ˮ��
 * �������һ��ˮ��
 * ��һ��ˮ��������һ��ˮ����ˮ��ֱ��װ�����ߵ���
 * */
// ģ���ˮ������,��Ŀ��ֵС��ӽ��ٵ�ˮ,��Ŀ��ֵ�����ȥ�ϴ��ˮ
bool Solution::canMeasureWater(int x, int y, int z) {
    // ����ż�����Ӳ��ܲ�������ˮ������������Ӧ����ʢ����Ŀ��ˮ��
    if((x%2==0&&y%2==0&&z%2)||x+y<z){
        return false;
    }
    int min = x<y?x:y;
    int max = x==min?y:x;
    int sum = 0;
    while(sum!=z){
        if(sum<z){
            // ��ˮ����,�����ˮ�����������ѡ�����ˮ��
            if(sum+min<=x+y){
                cout << sum << "L\t" <<"����:" << min << "L" << endl;
                sum += min;
            }else{
                cout << sum << "L\t" <<"����:" << max << "L" << endl;
                sum -= max;
            }
        }else if(sum > z){
            // ��ˮ����,����ˮ�����²�����ֵ��ѡ������ˮ��
            if(sum-max>=0){
                cout << sum << "L\t" <<"����:" << max << "L" << endl;
                sum -= max;
            }else{
                cout << sum << "L\t" <<"����:" << min << "L" << endl;
                sum += min;
            }
        }
        // �����ڼȲ��ܼ�ˮҲ���ܵ�ˮ�������������ֵ�����,���������⵽��˵���������
        if(sum<=0||sum>x+y){
            cout << "ˮ���쳣������"<< endl;
            return false;
        }
    }
    return true;
}

// ����Ԫ��
/* ����һ����СΪ n �����飬�ҵ����еĶ���Ԫ��
 * ����Ԫ����ָ�������г��ִ������� n/2��Ԫ��
 * ����Լ��������Ƿǿյģ����Ҹ������������Ǵ��ڶ���Ԫ��
 * */
// �����Ƕ���Ԫ��,��������������ѹ,��ȡһ����ѡ����Ԫ��,����ͬʱ���ж���Ԫ��-1,�����һ��ֻ�ж���Ԫ��������>0����������
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

// ��ת����
/* ����һ������,��ת����,������ÿ���ڵ������ƶ� k ��λ��,���� k �ǷǸ���
 * */
// �γɱպ�����,����ѡȡ�ϵ�
ListNode* Solution::rotateRight(ListNode* head, int k) {
    // �γɱջ�������
    int len = 1;
    auto p = head;
    while(p->next){
        p = p->next;
        ++len;
    }
    p->next = head;
    auto left = p;
    auto right = head;
    // �����ƶ�����
    int counter = len-k%len;
    while(counter>0){
        left = left->next;
        right = right->next;
        --counter;
    }
    // �ضϷ���
    left->next = nullptr;
    return right;
}
// ʹ����Ψһ����С����
/* ������������ A��ÿ�� move ��������ѡ������ A[i]����������� 1
 * ����ʹ A �е�ÿ��ֵ����Ψһ�����ٲ�������
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
// �ַ������������
/* �����ַ��� S �� T��ֻ���� S = T + ... + T��T ���������� 1 �λ��Σ�ʱ�����ǲ��϶� ��T �ܳ��� S��
 * ������ַ��� X��Ҫ������ X �ܳ��� str1 �� X �ܳ��� str2
 * */
// շת�����,���ַ��������ʽ
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

// ������м���
/* ����һ������ͷ��� head �ķǿյ���������������м���
 * ����������м��㣬�򷵻صڶ����м���
 * */
// ����ָ�뷨-��ָ��������,��ָ����һ���Ӷ�ʹ�õ���ָ�뵽ĩβʱ,��ָ��������һ��
ListNode* Solution::middleNode(ListNode* head) {
    auto left = head;
    auto right = head;
    // ����ָ��
    while(right&&right->next){
        left = left->next;
        right = right->next->next;
    }
    // ����ָ���޷�����ǰ��ʱ��ָ��պ�ָ����Ҫ��Ľڵ��λ��
    return left;
}

// ��ͬ·�� I
/* һ��������λ��һ�� m x n ��������Ͻ�,��ʼ������ͼ�б��Ϊ��Start��
 * ������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish����
 * ���ܹ��ж�������ͬ��·����
 * */
// ��̬�滮
int Solution::uniquePaths(int m, int n) {
    // �洢��һ�е���·����
    auto counter = static_cast<int *>(malloc(sizeof(int)*m));
    for(int i=0;i<m;++i){
        counter[i] = 1;
    }
    // �ظ��޸�����
    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            counter[j] = counter[j-1]+counter[j];
        }
    }
    int res = counter[m-1];
    free(counter);
    // ���һ��,���һ����Ϊ���
    return counter[m-1];
}

// ��ͬ·�� II
/* һ��������λ��һ�� m x n ��������Ͻ�,��ʼ������ͼ�б��Ϊ��Start��
 * ������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½�,����ͼ�б��Ϊ��Finish��
 * ���ڿ������������ϰ���,��ô�����Ͻǵ����½ǽ����ж�������ͬ��·����
 * */
// ��̬�滮�ڲ�ͬ·���Ļ�����,�����ϰ���ĵ���Ϊ0
int Solution::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    // ���������յ����ϰ����򲻴���·��,����0
    if(obstacleGrid[0][0]||obstacleGrid[n-1][m-1]){
        return 0;
    }
    auto counter = static_cast<int *>(malloc(sizeof(int)*m));
    // �жϵ�һ��ÿ�����·����,����ұ�·����ͨ,��ֱ��Ϊ0
    counter[0] = obstacleGrid[0][0]?0:1;
    for(int i=1;i<m;++i){
        counter[i] = counter[i-1]&&!obstacleGrid[0][i]?1:0;
    }
    // ÿһ�㿪ʼʱ,��һ���Ƿ����ϰ���
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

// ��С·����
/* ����һ�������Ǹ������� m x n ����,���ҳ�һ�������Ͻǵ����½ǵ�·��,ʹ��·���ϵ������ܺ�Ϊ��С
 * ˵����ÿ��ֻ�����»��������ƶ�һ��
 * */
// ��̬�滮-ʹ��һ������洢��һ��ȡ�õ����ֵ
int Solution::minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    auto dp = static_cast<int *>(malloc(sizeof(int) * m));
    // �жϵ�һ��ÿ������ܺ�,��Ϊǰһ����������
    dp[0] = grid[0][0];
    for(int i=1;i<m;++i){
        dp[i] = dp[i - 1] + grid[0][i];
    }
    // ÿһ�㿪ʼ���,����ÿ��ÿ��λ����dp[j] = dp[j] + min{dp[j-1],dp[j]}
    for(int i=1;i<n;++i){
        dp[0] = dp[0] + grid[i][0];
        for(int j=1;j<m;++j){
            if(dp[j - 1] < dp[j]){
                dp[j] += dp[j-1];
            }
            dp[j] += grid[i][j];
        }
    }
    // free������ڴ�
    int res = dp[m - 1];
    free(dp);
    return res;
}

// ��Ч����
/* ��֤�������ַ����Ƿ���Խ���Ϊʮ��������
 * */
// ����״̬���ⷨ
bool Solution::isNumber(const string& s) {
    // ״̬��ӳ���,��{BLANK,SIGN,NUM,DOT,E}ӳ��ΪҪ��ת��״̬
    int info[9][5]{
            {0 , 1, 2, 3,-1},   // 0״̬,δ���״̬
            {-1,-1, 2, 3,-1},   // 1״̬,��⵽����
            { 8,-1, 2, 4, 5},   // 2״̬,��⵽����
            {-1,-1, 4,-1,-1},   // 3״̬,��⵽��
            { 8,-1, 4,-1, 5},   // 4״̬,��⵽����
            {-1, 6, 7,-1,-1},   // 5״̬,��⵽e
            {-1,-1, 7,-1,-1},   // 6״̬,��⵽����
            { 8,-1, 7,-1,-1},   // 7״̬,��⵽����
            { 8,-1,-1,-1,-1}    // 8״̬,������
    };
    int state = 0;
    int le = s.size();
    for(int index=0;index<le;++index){
        int t = 0;
        // �ж�ȡ�õ��ַ�
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
    // ׷�ӿո��ж�ʹ�ÿ��Խ����ĵط���ת��ĩ״̬8
    state = info[state][0];
    return state==8;
}

// ��Ħʦ
/* һ�������İ�Ħʦ���յ�ԴԴ���ϵ�ԤԼ����ÿ��ԤԼ������ѡ��ӻ򲻽�
 * ��ÿ��ԤԼ����֮��Ҫ����Ϣʱ�䣬��������ܽ������ڵ�ԤԼ
 * ����һ��ԤԼ��������,�水Ħʦ�ҵ����ŵ�ԤԼ����(��ԤԼʱ���),�����ܵķ�����
 * */
// ��̬�滮,��ɨ�赽nums[i]��ֻ��Ҫ��nums[i]����ǰi-2�������е����ֵ����Ϊ�Ե�ǰ���ֽ�β�����ֵ
int Solution::massage(vector<int>& nums) {
    // ������ֿ�����
    if(nums.empty()){
        return 0;
    }
    int le = nums.size();
    // �����i-1������
    int before_right = 0;
    // �����i-2������
    int before_left = 0;
    // ����i-2֮ǰ�������ֵ
    int before_max=0;
    // ɨ�貢����������ֵ
    for(int i=0;i<le;++i){
        before_max = i > 1 && before_max < before_left ? before_left : before_max;
        before_left = i > 0 ? before_right : 0;
        before_right = nums[i] + before_max;
    }
    // ���һ�����������������ֵ����һ��,��������������˵��һ�������ٴ�ԤԼһ��
    return before_left>before_right?before_left:before_right;
}

// ��һ
/* ����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ
 * ���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢��������
 * ����Լ���������� 0 ֮�⣬��������������㿪ͷ
 * */
// ��ĩβ�ж��Ƿ����,ֻҪ����һ�β������ֱ�ӷ���ԭ����,�����������������ͷ����1
vector<int> Solution::plusOne(vector<int>& digits) {
    int le = static_cast<int>(digits.size())-1;
    // ����Ƿ�Ҫ+1,Ĭ��Ϊ�и�1Ҫ��
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
    // ȫΪ9����Ҫ������������
    if(overflow_flag){
        digits.insert(digits.begin(),1);
    }
    return digits;
}
// ��ά����ı����
/* �� N * N �������ϣ����Ƿ���һЩ 1 * 1 * 1  ��������
 * ÿ��ֵ v = grid[i][j] ��ʾ v ������������ڶ�Ӧ��Ԫ�� (i, j) ��
 * ���㷵����������ı����
 * */
// ����ܵķ�����,�ܵĽӴ�����,����������ȥ�Ӵ����������Ӷ��õ������
int Solution::surfaceArea(vector<vector<int>>& grid) {
    int n = grid.size();
    // �ܿ���
    int blockNum = 0;
    // �ܽӴ�����
    int touchNum = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            // �ж��Ϸ��Ӵ�������
            if(i>0){
                touchNum += grid[i][j] > grid[i - 1][j] ? grid[i - 1][j] : grid[i][j];
            }
            // �ж�����Ӵ�������
            if(j>0){
                touchNum += grid[i][j] > grid[i][j - 1] ? grid[i][j - 1] : grid[i][j];
            }
            // �ж����ڵ��ö����µĽӴ�������
            if(grid[i][j]>1){
                touchNum += grid[i][j]-1;
            }
            // �����ۼ�
            blockNum += grid[i][j];
        }
    }
    // �����
    return 6*blockNum-2*touchNum;
}

// ���������
/* ���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ��
 * ����Ϊ�ǿ��ַ�����ֻ�������� 1 ��
 * */
// ������λ�Ӻ�,����Ƿ����,���Ϊ����һλ������
string Solution::addBinary(const string& a, const string& b) {
    int l1 = a.size();
    int l2 = b.size();
    int lr = l1>l2?l1:l2;
    bool ofs = false;
    string res(lr,'0');
    // ��λ�Ӻ�
    for(int i=lr-1;i>=0;--i){
        // ��һ���������
        if(ofs){
            res[i] += 1;
            ofs = false;
        }
        // �Ӻ�������Ӧλ��
        if(l1>0&&a[l1-1]=='1'){
            res[i] += 1;
        }
        --l1;
        if(l2>0&&b[l2-1]=='1'){
            res[i] += 1;
        }
        --l2;
        // �������,��������һ�μ����������
        if(res[i]>'1'){
            ofs = true;
            res[i] -= 2;
        }
    }
    // ��������������ַ�����ͷ���'1'
    return ofs?'1'+res:res;
}

// ��ͼ����
/* ������������һ�ݴ�СΪ N x N �ġ���ͼ��(����)grid,�����ÿ��������(��Ԫ��)���� 0 �� 1 ��Ǻ���
 * ���� 0 ������1 ����½�أ���֪������½��������Զ�ĺ�������������һ�����뷵�ظú����������������½������ľ���
 * ��������˵�ľ����ǡ������پ��롻�� Manhattan Distance����(x0, y0) �� (x1, y1) ����������֮��ľ����� |x0 - x1| + |y0 - y1|
 * ������ǵĵ�ͼ��ֻ��½�ػ��ߺ����뷵�� -1
 * */
// ��̬�滮-�����Ͻ�ɨ����ٴ����½�ɨ��,ȡ���ֵΪ���
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


// ������62. ԲȦ�����ʣ�µ�����
/* 0,1,,n-1��n�������ų�һ��ԲȦ��������0��ʼ��ÿ�δ����ԲȦ��ɾ����m�����֡�������ԲȦ��ʣ�µ����һ������
 * ���磬0��1��2��3��4��5���������һ��ԲȦ
 * ������0��ʼÿ��ɾ����3�����֣���ɾ����ǰ4������������2��0��4��1��������ʣ�µ�������3
 * */
// Լɪ������,�ڶ��ɾ����,ֻʣ��һ���������±�Ϊ0,���ݷ����±�仯�ɷ��Ƴ�ʣ���������ԭ�����λ��
int Solution::lastRemaining(int n, int m) {
    // ��ʼ�±�
    int index = 0;
    // ����,��һ���±�=(����+��ǰ�±�)%��һ�γ���
    for (int i = 2; i != n + 1; ++i)
        index = (m + index) % i;
    return index;
}

// ��Ч���ŵ�Ƕ�����
/* ��Ч�����ַ��� ���壺����ÿ�������ţ������ҵ���֮��Ӧ�������ţ���֮��Ȼ������μ���ĩ����Ч�����ַ���������
 * Ƕ����� depth ���壺����Ч�����ַ���Ƕ�׵Ĳ���������μ���ĩ��Ƕ����ȡ�����
 * ����һ������Ч�����ַ����� seq�����㽫��ֳ��������ཻ����Ч�����ַ��� A �� B:
 * ���ཻ��ÿ�� seq[i] ֻ�ָܷ� A �� B �����е�һ�������ܼ����� A Ҳ���� B
 * A �� B �е�Ԫ����ԭ�ַ����п��Բ�����
 * A.length + B.length = seq.length
 * ����ѡ�� ���� ������ A �� B��ʹ�� max(depth(A), depth(B)) �Ŀ���ȡֵ��С
 * ���� depth(A) ��ʾ A ��Ƕ����ȣ�depth(B) ��ʾ B ��Ƕ�����
 * ���㷵��һ������Ϊ seq.length �Ĵ����� answer������������£�
 * answer[i] = 0��seq[i] �ָ� A
 * answer[i] = 1��seq[i] �ָ� B
 * �����ж������Ҫ��Ĵ𰸴���,��Ҳֻ�践����������һ��
 * */
// ���ÿ�������������,�����м�ֿ����߸�����ż�Էֿ�
vector<int> Solution::maxDepthAfterSplit(string seq) {
    // ȡ����ȱ�,����ȴ���һ�����Ϊ1,������Ϊ0
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
    // ȡ����ȱ������ż����Ϊ1,������Ϊ0
    int le = seq.size();
    vector<int> res(le, 0);
    int deep = 0;
    // ���γ�((��deep+1,���γ�))��deep-1,���γ�)(��()��deep����
    for(int i=1;i<le;++i){
        if(seq[i]==seq[i-1]){
            deep += seq[i] == '(' ? 1 : -1;
        }
        res[i] = deep%2;
    }
    return res;
}

// �ı����Ҷ���
/* ����һ�����������һ������ maxWidth�������Ű浥�ʣ�ʹ���Ϊÿ��ǡ���� maxWidth ���ַ������������˶�����ı�
 * ��Ӧ��ʹ�á�̰���㷨�������ø����ĵ��ʣ�Ҳ����˵�������ܶ����ÿ���з��õ���
 * ��Ҫʱ���ÿո� ' ' ��䣬ʹ��ÿ��ǡ���� maxWidth ���ַ�
 * Ҫ�󾡿��ܾ��ȷ��䵥�ʼ�Ŀո����������ĳһ�е��ʼ�Ŀո��ܾ��ȷ��䣬�������õĿո���Ҫ�����Ҳ�Ŀո���
 * �ı������һ��ӦΪ����룬�ҵ���֮�䲻�������Ŀո�
 * ˵��:
 * ������ָ�ɷǿո��ַ���ɵ��ַ�����
 * ÿ�����ʵĳ��ȴ��� 0��С�ڵ��� maxWidth
 * ���뵥������ words ���ٰ���һ������
*/
// ���Ȱ��յ��ʼ���һ���ո���з���,���޷����ɸ��൥��,��ʣ��ո���з���
vector<string> Solution::fullJustify(vector<string>& words, int maxWidth) {
    int wordsSum = words.size();
    vector<string> res;
    // ��������
    for(int i=0;i<wordsSum;++i){
        int st = i;         // ��¼�п�ʼλ��
        int line = words[i].size();         // ��¼�е��ʿո�ռ������
        // ѭ��ȡ��,ֱ���Ų���
        while(i+1 < wordsSum && line + words[i + 1].size() < maxWidth){
            line += (int)words[i+1].size()+1;
            ++i;
        }
        // ����ո��ܳ�
        int blanks=maxWidth-line+i-st;
        if(i == wordsSum - 1){          // �����������һ������,��ʹ�����������һ���ո����
            string temp(words[st]);
            for(int index= st + 1; index <= i; ++index){
                --blanks;
                temp += ' ';
                temp += words[index];
            }
            temp += string(blanks,' ');     // ����ո�
            res.push_back(temp);
        }else if(i==st){        // ֻ��һ������,�ո���ں���
            res.push_back(words[i]+string(blanks,' '));
        }else{          // ������ʽ���ƽ������ո�
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

// ������Ϸ
/* ���� �ٶȰٿ� ��������Ϸ�����Ϊ��������Ӣ����ѧ��Լ�����ζ١������� 1970 �귢����ϸ���Զ���
 * ����һ������ m �� n �����ӵ���壬ÿһ�����Ӷ����Կ�����һ��ϸ��
 * ÿ��ϸ��������һ����ʼ״̬��1 ��Ϊ��ϸ����live������ 0 ��Ϊ��ϸ����dead��
 * ÿ��ϸ������˸�����λ�ã�ˮƽ����ֱ���Խ��ߣ���ϸ������ѭ�����������涨�ɣ�
 * �����ϸ����Χ�˸�λ�õĻ�ϸ�����������������λ�û�ϸ��������
 * �����ϸ����Χ�˸�λ����������������ϸ�������λ�û�ϸ����Ȼ��
 * �����ϸ����Χ�˸�λ���г���������ϸ�������λ�û�ϸ��������
 * �����ϸ����Χ������������ϸ�������λ����ϸ�����
 * ���ݵ�ǰ״̬��дһ���������������������ϸ������һ����һ�θ��º�ģ�״̬
 * ��һ��״̬��ͨ������������ͬʱӦ���ڵ�ǰ״̬�µ�ÿ��ϸ�����γɵģ�����ϸ���ĳ�����������ͬʱ������
 * */
// ��״̬ӳ��ΪΨһֵ����ӳ��ֵ�ֳ�����,�ֱ�����1,0
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
            // ԭ������ϸ��ӳ��Ϊ����,ԭ��������ϸ��ӳ��Ϊ����,��Χ���ϸ����Ϊtemp
            board[row][col] = board[row][col]?9-temp:temp-9;
        }
    }
    // ӳ��Ϊ-6,,6,7��ϸ����Ϊ�˻�ϸ��,����������ϸ��
    for(int row=0;row<m;++row){
        for(int col=0;col<n;++col){
            int t = board[row][col];
            board[row][col] = t==-6||t==6||t==7?1:0;
        }
    }
}

// ��·��
/* �� Unix ������һ���ļ��ľ���·��������Ҫ���������߻��仰˵������ת��Ϊ�淶·��
 * �� Unix �����ļ�ϵͳ�У�һ���㣨.����ʾ��ǰĿ¼����
 * ���⣬������ ��..�� ��ʾ��Ŀ¼�л�����һ����ָ��Ŀ¼��
 * ���߶������Ǹ������·������ɲ���
 * ��ע�⣬���صĹ淶·������ʼ����б�� / ��ͷ����������Ŀ¼��֮�����ֻ��һ��б�� /
 * ���һ��Ŀ¼����������ڣ������� / ��β
 * ����,�淶·�������Ǳ�ʾ����·��������ַ���
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

// �༭����
/* ������������ word1 �� word2��������� word1 ת���� word2 ��ʹ�õ����ٲ�����
 * ����Զ�һ�����ʽ����������ֲ�����
 * ����һ���ַ�
 * ɾ��һ���ַ�
 * �滻һ���ַ�
 * */
// dp�����¼��Ӧ�ַ��ε����پ���
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

// ��������
/* ����һ�� m x n �ľ������һ��Ԫ��Ϊ 0
 * ���������к��е�����Ԫ�ض���Ϊ 0,��ʹ��ԭ���㷨
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

// ������ά����
/* ��дһ����Ч���㷨���ж� m x n �����У��Ƿ����һ��Ŀ��ֵ���þ�������������ԣ�
 * ÿ���е����������Ұ���������
 * ÿ�еĵ�һ����������ǰһ�е����һ������
 * */
// ������һ��һά����,���ж��ַ�,�ж�ֵ��Сʱ��������ӳ��(x,y)=(mid/col,mid%col)
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

// ��ɫ����
/* ����һ��������ɫ����ɫ����ɫ��һ�� n ��Ԫ�ص�����,ԭ�ض����ǽ�������
 * ʹ����ͬ��ɫ��Ԫ�����ڣ������պ�ɫ����ɫ����ɫ˳������
 * ������,����ʹ������ 0�� 1 �� 2 �ֱ��ʾ��ɫ����ɫ����ɫ
 * ע��:
 * ����ʹ�ô�����е�����������������
 * */
// �ּ�,��0�����ұ�,2�������,�м��Ϊ1;
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

// ��С�����Ӵ�
/* ����һ���ַ���S��һ���ַ���T,�����ַ���S�����ҳ�:���� T ������ĸ����С�Ӵ�
 * */
// ��ϣ���¼��ȡ��ĸ���Ѿ�ȡ����ĸ,���û�������,����ȡ��ʱ����,���ù�ϣ�����������ʵ�Ƿ�ƥ��Ӷ����͸��Ӷ�
string Solution::minWindow(const string& s, const string& t) {
    int needs[128]={0}; // ģ���ϣ��
    int hadGet[128]={0};// ģ���ϣ��
    int needSum = 0;    // ͳ�ƹ�ϣ��needs������
    int getSum = 0;     // ͳ���Ѿ�ȡ��������
    int res_st = 0;     // ������������ַ����Ŀ�ʼλ��
    int res_le = 0;     // ������������ַ����ĳ���
    int left = 0;       // ȡ��ָ��
    // ��t¼���ϣ��,������needs����
    for(auto i:t){++needs[i];}
    for(int need : needs){needSum += need;}
    // ��ָ��������ɨ��
    for(int right=0; right < s.size(); ++right){
        // �жϲ�����Ƿ�Ϊ�ؼ���ĸ,���ڹؼ���ĸ����ʱ���´���
        if(needs[s[right]] != 0){
            if(hadGet[s[right]] < needs[s[right]]){++getSum;}
            ++hadGet[s[right]];
            // ����ĸ����Ҫ��Χ�ڻ��߱�Ҫ��Ķ�����ȥ��
            while(left<=right&&(needs[s[left]] == 0 || (hadGet[s[left]] > needs[s[left]]))){
                if(hadGet[s[left]]!=0){--hadGet[s[left]];}
                ++left;
            }
            // �ж��Ƿ����Ҫ��,��ƥ��ɹ�,����и����ַ�����ʼλ�úͳ���
            if(getSum==needSum&&(res_le==0||res_le>right-left+1)){
                res_st = left;
                res_le = right-left+1;
            }
        }
    }
    return s.substr(res_st,res_le);
}

// ���
/* ������������ n �� k������ 1 ... n �����п��ܵ� k ���������
 * */
// �ݹ鵱���ȷ�������ʱ���в���
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

// �Ӽ�
/* ����һ�鲻���ظ�Ԫ�ص��������� nums
 * ����???�������п��ܵ��Ӽ����ݼ���
 * ˵�����⼯���ܰ����ظ����Ӽ�
 * */
// �ݹ�--��ÿһ�㶼���м�������ֱ�����������鳤��һ��
vector<vector<int>> Solution::subsets(vector<int>& nums) {
    vector<vector<int>> res{{}};
    vector<int> temp;
    co_subsets(0,nums,temp,res);
    return res;
}
void Solution::co_subsets(int start,vector<int>& nums,vector<int> &p,vector<vector<int>> &res){
    // ����������ʱ������ֹ
    if(p.size()==nums.size()){
        return;
    }
    // ���еݹ�--��ѹ����еݹ顢�ٵ���ѹ����
    for(int i=start;i<nums.size();++i){
        p.push_back(nums[i]);
        co_subsets(i+1,nums,p,res);
        res.push_back(p);
        p.pop_back();
    }
}

// ��������
/* ����һ����ά�����һ�����ʣ��ҳ��õ����Ƿ������������
 * ���ʱ��밴����ĸ˳��,ͨ�����ڵĵ�Ԫ���ڵ���ĸ����,���С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��
 * ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ��
 * */
// �ݹ�-����Ѱ�ҵ�һ����ĸ���ӵ�һ����ĸ����ʼ����������ڼ�����#ռλ��ֹ�ظ�����
bool Solution::exist(vector<vector<char>>& board, const string& word) {
    int row = board.size();
    int col = board[0].size();
    // Ѱ�ҵ�һ����ĸ��Ϊ�������������
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            if(board[i][j]==word[0]){
                // #ռλ��������������ؽ�������ɾ��ռλ
                board[i][j] = '#';
                bool res = co_exist(board,word,1,i,j);
                board[i][j] = word[0];
                // ��������ɴ��ڵ�����ֱ�ӷ���true
                if(res){
                    return true;
                }
            }
        }
    }
    // ��δ�������򷵻�false
    return false;
}
bool Solution::co_exist(vector<vector<char>>& board, const string& word,int index,int x,int y) {
    // ������ĩβ��ֱ�ӷ���true
    if(index==word.size()){
        return true;
    }
    int row = board.size();
    int col = board[0].size();
    // �ж��·�
    if(x+1<row&&board[x+1][y]!='#'&&board[x+1][y]==word[index]){
        board[x+1][y] = '#';
        bool temp = co_exist(board,word,index+1,x+1,y);
        board[x+1][y] = word[index];
        if(temp){
            return true;
        }
    }
    // �ж��Ϸ�
    if(x-1>=0&&board[x-1][y]!='#'&&board[x-1][y]==word[index]){
        board[x-1][y] = '#';
        bool temp = co_exist(board,word,index+1,x-1,y);
        board[x-1][y] = word[index];
        if(temp){
            return true;
        }
    }
    // �ж��ҷ�
    if(y+1<col&&board[x][y+1]!='#'&&board[x][y+1]==word[index]){
        board[x][y+1] = '#';
        bool temp = co_exist(board,word,index+1,x,y+1);
        board[x][y+1] = word[index];
        if(temp){
            return true;
        }
    }
    // �ж���
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

// ɾ�����������е��ظ��� II
/* ����һ���������飬����Ҫ��ԭ��ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ�����������Σ������Ƴ���������³���
 * ��Ҫʹ�ö��������ռ䣬�������ԭ���޸��������鲢��ʹ�� O(1) ����ռ�����������
 * */
// ����������
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

// �����˵��˶���Χ
/* ������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1]
 * һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩
 * Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18
 * �������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�
 * */
// �ж��Ϸ������Ƿ���·��,��·�����ɵ���
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
            // �߽��ж�,λ������Ҫ���޷��Ž��в���,����ǰ����ת��
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
// �����ݺ������λ��֮��
int Solution::co_movingCount(int x) {
    int res=0;
    for (; x; x /= 10){
        res += x % 10;
    }
    return res;
}

// ��ת�ַ�����ĵ���
/* ����һ���ַ����������ת�ַ����е�ÿ������
 * */
// �Ӻ���ǰɨ�赥����ʼ�����п������������
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

// ��������
/* �㽫��� K ��������������ʹ��һ���� 1 �� N  ���� N ��¥�Ľ���
 * ÿ�����Ĺ��ܶ���һ���ģ����һ�������ˣ���Ͳ����ٰ�������ȥ
 * ��֪������¥�� F ������ 0 <= F <= N �κδӸ��� F ��¥�����µļ��������飬�� F ¥�������͵�¥�����µļ�����������
 * ÿ���ƶ��������ȡһ��������������������ļ���������������һ¥�� X ���£����� 1 <= X <= N��
 * ���Ŀ����ȷ�е�֪�� F ��ֵ�Ƕ���
 * ���� F �ĳ�ʼֵ��Σ���ȷ�� F ��ֵ����С�ƶ������Ƕ���?
 * */
int Solution::superEggDrop(int K, int N) {
    // ��������Ϊkʱ,ÿ��Ĵ���
    int dp[N + 1];
    // ����ÿ��¥1����������Ҫ��Ͷ������
    for (int i = 0; i <= N; ++i) dp[i] = i;
    // ����ÿ��¥K����������Ҫ��Ͷ������
    for (int k = 2; k <= K; ++k) {
        int dp2[N + 1];
        int x = 1;
        dp2[0] = 0;
        // ��̬�滮,������1��ʱ�Ĵ��������N��ʱ�Ĵ���
        for (int n = 1; n <= N; ++n) {
            // ��ÿ�������Ѱ����Сֵ,�����ȼ������ʷ��ֵ�һ�����ӵ�ʱ���ĩβʱ��������
            while (x < n && max(dp[x-1], dp2[n-x]) >= max(dp[x], dp2[n-x-1])) {
                x++;
            }
            // ʹ����x��Ͷ���Ľ�����µ�n�����
            dp2[n] = 1 + max(dp[x-1], dp2[n-x]);
        }
        // ˢ��dp����
        for (int n = 1; n <= N; ++n) dp[n] = dp2[n];
    }
    return dp[N];
}

// ������ת�������� II
/* ���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת
 * ( ���磬���� [0,0,1,2,2,5,6] ���ܱ�Ϊ [2,5,6,0,0,1,2] )
 * ��дһ���������жϸ�����Ŀ��ֵ�Ƿ�����������С������ڷ��� true�����򷵻� false
 * */
// �����I�������ظ�ֵȥ��һ�߼���
bool Solution::searchII(vector<int>& nums, int target) {
    if(nums.empty()){
        return -1;
    }
    int le = nums.size(),res=-1,pot=le-1;
    int st=0;
    // ���ֲ��Ҳ��ҷ�ת��
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
    // ��β��ֵ���бȽ�,����תǰǰ��ε����ֵ,���������ֵ���ڷ�ת��֮ǰ���в���,�����ڷ�ת��֮����в���
    if(target>nums[le-1]||pot==le-1){
        // ����֮ǰд���Ķ����㷨
        res =divide_search(nums,0,pot,target);
    }else{
        res =divide_search(nums,pot+1,le-1,target);
    }
    return res!=-1;
}

// ɾ�����������е��ظ�Ԫ��
/* ����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ��
 * */
// �ͼ�¼����һ��ֵ��ȽϿ��Ƿ���ͬ,��ͬ������
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

// ɾ�����������е��ظ�Ԫ�� II
/* ����һ����������ɾ�����к����ظ����ֵĽڵ㣬ֻ����ԭʼ������ û���ظ����ֵ�����
 * */
// �ͼ�¼��ĩβ��Ƚ�,����ͬ��ɾ��ĩβ������
ListNode* Solution::deleteDuplicatesII(ListNode* head) {
    ListNode res(0);
    ListNode *index = &res;
    ListNode *p = head;
    index->next = p;
    p = p->next;
    while(p){
        // ��ֱͬ�Ӳ���
        if(index->next->val!=p->val){
            index = index->next;
            index->next = p;
            p = p->next;
        }else{
            // ������ֵͬ�Ľڵ�
            while(p&&p->val==index->next->val){
                p = p->next;
            }
            index->next = p;
            // �ж��Ƿ񵽴�ĩβ
            if(!index->next){
                return res.next;
            }
            p = p->next;
        }
    }
    return res.next;
}

// ������� II
/* �������� �ǿ� ���������������Ǹ��������������λλ������ʼλ��
 * ���ǵ�ÿ���ڵ�ֻ�洢һλ���֡�����������ӻ᷵��һ���µ�����
 * ����Լ���������� 0 ֮�⣬���������ֶ��������㿪ͷ
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

// 01����
/* ����һ���� 0 �� 1 ��ɵľ����ҳ�ÿ��Ԫ�ص������ 0 �ľ���
 * ��������Ԫ�ؼ�ľ���Ϊ 1
 * */
vector<vector<int>> Solution::updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    // ��ʼ����̬�滮�����飬���еľ���ֵ������Ϊһ���ܴ����
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX / 2));
    // ��� (i, j) ��Ԫ��Ϊ 0����ô����Ϊ 0
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }
    // ֻ�� ˮƽ�����ƶ� �� ��ֱ�����ƶ���ע�⶯̬�滮�ļ���˳��
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
    // ֻ�� ˮƽ�����ƶ� �� ��ֱ�����ƶ���ע�⶯̬�滮�ļ���˳��
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

// ��״ͼ�����ľ���
/* ���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1
 * ���ڸ���״ͼ�У��ܹ����ճ����ľ��ε�������
 * */
int Solution::largestRectangleArea(vector<int>& heights) {
    if(heights.empty()){
        return 0;
    }
    int le = heights.size();
    // ģ��ջ--�洢�±�
    int *dp = (int *)malloc(sizeof(int)*(le+1));
    int index = 0;
    dp[0] = -1;
    int max = 0;
    for(int i=0;i<le+1;++i){
        while(index!=0&&(i==le||heights[i]< heights[dp[index]])){
            // ����ջ��
            int temp = heights[dp[index--]];
            // �������
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

// ͳ���ظ�����
/* �� n �����ӵ��ַ��� s ����ַ��� S������ S = [s,n]�����磬["abc",3]=��abcabcabc��
 * ������ǿ��Դ� s2 ��ɾ��ĳЩ�ַ�ʹ���Ϊ s1������ַ��� s1 ���Դ��ַ��� s2 ���
 * ���磬���ݶ��壬"abc" ���Դ� ��abdbec�� ��ã������ܴ� ��acbbe�� ���
 * ���ڸ��������ǿ��ַ��� s1 �� s2��ÿ����� 100 ���ַ��������������� 0 �� n1 �� 106 �� 1 �� n2 �� 106
 * ���ڿ����ַ��� S1 �� S2������ S1=[s1,n1] ��S2=[s2,n2]
 * �����ҳ�һ����������ʹ[S2,M] �� S1 ��õ�������� M
 * */
// ̰��,���������黮��ʱ֮��ʹ�ó������л���
int Solution::getMaxRepetitions(string s1, int n1, string s2, int n2) {
    int l1 = s1.size();
    int l2 = s2.size();
    int i=0;
    int j=0;
    int sum = 0;
    // �����ж�����s2
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
    // �����ó�����
    return sum/n2;
}

// ��������
/* ����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е��������
 * �������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γ�
 * ���⣬����Լ��������������߾���ˮ��Χ
 * */
// �������BFS
int Solution::numIslands(vector<vector<char>>& grid) {
    if(grid.empty()||grid[0].empty()){
        return 0;
    }
    int row = grid.size();
    int col = grid[0].size();
    int res = 0;
    // ��ÿ�����й������,��������Ϊһ������,�ÿ�
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

// ͳ�ơ����������项
/* ����һ���������� nums ��һ������ k
 * ���ĳ�� ���� ��������ǡ���� k ���������֣����Ǿ���Ϊ����������ǡ����������项
 * �뷵����������С����������项����Ŀ
 * */
int Solution::numberOfSubArrays(vector<int>& nums, int k) {
    int le = nums.size();
    int left=0;
    int right=0;
    int count=0;
    int res = 0;
    // ������ż��,ȡ��Ϊ1Ϊ��,ȡ��Ϊ0Ϊż
    for(auto &i:nums){
        i = static_cast<unsigned int>(i)&0x1u;
    }
    // ����,ͨ���������ڽ���ȡ����
    while(left<le&&right<le){
        if(nums[right]){
            ++count;
        }
        ++right;
        // �ж�ǰ���ж���0�Լ����ж���0,�˻���Ϊ������k��1���������������
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

// ������������ͼ
/* ����һ�ö�����,�����Լ�վ�������Ҳ�,���մӶ������ײ���˳��,���ش��Ҳ����ܿ����Ľڵ�ֵ
 * */
// ������->��->����б�����,ͬʱ��¼��ǰ�������,����ˢ���������ʱ���в�����
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

// ������
/* ����һ�������� 0 �� 1 �Ķ�ά�����ƾ����ҳ�ֻ���� 1 �������Σ������������
 * */
// ջ����(������״ͼ)-ʱ��O(MN),�ռ�O(M)
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

// ���������
/* ��һ���� 0 �� 1 ��ɵĶ�ά�����ڣ��ҵ�ֻ���� 1 ����������Σ������������
 * */
// ��̬�滮,�Լ�Ϊ1,�ҵ���,����,�Ͼ�Ϊn��n��ʱ��,��������Ϊ(n+1)��(n+1)
int Solution::maximalSquare(vector<vector<char>>& matrix){
    if(matrix.empty()||matrix[0].empty()){
        return 0;
    }
    int row = matrix.size();
    int col = matrix[0].size();
    // ѹ������,һά�����ά
    int *dp = new int[col+1];
    for(int index=0;index<=col;++index){
        dp[index] = 0;
    }
    int maxN = 0;
    // �������
    for(int i=1;i<=row;++i){
        int temp = 0;
        for(int j=1;j<=col;++j){
            int sign = dp[j];
            if(matrix[i-1][j-1]=='1'){
                dp[j] = min(min(dp[j-1],dp[j]),temp)+1;     // ����������
                if(maxN<dp[j]){
                    maxN = dp[j];
                }
            }else{
                dp[j] = 0;
            }
            temp = sign;
        }
    }
    // ɾ�����������
    delete [] dp;
    return maxN*maxN;
}

// �ָ�����
/* ����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ
 * ��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ��
 * */
// �����ƽڵ���Ϊ��������,��x��Ϊ�ֽ�,��������
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

// ���������ֳ��ֵĴ���
/*һ���������� nums �����������֮�⣬�������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε�����
 * Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)
 * */
// ��������������,0^1=1,0^0=1^1=0,����������ͬ������Ϊ0,�����Ϊ��ͬ���ֵ����
vector<int> Solution::singleNumbers(vector<int>& nums) {
    unsigned int ret = 0;
    // �õ�������ͬ���ֵ����,�����Ϊ0
    for (int n : nums)
        ret ^= static_cast<unsigned int>(n);
    unsigned int div = 1;
    // Ѱ��һ��Ϊ1��λ,��Ϊ�����������ֵ�����,�����ַ�Ϊ������
    while ((div & ret) == 0)
        div <<= 1u;
    unsigned int a = 0, b = 0;
    // �ֱ��ÿ��������,ÿ�����һ����ͬ������,�������Ϊ��ͬ����������
    for (int n : nums)
        if (div & static_cast<unsigned int>(n))
            a ^= static_cast<unsigned int>(n);
        else
            b ^= static_cast<unsigned int>(n);
    return vector<int>{static_cast<int>(a), static_cast<int>(b)};
}

// �����ַ���
/* ����һ���ַ��� s1�����ǿ��԰����ݹ�طָ�������ǿ����ַ������Ӷ������ʾΪ������
 * ����������ַ����Ĺ����У����ǿ�����ѡ�κ�һ����Ҷ�ڵ㣬Ȼ�󽻻����������ӽڵ�
 * ͬ���أ�������Ǽ��������ڵ���ӽڵ㣬���������һ���µ������ַ���
 * ��������������ȵ��ַ��� s1 �� s2���ж� s2 �Ƿ��� s1 �������ַ���
 * */
// ��Ϊ�����ַ���,�����Ӵ�ҲΪ�����ַ���
bool Solution::isScramble(const string& s1, const string& s2) {
    if (s1.size() != s2.size())
        return false;
    return isScrambleRecursion(s1, s2);
}
bool Solution::isScrambleRecursion(const string& s1, const string& s2)
{
    if (s1 == s2)
        return true;
    //��ֹ��ʱ����s1�������ַ���s2�в������ڣ�˵��s1������ô�ָ��s2�޷�ƥ�䣬ֱ�ӷ���false������Ż�Ч��
    string t1 = s1, t2 = s2;
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    if (t1 != t2)
        return false;
    //i��1��s1.size-1�����ܴ��±�0��ʼ�����ٷָ�1���ַ������������޷�����ѭ��
    for (int i = 1; i < s1.size(); i++)
    {
        //��s1�ָ��[0,i)[i,s1.size)��Ӧs2ƥ�������[0,i)[i,s1.size)Ҳ������[s2.size-i,s2.size)[0,s2.size()-i)
        bool flag1 = isScrambleRecursion(s1.substr(0, i), s2.substr(0, i)) && isScrambleRecursion(s1.substr(i,s1.size()-i), s2.substr(i,s2.size()-i));
        bool flag2 = isScrambleRecursion(s1.substr(0, i), s2.substr(s2.size() - i, i)) && isScrambleRecursion(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i));
        if (flag1 || flag2)
            return true;
    }
    return false;
}

// ������
/* ��дһ���㷨���ж�һ���� n �ǲ��ǿ�����
 *��������������Ϊ������һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ����
 * Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1
 * ��� ���Ա�Ϊ  1����ô��������ǿ�����
 * ��� n �ǿ������ͷ��� True �����ǣ��򷵻� False
 * */
// ����ָ�뷨,������Ϊ1�������ѭ��,��ָ�뽫��׷�Ͽ�ָ��,isHappyNext����������һ����
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


// �ϲ�������������
/* �������������������� nums1 �� nums2
 * ���㽫 nums2 �ϲ��� nums1 ��
 * ʹ nums1 ��Ϊһ����������
 * */
// �ӵ�m+nλ�ý��в���,�Ƚϲ���,�����nums2��Ϊ����ʣ������ֱ�Ӳ���
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

// ���ױ���
/* ���ױ�����һ������������ϵͳ���ڸ�ϵͳ�У�������������ֵ����һ��λ���Ĳ���
 * ����һ�����������λ���ķǸ����� n����ӡ����ױ�������
 * ��ʹ�ж����ͬ�𰸣���Ҳֻ��Ҫ��������һ��
 * ���ױ������б����� 0 ��ͷ
 * */
// ����ת��,��תn-1����µĽ��,��1<<=n-1���в�����,ͬʱ׷����
vector<int> Solution::grayCode(int n) {
    // 0��1ʱ���������
    if(n==0){
        return vector<int>{0};
    }
    if(n==1){
        return vector<int>{0,1};
    }
    // ͨ��x������ȡ��,��������nλ�ϴ���1
    unsigned int x = 1;
    x <<= static_cast<unsigned int>(n-1);
    // ����n-1λ�ĸ��ױ���
    auto res = grayCode(n - 1);
    int l = res.size();
    // ����n-1�ĸ��ױ��벢��xȡ��,����������n-1���ױ������,��ʱ���Ϊ
    for(int i=l-1;i>=0;--i){
        res.push_back(x | static_cast<unsigned int>(res[i]));
    }
    // ���ظ��ױ���
    return res;
}
// ���ױ���ѭ���汾�ⷨ,����ڵݹ��,����������Ŀ���
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

// �Ӽ�II
/* ����һ�����ܰ����ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ���
 * ˵�����⼯���ܰ����ظ����Ӽ�
 * */
// ��������������,�����õݹ�;�ݹ���в���,��ѹ����
vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<int> temp;
    vector<vector<int>> res{vector<int>{}};
    // ��ʼ���ݹ�,��Ϊ��,��ѡΪ��,��ʼ��Ϊ0
    recursiveSubsetsWithDup(nums,res,temp,0);
    return res;
}
void Solution::recursiveSubsetsWithDup(vector<int>& nums,vector<vector<int>> &res,vector<int> &temp,int deep) {
    int ln = nums.size();
    // ���ȷ���Ҫ����ֹͣ�ݹ�
    if(ln==temp.size()){
        return;
    }
    // ��ͬһ�������ظ�����ʱ����,�ݹ�ʱ,��һ�����ѡ������һ������ѡ��
    for(int i=deep;i<ln;++i){
        if(i==deep||nums[i]!=nums[i-1]){
            temp.push_back(nums[i]);
            res.push_back(temp);
            recursiveSubsetsWithDup(nums,res,temp,i+1);
            temp.pop_back();
        }
    }
}


// ���뷽��
/* һ��������ĸ A-Z ����Ϣͨ�����·�ʽ�����˱���
 * "A"-1..."z"-26
 * ����һ��ֻ�������ֵķǿ��ַ������������뷽��������
 * */
// ����쳲�����,��¥��
int Solution::numDecoding(string s) {
    int l = s.size();
    if(s[0]=='0'){
        return 0;
    }
    int left = 1;   // ĩβΪ����һ��ĸ���
    int right = 1;  // ĩβΪ����һ��ĸ���
    for(int i=1;i<l;++i){
        int temp = 0;
        // ĩβ�������������λ�������,1X��2[0-6]
        if(s[i-1]=='1'||s[i-1]=='2'&&s[i]<'7'){
            temp += left;
        }
        // �Լ����Ե�����һ�������,X!=0
        if(s[i]!='0'){
            temp += right;
        }
        left = right;
        right = temp;
    }
    return right;
}

// ��ת���� II
/* ��ת��λ�� m �� n ��������ʹ��һ��ɨ����ɷ�ת
 * ˵��: 1 �� m �� n �� ������
 * */
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    ListNode nodeFirst(0);  //ʹ���ƽڵ����headΪnullptr
    nodeFirst.next = head;
    ListNode *p = nodeFirst.next;   // ����Ԫ��
    ListNode *q = &nodeFirst;   // ��¼��ת��ʼ��
    ListNode *tail = q; // ��¼ĩβ
    int c = 1;
    while(p){
        if(c>=m&&c<=n){
            // ����,�ȵ���tail��q��λ��,֮����q֮����в���
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
            // ����,ֱ�ӽ���tail����
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

// ��ԭIP��ַ
/* ����һ��ֻ�������ֵ��ַ�������ԭ�����������п��ܵ� IP ��ַ��ʽ
 * */
// �ֶν�ȡ,��ȡ4������,3����,����󳤶�Ϊs.size()+3==temp.size(),˵�����λ����ȷ,������,������ȥ
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

// ���������������
/* ����һ�������������������������
 * */
// ջ����,����ѹ����ڵ�,ֱ������ѹ��,�󵯳�����¼�����
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

// ��ͬ�Ķ��������� II
/* ����һ������ n������������ 1 ... n Ϊ�ڵ�����ɵĶ���������
 * */
// ȡһ�ڵ㽫���ַ�Ϊ������,���еݹ����
vector<TreeNode*> Solution::generateTrees(int n) {
    if (n == 0) {
        return vector<TreeNode*>{};
    }
    return generate_trees(1, n);
}
vector<TreeNode*> Solution::generate_trees(int start, int end) {
    // �洢[start,end]�Ľ�
    vector<TreeNode*> all_trees;
    // ��start>endʱ�޷��ݹ����,�ʲ���nullptr����
    if (start > end) {
        all_trees.push_back(nullptr);
        return all_trees;
    }
    // ȡ�ָ���
    for (int i = start; i <= end; i++) {
        auto left_trees = generate_trees(start,i-1);
        auto right_trees = generate_trees(i+1,end);
        // ���������ָ�������,����m��n��
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

// ��ͬ�Ķ���������
/* ����һ������ n������ 1 ... n Ϊ�ڵ���ɵĶ����������ж����֣�
 * */
// �����㿨������,�ɲ�ȡ��̬�滮�͹�ʽ
int Solution::numTrees(int n) {
    vector<int> G(n+1,0);
    G[0] = 1;
    G[1] = 1;
    // �ѿ�����,ȡ�ָ���,�󲿷�Ϊj���Ҳ���Ϊi-j��
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            G[i] += G[j - 1] * G[i - j];
        }
    }
    return G[n];
}

// �����ַ���
/* ���������ַ��� s1, s2, s3, ��֤ s3 �Ƿ����� s1 �� s2 ������ɵ�
 * */
// ��̬�滮,��ά����ѹ��һά
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

// ��֤����������
/* ����һ�����������ж����Ƿ���һ����Ч�Ķ���������
 * ����һ��������������������������
 * �ڵ��������ֻ����С�ڵ�ǰ�ڵ����
 * �ڵ��������ֻ�������ڵ�ǰ�ڵ����
 * �������������������������Ҳ�Ƕ���������
 * */
// (����)����������Ϊ����,����>��>��
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

// ���Ʊ��
/* ��һ�������к��ܻ�ӭ�Ĺ��ȣ�����ǰһ��ƻ���һЩ������
 * �ڽ�������һ�����Ҫ���е����ӽ���һ����Ϊ days ���������
 * ÿһ����һ���� 1 �� 365 ������
 * ��Ʊ�����ֲ�ͬ�����۷�ʽ��
 * һ��Ϊ��һ���ͨ��֤�ۼ�Ϊ costs[0] ��Ԫ
 * һ��Ϊ�������ͨ��֤�ۼ�Ϊ costs[1] ��Ԫ
 * һ��Ϊ����ʮ���ͨ��֤�ۼ�Ϊ costs[2] ��Ԫ
 * ͨ��֤�������������Ƶ�����
 * ��������Ҫ����ڸ������б� days ���г���ÿһ�����������Ҫ���������
 * */
// ����ݹ�
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


// ��ͬ����
/* ������������������дһ�����������������Ƿ���ͬ
 * ����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ��
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

// �Գƶ�����
/* ����һ����������������Ƿ��Ǿ���ԳƵ�
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

// �������Ĳ������
/* ����һ�������������㷵���䰴��������õ��Ľڵ�ֵ
 * �����أ������ҷ������нڵ�
 * */
// ���е�����
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

// ֻ����һ�ε�����
/* ����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ��
 * ˵����
 * ����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����
 * */
int Solution::singleNumber(vector<int>& nums) {
    unsigned int sign=0;
    for(auto i:nums){
        sign ^= static_cast<unsigned int>(i);
    }
    return static_cast<int>(sign);
}

// �������ľ���β�α���
/* ����һ����������������ڵ�ֵ�ľ���β�α���
 * ���ȴ������ң��ٴ������������һ��������Դ����ƣ������֮�佻�����
 */
// ����������ɲ�����,������תż������ת
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

// ��ΪK��������
/* ����һ�����������һ������ k������Ҫ�ҵ��������к�Ϊ k ��������������ĸ���
 * */
// ���ݵ��ƹ�ʽpre[i] = pre[i-1] + nums[i]��dp[i][j] = dp[0][j] - dp[0][i]�����Ż�
int Solution::subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp; // ��¼�ͳ��ֵĴ���
    mp[0] = 1;  // ��Ϊ0�ض�����1��
    int count = 0, pre = 0; // �������ѱ������������ܺ�
    for (auto& x:nums) {    // ����,����pre
        pre += x;
        if (mp.find(pre - k) != mp.end()){
            count += mp[pre - k];   //�鿴�Ƿ���ں�Ϊpre-k�����,��������˵�����Խ��нض�,�����������
        }
        mp[pre]++;  // ���¶�Ӧ�ͳ��ִ���
    }
    return count;
}

// ��ǰ��������������й��������
/* ����һ������ǰ�����������������������
 * ע��:����Լ�������û���ظ���Ԫ��
 * */
// ����ǰ�����������ʵݹ齨��,ǰ���һ��Ϊ���ڵ�,������ǰ��ĸ��ڵ�Ϊ�����Ϊ��������
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

// �����������������й��������
/* ����һ������������������������������
 * ע��:����Լ�������û���ظ���Ԫ��
 * */
// ����������������ʵݹ齨��,�������һ��Ϊ���ڵ�,������ǰ��ĸ��ڵ�Ϊ�����Ϊ��������
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

// �ܳ���ʱ��ɱ� 60 �����ĸ���
/* �ڸ����б��У��� i �׸����ĳ���ʱ��Ϊ time[i] ��
 * �������ܳ���ʱ�䣨����Ϊ��λ���ɱ� 60 �����ĸ����Ե�����
 * ��ʽ�ϣ�����ϣ������������ i �� j ����  i < j ���� (time[i] + time[j]) % 60 == 0
 * */
// ���������������Ĳ���������,�ʶ�ÿ��ȡ�ಢ��¼����,������O(1)��ʱ�临�Ӷ���ȡ����һ��ĸ���
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


// �˻����������
/* ����һ���������� nums �������ҳ������г˻��������������飨�������������ٰ���һ�����֣��������ظ�����������Ӧ�ĳ˻�
 * */
// ������������maxF,minF,һ���洢���ֵ,һ���洢��Сֵ,��nums[i]Ϊ����ʱ��Сֵ������ܴ������ֵ
// maxF[i]�洢maxF[i-1]*nums[i],minF[i]*nums[i],nums[i]���ֵ
// minF[i]�洢maxF[i-1]*nums[i],minF[i]*nums[i],nums[i]��Сֵ
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

// ��֤�����ַ��� ��
/* ����һ���ǿ��ַ��� s�����ɾ��һ���ַ�
 * �ж��Ƿ��ܳ�Ϊ�����ַ���
 * */
// ˫����������,�����ֲ�ƥ����ɾ����������һ����ɾ����Ϊ���Ĵ�
// validPalindrome������,checkPalindrome���Ĵ��жϺ���
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

// λ1�ĸ���
/* ��дһ������,������һ���޷�������,����������Ʊ��ʽ������λ��Ϊ ��1�� �ĸ���,Ҳ����Ϊ��������
 * */
int Solution::hammingWeight(uint32_t n) {
    int weight = 0;
    while(n){
        ++weight;
        n &= n-1u;
    }
    return weight;
}

// ����������С���
/* ����һ�����������ҳ�����С���
 * ��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�����
 * ˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ�
 * */
// ��nullptr�ֲ�,��ѹ��nullptr,��������ĵ�һ�����ӽڵ����ȼ�Ϊ���
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

// ��֤���Ĵ�
/* ����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд
 * ˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ�
 * */
// �ⷨ1������ĸ���ֵ���������,��дתСд��Ȼ����л����ж�;�ⷨ2,����ĸ����ת��Ϊ�ո�,�жϻ���ʱ�Զ������ո�
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

// ÿ��Ԫ������ż���ε�����ַ���
/* ����һ���ַ��� s
 * ���㷵��������������������ַ����ĳ���
 * ÿ��Ԫ����ĸ���� 'a'��'e'��'i'��'o'��'u' �������ַ����ж�ǡ�ó�����ż����
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

// ·���ܺ�
/* ����һ����������һ��Ŀ��ͣ��жϸ������Ƿ���ڸ��ڵ㵽Ҷ�ӽڵ��·��������·�������нڵ�ֵ��ӵ���Ŀ���
 * ˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ�
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

// ·���ܺ� II
/* ����һ����������һ��Ŀ��ͣ��ҵ����дӸ��ڵ㵽Ҷ�ӽڵ�·���ܺ͵��ڸ���Ŀ��͵�·��
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

// �ַ�������
/* ����һ������������ַ������������������ַ���
 * �������Ϊ: k[encoded_string]����ʾ���з������ڲ��� encoded_string �����ظ� k �Ρ�ע�� k ��֤Ϊ������
 * �������Ϊ�����ַ���������Ч�ģ������ַ�����û�ж���Ŀո�������ķ��������Ƿ��ϸ�ʽҪ���
 * ���⣬�������Ϊԭʼ���ݲ��������֣����е�����ֻ��ʾ�ظ��Ĵ��� k �����粻������� 3a �� 2[4] ������
 * */
// �����ڵ�ʽ��ֵ����Ϊ[],����Ϊa,b,��ʽΪa[b]=bbb������b<��a��>
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

// ��ҽ��� I
/* ����һ��רҵ��С͵���ƻ�͵���ؽֵķ���
 * ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ
 * ����������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�����
 * ����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽��
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

// ��ҽ��� II
/* ����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݣ�ÿ�䷿�ڶ�����һ�����ֽ�
 * ����ط����еķ��ݶ�Χ��һȦ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵ�
 * ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�����
 * ����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽��
 * */
// ����ת�����������ô�ҽ��� I�ĵ����㷨
int Solution::rob2(vector<int>& nums) {
    int st = 0;
    int en = nums.size();
    int left = rob1(nums,st,en-1);
    int right = rob1(nums,st+1,en);
    return left>right?left:right;
}

// ��ҽ��� III
/* ���ϴδ����һ���ֵ�֮���һȦ���ݺ�С͵�ַ�����һ���µĿ����Եĵ���
 * �������ֻ��һ����ڣ����ǳ�֮Ϊ�������� ���ˡ�����֮�⣬ÿ����������ֻ��һ��������������֮����
 * һ�����֮�󣬴�����С͵��ʶ��������ط������з��ݵ�����������һ�ö�������
 * �������ֱ�������ķ�����ͬһ�����ϱ���٣����ݽ��Զ�����
 * �����ڲ���������������£�С͵һ���ܹ���ȡ����߽��
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

// ��������
/* ���ж�һ�������Ƿ�Ϊ��������
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

// ӵ������ǹ��ĺ���
/* ����һ������ candies ��һ������ extraCandies ������ candies[i] ����� i ������ӵ�е��ǹ���Ŀ
 * ��ÿһ�����ӣ�����Ƿ����һ�ַ������������ extraCandies ���ǹ������������֮�󣬴˺����� ��� ���ǹ���ע�⣬�����ж������ͬʱӵ�� ��� ���ǹ���Ŀ
 * */
// 6.1��ͯ�ڿ���
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

// ��������С·����
/* ����һ�������Σ��ҳ��Զ����µ���С·���͡�ÿһ��ֻ���ƶ�����һ�������ڵĽ����
 * ���ڵĽ�� ������ָ���� �±� �� ��һ�����±� ��ͬ���ߵ��� ��һ�����±� + 1 ���������
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

// ��������������ĳ˻�
/* ����һ������Ϊ n ���������� nums������ n > 1������������� output
 * ���� output[i] ���� nums �г� nums[i] ֮�������Ԫ�صĳ˻�
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

// ���������
/* ����һ��δ������������飬�ҳ���������еĳ���
 * Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(n)*/
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

// ���ܵĶ��ַ�
/* ����һ�� N �ˣ����Ϊ 1, 2, ..., N���� �������ÿ���˷ֽ������С������
 * ÿ���˶����ܲ�ϲ�������ˣ���ô���ǲ�Ӧ������ͬһ��
 * ��ʽ�ϣ���� dislikes[i] = [a, b]����ʾ���������Ϊ a �� b ���˹���ͬһ��
 * �����������ַ�����ÿ���˷ֽ�����ʱ������ true�����򷵻� false
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

// ÿ���¶�
/* �����ÿ�� ���� �б���������һ���б�
 * ��Ӧλ�õ����Ϊ��Ҫ��۲⵽���ߵ����£�������Ҫ�ȴ�������
 * �����������֮�󶼲������ߣ����ڸ�λ���� 0 ������
 *���磬����һ���б� temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
 * ������Ӧ���� [1, 1, 4, 2, 1, 1, 0, 0]
 * ��ʾ������ �б��ȵķ�Χ�� [1, 30000]
 * ÿ�����µ�ֵ�ľ�Ϊ���϶ȣ������� [30, 100] ��Χ�ڵ�����
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

// ���ʲ��
/* ����һ���ǿ��ַ��� s ��һ�������ǿյ����б���ֵ� wordDict
 * �ж� s �Ƿ���Ա��ո���Ϊһ���������ֵ��г��ֵĵ���
 * ˵����
 * ���ʱ�����ظ�ʹ���ֵ��еĵ���
 * ����Լ����ֵ���û���ظ��ĵ���
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

// ������С��������
/* ����һ������ n ���������������һ�������� s
 * �ҳ���������������� �� s �ĳ�����С������������
 * �������䳤�ȡ���������ڷ������������������飬���� 0
 * */
int Solution::minSubArrayLen(int s, vector<int>& nums) {
    int st = -1;    // ��
    int en = -1;    // �ұ�
    int sum = 0;    // �ܺ�
    int l = 0;      // ��С����
    bool flag = true;   // �ж��Ƿ���ڣ��������Ƚ���̳�����Ϊ���鳤��
    for(auto i:nums){   // �Ҳ���м�������
        en++;
        sum += i;
        while(en>=st&&sum>=s){  // ���жϳ����Ƿ���£������ȥ������ѭ���ж�
            if(flag){
                l = nums.size();
                flag = false;
            }
            l = en-st<=l?en-st:l;
            st++;
            sum -= nums[st];
        }
    }
    return l;   // ������С����
}

// ��ˮ��
/* ������ʹ��һ��ľ�彨����ˮ��
 * ���������͵�ľ�壬���г��Ƚ϶̵�ľ�峤��Ϊshorter�����Ƚϳ���ľ�峤��Ϊlonger
 * ���������ʹ��k��ľ�塣��дһ��������������ˮ�����п��ܵĳ���
 * ���صĳ�����Ҫ��С��������
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

// �����Ҳ�С�ڵ�ǰԪ�صĸ���
/* ����һ���������� nums����Ҫ�󷵻�һ�������� counts
 * ���� counts �и�����:counts[i]��ֵ��nums[i]�Ҳ�С��nums[i]��Ԫ�ص�����
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

// ���³���Ϸ
/* һЩ��ħץס�˹�����P�������������˵��³ǵ����½�
 * ���³����� M x N ��������ɵĶ�ά����
 * ����Ӣ�µ���ʿ��K����������������Ͻǵķ���������봩�����³ǲ�ͨ���Կ���ħ�����ȹ���
 * ��ʿ�ĳ�ʼ��������Ϊһ����������������Ľ���������ĳһʱ�̽��� 0 �����£�������������
 * ��Щ�����ɶ�ħ�����������ʿ�ڽ�����Щ����ʱ��ʧȥ�������������������ֵΪ�����������ʾ��ʿ����ʧ����������
 * ��������Ҫô�ǿյģ��������ֵΪ 0����Ҫô����������ʿ����������ħ�������������ֵΪ�����������ʾ��ʿ�����ӽ���������
 * Ϊ�˾��쵽�﹫������ʿ����ÿ��ֻ���һ������ƶ�һ��
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

// �����е������·��
/* ����һ�����������ҳ������·���ĳ���
 * ����ÿ����Ԫ����������ϣ��£������ĸ������ƶ�
 * �㲻���ڶԽ��߷������ƶ����ƶ����߽��⣨���������ƣ�
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

// �ַ������
/* ���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ�
 * ��ʾ:
 * num1 ��num2 �ĳ��ȶ�С�� 5100
 * num1 ��num2 ��ֻ�������� 0-9
 * num1 ��num2 ���������κ�ǰ����
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
