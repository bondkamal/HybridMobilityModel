#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX // Initialize as infinite
typedef pair<int, int> iPair;
class threeD_cluster
{
private:
    int p_x_center, p_y_center, p_z_center;
    int p_x_range, p_y_range, p_z_range, rng, x_int, y_int, z_int, p_range;
    int new_x, new_y, new_z;

public:
    threeD_cluster( int p_x_center, int p_y_center, int p_z_center, int p_x_range, int p_y_range, int p_z_range)
    {
        cout<<"const running"<<endl;
        rng = 10; // random range
        this->p_x_range = p_x_range;
        this->p_y_range = p_y_range;
        this->p_z_range = p_z_range;
        this->x_int = (pow(rng, 2) - 1) * p_x_range;
        this->y_int = (pow(rng, 2) - 1) * p_y_range;
        this->z_int = (pow(rng, 2) - 1) * p_z_range;

        // original range
        this->p_range = sqrt((pow(p_x_range - p_x_center, 2) + p_y_range - p_y_center, 2) + pow(p_z_range - p_z_center, 2) * 1.0);

        // find node which are inside the range of the cluster
        // if the node is inside the cluster then compute the new coordinate for that
    }


    vector<vector<int>> changeCoordinate(int arr[][3], int size)
    {
        cout<<"changeCoordinate"<<endl;
        vector<vector<int>> newArr;
        for (int i = 0; i < size; i++) {   
            vector<int> temp;
            if (sqrt((pow(this->p_x_range - arr[i][0], 2) + this->p_y_range - arr[i][1], 2) + pow(this->p_z_range - arr[i][2], 2) * 1.0) <= this->p_range) {
                cout<<"if"<<endl;
                temp.push_back(x_int + arr[i][0]);
                temp.push_back(y_int + arr[i][1]);
                temp.push_back(z_int + arr[i][2]);
                newArr.push_back(temp);                
            }
            else {
                cout<<"else"<<endl;
                temp.push_back(arr[i][0]);
                temp.push_back(arr[i][1]);
                temp.push_back(arr[i][2]);
                newArr.push_back(temp);
            }
        }

        return newArr;
    }

    };

    void printCoordinate(vector<vector<int>> newArr){
        for(auto i:newArr){
            cout<<"("<< i[0]<<"," <<i[1]<<","<<i[2]<<")"<<endl;
        }
        cout << "print func" << endl;
    }

    class ShortestPathMapBased
    {
    private:
        /* data */
        int V;
        list<pair<int, int>> *adj;

    public:
        ShortestPathMapBased(int V)
        {
            this->V = V;
            adj = new list<iPair>[V];
        };

        void addEdge(int u, int v, int w);

        void shortestPathingraph(int s);
        int distance(int droneCoOrdinate1[], int droneCoOrdinate2[]);
    };

    void ShortestPathMapBased::addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[u].push_back(make_pair(u, w));

        adj[v].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void ShortestPathMapBased::shortestPathingraph(int src)
    {
        cout << "Source node is :: " << src << "\n";
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        vector<int> dist(V, INF);
        pq.push(make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            list<pair<int, int>>::iterator i;
            for (i = adj[u].begin(); i != adj[u].end(); ++i)
            {
                int v = (*i).first;
                int weight = (*i).second;
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        printf("Vertex \tDistance from Source\n");
        for (int i = 0; i < V; ++i)
            printf("%d \t\t %d\n", i, dist[i]);
    }

    int ShortestPathMapBased::distance(int droneCoOrdinate1[], int droneCoOrdinate2[])
    {
        int d = sqrt(pow(droneCoOrdinate2[0] - droneCoOrdinate1[0], 2) + pow(droneCoOrdinate2[1] - droneCoOrdinate1[1], 2) + pow(droneCoOrdinate2[2] - droneCoOrdinate1[2], 2) * 1.0);

        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        return d;
    }

int main() {
        int host;
        cout << "Enter the No of Drone node" << endl;
        cin >> host;

        if (host > 5 && host < 10)
        {
            int clusterHost = (host * 30 )/ 100;
            cout<<clusterHost<<endl;
            int droneCoOrdinateForThreeDcluster[clusterHost][3];
            cout << "No of node is < 200, so you are allowd to send 30 percent of node into 3D Cluster algo" << endl;
            cout << "Please enter the node co-ordinate for 3D cluster algorithm" << endl;
            for (int a = 0; a < clusterHost; a++)
            {
                cout << "Enter the coordinate for node No " << a + 1 << endl;
                cin >> droneCoOrdinateForThreeDcluster[a][0];
                cin >> droneCoOrdinateForThreeDcluster[a][1];
                cin >> droneCoOrdinateForThreeDcluster[a][2];
            }
            cout<<"Loop end"<<endl;
            
            int centerX,centerY,centerZ,rangeX,rangeY,rangeZ;
            cout<<"Please enter cluster center coordinates X, Y, Z"<<endl;
            cin>>centerX>>centerY>>centerZ;
            cout<<"Please enter cluster range coordinates X, Y, Z"<<endl;
            cin>>rangeX>>rangeY>>rangeZ;
            
            threeD_cluster callThreeDcluster(centerX, centerY, centerZ, rangeX, rangeY, rangeZ);
            vector<vector<int>> newCoordinateForThreeDCluster = callThreeDcluster.changeCoordinate(droneCoOrdinateForThreeDcluster,clusterHost);
           
        //     for(auto i:newCoordinateForThreeDCluster){
        //     cout<<"("<< i[0]<<"," <<i[1]<<","<<i[2]<<")"<<endl;
        //     cout << "main" << endl;
        // } // alternative way of print new Coordinates
        printCoordinate(newCoordinateForThreeDCluster);


             int mapHost = host - clusterHost;
             cout << "Please enter the node co-ordinate for Shortest path map based algorithm" << endl;
             int droneCoOrdinateForShortestPath[mapHost][3];
            for (int r = 0; r < mapHost; r++)
            {
                cout << "Enter the coordinate for node No " << r + 1 << endl;
                cin >> droneCoOrdinateForThreeDcluster[r][0];
                cin >> droneCoOrdinateForThreeDcluster[r][1];
                cin >> droneCoOrdinateForThreeDcluster[r][2];
            }
            ShortestPathMapBased g(mapHost);

            for (int p = 0; p < mapHost - 1; p++)
            {
                for (int i = p + 1; i < mapHost; i++)
                {
                    g.addEdge(p, i, g.distance(droneCoOrdinateForThreeDcluster[p], droneCoOrdinateForThreeDcluster[i]));
                }
            }

            cout << "Please enter the source node" << endl;
            int src;
            cin >> src;

            g.shortestPathingraph(src);
        }

        // if (host > 200)
        // {
        //     int clusterHost = host * (20 / 100);
        //     int droneCoOrdinateForThreeDcluster[clusterHost][3];
        //     cout << "No of node is < 200, so you are allowd to send 30 percent of node into 3D Cluster algo" << endl;
        //     cout << "Please enter the node co-ordinate for 3D cluster algorithm" << endl;
        //     for (int a = 0; a < clusterHost; a++)
        //     {
        //         cout << "Enter the coordinate for node No " << a + 1 << endl;
        //         cin >> droneCoOrdinateForThreeDcluster[a][0];
        //         cin >> droneCoOrdinateForThreeDcluster[a][1];
        //         cin >> droneCoOrdinateForThreeDcluster[a][2];
        //     }

        //     int mapHost = host - clusterHost;
        //     cout << "Please enter the node co-ordinate for Shortest path map based algorithm" << endl;
        //     int droneCoOrdinateForShortestPath[mapHost][3];
        //     for (int r = 0; r < mapHost; r++)
        //     {
        //         cout << "Enter the coordinate for node No " << r + 1 << endl;
        //         cin >> droneCoOrdinateForThreeDcluster[r][0];
        //         cin >> droneCoOrdinateForThreeDcluster[r][1];
        //         cin >> droneCoOrdinateForThreeDcluster[r][2];
        //     }
        //     ShortestPathMapBased g(mapHost);

        //     for (int p = 0; p < mapHost - 1; p++)
        //     {
        //         for (int i = p + 1; i < mapHost; i++)
        //         {
        //             g.addEdge(p, i, g.distance(droneCoOrdinateForThreeDcluster[p], droneCoOrdinateForThreeDcluster[i]));
        //         }
        //     }

        //     cout << "Please enter the source node" << endl;
        //     int src;
        //     cin >> src;

        //     g.shortestPathingraph(src);
        // }

        return 0;
    }