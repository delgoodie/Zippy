#include "BlueprintProvider.hpp"

#include "Async/Async.h"
#include "AssetData.h"
#include "AssetEditorMessages.h"
#include "BlueprintEditor.h"
#include "MessageEndpointBuilder.h"
#include "MessageEndpoint.h"
#include "Kismet2/KismetEditorUtilities.h"
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION <= 23
#include "Toolkits/AssetEditorManager.h"
#endif

#include "Runtime/Launch/Resources/Version.h"

void BluePrintProvider::AddAsset(FAssetData const& AssetData) {
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION <= 23
    UObject* cls = AssetData.GetAsset();
#else
    UObject* cls = AssetData.FastGetAsset();
#endif
    if (cls) {
        UBlueprint* Blueprint = Cast<UBlueprint>(cls);
        if (Blueprint && Blueprint->IsValidLowLevel()) {

        }
    }
}

bool BluePrintProvider::IsBlueprint(FString const& pathName) {
    return FPackageName::IsValidObjectPath(pathName);
}

void BluePrintProvider::OpenBlueprint(FString const& AssetPathName, TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> const& messageEndpoint) {
    // Just to create asset manager if it wasn't created already
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION <= 23
    FAssetEditorManager::Get();
    messageEndpoint->Publish(new FAssetEditorRequestOpenAsset(AssetPathName), EMessageScope::Process);
#else
    AsyncTask(ENamedThreads::GameThread, [AssetPathName]()
    {
        // An asset needs loading
        UPackage* Package = LoadPackage(nullptr, *AssetPathName, LOAD_NoRedirects);

        if (Package)
        {
            Package->FullyLoad();

            FString AssetName = FPaths::GetBaseFilename(AssetPathName);
            UObject* Object = FindObject<UObject>(Package, *AssetName);
            if(Object != nullptr)
                FKismetEditorUtilities::BringKismetToFocusAttentionOnObject(Object);
        }
    });
#endif
}
