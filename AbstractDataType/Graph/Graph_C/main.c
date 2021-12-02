#include "Graph_Methods.c"

// init()函数用于初始化标志数组

void main()
{
    // printf("开始构建邻接矩阵。。。\n");
    // AMGraph *G;
    // init();
    // CreateUDN(&G);
    // printf("邻接矩阵：\n");
    // Translation(G);
    // printf("\n\n邻接矩阵DFS：");
    // DFS_AM(G, 0);
    // printf("\n");
    // init();
    // printf("\n邻接矩阵BFS：");
    // BFS_AM(G, 0);

    printf("开始构建邻接表。。。\n");
    ALGraph *G;
    init();
    CreateUDG(&G);
    printf("邻接表DFS： ");
    DFS_AL(G, 0);
    printf("\n");
    init();
    printf("邻接表BFS：");
    BFS_AL(G,0);
    printf("\n");
    printf("邻接表：\n");
    TranslationLink(G);
}