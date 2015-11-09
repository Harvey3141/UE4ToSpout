// Copyright(c) 2015, Michael Allar
// All rights reserved.

#include "SpoutPluginPrivatePCH.h"
#include "Core.h"
#include "Engine.h"
#include "RenderCore.h"
#include "TickableObjectRenderThread.h"
#include "AllowWindowsPlatformTypes.h" 
#include "Spout.h"
#include "HideWindowsPlatformTypes.h"
#include <string>

class SpoutSenderObject
{
public:

	void Setup();
	void SetTextureSource(UTextureRenderTarget2D* _texture, FString senderName);
	void Update();
	void Close();
	bool GetbTextureReady() const { return bTextureReady;}

private:

	bool bTextureReady;
	UTextureRenderTarget2D* texture;
	SpoutSender* sender;
	FString senderName;
};


class FSpoutPlugin : public ISpoutPlugin, public FTickableObjectRenderThread
{
public:
	FSpoutPlugin() : FTickableObjectRenderThread(false), SpoutSenderInstance(nullptr), SpoutReceiverInstance(nullptr), SenderSourceTexture(nullptr), bTextureReady(false) {}
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual TStatId GetStatId() const override;

	SpoutSender* SpoutSenderInstance;
	SpoutReceiver* SpoutReceiverInstance;

public:
	//virtual void SetSpoutTextureSource(UTextureRenderTarget2D* SourceTexture) override;
	virtual void SetSpoutTextureSource(TArray<UTextureRenderTarget2D*> SourceTextures) override;

protected:
	UTextureRenderTarget2D* SenderSourceTexture;
	FTickerDelegate TickDelegate;
	//bool HandleTicker(float DeltaTime);
	bool bTextureReady;

	TArray<SpoutSenderObject> SpoutSenders;
};

IMPLEMENT_MODULE( FSpoutPlugin, SpoutPlugin )



void FSpoutPlugin::StartupModule()
{
	SpoutSenders.Empty();

	bTextureReady = false;

#if PLATFORM_WINDOWS
#if PLATFORM_64BITS
	LoadLibraryW(TEXT("../../../Engine/Binaries/ThirdParty/Spout/Win64/Spout.dll"));
#else	//32-bit platform
	LoadLibraryW(TEXT("../../../Engine/Binaries/ThirdParty/Spout/Win32/Spout.dll"));
#endif
#endif	//PLATFORM_WINDOWS


	/*
	SpoutSenderInstance = new SpoutSender;
	//SpoutSenderInstance->SetMemoryShareMode(false);
	//SpoutReceiverInstance->SetDX9(true);

	SenderSourceTexture = NewObject<UTextureRenderTarget2D>();
	SenderSourceTexture->bNeedsTwoCopies = false;
	SenderSourceTexture->InitCustomFormat(800, 600, PF_B8G8R8A8, true);
	SenderSourceTexture->AddToRoot();
	SenderSourceTexture->UpdateResource();

	bTextureReady = true;

	char SenderName[256];
	memset(&SenderName, 0, 256);
	sprintf_s(SenderName, "UE4 Spout Plugin");
	

	if (SpoutSenderInstance->CreateSender(SenderName, 800, 600, 87))
	{
		ENQUEUE_UNIQUE_RENDER_COMMAND_ONEPARAMETER(
			RegisterSpoutPluginTick,
			FSpoutPlugin*, UnregisteredSpoutPlugin, this,
			{
				UnregisteredSpoutPlugin->Register();
			}
		);
	}
	else
	{
		UE_LOG(LogSpout, Error, TEXT("FUCK"));
	}
	*/
	
	ENQUEUE_UNIQUE_RENDER_COMMAND_ONEPARAMETER(
		RegisterSpoutPluginTick,
		FSpoutPlugin*, UnregisteredSpoutPlugin, this,
		{
		UnregisteredSpoutPlugin->Register();
	}
	)

}


//void FSpoutPlugin::ShutdownModule()
//{
//	bTextureReady = false;
//
//	Unregister();
//
//	if (SpoutSenderInstance)
//	{
//		SpoutSenderInstance->ReleaseSender();
//		delete SpoutSenderInstance;
//		SpoutSenderInstance = nullptr;
//	}
//
//	if (SenderSourceTexture)
//	{
//		SenderSourceTexture->RemoveFromRoot();
//		SenderSourceTexture = nullptr;
//	}
//	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
//	// we call this function before unloading the module.
//}

void FSpoutPlugin::ShutdownModule()
{

	Unregister();

	for (int32 Index = 0; Index != SpoutSenders.Num(); ++Index) {
		SpoutSenders[Index].Close();
	}

	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

//void FSpoutPlugin::SetSpoutTextureSource(UTextureRenderTarget2D* SourceTexture)
//{
//	bTextureReady = false;
//
//	if (SpoutSenderInstance)
//	{
//		SpoutSenderInstance->ReleaseSender();
//	}
//
//	if (SenderSourceTexture)
//	{
//		SenderSourceTexture->RemoveFromRoot();
//		SenderSourceTexture = nullptr;
//	}
//	SenderSourceTexture = SourceTexture;
//	if (SenderSourceTexture)
//	{
//		SenderSourceTexture->bNeedsTwoCopies = true;
//		SenderSourceTexture->InitCustomFormat(SenderSourceTexture->GetSurfaceWidth(), SenderSourceTexture->GetSurfaceHeight(), PF_B8G8R8A8, false);
//		SenderSourceTexture->UpdateResource();
//
//		char SenderName[256];
//		memset(&SenderName, 0, 256);
//		sprintf_s(SenderName, "UE4 Spout Plugin");
//
//		if (SpoutSenderInstance->CreateSender(SenderName, SenderSourceTexture->GetSurfaceWidth(), SenderSourceTexture->GetSurfaceHeight(), 87))
//		{
//		}
//		else
//		{
//			UE_LOG(LogSpout, Error, TEXT("FUCK"));
//		}
//
//		bTextureReady = true;
//	}	
//}

void FSpoutPlugin::SetSpoutTextureSource(TArray<UTextureRenderTarget2D*> SourceTextures)
{
	for (int32 Index = 0; Index != SourceTextures.Num(); ++Index) {
		SpoutSenderObject spoutSenderObject;
		spoutSenderObject.Setup();
		FString senderName = "UnityCam" + FString::FromInt(Index+1);
		spoutSenderObject.SetTextureSource(SourceTextures[Index], senderName);
		SpoutSenders.Add(spoutSenderObject);
	}
}

bool FSpoutPlugin::IsTickable() const
{
	for (int32 Index = 0; Index != SpoutSenders.Num(); ++Index) {
		bool ready = SpoutSenders[Index].GetbTextureReady();
	}
	return true;
}

TStatId FSpoutPlugin::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(FSpoutPlugin, STATGROUP_Tickables);
}

