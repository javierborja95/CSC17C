/* File:   Play.h
 * Author: Javier B
 * Created on October 20, 12:00 PM
 * Purpose: Class Implementation File for play class
 */

//User Libraries
#include "Play.h"

void Play::play(Game *a){
    //Variables
    win=false;
    unsigned int c; //Temp char
    char   s[SIZE]; //Temp string
    
    //Initialize wheel array
    int *w=new int[WHEEL];
    int statArr[WHEEL]={0,0,5,5,10,15,15,20,25,30,35,40}; //Initialize wheel
    for(int i=0;i<WHEEL;i++){
        w[i]=statArr[i];
    }
    this->w=w;
    
    //Input Data
    Clue temp;
    temp=a->stck.top();
    a->stck.pop();
    this->clue.setCat(temp.getCat());
    this->clue.setPhrase(temp.getPhrase());
    
    //Create a new Phrase
    Phrase p;
    p.setArr(temp.getPhrase());
    
    //Copy Phrase to pointer
    this->p=p;
}

void Play::end(Game *a){
    //Output Data
    if(a->getMoney()<=0){
        cout<<"The phrase was actually: "<<endl;
        cout<<clue.getPhrase()<<endl;
        cout<<"You have no money.\n"
            "You must restart the game to play again"<<endl;
    }else cout<<"Congrats you win!\n"
            "You have $"<<a->getMoney()*10<<".00 left in your account"<<endl;
}

void Play::spin(Game *a){
    //Variables
    int choice=rand()%WHEEL;//Random wheel choice
    char input;             //Letter input
    bool error;             //Incorrect letter input
    bool match=false;       //Did letter match?
    int money=w[choice];    //Money to add or subtract from user's money
    int points=0;           //Counter for points
    bool win=true;
    
    //Input Data
    cout<<"Spinning...\nPress Enter to continue";
    cin.get();
    cout<<"_________________________________________"<<endl;
    if(money==0) cout<<"You spun a free guess"<<endl;
    else cout<<endl<<"You spun $"<<money*10<<".00"<<endl;
    display();
    do{
        try{
            error=false;
            cout<<"What letter do you want to use? ";
            cin>>input;
            cin.ignore();
            
    //Process Data
            if(!isalpha(input)){
                throw "Input must be part of the alphabet";
            }
            input=static_cast<char>(toupper(input)); //Make uppercase
            if(input=='A'||input=='E'||input=='I'||input=='O'||input=='U'){
                throw "You have to buy vowels";
            }
            for(int i=0;i<ALPHA;i++){
                if(k.getChar(i)==input){
                    if(k.isUsed(i)==true){
                        cout<<"You already used that letter"<<endl;
                        return;
                    }else k.use(i);
                }
            }
        }
        catch(char const* s){
            cout<<s<<endl;
            error=true;
            cout<<"Press enter to continue"<<endl;
            cin.get();
        }
    }while(error); //Keep looping until valid input
    for(int i=0;i<p.getSize();i++){
        if(input==p.getLetter(i)){  //If letter matches
            points+=10;             //Add ten points
            match=true;             //Match is true
            p.use(i);               //Don't hide letter anymore
        }
    }
    //Output Data
    if(match){ //If match is true
        cout<<"You have been awarded $"<<money*10<<".00"<<endl;
        a->addMoney(money);
        cout<<"You gain 10 points for each letter guessed"<<endl;
        cout<<"You gained "<<points<<" points"<<endl;
        a->addScore(points);
        for(int i=0;i<p.getSize();i++){
            if(p.getUsed(i)==false){
                win=false;   //Not all letters are revealed, win=false;
            }
        }
        this->win=win;       //All letters of phrase are revealed, win=true
    }else{ //Match is not true
        a->subMoney(money);
        cout<<"_________________________________________"<<endl;
        cout<<"You have lost $"<<money*10<<".00."<<endl;
    }if(a->getMoney()<=0){
        end(a);
    }
    if(this->win==true){
        end(a);
    } 
}

