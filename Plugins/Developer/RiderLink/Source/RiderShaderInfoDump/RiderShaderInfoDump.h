#pragma once

#include "Modules/ModuleInterface.h"

class RIDERSHADERINFODUMP_API FRiderShaderInfoDumpModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
};
