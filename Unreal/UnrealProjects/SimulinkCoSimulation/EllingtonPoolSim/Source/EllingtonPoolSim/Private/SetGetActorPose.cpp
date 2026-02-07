// Copyright 2019-2022 The MathWorks, Inc.
// Copyright 2026 Liam Multhaup, Liam@jmulthaup.com
#include "SetGetActorPose.h"

// Sets default values
ASetGetActorPose::ASetGetActorPose() :SignalReader(nullptr), SignalWriter(nullptr)
{
}

void ASetGetActorPose::Sim3dSetup()
{
    Super::Sim3dSetup();
    if (Tags.Num() != 0) {
        unsigned int numElements = 6;
        FString tagName = Tags.Top().ToString();

        FString SignalReaderTag = tagName;
        SignalReaderTag.Append(TEXT("Set"));
        SignalReader = StartSimulation3DMessageReader(TCHAR_TO_ANSI(*SignalReaderTag), sizeof(float) * numElements);

        FString SignalWriterTag = tagName;
        SignalWriterTag.Append(TEXT("Get"));
        SignalWriter = StartSimulation3DMessageWriter(TCHAR_TO_ANSI(*SignalWriterTag), sizeof(float) * numElements);
    }
}

void ASetGetActorPose::Sim3dStep(float DeltaSeconds)
{
    unsigned int numElements = 6;
    float array[6];
    int statusR = ReadSimulation3DMessage(SignalReader, sizeof(float) * numElements, array);
    FVector newLocation;
    newLocation.X = array[0];
    newLocation.Y = array[1];
    newLocation.Z = array[2];
    FRotator newRotation;
    newRotation.Roll = array[3];
    newRotation.Pitch = array[4];
    newRotation.Yaw = array[5];
    SetActorLocationAndRotation(newLocation, newRotation);
    float fvectorAndRotator[6] = { newLocation.X, newLocation.Y, newLocation.Z, newRotation.Roll, newRotation.Pitch, newRotation.Yaw };
    int statusW = WriteSimulation3DMessage(SignalWriter, sizeof(float) * numElements, fvectorAndRotator);
}

void ASetGetActorPose::Sim3dRelease()
{
    Super::Sim3dRelease();
    if (SignalReader) {
        StopSimulation3DMessageReader(SignalReader);
    }
    SignalReader = nullptr;

    if (SignalWriter) {
        StopSimulation3DMessageWriter(SignalWriter);
    }
    SignalWriter = nullptr;
}