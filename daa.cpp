#include <bits/stdc++.h>
using namespace std;
// prim's algorithm
//  int main()
//  {
//      //example for no. of vertices 5;
//      int n = 5;
//      bool selectedvertices[n];//selected vertices put into graph;
//      for(int i = 0; i<n;i++) selectedvertices[i] = false;
//      int adjacencylist[n][n] = {{0, 9, 75, 0, 0},
//                                 {9, 0, 95, 19, 42},
//                                 {75, 95, 0, 51, 66},
//                                 {0, 19, 51, 0, 31},
//                                 {0, 42, 66, 31, 0}};
//      int no_of_edges = 0; //no. of edges in solution is always = V-1(here n-1)
//      selectedvertices[0] = true;
//      while(no_of_edges!= n-1)
//      {   int x = 0;
//          int y = 0;
//          int minimum = INT_MAX;
//          for (int i = 0; i < n; i++) // loop for selected vertex
//          {
//              if(selectedvertices[i] == true)//only if the vertex can be reached
//              {
//                  for(int j = 0; j<n;j++)
//                  {
//                      if(!selectedvertices[j] && adjacencylist[i][j]) // j'th vertex not yet selected and edge present
//                      {
//                          if(minimum>adjacencylist[i][j])
//                          {
//                              minimum = adjacencylist[i][j];
//                              x = i;
//                              y = j;

//                         }
//                     }
//                 }
//             }
//         }
//         cout<<x<<"->"<<y<<":"<<minimum<<endl;
//             selectedvertices[y] = true;
//             no_of_edges++;

//     }
// }

//

// dijkstra algo
//  int main(){
//      int n = 9; // no. of vertices
//      int edges[n][n] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
//                          { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
//                          { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
//                          { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
//                          { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
//                          { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
//                          { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
//                          { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
//                          { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
//      int startingvertex = 0; //dijakstra start
//      int finalsolution[n];
//      int relaxedvertex[n];
//      for(int i = 0; i<n;i++)
//      {
//          finalsolution[i] = INT_MAX;
//          relaxedvertex[i] = false;
//      }
//          //relax the first vertex
//          finalsolution[startingvertex] = 0;
//          relaxedvertex[startingvertex] = true;
//          //array to check if a vertex is relaxed or not
//          //now run the loop n-1 times while relaxing one vertex for each loop.
//          int last_min = edges[startingvertex][startingvertex];
//          int last_vertex = startingvertex;
//          for(int i = 0; i<n-1;i++){
//              //second loop to find minimum for each vertex
//                  int temp_min = INT_MAX;
//                  int temp_index = -1;
//              for(int j = 0;j<n;j++)
//              {
//                  if(!relaxedvertex[j])
//                  {
//                      if(edges[last_vertex][j]){
//                      int calc = last_min + edges[last_vertex][j];
//                      finalsolution[j] = min(finalsolution[j],calc);
//                      }
//                      if(temp_min>finalsolution[j]){
//                          temp_min = finalsolution[j];
//                          temp_index = j;
//                      }
//                  }

//             }
//             last_min = temp_min;
//             last_vertex = temp_index;
//             relaxedvertex[last_vertex] = true;
//         }
//         //printing the final solution
//         for(int i = 0; i<n;i++)
//         cout<<"vertex "<<i<<":"<<finalsolution[i]<<endl;

// }

// //0/1 knapsack - basically write recursive solution along with a map
// int knapsack(int W,int wt[],int val[],int n,map<pair<int,int>,int> dp)
// {
//     /*
//     W - weight of knapsack
//     wt[] - weights of the items
//     val[] - values of the items
//     n - no. of items
//     */
//    //base case - if capacity is full or no items left
//    if(dp.find({W,n}) != dp.end())
//    {
//         return dp[{W,n}];
//    }
//    if(W==0||n==0)
//    {
//     dp[{W,n}] = 0;
//     return 0;
//    }
//    //we will iterate from the last item as it is very easy to exclude in the next loop by reducing the n by 1
//    if(wt[n-1] > W)//this item cannot be taken in knapsack
//    {
//         dp[{W,n}] = knapsack(W,wt,val,n-1,dp);
//         return dp[{W,n}]; //last item taken out
//    }
//    else{ // comparing the maximum value without the last item + with the item
//         dp[{W,n}] = max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1,dp),knapsack(W,wt,val,n-1,dp));
//         return dp[{W,n}] ;

