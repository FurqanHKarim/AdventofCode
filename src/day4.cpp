#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <regex>


int part1(const std::vector<std::string> input);
std::vector<std::string> generateVerical(const std::vector<std::string> &inputHorizontal);
std::vector<std::string> generateRDiag(const std::vector<std::string> &inputHorizontal);
std::vector<std::string> generateSDiag(const std::vector<std::string> &inputHorizontal);
int checkXMAS(const std::vector<std::string> input);

int part2(const std::vector<std::string> input);
bool searchX_MAS(const std::vector<std::string> input, int x,int y);


int main(){

    freopen("../input/day4.txt","r",stdin);
    std::string line;
    std::vector<std::string> input;
    while(std::getline(std::cin,line)){
        input.push_back(line);
    }
    std::cout<<part1(input)<<std::endl;
    std::cout<<part2(input)<<std::endl;

    
    
}

int part2(const std::vector<std::string> input){

    int answer = 0;
    for (int i = 1; i < input.size()-1; i++)
    {
        for (int j = 1; j < input[0].length()-1; j++)
        {
            if(input[i][j] == 'A')
                answer += searchX_MAS(input,i,j);
            
        }
        
    }

    return answer;
}

int part1(const std::vector<std::string> input){

    int answer = 0;
    std::vector<std::string> inputVertical = generateVerical(input);
    std::vector<std::string> inputRDiag = generateRDiag(input);
    std::vector<std::string> inputSDiag = generateSDiag(input);
    
    answer += checkXMAS(input);
    answer += checkXMAS(inputVertical);
    answer += checkXMAS(inputRDiag);
    answer += checkXMAS(inputSDiag);

    return answer;
}

bool searchX_MAS(const std::vector<std::string> input, int x,int y){
    char c  = input[x][y];
    if( c != 'A')  
        return false;
    char tl = input[x-1][y-1];
    char tr = input[x-1][y+1];
    char bl = input[x+1][y-1];
    char br = input[x+1][y+1];
    return ((tl=='M'  && br=='S') || (tl=='S'  && br=='M')) && ((tr=='M'  && bl=='S') || (tr=='S'  && bl=='M'));
}

std::vector<std::string> generateVerical(const std::vector<std::string> &inputHorizontal){
    std::vector<std::string> inputVertical;
    for (int i = 0; i < inputHorizontal[0].length(); i++)
    {   
        std::string dummy;
        for (int j = 0; j < inputHorizontal.size(); j++)
        {
            dummy += inputHorizontal[j][i];
        }
        inputVertical.push_back(dummy);
        
    }
    return inputVertical;
}

std::vector<std::string> generateRDiag(const std::vector<std::string> &inputHorizontal){
    std::vector<std::string> inputRDiag;
    int m = inputHorizontal.size(), n = inputHorizontal[0].length();
    for (int col = 0; col < n; col++)
    {
        std::string dummy;
        int i = 0, j = col;
        while(i < m  &&  j < n){
            dummy +=inputHorizontal[i++][j++];
        }
        inputRDiag.push_back(dummy);
    }
    for (int row = 1; row < m; row++)
    {
        std::string dummy;
        int i = row, j = 0;
        while(i < m  &&  j < n){
            dummy +=inputHorizontal[i++][j++];
        }
        inputRDiag.push_back(dummy);
    }

    return inputRDiag;

}

std::vector<std::string> generateSDiag(const std::vector<std::string> &inputHorizontal){
    std::vector<std::string> inputSDiag;
    int m = inputHorizontal.size(), n = inputHorizontal[0].length();
        // Upper diagonals starting from the last column
    for (int col = 0; col < n; col++) {
        std::string dummy;
        int i = 0, j = col;
        while (i < m && j >= 0) {
            dummy += inputHorizontal[i++][j--];
        }
        inputSDiag.push_back(dummy);
    }

    // Lower diagonals starting from the first row (excluding the top-right diagonal)
    for (int row = 1; row < m; row++) {
        std::string dummy;
        int i = row, j = n - 1;
        while (i < m && j >= 0) {
            dummy += inputHorizontal[i++][j--];
        }
        inputSDiag.push_back(dummy);
    }
    return inputSDiag;
}

int checkXMAS(const std::vector<std::string> input){
    int count = 0;
    for (auto &&iteration : input)
    {
        
        std::regex forwardDelim("XMAS");
        for (
            std::sregex_token_iterator it(iteration.begin(),iteration.end(),forwardDelim); 
            it != std::sregex_token_iterator(); it++)
            count++;

        std::regex reversedelim("SAMX");
        for (
            std::sregex_token_iterator it(iteration.begin(),iteration.end(),reversedelim); 
            it != std::sregex_token_iterator(); it++)
            count++;

    }
    return count;


}