#include "StdAfx.h"
#include "GameDicesStd.h"

/*!
* \fn GameDicesStd* GameDicesStd::GameDicesStd_New()
* \brief Fonction de creation d'une nouvelle instance d'un objet GameDicesStd
* \return Instance nouvellement allouee d'un objet de type GameDicesStd
*/
GameDicesStd::GameDicesStd()
{
	 d1 = 0;
	 d2 = 0;
	 maxValue = 6;
	 srand((unsigned int)time(NULL));
}

/*!
* \fn void GameDicesStd::reset()
* \brief remet a zero les 2 des
* \return
*/
void GameDicesStd::reset(){
	d1=0;
	d2=0;
}

/*!
* \fn int GameDicesStd::rollFirstDice()
* \brief lance le premier de
* \return la valeur de d1 apres l'avoir lance
*/
int GameDicesStd::rollFirstDice(){
	d1 = rand() % maxValue + 1;
	return d1;
}

/*!
* \fn int GameDicesStd::rollSecondDice()
* \brief lance le second de
* \return la valeur de d2 apres l'avoir lance
*/
int GameDicesStd::rollSecondDice(){
	d2 = rand() % maxValue + 1;
	return d2;
}

/*!
* \fn int GameDicesStd::getFirstDiceValue()
* \brief donne la valeur du premier de sans le lancer
* \return la valeur de d1
*/
int GameDicesStd::getFirstDiceValue(){
	return d1;
}

/*!
* \fn int GameDicesStd::getFirstSecondValue()
* \brief donne la valeur du second de sans le lancer
* \return la valeur de d2
*/
int GameDicesStd::getSecondDiceValue(){
	return d2;
}

EXTERNC DLL GameDicesStd* GameDicesStd_New(){return new GameDicesStd();}
EXTERNC DLL void GameDicesStd_Delete(GameDicesStd* gd){delete gd;}
