#include "stdio.h"
#include "stdlib.h"
#include "Graph_Struct.c"
#include "queue/QueueMethods.c"

typedef int Status;
typedef int bool;
#define ok 1
#define overflow 0
#define false 0
#define true 1
#define error 0;

/**
 * 超级大坑：关于使用字符作为数据类型时：
 * scanf("%c",&ch);
 * 会出现很诡异的问题，这个问题需要加一个 getchar();来解决
 * 作用就是吸收掉 \n 回车符
 * scanf("%c",&ch);
 * getchar();
 * 
 * 这个与C设计有关系。坑的很
 * 
 */

char v1;
char v2;    //任意一条边的两个顶点
int weight; //边的权值

/**
 * 邻接矩阵版
 * @brief 这个函数用于确定顶点在顶点数组中的下标
 * 
 * @param G 待查找的图
 * @param v 查找的顶点
 * @return * int 返回顶点在顶点数组中的下标
 */
int LocateVex(AMGraph *G, VerTexType v)
{
    int i;
    for (i = 0; i < G->vexnum; i++)
    { //简单厨宝的方法，一个一个找，可以改进为二分查找
        if (G->vexs[i] == v)
        {
            return i;
        }
    }
    return error;
}

/**
 * @brief 采用邻接矩阵表示法创建无向图
 * 无向图的邻接矩阵是对称矩阵
 * @param G 无向图
 * @return * Status 
 */
Status CreateUDN(AMGraph **G)
{
    // 采用邻接矩阵表示法，创建无向图G
    (*G) = (AMGraph *)malloc(sizeof(AMGraph));
    printf("总顶点数：");
    scanf("%d", &(*G)->vexnum);
    printf("总边数：");
    scanf("%d", &(*G)->arcnum);
    getchar();
    int i;
    for (i = 0; i < (*G)->vexnum; i++) //依次输入点的信息
    {
        printf("第%d个顶点的信息：", i + 1);
        scanf("%c", &((*G)->vexs[i]));
        getchar();
    }
    int j = 0;
    for (i = 0; i < (*G)->vexnum; i++)
    { //初始化邻接矩阵，边的权值均初始化为极大值MaxInt
        for (j = 0; j < (*G)->vexnum; j++)
        {
            (*G)->arcs[i][j] = MaxInt;
        }
    }
    printf("\n输入一条边依附的顶点\n");
    int k;
    for (k = 0; k < (*G)->arcnum; k++)
    {
        // printf("顶点一：");
        // scanf("%c", &v1);
        // getchar();
        // printf("顶点二：");
        // scanf("%c", &v2);
        printf("序偶对（v1 v2）：");
        scanf("%c %c", &v1, &v2);
        getchar();
        printf("边的权值：");
        scanf("%d", &weight);
        getchar();
        printf("\n");
        i = LocateVex(*G, v1); //确定v1和v2在顶点数组中的位置
        j = LocateVex(*G, v2);
        (*G)->arcs[i][j] = weight;           //边<v1,v2>的权值置为weight
        (*G)->arcs[j][i] = (*G)->arcs[i][j]; //<v1,v2>的对称边<v2,v1>的权值为weight
    }                                        //for 构建邻接矩阵结束
    return ok;
}

/**
 * 邻接表版
 * 
 * @brief 这个函数用于找出顶点的下标
 * 
 * @param G 邻接表
 * @param v 查找顶点
 * @return * int 返回顶点下标
 */

int LocateVexLink(ALGraph *G, VerTexType v)
{
    int i;
    for (i = 0; i < G->vexnum; i++)
    { //简单厨宝的方法，一个一个找，可以改进为二分查找
        if (G->vertices[i].data == v)
        {
            return i;
        }
    }
    return error;
}

/**
 * @brief 采用邻接表表示法，创建无向图 G
 * 
 * @param G 创建的无向图
 * @return * Status 
 */

