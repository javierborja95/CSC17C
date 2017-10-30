/* 
 * File:   main.cpp
 * Author: Javier Borja
 * Created on October 20, 12:00 PM
 * Purpose: Wheel of fortune. Player guesses a phrase with category as a clue.
 */

//System Libraries
#include <iostream>   //Input/Output
using namespace std;

//User Libraries
#include "Game.h"
#include "Play.h"

//Global Constants

//Function Prototypes
void play(Game *);

//Execution

int main(int argc, char** argv){
    //Variables
    Game whOfF;       //Wheel of fortune Game object
    Game *ptr=&whOfF; //Pointer to pass Game object
    char choice;      //Menu choice
    
    //Input Data
    do{
        whOfF.menu();
        cin>>choice;
        cin.ignore();
        
    //Process Data
        switch(choice){
            case'1':{
                play(ptr);
                break;
            }
            case'2':{
                whOfF.lderBrd();
                break;
            }
            case'3':{
                whOfF.write();
                break;
            }
            case'4':{
                whOfF.read();
                break;
            }
        }
    }while((choice=='1'||choice=='2'||
            choice=='3'||choice=='4')&&whOfF.getMoney()>0);
    
    //Process Data
    
    return 0;
}

void play(Game *ptr){
    //Variables
    Play game;      //Play object
    char option;    //Menu option
    game.play(ptr); //Start playing
    
    //Input Data
    do{
        game.display(); //Display hidden phrase and available keyboard letters
        do{
            game.menu(ptr); //Display menu
            cin>>option;
            cin.ignore();
            switch(option){
                case'1':
                    game.spin(ptr);
                    break;
                case'2':
                    game.buy(ptr);
                    break;
                case'3':
                    game.guess(ptr);
                    break;
                default: cout<<"ERROR: Bad Input"<<endl;
            }
        }while(option<49||option>51);
    //Loop until win or lose
    }while((game.getWin()==false)&&(game.getMoney(ptr)>0));
}