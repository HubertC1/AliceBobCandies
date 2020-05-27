#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <int> list;
int j;

int main(){
    int tests; cin >> tests;
    while (tests--){
        list.clear();
        int atot = 0;
        int btot = 0;
        bool breakall = false;
        string turn = "a";
        bool oneele = false;
        bool reseta = true;
        bool resetb = false;
        int prea = 0;
        int preb = 0;
        int moves = 0;
        int num; cin >> num;
        if (num == 1){
            oneele = true;
        }
        while(num--){ 
            int ele; cin>> ele;
            list.push_back(ele);
        }
        if (oneele){
            atot += list[0];
            moves ++;
        }else{
            j = list.size();
            for (int i = 0; i<list.size(); i++){
                if (i==j){
                    break;
                }
                turn = "a";
                if (reseta){
                    moves ++;
                    prea = 0;
                    reseta = false;
                }
                prea += list[i];
                atot += list[i];
                resetb = true;
                while((turn == "a"&&prea>preb)||(turn == "b"&&prea>=preb)){
                    turn = "b";
                    if (resetb){
                        if(j>i+1){
                            moves ++;
                        }
                        preb = 0;
                        resetb = false;
                    }
                    j --;
                    if (j==i){
                        breakall = true;
                        break;
                    }
                    preb += list[j];
                    btot += list[j];
                    reseta = true;
                }
                if (breakall){
                    break;
                }
            }
        }
        cout << endl;
        cout << moves << " " << atot << " " << btot << endl;

    }
}