void Play::buy(Game *a){
    //Conditions to return
    if((k.isUsed(0))&&(k.isUsed(4))&&(k.isUsed(8))&&(k.isUsed(14))&&(k.isUsed(20))){
        cout<<"You have already bought all the vowels"<<endl;
        return; //Exit
    }
    if(a->getMoney()<=50){
        cout<<"You don't have enough money!"<<endl;
        cout<<"Spin the wheel or guess the puzzle"<<endl;
        cout<<"Input a key to continue: ";
        cin.get();
        return; //Exit
    }
    
    //Variables
    char input;     //Input for vowel
    bool error;     //Error
    bool win=true;  //Win
    
    //Input Data
    do{
        try{
            error=false;
            cout<<"_________________________________________"<<endl;
            display();
            cout<<"Which vowel do you want to buy? ";
            cin>>input;
            cin.ignore();
            input=static_cast<char>(toupper(input));
            if(input=='A'||input=='E'||input=='I'||input=='O'||input=='U'){

            }
            else{
                throw "You did not choose a vowel";
            }
            for(int i=0;i<ALPHA;i++){
                if(k.getChar(i)==input){
                    if(k.isUsed(i)==true){
                        throw "You already used that letter";
                    }else k.use(i);
                }
            }
        }
        catch(char const* s){
            cout<<s<<endl;
            error=true;
            cout<<"Press enter to continue"<<endl;
            cin.get();
        }
    }while(error==true); //Loop until valid input
    
    //Process Data
    cout<<"You have bought a vowel for $500.00"<<endl;
    a->subMoney(50);              //Subtract money from user
    for(int i=0;i<p.getSize();i++){
        if(p.getLetter(i)==input) //Reveal vowels from clue phrase
            p.use(i);
    }
    for(int i=0;i<p.getSize();i++){
        if(p.getUsed(i)==false){
            win=false;//Not all letters are revealed, win=false;
        }
    }
    if(win==true){    //All letters of phrase are revealed,
        this->win=win;//win=true
        end(a);
    }            
}

void Play::guess(Game *a){
    //Variables
    string answer; //Player answer
    int counter=0; //Amount of empty letters in keyboard array
    int score=30;  //Points=score*counter
    bool win=true;
    
    //Input Data
    display();
    cout<<"Input the final answer: ";
    getline(cin,answer);
    
    //Process Data
    for(int i=0;i<p.getSize();i++){ //Convert to uppercase
        answer[i]=static_cast<char>(toupper(answer[i]));
    }
    for(int i=0;i<p.getSize();i++){
        if((p.getLetter(i))!=(answer[i])){//Check to see if all letters match
            win=false;                    //Phrase did not match answer
        }
    }
    cout<<endl;
    for(int i=0;i<p.getSize();i++){    //Go through phrase array to add
        if((p.getUsed(i))==false){     //points for each letter that is not used
            counter++;
        }
    }
    
    //Output Data
    if(win==true){
        score*=counter;
        cout<<"You gain 30 points for each hidden letter you guessed"<<endl;
        cout<<"You gain "<<score<<" points"<<endl;
        a->addScore(score);
        this->win=win;                 //Make private member win=local win;
        end(a);                        //Go to end
    }else{
        cout<<"You did not guess correctly. You have lost $300.00\n";
        a->subMoney(30);
    }
    if(a->getMoney()<=0){
        end(a);
    }
}

void Play::display(){
    //Output Data
    clue.showCat();
    p.display();
    k.display();
    cout<<endl;
}

void Play::menu(Game *a){
    //Output Data
    cout<<"Your money = $"<<a->getMoney()*10<<".00"<<endl;
    cout<<endl<<endl<<"What would you like to do?"<<endl;
    cout<<  " 1. Spin the Wheel ✪\n"
    " 2. Buy a vowel ($500.00)\n"
    " 3. Solve the Puzzle ✉(Bad guess lose $300.00)\n"<<endl;
}