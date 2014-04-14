#include "StdAfx.h"
#include "SineWave.h"
#include <cmath>

CSineWave::CSineWave(void)
{
	m_phase = 0;
	m_amp = 0.1;
	m_freq = 440;
}


CSineWave::~CSineWave(void)
{
}

void CSineWave::Start()
{
    m_phase = 0;
}

bool CSineWave::Generate()
{
    m_frame[0] = m_amp * sin(m_phase * 2 * PI);
    m_frame[1] = m_frame[0];

    return true;
}

void CSineWave::UpdatePhase()
{
	m_phase += m_freq * GetSamplePeriod();
}