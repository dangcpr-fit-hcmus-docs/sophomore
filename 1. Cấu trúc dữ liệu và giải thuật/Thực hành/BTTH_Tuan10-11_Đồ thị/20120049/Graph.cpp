#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <queue>
#include <string>
using namespace std;
#define MAX 50
#define inf 100000007
struct graph {
    int num_vertices;
    int adjacency_list[MAX][MAX];
};
struct graphWeight {
    int num_vertices;
    int adjacency_list[MAX][MAX];
};
graph createGraphFromFile(const string& filename) { //Ham so 1
    fstream f;
    f.open(filename, ios::in);
    graph G;
    f >> G.num_vertices;
    int i = 0, j = 0;
    while (!f.eof()) {
        if (j != G.num_vertices - 1) {
            f >> G.adjacency_list[i][j];
            j++;
        }
        else {
            f >> G.adjacency_list[i][j];
            i++;
            j = 0;
        }
    }
    f.close();
    return G;
}
graphWeight createGraphWeight(const string& filename) { //Ham so 1
    fstream f;
    f.open(filename, ios::in);
    graphWeight G;
    f >> G.num_vertices;
    int i = 0, j = 0;
    while (!f.eof()) {
        if (j != G.num_vertices - 1) {
            f >> G.adjacency_list[i][j];
            j++;
        }
        else {
            f >> G.adjacency_list[i][j];
            i++;
            j = 0;
        }
    }
    f.close();
    return G;
}
void DisplayGraph(graph g) { //Ham so 2
    for (int i = 0; i < g.num_vertices; i++) {
        cout << i + 1 << ": ";
        for (int j = 0; j < g.num_vertices; j++) {
            if (g.adjacency_list[i][j]) {
                cout << j + 1 << ' ';
            }
        }
        cout << '\n';
    }
}
bool IsUndirectedGraph(graph g) { //Ham so 3
    for (int i = 0; i < g.num_vertices; i++) {
        if (g.adjacency_list[i][i] != 0)
            return 0;
        for (int j = i; j < g.num_vertices; j++) {
            if (g.adjacency_list[i][j] != inf && g.adjacency_list[j][i] != inf)
                continue;
            else
                return 0;
        }
    }
    return 1;
}
int CountEdge(graph g, bool UndirectedGraph) { //Ham so 4
    int sum = 0;
    for (int i = 0; i < g.num_vertices; i++) {
        for (int j = 0; j < g.num_vertices; j++) {
            sum += g.adjacency_list[i][j];
        }
    }
    if (UndirectedGraph) {
        return sum / 2;
    }
    else {
        return sum;
    }
}
void listDegreeOfVertices(graph g) { //Ham so 5
    int i = 0;
    while(i < g.num_vertices) {
        cout << "Dinh " << i + 1 << ":\nDi ra: ";
        for (int j = 0; j < g.num_vertices; j++) {
            if (g.adjacency_list[i][j]) cout << j + 1 << ' ';
        }
        cout << "\nDi vao: ";
        for (int j = 0; j < g.num_vertices; j++) {
            if (g.adjacency_list[j][i]) cout << j + 1 << ' ';
        }
        cout << '\n'; i++;
    }
}
void DFS(graph g, int start_vextex) { //Ham so 6
    vector<int> s;
    vector<bool> check; check.resize(g.num_vertices);
    s.push_back(start_vextex);
    while (s.size() != 0) {
        int tmp = s[s.size() - 1];
        s.pop_back();
        if (check[tmp - 1] == 1) continue;
        check[tmp - 1] = 1;
        cout << tmp << ' ';
        for (int i = g.num_vertices - 1; i >= 0; i--) {
            if (g.adjacency_list[tmp - 1][i] == 1) {
                s.push_back(i + 1);
            }
        }
    }
}
void BFS(graph g, int start_vextex) { //Ham so 7
    vector<int> check;
    check.resize(g.num_vertices);
    vector<int> q;
    q.push_back(start_vextex - 1);
    check[start_vextex - 1] = 1;
    while (q.size() != 0) {
        for (int j = 0; j < g.num_vertices; j++) {
            if (g.adjacency_list[q[0]][j] == 1 && check[j] == 0) {
                q.push_back(j);
                check[j] = 1;
            }
        }
        cout << q[0] + 1 << ' ';
        q.erase(q.begin(), q.begin() + 1);      
    }
}
bool isCyclicGraph(graph g) { //Ham so 8
    vector<int> s;
    vector<bool> check; check.resize(g.num_vertices);
    int start_vextex = 1;
    bool cycle = 0;
    for (int k = start_vextex - 1; k < g.num_vertices; k++) {
        s.push_back(k + 1);
        while (s.size() != 0) {
            int tmp = s[s.size() - 1];
            s.pop_back();            
            if (check[tmp - 1] == 1) {
                if (tmp - 1 == k) return 1;
                else continue;
            }
            check[tmp - 1] = 1;
            for (int i = g.num_vertices - 1; i >= 0; i--) {
                if (g.adjacency_list[tmp - 1][i] == 1) {
                    s.push_back(i + 1);
                }
            }
        }
        fill(check.begin(), check.end(), 0);
    }
    return 0;
}
bool DFSForConnect(graph g, int start_vextex, vector<bool>& check) {
    vector<int> s;
    s.push_back(start_vextex);
    bool connected = 0;
    if (check[start_vextex - 1] == 1) return 0;
    while (s.size() != 0) {
        int tmp = s[s.size() - 1];
        s.pop_back();
        if (check[tmp - 1] == 1) continue;
        connected = 1;
        check[tmp - 1] = 1;
        for (int i = g.num_vertices - 1; i >= 0; i--) {
            if (g.adjacency_list[tmp - 1][i] == 1) {
                s.push_back(i + 1);
            }
        }
    }
    return connected;
}

