#include <stdio.h>
#include <vector>
#include <queue>

const int Inf = 30000;

int main(){
    int n, s, l;
    //printf("Initiate number of vertexes: ");
    scanf("%d ", &n);
    //printf("Initiate starting vertex: "); //s in [1;n]
    scanf("%d ", &s);
    //printf("Initiate last vertex: "); //l in [1;n]
    scanf("%d ", &l);
    s--;
    l--;
    //making up the matrix of vertexses
    std::vector <std::vector <int>> matrix (n, std::vector <int> (n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            //printf("Set the value of %d %d", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    std::vector <int> distances (n, Inf); //distances[x] is distance from s to x
    distances[s] = 0; //distance from[s] to s obviously equals to 0
    std::priority_queue <std::pair <int, int>> queue; //queue{{len, ver}}
    queue.push(std::make_pair(0, s));

    while(!queue.empty()){ //while we haven't visited to last vertex (aka queue isnt empty)
        int len = -queue.top().first; 
        int v = queue.top().second; 
        queue.pop(); //clearing the queue
        if (len > distances[v]) //if INF - skip iteration
            continue;
        for (int i = 0; i < n; i++){ 
            int vert = i;
            int len_of_vert = matrix[v][i]; // if where's a way to get to vertex faster than distances[vert], then it's a new distance 
            if (distances[vert] > distances[v] + len_of_vert){
                distances[vert] = distances[v] + len_of_vert;
                queue.push(std::make_pair(-distances[vert], vert));
            }
        }
    }

    if (distances[l] == Inf){
        printf("Unable to get there");
    }else{
        printf("%d", distances[l]);
    }
}