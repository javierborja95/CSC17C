/* File:   Game.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Implementation File for Game class
 */

//User Libraries
#include "Game.h"
#include "Play.h"
#include "Tree.h"
#include "RecursiveSorts.h"

Game::Game(){
    //Variables
    int n;          //To hold score and money
    char s[SIZE];   //String to hold phrase
    //Initialize random seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Fill Library
    fill();
    
    //Try to load
    in.open("save.dat",ios::in);
    try{
        if(in.fail()){
            cout<<"No save detected"<<endl;
            throw 0;
        }else{
            if(in>>n){
                cout<<"Save file detected: would you like to continue?"<<endl
                    <<"(Both options will delete the profile, you can save later)\n"
                    <<"1.Continue\n2.New Game(default)"<<endl;
                cin>>s[0];
                cin.ignore();
                if(s[0]=='1'){
                    in.getline(s,SIZE,'.');
                    user.name=s;
                    user.money=n;
                    in>>user.score;
                }else throw 0;

            }else{
                cout<<"No save detected"<<endl;
                throw 0;
            }
        }
    }
    catch(const int &){
        cout<<"Input your name: ";
        getline(cin,user.name);
    }
    cout<<"Welcome to Wheel of Fortune "<<user.name<<"!\n";
    
    //Close istream
    in.close();
    in.clear();
    
    //Clear save
    ofstream out;
    out.open("save.dat",ios::out | ios::trunc);
    out.close();
}

Game::~Game(){
    //Variables
    ofstream out; //Output
    
    //Output Data
    char choice;
    cout<<"Thanks for playing "<<user.name<<"!"<<endl;
    cout<<"Your final score: "<<user.score<<" points"<<endl;
    if(user.money>0){
        cout<<"Do you wish to save?\n1.Save\n2.Exit without saving(default)\n";
        cin>>choice;
        cin.ignore();
    }
    if(choice!='1'||user.money<=0){
        cout<<"\nDo you wish to add your score to the leaderboard?\n"
            "Input 1 to add\n"
            "Input 2 to exit(default): ";
        cin>>choice;
        if(choice=='1') addLder(); //Add to leaderboard
    }else{
        if(user.name.size()==0){
            cout<<"Error: No name"<<endl;
            return;
        }
        out.open("save.dat",ios::out);
        out<<user.money<<user.name<<"."<<user.score;
        out.close();
        cout<<"Your file has been saved"<<endl;
    }
}

void Game::addLder(){
    if(user.name.size()==0){
        cout<<"Error: No name"<<endl;
        return;
    }
    //Variables
    ofstream out; //Output
    int n;       //Size of string
    
    //Output Data
    out.open("users.dat",ios::out|ios::app);
    out<<user.name.size()<<user.name<<user.score<<endl;
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
        
        cout<<"Input sort method:\n1.By score(default)\n2.By name\n";
        cin>>n;
        cin.ignore();
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
            Tree<Player> tree;
            cout<<"Sorted Leaderboard by score:"<<endl;
            set<Player>::iterator p;
            for(p=arr.begin();p!=arr.end();p++){
                tree.insert(*p);
            }
            tree.inorder();
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
    char choice;    //Choice variable
    queue<Clue> que;//Queue of clues
    
    //Open File
    in.clear();
    in.open("phrase.dat",ios::in);
    if(in.fail()){
        cout<<"CRITICAL ERROR: File opening failed"<<endl;
        return;
    }
    cout<<"Choose display option:\n1.Unsorted(default)\n2.Sorted\n";
    cin>>choice;
    cin.ignore();
    
    //Output Data
    if(choice=='2'){
        cout<<"Choose sort option:\n1.Binary tree inorder output(default)\n"
                "2.Recursive Sort\n"
                "3.STL sort\n";
        cin>>choice;
        cin.ignore();
        if(choice=='3'){
            set<Clue>::iterator p;
            for(int i=0;i<7;i++){
                set<Clue> tset;
                in.clear();
                in.seekg(0,ios::beg); //Go back to beginning
                while(in>>n){         //Repeat until in can't extract a char
                    in.getline(s,SIZE,'.');
                    if(n==i+1){
                        clue.setCat(n);
                        clue.setPhrase(s);
                        tset.insert(clue);
                    }
                }
                for(p=tset.begin();p!=tset.end();p++){
                    que.push(*p);
                }
            }
            int a=1,b=1; //Variables for algorthm
            while(!que.empty()){
                clue=que.front();
                que.pop();
                if(clue.getCat()==a){
                    b=clue.getCat();
                }
                if(a==b){ //Algorithm for showing category once
                    cout<<endl;
                    clue.showCat();
                    a++;
                }
                cout<<clue.getPhrase()<<endl;
            }
        }else if(choice=='2'){
            vector<Clue> array;
            in.clear();
            in.seekg(0,ios::beg); //Go back to beginning
            while(in>>n){
                in.getline(s,SIZE,'.');
                clue.setCat(n);
                clue.setPhrase(s);
                array.push_back(clue);
            }
            cout<<"\nChoose type of recursive sort\n"
                  "1. Recursive Bubble(default):\n2. Recursive Insertion:"<<endl;
            cin>>choice;
            cin.ignore();
            if(choice=='2') insertRec(array,array.size());
            else bubbleRec(array,array.size());
            vector<Clue>::iterator p;
            for(p=array.begin();p!=array.end();p++){
                cout<<*p<<endl;
            }
        }else{
            cout<<"Choice 1"<<endl;
            //Variables
            Tree<Clue> tree;
            in.clear();
            in.seekg(0,ios::beg); //Go back to beginning
            while(in>>n){         //Repeat until in can't extract a char
                in.getline(s,SIZE,'.');
                clue.setCat(n);
                clue.setPhrase(s);
                tree.insert(clue);
            }
            tree.inorder();
        }
    }
    else{
        while(in>>n){       //Repeat until in can't extract a char
                in.getline(s,SIZE,'.');
                clue.setCat(n); //Set category
                clue.showCat(); //View category
                cout<<s<<endl;  //Output string
        }
    }
    
    //Input Data  
    in.close();
    cout<<endl<<"Input anything to continue: ";
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
        cout<<endl<<"0 Exit(default)"<<endl;
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
    cout<<"\n\nYour money: $"<<user.money*10<<".00\n"
        "Your score: "<<user.score<<" points\n\n"
        "Select an option below:\n"
        " 1. Begin a new game of Wheel of Fortune\n"
        " 2. View the leaderboard\n"
        " 3. Append to the Library\n"
        " 4. View the Library(You'll spoil all the answers!)\n\n";
    if(user.money>0) cout<<"Any other input to exit and save your progress: ";
    else cout<<"Any other input to exit: ";
}

void Game::play(){
    if(user.money<0){
        cout<<"You have no money. Restart to play again."<<endl;
        return;
    }
    //Variables
    Play obj;       //Play object
    char option;    //Menu option
    obj.play(this); //Start playing
    
    //Input Data
    do{
        obj.display(); //Display hidden phrase and available keyboard letters
        do{
            obj.menu(this); //Display menu
            cin>>option;
            cin.ignore();
            switch(option){
                case'1':
                    obj.spin(this);
                    break;
                case'2':
                    obj.buy(this);
                    break;
                case'3':
                    obj.guess(this);
                    break;
                default: cout<<"ERROR: Bad Input"<<endl;
            }
        }while(option<49||option>51);
    //Loop until win or lose
    }while((obj.getWin()==false)&&(obj.getMoney(this)>0));
}