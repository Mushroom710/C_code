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

char v1;
char v2;    //任意一条边的两个顶点
int weight; //边的权值
int D[MVNum][MVNum];
int Path[MVNum][MVNum];


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
    } // for

    int k, j;
    for (k = 0; k < (*G)->arcnum; k++) //输入各边，构造邻接表
    {
        printf("序偶对（v1 v2）权值：");
        scanf("%c %c %d", &v1, &v2, &weight);
        printf("\n");
        getchar();
        // 确定v1和v2在G中的位置，即顶点在G->vertices中的序号
        i = LocateVexLink(*G, v1);
        j = LocateVexLink(*G, v2);
        //生成一个新的边结点 *p1
        ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));
        p1->adjvex = j; //邻接点的序号为 j
        p1->info = weight;
        // 将新结点 *p1 插入顶点vi的表头部

        p1->nextarc = (*G)->vertices[i].firstarc;
        (*G)->vertices[i].firstarc = p1;

        //生成另一个对称的新的边结点 *p2
        ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
        p2->adjvex = i; //邻接点序号为 i
        p2->info = weight;
        //将新结点 *p2 插入顶点 vj 的边表头部

        p2->nextarc = (*G)->vertices[j].firstarc;
        (*G)->vertices[j].firstarc = p2;

    } // for
    return ok;
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
        p = p->nextarc; // p指向写一个边结点
    }                   // while
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
 * @brief 将邻接表转为邻接矩阵
 *
 * @param lg 邻接表
 * @param mg 邻接矩阵
 * @return * void
 */
void ListToMatrix(ALGraph **lg, AMGraph **mg)
{
    // printf("将邻接表转为邻接矩阵\n");
    (*mg) = (AMGraph *)malloc(sizeof(AMGraph)); //初始化邻接矩阵
    (*mg)->vexnum = (*lg)->vexnum;              //顶点数
    (*mg)->arcnum = (*lg)->arcnum;              //边数
    ArcNode *p;                                 //边结点
    int i;
    int count = (*mg)->vexnum;
    for (i = 0; i < count; i++) //遍历所有的边结点
    {
        (*mg)->vexs[i] = (*lg)->vertices[i].data; //对应的顶点数据赋值
        p = (*lg)->vertices[i].firstarc;          //指向第一条边结点
        while (p)                                 //边结点不为空
        {
            // printf("info:%d,adj:%d\n", p->info, p->adjvex);
            (*mg)->arcs[i][p->adjvex] = p->info; //边的权值
            p = p->nextarc;                      //下一条边结点
        }
    }
    int j;
    // 没有边的权值就置为 MaxInt
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < count; j++)
        {
            if (i != j && (*mg)->arcs[i][j] == 0)
            { //不是对角线上的权值
                (*mg)->arcs[i][j] = MaxInt;
            }
        }
    }
}

/**
 * @brief 弗洛伊德算法求最短路径
 *
 * @param G 邻接矩阵
 * @return * void
 */
void Floyd(AMGraph *G)
{
    int i, j, k;
    int n = G->vexnum; //结点数
    // 各对结点之间初始已知路径及距离
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            D[i][j] = G->arcs[i][j];
            if (D[i][j] < MaxInt && i != j)
            {
                Path[i][j] = j; //如果 i 和 j之间有边，则将 i的后继置为 j
            }
            else
            {
                Path[i][j] = -1; //否则置为 -1
            }
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (D[i][k] + D[k][j] < D[i][j]) //从i经k到j的一条路径更短
                {
                    D[i][j] = D[i][k] + D[k][j]; //更新D[i][j]
                    Path[i][j] = Path[i][k];     //更改i后继为k
                }
            }
        }
    }
}

/**
 * @brief 输出最短路径
 *
 * @param G 邻接矩阵
 * @param n 结点数
 * @return * void
 */
void GetMin(AMGraph *G, int n)
{
    //显示最短路径
    int i, j, k;
    printf("\n各顶点间最短路径如下:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j && D[i][j] != MaxInt)
            {
                printf("从 %c 到 %c 的最短路径长度为 %d ,具体路径为 ", G->vexs[i], G->vexs[j], D[i][j]);
                printf("%c", G->vexs[i]); //输出起点
                k = i;                    //从起点出发，寻找完整路径
                while (k != j)
                {
                    k = Path[k][j];
                    printf("->%c", G->vexs[k]); //将途径点输出
                }
                printf("\n");
            }
        }
    }
}