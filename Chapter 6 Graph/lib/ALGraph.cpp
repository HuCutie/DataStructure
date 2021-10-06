#include "C:\MyProjects\Visual Studio Code Workspace\DataStructure\Chapter 6 Graph\include\ALGraph.h"

int GetIndexByData(ALGraph G, VertexType x)
{
    for(int i = 0; i < G.VexNum; i++)
    {
        if(G.vertices[i].data == x)
        {
            return i;
        }
    }

    return -1;
}

void InitALGraph(ALGraph & G)
{
    cout << "Input the number of vertices: ";
    cin >> G.VexNum;

    cout << "Input each vertex: " << endl;
    for(int i = 0; i < G.VexNum; i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].first = NULL;
    }

    G.ArcNum = 0;
}

ALGraph Create()
{
    ALGraph G;
    ArcNode * p;
    VertexType temp;

    InitALGraph(G);

    for(int i = 0; i < G.VexNum; i++)
    {

        while (1)
        {
            cout << "Input the end node starting whith " << G.vertices[i].data << " (# stands for NULL) : ";
            cin >> temp;

            if (temp == '#')
            {
                break;
            }
            else
            {
                int index = GetIndexByData(G, temp);
                if (index != -1)
                {
                    p = (ArcNode *)malloc(sizeof(ArcNode));

                    p->adjvex = index;
                    p->next = G.vertices[i].first;
                    G.vertices[i].first = p;

                    G.ArcNum++;
                }
                else
                {
                    cout << "Wrong node, please input again." << endl;
                    continue;
                }
            }
        }
    }

    return G;
}

int main()
{
    ALGraph G = Create();
    return 0;
}