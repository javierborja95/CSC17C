/* File:   Game.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Implementation File for Game class
 */

//User Libraries
#include "Game.h"

Game::Game(){
    //Initialize random seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Fill Library
    fill();
    
    //Input
    cout<<"Input your name: ";
    getline(cin,user.name);
    cout<<"Welcome to Wheel of Fortune "<<user.name<<"!\n";
}

Game::~Game(){
    //Close Files
    in.close();
    
    //Output Data
    char choice;
    cout<<"Thanks for playing "<<user.name<<"!"<<endl;
    cout<<"Your final score: "<<user.score<<" points"<<endl;
    cout<<"Do you wish to add your score to the leaderboard?\n"
            "Input 1 to add\n"
            "Input 2 to exit: ";
    cin>>choice;
    if(choice=='1'){
        addLder(); //Add to leaderboard
    }
}

void Game::addLder(){
    //Variables
    fstream out; //Output in binary
    int n;       //Size of string
    
    //Output Data
    out.open("users.dat",ios::out|ios::app|ios::binary);
    n=user.name.size();
    out.write(reinterpret_cast<char *>(&n),sizeof(n));
    out.write(user.name.c_str(),n);
    out.write(reinterpret_cast<char *>(&user.score),sizeof(unsigned int));
    cout<<"Your score has been added"<<endl;
    
    //Close files
    out.close();
}

void Game::fill(){
    //Variables
    vector<Clue> arr; //Vector that contains clues and category
    unsigned int a;   //Temp char
    Clue temp;        //Temp clue
    char s[SIZE];     //Temp char array
    
    //Open File
    in.open("phrase.dat",ios::in);
    if(in.fail()){
        cout<<"CRITICAL ERROR: File opening failed"<<endl;
        exit(1);
    }
    
    //Input Data
    while(in>>a){
        in.getline(s,SIZE,'.');
        temp.setCat(a);
        temp.setPhrase(s);
        arr.push_back(temp);
    }
    
    //Process Data
    random_shuffle(arr.begin(),arr.end());
    vector<Clue>::iterator p;
    for(p=arr.begin();p!=arr.end();p++){
        this->stck.push(*p);
    }
    
    //Close Files
    in.close();
}

void Game::lderBrd(){
    //Variables
    fstream in;             //Input from file
    int n;                  //Size of string that is read from file
    set<Player,greater<Player>> arr;//Set of Player structures
    Player temp;            //Temp Player for input
    string a;               //Player inputs to continue
    in.clear();
    try{
        //Open files
        in.open("users.dat",ios::in);
        if(in.fail()){
            throw "users.dat not found";
        }
        //Input Data
        while(in>>n){ //Get size of string
            temp.name.resize(n);     //Resize string size to n
            in.read(&temp.name[0],n);//In name string of size n
            in>>temp.score;
            arr.insert(temp);
        }
        
        cout<<"Input sort method:\n1.By score\n2.By name\n";
        cin>>n;
        cin.clear();
        //Output Data
        if(n==2){
            vector<Player> a(arr.begin(),arr.end());
            sort(a.begin(),a.end(),name_sort());
            cout<<"Sorted Leaderboard by name:"<<endl;
            vector<Player>::iterator p;
            for(p=a.begin();p!=a.end();p++){
                cout<<p->name;
                cout<<setw(5)<<right<<p->score<<" points"<<endl<<endl;
            }
        }else{
            cout<<"Sorted Leaderboard by score:"<<endl;
            set<Player>::iterator p;
            for(p=arr.begin();p!=arr.end();p++){
                cout<<p->name;
                cout<<setw(5)<<right<<p->score<<" points"<<endl<<endl;
            }
        }
        cout<<"Press enter to continue"<<endl;
        getline(cin,a);
    }
    catch(char* const s){
        in.close();
        cout<<s<<endl;
    }
    
    
    //Close files
    in.close();
}

void Game::read(){
    //Variables
    Clue clue;      //Temporary Clue to fill
    unsigned int n; //Categories are numbered
    char s[SIZE];   //String to hold phrase
    
    //Open File
    in.clear();
    in.open("phrase.dat",ios::in);
    if(in.fail()){
        cout<<"CRITICAL ERROR: File opening failed"<<endl;
        return;
    }
    
    //Input Data
    while(in>>n){          //Repeat until in can't extract a char
        in.getline(s,SIZE,'.');
        
    //Output Data
        clue.setCat(n); //Set category
        clue.showCat(); //View category
        cout<<s<<endl;  //Output string
    }
    
    in.close();
    cout<<"Input anything to continue: ";
    cin.get();
}

void Game::write(){
    //Variables
    char choice;    //Menu choice
    char input;     //Input for sub-menu
    fstream out;    //Output to file
    char line[SIZE];//Character array of size=44
    Clue clue;
    
    //Open File
    out.open("phrase.dat",ios::app);
    
    //Input Data
    cout<<endl<<"Input 1 to input a phrase\n"
            "Input 0 to exit: ";
    cin>>choice;
    cin.ignore();
    if(choice=='1'){
        cout<<endl<<"Input a category:\n";
        for(int i=1;i<=7;i++){
            cout<<i<<" ";
            clue.setCat(i);
            clue.showCat();
        }
        cout<<endl<<"0 Exit"<<endl;
        cin>>input;
        cin.ignore();
        
    //Output Data
        if(input>48&&input<56){ //If input is '1'-'7'
            clue.setCat(input-48);
            cout<<"Input your phrase(max 44 characters): "<<endl;
            cin.getline(line,SIZE);
            if(isGood(line)){ //If input is good ask if wish to append
                cin>>choice;
                cin.ignore();
                if(choice=='1'){
                    out<<input;
                    for(int i=0;i<strlen(line);i++){
                        out<<static_cast<char>(toupper(line[i])); //Make uppercase
                    }
                    out<<"."<<endl;
                    cout<<"You must restart the game for effects to take effect"<<endl;
                }
            }
        }
    }
    
    //Close File
    out.close();
}

bool Game::isGood(char a[]){
    //Process Data
    try{
        if(strlen(a)<4||strlen(a)>44){ //If char array doesn't fit size limit
            throw "ERROR: Phrase must be greater than 3 characters and less than 44";
        }
        for(int i=0;i<strlen(a);i++){
            if(isdigit(a[i])||(!isalpha(a[i])&&!isspace(a[i]))){//If not space or letter
                throw "ERROR: Input must be characters only\n";
            }
        }

    //Output Data
        cout<<"Do you really wish to add the following phrase?"<<endl;
        for(int i=0;i<strlen(a);i++){
            cout<<static_cast<char>(toupper(a[i]));
        }
        cout<<endl<<endl<<"Input 1 to append\n"
                "Or anything else to cancel: ";
        return true;
    }
    
    //Catch errors
    catch(char const* s){
        cout<<s<<endl;
        return false;
    }
}

void Game::menu(){
    //Output Data
    cout<<"Your money: $"<<user.money*10<<".00\n"
        "Your score: "<<user.score<<" points\n\n"
        "Select an option below:\n"
        " 1. Begin a new game of Wheel of Fortune\n"
        " 2. View the leaderboard\n"
        " 3. Append to the Library\n"
        " 4. View the Library(You'll spoil all the answers!)\n\n"
        "Any other input to exit: ";
}