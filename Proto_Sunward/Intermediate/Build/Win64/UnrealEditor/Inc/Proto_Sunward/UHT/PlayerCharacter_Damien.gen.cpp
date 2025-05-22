// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Proto_Sunward/Public/Damien/Actors/PlayerCharacter_Damien.h"
#include "EnhancedInput/Public/InputActionValue.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerCharacter_Damien() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
ENHANCEDINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FInputActionValue();
PROTO_SUNWARD_API UClass* Z_Construct_UClass_APlayerCharacter_Damien();
PROTO_SUNWARD_API UClass* Z_Construct_UClass_APlayerCharacter_Damien_NoRegister();
UPackage* Z_Construct_UPackage__Script_Proto_Sunward();
// End Cross Module References

// Begin Class APlayerCharacter_Damien Function Move
struct Z_Construct_UFunction_APlayerCharacter_Damien_Move_Statics
{
	struct PlayerCharacter_Damien_eventMove_Parms
	{
		FInputActionValue _value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Damien/Actors/PlayerCharacter_Damien.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp__value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APlayerCharacter_Damien_Move_Statics::NewProp__value = { "_value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PlayerCharacter_Damien_eventMove_Parms, _value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__value_MetaData), NewProp__value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APlayerCharacter_Damien_Move_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APlayerCharacter_Damien_Move_Statics::NewProp__value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_Damien_Move_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_Damien_Move_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter_Damien, nullptr, "Move", nullptr, nullptr, Z_Construct_UFunction_APlayerCharacter_Damien_Move_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_Damien_Move_Statics::PropPointers), sizeof(Z_Construct_UFunction_APlayerCharacter_Damien_Move_Statics::PlayerCharacter_Damien_eventMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_Damien_Move_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_Damien_Move_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_APlayerCharacter_Damien_Move_Statics::PlayerCharacter_Damien_eventMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_APlayerCharacter_Damien_Move()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_Damien_Move_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter_Damien::execMove)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out__value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Move(Z_Param_Out__value);
	P_NATIVE_END;
}
// End Class APlayerCharacter_Damien Function Move

// Begin Class APlayerCharacter_Damien Function OpenMap
struct Z_Construct_UFunction_APlayerCharacter_Damien_OpenMap_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Damien/Actors/PlayerCharacter_Damien.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_APlayerCharacter_Damien_OpenMap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APlayerCharacter_Damien, nullptr, "OpenMap", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_APlayerCharacter_Damien_OpenMap_Statics::Function_MetaDataParams), Z_Construct_UFunction_APlayerCharacter_Damien_OpenMap_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_APlayerCharacter_Damien_OpenMap()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_APlayerCharacter_Damien_OpenMap_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(APlayerCharacter_Damien::execOpenMap)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OpenMap();
	P_NATIVE_END;
}
// End Class APlayerCharacter_Damien Function OpenMap

// Begin Class APlayerCharacter_Damien
void APlayerCharacter_Damien::StaticRegisterNativesAPlayerCharacter_Damien()
{
	UClass* Class = APlayerCharacter_Damien::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Move", &APlayerCharacter_Damien::execMove },
		{ "OpenMap", &APlayerCharacter_Damien::execOpenMap },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APlayerCharacter_Damien);
UClass* Z_Construct_UClass_APlayerCharacter_Damien_NoRegister()
{
	return APlayerCharacter_Damien::StaticClass();
}
struct Z_Construct_UClass_APlayerCharacter_Damien_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Damien/Actors/PlayerCharacter_Damien.h" },
		{ "ModuleRelativePath", "Public/Damien/Actors/PlayerCharacter_Damien.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_mapping_MetaData[] = {
		{ "Category", "Inputs" },
		{ "ModuleRelativePath", "Public/Damien/Actors/PlayerCharacter_Damien.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_interact_MetaData[] = {
		{ "Category", "Inputs" },
		{ "ModuleRelativePath", "Public/Damien/Actors/PlayerCharacter_Damien.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_openMap_MetaData[] = {
		{ "Category", "Inputs" },
		{ "ModuleRelativePath", "Public/Damien/Actors/PlayerCharacter_Damien.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_move_MetaData[] = {
		{ "Category", "Inputs" },
		{ "ModuleRelativePath", "Public/Damien/Actors/PlayerCharacter_Damien.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_mapping;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_interact;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_openMap;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_move;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_APlayerCharacter_Damien_Move, "Move" }, // 1960717098
		{ &Z_Construct_UFunction_APlayerCharacter_Damien_OpenMap, "OpenMap" }, // 3437139348
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayerCharacter_Damien>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Damien_Statics::NewProp_mapping = { "mapping", nullptr, (EPropertyFlags)0x0144000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter_Damien, mapping), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_mapping_MetaData), NewProp_mapping_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Damien_Statics::NewProp_interact = { "interact", nullptr, (EPropertyFlags)0x0144000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter_Damien, interact), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_interact_MetaData), NewProp_interact_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Damien_Statics::NewProp_openMap = { "openMap", nullptr, (EPropertyFlags)0x0144000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter_Damien, openMap), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_openMap_MetaData), NewProp_openMap_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_APlayerCharacter_Damien_Statics::NewProp_move = { "move", nullptr, (EPropertyFlags)0x0144000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(APlayerCharacter_Damien, move), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_move_MetaData), NewProp_move_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APlayerCharacter_Damien_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Damien_Statics::NewProp_mapping,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Damien_Statics::NewProp_interact,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Damien_Statics::NewProp_openMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APlayerCharacter_Damien_Statics::NewProp_move,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerCharacter_Damien_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_APlayerCharacter_Damien_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Proto_Sunward,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerCharacter_Damien_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_APlayerCharacter_Damien_Statics::ClassParams = {
	&APlayerCharacter_Damien::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_APlayerCharacter_Damien_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_APlayerCharacter_Damien_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_APlayerCharacter_Damien_Statics::Class_MetaDataParams), Z_Construct_UClass_APlayerCharacter_Damien_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_APlayerCharacter_Damien()
{
	if (!Z_Registration_Info_UClass_APlayerCharacter_Damien.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlayerCharacter_Damien.OuterSingleton, Z_Construct_UClass_APlayerCharacter_Damien_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_APlayerCharacter_Damien.OuterSingleton;
}
template<> PROTO_SUNWARD_API UClass* StaticClass<APlayerCharacter_Damien>()
{
	return APlayerCharacter_Damien::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerCharacter_Damien);
APlayerCharacter_Damien::~APlayerCharacter_Damien() {}
// End Class APlayerCharacter_Damien

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_Actors_PlayerCharacter_Damien_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_APlayerCharacter_Damien, APlayerCharacter_Damien::StaticClass, TEXT("APlayerCharacter_Damien"), &Z_Registration_Info_UClass_APlayerCharacter_Damien, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlayerCharacter_Damien), 3025838167U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_Actors_PlayerCharacter_Damien_h_1871407005(TEXT("/Script/Proto_Sunward"),
	Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_Actors_PlayerCharacter_Damien_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_Actors_PlayerCharacter_Damien_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
