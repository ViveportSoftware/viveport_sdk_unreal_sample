// Fill out your copyright notice in the Description page of Project Settings.

#include "ViveportSDKPrivatePCH.h"
#include "ViveportDRMComponent.h"

// Sets default values for this component's properties
UViveportDRMComponent::UViveportDRMComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UViveportDRMComponent::BeginPlay()
{
	Super::BeginPlay();
	UViveportApi::GetLicense(&myLicenseChecker, APP_ID, APP_KEY);
    UViveportApi::Init(&myInitCallback, APP_ID);
}

void UViveportDRMComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    UViveportApi::Shutdown(&myShutdownCallback);
}

// Called every frame
void UViveportDRMComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UViveportDRMComponent::MyLicenseChecker::OnSuccess(
    long long issue_time,
    long long expiration_time,
    int latest_version,
    bool update_required
    )
{

}

void UViveportDRMComponent::MyLicenseChecker::OnFailure(int error_code, const FString& error_message) {
    FString fstring = FString::Printf(TEXT("Verify failed!\n error_code=%d,\n error_message=%s"),
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
