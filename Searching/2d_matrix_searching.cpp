#include<iostream>
#include<vector>

using namespace std;


vector<int> Neive(vector<vector<int>>& matrix, int target) {
    // Q. You have to search in matrix which is sorted by rows & columns(not overall matrix is sorted)

    // we are not using binary search here, this approach is when we have *sorted rows & columns
    // also work for this problem, but this can be done in O(logn + logm)
    // this approach took time: is O(n + m)

    // we start searching from the last column of the first row
    // if that is < target means all the left half always less than target so we do row++
    // if elem > target means our all elem from downside of that column always greater so colmn--

    int row = 0;
    int column = matrix[0].size() - 1;      // column size

    while(row < matrix.size() && column >= 0) {
        if(matrix[row][column] == target)
            return {row, column};

        if(matrix[row][column] < target) 
            row++;

        else 
            column--;
    }

    return {-1, -1};
}

// searach in the row provided between the columns
// parameters are matrix, & in which row your going to search & from what start column to end column 
// your going to search the target
vector<int> binarySearch(vector<vector<int>>& matrix, int row, int cStart, int cEnd, int target) {

    while(cStart <= cEnd) {
        int mid = cStart + (cEnd - cStart) / 2;

        // if elem at the middle of that row1
        if(matrix[row][mid] == target) 
            return {row, mid};

        if(matrix[row][mid] < target)
            cStart = mid + 1;

        else 
            cEnd = mid - 1;
    }

    return {-1, -1};
}
        

vector<int> searchMatrix(vector<vector<int>>& matrix, int target) {
    // approach 2: apply binary search time: O(log(n) + log(m))         
    // ex matrix: target = 3
    //     1 2 3 4
    //     5 6 7 8
    //     9 10 11 12
    //     13 14 15 16

    // we going to preform binary search on middle column(here 1st column is middle(3/2))
    // so middle element is going to be 6
    // so here our mid > target means all further rows contain greater elements so egnore them
    // from this observation we found these cases:
    // if elem == target   return it
    // if elem > target    ignore rows after it
    // if elem < target    ignore rows before it (coz their elem are less than curr elem)

    // this is how we are reducing our search space
    // lower bound is first row(rowStart) & upper bound is last row(rowEnd)

    // at the end only 2 rows will remain
    // check wheather *mid column* you are at contain answer that is [2, 6] (first 2 rows mid column)
    // so in this example,  2 != 3 & 6 != 3 
    // then will going to consider 4 parts 
    // part 1 is left side of 2 
    // part 2 is right side of 2
    // part 3 is left side of 6
    // part 4 is right side of 6
    // these parts are sorted arrays so simple binary search over here

    int rows = matrix.size();
    int cols = matrix[0].size();

    // if there is only 1 row
    if(rows == 1) 
        return binarySearch(matrix, 0, 0, cols-1, target);


    int rowStart = 0;
    int rowEnd = rows - 1;
    int cMid = cols / 2;        // column mid in which we start searching


    // eliminating the rows 
    // run the loop till 2 rows remaining
    while(rowStart < (rowEnd - 1)) {
        int mid = rowStart + (rowEnd - rowStart) / 2;   // this is mid row

        if(matrix[mid][cMid] == target) 
            return {mid, cMid};

        // then eliminate upper rows coz they are containing lower value than mid (sorted matrix)
        if(matrix[mid][cMid] < target)
            rowStart = mid;

        // if mid > target then eliminate lower rows coz they contain higher value than mid
        else
            rowEnd = mid; 
    }

    // now we have 2 rows
    // check wheather target is in the mid col of 2 remaining rows
    // (in example) first check for 2 then check for 6 (mid col mid elems)
    if(matrix[rowStart][cMid] == target)
        return {rowStart, cMid};

    // this is second remaining row (checking 6)
    if(matrix[rowStart + 1][cMid] == target)
        return {rowStart+1, cMid};

    // if target not in middle then check for 4 parts as disscussed

    // we have to check this if cMid out of bound coz we are using [cMid-1]
    // like this case: [[1], [3]] target = 0

    // search in 1st half (left side of cMid) (if 2 > target)
    if(cMid != 0 && matrix[rowStart][cMid - 1] >= target)
        return binarySearch(matrix, rowStart, 0, cMid - 1, target);

    // search in 2nd half (right side of cMid) (if 2 < target)
    // here 1 more condition is it should also less than that same row last elem (4 in example)
    // coz target < cMid can appear in second row right side [7 to 8 in example]
    // another corner case that doing [cMid + 1] can **overflow
    if(cMid != cols - 1 && matrix[rowStart][cMid + 1] <= target && target <= matrix[rowStart][cols-1])
        return binarySearch(matrix, rowStart, cMid + 1, cols - 1, target);

    // search in 3rd half (second row left side of cMid) (if 6 > target)
    if((rowStart != rows - 1) && (cMid != 0) && matrix[rowStart + 1][cMid - 1] >= target)
        return binarySearch(matrix, rowStart + 1, 0, cMid - 1, target);

    // search in 4th half (second row right side of cMid) (if 6 < target)
    if((rowStart != rows - 1) && (cMid != cols - 1) && matrix[rowStart + 1][cMid + 1] <= target)  
        return binarySearch(matrix, rowStart + 1, cMid + 1, cols - 1, target);
    
    return {-1, -1};
}

 
int main()
{
    // this is sorted array
    vector<vector<int>> matrix = {
                                    {1, 3, 5, 7},
                                    {10, 11, 16, 20},
                                    {23, 30, 34, 60}
                                };
    
    // this is only sorted by rows & columns
    // vector<vector<int>> matrix = {
    //                                 {10, 20, 30, 40},
    //                                 {15, 25, 35, 45},
    //                                 {28, 29, 37, 49},
    //                                 {33, 34, 38, 50}
    //                             };

    vector<int> ans(2);

    // Neive time: O(n + m) where n is size of rows & m size of cols
    // this is for when matrix is sorted by rows & by columns
    ans = Neive(matrix, 37);
    cout << "Neive Answer:    " << ans[0] << " " << ans[1] << endl;

    ans = searchMatrix(matrix, 30);
    cout << "Efficient Answer: " << ans[0] << " " << ans[1] << endl;

}