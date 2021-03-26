#include <unordered_map>
#include <iostream>
#include "Direction.hpp"
#include "Board.hpp"
using namespace std;
namespace ariel{
void Board::post(unsigned int row,unsigned int col,ariel::Direction direction,string message){
if(message.length()<1){ return;}
if(row<min_row){ min_row=row;}
if(row+1>max_row){ max_row=row+1;}
if (col<min_col){ min_col=col;}
if(col+1>max_col){ max_col=col+1;}
if(direction==Direction::Horizontal){
if(col+message.length()>max_col){ max_col=col+message.length();}
for (unsigned int i = 0; i < message.length(); i++)
{
    board[row][col+i]=message.at(i);
}
}else{
if(row+message.length()>max_row){ max_row=row+message.length();}
for (unsigned int i = 0; i < message.length(); i++)
{
    board[row+i][col]=message.at(i);
}
}
}
string Board::read(unsigned int row,unsigned int col,ariel::Direction direction,unsigned int length){
    string ans;
    if (length<1){ return ans;}
if(direction==Direction::Horizontal){
for (unsigned int i = 0; i < length; i++)
{
    if (board.find(row)==board.end() || board.at(row).find(col+i)==board.at(row).end()){
        ans+="_";
    }
    else{
    ans+=board.at(row).at(col+i);
    }
}
}else{
for (unsigned int i = 0; i < length; i++)
{
    if(board.find(row+i)==board.end() || board.at(row+i).find(col)==board.at(row+i).end()){
        ans+="_";
    }else{
    ans+=board.at(row+i).at(col);
    }
}
}
return ans;
}
void Board::show(){
    for (unsigned int k = min_col; k < max_col; k++)
    {
        if(k==min_col){ std::cout << "  ";}
        std:: cout << " " << k << " ";
    }
    std:: cout << endl;
    for (unsigned int i = min_row; i < max_row; i++)
    {
        std:: cout << i << " ";
        for (unsigned int j = min_col; j < max_col; j++)
        {
            if(board.find(i)==board.end() || board.at(i).find(j)==board.at(i).end()){
                std:: cout<< " " << "_" << " ";
            }else{
                std:: cout<< " " <<board.at(i).at(j) << " ";
            }
        }
            std:: cout << endl;
    }
}
};