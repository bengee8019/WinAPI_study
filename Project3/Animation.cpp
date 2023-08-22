#include "Stdafx.h"
#include "Animation.h"

int _frameNum;
int _frameWidth;
int _frameHeight;
int _frameNumWidth;
int _frameNumHeight;
float _frameUpdateSec;
float _elapsedSec;

bool _isPlay;
bool _loop;

DWORD _nowPlayIdx;

Animation::Animation(void) : _frameNum(0),
_frameWidth(0),
_frameHeight(0),
_frameNumWidth(0),
_frameNumHeight(0),
_frameUpdateSec(0),
_elapsedSec(0),
_isPlay(false),
_loop(false),
_nowPlayIdx(0)
{
}


HRESULT Animation::init(int totalW, int totalH, int frameW, int frameH)
{
	//가로
	_frameWidth = frameW;
	_frameNumWidth = totalW / _frameWidth;

	//세로
	_frameHeight = frameH;
	_frameNumHeight = totalH / _frameHeight;

	//총 프레임
	_frameNum = _frameNumWidth * _frameNumHeight;

	//오류 방지를 위해 집어넣기 전에 한번 청소 
	_frameList.clear();


	//추가
	for (int i = 0; i < _frameNumHeight; i++)
	{
		for (int j = 0; j < _frameNumWidth; j++)
		{
			POINT framePos;
			framePos.x = j * _frameWidth;
			framePos.y = i * _frameHeight;
			_frameList.push_back(framePos);
		}
	}

	//기본 세팅
	setDefPlayFrame();

	return S_OK;
}

void Animation::release(void)
{
}

//기본 프레임 세팅
void Animation::setDefPlayFrame(bool reverse, bool loop)
{
	_loop = loop;
	_playList.clear();
	if (reverse)
	{
		if (_loop)
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}
			//2는 자연스럽게 조절하자
			for (int i = _frameNum - 2; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}

			for (int i = _frameNum - 2; i >= 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else
	{
		for (int i = 0; i < _frameNum; i++)
		{
			_playList.push_back(i);
		}

	}
}
//원하는 프레임(위치)
void Animation::setPlayFrame(int* playArr, int arrLen, bool loop)
{
	_loop = loop;
	_playList.clear();
	int tmpIdx = *playArr;
	if (_loop)
	{
		for (int i = tmpIdx; i < tmpIdx + arrLen; i++)
		{
			_playList.push_back(i);
		}
		for (int i = tmpIdx + arrLen - 2; i > tmpIdx; i--)
		{
			_playList.push_back(i);
		}
	}
	else
	{
		for (int i = tmpIdx; i < tmpIdx + arrLen; i++)
		{
			_playList.push_back(i);
		}
		for (int i = tmpIdx + arrLen - 2; i >= tmpIdx; i--)
		{
			_playList.push_back(i);
		}
	}
}
//구간 잘라서 재생
void Animation::setPlayFrame(int start, int end, bool reverse, bool loop)
{
	_loop = loop;
	_playList.clear();
	if (reverse)
	{
		if (_loop)
		{
			for (int i = start; i < end; i++)
			{
				_playList.push_back(i);
			}
			for (int i = end - 2; i > start; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			for (int i = start; i < end; i++)
			{
				_playList.push_back(i);
			}
			for (int i = end - 2; i >= start; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else
	{
		for (int i = start; i < end; i++)
		{
			_playList.push_back(i);
		}
	}
}

void Animation::setFPS(int framePerSec)
{
	_frameUpdateSec = (float)framePerSec/1000;
}

void Animation::frameUpdate(float elapsedTime)
{
	if (_isPlay)
	{
		_elapsedSec += elapsedTime;
		if (_elapsedSec >= _frameUpdateSec)
		{
			_elapsedSec -= _frameUpdateSec;

			_nowPlayIdx++;

			if (_nowPlayIdx == _playList.size())
			{
				if (_loop)
				{
					_nowPlayIdx = 0;
				}
				else
				{
					_nowPlayIdx--;
					_isPlay = false;
				}
			}
		}
	}
}

void Animation::AniStart(void)
{
	_isPlay = true;
	_nowPlayIdx = 0;

}

void Animation::AniStop(void)
{
	_isPlay = false;
	_nowPlayIdx = 0;
}

void Animation::AniPause(void)
{
	_isPlay = false;
}

void Animation::AniResume(void)
{
	_isPlay = true;
}
