#include <bits/stdc++.h>

using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;

} Node, *list1;

list1 L;
void init()
{ //初始化
    L = new Node;
    L->next = NULL;
}
//头插法
void tochafa(int n)
{
    list1 p;
    for (int i = 0; i < n; i++)
    {
        p = new Node;
        cin >> p->data;
        p->next = L->next;
        L->next = p;
    }
}
//尾插法
void wcf(int n)
{
    list1 r;
    list1 p;
    r = L;
    for (int i = 0; i < n; i++)
    {
        p = new Node;
        cin >> p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}
void show()
{
    list1 p;
    p = L;
    p = p->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
//链表的删除

void listdelete(int i)
{
    list1 p;
    p = L;
    int j = 0;
    while ((p->next) && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1)
        return;
    list1 q = p->next;
    p->next = q->next;
    free(q);
}
//链表的插入
void listinsert(int i, int e)
{
    list1 p;
    p = L;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return;
    list1 s;
    s = new Node;

    s->data = e;
    s->next = p->next;
    p->next = s;
}
int main()
{
    init();
    cout << "请选择下列选项" << endl;
    cout << "1.正序排列" << endl;
    cout << "2.逆序排列" << endl;
    cout << "3.删除第几个数据" << endl;
    cout << "4.插入数据" << endl;
    cout << "5.输出" << endl;
    int a, g, m;
    while (1)
    {
        cin >> a;
        if (a == 1)
        {
            cout << "你想搞几个数" << endl;
            cin >> g;
            cout << "输入数据" << endl;
            wcf(g);
            cout << "重新选择选项" << endl;
        }
        if (a == 2)
        {
            cout << "你想搞几个数" << endl;
            cin >> g;
            cout << "输入数据" << endl;
            tochafa(g);
            cout << "重新选择选项" << endl;
        }
        if (a == 3)
        {
            cout << "你想删除的第几个数的序号" << endl;
            cin >> g;
            listdelete(g);
            cout << "重新选择选项" << endl;
        }
        if (a == 4)
        {
            cout << "你想插入的序号，数据" << endl;
            cin >> g >> m;
            listinsert(g, m);
            cout << "重新选择选项" << endl;
        }
        if (a == 5)
        {
            show();
            break;
        }
    }
    //tochafa(3);
    // wcf(3);
    //listdelete(1);
    // listinsert(1,3);
    // show();

    return 0;
}