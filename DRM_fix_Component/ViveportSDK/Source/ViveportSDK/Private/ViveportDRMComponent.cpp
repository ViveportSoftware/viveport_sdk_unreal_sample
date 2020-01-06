// Fill out your copyright notice in the Description page of Project Settings.

#include "ViveportSDKPrivatePCH.h"
#include "ViveportDRMComponent.h"

// Sets default values for this component's properties
UViveportDRMComponent::UViveportDRMComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UViveportDRMComponent::BeginPlay()
{
	Super::BeginPlay();
	UViveportApi::GetLicense(&myLicenseChecker, VIVEPORT_ID, VIVEPORT_KEY);
    UViveportApi::Init(&myInitCallback, VIVEPORT_ID);
}

void UViveportDRMComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    UViveportApi::Shutdown(&myShutdownCallback);
}

void UViveportDRMComponent::MyLicenseChecker::OnSuccess(
    long long issue_time,
    long long expiration_time,
    int latest_version,
    bool update_required
    )
{

}

// Failed to verify the license, and the app will exit now. If you want to show some error messages or do something, you can change here.
void UViveportDRMComponent::MyLicenseChecker::OnFailure(int error_code, const FString& error_message) {
    FString fstring = FString::Printf(TEXT("Failed to verify the license.\n error_code=%d,\n error_message=%s"),
        error_code,
        *error_message);
    FPlatformMisc::RequestExit(true);
}

void UViveportDRMComponent::MyInitCallback::OnSuccess()
{
    
}

void UViveportDRMComponent::MyInitCallback::OnFailure(int error_code)
{
    
}

void UViveportDRMComponent::MyShutdownCallback::OnSuccess()
{
    
}

void UViveportDRMComponent::MyShutdownCallback::OnFailure(int error_code)
{
    
}
