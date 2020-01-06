// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ViveportApi.h"
#include "Components/ActorComponent.h"
#include "ViveportDRMComponent.generated.h"


UCLASS( ClassGroup=(Viveport), meta=(BlueprintSpawnableComponent) )
class VIVEPORTSDK_API UViveportDRMComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UViveportDRMComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** The APP ID for auth verify */
    FString VIVEPORT_ID = "YOUR_VIVEPORT_ID";

    /** Public key for auth verify */
    FString VIVEPORT_KEY = "YOUR_VIVEPORT_KEY";

private:
    // callback interface
    class MyLicenseChecker : public UViveportApi::LicenseChecker
    {
    public:
        void OnSuccess(
                long long issue_time,
                long long expiration_time,
                int latest_version,
                bool update_required
        ) override;
        void OnFailure(
                int errorCode,
                const FString& errorMessage
        ) override;
    };

    MyLicenseChecker myLicenseChecker;

    class MyInitCallback : public ViveportApiStatus
    {
    public:
        void OnSuccess(
            ) override;
        void OnFailure(int error_code
            ) override;
    };

    MyInitCallback myInitCallback;

    class MyShutdownCallback : public ViveportApiStatus
    {
    public:
        void OnSuccess(
            ) override;
        void OnFailure(int error_code
            ) override;
    };

    MyShutdownCallback myShutdownCallback;
};
