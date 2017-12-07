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

//Execution

int main(int argc, char** argv){
    //Variables
    Game game;        //Wheel of fortune Game object
    char choice;      //Menu choice
    
    //Input Data
    do{
        game.menu();
        cin>>choice;
        cin.ignore();
        cout<<"\n\n\n\n\n";
        
    //Process Data
        switch(choice){
            case'1':{
                game.play();
                break;
            }
            case'2':{
                game.lderBrd();
                break;
            }
            case'3':{
                game.write();
                break;
            }
            case'4':{
                game.read();
                break;
            }
        }
    }while((choice=='1'||choice=='2'||
            choice=='3'||choice=='4'));
    
    //Process Data
    
    return 0;
}