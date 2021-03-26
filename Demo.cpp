#include <iostream>
#include <string>
#include "Board.hpp"
#include "Direction.hpp"

int main(){
    ariel::Board b;
    b.post(0,0,ariel::Direction::Horizontal,"Hello");
 //   b.post(2,2,ariel::Direction::Horizontal,"Hello");
    std:: cout << b.read(0,0,ariel::Direction::Horizontal,8) << endl;    
    b.show();
    return 0;
}