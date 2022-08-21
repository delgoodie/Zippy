// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Zippy/Public/ZippyCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZippyCharacter() {}
// Cross Module References
	ZIPPY_API UClass* Z_Construct_UClass_AZippyCharacter_NoRegister();
	ZIPPY_API UClass* Z_Construct_UClass_AZippyCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_Zippy();
	ZIPPY_API UClass* Z_Construct_UClass_UZippyCharacterMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
	void AZippyCharacter::StaticRegisterNativesAZippyCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AZippyCharacter);
	UClass* Z_Construct_UClass_AZippyCharacter_NoRegister()
	{
		return AZippyCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AZippyCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZippyCharacterMovementComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ZippyCharacterMovementComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TurnRateGamepad_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnRateGamepad;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AZippyCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Zippy,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZippyCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ZippyCharacter.h" },
		{ "ModuleRelativePath", "Public/ZippyCharacter.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZippyCharacter_Statics::NewProp_ZippyCharacterMovementComponent_MetaData[] = {
		{ "Category", "Movement" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ZippyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZippyCharacter_Statics::NewProp_ZippyCharacterMovementComponent = { "ZippyCharacterMovementComponent", nullptr, (EPropertyFlags)0x002008000009001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZippyCharacter, ZippyCharacterMovementComponent), Z_Construct_UClass_UZippyCharacterMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZippyCharacter_Statics::NewProp_ZippyCharacterMovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZippyCharacter_Statics::NewProp_ZippyCharacterMovementComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZippyCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ZippyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZippyCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZippyCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZippyCharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZippyCharacter_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZippyCharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ZippyCharacter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZippyCharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZippyCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZippyCharacter_Statics::NewProp_FollowCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZippyCharacter_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZippyCharacter_Statics::NewProp_TurnRateGamepad_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */" },
		{ "ModuleRelativePath", "Public/ZippyCharacter.h" },
		{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZippyCharacter_Statics::NewProp_TurnRateGamepad = { "TurnRateGamepad", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZippyCharacter, TurnRateGamepad), METADATA_PARAMS(Z_Construct_UClass_AZippyCharacter_Statics::NewProp_TurnRateGamepad_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZippyCharacter_Statics::NewProp_TurnRateGamepad_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZippyCharacter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZippyCharacter_Statics::NewProp_ZippyCharacterMovementComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZippyCharacter_Statics::NewProp_CameraBoom,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZippyCharacter_Statics::NewProp_FollowCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZippyCharacter_Statics::NewProp_TurnRateGamepad,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AZippyCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZippyCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AZippyCharacter_Statics::ClassParams = {
		&AZippyCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AZippyCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AZippyCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AZippyCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AZippyCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AZippyCharacter()
	{
		if (!Z_Registration_Info_UClass_AZippyCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZippyCharacter.OuterSingleton, Z_Construct_UClass_AZippyCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AZippyCharacter.OuterSingleton;
	}
	template<> ZIPPY_API UClass* StaticClass<AZippyCharacter>()
	{
		return AZippyCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZippyCharacter);
	struct Z_CompiledInDeferFile_FID_Zippy_Source_Zippy_Public_ZippyCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Zippy_Source_Zippy_Public_ZippyCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AZippyCharacter, AZippyCharacter::StaticClass, TEXT("AZippyCharacter"), &Z_Registration_Info_UClass_AZippyCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZippyCharacter), 2054858365U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Zippy_Source_Zippy_Public_ZippyCharacter_h_3250767710(TEXT("/Script/Zippy"),
		Z_CompiledInDeferFile_FID_Zippy_Source_Zippy_Public_ZippyCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Zippy_Source_Zippy_Public_ZippyCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
