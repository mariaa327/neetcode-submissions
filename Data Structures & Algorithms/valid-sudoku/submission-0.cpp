class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            vector<int> freq(10, 0);
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '0';

                freq[num]++;

                if(freq[num] > 1) return false;
            }
        }

        for(int j = 0; j < 9; j++) {
            vector<int> freq(10, 0);

            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '0';

                freq[num]++;

                if(freq[num] > 1) return false;
            }
        }

        for(int i = 0; i < 9; i+=3) {
            for(int j = 0; j<9; j+=3) {
                vector<int> freq(10, 0);

                for(int row = i; row < i+3; row++) {
                    for(int col = j; col < j+3; col++) {
                        if(board[col][row] == '.') {
                            continue;
                        }

                        int num = board[col][row] - '0';

                        freq[num]++;

                        if(freq[num] > 1) return false;
                    }
                }
            }
        }

        return true;
    }
};


// vector<int> freq(10, 0);

// for (int j = 0; j < 9; j++) {
//     if (board[i][j] == '.')
//         continue;

//     int num = board[i][j] - '0';

//     freq[num]++;

//     if (freq[num] > 1)
//         return false;
// }