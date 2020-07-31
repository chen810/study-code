## 标题
* 使用多个`#`号进行标题级别的表示，例如：
    ># 一级标题
    >###### 六级标题(最大)
* 分别使用`===`和`---`在标题下一行作为一级标题和二级标题。
    >二级标题
    >---

## 分割线
使用三个或三个以上的`*`或`-`构成分割线，可使用空格隔开`-`避免成为二级标题。
- - -

## 粗体和斜体
分别使用`*`和`**`表示斜体和粗体
*斜体*
**粗体**
 ***加粗斜体***
~~删除线~~使用两个`~`表示

## 超链接和图片
[第一种写法](https://www.baidu.com/)
[第二种写法][1]:此方法对应的网址另起一行
![图片链接](https://t7.baidu.com/it/u=3616242789,1098670747&fm=79&app=86&size=h300&n=0&g=4n&f=jpeg?sec=1596728289&t=3800c381ea16ec4bd6f34174132e74a9)
显示可点击链接 <https://www.baidu.com/>

[1]: https://www.baidu.com/

## 无序列表
使用`-`,`+`,`*`表示无序列表，可反复嵌套
- 一
  -  二
     - 三
       - 四

## 有序列表
使用`数字.`作为表示有序列表，可嵌套
1. 一
   1. 二
      1. 三

## 文字引用
引用降级需在后面加一行`>`
> 第一层次引用
>> 第二层次引用
>
>第一层次引用

## 行内代码块
使用 \` 表示，`行内代码块`，转义使用`\`字符

## 代码块
使用四个空格作为代码块,前一行应空出:

    #include <stdio.h>
    int main(){
        printf("hello world!")
    }
使用```作为代码块标识:
```
#include <stdio.h>
int main(){
    printf("hello world!")
}
```
---
## 表格
第二行表示每一列的对其方式，如：
|编号|数量|价格|
|---|---:|---:|
|1|50|￥50|
|2|100|￥20|
其中:`---`左对齐、`---:`右对齐

## 流程图
主要的语法为 `name=>type: describe`,其中 type 主要有以下几种：
1.开始和结束：`start` `end`
2.输入输出：`inputoutput`
3.操作：`operation`
4.条件：`condition`
5.子程序：`subroutine`
第一步：创建节点
第二部：编写节点连接图
第三部：放入表示符` ```flow` 和` ``` `之间
```flow
 ST=>start: ST A=0:>https://www.baidu.com/
 io=>inputoutput: IO N=?
 op=>operation: OP A+N
 can=>condition: Choice A>100
 SUB=>subroutine: NEXT 2*A
 E=>end: END

 ST->io->op->can
 can(yes)->E
 can(no)->SUB->io
```