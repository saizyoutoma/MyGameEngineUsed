#include "Input.h"
#include "DirectXMath.h"


namespace Input
{
	LPDIRECTINPUT8   pDInput = nullptr;
	LPDIRECTINPUTDEVICE8 pKeyDevice = nullptr;
	BYTE keyState[256] = { 0 };
	BYTE prevKeyState[256];    //�O�t���[���ł̊e�L�[�̏��

	LPDIRECTINPUTDEVICE8  pMouseDevice;
	DIMOUSESTATE mouseState;
	DIMOUSESTATE prevMouseState;
	XMVECTOR mousePosition;

	void Initialize(HWND hWnd)
	{
		DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, nullptr);
		
		//�L�[�{�[�h
		pDInput->CreateDevice(GUID_SysKeyboard, &pKeyDevice, nullptr);
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
		pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);

		//�}�E�X
		pDInput->CreateDevice(GUID_SysMouse, &pMouseDevice, nullptr);
		pMouseDevice->SetDataFormat(&c_dfDIMouse);
		pMouseDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	}

	void Update()
	{
		memcpy(prevKeyState, keyState, sizeof(keyState));

		pKeyDevice->Acquire();//�����Ȃ��ƂȂ񂩃L�[�{�[�h�����X���������珑��
		pKeyDevice->GetDeviceState(sizeof(keyState), &keyState);

		pMouseDevice->Acquire();
		memcpy(&prevMouseState, &mouseState, sizeof (mouseState));
		pMouseDevice->GetDeviceState(sizeof(mouseState), &mouseState);
	}

	bool IsKey(int keyCode)
	{
		if (keyState[keyCode] & 128)//�r�b�g�̌v�Z�����Ă��邱�Ƃ��킩��₷���悤�ɂ���Ȃ�16�i���ŏ���
		{
			return true;
		}
		return false;
	}

	bool IsKeyDown(int keyCode)
	{
		//���͉����ĂāA�O��͉����ĂȂ�
		if (!(prevKeyState[keyCode] & 128) && IsKey(keyCode))
		{
			return true;
		}
		return false;
	}

	bool IsKeyUp(int keyCode)
	{
		//���͉����Ă��Ȃ��āA�O��͉����Ă�
		if (prevKeyState[keyCode] & 128 && !IsKey(keyCode))
		{
			return true;
		}
		return false;
	}


	bool IsMouseButton(int buttonCode)
	{
		if (mouseState.rgbButtons[buttonCode] & 0x80)
		{
			return true;
		}
		return false;
	}

	bool IsMouseButtonDown(int buttonCode)
	{
		if (IsMouseButton(buttonCode) && !(prevMouseState.rgbButtons[buttonCode] & 0x80))
		{
			return true;
		}
		return false;
	}

	bool IsMouseButtonUp(int buttonCode)
	{
		if (!(IsMouseButton(buttonCode) && prevMouseState.rgbButtons[buttonCode] & 0x80))
		{
			return true;
		}
		return false;
	}

	

	XMVECTOR GetMousePosition()
	{
		return mousePosition;
	}

	void SetMousePosition(int x, int y)
	{
		mousePosition = XMVectorSet((float)x, (float)y, 0, 0);
	}

	void Release()
	{
		SAFE_RELEASE(pDInput);
		SAFE_RELEASE(pKeyDevice);
		SAFE_RELEASE(pMouseDevice);
	}
}