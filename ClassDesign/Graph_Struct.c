// ----图的邻接矩阵存储表示----
#define MaxInt 32766 //表示极大值，即无穷大
#define MVNum 100    //最大顶点数

typedef char VerTexType; //顶点的数据类型
typedef int ArcType;     //边的数据类型

typedef struct
{
    VerTexType vexs[MVNum];     //顶点表
    ArcType arcs[MVNum][MVNum]; //邻接矩阵
    int vexnum;                 //图的当前点数
    int arcnum;                 //图的当前边数
} AMGraph;

//----图的邻接表存储表示----
// #define MVNum 100   //最大顶点数
typedef int OtherInfo; //和边相关的信息

typedef struct ArcNode //边结点
{
    int adjvex;              //该边所指向的顶点的位置
    struct ArcNode *nextarc; //指向下一条边的指针
    OtherInfo info;          //和边相关的信息，比如：权值
} ArcNode;

typedef struct VNode
{ //顶点信息
    VerTexType data;
    ArcNode *firstarc; //指向第一条边依附该顶点的边的指针
    ArcNode *next;
} VNode, AdjList[MVNum]; // AdjList表示邻接表类型

typedef struct
{
    AdjList vertices;
    int vexnum; //图的当前点数
    int arcnum; //图的当前边数
} ALGraph;