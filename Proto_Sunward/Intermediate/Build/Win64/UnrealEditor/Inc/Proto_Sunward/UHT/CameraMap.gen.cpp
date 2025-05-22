// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Proto_Sunward/Public/Dalien/Actors/CameraMap.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCameraMap() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
PROTO_SUNWARD_API UClass* Z_Construct_UClass_ACameraMap();
PROTO_SUNWARD_API UClass* Z_Construct_UClass_ACameraMap_NoRegister();
UPackage* Z_Construct_UPackage__Script_Proto_Sunward();
// End Cross Module References

// Begin Class ACameraMap Function Interaction
struct Z_Construct_UFunction_ACameraMap_Interaction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Dalien/Actors/CameraMap.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACameraMap_Interaction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACameraMap, nullptr, "Interaction", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACameraMap_Interaction_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACameraMap_Interaction_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ACameraMap_Interaction()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACameraMap_Interaction_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ACameraMap::execInteraction)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Interaction();
	P_NATIVE_END;
}
// End Class ACameraMap Function Interaction

// Begin Class ACameraMap
void ACameraMap::StaticRegisterNativesACameraMap()
{
	UClass* Class = ACameraMap::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Interaction", &ACameraMap::execInteraction },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACameraMap);
UClass* Z_Construct_UClass_ACameraMap_NoRegister()
{
	return ACameraMap::StaticClass();
}
struct Z_Construct_UClass_ACameraMap_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Dalien/Actors/CameraMap.h" },
		{ "ModuleRelativePath", "Public/Dalien/Actors/CameraMap.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mapping_MetaData[] = {
		{ "Category", "Inputs" },
		{ "ModuleRelativePath", "Public/Dalien/Actors/CameraMap.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_interact_MetaData[] = {
		{ "Category", "Inputs" },
		{ "ModuleRelativePath", "Public/Dalien/Actors/CameraMap.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_mapping;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_interact;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ACameraMap_Interaction, "Interaction" }, // 1441121180
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACameraMap>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACameraMap_Statics::NewProp_mapping = { "mapping", nullptr, (EPropertyFlags)0x0144000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACameraMap, mapping), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mapping_MetaData), NewProp_mapping_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACameraMap_Statics::NewProp_interact = { "interact", nullptr, (EPropertyFlags)0x0144000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACameraMap, interact), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_interact_MetaData), NewProp_interact_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACameraMap_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACameraMap_Statics::NewProp_mapping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACameraMap_Statics::NewProp_interact,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACameraMap_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ACameraMap_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_Proto_Sunward,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACameraMap_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ACameraMap_Statics::ClassParams = {
	&ACameraMap::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ACameraMap_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ACameraMap_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACameraMap_Statics::Class_MetaDataParams), Z_Construct_UClass_ACameraMap_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ACameraMap()
{
	if (!Z_Registration_Info_UClass_ACameraMap.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACameraMap.OuterSingleton, Z_Construct_UClass_ACameraMap_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ACameraMap.OuterSingleton;
}
template<> PROTO_SUNWARD_API UClass* StaticClass<ACameraMap>()
{
	return ACameraMap::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ACameraMap);
ACameraMap::~ACameraMap() {}
// End Class ACameraMap

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Dalien_Actors_CameraMap_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ACameraMap, ACameraMap::StaticClass, TEXT("ACameraMap"), &Z_Registration_Info_UClass_ACameraMap, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACameraMap), 2889235915U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Dalien_Actors_CameraMap_h_303413005(TEXT("/Script/Proto_Sunward"),
	Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Dalien_Actors_CameraMap_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Dalien_Actors_CameraMap_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
