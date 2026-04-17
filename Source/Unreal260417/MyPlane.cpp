// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlane.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMyPlane::AMyPlane()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);

	LeftPropeller = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftPropeller"));
	LeftPropeller->SetupAttachment(Box);

	RightPropeller = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightPropeller"));
	RightPropeller->SetupAttachment(Box);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Box);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Box);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
}

// Called when the game starts or when spawned
void AMyPlane::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddPropellerRotate(DeltaTime);

	AddMovementInput(GetActorForwardVector(), BoostValue);
}

// Called to bind functionality to input
void AMyPlane::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyPlane::AddPropellerRotate(float DeltaTime)
{
	LeftPropeller->AddRelativeRotation(FRotator(0.0f, 0.0f, PropellerSpeed * DeltaTime));
	RightPropeller->AddRelativeRotation(FRotator(0.0f, 0.0f, PropellerSpeed * DeltaTime));
}