bool IsConnectedGraph(graph g) { //Ham so 9
    vector<bool> check; check.resize(g.num_vertices);
    vector<int> s; s.push_back(0);
    do {
        int k = s[s.size() - 1];
        check[k] = 1;
        s.pop_back();
        for (int i = 0; i < g.num_vertices; i++) {
            if (g.adjacency_list[k][i] != 0 && check[i] == 0)
                s.push_back(i);
        }
    } while (s.size() != 0);
    for (int i = 0; i < g.num_vertices; i++) {
        if (!check[i]) return 0;
    }
    return 1;
}

int CountConnectedComponents(graph g) { //Ham so 10
    vector<bool> check; check.resize(g.num_vertices);
    int cnt = 0;
    for (int i = 1; i <= g.num_vertices; i++) {
        if (DFSForConnect(g, i, check))
            cnt++;
    }
    return cnt;
}

void FindShortestPathDijkstra(graphWeight g, int start_vertex) { //Ham so 11.1
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<pair<int, int>> dist;
    vector<bool> check; check.resize(g.num_vertices);
    check[start_vertex - 1] = 1;
    int tmp = 0, i = 1;
    for (int i = 0; i < g.num_vertices; i++) {
        dist.push_back({ inf, 0 });
    }
    cout << "Duong di ngan nhat:\n";
    do {
        for (int i = 0; i < g.num_vertices; i++) { //Ham so 11.2
            if (check[i] == 0) {
                if (g.adjacency_list[start_vertex - 1][i] + tmp < dist[i].first) {
                    dist[i] = { g.adjacency_list[start_vertex - 1][i] + tmp, start_vertex };
                    q.push({ g.adjacency_list[start_vertex - 1][i] + tmp, i });
                }
            }           
        }
        for (int i = 0; i < g.num_vertices; i++) {
            if (dist[i].second == 0) cout << "(inf,-)\t";
            else cout << "(" << dist[i].first << "," << dist[i].second << ")\t";
        }
        cout << "\n";
        tmp = q.top().first;
        check[q.top().second] = 1;
        start_vertex = q.top().second + 1;
        q.pop();
    } while (!q.empty());
    cout << "Src\tDes\tWei\n";
    for (int i = 0; i < g.num_vertices; i++) {
        if (dist[i].second != 0)
            cout << i + 1 << '\t' << dist[i].second << '\t' << dist[i].first << '\n';
    }
}

