// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Proto_Sunward/Public/Damien/UI/MarkerButton.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMarkerButton() {}

// Begin Cross Module References
PROTO_SUNWARD_API UClass* Z_Construct_UClass_AMarker_NoRegister();
PROTO_SUNWARD_API UClass* Z_Construct_UClass_UMarkerButton();
PROTO_SUNWARD_API UClass* Z_Construct_UClass_UMarkerButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Proto_Sunward();
// End Cross Module References

// Begin Class UMarkerButton Function DestroyMark
struct Z_Construct_UFunction_UMarkerButton_DestroyMark_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Damien/UI/MarkerButton.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMarkerButton_DestroyMark_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMarkerButton, nullptr, "DestroyMark", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMarkerButton_DestroyMark_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMarkerButton_DestroyMark_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMarkerButton_DestroyMark()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMarkerButton_DestroyMark_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMarkerButton::execDestroyMark)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DestroyMark();
	P_NATIVE_END;
}
// End Class UMarkerButton Function DestroyMark

// Begin Class UMarkerButton
void UMarkerButton::StaticRegisterNativesUMarkerButton()
{
	UClass* Class = UMarkerButton::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "DestroyMark", &UMarkerButton::execDestroyMark },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMarkerButton);
UClass* Z_Construct_UClass_UMarkerButton_NoRegister()
{
	return UMarkerButton::StaticClass();
}
struct Z_Construct_UClass_UMarkerButton_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Damien/UI/MarkerButton.h" },
		{ "ModuleRelativePath", "Public/Damien/UI/MarkerButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_removeButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "MarkerButton" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Damien/UI/MarkerButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_marker_MetaData[] = {
		{ "Category", "MarkerButton" },
		{ "ModuleRelativePath", "Public/Damien/UI/MarkerButton.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_removeButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_marker;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMarkerButton_DestroyMark, "DestroyMark" }, // 2858607972
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMarkerButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMarkerButton_Statics::NewProp_removeButton = { "removeButton", nullptr, (EPropertyFlags)0x0144000000080009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMarkerButton, removeButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_removeButton_MetaData), NewProp_removeButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMarkerButton_Statics::NewProp_marker = { "marker", nullptr, (EPropertyFlags)0x0144000000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMarkerButton, marker), Z_Construct_UClass_AMarker_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_marker_MetaData), NewProp_marker_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMarkerButton_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMarkerButton_Statics::NewProp_removeButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMarkerButton_Statics::NewProp_marker,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMarkerButton_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMarkerButton_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Proto_Sunward,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMarkerButton_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMarkerButton_Statics::ClassParams = {
	&UMarkerButton::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMarkerButton_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMarkerButton_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMarkerButton_Statics::Class_MetaDataParams), Z_Construct_UClass_UMarkerButton_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMarkerButton()
{
	if (!Z_Registration_Info_UClass_UMarkerButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMarkerButton.OuterSingleton, Z_Construct_UClass_UMarkerButton_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMarkerButton.OuterSingleton;
}
template<> PROTO_SUNWARD_API UClass* StaticClass<UMarkerButton>()
{
	return UMarkerButton::StaticClass();
}
UMarkerButton::UMarkerButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMarkerButton);
UMarkerButton::~UMarkerButton() {}
// End Class UMarkerButton

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_UI_MarkerButton_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMarkerButton, UMarkerButton::StaticClass, TEXT("UMarkerButton"), &Z_Registration_Info_UClass_UMarkerButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMarkerButton), 3593099241U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_UI_MarkerButton_h_2007259116(TEXT("/Script/Proto_Sunward"),
	Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_UI_MarkerButton_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_UI_MarkerButton_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
