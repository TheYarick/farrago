#include <iostream>
#include <queue>
 
using namespace std;
 
 
//This function returns distance for two horses to meet together
//as a half of distance for one horse to get to second horse's position
//or -1 if it's impossible
 
int BFS_dist(int field_size,
             int start_x,
             int start_y,
             int finish_x,
             int finish_y) {
 
    //deltas for getting to neighbours
    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
 
    //we make an array for keeping distances from start point to any other
    int **distance = new int *[field_size];
    for (int i = 0; i < field_size; ++i) {
        distance[i] = new int [field_size];
        for (int j = 0; j < field_size; ++j)
            distance[i][j] = -1;
    }
 
    queue <pair <int, int> > q;
 
    q.push(make_pair(start_x, start_y));
    distance[start_x][start_y] = 0;
   
    while (!q.empty())
    {
        int next_x = q.front().first;
        int next_y = q.front().second;
        if (next_x == finish_x && next_y == finish_y) {
            int dist = distance[next_x][next_y];
            for (int i = 0; i < field_size; ++i)
                delete [] distance[i];
            delete [] distance;
            if (dist % 2 == 0)
                return dist / 2;
            else
                return -1;
        }
        q.pop();
 
        for (int i = 0; i < 8; ++i)
        {
            int neigh_x = next_x + dx[i];
            int neigh_y = next_y + dy[i];
            if (neigh_x > -1 && neigh_x < field_size && neigh_y > -1 && neigh_y < field_size)
                if (distance[neigh_x][neigh_y] == -1) {
                    q.push(make_pair(neigh_x, neigh_y));
                    distance[neigh_x][neigh_y] = distance[next_x][next_y] + 1;
                }
        }
    }
}
 
 
int main() {   
    int xstart, ystart, xfinis, yfinis;
    char xst, xfn;
    cin >> xst >> ystart >> xfn >> yfinis;
 
    //switching from lettercoord to digitcoord
    switch (xst) {
    case 'a': xstart = 0; break;
    case 'b': xstart = 1; break;
    case 'c': xstart = 2; break;
    case 'd': xstart = 3; break;
    case 'e': xstart = 4; break;
    case 'f': xstart = 5; break;
    case 'g': xstart = 6; break;
    case 'h': xstart = 7; break;
    }
    switch (xfn) {
    case 'a': xfinis = 0; break;
    case 'b': xfinis = 1; break;
    case 'c': xfinis = 2; break;
    case 'd': xfinis = 3; break;
    case 'e': xfinis = 4; break;
    case 'f': xfinis = 5; break;
    case 'g': xfinis = 6; break;
    case 'h': xfinis = 7; break;
    }
 
    cout << BFS_dist(8, xstart, ystart - 1, xfinis, yfinis - 1);
}