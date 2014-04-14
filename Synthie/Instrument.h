#pragma once
#include "AudioNode.h"
#include "Note.h"
#include "resource.h"

class CSynthesizer;

class CInstrument :
	public CAudioNode
{
public:
	CInstrument(void);
	virtual ~CInstrument(void);
	virtual void SetNote(CNote *note) = 0;
	void SetSend(int send, double value);
	double GetSend(int send);
	//virtual void SetMaster(int master);

private:
	double sends[NUM_EFFECTS_BUILD + 1];
};

