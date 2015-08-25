#pragma once
#pragma comment(lib,"DllModeleCpp.lib")
#include "..\DllModeleCpp\ImplementationStd\GameDicesStd.h"
#include "Observer\Observable.h"
#include "Observer\Observer.h"

namespace mWrapper {

	public ref class WrapperDices : Observable
	{
	private:
		GameDicesStd* dices;	/*!< Des*/
		Observer^ observer;		/*!< Observer*/
		bool observerSet;		/*!< Indique si un observer a ete defini*/

	public:
		/*!
		* \fn WrapperDices* WrapperDices()
		* \brief Instancie l'objet C++ correspondant
				* \return Instance nouvellement allouee d'un objet de type WrapperDices
		*/
		WrapperDices(){
			observerSet = false;
			dices = GameDicesStd_New();
		}

		/*!
		* \fn WrapperDices()
		* \brief ~Detruit l'objet C++ correspondant
				* \return
		*/
		~WrapperDices(){
				GameDicesStd_Delete(dices);
		}

		/*!
		* \fn void setObserver(Observer^ o)
		* \brief definit un observer
		* \param Observer^ o
		* \return
		*/
		virtual void setObserver(Observer^ o){
			observer = o;
			observerSet = true;
		}

		/*!
		* \fn void notify(Observer^ o)
		* \brief notifie l'observer o
		* \param Observer^ o
		* \return
		*/
		virtual void notify(Observer^ o){
			if (observerSet)
			o->update();
		}

		/*!
		* \fn void reset()
		* \brief remet a zero les des
				* \return
		*/
		void reset(){
			dices->reset();
			notify(observer);
		}

		/*!
		* \fn int rollFirstDice()
		* \brief lance le premier de
				* \return int resultat du de
		*/
		int rollFirstDice(){
			int res = dices->rollFirstDice();
			notify(observer);
			return res;
		}

		/*!
		* \fn int rollSecondDice()
		* \brief lance le second de
				* \return int resultat du de
		*/
		int rollSecondDice(){
			int res = dices->rollSecondDice();
			notify(observer);
			return res;
		}

		/*!
		* \fn int getFirstDiceValue()
		* \brief donne le de sans le lancer
				* \return int valeur du de
		*/
		int getFirstDiceValue(){
			return dices->getFirstDiceValue();
		}

		/*!
		* \fn int getFirstDiceValue()
		* \brief donne le de sans le lancer
				* \return int valeur du de
		*/
		int getSecondDiceValue(){
			return dices->getSecondDiceValue();
		}
	
	protected:
		/*!
		* \fn !WrapperDices()
		* \brief Destructeur
				* \return
		*/
		!WrapperDices(){
			GameDicesStd_Delete(dices);
		}
	};
	
}

