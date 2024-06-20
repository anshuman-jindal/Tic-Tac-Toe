#include <bits/stdc++.h>
using namespace std;

char board[3][3] = {{ ' ', ' ', ' ' }, 
                    { ' ', ' ', ' ' }, 
                    { ' ', ' ', ' ' }};

void print(){ 
    cout<<'\n'; 
    for (int i = 0; i < 3; i++) {  
        for (int j = 0; j < 3; j++) { 
            cout << board[i][j]; 
            if(j!=2) cout<<" | ";
        } 
        if(i!=2)
        cout << "\n---------\n"; 
        else cout<<"\n\n";
    } 
} 

int main(){
    string p1, p2;
    cout<<"2-player Tic Tac Toe\n";
    cout<<"Enter the first player's name (first name only)\n";
    cin>>p1;
    if(p1!=" ")
    cout<<p1<< " gets X!\n";
    cout<<"Enter the second player's name (first name only)\n";
    cin>>p2;
    if(p2!=" ")
    cout<<p2<<" gets O!\n";
    cout<<"Note: Enter the numbers in (row, column) format\n";
    bool even=1;
    for(int i=0;i<9; i++){
        char ch;
        if(even){
            cout<<p1<<"'s turn\n";
            ch='X';
        }
        else{
            cout<<p2<<"'s turn\n";
            ch='O';
        }
        string s1, s2;
        cin>>s1;
        if(s1.size()>1 || s1[0]<'0' || s1[0]>'2'){
            cout<<"Enter valid numbers in {0, 1, 2}\n";
            i--;
            continue;
        }
        cin>>s2;
        if(s2.size()>1 || s2[0]<'0' || s2[0]>'2'){
            cout<<"Enter valid numbers in {0, 1, 2}\n";
            i--;
            continue;
        }
        if(board[s1[0]-'0'][s2[0]-'0']!=' '){
            cout<<"Already occupied cell. Retry\n";
            i--;
            continue;
        }
        board[s1[0]-'0'][s2[0]-'0']=ch;
        even=!even;
        print();
        for(int k=0; k<2; k++)
        if(board[0][k]=='X' && board[1][k]=='X' && board[2][k]=='X'){
            cout<<p1<<" wins!\n";
            return 0;
        }
        for(int k=0; k<2; k++)
        if(board[k][0]=='X' && board[k][1]=='X' && board[k][2]=='X'){
            cout<<p1<<" wins!\n";
            return 0;
        }
        if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X'){
            cout<<p1<<" wins!\n";
            return 0;
        }
        if(board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X'){
            cout<<p1<<" wins!\n";
            return 0;
        }

        for(int k=0; k<2; k++)
        if(board[0][k]=='O' && board[1][k]=='O' && board[2][k]=='O'){
            cout<<p2<<" wins!\n";
            return 0;
        }
        for(int k=0; k<2; k++)
        if(board[k][0]=='O' && board[k][1]=='O' && board[k][2]=='O'){
            cout<<p2<<" wins!\n";
            return 0;
        }
        if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O'){
            cout<<p2<<" wins!\n";
            return 0;
        }
        if(board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O'){
            cout<<p1<<" wins!\n";
            return 0;
        }
    }
    cout<<"It's a draw!\n";
}