//    }
// }
// int main()
// {
//     int W = 50;
//     int wt[] = {10,20,30};
//     int val[] = {60,100,120};
//     int n =3 ;
//     map<pair<int,int>,int> dp;
//     cout<<knapsack(W,wt,val,n,dp)<<endl;
// }

// chatgpt
//  //tsp using recursion
//  const int INF = INT_MAX; // Infinity value

// // Function to calculate the cost of the minimum Hamiltonian cycle using dynamic programming
// int tspRecursion(int currentCity, int mask, vector<vector<int>>& graph, vector<vector<int>>& memo) {
//     int n = graph.size();

//     // Base case: If all cities have been visited
//     if (mask == (1 << n) - 1) {
//         return graph[currentCity][0]; // Return cost from current city back to the starting city
//     }

//     // Check if the result is already memoized
//     if (memo[currentCity][mask] != -1) {
//         return memo[currentCity][mask];
//     }

//     // Initialize minimum cost to infinity
//     int minCost = INF;

//     // Try visiting all unvisited cities
//     for (int nextCity = 0; nextCity < n; nextCity++) {
//         // Check if the next city is not visited yet
//         if ((mask & (1 << nextCity)) == 0) {
//             int newMask = mask | (1 << nextCity); // Mark next city as visited
//             int currentCost = graph[currentCity][nextCity] + tspRecursion(nextCity, newMask, graph, memo);
//             minCost = min(minCost, currentCost);
//         }
//     }

//     // Memoize the result
//     memo[currentCity][mask] = minCost;

//     return minCost;
// }

// // Function to solve the Traveling Salesman Problem using recursion and dynamic programming
// int solveTSP(vector<vector<int>>& graph) {
//     int n = graph.size();

//     // Create a memoization table
//     vector<vector<int>> memo(n, vector<int>(1 << n, -1));

//     // Start the recursion from the first city (0) and mark it as visited
//     int startCity = 0;
//     int mask = 1; // Start with only the first city visited

//     // Call the recursive function
//     int minCost = tspRecursion(startCity, mask, graph, memo);

//     return minCost;
// }

// int main() {
//     int n = 4; // Number of cities

//     // Create a graph matrix to represent the costs between cities
//     vector<vector<int>> graph = {
//         {0, 20, 42, 25},
//         {20, 0, 30, 34},
//         {42, 30, 0, 10},
//         {25, 34, 10, 0}
//     };

//     // Solve the TSP problem
//     int minCost = solveTSP(graph);

//     cout << "Minimum cost of the Traveling Salesman Problem: " << minCost << endl;

//     return 0;
// }

// n queens
#define N 8
/* print solution */
void printSolution(int board[N][N])
{
     for (int i = 0; i < N; i++)
     {
          for (int j = 0; j < N; j++)
               cout << board[i][j] << " ";
          cout << endl;
     }
}
/* check if a queen can be placed on board[row][col]*/
bool isSafe(int board[N][N], int row, int col)
{
     int i, j;
     for (i = 0; i < col; i++)
     {
          if (board[row][i])
               return false;
     }
     for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
     {
          if (board[i][j])
               return false;
     }
     for (i = row, j = col; j >= 0 && i < N; i++, j--)
     {
          if (board[i][j])
               return false;
     }
     return true;
}
/*solve N Queen problem */
bool solveNQUtil(int board[N][N], int col)
{
     if (col >= N) return true;
     for (int i = 0; i < N; i++)
     {
          if (isSafe(board, i, col))
          {
               board[i][col] = 1;
               if (solveNQUtil(board, col + 1) == true)
                    return true;
               board[i][col] = 0;
          }
     }
     return false;
}
/* solves the N Queen problem using Backtracking.*/
bool solveNQ()
{
     int board[N][N] = {0};
     if (solveNQUtil(board, 0) == false)
     {
          cout << "Solution does not exist" << endl;
          return false;
     }
     printSolution(board);
     return true;
}
// Main
int main()
{
     solveNQ();
     return 0;
}
