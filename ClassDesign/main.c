#include "Graph_Methods.c"

// 出现乱码，请将控制台编码改为 UTF-8 ，参考命令：chcp 65001
// init()函数用于初始化标志数组

void main()
{

    printf("开始构建邻接表。。。\n");
    ALGraph *G;
    AMGraph *mg;
    init();
    CreateUDG(&G);
    printf("邻接表DFS： ");
    DFS_AL(G, 0);
    printf("\n");
    init();
    printf("邻接表BFS：");
    BFS_AL(G, 0);
    printf("\n");
    // printf("邻接表转邻接矩阵\n");
    ListToMatrix(&G, &mg);
    // 调用弗洛伊德算法
    Floyd(mg);
    // 打印最短路径
    GetMin(mg, mg->vexnum);
}