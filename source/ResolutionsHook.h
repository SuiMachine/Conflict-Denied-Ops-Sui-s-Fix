static void HookResolutions(DWORD baseAddress, int CustomResolutionX, int CustomResolutionY)
{
	if (CustomResolutionX < 640 || CustomResolutionY < 480)
	{
		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);
		CustomResolutionX = desktop.right;
		CustomResolutionY = desktop.bottom;
	}

	*(DWORD*)(baseAddress + 0x516708) = (DWORD)CustomResolutionX;
	*(DWORD*)(baseAddress + 0x516708 +4) = (DWORD)CustomResolutionY;
}

static void HookFOV(DWORD baseAddress, float desiredFOV)
{
	*(float*)(baseAddress + 0x5180E0) = desiredFOV;			//Actual FOV
	*(double*)(baseAddress + 0x514878) = (double)desiredFOV;
}