/*
void FSpoutPlugin::Tick(float DeltaTime)
{

	if (!bTextureReady)
	{
		return;
	}

	if (SpoutSenderInstance && SenderSourceTexture && SenderSourceTexture->GetRenderTargetResource())
	{
		uint32 width = SenderSourceTexture->GetSurfaceWidth();
		uint32 height = SenderSourceTexture->GetSurfaceHeight();
		uint32 MemSize = width*height * 4;

		uint32 stride = 0;
		void* MipData = GDynamicRHI->RHILockTexture2D(
			SenderSourceTexture->GetRenderTargetResource()->GetRenderTargetTexture(), 0, RLM_ReadOnly, stride, false);
		if (MipData)
		{
			//@TODO: Figure out why sending the MipData directly won't work
			unsigned char* sendOut = new unsigned char[MemSize];
			FMemory::Memcpy(sendOut, MipData, MemSize);
			GDynamicRHI->RHIUnlockTexture2D(SenderSourceTexture->GetRenderTargetResource()->GetRenderTargetTexture(), 0, false);
			SpoutSenderInstance->SendImage(sendOut, width, height, 0x80E1, false, false);
			delete sendOut;
		}
		else
		{
			UE_LOG(LogSpout, Error, TEXT("FUCK"));
		}
	}
}
*/

void FSpoutPlugin::Tick(float DeltaTime)
{
	for (int32 Index = 0; Index != SpoutSenders.Num(); ++Index) {
		SpoutSenders[Index].Update();
	}
}

/////////////////////////////////////////////////////////////////////


void SpoutSenderObject::Setup() {
	sender = new SpoutSender;

	texture = NewObject<UTextureRenderTarget2D>();
	texture->bNeedsTwoCopies = false;
	texture->InitCustomFormat(800, 600, PF_B8G8R8A8, true);
	texture->AddToRoot();
	texture->UpdateResource();

	bTextureReady = true;
}


void SpoutSenderObject::SetTextureSource(UTextureRenderTarget2D* _texture, FString _senderName) {

	bTextureReady = false;

	if (sender)
	{
		sender->ReleaseSender();
	}

	if (sender)
	{
		texture->RemoveFromRoot();
		texture = nullptr;
	}
	texture = _texture;
	if (texture)
	{
		texture->bNeedsTwoCopies = true;
		texture->InitCustomFormat(texture->GetSurfaceWidth(), texture->GetSurfaceHeight(), PF_B8G8R8A8, false);
		texture->UpdateResource();

		char SenderName[256];
		memset(&SenderName, 0, 256);
		std::string cstr(TCHAR_TO_UTF8(*_senderName));
		memcpy(SenderName, cstr.c_str(), cstr.size());
		//sprintf_s(SenderName, cstr);
		senderName = _senderName;

		if (sender->CreateSender(SenderName, texture->GetSurfaceWidth(), texture->GetSurfaceHeight(), 87))
		{
		}
		else
		{
			UE_LOG(LogSpout, Error, TEXT("FUCK"));
		}

		bTextureReady = true;
	}
}

void SpoutSenderObject::Update() {

	if (!bTextureReady)
	{
		return;
	}

	if (sender && texture && texture->GetRenderTargetResource())
	{
		
		uint32 width = texture->GetSurfaceWidth();
		uint32 height = texture->GetSurfaceHeight();
		uint32 MemSize = width*height * 4;

		uint32 stride = 0;
		void* MipData = GDynamicRHI->RHILockTexture2D(
			texture->GetRenderTargetResource()->GetRenderTargetTexture(), 0, RLM_ReadOnly, stride, false);
		if (MipData)
		{
			//@TODO: Figure out why sending the MipData directly won't work
			unsigned char* sendOut = new unsigned char[MemSize];
			FMemory::Memcpy(sendOut, MipData, MemSize);
			GDynamicRHI->RHIUnlockTexture2D(texture->GetRenderTargetResource()->GetRenderTargetTexture(), 0, false);
			sender->SendImage(sendOut, width, height, 0x80E1, false, false);
			delete sendOut;
		}
		else
		{
			UE_LOG(LogSpout, Error, TEXT("FUCK"));
		}
	}
	
}

void SpoutSenderObject::Close() {
	bTextureReady = false;

	if (sender)
	{
		sender->ReleaseSender();
		delete sender;
		sender = nullptr;
	}

	if (texture)
	{
		texture->RemoveFromRoot();
		texture = nullptr;
	}
}

DEFINE_LOG_CATEGORY(LogSpout)


