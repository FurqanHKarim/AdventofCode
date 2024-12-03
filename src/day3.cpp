#include <iostream>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

int mul(const string& str){
    int number0,number1;
    sscanf_s(str.c_str(),"mul(%d,%d)",&number0,&number1);
    return number0*number1;
}
int part1(){
    freopen("../input/day3.txt","r",stdin);
    string line;
    string delimiter = "mul\\(";
    regex delim("(mul\\([0-9]{1,3},[0-9]{1,3}\\))");
      
    long long result = 0;
    while(getline(cin,line)){
        sregex_token_iterator it(line.begin(),line.end(),delim);
        sregex_token_iterator end;
        
        
        vector<string> tokens(it,end);
        for (auto && it:tokens)
        {
            result+=mul(it);

        }
        
    }
    cout<<result<<endl;
}
int part2(){
    freopen("../input/day3.txt","r",stdin);
    string line;
      
    regex r("(do\\(\\)|don't\\(\\)|mul\\([0-9]{1,3},[0-9]{1,3}\\))");
    long long result = 0;
    bool enabled = true;
    while(getline(cin,line)){
        for (sregex_iterator i = sregex_iterator(line.begin(), line.end(), r); i != sregex_iterator(); ++i) {
            if(i->str() == "do()"){
                enabled = true;
            }else if(i->str() == "don't()"){
                enabled = false;
            }else if(enabled){
                result += mul(i->str());
            }
    }
        
    }
    cout<<result<<endl;
}
int main(){
    part2();
}
//         input.erase(0, pos + delimiter.length());
