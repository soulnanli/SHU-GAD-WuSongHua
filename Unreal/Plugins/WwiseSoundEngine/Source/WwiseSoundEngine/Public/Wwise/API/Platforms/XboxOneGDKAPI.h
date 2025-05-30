/*******************************************************************************
The content of this file includes portions of the proprietary AUDIOKINETIC Wwise
Technology released in source code form as part of the game integration package.
The content of this file may not be used without valid licenses to the
AUDIOKINETIC Wwise Technology.
Note that the use of the game engine is subject to the Unreal(R) Engine End User
License Agreement at https://www.unrealengine.com/en-US/eula/unreal
 
License Usage
 
Licensees holding valid licenses to the AUDIOKINETIC Wwise Technology may use
this file in accordance with the end user license agreement provided with the
software or, alternatively, in accordance with the terms contained
in a written agreement between you and Audiokinetic Inc.
Copyright (c) 2025 Audiokinetic Inc.
*******************************************************************************/

#pragma once

#include "CoreMinimal.h"
#include "AkInclude.h"

#include "Wwise/WwiseSoundEngineModule.h"

#if defined(PLATFORM_XBOXONEGDK) && PLATFORM_XBOXONEGDK

class IWwisePlatformAPI
{
public:
	inline static IWwisePlatformAPI* Get()
	{
		IWwiseSoundEngineModule::ForceLoadModule();
		return IWwiseSoundEngineModule::Platform;
	}

	UE_NONCOPYABLE(IWwisePlatformAPI);

protected:
	IWwisePlatformAPI() = default;

public:
	virtual ~IWwisePlatformAPI() {}

	/// Finds the device ID for particular Audio Endpoint.  
	/// \return A device ID to use with AddSecondaryOutput
	virtual AkUInt32 GetDeviceID(IMMDevice* in_pDevice) = 0;

	/// Finds an audio endpoint that matches the token in the device name or device ID and returns and ID compatible with AddSecondaryOutput.  
	/// This is a helper function that searches in the device ID (as returned by IMMDevice->GetId) and IMMXboxDevice->GetPnpId()
	/// If you need to do matching on different conditions, use IMMXboxDeviceEnumerator directly.
	/// \return An ID to use with AddSecondaryOutput.  The ID returned is the device ID as returned by IMMDevice->GetId, hashed by AK::SoundEngine::GetIDFromName()
	virtual AkUInt32 GetDeviceIDFromName(wchar_t* in_szToken) = 0;

	/// Finds the device ID for particular GameInput device.
	/// \return A device ID to use with AddSecondaryOutput
	virtual AkUInt32 GetGameInputDeviceID(const IGameInputDevice* in_pGameInputDevice) = 0;
};

#endif
