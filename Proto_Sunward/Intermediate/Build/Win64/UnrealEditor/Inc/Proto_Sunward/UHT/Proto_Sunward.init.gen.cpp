// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProto_Sunward_init() {}
	PROTO_SUNWARD_API UFunction* Z_Construct_UDelegateFunction_AMarker_OnDestroyMarker__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Proto_Sunward;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Proto_Sunward()
	{
		if (!Z_Registration_Info_UPackage__Script_Proto_Sunward.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_AMarker_OnDestroyMarker__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Proto_Sunward",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xBEF789C1,
				0xFFE2C7E5,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Proto_Sunward.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Proto_Sunward.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Proto_Sunward(Z_Construct_UPackage__Script_Proto_Sunward, TEXT("/Script/Proto_Sunward"), Z_Registration_Info_UPackage__Script_Proto_Sunward, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xBEF789C1, 0xFFE2C7E5));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
