// Copyright 2019-2022 The MathWorks, Inc.
// Copyright 2026 Liam Multhaup, Liam@jmulthaup.com

#pragma once

#include "CoreMinimal.h"
#include "Sim3dActor.h"
#include "SetGetActorPose.generated.h"

UCLASS()
class ELLINGTONPOOLSIM_API ASetGetActorPose : public ASim3dActor
{
	GENERATED_BODY()

	void* SignalReader;
	void* SignalWriter;

public:
	// Sets default values for this actor's properties
	ASetGetActorPose();

	virtual void Sim3dSetup() override;
	virtual void Sim3dRelease() override;
	virtual void Sim3dStep(float DeltaSeconds) override;
};