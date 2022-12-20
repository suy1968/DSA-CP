#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

void print(int **arr, int n, int starting_vertex, bool *visited)
{
    queue<int> q;
    q.push(starting_vertex);
    visited[starting_vertex] = true;
    while (!q.empty()) {

        cout << q.front() << " ";
        int current_element = q.front();
        q.pop();

        for (int i = 1; i < n; i++) {
            if (arr[current_element][i] == 1 && !visited[i] && i != current_element){
                q.push(i);
                visited[i] = true;
     
            }
        }
    }
}
void BFS( int **arr , bool* visited , int starting_index , int v){
    
    for (int i = 0; i < v; i++){
        if (!visited[i]) {
            print(arr, v, i, visited);
        }
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    int **arr = new int *[v];
    for (int i = 0; i < v; i++){
        arr[i] = new int[v];
        for (int j = 0; j < v; j++){
            arr[i][j] = 0;
        }
    }
    while (e--){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    bool *visited = new bool[v];
    // for (int i = 0; i < v; i++){
    //     visited[i] = false;
    // }
    memset(visited,false,sizeof(visited));
    BFS( arr , visited ,0 , v );   
}
