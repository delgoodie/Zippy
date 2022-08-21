#pragma once

#include "Delegates/Delegate.h"

struct FAssetData;
class FMessageEndpoint;
class UBlueprint;

class RIDERBLUEPRINT_API BluePrintProvider {
public:

    static void AddAsset(FAssetData const& AssetData);

    static bool IsBlueprint(FString const& pathName);

    static void OpenBlueprint(FString const& path, TSharedPtr<FMessageEndpoint, ESPMode::ThreadSafe> const& messageEndpoint);
};