Status CreateUDG(ALGraph **G)
{
    (*G) = (ALGraph *)malloc(sizeof(ALGraph));
    // 输入总顶点数，总边数
    printf("总顶点数：");
    scanf("%d", &(*G)->vexnum);
    printf("总边数：");
    scanf("%d", &(*G)->arcnum);
    getchar();
    int i;
    for (i = 0; i < (*G)->vexnum; i++)
    { //输入各点，构造表头结点表
        printf("输入第 %d 个顶点的值：", i + 1);
        scanf("%c", &(*G)->vertices[i].data);
        getchar();
        (*G)->vertices[i].firstarc = NULL; //初始化表头结点的指针域为NULL
        (*G)->vertices[i].next = NULL;
    } //for

    int k, j;
    for (k = 0; k < (*G)->arcnum; k++) //输入各边，构造邻接表
    {
        //输入一条边依附的两个顶点
        // printf("顶点一：");
        // scanf("%c", &v1);
        // getchar();
        // printf("顶点二：");
        // scanf("%c", &v2);
        printf("序偶对（v1 v2）：");
        scanf("%c %c", &v1, &v2);
        printf("\n");
        getchar();
        // 确定v1和v2在G中的位置，即顶点在G->vertices中的序号
        i = LocateVexLink(*G, v1);
        j = LocateVexLink(*G, v2);
        // printf("%d---%d\n",i,j);
        //生成一个新的边结点 *p1
        ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));
        p1->adjvex = j; //邻接点的序号为 j
        // 将新结点 *p1 插入顶点vi的表头部
        
        // 正相关创建
        if((*G)->vertices[i].firstarc == NULL){
            p1->nextarc = NULL;
            (*G)->vertices[i].firstarc = p1;
            (*G)->vertices[i].next = (*G)->vertices[i].firstarc;
        }else{
            (*G)->vertices[i].next->nextarc = p1;
            (*G)->vertices[i].next = p1;
            p1->nextarc = NULL;
        }

        // 反相关创建
        // p1->nextarc = (*G)->vertices[i].firstarc;
        // (*G)->vertices[i].firstarc = p1;

        //生成另一个对称的新的边结点 *p2
        ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
        p2->adjvex = i; //邻接点序号为 i
        // 将新结点 *p2 插入顶点 vj 的边表头部

        // 正相关创建
        if((*G)->vertices[j].firstarc == NULL){
            p2->nextarc = NULL;
            (*G)->vertices[j].firstarc = p2;
            (*G)->vertices[j].next = (*G)->vertices[j].firstarc;
        }else{
            (*G)->vertices[j].next->nextarc = p2;
            (*G)->vertices[j].next = p2;
            p2->nextarc = NULL;
        }

        // 反相关创建
        // p2->nextarc = (*G)->vertices[j].firstarc;
        // (*G)->vertices[j].firstarc = p2;

    } //for
    return ok;
}

/**
 * @brief 遍历邻接矩阵
 * 
 * @param G 待遍历的邻接矩阵
 */

void Translation(AMGraph *G)
{
    int i;
    int j;
    int num = G->vexnum;
    printf("\t");
    for (i = 0; i < num; i++)
    {
        printf("%c\t", G->vexs[i]);
    }
    printf("\n\n");
    for (i = 0; i < num; i++)
    {
        printf("%c\t", G->vexs[i]);
        for (j = 0; j < num; j++)
        {

            printf("%d\t", G->arcs[i][j]);
        }
        printf("\n");
    }
}

void TranslationLink(ALGraph *G){
    if(!G){
        return;
    }
    int i;
    for (i = 0; i < G->vexnum;i++){
        VNode p = G->vertices[i];
        ArcNode *q = p.firstarc;
        printf("%c\t", p.data);
        while (q)
        {
            printf("%c\t", G->vertices[q->adjvex].data);
            q = q->nextarc;
        }
        printf("\n");
    }
}

    bool visited[MVNum];
/**
 * @brief 初始化visited数组，置为 false
 * 
 * @return * void 
 */
void init()
{
    int i;
    for (i = 0; i < MVNum; i++)
    {
        visited[i] = false;
    }
}

