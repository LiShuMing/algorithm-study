/*
* author	: lism2013@hotmail.com
* file		: graph.h
* cdatetime : 2017-02-05 16:11
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <stack>
#include <queue>
#include <stdexcept>

enum Color{White = 0, Gray, Black};

// vertex
typedef struct Vertex{
    int     val;
    int     distance;
    int     time;
    char    lab;
    Color   color;
    int     father;
}Vertex;

// edge
typedef struct Edge{
    // direction or undirectoin
    bool    d;
    int     val;
    int     start;
    int     end;
    // start label
    char    sl;
    // end label
    char    el;
}Edge;

#define  maxVtNum 20
class Graph{
    private:
        Vertex              vts[maxVtNum];
        int                 vtNum;
        int                 edNum;
        int                 mat[maxVtNum][maxVtNum];
        std::queue<int>     q;
    public:
        Graph(){
            vtNum = 0;
            for (int i = 0; i < maxVtNum; i++){
                for (int j = 0; j < maxVtNum; j++){
                    mat[i][j] = 0;
                }
            }
        };
        ~Graph(){};

        // add vertex
        void addVertex(char lab){
            Vertex v;
            v.lab = lab;
            v.color = White;
            //TODO
            v.val = 0;

            vts[vtNum++] = v;
        }

        // add edge
        void addEdge(int s, int e){
            if (s >= maxVtNum || e >= maxVtNum){
                return;
            }
            mat[s][e] = 1;
            mat[e][s] = 1;
            edNum++;
        }

        // add edge
        void addEdgeV(int s, int e, int val){
            if (s >= maxVtNum || e >= maxVtNum){
                return;
            }
            mat[s][e] = val;
            mat[e][s] = val;
            edNum++;
        }

        // add edge char
        void addEdgeC(char s, char e, int val){
            int ss = s - 'a';
            int ee = e - 'a';

            if (ss >= maxVtNum || ee >= maxVtNum){
                return;
            }

            mat[ss][ee] = val;
            mat[ee][ss] = val;
            edNum++;
        }

        // print graph
        void printGraph(){
            for (int i = 0; i < vtNum; i++){
                if (i == 0){
                    for (int j = 0; j < vtNum; j++){
                        printf("%c\t", vts[j].lab);
                    }
                    printN();
                }

                for (int j = 0; j < vtNum; j++){
                    printf("%d\t", mat[i][j]);
                }
                printN();
            }
        }

        // print distance
        void printGraphDistance(){
            for (int i = 0; i < vtNum; i++){
                printf("%d\t", vts[i].distance);
            }

            printN();
        }

        // print time
        void printGraphTime(){
            for (int i = 0; i < vtNum; i++){
                printf("%d\t", vts[i].time);
            }

            printN();
        }

        // print father
        void printGraphFather(){
            for (int i = 0; i < vtNum; i++){
                printf("%d:%c -> %d:%c\t", i, vts[i].lab, 
                        vts[i].father, vts[vts[i].father].lab);
            }

            printN();
        }

        // dfs visit
        void dfsVisit(int s, int* time){
            *time = *time + 1;

            vts[s].distance = *time;
            vts[s].color = Gray;

            for (int j = 0; j < vtNum; j++){
                if (mat[s][j] == 1){
                    if (vts[j].color == White){
                        vts[j].father = s;
                        dfsVisit(j, time);
                    }
                }
            }

            *time = *time + 1;
            vts[s].color    = Black;
            vts[s].time     = *time;
        }

        // dfs
        void DFS(int s){
            int time = 0;

            // init vts
            for (int i = 0; i < vtNum; i++){
                vts[i].color    = White;
                vts[i].time     = 0;
                vts[i].distance = 0;
                vts[i].father   = -1;
            }

            for (int i = 0; i < vtNum; i++){
                if (vts[i].color == White){
                    dfsVisit(i, &time);
                }
            }
        }

        // bfs
        void BFS(int s){
            if (s >= vtNum){
                throw std::invalid_argument("source vertex invalid");
            }

            // init vts
            for (int i = 0; i < vtNum; i++){
                vts[i].color    = White;
                vts[i].distance = 0;
            }

            vts[s].color    = Gray;
            vts[s].distance = 0;
            vts[s].father   = -1;
            q.push(s);

            int t;
            while (!q.empty()){
                t = q.front();
                q.pop();

                for (int j = 0; j < vtNum; j++){
                    if (mat[t][j] == 1){
                        if (vts[j].color == White){
                            vts[j].color    = Gray;
                            vts[j].distance = vts[t].distance + 1;
                            vts[j].father = t;

                            q.push(j);
                        }
                    }
                }

                vts[t].color = Black;
            }
        }

        // minimum spanning tree : kruskal
        void sortEdge(Edge eds[]){
        }

        void mstKruskal(){
            Edge eds[edNum];

            // build edgs 
            int index = 0;
            for (int i = 0; i < vtNum; i++){
                for (int j = i; j < vtNum; j++){
                    if (mat[i][j] != 0){
                        eds[index].start        = i;
                        eds[index].end          = j;
                        eds[index].sl           = vts[i].lab;
                        eds[index].el           = vts[j].lab;
                        eds[index].val          = mat[i][j];
                        eds[index].d            = false;

                        index += 1;
                    }
                }
            }

            // TODO:sort eds.val
        }

        // minimum spanning tree : prim
        void mstPrim(){
        }
};

//
void testGraph(){
    Graph* g = new Graph();
    g->addVertex('a');
    g->addVertex('b');
    g->addVertex('c');
    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 2);
    g->printGraph();

    // bfs
    printStr("bfs 1");
    g->BFS(1);
    g->printGraphDistance();
    printStr("bfs 1:father");
    g->printGraphFather();
    printStr("bfs 2");
    g->BFS(2);
    g->printGraphDistance();

    // dfs
    g->DFS(1);
    printStr("dfs 1:distance");
    g->printGraphDistance();
    printStr("dfs 1:time");
    g->printGraphTime();
    printStr("dfs 1:father");
    g->printGraphFather();
    delete g;

    // kruskal
    Graph* g2 = new Graph();
    g2->addVertex('a');
    g2->addVertex('b');
    g2->addVertex('c');
    g2->addVertex('d');
    g2->addVertex('e');
    g2->addVertex('f');
    g2->addVertex('g');
    g2->addVertex('h');
    g2->addVertex('i');

    g2->addEdgeC('a', 'b', 4);
    g2->addEdgeC('a', 'h', 8);
    g2->addEdgeC('b', 'c', 8);
    g2->addEdgeC('b', 'h', 11);
    g2->addEdgeC('h', 'i', 7);
    g2->addEdgeC('h', 'g', 1);
    g2->addEdgeC('i', 'c', 2);
    g2->addEdgeC('i', 'g', 6);
    g2->addEdgeC('g', 'f', 2);
    g2->addEdgeC('c', 'f', 4);
    g2->addEdgeC('c', 'd', 7);
    g2->addEdgeC('e', 'd', 9);
    g2->addEdgeC('e', 'f', 14);
    g2->printGraph();
}

#endif /* !GRAPH_H */
