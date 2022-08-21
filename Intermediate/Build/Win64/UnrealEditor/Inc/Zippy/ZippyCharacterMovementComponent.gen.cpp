// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Zippy/Public/ZippyCharacterMovementComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZippyCharacterMovementComponent() {}
// Cross Module References
	ZIPPY_API UClass* Z_Construct_UClass_UZippyCharacterMovementComponent_NoRegister();
	ZIPPY_API UClass* Z_Construct_UClass_UZippyCharacterMovementComponent();
	ENGINE_API UClass* Z_Construct_UClass_UCharacterMovementComponent();
	UPackage* Z_Construct_UPackage__Script_Zippy();
// End Cross Module References
	DEFINE_FUNCTION(UZippyCharacterMovementComponent::execSprintReleased)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SprintReleased();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZippyCharacterMovementComponent::execSprintPressed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SprintPressed();
		P_NATIVE_END;
	}
	void UZippyCharacterMovementComponent::StaticRegisterNativesUZippyCharacterMovementComponent()
	{
		UClass* Class = UZippyCharacterMovementComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SprintPressed", &UZippyCharacterMovementComponent::execSprintPressed },
			{ "SprintReleased", &UZippyCharacterMovementComponent::execSprintReleased },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintPressed_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintPressed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ZippyCharacterMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintPressed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZippyCharacterMovementComponent, nullptr, "SprintPressed", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintPressed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintPressed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintPressed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintPressed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintReleased_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintReleased_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/ZippyCharacterMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintReleased_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZippyCharacterMovementComponent, nullptr, "SprintReleased", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintReleased_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintReleased_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintReleased()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintReleased_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UZippyCharacterMovementComponent);
	UClass* Z_Construct_UClass_UZippyCharacterMovementComponent_NoRegister()
	{
		return UZippyCharacterMovementComponent::StaticClass();
	}
	struct Z_Construct_UClass_UZippyCharacterMovementComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Sprint_MaxWalkSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Sprint_MaxWalkSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Walk_MaxWalkSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Walk_MaxWalkSpeed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCharacterMovementComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_Zippy,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintPressed, "SprintPressed" }, // 1857755336
		{ &Z_Construct_UFunction_UZippyCharacterMovementComponent_SprintReleased, "SprintReleased" }, // 2707387385
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ZippyCharacterMovementComponent.h" },
		{ "ModuleRelativePath", "Public/ZippyCharacterMovementComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::NewProp_Sprint_MaxWalkSpeed_MetaData[] = {
		{ "Category", "ZippyCharacterMovementComponent" },
		{ "ModuleRelativePath", "Public/ZippyCharacterMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::NewProp_Sprint_MaxWalkSpeed = { "Sprint_MaxWalkSpeed", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UZippyCharacterMovementComponent, Sprint_MaxWalkSpeed), METADATA_PARAMS(Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::NewProp_Sprint_MaxWalkSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::NewProp_Sprint_MaxWalkSpeed_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::NewProp_Walk_MaxWalkSpeed_MetaData[] = {
		{ "Category", "ZippyCharacterMovementComponent" },
		{ "ModuleRelativePath", "Public/ZippyCharacterMovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::NewProp_Walk_MaxWalkSpeed = { "Walk_MaxWalkSpeed", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UZippyCharacterMovementComponent, Walk_MaxWalkSpeed), METADATA_PARAMS(Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::NewProp_Walk_MaxWalkSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::NewProp_Walk_MaxWalkSpeed_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::NewProp_Sprint_MaxWalkSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::NewProp_Walk_MaxWalkSpeed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZippyCharacterMovementComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::ClassParams = {
		&UZippyCharacterMovementComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UZippyCharacterMovementComponent()
	{
		if (!Z_Registration_Info_UClass_UZippyCharacterMovementComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZippyCharacterMovementComponent.OuterSingleton, Z_Construct_UClass_UZippyCharacterMovementComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UZippyCharacterMovementComponent.OuterSingleton;
	}
	template<> ZIPPY_API UClass* StaticClass<UZippyCharacterMovementComponent>()
	{
		return UZippyCharacterMovementComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UZippyCharacterMovementComponent);
	struct Z_CompiledInDeferFile_FID_Zippy_Source_Zippy_Public_ZippyCharacterMovementComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Zippy_Source_Zippy_Public_ZippyCharacterMovementComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UZippyCharacterMovementComponent, UZippyCharacterMovementComponent::StaticClass, TEXT("UZippyCharacterMovementComponent"), &Z_Registration_Info_UClass_UZippyCharacterMovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZippyCharacterMovementComponent), 1723686722U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Zippy_Source_Zippy_Public_ZippyCharacterMovementComponent_h_2399642763(TEXT("/Script/Zippy"),
		Z_CompiledInDeferFile_FID_Zippy_Source_Zippy_Public_ZippyCharacterMovementComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Zippy_Source_Zippy_Public_ZippyCharacterMovementComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
