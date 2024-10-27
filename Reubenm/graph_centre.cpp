#include <bits/stdc++.h>
using namespace std;

// define the size of incidence matrix
#define size 4

// function to check if it is a star graph
//checkStar is function name
//references to an integer center to store the center node if the graph is a star graph
bool checkStar(int mat[][size], int &center)
{
    // initialize number of vertex with deg 1 and n-1
    /*vertexD1 = 0 counts the number of vertices (nodes) in the graph with degree of 1.
	(nodes only connected to the center node)*/
	// vertexDn_1 = 0 is variable counting number of vertices with a degree of size-1(center node)
    int vertexD1 = 0, vertexDn_1 = 0;

    // check for S1(single node graph)
    if (size == 1)
        return (mat[0][0] == 0);

    // check for S2
    if (size == 2)
        return (mat[0][0] == 0 && mat[0][1] == 1 &&
                mat[1][0] == 1 && mat[1][1] == 0);

    // check for Sn (n>2)-more than two nodes
    for (int i = 0; i < size; i++)
    {
        int degreeI = 0;
        for (int j = 0; j < size; j++)
            if (mat[i][j])
                degreeI++;

        if (degreeI == 1)
            vertexD1++;
        else if (degreeI == size - 1)
        {
            vertexDn_1++;
            center = i; // store the center node
        }
    }

    return (vertexD1 == (size - 1) &&//return true if the graph is a star graph
            vertexDn_1 == 1);
}

// calling
int main()
{
    int mat[size][size] = {{0, 1, 1, 1},
                           {1, 0, 0, 0},
                           {1, 0, 0, 0},
                           {1, 0, 0, 0}};

    int center = -1;
    if (checkStar(mat, center))
    {
        cout << "Star Graph\n";
        cout << "Center of the Star Graph is Node: " << center + 1 << endl; // +1 to convert 0-based index to 1-based
    }
    else
    {
        cout << "Not a Star Graph\n";
    }

    return 0;
}