#pragma once
#include "Observer.h"

	/*! \interface Observable
	* \brief interface a implementer pour devenir observable
	*
	*/
public interface class Observable
{
public:
	virtual void setObserver(Observer^ o);
	virtual void notify(Observer^ o);
};

