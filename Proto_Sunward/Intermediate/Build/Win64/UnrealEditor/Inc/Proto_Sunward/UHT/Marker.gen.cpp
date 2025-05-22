// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Proto_Sunward/Public/Damien/Actors/Marker.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMarker() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
PROTO_SUNWARD_API UClass* Z_Construct_UClass_AMarker();
PROTO_SUNWARD_API UClass* Z_Construct_UClass_AMarker_NoRegister();
PROTO_SUNWARD_API UFunction* Z_Construct_UDelegateFunction_AMarker_OnDestroyMarker__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_Proto_Sunward();
// End Cross Module References

// Begin Delegate FOnDestroyMarker
struct Z_Construct_UDelegateFunction_AMarker_OnDestroyMarker__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Damien/Actors/Marker.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_AMarker_OnDestroyMarker__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMarker, nullptr, "OnDestroyMarker__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_AMarker_OnDestroyMarker__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_AMarker_OnDestroyMarker__DelegateSignature_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UDelegateFunction_AMarker_OnDestroyMarker__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_AMarker_OnDestroyMarker__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void AMarker::FOnDestroyMarker_DelegateWrapper(const FMulticastScriptDelegate& OnDestroyMarker)
{
	OnDestroyMarker.ProcessMulticastDelegate<UObject>(NULL);
}
// End Delegate FOnDestroyMarker

// Begin Class AMarker
void AMarker::StaticRegisterNativesAMarker()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMarker);
UClass* Z_Construct_UClass_AMarker_NoRegister()
{
	return AMarker::StaticClass();
}
struct Z_Construct_UClass_AMarker_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Damien/Actors/Marker.h" },
		{ "ModuleRelativePath", "Public/Damien/Actors/Marker.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_onDestroyMarker_MetaData[] = {
		{ "ModuleRelativePath", "Public/Damien/Actors/Marker.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_onDestroyMarker;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UDelegateFunction_AMarker_OnDestroyMarker__DelegateSignature, "OnDestroyMarker__DelegateSignature" }, // 3109250929
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMarker>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AMarker_Statics::NewProp_onDestroyMarker = { "onDestroyMarker", nullptr, (EPropertyFlags)0x0040000000080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMarker, onDestroyMarker), Z_Construct_UDelegateFunction_AMarker_OnDestroyMarker__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_onDestroyMarker_MetaData), NewProp_onDestroyMarker_MetaData) }; // 3109250929
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMarker_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMarker_Statics::NewProp_onDestroyMarker,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMarker_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMarker_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_Proto_Sunward,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMarker_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMarker_Statics::ClassParams = {
	&AMarker::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMarker_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMarker_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMarker_Statics::Class_MetaDataParams), Z_Construct_UClass_AMarker_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMarker()
{
	if (!Z_Registration_Info_UClass_AMarker.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMarker.OuterSingleton, Z_Construct_UClass_AMarker_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMarker.OuterSingleton;
}
template<> PROTO_SUNWARD_API UClass* StaticClass<AMarker>()
{
	return AMarker::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMarker);
AMarker::~AMarker() {}
// End Class AMarker

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_Actors_Marker_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMarker, AMarker::StaticClass, TEXT("AMarker"), &Z_Registration_Info_UClass_AMarker, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMarker), 3205645038U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_Actors_Marker_h_4077288582(TEXT("/Script/Proto_Sunward"),
	Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_Actors_Marker_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_Actors_Marker_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
