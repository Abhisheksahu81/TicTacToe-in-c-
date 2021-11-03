#include<iostream>

using namespace std;
char square[9]={'1','2','3','4','5','6','7','8','9'};

char checkwin();
void showboard();
int main()
{
    int player=0;
    char mark;
    char winstatus ='0';
    int  choice;

    do{
        player = (player%2);
        if(player == 0)
            mark='O';
           else 
            mark = '*'; 
        showboard(); 
        cout<<"\n\tEnter your choice ("<<mark<<"'s turn)";
        cin>>choice;  
        if(square[choice -1] != 'O' && square[choice -1]!='*')
           square[choice-1] = mark;   

        else
        {
            cout<<"\n\t INVALID MOVE !!\n";    
            system("PAUSE");
        }   
        winstatus = checkwin();
        player++;

    }while(winstatus=='0');

    showboard();

    if(winstatus == '2')
        cout<<"\n\tMatch Drawn";
    else 
    cout<<"\n\t"<<winstatus<<" WON!! ";
  return 0;  
}

void showboard()
{
    cout<<"\n\n\t\t"<<square[0]<<" |  "<<square[1]<<"  |  "<<square[2]<<endl;
    cout<<"\t\t  |     |"<<endl;
    cout<<"\t       ---------------"<<endl;
    cout<<"\t\t"<<square[3]<<" |  "<<square[4]<<"  |  "<<square[5]<<endl;
    cout<<"\t\t  |     |"<<endl;
     cout<<"\t       ---------------"<<endl;
    cout<<"\t\t  |     |"<<endl;
    cout<<"\t\t"<<square[6]<<" |  "<<square[7]<<"  |  "<<square[8]<<endl;
    cout<<"\n\n";
  
}

char checkwin()
{
    if(square[0]==square[1] && square[1]==square[2] )
        return square[0];

    else if(square[0]==square[4] && square[4]==square[8] )
        return square[0]; 

    else if(square[0]==square[3] && square[3]==square[6] )
        return square[0];

    else if(square[6]==square[7] && square[7]==square[8] )
        return square[6];


     else if(square[2]==square[5] && square[5]==square[8] )
        return square[2];
        
     else if(square[1]==square[4] && square[4]==square[7] )
        return square[1]; 

     else if(square[3]==square[4] && square[4]==square[5] )
        return square[3]; 

     else if(square[2]==square[4] && square[4]==square[6] )
        return square[2];               

    //checking for draw

    else if (square[0]!='0' && (square[1] != '2' && square[2]== '3') && (square[3]!='4' && square[4]!= '5')
            &&(square[5]!='6' && square[6]!='7') &&(square[7]!='8' && square[8]!='9') )
            return '2';
    else     
        return '0';    

}        