/**
 * @brief 邻接表的深度优先搜索遍历
 * 
 * @param G 邻接表
 * @param v 访问的结点
 * @return * void 
 */
void DFS_AL(ALGraph *G, int v)
{
    // 首先从第 v 个顶点开始出发深度优先搜索遍历图 G
    // 访问第 v 个结点，并访问标志数组相应分量值为 true
    printf("%c\t", G->vertices[v].data);
    visited[v] = true;
    // p指向 v 的边链表的第一个边结点
    ArcNode *p = G->vertices[v].firstarc;
    while (p != NULL)
    {
        int w = p->adjvex; //表示 w 是 v 的邻接点
        if (!visited[w])
        {
            DFS_AL(G, w); //如果w未访问，则递归调用 DFS_AL
        }
        p = p->nextarc; //p指向写一个边结点
    }                   //while
}

/**
 * @brief 邻接矩阵深度优先搜索
 * 
 * @param G 邻接矩阵
 * @param v 访问结点
 * @return * void 
 */
void DFS_AM(AMGraph *G, int v)
{
    // 首先从第 v 个顶点开始出发深度优先搜索遍历图 G
    // 访问第 v 个结点，并访问标志数组相应分量值为 true
    printf("%c\t", G->vexs[v]);
    visited[v] = true;
    int w;
    // 依次检查邻接矩阵中 v 所在行
    for (w = 0; w < G->vexnum; w++)
    {
        // G->arcs[v][w] != 0表示 w 是 v 的邻接点，如果 w 未访问，则递归调用 DFS_AM
        if ((G->arcs[v][w] != 0) && (!visited[w]))
        {
            DFS_AM(G, w);
        }
    }
}

/**
 * @brief 邻接表的广度优先搜索遍历
 * 遍历的是一个连通图，非连通图只需要写一个函数，遍历visited数组，
 * 没有访问过的结点就以这个结点为起始节点，再次调用 BFS_AL 函数即可
 * 
 * @param G 邻接表
 * @param v 访问结点
 * @return * void 
 */

LinkQueue q; //辅助队列

void BFS_AL(ALGraph *G, int v)
{
    // 按广度优先搜索遍历图 G
    // 首先访问起始结点 v
    printf("%c\t", G->vertices[v].data);
    visited[v] = true;
    InitQueue(&q);            //初始化辅助队列
    EnQueue(&q, v);           //访问起始结点 v 后，将 v 入队
    while (q.rear != q.front) //队列非空时，循环遍历
    {
        int tmp;                                         //辅助变量，用于记录出队的元素
        DeQueue(&q, &tmp);                               //队头元素出队
        ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode)); //辅助边结点，用于记录当前结点的下一个邻接结点
        p = G->vertices[tmp].firstarc;                   //辅助边结点指向当前结点的下一个边结点

        // while相当于一次链表遍历。需要遍历完当前结点的所有邻接点。
        // 通过边链表的 adjvex 可以找到对应的邻接点。
        while (p) //边结点非空时，说明当前结点有邻接结点
        {
            if (!visited[p->adjvex]) //邻接点未访问时
            {
                printf("%c\t", G->vertices[p->adjvex].data); //访问该邻接点
                visited[p->adjvex] = true;
                EnQueue(&q, p->adjvex); //访问后，将该邻接点入队
            }
            p = p->nextarc; //指针后移
        }
    }
}

/**
 * @brief 邻接矩阵的广度优先搜索遍历
 * 
 * @param G 邻接矩阵
 * @param v 起始结点
 * @return * void 
 */

void BFS_AM(AMGraph *G, int v)
{
    printf("%c\t", G->vexs[v]);
    visited[v] = true;
    InitQueue(&q);
    EnQueue(&q, v);
    while (q.front != q.rear)
    {
        int tmp;
        DeQueue(&q, &tmp);
        int i;
        for (i = 0; i < G->vexnum; i++)
        {
            if (!visited[i] && (G->arcs[tmp][i] != 0))
            {
                printf("%c\t", G->vexs[i]);
                visited[i] = true;
                EnQueue(&q, i);
            }
        }
    }
}