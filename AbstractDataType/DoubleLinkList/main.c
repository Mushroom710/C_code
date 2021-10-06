#include "MethodsDuList.c"

DuLinkList dul;

void main(){
    dul = Init(dul);
    DefaultDu(dul);
    Show(dul);
    DulInsert(dul, 0, 200);
    Show(dul);
    DeleteNode(dul,3);
    Show(dul);
}