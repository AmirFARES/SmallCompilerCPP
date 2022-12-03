#include <iostream>
#include <string>
#include<ctype.h>

using namespace std;

//Prototypes
bool IsCompiledInst(string line);
bool IsIdent(string mot);
bool IsNum(string mot);
bool IsSep(string mot);



int main()
{
    string line;
    cout << "give me instruction : ";
    getline(cin, line);
    IsCompiledInst(line);

    // this two line for tests only
    string tempss;
    cin >> tempss;
    return 0;
}



//Functions

bool IsCompiledInst(string line){
    int i=0;
    string temp;
    while(i<line.length()){

        if(line[i]==32){            //if line[i] == space
            if(temp!=""){           //if word not empty
                cout << temp+"                   ";
                if(IsIdent(temp)){
                    cout << "this is an identificateur.";
                }else if(IsNum(temp)){
                    cout << "this is a number.";
                }else{
                    cout << "*syntax error found*";
                    return false;
                }
                cout << "\n";
            }
            temp="";
        }else if((line[i]==58)||(line[i]==59)||(line[i]==44)){
            if(temp!=""){
                cout << temp+"                   ";
                if(IsIdent(temp)){
                    cout << "this is an identificateur.";
                }else if(IsNum(temp)){
                    cout << "this is a number.";
                }else{
                    cout << "*syntax error found*";
                    return false;
                }
                cout << "\n";
            }
            temp="";

            temp+=line[i];
            cout << temp+"                   ";
            cout << "this is a separator.";
            cout << "\n";
            temp="";
        }else{
            temp+=line[i];
        }
        i++;
    }
    if(temp!=""){
        cout << temp+"                   ";
        if(IsIdent(temp)){
            cout << "this is an identificateur.";
        }else if(IsNum(temp)){
            cout << "this is a number.";
        }else{
            cout << "*syntax error found*";
            return false;
        }
        cout << "\n";
    }
    return true;
}

bool IsIdent(string mot){
    if(isalpha(mot[0])!=0){
        for(int i=1;i<mot.length();i++){
            if(!((isalnum(mot[i])!=0)||(mot[i]==95))){
                return false;
            }
        }
    }else{
        return false;
    }
    return true;
}

bool IsNum(string mot){
    if(((mot[0]==43)||(mot[0]==45))&&(mot.length()==1)){
        return false;
    }else if((mot[0]==43)||(mot[0]==45)||(isdigit(mot[0])!=0)){
        for(int i=1;i<mot.length();i++){
            if(isdigit(mot[i])==0){
                return false;
            }
        }
    }else{
        return false;
    }
    return true;
}

bool IsSep(string mot){
    return ((mot[0]==58)||(mot[0]==59)||(mot[0]==44));
}








