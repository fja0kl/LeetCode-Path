class Solution {
public:
    string intToRoman(int num) {
        //各种可能出现的组合:10以下;100以下;1000以下;4000以下
        string romanPieces[]={"","I","II","III","IV","V","VI","VII","VIII","IX",
                              "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
                              "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
                              "","M","MM","MMM"};
        return romanPieces[num/1000+30]+romanPieces[(num/100)%10+20]
            +romanPieces[(num/10)%10+10]+romanPieces[num%10];
    }
};