void FindShortestPathFloyd(graphWeight g) {
    for (int i = 0; i < g.num_vertices; i++)
        for (int j = 0; j < g.num_vertices; j++) {
            for (int k = 0; k < g.num_vertices; k++) {
                if (g.adjacency_list[j][i] + g.adjacency_list[i][k] < g.adjacency_list[j][k])
                    g.adjacency_list[j][k] = g.adjacency_list[j][i] + g.adjacency_list[i][k];
            }
        }
    cout << "Duong di ngan nhat:\n";
    for (int i = 0; i < g.num_vertices; i++){
        for (int j = 0; j < g.num_vertices; j++) {
            cout << g.adjacency_list[i][j] << " ";
        }
        cout << "\n";
    }
}

void FindShortestPathBellman(graphWeight g, int start_vertex) { //Ham so 11.3
    vector<pair<int, int>> dist;
    cout << "Duong di ngan nhat:\n";
    //vector<bool> check; check.resize(g.num_vertices);
    for (int i = 0; i < g.num_vertices; i++) {
        if (i == start_vertex - 1) dist.push_back({ 0, 0 });
        else dist.push_back({ inf, 0 });
    }
    //check[start_vertex - 1] == 1;
    int v = 0;
    while (true) {
        bool check = 1;
        if (v == 0) {
            for (int i = 0; i < g.num_vertices; i++) {
                if (g.adjacency_list[start_vertex - 1][i] < inf)
                    dist[i] = { g.adjacency_list[start_vertex - 1][i],start_vertex };
            }
        }
        for (int i = 0; i < g.num_vertices; i++) {
            if (i == start_vertex - 1) continue;
            pair<int, int> tmp = { inf, 0 };
            for (int j = 0; j < g.num_vertices; j++)
                if (dist[j].first + g.adjacency_list[j][i] < tmp.first)
                    tmp = { dist[j].first + g.adjacency_list[j][i], j + 1 };
            if (dist[i] != tmp) check = 0;
            dist[i] = tmp;
        }
        for (int i = 0; i < g.num_vertices; i++) {
            if (dist[i].second == 0) cout << "(0,-)\t";
            else if (dist[i].first == inf) cout << "(inf,-)\t";
            else cout << "(" << dist[i].first << "," << dist[i].second << ")\t";
        }
        cout << "\n";
        if (v == 0) {
            v++; continue;
        }
        if (check == 1) break;
        if (v == g.num_vertices) {
            if (check == 0) cout << "Vo nghiem";
            break;
        }
    }
}

int main()
{
    graph G = createGraphFromFile("graph.txt"); //1
    DisplayGraph(G); //2
    bool UndirectedGraph = IsUndirectedGraph(G); //3
    cout << UndirectedGraph << endl;
    cout << CountEdge(G, UndirectedGraph) << endl; //4
    listDegreeOfVertices(G); //5
    DFS(G, 1); cout << endl; //Dinh bat dau tu 1 //6
    BFS(G, 1); cout << endl; //7
    cout << isCyclicGraph(G) << endl; //8
    cout << IsConnectedGraph(G) << endl; //9
    cout << CountConnectedComponents(G) << endl; //10
    graphWeight H = createGraphWeight("graphWithWeight.txt");
    FindShortestPathDijkstra(H, 1);
    FindShortestPathFloyd(H);
    FindShortestPathBellman(H, 1);
}