#include<iostream>
#include<queue>
using namespace std;
int main(){
    string str="facfdcad";
    queue<char> q;
    int freq[26]={0};
    for (int i = 0; i < str.length(); i++)
    {
        char ch=str[i];
        freq[ch-'a']++;
        q.push(ch);


        //answer find karo
        while(!q.empty()){
            char frontCharacter =q.front();
            if(freq[frontCharacter-'a']>1){
                //yaani answer nhi hai
                q.pop();
            }
            else{
                //==1 wala case
                //yahi answer hai
                cout<<frontCharacter<<"->";
                break;
            }
        }
        if(q.empty()){
            //it means koi answer nhi nikla
            cout<<"#"<<"->";
        }
    }

    
}