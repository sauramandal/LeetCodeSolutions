// Solution - To run this file include headers, main() & util functions
bool isOnPerimeter(int i, int j, int rows, int cols) {
    return (i == 0 || j == 0 || i == rows - 1 || j == cols - 1);
}

// -1 -> Visited
// 1 -> Water
// 0 -> Land
bool isClosedIsland(int **grid, int i, int j, int rows, int cols) {
    if(grid[i][j] == -1 || grid[i][j] == 1) return true;
    if(isOnPerimeter(i, j, rows, cols))
        return false;
    //If we are good, traverse matrix in 4 directions
    grid[i][j] = -1; //visit current elem & mark it as visited
    bool left = isClosedIsland(grid, i, j-1, rows, cols);
    bool right = isClosedIsland(grid, i, j+1, rows, cols);
    bool up = isClosedIsland(grid, i-1, j, rows, cols);
    bool down = isClosedIsland(grid, i+1, j, rows, cols);
    return left && right && up && down;
}

int closedIsland(int** grid, int gridSize, int* gridColSize){
    if(gridSize == 0) return 0;
    int rows = gridSize, cols = *gridColSize;
    int countClosedIslands = 0;
    // Loop through the subset of matrix, leaving the perimeter 
    for(int i=1 ; i<rows-1; i++) {
        for(int j=1; j<cols-1; j++) {
            // If its a land
            if(grid[i][j] == 0) 
                if(isClosedIsland(grid, i, j, rows, cols))
                    countClosedIslands++;
            
        }
    }
    return countClosedIslands;
}

// Time Complexity: O(rows * cols)

