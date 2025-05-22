// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Proto_Sunward/Public/Damien/UI/CameraOverlay.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCameraOverlay() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
PROTO_SUNWARD_API UClass* Z_Construct_UClass_UCameraOverlay();
PROTO_SUNWARD_API UClass* Z_Construct_UClass_UCameraOverlay_NoRegister();
PROTO_SUNWARD_API UClass* Z_Construct_UClass_UMarkerButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_Proto_Sunward();
// End Cross Module References

// Begin Class UCameraOverlay
void UCameraOverlay::StaticRegisterNativesUCameraOverlay()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCameraOverlay);
UClass* Z_Construct_UClass_UCameraOverlay_NoRegister()
{
	return UCameraOverlay::StaticClass();
}
struct Z_Construct_UClass_UCameraOverlay_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Damien/UI/CameraOverlay.h" },
		{ "ModuleRelativePath", "Public/Damien/UI/CameraOverlay.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MarkerAmountText_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "CameraOverlay" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Damien/UI/CameraOverlay.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_buttonRef_MetaData[] = {
		{ "Category", "CameraOverlay" },
		{ "ModuleRelativePath", "Public/Damien/UI/CameraOverlay.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_removeButton_MetaData[] = {
		{ "Category", "CameraOverlay" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Damien/UI/CameraOverlay.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MarkerAmountText;
	static const UECodeGen_Private::FClassPropertyParams NewProp_buttonRef;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_removeButton;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCameraOverlay>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCameraOverlay_Statics::NewProp_MarkerAmountText = { "MarkerAmountText", nullptr, (EPropertyFlags)0x0144000000080009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraOverlay, MarkerAmountText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MarkerAmountText_MetaData), NewProp_MarkerAmountText_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UCameraOverlay_Statics::NewProp_buttonRef = { "buttonRef", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraOverlay, buttonRef), Z_Construct_UClass_UClass, Z_Construct_UClass_UMarkerButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_buttonRef_MetaData), NewProp_buttonRef_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCameraOverlay_Statics::NewProp_removeButton = { "removeButton", nullptr, (EPropertyFlags)0x0144000000080009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraOverlay, removeButton), Z_Construct_UClass_UMarkerButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_removeButton_MetaData), NewProp_removeButton_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCameraOverlay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraOverlay_Statics::NewProp_MarkerAmountText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraOverlay_Statics::NewProp_buttonRef,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraOverlay_Statics::NewProp_removeButton,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraOverlay_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCameraOverlay_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_Proto_Sunward,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraOverlay_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCameraOverlay_Statics::ClassParams = {
	&UCameraOverlay::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCameraOverlay_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCameraOverlay_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraOverlay_Statics::Class_MetaDataParams), Z_Construct_UClass_UCameraOverlay_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCameraOverlay()
{
	if (!Z_Registration_Info_UClass_UCameraOverlay.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCameraOverlay.OuterSingleton, Z_Construct_UClass_UCameraOverlay_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCameraOverlay.OuterSingleton;
}
template<> PROTO_SUNWARD_API UClass* StaticClass<UCameraOverlay>()
{
	return UCameraOverlay::StaticClass();
}
UCameraOverlay::UCameraOverlay(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCameraOverlay);
UCameraOverlay::~UCameraOverlay() {}
// End Class UCameraOverlay

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_UI_CameraOverlay_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCameraOverlay, UCameraOverlay::StaticClass, TEXT("UCameraOverlay"), &Z_Registration_Info_UClass_UCameraOverlay, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCameraOverlay), 3856668413U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_UI_CameraOverlay_h_2341151774(TEXT("/Script/Proto_Sunward"),
	Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_UI_CameraOverlay_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_PUEC1602_Documents_GitHub_Proto_Sunward_Proto_Sunward_Source_Proto_Sunward_Public_Damien_UI_CameraOverlay_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
