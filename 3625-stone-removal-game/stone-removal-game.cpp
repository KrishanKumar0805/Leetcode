class Solution {
public:
    bool canAliceWin(int n) {
        bool chk = false ; int k = 10 ;
        int i = n ;
        while (i > 0){
            if(i <  k) return chk ;
            i-= k ; k-- ; 
            chk = !chk ;
        }
        return chk ;
    }
};