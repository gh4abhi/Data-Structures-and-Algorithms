// Problem Link - https://practice.geeksforgeeks.org/problems/tic-tac-toe2412/1?page=5&difficulty[]=1&company[]=Amazon&category[]=Arrays&category[]=Strings&sortBy=submissions

#define ll int

class Solution{   
public:
    
    bool win(char ch, char board[9])
    {
        ll check[8][3] = {{0,1,2},{3,4,5},{6,7,8},
            {0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
        for(ll i=0;i<8;i++)
            if(board[check[i][0]]==ch and board[check[i][1]]==ch and board[check[i][2]]==ch)
                return 1;
        return 0;
    }

    bool isValid(char board[9]){
        ll xcount = 0, ocount = 0;
        for(ll i=0;i<9;i++)
        {
            if(board[i]=='X')
                xcount++;
            else if(board[i]=='O')
                ocount++;
        }
        if(xcount==ocount or xcount==ocount+1)
        {
            if(win('O',board))
            {
                if(win('X',board))
                    return false;
                return ocount==xcount;
            }
            if(win('X',board))
                return xcount!=ocount;
            return true;
        }
        return false;
    }
};
