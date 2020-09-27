/*�ַ�����ȡ������ִ����㷨��
 *ʹ���������㷨 Manacher��s Algorithm
 * Ϊ������ż�ִ�Ӱ�죬���ִ�����в���һ�������ַ�����ȡ#����β�������ֱ�Ϊ$&
 * ȡһ������t(����ʹ��vector����������),��¼��ÿ��λ��Ϊ���ĵĻ����ִ��뾶����
 * ��������ȳ���2Ϊ����ǰ�ִ����±�
 * ���ӵ�ΪO(n)----> Manacher_NB
 * */
#include <iostream>
#include <vector>
using namespace std;
static string manacher(const string&s){
    // ���ִ����в��빹�죬����$#a#...#z#&
    string p("$");
    for(auto i:s){
        p.push_back('#');
        p.push_back(i);
    }
    p.push_back('#');
    p.push_back('&');

    // ȡint������¼��Ӧλ���������Ӵ��뾶��������0
    int length_p = static_cast<int>(p.size());
    vector<int> t(length_p,0);
    // c,rΪ���Ʋ���, rΪ��ǰ���Ĵ�����λ�ã�cΪrȡ����λ��ʱ������
    int c=0,r=0;
    // �ӵ�һ��#��ʼ���������һ��#
    for(int l=1;l<length_p-1;++l){
        // ��ȡ����c�ľ����±�
        int l_m = 2*c -l;
        // ���һ����ִ��������±�����棬��ֹĿǰ�����ִ������ҳ���ԭ�����ң�ȡ����ֵ
        if(r>l){
            t[l] = r-l < t[l_m]? r-l:t[l_m];
        }
        // �Ե�ǰ�±��ִ���ȡ˫�����ţ�ֱ����������
        while(p[l+1+t[l]]==p[l-1-t[l]]){
            ++t[l];
        }
        // �ж�Ŀǰ�����ұ߽��Ƿ����ԭ�����ұ߽磬������ͬʱ����c��r
        if(l+t[l]>r){
            r = l+t[l];
            c = l;
        }
    }
    // �жϳ���ִ������Լ��ʱ�İ뾶
    r=0;
    for(int index=0;index<length_p;++index){
        cout << t[index]<<" ";
        if(r < t[index]){
            c = index;
            r = t[c];
        }
    }
    // ����c,rȡ��������Ҫ�Ļ����Ӵ�������Ϊ����ֵ����
    string res;
    for(int k=(c-r)/2;k<(c+r)/2;++k){
        res.push_back(s[k]);
    }
    return res;
}