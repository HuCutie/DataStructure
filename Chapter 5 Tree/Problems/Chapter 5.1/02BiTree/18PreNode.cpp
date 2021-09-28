#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 5 Tree\lib\ThreadBiTree.cpp"

int main()
{
    ThreadBiTree T = CreatThreadBiTreeByPre();
    CreateInThread(T);

    InOrder(T);
    return 0;
}