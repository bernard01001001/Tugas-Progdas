#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> username;
vector<string> password;
char upper[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char lower[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char spcChar[]={'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', ']', '{', '}', '/', '\\', ',', '.', '\'', '"', ';', ':', '?'};
char num[]={'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
string tempUser;
string tempPass;
int choice=1;

class Myclass{
  public:
  string passCheck(string tempPass){
    bool checkUpper=false;
    bool checkLower=false;
    bool checkSpcChar=false;
    bool checkNum=false;
    
    for(char c:tempPass){
      for(auto j:upper){
        if(c==j){
          checkUpper=true;
        }
      }
      for(auto j:lower){
        if(c==j){
          checkLower=true;
        }
      }
      for(auto j:spcChar){
        if(c==j){
          checkSpcChar=true;
        }
      }
      for(auto j:num){
        if(c==j){
          checkNum=true;
        }
      }
      
    }
    if(checkUpper==true && checkLower==true && checkSpcChar==true && checkNum==true){
      username.push_back(tempUser);
      password.push_back(tempPass);
      return "registered successfully!";
    }
    else{
      return "password not strong enough";
    }

  }
};
void login(string tempUser, string tempPass){
    for(int i=0; i<username.size();i++){
      if(tempPass==password[i] && tempUser==username[i]){
        cout<<"logged in successfully"<<endl;
        break;
      }
      else{
        cout<<"login invalid"<<endl;
      }
    }
}
int main(){
  myclass obj;
  while(choice<=2 && choice>=1){
    cout<<"1. register"<<endl;
    cout<<"2. login"<<endl;
    cout<<"3. exit"<<endl;
    cin>>choice;
    
    if(choice<=2 && choice>=1){
      cout<<"username: "<<endl;
      cin>>tempUser;
      cout<<"password: "<<endl;
      cin>>tempPass;
      if(choice == 1){
        while(obj.passCheck(tempPass)=="password not strong enough"){
          cout<< obj.passCheck(tempPass)<<endl;
          cin>>tempPass;
        }
        cout<<obj.passCheck(tempPass)<<endl;
      }
      else if(choice == 2){
        login(tempUser, tempPass);
      }
    }
  }
  return 0;
}
