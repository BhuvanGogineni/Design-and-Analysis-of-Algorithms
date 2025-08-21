/*Converting recursive programs to non-recursive programs. Towers
of Hanoi Problem example.*/

#include <iostream>
#include <cmath>
using namespace std;

void movingdisk(char src, char dest, int disk){
    cout << "\nDisk " << disk << " moved from " << src << " rod to " << dest << " rod.\n";
} 

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n = 3;
    char strt = 'A', mddle = 'B', end = 'C';
    if(n % 2 == 0){
        swap(&mddle, &end);
    }
    int total_moves = pow(2 , n) - 1;
    for(int i = 1;i <= total_moves; i++){
        if(i % 3 == 0){
            if(i == 3){
                movingdisk(end, mddle, 1);
            }
            if(i == 6){
                movingdisk(mddle, end , 2);
            }
        }
        if(i % 3 == 1){
            if(i == 1){
                movingdisk(strt, end, 1);
            }
            if(i == 4){
                movingdisk(strt, end, 3);
            }
            if(i == 7){
                movingdisk(strt, end, 1);
            }
        }
        if(i % 3 == 2){
            if(i == 2){
                movingdisk(strt, mddle, 2);
            }
            if(i == 5){
                movingdisk(mddle, strt, 1);
            }
        }
    }
    return 0;
}