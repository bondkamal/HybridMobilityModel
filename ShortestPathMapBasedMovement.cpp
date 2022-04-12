#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX  //Initialize as infinite


#include <bits/stdc++.h>
#include <iomanip>
#include <iostream>
#include <math.h>

typedef pair<int,int> iPair;

// struct DroneNode
// {
//     int x_coordinaate, y_coordinaate, z_coordinaate;
// };


class ClassBaseDijkstraAlgo
{
private:
    /* data */
    int V;
    list<pair<int,int>> *adj;

public:
    ClassBaseDijkstraAlgo(int V){
        this->V = V;
        adj = new list<iPair>[V];
    };
   

    void addEdge(int u, int v, int w);

    void shortestPathingraph(int s);
    int distance(int droneCoOrdinate1[],int droneCoOrdinate2[]);
    
};

void ClassBaseDijkstraAlgo::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[u].push_back(make_pair(u,w));
}

void ClassBaseDijkstraAlgo::shortestPathingraph(int src){
    cout<<"Source node is :: " << src <<"\n";
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq; 
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;

     while (!pq.empty()){
        int u = pq.top().second;  
        pq.pop();
        list<pair<int, int>>::iterator i;  
         for (i = adj[u].begin(); i != adj[u].end(); ++i){
              int v = (*i).first;  
            int weight = (*i).second;  
             if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;  
                pq.push(make_pair(dist[v], v));  
            }  
         }
     }
    printf("Vertex \tDistance from Source\n");
    for (int i = 0; i < V; ++i)  
        printf("%d \t\t %d\n", i, dist[i]); 
}

int ClassBaseDijkstraAlgo::distance(int droneCoOrdinate1[],int droneCoOrdinate2[])
{
    // float d = sqrt(pow(x2 - x1, 2) +
    //             pow(y2 - y1, 2) +
    //             pow(z2 - z1, 2) * 1.0);
    int d = sqrt(pow(droneCoOrdinate2[0]-droneCoOrdinate1[0],2)+pow(droneCoOrdinate2[1]-droneCoOrdinate1[1],2)+pow(droneCoOrdinate2[2]-droneCoOrdinate1[2],2) * 1.0);

    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    // cout << " Distance is " << d;
    return d;
}

int main()  
{  
    int V = 4;   
    ClassBaseDijkstraAlgo g(V); 

    int droneCoOrdinate0[3] = {1,2,3};
    int droneCoOrdinate1[3] = {4,5,6};
    int droneCoOrdinate2[3] = {7,8,9};
    int droneCoOrdinate3[3] = {10,11,12};

    //int p = g.distance(droneCoOrdinate1,droneCoOrdinate2);

    g.addEdge(0, 1, g.distance(droneCoOrdinate0,droneCoOrdinate1));  
    g.addEdge(0, 2, g.distance(droneCoOrdinate0,droneCoOrdinate2));  
    g.addEdge(0, 3, g.distance(droneCoOrdinate0,droneCoOrdinate3));  
    g.addEdge(1, 2, g.distance(droneCoOrdinate1,droneCoOrdinate2));  
    g.addEdge(1, 3, g.distance(droneCoOrdinate1,droneCoOrdinate3));  
    g.addEdge(2, 3, g.distance(droneCoOrdinate2,droneCoOrdinate3));  
    



    g.shortestPathingraph(0); 

    
      
    return 0; 
}  

















