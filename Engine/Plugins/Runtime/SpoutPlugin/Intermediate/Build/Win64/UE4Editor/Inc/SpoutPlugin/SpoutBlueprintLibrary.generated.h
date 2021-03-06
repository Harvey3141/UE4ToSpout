// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTextureRenderTarget2D;
#ifdef SPOUTPLUGIN_SpoutBlueprintLibrary_generated_h
#error "SpoutBlueprintLibrary.generated.h already included, missing '#pragma once' in SpoutBlueprintLibrary.h"
#endif
#define SPOUTPLUGIN_SpoutBlueprintLibrary_generated_h

#define Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCreateRenderTarget2DWithOneCopy) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Width); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Height); \
		P_FINISH; \
		*(UTextureRenderTarget2D**)Z_Param__Result=USpoutBlueprintLibrary::CreateRenderTarget2DWithOneCopy(Z_Param_Width,Z_Param_Height); \
	} \
 \
	DECLARE_FUNCTION(execSetSpoutSenderTextureSource) \
	{ \
		P_GET_TARRAY(UTextureRenderTarget2D*,Z_Param_SourceTextures); \
		P_FINISH; \
		USpoutBlueprintLibrary::SetSpoutSenderTextureSource(Z_Param_SourceTextures); \
	}


#define Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCreateRenderTarget2DWithOneCopy) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Width); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Height); \
		P_FINISH; \
		*(UTextureRenderTarget2D**)Z_Param__Result=USpoutBlueprintLibrary::CreateRenderTarget2DWithOneCopy(Z_Param_Width,Z_Param_Height); \
	} \
 \
	DECLARE_FUNCTION(execSetSpoutSenderTextureSource) \
	{ \
		P_GET_TARRAY(UTextureRenderTarget2D*,Z_Param_SourceTextures); \
		P_FINISH; \
		USpoutBlueprintLibrary::SetSpoutSenderTextureSource(Z_Param_SourceTextures); \
	}


#define Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUSpoutBlueprintLibrary(); \
	friend SPOUTPLUGIN_API class UClass* Z_Construct_UClass_USpoutBlueprintLibrary(); \
	public: \
	DECLARE_CLASS(USpoutBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, SpoutPlugin, NO_API) \
	DECLARE_SERIALIZER(USpoutBlueprintLibrary) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<USpoutBlueprintLibrary*>(this); }


#define Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesUSpoutBlueprintLibrary(); \
	friend SPOUTPLUGIN_API class UClass* Z_Construct_UClass_USpoutBlueprintLibrary(); \
	public: \
	DECLARE_CLASS(USpoutBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), 0, SpoutPlugin, NO_API) \
	DECLARE_SERIALIZER(USpoutBlueprintLibrary) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<USpoutBlueprintLibrary*>(this); }


#define Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USpoutBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USpoutBlueprintLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USpoutBlueprintLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USpoutBlueprintLibrary); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API USpoutBlueprintLibrary(const USpoutBlueprintLibrary& InCopy); \
public:


#define Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USpoutBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API USpoutBlueprintLibrary(const USpoutBlueprintLibrary& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USpoutBlueprintLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USpoutBlueprintLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USpoutBlueprintLibrary)


#define Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_8_PROLOG
#define Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_RPC_WRAPPERS \
	Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_INCLASS \
	Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_POP


#define Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_INCLASS_NO_PURE_DECLS \
	Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h_11_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SpoutBlueprintLibrary."); \
PRAGMA_POP


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Engine_Plugins_Runtime_SpoutPlugin_Source_SpoutPlugin_Classes_SpoutBlueprintLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
