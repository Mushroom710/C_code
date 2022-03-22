#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "HuffmanStruct.c"

/**
 * 哈夫曼编码表的存储表示
 * */
typedef char **HuffmanCode; //动态分配数组存储哈夫曼编码表

/**
 * 说明： 
 * 1.这个数组用于存放权值较小的下标
 * 2.因为通过下标就可以找到权值，所以不需要存放权值
 * 3.默认初始化为 0
*/
int idx[2];
/**
 * 说明：
 * 1.用于初始化idx数组
 * */
void init()
{
    idx[0] = 0;
    idx[1] = 0;
}

/**
 * @brief Select
 * 1.这个函数用于从HT数组中找出weight较小的两个下标
 * 
 * @param HT 哈夫曼树
 * @param n 结点个数
 * @return * void 返回值
 */
void Select(HuffmanTree HT, int n)
{
    init(); //初始化idx数组，避免上次计算结果的影响
    int i = 1;
    for (; i <= n; i++)
    {
        /**
         * 1.首先，只有parent为 0 的结点才参与比较，因为不为 0 的结点已经有了双亲
        */
        if (HT[i].parent == 0)
        {
            /**
             * 比较思路：
             * 1.规定：最小的放在 idx[0],第二小的放在idx[1]
             * 2.比较过程：首先与idx[0]对应的weight与HT[i].weight比较，若小
             * 则idx[1] = idx[0];idx[0] = i。如果第一个if不成立，就进入else if中
             * 若idx[1]对应的weight小于HT[i].weight，则idx[1] = i。
            */
            if (HT[idx[0]].weight > HT[i].weight)
            {
                idx[1] = idx[0];
                idx[0] = i;
            }
            else if (HT[idx[1]].weight > HT[i].weight)
            {
                idx[1] = i;
            }
            /**
             * 这一节代码是多余的，因为idx[0]对应的权值一定小于idx[1]。参见idx数组的定义
             * */
            // if(HT[idx[0]].weight > HT[idx[1]].weight){
            //     int tmp = idx[1];
            //     idx[1] = idx[0];
            //     idx[0] = tmp;
            // }
        }
    }
    int tmp;
    // printf("%d--%d\n", idx[0], idx[1]);
    if (idx[0] > idx[1])
    {
        tmp = idx[1];
        // printf("%d\n",tmp);
        idx[1] = idx[0];
        idx[0] = tmp;
    }
    // printf("%d--%d\n", idx[0], idx[1]);
}

/**
 * @brief Create a Huffman Tree object
 * 构建哈夫曼树
 * 
 * @param HT 哈夫曼表
 * @param n 几个结点
 * @return * void 返回值
 */

void CreateHuffmanTree(HTNode HT[], int n)
{
    // 构造哈夫曼树，小于1无需构建
    if (n <= 1)
    {
        return;
    }
    /**
     * 规定下标从1开始
     * m的计算规则是通过Huffman树的结构推导出来的
     * */
    int m = 2 * n - 1;
    // HT = (HTNode *)calloc(m+1,sizeof(HTNode));
    int i = 1;
    printf("初始化：\n");
    printf("结点i\tweight\tparent\tlchild\trchild\n");
    /**
     * 先全部初始化为 0
     * */
    for (; i <= m; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        printf("%d\t%d\t%d\t%d", i, HT[i].parent, HT[i].lchild, HT[i].rchild);
        printf("\n");
    }
    i = 1;
    for (; i <= n; i++)
    {
        /**
         * 输入每一个结点的权值(weight)
         * */
        printf("输入第%d个叶子结点:", i);
        scanf("%d", &HT[i].weight);
    }
    i = n + 1;
    for (; i <= m; i++)
    {
        // 通过n-1次的选择、删除、合并来创建哈夫曼树
        // 调用Select函数，找出parent=0且权值最小的两个结点的下标
        Select(HT, i - 1);
        // 这两个结点的parent即为正在构建的结点下标
        HT[idx[0]].parent = i;
        HT[idx[1]].parent = i;
        // 正在构建结点的左右孩子为先前找到的两个结点下标
        // 权值小的放在左孩子，权值较大的放在右孩子
        HT[i].lchild = idx[0];
        HT[i].rchild = idx[1];
        // 计算出构建结点的权值weight，由idx[0]和idx[1]对应的权值得出
        HT[i].weight = HT[idx[0]].weight + HT[idx[1]].weight;
        // printf("%d\n",HT[i].weight);
    }
}

/**
 * @brief Create a Huffman Code object
 * 根据哈夫曼树求哈夫曼编码
 * 
 * @param HT 已经生成的哈夫曼树
 * @param HC 哈夫曼编码表
 * @param n 结点个数
 * @return * void 返回值
 */

void CreateHuffmanCode(HTNode HT[], HuffmanCode HC, int n)
{
    // 从叶子结点到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
    *HC = (char *)malloc(sizeof(char *) * (n + 1)); //分配存储n个字符编码的编码表空间
    char cd[n];                                     //分配临时存放每个字符编码的动态数组空间
    cd[n - 1] = '\0';                               //编码结束符
    int i = 1;
    for (; i <= n; i++) //逐个字符求哈夫曼编码
    {
        int start = n - 1; //start开始时指向最后，即编码结束符的位置
        int c = i;
        int f = HT[i].parent; //f指向结点c的双亲结点
        while (f != 0)        //从叶子结点开始向上回溯，直到根结点
        {
            --start;               //回溯一次start向前指一个位置
            if (HT[f].lchild == c) //结点c是f的左孩子，则生成代码 0
            {
                cd[start] = '0';
            } //结点c是f的右孩子，则生成代码 1
            else
            {
                cd[start] = '1';
            } //if
            c = f;
            f = HT[f].parent;                               //继续向上回溯
        }                                                   //while 求出第i个字符的编码
        HC[i] = (char *)malloc(sizeof(char) * (n - start)); //为第i个字符编码分配空间
        strcpy(HC[i], &cd[start]);                          //将求得的编码从临时空间cd复制到HC的当前行中
    }                                                       //for
    free(cd);                                               //释放临时空间
}

void main()
{
    // HuffmanTree ht;
    int n;
    printf("请输入结点个数：");
    scanf("%d", &n);
    printf("\n");
    /**
     * 规定下标从1开始
     * m的计算规则是通过Huffman树的结构推导出来的
     * */
    int m = 2 * n - 1;
    // printf("%d\n", m);
    // HTNode* ht = (HTNode*)calloc(16,sizeof(HTNode));
    // 因为下标从1开始，所以分配2*n的空间
    HTNode ht[2 * n];
    // 调用创建哈夫曼树的函数
    CreateHuffmanTree(ht, n);
    int i = 1;
    printf("结点i\tweight\tparent\tlchild\trchild\n");
    // 输出构建好的哈夫曼树
    for (; i <= m; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d", i, ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
        printf("\n");
    }
    printf("\n");
    HuffmanCode hc;
    printf("传说中的哈夫曼编码：\n");
    // 调用构建哈夫曼编码的函数
    CreateHuffmanCode(ht, hc, n);
    i = 1;
    // 打印每一个字符的哈夫曼编码
    for (; i <= n; i++)
    {
        printf("weight  %d：%s\n", ht[i].weight, hc[i]);
    }
}